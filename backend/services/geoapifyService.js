// backend/services/geoapifyService.js
const axios = require('axios');
require('dotenv').config();

const geoapifyApiKey = process.env.GEOAPIFY_API_KEY;
const geoapifyBaseUrl = 'https://api.geoapify.com/v2';
const geoapifyGeocodeBaseUrl = 'https://api.geoapify.com/v1';

async function getPlacesByCoordinates(latitude, longitude, radius, categories) {
    if (!geoapifyApiKey) {
        throw new Error("GEOAPIFY_API_KEY is not defined in your .env file.");
    }
    const url = `${geoapifyBaseUrl}/places`;

    const params = {
        filter: `circle:${longitude},${latitude},${radius}`,
        bias: `proximity:${longitude},${latitude}`,
        limit: 20,  // Adjust as needed
        apiKey: geoapifyApiKey,
    };

    // Add categories to the parameters if provided AND not empty
    if (categories && categories.length > 0) {
        params.categories = categories.join(',');
    }

    try {
        const response = await axios.get(url, { params }); // Pass params object
        const data = response.data;
        return data.features; // Return the features array (GeoJSON FeatureCollection)

    } catch (error) {
        handleGeoapifyError(error);
    }
}

async function getPlacesByText(query, bias, categories) { // Add categories parameter
    if (!geoapifyApiKey) {
        throw new Error("GEOAPIFY_API_KEY is not defined in your .env file.");
    }
    const url = `${geoapifyBaseUrl}/places`;

    const params = { // Use an object for parameters
        text: query,
        apiKey: geoapifyApiKey,
        limit: 20 //Adjust limit as needed.
    };
     // Add bias to the parameters if provided
    if (bias) {
        params.bias = bias;
    }
    // Add categories to parameters if provided and not empty
    if (categories && categories.length > 0) {
        params.categories = categories.join(',');
    }

    try {
        const response = await axios.get(url, { params });  // Pass params object

        const data = response.data;
         return data.features; // Return the features array

    } catch (error) {
       handleGeoapifyError(error);
    }
}


async function getPlaceDetails(placeId) {
    if (!geoapifyApiKey) {
        throw new Error("GEOAPIFY_API_KEY is not defined in your .env file.");
    }
    const url = `${geoapifyBaseUrl}/place-details`;

    try {
        const response = await axios.get(url, {
            params: {
                features: 'opening_hours', //Request opening_hours feature
                id: placeId,
                apiKey: geoapifyApiKey,
            },
        });

        const data = response.data;
         if (data.features && data.features.length > 0) {
            return data.features[0]; // Return the first feature (if it exists)
        } else {
            throw new Error('Geoapify Place Details: No place details found.'); // More specific error
        }

    } catch (error) {
       handleGeoapifyError(error);
    }
}


async function geocode(query) {
    if (!geoapifyApiKey) {
        throw new Error("GEOAPIFY_API_KEY is not defined in your .env file.");
    }
	const url = `${geoapifyGeocodeBaseUrl}/geocode`;

    try {
        const response = await axios.get(url, {
            params: {
                text: query,
                apiKey: geoapifyApiKey,
            },
        });

        const data = response.data;
        return data.results;

    } catch (error) {
        handleGeoapifyError(error);
    }
}

// Centralized error handling for Geoapify API calls
function handleGeoapifyError(error) {
     if (error.response) {
        // The request was made and the server responded with a status code
        // that falls out of the range of 2xx
        const status = error.response.status;
        const message = error.response.data.message || error.response.data.error || error.response.statusText;  //More robust message extraction

        if(status === 400){
            throw new Error(`Geoapify API error: Bad Request - ${message}`);
        } else if (status === 401){
             throw new Error(`Geoapify API error: Unauthorized - Check your API key. ${message}`);
        } else if (status === 429){
            throw new Error(`Geoapify API error: Too Many Requests - You have exceeded your API rate limit. ${message}`)
        }
        else{
            throw new Error(`Geoapify API error: ${status} - ${message}`);
        }
    } else if (error.request) {
        // The request was made but no response was received
        throw new Error('Geoapify API: No response received.');
    } else {
        // Something happened in setting up the request that triggered an Error
        throw new Error(`Geoapify API error: ${error.message}`);
    }
}

module.exports = { getPlacesByCoordinates, getPlacesByText, getPlaceDetails, geocode };