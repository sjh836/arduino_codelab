const int led[6]={3,4,5,6,7,8};
const int button=2;
int randNumber;
int last_state=0;
int current_state=0;

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  for(int i=0; i<6; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  Serial.println("");
  Serial.println("Name: LEE, JungHoon");
  Serial.println("Student ID: 2012335054");
  Serial.println("<<< DICE GAME >>>");
  Serial.println("press the button");
}

void loop()
{
  current_state=digitalRead(button);
  if(current_state!=last_state)
  {
    delay(5);
    if(current_state==HIGH)
    {
      Serial.println("Button ON!");
      Serial.println("Roll the dice");
      randomSeed(analogRead(A0));
      randNumber=random(6);
      Serial.print("dice: ");
      Serial.println(randNumber+1);
      
      switch(randNumber)
      {
          case 0:
           ledon(0);
          break;
    
          case 1:
          ledon(1);
          break;
    
          case 2:
          ledon(2);
          break;
    
          case 3:
          ledon(3);
          break;
    
          case 4:
          ledon(4);
          break;
    
          case 5:
          ledon(5);
          break;
       }
    }
    last_state=current_state;
    delay(50);
  }
}
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
