/* 블루투스 Setting */

#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
SoftwareSerial BT(12, 13); //블루투스모듈에 연결하고 Tx를 12번 pin, Rx를 13번 pin으로 설정한다
 
void setup()  
{
  Serial.begin(9600); //시리얼 통신을 9600속도로 시작
  BT.begin(9600);  //블루투스 통신을 9600속도로 시작
}
 
void loop()
{
  if (BT.available()) //블루투스 포트의 수신 버퍼에 저장된 데이터 개수를 반환
  {
    Serial.write(BT.read()); //블루투스에서 전송된 문자를 읽어 시리얼모니터 출력
  }
  if (Serial.available()) //시리얼 포트의 수신 버퍼에 저장된 데이터 개수를 반환
  {
    BT.write(Serial.read()); //시리얼모니터에서 전송된 문자를 읽어 블루투스에 출력
  }
}
