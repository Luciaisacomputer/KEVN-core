var SerialPort = require("serialport");
var argv = require( 'argv' );
var options = {
    name: 'serialport',
    short: 'sp',
    type: 'string',
    description: 'Uses the defined port',
    example: "'script --port=/dev/cu.usbmodem1421' or 'script -sp /dev/cu.usbmodem1421'"
};

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

var serialport = new SerialPort(serialPortName, config);
serialport.on('open', function(){
  console.log('Serial Port Opened');
  serialport.on('data', function(data){
      console.log(data);
  });
});

