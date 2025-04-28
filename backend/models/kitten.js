const mongoose = require('mongoose');

const kittySchema = new mongoose.Schema({
    city: String,
    place: String,
    rating: Number,
    dist: String,
    desc: String
  });

  const Kitten = mongoose.model('Kitten', kittySchema);

  module.exports = Kitten