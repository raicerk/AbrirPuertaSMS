#include <Servo.h>

Servo myservo;
int pos = 0;
String a;
String randNumber;
long vuelta = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  delay(500);
  myservo.write(0);
}

void loop() {

  vuelta++;

  while(Serial.available()>0) {
    
    a = Serial.readString();// read the incoming data as string

    if(a == "activado"){
      randNumber = vuelta;
      Serial.println(randNumber);
    }

    if(a == randNumber){
      Serial.println("Exito!!");
      myservo.write(180);
      delay(2000);
      myservo.write(0);
      vuelta = 0;
    }else{
      Serial.println("Error");
      myservo.write(0);
    }
  }
  
  if(vuelta == 99999){
    vuelta = 0;  
  }

}
