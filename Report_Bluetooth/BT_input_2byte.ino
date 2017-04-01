/* Case 3. R:0-255, G:0-255, B:0-255을 만족하도록 App Inventor을 이용하여 3개의 slide을 만들어서  색상을 디자인하기 */
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

SoftwareSerial BT(12, 13); //블루투스모듈에 연결하고 Tx를 12번 pin, Rx를 13번 pin으로 설정한다
const int led[3]={9,10,11}; //(pin) 11=RedLed, 10=GreenLed, 9=BlueLed
int data[2]={0}; //블루투스로 입력받은 2byte 값을 저장하는 배열 선언
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
  Serial.println("Case 3.");
  Serial.println("<<< RGB LED: App slider can make all the colors >>>"); 
  Serial.println("Control the RGB slider"); 
}
void loop()
{
  if(BT.available()>=2) //블루투스 포트의 수신 버퍼에 저장된 데이터 개수(byte단위)가 2개이상일때만 문장실행
  {
      data[0]=BT.read(); //2byte중 뒤의 8비트를 수신해서 저장, 슬라이더 값을 인식함
      data[1]=BT.read(); //2byte중 앞의 8비트를 수신해서 저장, 각 슬라이더(R,G,B)를 인식함
      Serial.print("data[0]: ");
      Serial.print(data[0]);
      Serial.print("\tdata[1]: ");
      Serial.print(data[1]);
      Serial.println("");
      
      if(data[1]==0) //Red 슬라이더
      {
        value[0]=map(data[0], 0, 255, 0, 255);
        value[0]=constrain(data[0], 0, 255);
      }
      else if(data[1]==1) //Green 슬라이더
      {
        value[1]=map(data[0], 0, 255, 0, 255);
        value[1]=constrain(data[0], 0, 255);
      }
      else if(data[1]==2) //Blue 슬라이더
      {
        value[2]=map(data[0], 0, 255, 0, 255);
        value[2]=constrain(data[0], 0, 255);
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
