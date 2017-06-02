var SerialPort = require("serialport");

var config = {
    baudrate: 9600,
     dataBits: 8, 
     parity: 'none', 
     stopBits: 1, 
     flowControl: false,
     parser: SerialPort.parsers.readline('\n')
};

var serialport = new SerialPort("/dev/cu.usbmodem1421", config);

serialport.on('open', function(){

  console.log('Serial Port Opened');

  serialport.on('data', function(data){
      console.log(data);
  });

});
