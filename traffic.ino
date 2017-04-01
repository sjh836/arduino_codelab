int ledred=9;
int ledyellow=8;
int ledgreen=7;

void setup()
{
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
}

void loop() {
  digitalWrite(ledred, HIGH);   
  delay(5000);              
  digitalWrite(ledyellow, HIGH);    
  delay(2000);
  digitalWrite(ledred, LOW);   
  digitalWrite(ledyellow, LOW);
  for(int i=0; i<5;i++)
  {
    digitalWrite(ledgreen, HIGH);
    delay(1000);
    digitalWrite(ledgreen, LOW); 
    delay(1000);     
  }
  digitalWrite(ledyellow, HIGH);    
  delay(2000);
  digitalWrite(ledyellow, LOW);              
}
