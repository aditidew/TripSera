// src/services/api.js
import axios from 'axios';

const API_BASE_URL = 'http://localhost:5000/api/places'; // Or your backend URL if different

export const searchPlaces = async (params) => {
  try {
    const response = await axios.get(`${API_BASE_URL}/places`, { params });
    return response.data;
  } catch (error) {
    console.error('Error fetching places:', error);
    if (error.response) {
      // The request was made and the server responded with a status code
      // that falls out of the range of 2xx
      throw new Error(error.response.data.message || 'An error occurred.');
    } else if (error.request) {
      // The request was made but no response was received
      throw new Error('No response received from the server.');
    } else {
      // Something happened in setting up the request that triggered an Error
      throw new Error('Error setting up the request.');
    }
  }
};