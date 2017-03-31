const int redled=7;
const int yellowled=8;
const int greenled=9;
const int button=2;
int last_state=0;
int current_state=0;
int cnt=0;

void setup()
{
  Serial.begin(9600);
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(button, INPUT);
  Serial.println("");
  Serial.println("Name: LEE, JungHoon");
  Serial.println("Student ID: 2012335054");
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
      cnt++;
      Serial.println(cnt);
      if(cnt%3==1)
      {
        Serial.println("Red LED ON, Yellow and Green LED OFF");
       digitalWrite(redled, HIGH);
       digitalWrite(yellowled, LOW);
       digitalWrite(greenled, LOW);
      }
      else if(cnt%3==2)
      {
        Serial.println("Yellow LED ON, Red and Green LED OFF");
       digitalWrite(redled, LOW);
       digitalWrite(yellowled, HIGH);
       digitalWrite(greenled, LOW);
      }
      else
      {
        Serial.println("Green LED ON, Red and Yellow LED OFF");
       digitalWrite(redled, LOW);
       digitalWrite(yellowled, LOW);
       digitalWrite(greenled, HIGH);
      }
    }
    last_state=current_state;
    delay(50);
  }
}

