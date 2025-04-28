const { reverseGeocode } = require('../services/nominatimService');
const { getPlacesByCoordinates, getPlacesByText, getPlaceDetails, geocode } = require('../services/geoapifyService');

exports.searchPlaces = async (req, res) => {
    const { latitude, longitude, city, haltDuration, categories } = req.query;

    try {
        if (latitude && longitude) {
            // Search by Location (Detect My Location)
            const lat = parseFloat(latitude);
            const lng = parseFloat(longitude);
            const duration = parseInt(haltDuration);
            const categoriesArray = categories ? categories.split(',').map(c => c.trim()) : [];
            // 1. Reverse Geocode (Nominatim) - optional, to get a nice address
            let addressDetails;
            try{
                addressDetails = await reverseGeocode(lat, lng);
            }
            catch(nominatimError){
                console.error("Nominatim Error:", nominatimError);
                //Decide whether to continue without address, or return
            }
            // 2. Get Places by Coordinates (Geoapify)
            const places = await getPlacesByCoordinates(lat, lng, 5000, categoriesArray); // 5km radius, for example


            // 3. Get Place Details (Geoapify) and Filter
            const detailedPlaces = [];
            for (const place of places) {
                try {
                    const details = await getPlaceDetails(place.place_id); // Assuming place has a place_id
                     const now = new Date();
                    const dayOfWeek = now.getDay();
                    const currentTime = `${now.getHours().toString().padStart(2, '0')}:${now.getMinutes().toString().padStart(2, '0')}`;

                    if (isOpen(details, dayOfWeek, currentTime, duration)) { // Your existing isOpen function
                        detailedPlaces.push(details);
                    }
                } catch (detailsError) {
                    console.error("Error getting place details:", detailsError);
                    // Decide whether to skip this place or return a partial error
                }
            }

            res.json(detailedPlaces);

        } else if (city) {
            // Search by City/Place
            const duration = parseInt(haltDuration);
            const categoriesArray = categories ? categories.split(',').map(c => c.trim()) : [];

            // 1. Geocode the city (Geoapify)
            let geoResult
            try{
                 geoResult = await geocode(city);
            } catch(geoError){
                console.error("Geocoding Error:", geoError);
                return res.status(400).json({ message: 'Could not geocode the city/place.' });
            }

            if (!geoResult || geoResult.length === 0) {
               return res.status(404).json({ message: 'City/Place not found.' });
            }
            const { lat, lon } = geoResult[0]; // Get the coordinates of the first result

            // 2. Get places by text or coordinates
            const places = await getPlacesByText(city, `circle:${lon},${lat},5000`, categoriesArray);


            // 3. Get Place Details (Geoapify) and Filter. Similar to above
            const detailedPlaces = [];
              for (const place of places) {
                try {
                    const details = await getPlaceDetails(place.place_id); // Assuming place has a place_id

                    const now = new Date();
                    const dayOfWeek = now.getDay();
                    const currentTime = `${now.getHours().toString().padStart(2, '0')}:${now.getMinutes().toString().padStart(2, '0')}`;

                    if (isOpen(details, dayOfWeek, currentTime, duration)) {
                        detailedPlaces.push(details);
                    }
                } catch (detailsError) {
                    console.error("Error getting place details:", detailsError);
                    // Decide whether to skip this place or return a partial error
                }
            }

            res.json(detailedPlaces);

        } else {
            return res.status(400).json({ message: 'Missing required parameters (latitude/longitude or city)' });
        }
    } catch (error) {
        console.error("General Error in searchPlaces:", error);
        res.status(500).json({ message: 'An unexpected error occurred.' });
    }
};


  // Helper function to check if a place is open (existing code - place it here)
const isOpen = (place, dayOfWeek, currentTime, duration) => {
    //...your existing logic from previous response...
    if (!place.properties || !place.properties.opening_hours) {
      return false;
    }
    const openingHours = place.properties.opening_hours;

    const daySchedule = openingHours.find(schedule => schedule.day === dayOfWeek);

    if (!daySchedule) {
        return false; // No schedule for that day
    }

    const openTime = daySchedule.open;
    const closeTime = daySchedule.close;

    // Convert to minutes since midnight
    const currentTimeMinutes = parseInt(currentTime.split(':')[0]) * 60 + parseInt(currentTime.split(':')[1]);
    const openTimeMinutes = parseInt(openTime.split(':')[0]) * 60 + parseInt(openTime.split(':')[1]);
    const closeTimeMinutes = parseInt(closeTime.split(':')[0]) * 60 + parseInt(closeTime.split(':')[1]);

    // Calculate the end time of the halt
    const haltEndTimeMinutes = currentTimeMinutes + (duration * 60);

    // Check if the place is open during the entire halt
    if (openTimeMinutes <= currentTimeMinutes && closeTimeMinutes >= haltEndTimeMinutes) {
        return true;
    }

    // Handle cases where opening hours span midnight
    if (closeTimeMinutes < openTimeMinutes) {
        if (openTimeMinutes <= currentTimeMinutes || closeTimeMinutes >= haltEndTimeMinutes) {
            return true;
        }
    }

    return false;
};