long sonar()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  return distance;
}

long ir_prox()
{
  long r = (analogRead(ir) + analogRead(ir) + analogRead(ir)) / 3;

  return r;
}

char check_color()
{
  int r = color('r');
  int b = color('b');
  int g = color('g');
  int n = color('n');

  return 'r';
}

int color(char c)
{
  int freq;
  //color scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  /*
    L  H 2%
    H L 20%
    H H 100%
  */


  /*
    color sensing

    L L RED
    L H BLUE
    H L Clear (no filter)
    H H GREEN
  */

  if (c == 'r')
  {
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);

    freq = pulseIn(out, LOW);
    return freq;
  }

  else if (c == 'g')
  {
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);

    freq = pulseIn(out, LOW);
    return freq;
  }

  else if (c == 'b')
  {
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);

    freq = pulseIn(out, LOW);
    return freq;
  }

  else
  {
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);

    freq = pulseIn(out, LOW);
    return freq;
  }

}

char pro()
{
  unsigned long cur,endd;
   
  int i ;
  long R,G,B,r , g , b,mn,n;

  R = 0;
  G = 0;
  B = 0;

  cur = millis();
  endd = cur + 1000;
  
  for ( i = 0 ;cur < endd  ; i++)
  { 
    cur = millis();
    
     r = color('r');
     g = color('g');
     b = color('b');
     n = color('n');
     mn;

    //r -= n;
    //g -= n;
    //b -= n;

    if ( r <= g && r <= b)
    {
      mn = r;
    }

    if ( g <= r && g <= b)
    {
      mn = g;
    }

    if ( b <= g && b <= r)
    {
      mn = b;
    }

    mn /= 10;

    r /= mn;
    g /= mn;
    b /= mn;
    
    R += r;
    G += g;
    B += b;
  }

  R /= i;
  G /= i;
  B /= i;

  if( R >= 5 && R <= 15  && G >= 10 && G <= 30 && B >= 21 && B <= 50  ) return 'y';
  
    if( R >= 15 && R <= 25 && G >= 5 && G <= 15 && B >= 10 && B <= 20  ) return 'g';
    
      if( R >= 50 && R <= 100 && G >= 20 && G <= 45 && B >= 10 && B <= 20  ) return 'b';

      return 'n';
}

