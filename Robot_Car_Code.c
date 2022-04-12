//Initializing the pins according to the way they are wired on the H-bridge

//Right Motor 
int in1 = 9;
int in2 = 8;  
int ConA = 10;

//Left Motor
int in3 = 7;  
int in4 = 6; 
int ConB = 5; 

//Declaring the pin modes
void setup() {
  //Declaring the pin modes for the right Motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ConA, OUTPUT);

  //Declaring the pin modes for the left Motor
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 
  pinMode(ConB, OUTPUT);

  //costant
  Serial.begin(9600);
}

//Initializing the movements through (High-ON, Low-OFF)

//Going Forward
void GoForward(){
 digitalWrite(in1, HIGH);
 digitalWrite(in3, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in4, LOW);
 analogWrite(ConA,145);
 analogWrite(ConB,145);
}

//Turning Left
void GoLeft(){
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(ConA,125);
}

//Turning Left with a greater Speed
void GoLeftSpeed(){
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(ConA,135);
}

//Turning Right
void GoRight(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ConB,125);
}

//Turning Right with a greater Speed
void GoRightSpeed(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ConB,135);
}

//Going Backwards
void GoBackward(){
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH); 
 analogWrite(ConA,110);
 analogWrite(ConB,110);
}

//mainloop with all the previously declared functions
void loop(){

  //Initialize the sensor analogs according to the Arduino Uno placement
   int a0=analogRead(A0);//A0 input reading
   int a1=analogRead(A1);//A1 input reading
   int a2=analogRead(A2);//A2 input reading
   int a3=analogRead(A3);//A3 input reading
   int a4=analogRead(A4);//A4 input reading
  
  //Check the sensor responding:
   Serial.print(a0,DEC);
   Serial.print("\t");
   Serial.print(a1,DEC);
   Serial.print("\t");
   Serial.print(a2,DEC);
   Serial.print("\t");
   Serial.print(a3,DEC);
   Serial.print("\t");
   Serial.println(a4,DEC);

   //Initialize the threshold value
   int threshhold=100;  // when analog value is bigger than the threshold value it means that the sensor is reading a black line
   
  //GoForward when
  
  //WWBWW - forward
  if(a0<threshhold && a1<threshhold && a2>threshhold && a3<threshhold && a4<threshhold){//
  GoForward();
  }
  //BBBBB - foward
  else if(a0>threshhold && a1>threshhold && a2>threshhold && a3>threshhold && a4>threshhold){
   GoForward();
  }

  
  //GoLeftForward when
  
  //BWWWW - left with speed - to adjust the center sensor to the line
  else if(a0>threshhold && a1<threshhold && a2<threshhold && a3<threshhold && a4<threshhold){
    GoLeftSpeed();
   }
  //WBWWW - left
  else if(a0<threshhold && a1>threshhold && a2<threshhold && a3<threshhold && a4<threshhold){
    GoLeft();
   }
  //BBWWW - left
  else if(a0>threshhold && a1>threshhold && a2<threshhold && a3<threshhold && a4<threshhold){
    GoLeft();
   }
  //BBBWW - left
  else if(a0>threshhold && a1>threshhold && a2>threshhold && a3<threshhold && a4<threshhold){
    GoLeft();
   }
   
  //GoRight when

  //WWWWB - right with speed - to adjust the center sensor to the line
  else if(a0<threshhold && a1<threshhold && a2<threshhold && a3<threshhold && a4>threshhold){
    GoRightSpeed();
   }
  //WWWBW - right
  else if(a0<threshhold && a1<threshhold && a2<threshhold && a3>threshhold && a4<threshhold){
    GoRight();
  }
  //WWWBB - right
  else if(a0<threshhold && a1<threshhold && a2<threshhold && a3>threshhold && a4>threshhold){
    GoRight();
  }
  //WWBBB - right
  else if(a0<threshhold && a1<threshhold && a2>threshhold && a3>threshhold && a4>threshhold){
    GoRight();
  }
   
  //GoBackward when
  
  //WWWWW - right
  else if(a0<threshhold && a1<threshhold && a2<threshhold && a3<threshhold && a4<threshhold){
    delay(20); //delay to let the sensors check for the black line
    GoBackward();
  }

}