/* Case 1. smartphone application으로 부터 숫자(R,G,B)를 입력시켜서 RGB LED을 이용하여 색상을 디자인하기 */
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

SoftwareSerial BT(12, 13); //블루투스모듈에 연결하고 Tx를 12번 pin, Rx를 13번 pin으로 설정한다
const int led[3]={9,10,11}; //(pin) 11=RedLed, 10=GreenLed, 9=BlueLed
int value[3]={0}; //(index) 0=Red, 1=Green, 2=Blue

void setup()
{
  BT.begin(9600); //블루투스 통신을 9600속도로 시작
  Serial.begin(9600); //시리얼 통신을 9600속도로 시작
  for(int i=0;i<3;i++)
  {
    pinMode(led[i],OUTPUT); //led 3개를 출력으로 지정
  }
  Serial.println("");
  Serial.println("Case 1.");
  Serial.println("<<< RGB LED: Smartphone application can make all the colors >>>"); 
  Serial.println("Input the RGB value through bluetooth");
}
void loop()
{
  if(BT.available()>0) //블루투스 포트의 수신 버퍼에 저장된 데이터 개수를 반환
  {
    for(int i=0;i<3;i++)
    {
      value[i]=BT.parseInt(); //블루투스 버퍼에 있는 데이터 중 다음에 사용할 것을 Int형으로 형변환하여 반환
      value[i]=constrain(value[i], 0, 255); //value값을 0~255으로 제한
    }
    setColor(value[0], value[1], value[2]); //함수호출
  }
}
/*
  (pin) 11=RedLed, 10=GreenLed, 9=BlueLed
  (index) 0=BlueLed, 1=GreenLed, 2=RedLed
  setColor함수는 매개변수 값에 따라 PWM으로 RGB LED를 출력합니다.
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
