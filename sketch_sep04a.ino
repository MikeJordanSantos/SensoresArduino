#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
int pinSensor= 5;
int temp,hum;
int periodo = 5000; //1000 = 1 segundo
unsigned long ahora = 0;
/*Sensor que usaré*/
DHT dht (pinSensor, DHT11);
/*Enciendo el monitor serial y el sensor*/
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  /*Obtengo datos y los guardo en las variables*/
  temp = dht.readTemperature();
  hum =  dht.readHumidity();
  //Serial.print("sound: ");
  //Serial.println(analogRead(A0));
  if(millis() > ahora + periodo){
    ahora = millis();
    Serial.println('{');
    Serial.print("temperature: ");
    Serial.print(temp);
    Serial.println("°C, ");
    Serial.print("humidity: ");
    Serial.print(hum);
    Serial.println("% , ");
    Serial.print("sound: ");
    Serial.println(analogRead(A0));
    Serial.println('}');
  }
  Serial.println('{');
  Serial.print("sound: ");
  Serial.println(analogRead(A0));
  Serial.println('}');
/*  File dataFile = SD.open("datalog.csv", FILE_WRITE);
  if(dataFile){
    dataFile.println("DATOS");
    dataFile.close();  
  }*/
}
