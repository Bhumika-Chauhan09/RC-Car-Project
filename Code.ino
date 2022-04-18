/*
 * Bhumika Chauhan 
 * 2110994802 
 * Bluetooth based remote Controlled Car 
 * download the application Bluetooth RC Car from play store to run your rover 
*/
char t;
 
void setup() {
pinMode(13,OUTPUT);   //Left side motors forward
pinMode(12,OUTPUT);   //Left side motors reverse
pinMode(11,OUTPUT);   //Right side motors forward
pinMode(10,OUTPUT);   //Right side motors reverse
pinMode(9,OUTPUT);    //Led Pin
pinMode(8,OUTPUT);    // BUZZER Pin
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available())
{
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //Forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //Backward(all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //Turn Right (left side motors rotate in forward direction)
  digitalWrite(13,HIGH);
}
 
else if(t == 'R'){      //Turn Left (right side motors rotate in forward direction)
  digitalWrite(11,HIGH);
}
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
