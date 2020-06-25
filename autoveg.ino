#include "DHT.h"
#define DHTPIN 7 
#define motor 3
#define switchPin 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int switchState = 0;   
int val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 8;//Variable for Soil moisture Power


void setup(){ 
  pinMode(switchPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);   // open serial over USB
  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
  dht.begin();
  }

void loop(){
  tempRead();
  switchState = digitalRead(switchPin);
  Serial.print(" Soil Moisture = ");   
  pump();
}

int readSoil(){
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}

void tempRead(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
}

void pump(){
  val = analogRead(soilPin);
  Serial.println(readSoil());
  
  if (val < 150){
    delay(1000);
    digitalWrite(motor, HIGH);
    delay(5000);
    digitalWrite(motor, LOW);
    delay(5000);
  }
  else{
    delay(1000);
  }
}
