//create express server
const express = require('express');
const app = express();
const cors = require('cors');
const mqtt = require('mqtt');

//crete mqtt client
const client = mqtt.connect(process.env.SERVER);

//check if client is connected
client.on('connect', () => {
    console.log('Connected to MQTT broker');
});

//use cors to allow cross origin resource sharing
app.use(cors({ origin: '*' }));

app.get('/tv/on', (req, res) => {
    
    //get the url query password
    const password = req.query.password;
    
    //if password is correct
    if (password === process.env.PASSWORD) {
        res.send('Turning on...');
        client.publish('home-assistant/theater/tv/set', 'ON');
    } else {
        res.send('Password incorrect');
    }
});

app.get('/tv/off', (req, res) => {
    
    //get the url query password
    const password = req.query.password;
    
    //if password is correct
    if (password === process.env.PASSWORD) {
        res.send('Turning off...');
        client.publish('home-assistant/theater/tv/set', 'OFF');
    } else {
        res.send('Password incorrect');
    }
});

//listen for requests on port 3000
app.listen(process.env.PORT, () => {
    console.log("Server is running on port " + process.env.PORT);
});

process.on('SIGINT', function() {
    process.exit();
});