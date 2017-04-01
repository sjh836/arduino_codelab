/* Case 2. digital input -> analog output */
const int led[3]={9,10,11}; //(pin) 11=RedLed, 10=GreenLed, 9=BlueLed
int button[3]={2,3,4}; //(pin) 4=Red, 3=Green, 2=Blue 
int value[3]={0}; //(index) 0=Red, 1=Green, 2=Blue
int last[3]={0}; //버튼의 과거상태를 저장하는 변수선언 
int current[3]={0}; //버튼의 현재상태를 저장하는 변수선언 
int set_Interval=25; //시리얼모니터로 입력받아 버튼의 간격값을 저장하는 변수선언, 디폴트값 25

void setup()
{
  Serial.begin(9600); //시리얼 통신을 9600속도로 시작
  for(int i=0;i<3;i++)
  {
    pinMode(led[i],OUTPUT); //led 3개를 출력으로 지정
    pinMode(button[i],INPUT);  //button 3개를 입력으로 지정
  }
  Serial.println("");
  Serial.println("Case 2. digital input -> analog output");
  Serial.println("<<< RGB LED: this can make all the colors >>>"); 
  Serial.println("press the button");
}
void loop()
{
  if(Serial.available()>0) //시리얼 포트의 수신 버퍼에 저장된 데이터 개수를 반환
  {
    set_Interval=Serial.parseInt(); //버퍼에 있는 데이터 중 다음에 사용할 것을 Int형으로 형변환하여 반환
    Serial.print("button interval: ");
    Serial.print(set_Interval);
    Serial.println("");
  }
  for(int i=0;i<3;i++)
  {
    current[i]=digitalRead(button[i]);
    if(current[i]!=last[i]) //button debouncing
    {
      if(current[i]==HIGH)
      {
        value[i]+=set_Interval; //버튼이 눌리면 value값에 set_Interval를 더해줍니다
        if(value[i]>255) //만약 value값이 255를 초과했을 경우 0으로 초기화합니다
          value[i]=0;
        setColor(value[0], value[1], value[2]); //함수호출
      }
      last[i]=current[i];
      delay(50);
    }
  }
}
/*
  (pin) 11=RedLed, 10=GreenLed, 9=BlueLed
  (index) 0=BlueLed, 1=GreenLed, 2=RedLed
  매개변수 값만큼의 밝기로 Led를 출력합니다.
*/
void setColor(int red, int green, int blue)
{
  analogWrite(led[2],red);
  Serial.print("red: ");
  Serial.print(red);
  analogWrite(led[1],green);
  Serial.print("\tgreen: ");
  Serial.print(green);
  analogWrite(led[0],blue);
  Serial.print("\tblue: ");
  Serial.print(blue);
  Serial.println("");
}
