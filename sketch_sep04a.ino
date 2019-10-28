#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
//float db, analog;
float adc, dB, PdB;
int pinSensor= 2;
int temp,hum;
int period = 1000; //1000 = 1 segundo
unsigned long timeNow = 0;
/*Sensor que usaré*/
DHT dht (pinSensor, DHT11);
/*Enciendo el monitor serial y el sensor*/
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  /*Obtengo datos y los guardo en las variables*/
  //analog = analogRead(A0);
  temp = dht.readTemperature();
  hum =  dht.readHumidity();
  //Logaritmo para conversion a Decibeles        //db = (20*log10(analog)-.1975);  
  PdB = dB; //Store the previous of dB here
  adc = analogRead(A0); //Read the ADC value from amplifer
  dB = (adc+83.2073)/ 11.003;  //Convert ADC value to dB using Regression values

  if(millis() > timeNow + period){
    timeNow = millis();
    Serial.println('[');
    Serial.print("temperature: ");
    Serial.print(temp);
    Serial.println("°C, ");
    Serial.print("humidity: ");
    Serial.print(hum);
    Serial.println("% , ");
    Serial.print("sound: ");
    Serial.println(dB);
    //Serial.println(analogRead(A0));
    Serial.println(']');
  }
  Serial.println('[');
  Serial.print("sound: ");
  Serial.println(dB);
  //Serial.println(analogRead(A0));
  Serial.println(']');
/*  File dataFile = SD.open("datalog.csv", FILE_WRITE);
  if(dataFile){
    dataFile.println("DATOS");
    dataFile.close();  
  }*/
}
