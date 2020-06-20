#define SoilPower 7
#define motor 3
#define switchPin 2

int switchState = 0;   
int val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 

void setup(){ 
  pinMode(switchPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);   // open serial over USB
  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
  }

void loop(){
  switchState = digitalRead(switchPin);
  Serial.print("Soil Moisture = ");    
  Serial.println(readSoil());
  if (switchState == HIGH){
    delay(1000);
    digitalWrite(motor, LOW);
    delay(10000);
    digitalWrite(motor, HIGH);
    delay(15000);
  }
  else{
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
