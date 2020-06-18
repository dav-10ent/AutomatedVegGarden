#define SoilPower 7
#define motor 3

int val = 0;
int SoilPin = 0;

void setup(){ 
  
  pinMode(motor, OUTPUT);
  pinMode(soilPower, OUTPUT);
  
  }

void loop(){
  sensorValue = readSoil();
  
  if (sensorValue <= 100){
    digitalWrite(motor, HIGH);
    delay(5000);
    digitalWrite(motor, LOW);
  }
  else {
    delay(1000);
  }
}

int readSoil()
{

    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}
