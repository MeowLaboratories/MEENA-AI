#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HomeSerial(A8, A9); // rx tx

#define pi 3.14159265

#define trigPin 30
#define echoPin 31

#define ir A0

#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define out 12

Servo base;
Servo elbow;
Servo wrist;
Servo lift;
Servo grab_l;
Servo grab_r;

//char str[10];

int apos = 0;
int bpos = 0;
int cpos = 0;
double len_a, len_b;
double alpha, theta1, theta2, theta3, gama;

int base_p = 0, elbow_p = 0, lift_p = 130, wrist_p = 30;

void setup()
{
  //serial
  //Serial1.begin(9600);
  Serial.begin(9600);

  HomeSerial.begin(38400);

  //sonar
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //hand
  grab_l.attach(3);
  grab_l.write(40);
  grab_r.attach(2);
  grab_r.write(120);
  wrist.attach(5); // 0 theke 100. 0 hoilo daaner dike
  wrist.write(wrist_p);
  elbow.attach(6);
  elbow.write(elbow_p); // 0 theke shuru
  lift.attach(4);
  lift.write(lift_p); // 80 hoilo grab er height.. 120 hoilo upore thakbe

  base.attach(7);
  base.write(base_p);

  len_a = 17;//length of arms
  len_b = 14;

  //color module initialization
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(out, INPUT);

  //pos
  //releasee();
  //lift_down();
  anything(0, 50, 110);
  //delay(2000);

  releasee();
  lift_down();
  anything(0, 50, 110);

  pinMode(A10,OUTPUT);
  pinMode(A11,OUTPUT);
  pinMode(A12,OUTPUT);
  pinMode(A13,OUTPUT);

  digitalWrite(A10,HIGH);
  digitalWrite(A11,HIGH);
  digitalWrite(A12,HIGH);
  digitalWrite(A13,HIGH);

}

void loop() {

  if ( HomeSerial.available() )
  {
    String ln = read_ln();

    Serial.println(ln[0]);

    if(ln[0] == 'b') grab_thingies();
    if(ln[0] == 't') take_thingies();
    if(ln[0] == 'o') digitalWrite(A10,LOW);
    if(ln[0] == 'n') digitalWrite(A10,HIGH);
  }
  delay(100);
}

String read_ln()
{
  String ln = "";
  while (1)
  {
    if (HomeSerial.available() ) {
      char ch = HomeSerial.read();
      if (ch =='\n')
        break;
      else
        ln = ln + ch;
    }
  }
  return ln;
}
