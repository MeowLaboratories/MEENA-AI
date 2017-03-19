void box_zone() {
  int a,i,j,k,l;
  long dis;

  i = 5;
  j = 110;
  k = 20;
  
  anything(0,50,110);
  lift_down();
  releasee();

  unsigned long cur,endd; 

  while (1)
  {
    anything(0,50,110);
    lift_down();
    releasee();

    a = 0;
    if(sonar() < 30)
    {
       delay(10);
       while(sonar() < 30)
       {
        delay(10);
        a++;
        //if (a>100)break;
       }

       delay(3000);

       if(a > 3)
       {
         i = 0;
         dis = sonar();
         while(dis > 3 && dis != 0)
         {
           anything(i,50,110);
           delay(10);
           i++;
           dis = sonar();
         }

        // anything(i+5,50,110);

         grab();
         delay(1000);
         lift_up();
         //delay(1000);

        // debug();
         char meow = pro();
         drop(meow);        
       }
    }
    else delay(10);
  }

  delay(10);
}

