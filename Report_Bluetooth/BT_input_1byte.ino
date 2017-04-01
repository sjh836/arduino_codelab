/* Case2. R:0-49, G:50-99, B:100-149을 만족하도록 App Inventor을 이용하여 3개의 slide을 만들어서 색상을 디자인하기 */
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

SoftwareSerial BT(12, 13); //블루투스모듈에 연결하고 Tx를 12번 pin, Rx를 13번 pin으로 설정한다
const int led[3]={9,10,11}; //(pin) 11=RedLed, 10=GreenLed, 9=BlueLed
int data=0; //블루투스로 입력받은 1byte 값을 저장하는 변수 선언
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
  Serial.println("Case 2.");
  Serial.println("<<< RGB LED: App slider can make all the colors >>>"); 
  Serial.println("Control the RGB slider"); 
}
void loop()
{
  if(BT.available()>0) //블루투스 포트의 수신 버퍼에 저장된 데이터 개수를 반환
  { //반환갯수가 1개이상일때만 문장실행
      data=BT.read(); //블루투스로 부터 값을 입력받아 저장
      if(data<50) //data에 0~49값이 들어오면 Red Slider로 인식
      {
        value[0]=map(data, 0, 49, 0, 255); //0~49를 0~255로 맵핑
      }
      else if(data<100) //data에 0~99값이 들어오면 Red Slider로 인식
      {
        value[1]=map(data, 50, 99, 0, 255); //50~99를 0~255로 맵핑
      }
      else //data에 100~149값이 들어오면 Red Slider로 인식
      {
        value[2]=map(data, 100, 149, 0, 255); //100~149를 0~255로 맵핑
      }
      setColor(value[0], value[1], value[2]); //함수호출
  }
}
/*
  (pin) 11=RedLed, 10=GreenLed, 9=BlueLed
  (index) 0=BlueLed, 1=GreenLed, 2=RedLed
  setColor함수는 매개변수 값에 따라 PWM으로 RGB LED를 출력합니다.
*/
void setColor(int red, int green, int blue) //9=blue, 10=green, 11=red
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
