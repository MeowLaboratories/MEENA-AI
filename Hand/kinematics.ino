//drop zone 1 yellow
//drop zone 2 green 
//drop zone 3 blue
//meow 
/*
 * delay(2000);
  anything(0,45,0); // drop_1
  delay(2000);
  anything(138,45,0);
  delay(2000);
  anything(165,50,110);
  delay(10000);
 */

void hand_kin(int p , int  q)
{
  float d, a, b;

double  x = (double) p;
double y = (double) q;

  a = len_a;
  b = len_b;

  
  if (x != 0)
    alpha = (atan(y / x)) * 180/ pi;
  else alpha = 90.0;

  if (x < 0 && y < 0) alpha += 180;
  float x_square = x * x;
  float y_square = y * y;
  float x_y = y_square + x_square; 
     

  d = sqrt(x_y);
 

  theta1 = a * a + d * d - b * b;
  theta1 /= 2 * a * d;
  theta1 = (acos(theta1)) * 180 / pi;
   

  theta2 = a * a + b * b - d * d;
  theta2 /= 2 * a * b;
  theta2 = (acos(theta2)) * 180 / pi;

  theta3 = b * b + d * d - a * a;
  theta3 /= 2 * b * d;
  theta3 = (acos(theta3)) * 180 / pi;

  apos = (int)alpha - (int)theta1;
  bpos = 180-(int)theta2;
  cpos =45* (theta2/alpha);
  //cpos = (int)alpha - (int)theta1;
  Serial.println(bpos);
}

void take_pos(int p , int q)
{
  hand_kin(p , q);

  apos *= 2;
  apos /= 3;
  bpos *= 2;
  bpos /= 3;
  cpos += 60;

  apos += 7;
  
  anything(apos,bpos,cpos);
}

void grab()
{
  grab_l.write(70);
  grab_r.write(90);
}

void releasee()
{
  grab_l.write(20);
  grab_r.write(140);
}

void lift_up()
{
  //lift.write(130);
  int i = 95;
  while( i <= 130)
  {
    lift.write(i);
    i++;
    delay(10);
  }
}

void lift_down()
{
  int i = 130;
  while( i >= 95)
  {
    lift.write(i);
    i--;
    delay(10);
  }
}

void drop(char meow)
{
           if(meow == 'g' )
         {
            //delay(2000);
            anything(165,50,110);
            //delay(1000);
            lift_down();
            delay(500);
            releasee();
            delay(500);
         }

        else if(meow == 'b' )
         {
            //delay(2000);
            anything(138,45,0);
            //delay(1000);
            lift_down();
            delay(500);
            releasee();
            delay(500);
         }

         else
         {
            //delay(2000);
            anything(0,45,0);
            //delay(1000);
            lift_down();
            delay(500);
            releasee();
            delay(500);
         }
}

