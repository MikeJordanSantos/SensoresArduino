const http = require('http');
const express = require('express');
const socketIo = require('socket.io');
const app = express();
const server = http.createServer(app);
const io = socketIo.listen(server);
app.use(express.static(__dirname + '/public'));

server.listen(3000, function (){
    console.log('SERVIDOR INICIALIZADO');
});
//SERIAL COMUNICACION
const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
const port = new SerialPort('COM7',{
    baudRate: 9600
});
const parser = port.pipe(new Readline({delimiter: '\r\n' }));
parser.on('open', ()=>{
    console.log('conexion esta abierta');
});
let datos = {
    date: Date.now(),
    sound: [],
    temp: [],
    hum: []
}
let flag =false;
parser.on('data', (data)=>{
    const x = String.toString(data);
    console.log(x);
});
parser.on('error', (err)=>{
    console.log(err);
});
/* 
app.listen(8000, ()=>{
    console.log('SERVIDOR INICIALIZADO');
});
var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io').listen(server);
var serialport = require('serialport');
var Serialport = serialport.SerialPort;
var myPort= new Serialport('COM7', {
    baudrate: 9600,    
});
myPort.on('open', onOpen);
myPort.on('data', onData);
function onOpen(){
    console.log('Arduino conectado');
};
function onData(){
};
server.listen(8000, ()=>{
    console.log('SERVIDOR INICIALIZADO');
});
*/