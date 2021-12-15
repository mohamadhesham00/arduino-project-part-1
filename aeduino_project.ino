#include <Servo.h>
int led=13;
int ldr=A0;
int sensorvalue=0;
Servo myservo;
int daytime=0;
int pos=0 ;
int trigPin =12;
int echoPin = 11;
void setup() 
{  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  myservo.attach(10); 

}

void loop() 
{
  long duration, distance;
  daytime=analogRead(ldr);
  if(daytime<=300)
  {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
     
    if (distance < 25) 
    {  
      digitalWrite(led,HIGH);
      Serial.println("some one is in the room");
    }
    else
    {
       digitalWrite(led,LOW);
       Serial.println("no one is in the room");

 
    }
    
    if(pos==0)
    {
    for (pos = 0; pos <=180; pos += 5) 
    { 
        myservo.write(pos); 
        delay(15);
    }
    }
    if(pos==180)
    {
    for(pos=180;pos>=0;pos-=5)
    {
      myservo.write(pos); 
        delay(15);
    }
    }
    
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("no one is in the room");

     
  }


  
}
