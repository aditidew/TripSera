// server.js (Node.js + Express)

const express = require("express");
const fetch = require("node-fetch");
const cors = require("cors");

const app = express();
app.use(cors()); // Allow all origins, for testing only

const API_KEY = "YOUR_API_KEY";

app.get("/places", async (req, res) => {
  const { lat, lng, type } = req.query;
  const radius = 5000;

  if (!lat || !lng || !type) {
    return res.status(400).send({ error: "Missing parameters" });
  }

  const url = `https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=${lat},${lng}&radius=${radius}&type=${type}&key=${API_KEY}`;

  try {
    const response = await fetch(url);
    const data = await response.json();
    res.json(data);
  } catch (error) {
    res.status(500).send({ error: error.message });
  }
});

app.listen(3000, () => {
  console.log("Proxy server running on http://localhost:3000");
});
