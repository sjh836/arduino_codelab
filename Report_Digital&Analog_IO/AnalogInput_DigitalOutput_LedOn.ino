/* Case 3. analog input -> digital output */
const int led[8]={3,4,5,6,7,8,9,10}; //8개의 pin을 연결
const int pot=0; //가변저항을 0pin에 연결
int value;
int last_value=0;

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<8;i++)
    pinMode(led[i],OUTPUT);
  Serial.println("");
  Serial.println("Case 3. analog input -> digital output");
  Serial.println("Turn the potentiometer");
}
void loop()
{
  value=analogRead(pot); //가변저항으로부터 값을 읽어 value값에 넣음
  value=map(value, 0, 1023, 0, 255); //10비트를 8비트로 맵핑
  value=constrain(value, 0, 255); //value값을 0~255으로 제한
  if(value!=last_value) //가변저항을 돌릴 때만 출력
  {
    Serial.print("Value: ");
    Serial.print(value);
    Serial.print("\t");

    /*
       value(가변저항값)를 8등분하여 특정 범위일때 led가 켜지는 갯수를 컨트롤하였습니다. 
    */
    if(value==0)
      ledon(0);
    else if(value<32)
      ledon(1);
    else if(value<64)
      ledon(2);
    else if(value<96)
      ledon(3);
    else if(value<128)
      ledon(4);
    else if(value<160)
      ledon(5);
    else if(value<192)
      ledon(6);
    else if(value<224)
      ledon(7);
    else
      ledon(8);
  }
  last_value=value;
}
/*
    ledon함수는 처음에 모든 led를 off하고 매개변수로 들어온 number값만큼 다시 led를 on합니다
 */
void ledon(int number)
{
  for(int i=0;i<8;i++)
    digitalWrite(led[i],LOW);
  for(int i=0;i<number;i++)
    digitalWrite(led[i],HIGH);
  Serial.print("turn on ");
  Serial.print(number);
  Serial.println(" light(s)");
}
