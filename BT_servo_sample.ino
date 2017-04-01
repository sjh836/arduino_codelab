#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
SoftwareSerial BT(12, 13);
int value;
int last = 0;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  myservo.attach(9);
}

void loop()
{
    if(BT.available()>0)
    {
      value=BT.parseInt();
      
      Serial.print("value: ");
      Serial.println(value);
      myservo.write(value);
    }
}

