/* Case 1. digital input -> digital output */
const int led[6]={3,4,5,6,7,8}; //led를 3~8번 Pin에 연결합니다
const int button=2; //button을 2번 Pin에 연결합니다
int randNumber; //난수를 저장하는 변수선언
int last_state=0; //버튼의 과거상태를 저장하는 변수선언 
int current_state=0; //버튼의 현재상태를 저장하는 변수선언 

void setup()
{
  Serial.begin(9600); //시리얼 통신을 9600속도로 시작
  pinMode(button, INPUT); //button을 입력으로 지정
  for(int i=0; i<6; i++)
  {
    pinMode(led[i], OUTPUT); //led 6개를 출력으로 지정
  }
  randomSeed(analogRead(0)); //Seed값을 floating상태인 analog 0번 Pin에서 읽습니다
  Serial.println("");
  Serial.println("Case 1. digital input -> digital output");
  Serial.println("<<< DICE GAME >>>");
  Serial.println("press the button");
}

void loop()
{
  current_state=digitalRead(button); //버튼의 상태를 읽어 current_state값에 넣음
  if(current_state!=last_state) //Button debouncing
  {
    if(current_state==HIGH)
    {
      Serial.println("Button ON!");
      Serial.println("Roll the dice");
      randNumber=random(6); //0~5 사이의 난수를 생성합니다
      Serial.print("dice: ");
      Serial.println(randNumber+1);
      ledon(randNumber); //함수호출
    }
    last_state=current_state;
    delay(50);
  }
}
/* 
  ledon함수는 매개변수 number의 수만큼 켜지고 2초동안 delay합니다
  그 뒤 모든 LED가 꺼지고 blink를 3회반복하고 종료됩니다.
*/
void ledon(int number)
{  
  for(int i=0; i<=number; i++)
    digitalWrite(led[i], HIGH);
  Serial.print("turn on ");
  Serial.print(number+1);
  Serial.println(" light(s)");
  Serial.println("wait for 2sec");
  delay(2000);
  for(int i=0; i<6; i++)
    digitalWrite(led[i], LOW);
  Serial.println("All LED OFF");
  delay(300);
  Serial.println("All LED blink");
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<6; j++)
       digitalWrite(led[j], HIGH);
    Serial.println("wait for 0.5sec");
    delay(500);
    for(int j=0; j<6; j++)
       digitalWrite(led[j], LOW);
    Serial.println("wait for 0.5sec");
    delay(500);
  }
  Serial.println("Next Turn!!\n");
}
