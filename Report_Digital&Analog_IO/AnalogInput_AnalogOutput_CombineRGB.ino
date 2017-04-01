/* Case 4. analog input -> analog output */
const int rgbled[3]={9,10,11}; ///(pin) 11=RedLed, 10=GreenLed, 9=BlueLed
const int led[3]={3,5,6}; ///(pin) 6=RedLed, 5=GreenLed, 3=BlueLed
const int pot[3]={0,1,2}; //(pin) 2=RedLed, 1=GreenLed, 0=BlueLed
int value[3]={0}; //(index) 0=Red, 1=Green, 2=Blue
int last_value[3]={0};

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  {
    pinMode(rgbled[i],OUTPUT);
    pinMode(led[i],OUTPUT);
  }
  Serial.println("");
  Serial.println("Case 4. analog input -> analog output");
  Serial.println("Turn the potentiometer");
}
void loop()
{
  for(int i=0;i<3;i++)
  {
    value[i]=analogRead(pot[i]); //가변저항으로부터 값을 읽어 value값에 넣음
    value[i]=map(value[i], 0, 1023, 0, 255); //10비트를 8비트로 맵핑
    value[i]=constrain(value[i], 0, 255); //value값을 0~255으로 제한
  }
  for(int i=0;i<3;i++)
  {
    if(value[i]!=last_value[i]) //가변저항을 돌릴 때만 출력
      setColor(value[0], value[1], value[2]);
    last_value[i]=value[i];
  }
  delay(50);
}
/*
    setColor함수는 매개변수 값에 따라 PWM으로 RGB LED와 단색 LED를 출력합니다.
    단색LED의 Combine버전이 RGB LED임을 알 수 있습니다
 */
void setColor(int red, int green, int blue)
{
  analogWrite(led[2],red);
  analogWrite(rgbled[2],red);
  Serial.print("Red: ");
  Serial.print(red);
  analogWrite(led[1],green);
  analogWrite(rgbled[1],green);
  Serial.print("\tGreen: ");
  Serial.print(green);
  analogWrite(led[0],blue);
  analogWrite(rgbled[0],blue);
  Serial.print("\tBlue: ");
  Serial.print(blue);
  Serial.println("");
}

