require("dotenv").config();

const fs = require('fs');
const path = require("path")
const Papa = require('papaparse');

const connectDB = require("./db");
const Kitten = require('../models/kitten');

const csvFile = fs.readFileSync(path.join(__dirname, "./Places.csv"), 'utf8');
let { data } = Papa.parse(csvFile, { header: true });

data = data.map(place => {
    return {
        ...place,
        rating: Number(place.rating)
    }
}).filter(place => !isNaN(place.rating))

// console.log(data)

const seed = async () => {
    await connectDB();
    
    // drop the collection
    await Kitten.deleteMany({});
    
    try {
        const result = await Kitten.insertMany(data)
        console.log(result.length, "kittens created");
        
    } catch (error) {
        console.error(error);
    }

};

seed();