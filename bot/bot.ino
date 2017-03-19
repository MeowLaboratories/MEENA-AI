#include <Servo.h>

Servo servoL, servoR, servo, servoStore;

#define tx 18
#define rx 19

char ch = 'n';

char a = '0', b = '0', x[3];

const byte EnA = 2, EnB = 3;
const byte InA = 30, InB = 28, InC = 26, InD = 24;

int motorSpeed = 100;

int finger = 2, arm = 1, store = 3, sr = 55, sl = 105;


//variables........
int brk = 0, valArm = 45, valStore = 150, a1, b1;


void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);

  int a, b, c;
  servo.attach(7);
  servoL.attach(5);
  servoR.attach(6);

  //    servoL.write (servoL.read());
  //    servo.write (servoR.read());
  //Serial.print(a);
  //Serial.print(" ");
  //
  //Serial.println(b);

  servo.write(50);
  servoL.write(105);
  servoR.write(55);



  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);

  pinMode(InA, OUTPUT);
  pinMode(InB, OUTPUT);
  pinMode(InC, OUTPUT);
  pinMode(InD, OUTPUT);

}

void loop()

{
  if (Serial1.available()) {
    ch = Serial1.read();
  }

  if (ch == 'n') {
    move(0, 0);

    if (brk == 1) {
      move(-200, -200);
      delay(150);
      move(0, 0);

      brk = 100;
    }

    else if (brk == 2) {
      move(-150, -150);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 3) {
      move(-100, -100);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 4) {
      move(-150, -150);
      delay(150);
      move(0, 0);

      brk = 100;
    }





    else if (brk == 5) {
      move(200, 200);
      delay(150);
      move(0, 0);

      brk = 100;
    }

    else if (brk == 6) {
      move(150, 150);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 7) {
      move(100, 100);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 8) {
      move(80, 80);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 9) {
      move(50, 50);
      delay(150);
      move(0, 0);

      brk = 100;
    }





    else if (brk == 10) {
      move(-200, 200);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 11) {
      move(-150, 150);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 12) {
      move(-100, 100);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 13) {
      move(-50, 50);
      delay(150);
      move(0, 0);

      brk = 100;
    }



    else if (brk == 14) {
      move(200, -200);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 15) {
      move(150, -150);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 16) {
      move(100, -100);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 17) {
      move(80, -80);
      delay(150);
      move(0, 0);

      brk = 100;
    }
    else if (brk == 18) {
      move(50, -50);
      delay(150);
      move(0, 0);

      brk = 100;
    }








  }

  //0-3
  else if (ch == '0') {
    move(255, 255);
    brk = 1;
  }

  else if (ch == '1') {
    move(200, 200);
    brk = 2;
  }
  else if (ch == '2') {
    move(150, 150);
    brk = 3;
  }
  else if (ch == '3') {
    move(100, 100);
    brk = 4;
  }

  //5-9
  else if (ch == '9') {
    move(-255, -255);
    brk = 5;
  }
  else if (ch == '8') {
    move(-200, -200);
    brk = 6;
  }
  else if (ch == '7') {
    move(-155, -155);
    brk = 7;
  }
  else if (ch == '6') {
    move(-100, -100);
    brk = 8;
  }
  else if (ch == '5') {
    move(-55, -55);
    brk = 9;
  }




  //hackbackpack motor

  else if (ch == 'f') {
    move(255, 255);
    delay(10);
    move(0, 0);
  }
  else if (ch == 'x') {
    move(255, -255);
    delay(30);
    move(0, 0);
  }
  else if (ch == 'y') {
    move (-255, 255);
    delay(30);
    move(0, 0);
  }
  else if (ch == 'z') {
    move(-255, -255);
    delay(10);
    move(0, 0);
  }
  else if (ch == 'm') {
    move(0, 0);
  }





  else if (ch == 'G') {
    move(255, -255);
    brk = 10;
  }

  else if (ch == 'H') {
    move(255, -255);
    brk = 10;
  }
  else if (ch == 'J') {
    move(250, -250);
    brk = 11;
  }
  else if (ch == 'K') {
    move(155, -155);
    brk = 12;
  }
  else if (ch == 'L') {
    move(100, -100);
    brk = 13;
  }



  //  else if(ch == 'G'){
  //      move(-255,255);
  //      brk = 14;
  //  }
  else if (ch == 'Q') {
    move(-250, 250);
    brk = 15;
  }
  else if (ch == 'W') {
    move(-155, 155);
    brk = 16;
  }
  else if (ch == 'E') {
    move(-100, 100);
    brk = 17;
  }
  else if (ch == 'R') {
    move(-55, 55);
    brk = 18;
  }



  //hackbackpack servo
  else if (ch == 'a') {
    servoArm(-3);
  }

  else if (ch == 'c') {
    servoArm(3);
  }


  else if (ch == 'b') {
    //    sr++;
    //      sl--;
    servoR.write(55);
    servoL.write(105);
  }

  else if (ch == 'd') {
    sr--;
    sl++;
    servoR.write(70);
    servoL.write(80);
  }

}






void move(int left, int right) {

  if (motorSpeed != 100) {
    left = (left * motorSpeed) / 100;
    right = (right * motorSpeed) / 100;
  }

  int speedA, speedB;

  if (right >= 0) {
    speedA = right;
    analogWrite(EnA, speedA);
    digitalWrite(InA, HIGH);
    digitalWrite(InB, LOW);
  }
  else if (right < 0) {
    speedA = -right;
    analogWrite(EnA, speedA);
    digitalWrite(InA, LOW);
    digitalWrite(InB, HIGH);
  }


  if (left >= 0) {
    speedB = left;
    analogWrite(EnB, speedB);
    digitalWrite(InC, HIGH);
    digitalWrite(InD, LOW);
  }
  else if (left < 0) {
    speedB = -left;
    analogWrite(EnB, speedB);
    digitalWrite(InC, LOW);
    digitalWrite(InD, HIGH);
  }

}



//void grabber(byte servoNo, int val){
//
//   int currentVal, i;
//
//   if(servoNo == 1){
//      currentVal = servo.read();
//
//      if(val > currentVal){
//         for(i = currentVal; i <= val; i++){
//            servo.write(i);
//            delay(15);
//         }
//         valArm = val;
//      }
//
//      else if(val < currentVal){
//         for(i = currentVal; i >= val; i--){
//            servo.write(i);
//            delay(15);
//         }
//         valArm = val;
//      }
//
//      else {
//          servo.write(val);
//          valArm = val;
//      }
//   }
//
//
//
//   else if(servoNo == 2){
//      servoL.write(180-val-28);
//      servoR.write(val);
//   }
//
//
//
//}



void servoArm(int add) {

  //    valArm = servo.read();

  int newVal = valArm + add;

  if (newVal < 30) {
    newVal = 30;
  }
  else if (newVal > 168) {
    newVal = 168;
  }

  servo.write(newVal);
  valArm = newVal;
  delay(100);
  //oi +50
}


void servoFinger(int add) {

  //    valArm = servo.read();

  int newVal = valArm + add;

  if (newVal < 30) {
    newVal = 30;
  }
  else if (newVal > 168) {
    newVal = 168;
  }
  servoL.write((180 - newVal) - 28);
  servoR.write(newVal);

  valArm = newVal;
  delay(100);
  //oi +50
}



void servoStr(int add) {

  //    valArm = servo.read();

  int newVal = valStore + add;

  if (newVal < 70) {
    newVal = 70;
  }
  else if (newVal > 150) {
    newVal = 150;
  }

  servoStore.write(newVal);
  valStore = newVal;
  delay(5);
}
