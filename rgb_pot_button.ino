const int led[3]={9,10,11}; //9=blue, 10=green, 11=red
int pot[3]={0,1,2}; //2=red, 1=green, 0=blue
int button[3]={2,3,4}; //2=blue, 3=green, 4=red
int value[3]={0}; //0=red, 1=green, 2=blue
int combine[3]={0}; //0=red, 1=green, 2=blue
int last[3]={0};
int current[3]={0};
int last_combine[3]={0};

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  {
    pinMode(led[i],OUTPUT);
    pinMode(button[i],INPUT);
  }
}
void loop()
{
  for(int i=0;i<3;i++)
  {
    current[i]=digitalRead(button[i]);
    if(current[i]!=last[i])
    {
      if(current[i]==HIGH) //value: 0=red, 1=green, 2=blue
      {
        value[i]+=25;
        if(value[i]>255)
        {
          value[i]=0;
          combine[i]=0;
        }
      }
      last[i]=current[i];
      delay(50);
    }
  }
  
  for(int i=0;i<3;i++)
  {
    pot[i]=analogRead(i);
    pot[i]=map(pot[i], 200, 900, 0, 255);
    pot[i]=constrain(pot[i], 0, 255);

    combine[i]=value[i]+pot[i];
    if(combine[i]>255)
    {
      value[i]=0;
      combine[i]=255;
    }
  }
  if(last_combine[0]!=combine[0]||last_combine[1]!=combine[1]||last_combine[2]!=combine[2])
    setColor(combine[0], combine[1], combine[2]);
  for(int i=0;i<3;i++)
  {
    last_combine[i]=combine[i];
  }
  
  delay(50);
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

