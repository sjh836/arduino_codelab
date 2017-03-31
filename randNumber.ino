int randNumber;
int count[6]={0};
int cnt=0;

void setup()
{
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Name: LEE, JungHoon");
  Serial.println("Student ID: 2012335054");

  randomSeed(analogRead(0));

for(int i=0; i<100; i++)
{
    randNumber=random(1,7);
  
  switch(randNumber)
  {
    case 1:
    count[0]++;
    break;
    case 2:
    count[1]++;
    break;
    case 3:
    count[2]++;
    break;
    case 4:
    count[3]++;
    break;
    case 5:
    count[4]++;
    break;
    case 6:
    count[5]++;
    break;
  }
  cnt++;
}
  Serial.print("1: ");
  Serial.println(count[0]/(float)cnt);
    Serial.print("2: ");
  Serial.println(count[1]/(float)cnt);
    Serial.print("3: ");
  Serial.println(count[2]/(float)cnt);
    Serial.print("4: ");
  Serial.println(count[3]/(float)cnt);
    Serial.print("5: ");
  Serial.println(count[4]/(float)cnt);
    Serial.print("6: ");
  Serial.println(count[5]/(float)cnt);
}
void loop()
{

}

