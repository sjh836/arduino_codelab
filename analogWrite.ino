const int LED=3;
const int button=2;
int current=0;
int last=0;
int cnt=0;
int light=0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  current=digitalRead(button);
  if(current!=last)
  {
    if(current==HIGH)
    {
      cnt++;
      Serial.println(cnt);
      if(cnt>0&&cnt<=10)
      {
        light+=25;  
        Serial.println(light);
        analogWrite(LED, light);
      }
      else if(cnt>10&&cnt<=20)
      {
        light-=25;      
        analogWrite(LED, light);
        if(cnt==20)
          cnt=0;
      }
    }
    last=current;
    delay(50);
  }
}
