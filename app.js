var SerialPort = require("serialport");
var axios = require('axios');
var argv = require( 'argv' );

var options = {
    name: 'serialport',
    short: 'sp',
    type: 'string',
    description: 'Uses the defined port',
    example: "'script --port=/dev/cu.usbmodem1421' or 'script -sp /dev/cu.usbmodem1421'"
};

var apiUrl = 'http://cod10.165.60.110:8000';
var touchEndpoint = '/api/users/1/touches';

var args = argv.option(options).run();
var serialPortName = args.options.serialport;

var config = {
    baudrate: 9600,
     dataBits: 8, 
     parity: 'none', 
     stopBits: 1, 
     flowControl: false,
     parser: SerialPort.parsers.readline('\n')
};

var touchTimeout;
var pressureValues = [];
var duration = 0;
var startTouchTime;

var logTouch = function(data) {
    var body;

    data = parseInt(data, 10);

    // do not log touch pressure events under 200
    if (!data || data < 200) return;

    console.log('logTouch', data);

    if (!touchTimeout) {
        // first touch event in series
        startTouchTime = (new Date()).getTime();
        console.log('startTouchTime', startTouchTime);
    } else {
        // subsequent touch events - reset timeout
        console.log('clearTimeout');
        clearTimeout(touchTimeout);
        touchTimeout = null;
    }
    
    pressureValues.push(data); 

    touchTimeout = setTimeout(function() {

        console.log('pressureValues', pressureValues);

        var pressureValueTotalSum = pressureValues.reduce(function(total, value) {
            return total + value;
        }, 0);

        console.log('pressureValueTotalSum', pressureValueTotalSum);

        var pressureValueAverage = Math.round(pressureValueTotalSum / pressureValues.length);

        console.log('pressureValueAverage', pressureValueAverage);

        var endTouchTime = (new Date()).getTime();
        console.log('endTouchTime', endTouchTime);

        var duration = endTouchTime - startTouchTime;
        console.log('duration', duration);

        body = {
            pressureValue: pressureValueAverage,
            duration: duration
        };

        // reset
        pressureValues = [];
        startTouchTime = null;
        clearTimeout(touchTimeout);
        touchTimeout = null;
            
        var requestUrl = apiUrl + touchEndpoint;
        console.log('requestUrl', requestUrl);

        axios.post(requestUrl, body)
            .then(function (response) {
                console.log(response);
            })
            .catch(function (error) {
                console.log(error);
            });

    }, 5000);

}

var serialport = new SerialPort(serialPortName, config);
serialport.on('open', function(){
  console.log('Serial Port Opened');
  serialport.on('data', function(data){
      logTouch(data);
  });
});

// Use to get open ports - uncomment to use
// var SerialPort = require('serialport');
// SerialPort.list(function (err, ports) {
//   ports.forEach(function(port) {
//     console.log(port.comName);
//     console.log(port.pnpId);
//     console.log(port.manufacturer);
//   });
// });

