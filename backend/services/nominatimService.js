// backend/services/nominatimService.js
const axios = require('axios');
require('dotenv').config();

const nominatimBaseUrl = process.env.NOMINATIM_BASE_URL;

async function reverseGeocode(latitude, longitude) {
    if (!nominatimBaseUrl) {
        throw new Error("NOMINATIM_BASE_URL is not defined in your .env file.");
    }
    const url = `${nominatimBaseUrl}/reverse`;

    try {
        const response = await axios.get(url, {
            params: {
                lat: latitude,
                lon: longitude,
                format: 'jsonv2', // Use jsonv2 for more detailed address information
            },
            headers:{ //Optional
                'User-Agent': 'Tripsera App'
            }
        });


        const data = response.data;
        //Nominatim doesn't have a consistent "status" field like some other APIs.
        //Instead, it returns different HTTP status codes and sometimes an "error" field.
        if (data.error) {
            throw new Error(`Nominatim error: ${data.error}`);
        }

        // Construct a more structured address object
        const address = {
            road: data.address.road || null,
            city: data.address.city || data.address.town || data.address.village || null,
            state: data.address.state || null,
            country: data.address.country || null,
            postcode: data.address.postcode || null,
            displayName: data.display_name || null,
            latitude: data.lat, //Include these
            longitude: data.lon
        };

        return address;

    } catch (error) {
        if (error.response) {
            // The request was made and the server responded with a status code outside of 2xx
            throw new Error(`Nominatim API error: ${error.response.status} - ${error.response.statusText}`);
        } else if (error.request) {
             // The request was made but no response was received
            throw new Error('Nominatim API: No response received.');
        }
        throw new Error(`Nominatim API error: ${error.message}`);
    }
}

module.exports = { reverseGeocode };