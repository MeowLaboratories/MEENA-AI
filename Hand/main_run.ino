void main_run()
{
  int i, j, a;

  while (1)
  {
    releasee();
    lift_down();
    take_pos(15, 30);

    if (sonar() < 30)
    {
      delay(10);

      a = 0;
      while (sonar() < 30)
      {
        delay(10);
        a++;
      }

      if (a > 3)
      {
        i = 10;
        j = 30;

        while (1)
        {
          take_pos(i--, j);

          if (sonar() < 30) break;
          delay(20);

        }

        while (sonar() > 5)
        {
          delay(20);
          take_pos(i, j++);
        }

        grab();
        lift_up();


      }
    }

    delay(10);
  }
}

void grab_thingies()
{
  anything(0, 50, 140);
  lift_down();
  releasee();

  int  i = 0;
  long  dis = sonar();
  while (dis > 3 && dis != 0)
  {
    anything(i, 50, 110);
    delay(10);
    i++;
    dis = sonar();
  }

  // anything(i+5,50,110);

  grab();
  delay(1000);
  lift_up();

  anything(90, 50, 140);
  lift_down();
  delay(1000);
  releasee();
  delay(2000);
  anything(0, 50, 140);
  
}
void take_thingies()
{
  anything(60, 50, 140);
  lift_down();
  releasee();

  int  i = 60;
  long  dis = sonar();
  while (dis > 3 && dis != 0)
  {
    anything(i, 50, 110);
    delay(10);
    i++;
    dis = sonar();
  }

  // anything(i+5,50,110);

  grab();
  delay(1000);
  lift_up();

  anything(30, 50, 140);
  lift_down();
  delay(1000);
  releasee();
  delay(2000);
  anything(0, 50, 140);
}

