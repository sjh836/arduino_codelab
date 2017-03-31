const int led[3]={9,10,11}; //9=blue, 10=green, 11=red
int pot[3]={0,1,2}; //2=red, 1=green, 0=blue

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  {
    pinMode(led[i],OUTPUT);
  }
}
void loop()
{
  for(int i=0;i<3;i++)
  {
    pot[i]=analogRead(i);
    pot[i]=map(pot[i], 200, 900, 0, 255);
    pot[i]=constrain(pot[i], 0, 255);
  }
  setColor(pot[0], pot[1], pot[2]);
  delay(200);
}
void setColor(int red, int green, int blue) //9=blue, 10=green, 11=red
{
  analogWrite(led[2],red);
  Serial.print("\nred: ");
  Serial.print(red);
  analogWrite(led[1],green);
  Serial.print("\tgreen: ");
  Serial.print(green);
  analogWrite(led[0],blue);
  Serial.print("\tblue: ");
  Serial.print(blue);
}
