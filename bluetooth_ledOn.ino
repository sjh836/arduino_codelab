#include <SoftwareSerial.h>

SoftwareSerial BT(12, 13);

const int led[6]={3,4,5,6,7,8};
int data;

void setup()
{
  Serial.begin(9600);
  for(int i=0; i<6; i++)
    pinMode(led[i], OUTPUT);
  BT.begin(9600);
  Serial.println("");
  Serial.println("Name: LEE, JungHoon");
  Serial.println("Student ID: 2012335054");
}

void loop()
{
  if(BT.available()>0)
  {
    data=BT.parseInt();
    Serial.println(data);
    for(int i=0; i<6; i++)
      digitalWrite(led[i], LOW);
    ledON(data);
  }
}

void ledON(int number)
{
  switch(number)
  {
    case 1: case 2: case 3: case 4: case 5: case 6: 
      for(int i=0; i<number; i++)
       digitalWrite(led[i], HIGH);
      break;
    case 7:
      for(int i=1; i<6; i+=2)
       digitalWrite(led[i], HIGH);
      break;
    case 8:
      for(int i=0; i<6; i+=2)
       digitalWrite(led[i], HIGH);
      break;
    case 9:
      for(int i=0; i<6; i++)
      {
         digitalWrite(led[i], HIGH);
         delay(300);
      }
    break;
    case 10:
      for(int i=0; i<6; i++)
        digitalWrite(led[i], HIGH);
      delay(300);
      for(int i=5; i>=0; i--)
      {
         digitalWrite(led[i], LOW);
         delay(300);
      }
    break;
  }
}
