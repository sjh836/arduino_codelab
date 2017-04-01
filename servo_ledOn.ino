#include <Servo.h>

Servo servo;
const int light=2;
const int led[3]={9,10,11};
int value;
int last = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(light, INPUT);
  for(int i=0;i<3;i++)
    pinMode(led[i], OUTPUT);
  servo.attach(6);
}

void loop()
{
  value=digitalRead(light);
  if(last!=value)
  {
    //Serial.println(value);
    if(value==0)
    {
      Serial.println("A");
      servo.write(0);
      setColor(0, 0, 0);
    }
    else if(value==1)
    {
      Serial.println("B");
      servo.write(179);
      for(int i=0;i<5;i++)
      {
        setColor(255, 255, 255);
        delay(50);
        setColor(0, 0, 0);
        delay(50);
      }
      setColor(255, 255, 255);
    }
    last=value;
    delay(200);
  }
}
void setColor(int red, int green, int blue) //9=blue, 10=green, 11=red
{
  analogWrite(led[2],red);
  analogWrite(led[1],green);
  analogWrite(led[0],blue);
}
