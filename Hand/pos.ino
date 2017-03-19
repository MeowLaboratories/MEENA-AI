void anything(int x, int y, int z) {
  int a = (x - base_p );
  int b = (y - elbow_p);
  int c = (z - wrist_p);

  int a1 = 1, b1 = 1, c1 = 1;

  int mx = 0;

  if (a < 0) {
    a *= -1;
    a1 = -1;
  }
  if (b < 0) {
    b *= -1;
    b1 = -1;
  }
  if (c < 0) {
    c *= -1;
    c1 = -1;
  }

  if (a >= b && a >= c) mx = a;
  if (b >= a && b >= c) mx = b;
  if (c >= b && c >= a) mx = c;

  for (int i = 0; i < mx; i++)
  {
    if (base_p != x) 
    {
      base_p += a1;
      base.write(base_p);
    }
    if (elbow_p != y)
    {
      elbow_p += b1;

      elbow.write(elbow_p);
    }
    if (wrist_p != z)
    {
      wrist_p += c1;
      wrist.write(wrist_p);
    }
    delay(15);
  }

}
