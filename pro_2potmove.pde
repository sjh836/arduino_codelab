import processing.serial.*;
Serial arduino;  
float topbottom=0; 
float leftright=0; 

void setup() 
{     
  size(500,500); 
  arduino=new Serial(this, "COM4", 9600); 
  arduino.bufferUntil('\n'); 
} 

void draw()
{     
  background(255);
  rect(topbottom, leftright, 120, 120);
}  
void serialEvent(Serial arduino)
{     
  topbottom=float(arduino.readStringUntil('\t'));
  leftright=float(arduino.readStringUntil('\n'));
}