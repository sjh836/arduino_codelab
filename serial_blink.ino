const int ledred=9;
const int ledyellow=8;
const int ledgreen=7;
char data;

void setup()
{
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Name: LEE, JungHoon");
  Serial.println("Student ID: 2012335054");
  Serial.println("\nInput the number");
}

void loop()
{
  if(Serial.available()>0)
  {
    data=Serial.read();
    Serial.println(data);
    switch(data)
    {
      case '1':
      Serial.println("1th execute: Red LED Blink");
      blink(ledred);
      break;
      
      case '2':
      Serial.println("2th execute: Yellow LED Blink");
      blink(ledyellow);
      break;
      
      case '3':
      Serial.println("3th execute: Green LED Blink");
      blink(ledgreen);
      break;
      
      case '4':
      Serial.println("4th execute: ALL LED ON");
      digitalWrite(ledred, HIGH);
      digitalWrite(ledyellow, HIGH);
      digitalWrite(ledgreen, HIGH);
      break;
      
      case '5':
      Serial.println("5th execute: ALL LED OFF");
      digitalWrite(ledred, LOW);
      digitalWrite(ledyellow, LOW);
      digitalWrite(ledgreen, LOW);
      break;
      
      case '6':
      Serial.println("6th execute: 3/15 EX1");
      digitalWrite(ledred, HIGH);
      Serial.println("Red LED ON");
      Serial.println("wait for 1sec");    
      delay(1000);              
      digitalWrite(ledyellow, HIGH);
      Serial.println("Yellow LED ON");
      Serial.println("wait for 1sec");     
      delay(1000);
      digitalWrite(ledgreen, HIGH);
      Serial.println("Green LED ON");
      Serial.println("wait for 1sec");    
      delay(1000);
      digitalWrite(ledred, LOW);  
      digitalWrite(ledyellow, LOW);  
      digitalWrite(ledgreen, LOW);
      Serial.println("All LED OFF");
      Serial.println("wait for 1sec");   
      delay(1000);
      break;
      
      case '7':
      Serial.println("7th execute: traffic");
      digitalWrite(ledred, HIGH);
      Serial.println("Red LED ON");
      Serial.println("wait for 5sec");   
      delay(5000);              
      digitalWrite(ledyellow, HIGH); 
      Serial.println("Yellow LED ON");
      Serial.println("wait for 2sec");   
      delay(2000);
      digitalWrite(ledred, LOW);   
      digitalWrite(ledyellow, LOW);
      Serial.println("Red & Yellow LED OFF");
      for(int i=0; i<5;i++)
      { 
        blink(ledgreen);
      }
      digitalWrite(ledyellow, HIGH);
      Serial.println("Yellow LED ON");
      Serial.println("wait for 2sec");    
      delay(2000);
      digitalWrite(ledyellow, LOW);    
      Serial.println("Yellow LED OFF");
      break;
      
      case '8':
      Serial.println("8th execute: 3 color LED on/off");
      for(int i=0; i<8; i++)
        blink(ledred);
      for(int i=0; i<4; i++)
        blink(ledyellow);
      for(int i=0; i<2; i++)
        blink(ledgreen);
      break;
      
      default:
      Serial.println("Error");
      break;
    }
  }
}
void blink(int number)
{
  digitalWrite(number, HIGH);
  Serial.print(number);
  Serial.println("PIN ON");
  Serial.println("wait for 1sec");
  delay(1000);
  digitalWrite(number, LOW);
  Serial.print(number);
  Serial.println("PIN OFF");
  Serial.println("wait for 1sec");
  delay(1000);
}
