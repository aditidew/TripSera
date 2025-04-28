// src/components/SearchForm.jsx
import React, { useState } from 'react';
import { searchPlaces } from '../services/api';
import '../App.css';

const SearchForm = () => {
  const [city, setCity] = useState('');
  const [haltDuration, setHaltDuration] = useState('');
  const [places, setPlaces] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [categories, setCategories] = useState('');

  const handleDetectLocation = () => {
    setError(null); // Clear any previous errors
    setLoading(true);
    if (navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(
        async (position) => {
          const { latitude, longitude } = position.coords;
          try {
            const data = await searchPlaces({ latitude, longitude, haltDuration, categories });
            setPlaces(data);
          } catch (err) {
            setError(err.message);
            setPlaces([]);
          } finally {
            setLoading(false);
          }
        },
        (geoError) => {
          setLoading(false);
          setError('Geolocation error: ' + geoError.message);
          setPlaces([]);
        }
      );
    } else {
      setLoading(false);
      setError('Geolocation is not supported by this browser.');
      setPlaces([]);
    }
  };

  const handleCitySearch = async () => {
    setError(null); // Clear any previous errors
    setLoading(true);
    try {
      const data = await searchPlaces({ city, haltDuration, categories });
      setPlaces(data);
    } catch (err) {
      setError(err.message);
      setPlaces([]);
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="search-form">
      <h2>Search Places</h2>
      <div>
        <label htmlFor="city">City/Place:</label>
        <input
          type="text"
          id="city"
          value={city}
          onChange={(e) => setCity(e.target.value)}
          placeholder="Enter city or place name"
        />
      </div>
      <div>
        <label htmlFor="haltDuration">Halt Duration (hours):</label>
        <input
          type="number"
          id="haltDuration"
          value={haltDuration}
          onChange={(e) => setHaltDuration(e.target.value)}
          placeholder="Enter halt duration in hours"
        />
      </div>
      <div>
            <label htmlFor="categories">Categories (comma-separated):</label>
            <input
                type="text"
                id="categories"
                value={categories}
                onChange={(e) => setCategories(e.target.value)}
                placeholder="e.g., restaurant,cafe,tourism"
            />
        </div>
      <button onClick={handleCitySearch} disabled={loading}>Search by City/Place</button>
      <button onClick={handleDetectLocation} disabled={loading}>Detect My Location</button>

      {loading && <p>Loading...</p>}
      {error && <p className="error-message">{error}</p>}

      {places.length > 0 && (
        <div className="results">
          <h3>Results:</h3>
          <ul>
            {places.map((place, index) => (
              <li key={index}>
                {/*  Display place information (adjust as needed) */}
                <p><strong>{place.properties.name}</strong></p>
                 <p>Address: {place.properties.address_line2}</p>
                {/* Add more details here, e.g., opening hours */}
              </li>
            ))}
          </ul>
        </div>
      )}
    </div>
  );
};

export default SearchForm;