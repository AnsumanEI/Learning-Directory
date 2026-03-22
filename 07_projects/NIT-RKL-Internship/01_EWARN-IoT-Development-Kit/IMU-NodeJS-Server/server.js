const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');
const axios = require('axios');
const http = require('http');
const WebSocket = require('ws');

const app = express();
const port = 3000;

// ThingSpeak API information
const apiKey = 'YOUR_THINGSPEAK_API_KEY';
const thingSpeakUrl = `http://api.thingspeak.com/update?api_key=${apiKey}`;

// Middleware to parse JSON data
app.use(bodyParser.json());

// Serve the static HTML file
app.use(express.static(path.join(__dirname, 'public')));

let sensorData = {};

// Create an HTTP server
const server = http.createServer(app);

// Create a WebSocket server
const wss = new WebSocket.Server({ server });

// WebSocket connection
wss.on('connection', ws => {
  console.log('Client connected');

  ws.on('close', () => {
    console.log('Client disconnected');
  });
});

// Function to broadcast data to all connected clients
const broadcastData = data => {
  wss.clients.forEach(client => {
    if (client.readyState === WebSocket.OPEN) {
      client.send(JSON.stringify(data));
    }
  });
};

// Endpoint to receive data from the Arduino
app.post('/data', async (req, res) => {
  sensorData = req.body;
  console.log('Received data:', sensorData);

  // Send data to ThingSpeak
  try {
    const response = await axios.get(thingSpeakUrl, {
      params: {
        field1: sensorData.accelX,
        field2: sensorData.accelY,
        field3: sensorData.accelZ,
        field4: sensorData.gyroX,
        field5: sensorData.gyroY,
        field6: sensorData.gyroZ,
      }
    });
    console.log('Data sent to ThingSpeak:', response.data);
  } catch (error) {
    console.error('Error sending data to ThingSpeak:', error);
  }

  // Broadcast the received data to all WebSocket clients
  broadcastData(sensorData);

  res.sendStatus(200);
});

// Endpoint to serve sensor data to the client
app.get('/sensorData', (req, res) => {
  res.json(sensorData);
});

// Start the server
server.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
