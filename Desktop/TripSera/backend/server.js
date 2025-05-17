const express = require("express");
const cors = require("cors");
const fetch = require("node-fetch");

const app = express();
const PORT = 3000;
const GOOGLE_API_KEY = "YOUR_API_KEY"; // Replace this with your actual API key

app.use(cors());

app.get("/places", async (req, res) => {
  const { lat, lng, type } = req.query;

  if (!lat || !lng || !type) {
    return res.status(400).json({ status: "ERROR", message: "Missing parameters" });
  }

  const url = `https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=${lat},${lng}&radius=5000&type=${type}&key=${AIzaSyAu6vsXgiqLRDyOAs1o2bEx7rKZHIjyhZU}`;

  try {
    const response = await fetch(url);
    const data = await response.json();

    if (data.status !== "OK") {
      console.error("Google API Error:", data.status, data.error_message);
      return res.status(500).json({ status: data.status, message: data.error_message || "Google API error" });
    }

    res.json({ status: "OK", results: data.results });
  } catch (err) {
    console.error("Server error:", err);
    res.status(500).json({ status: "ERROR", message: "Internal server error" });
  }
});

app.listen(PORT, () => {
  console.log(`🌐 Server running at http://localhost:${PORT}`);
});
