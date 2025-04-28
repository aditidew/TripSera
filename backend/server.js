const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const mongoose = require('mongoose'); // Import mongoose
const placesRoutes = require('./routes/places'); // Import places routes

dotenv.config();

const app = express();
const port = process.env.PORT || 5000; // Use PORT from .env or default to 5000

app.use(cors());
app.use(express.json());

// // MongoDB Connection
// mongoose.connect(process.env.MONGODB_URI || 'mongodb://localhost:27017/tripsera') // Removed options
//   .then(() => console.log("MongoDB connected successfully"))
//   .catch(err => console.error("MongoDB connection error:", err));

app.get('/', (req, res) => {
    res.json({ message: 'Hello from the Tripsera backend!' });
});

// Basic route for testing
app.get('/', (req, res) => {
    res.json({ message: 'Hello from the Tripsera backend!' });
});

// Use the places routes (unified endpoint)
app.use('/api/places', placesRoutes);

// Error handling middleware (best practice - catch-all for errors)
app.use((err, req, res, next) => {
    console.error(err.stack); // Log the error stack for debugging
    res.status(500).json({ message: 'Something went wrong on the server!' });
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});