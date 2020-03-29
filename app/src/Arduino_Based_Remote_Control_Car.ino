//RC Receiver input pins
const int A  =   2;
const int B  =   3;
const int C  =   4;
const int D  =   5;

//Output pins to L293 DC Motor Driver
const int EnA     =   8; 
const int InOne   =   9;
const int InTwo   =  10;

const int EnB     =  11;
const int InThree =  12;
const int InFour  =  13;


int Astate     =   0;
int Bstate     =   0;
int Cstate     =   0;
int Dstate     =   0;

//Configure input, output pins
void setup() {
  
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);

  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT); 

  pinMode(InOne, OUTPUT); 
  pinMode(InTwo, OUTPUT); 
  pinMode(InThree, OUTPUT); 
  pinMode(InFour, OUTPUT);       
}

void loop(){
  
  //Read the status of RC Receiver module
  int Astate     =   digitalRead(A);
  int Bstate     =   digitalRead(B);
  int Cstate     =   digitalRead(C);
  int Dstate     =   digitalRead(D);
  
  //If button A pressed, call the move forward function
  if (Astate == HIGH) {       
      MoveForward();
  } 
  //If button B is pressed, call the turn right function
  else if(Bstate == HIGH){
      TurnRight();
  }
  //If button C pressed, call the turn left function
  else if(Cstate == HIGH){
      TurnLeft();
  }
  //If button A pressed, call the reverse function
  else if(Dstate == HIGH){
      Reverse();
  }
  //Else stop the car
  else
  {
      digitalWrite(EnA, LOW); 
      digitalWrite(InThree, LOW); 
      digitalWrite(InFour, LOW); 
      
      digitalWrite(InOne, LOW); 
      digitalWrite(InTwo, LOW); 
      digitalWrite(EnB, LOW); 
  }
}
//Move forward
void MoveForward()
{
      digitalWrite(EnA, HIGH); 
      digitalWrite(InOne, HIGH); 
      digitalWrite(InTwo, LOW); 
      
      digitalWrite(EnB, HIGH); 
      digitalWrite(InThree, LOW); 
      digitalWrite(InFour, HIGH);   
}
//Turn left
void TurnLeft()
{
      digitalWrite(EnA, HIGH); 
      digitalWrite(InOne, HIGH); 
      digitalWrite(InTwo, LOW); 
      
      digitalWrite(EnB, HIGH); 
      digitalWrite(InThree, LOW); 
      digitalWrite(InFour, LOW); 
}
//Turn right
void TurnRight()
{
      digitalWrite(EnA, HIGH); 
      digitalWrite(InOne, LOW); 
      digitalWrite(InTwo, LOW); 
      
      digitalWrite(EnB, HIGH); 
      digitalWrite(InThree, LOW); 
      digitalWrite(InFour, HIGH); 
}
//Reverse 
void Reverse()
{
      digitalWrite(EnA, HIGH); 
      digitalWrite(InOne, LOW); 
      digitalWrite(InTwo, HIGH); 
      
      digitalWrite(EnB, HIGH); 
      digitalWrite(InThree, HIGH); 
      digitalWrite(InFour, LOW);  
}
