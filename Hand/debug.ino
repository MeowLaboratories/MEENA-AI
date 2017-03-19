void debug()
{
  Serial.begin(9600);
  while(1)
  {
    //Serial.println(pro());
    pro_debug();
  }
}

void debug_color()
{
  Serial.print("red = ");
  
  Serial.print(color('r') / color('n'));
  Serial.print("      ");

  Serial.print("green = ");
  Serial.print(color('g') / color('n'));
  Serial.print("      ");

  Serial.print("blue = ");
  Serial.print(color('b') / color('n'));
  Serial.print("      ");

  Serial.print("no filter = ");
  Serial.print(color('n') );
  Serial.println();

  delay(50);

  /*
   * 
   */
}

void debug_sonar()
{
  Serial.println(sonar());
  delay(10);
}

void debug_ir()
{
  Serial.println(ir_prox());
  delay(10);
}
void pro_debug()
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

  Serial.print("red = ");

  Serial.print(R);
  Serial.print("      ");

  Serial.print("green = ");
  Serial.print(G);
  Serial.print("      ");

  Serial.print("blue = ");
  Serial.print(B);
  Serial.print("      ");

  Serial.print("no filter = ");
  Serial.print(n);
  Serial.println();
}
