const int pot[2]={0,1};
int value[2];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int i=0;i<2;i++)
  {
    value[i]=analogRead(pot[i]);
    value[i]=map(value[i], 0, 1023, 0, 255);
    value[i]=constrain(value[i], 0, 255);
  }

  Serial.print(value[0]);
  Serial.print("\t");
  Serial.print(value[1]);
  Serial.print("\n");

  delay(50);
}
