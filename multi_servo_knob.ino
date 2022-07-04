#include <Servo.h>

const int potpin1 = A0;
const int potpin2 = A1;
const int potpin3 = A2;
const int potpin4 = A3;
const int potpin5 = A4;

const int servpin1 = 3;
const int servpin2 = 5; 
const int servpin3 = 6;
const int servpin4 = 9; 
const int servpin5 = 10;
 

int potval1;
int potval2;
int potval3;
int potval4;
int potval5;

int previous1 = 0;
int previous2 = 0;
int previous3 = 0;
int previous4 = 0;
int previous5 = 0;



int long newval1 = 0;
int long newval2 = 0; 
int long newval3 = 0;
int long newval4 = 0; 
int long newval5 = 0;


Servo hand;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;


void setup(){
pinMode(potpin1, INPUT);
pinMode(potpin2, INPUT);
pinMode(potpin3, INPUT);
pinMode(potpin4, INPUT);
pinMode(potpin5, INPUT);

hand.attach(servpin1);
wrist.attach(servpin2);
elbow.attach(servpin3);
shoulder.attach(servpin4);
base.attach(servpin5);
  
}


void loop(){

potval1 = analogRead(potpin1);
potval2 = analogRead(potpin2);
potval3 = analogRead(potpin3);
potval4 = analogRead(potpin4);
potval5 = analogRead(potpin5);




if((potval1 > previous1 + 8 ) or (potval1 < previous1-8)){
newval1 = map(potval1, 0, 1023, 10, 170);
hand.write(newval1);
}

if((potval2 > previous2 + 8 ) or (potval2 < previous2-8)){
newval2 = map(potval2, 0, 1023, 10, 170);
wrist.write(newval2);
}

if((potval3 > previous3 + 6 ) or (potval3 < previous3-6)){
newval3 = map(potval3, 0, 1023, 10, 170);
elbow.write(newval3);
}

if((potval4 > previous4 + 6 ) or (potval4 < previous4-6)){
newval4 = map(potval4, 0, 1023, 10, 170);
shoulder.write(newval4);
}

if((potval5 > previous5 + 6 ) or (potval5 < previous5-6)){
newval5 = map(potval5, 0, 1023, 10, 170);
base.write(newval5);
}

previous1 = potval1;
previous2 = potval2;
previous3 = potval3;
previous4 = potval4;
previous5 = potval5;

delay(100);

  
}
