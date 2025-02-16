#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//regular digit format
char rdf[2] = "f";

//Functions

int gcd(int a, int b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}

//Formul itm
//fp = num/denom
//num %= denom

//Formul tif
//num = denom * fp + num

int addfracnum(int fn, int fd, int sn, int sd)
{
  int denomval = lcm(fd, sd);
  fn *= (denomval / fd);
  sn *= (denomval / sd);
  return fn + sn;
}

int subfracnum(int fn, int fd, int sn, int sd)
{
  int denomval = lcm(fd, sd);
  fn *= (denomval / fd);
  sn *= (denomval / sd);
  return fn - sn;
}

//Formul mulfrac
//fn *= sn
//fd *= sd

//Formul divfrac
//fn *= sd
//fd *= sn

//Formul cf
//(snd/sdd) = (fnd/fdd)*(snn/sdn)/(fnn/fdn)
//(tnn/tdn) = (fnn/fdn)*(tnd/tdd)/(fnd/fdd)


int main()
{
  char action[256];
  while (1)
  {
    scanf("%s", &action);
   
    if (!strcmp(action, "exit"))
      return 0;

    if (!strcmp(action, "clear"))
      system("clear");

    if (!strcmp(action, "lof")) //list of functions
      printf("exit clear lof crdf chrdf cf add sub mul div pow rod af sf mf df fd tdap tif itm dtf reduce rt gcd lcm\n");


    if (!strcmp(action, "crdf")) //change regular digit format
    {
      scanf("%s", rdf);
      if (!strcmp(rdf, "d"))
        printf("%%d -> int\n");
      else if (!strcmp(rdf, "f"))
        printf("%%f -> float\n");
      else if (!strcmp(rdf, "lf"))
        printf("%%lf -> double\n");
      else if (!strcmp(rdf, "l"))
        printf("%%l = %%Lf -> long double\n");
      else if (!strcmp(rdf, "Lf"))
        printf("%%Lf -> long double\n");
      else
        printf("wrong format\n");
    }

    if (!strcmp(action, "chrdf"))
      printf("%s\n", rdf);
 
    //cf
    if (!strcmp(action, "cf"))
    {
      int fnn, fdn, fnd, fdd;
      int snn, sdn, snd, sdd;
      int tnn, tdn, tnd, tdd;
      int type;
      scanf("%d", &type);
      if (type != 2 || type != 3)
        printf("Wrong type\n");
      scanf("%d%d%d%d", &fnn, &fdn, &fnd, &fdd);
      if (type == 2)
      {
        scanf("%d%d", &snn, &sdn);
        //(snd/sdd) = (fnd/fdd)*(snn/sdn)/(fnn/fdn)
        fnd *= snn;
        fdd *= sdn;
        fnd *= fdn;
        fdd *= fnn;
        int gcdval = gcd(fnd, fdd);
        fnd /= gcdval;
        fdd /= gcdval;
        printf("%d/%d\n", fnd, fdd);
      }

      if (type == 3)
      {
        scanf("%d%d", &tnd, &tdd);
        fnn *= tnd;
        fdn *= tdd;
        fnn *= fdd;
        fdn *= fnd;
        int gcdval = gcd(fnn, fdn);
        fnn /= gcdval;
        fdn /= gcdval;
        printf("%d/%d\n", fnn, fdn);
      }
    }
    
    //add
    if (!strcmp(action, "add"))
    {
      if (!strcmp(rdf, "d"))
      {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
      }
      else if (!strcmp(rdf, "f"))
      {
        float a, b;
        scanf("%f%f", &a, &b);
        printf("%f\n", a+b);
      }
      else if (!strcmp(rdf, "lf"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", a+b);
      }
      else if (!strcmp(rdf, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", a+b);
      }
      else
        printf("check rdf\n");
    }

    //sub
    if (!strcmp(action, "sub"))
    {
      if (!strcmp(rdf, "d"))
        {
          int a, b;
          scanf("%d%d", &a, &b);
          printf("%d\n", a-b);
        }
      else if (!strcmp(rdf, "f"))
      {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a-b);
      }
      else if (!strcmp(rdf, "f"))
      {
        float a, b;
        scanf("%d%d", &a, &b);
        printf("%f\n", a-b);
      }
      else if (!strcmp(rdf, "lf"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", a-b);
      }
      else if (!strcmp(rdf, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", a-b);
      }
      else
        printf("check rdf\n");
    }

    //mul
    if (!strcmp(action, "mul"))
    {
      if (!strcmp(rdf, "d"))
      {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a*b);
      }
      else if (!strcmp(rdf, "f"))
      {
        float a, b;
        scanf("%f%f", &a, &b);
        printf("%f\n", a*b);
      }
      else if (!strcmp(rdf, "lf"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", a*b);
      }
      else if (!strcmp(rdf, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", a*b);
      }
    }
    
    //div
    if (!strcmp(action, "div"))
    {
      if (!strcmp(rdf, "d"))
      {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a/b);
      }
      if (!strcmp(rdf, "f"))
      {
        float a, b;
        scanf("%f%f", &a, &b);
        printf("%f\n", a/b);
      }
      if (!strcmp(rdf, "lf"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", a/b);
      }
      if (!strcmp(rdf, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", a/b);
      }
    }

    //pow
    if (!strcmp(action, "pow"))
    {
      if (!strcmp(rdf, "lf") || !strcmp(rdf, "d"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", pow(a, b));
      }
      if (!strcmp(rdf, "f"))
      {
        float a, b;
        scanf("%f%f", &a, &b);
        printf("%f\n", powf(a, b));
      }
      if (!strcmp(rdf, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", powl(a, b));

      }
    }

    //rod
    if (!strcmp(action, "rod"))
    {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", a%b);
    }

    //addfraction
    if (!strcmp(action, "af")) 
    {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      fn = addfracnum(fn, fd, sn, sd);
      fd = lcm(fd, sd);
      int gcdval = gcd(fn, fd);
      fn /= gcdval;
      fd /= gcdval;
      printf("%d/%d\n", fn, fd);
    }

    //subfraction
    if (!strcmp(action, "sf"))
    {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      fn = subfracnum(fn, fd, sn, sd);
      fd = lcm(fd, sd);
      int gcdval = gcd(fn, fd);
      fn /= gcdval;
      fd /= gcdval;
      printf("%d/%d\n", fn, fd);
    }

    //mulfraction
    if (!strcmp(action, "mf"))
    {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      fn *= sn;
      fd *= sd;
      int gcdval = gcd(fn, fd);
      fn /= gcdval;
      fd /= gcdval;
      printf("%d/%d\n", fn, fd);
    }

    //divfraction
    if (!strcmp(action, "df"))
    {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      fn *= sd;
      fd *= sn;
      int gcdval = gcd(fn, fd);
      fn /= gcdval;
      fd /= gcdval;
      printf("%d/%d\n", fn, fd);
    }
  
    //fd
    if (!strcmp(action, "fd"))
    {
      int number;
      scanf("%d", &number);
      for (int i = 1; i <= number; i++)
      {
        if (number % i == 0)
        {
          printf("%d ", i);
        }
      }
      printf("\n");
    }

    //tdap
    if (!strcmp(action, "tdap"))
    {
      int num, denom;
      scanf("%d%d", &num, &denom);
      printf("%lf\n", (double)num/(double)denom);
      printf("%lf%%\n", (double)num/((double)denom/100));
    }

    if (!strcmp(action, "tif"))
    {
      int num, denom, fp;
      scanf("%d%d%d", &fp, &num, &denom);
      num = denom * fp + num;
      printf("%d/%d", num, denom);
    }

    if (!strcmp(action, "itm"))
    {
      int num, denom, fp;
      scanf("%d%d", &num, &denom);
      fp = num/denom;
      num %= denom;
      printf("%d %d/%d\n", fp, num, denom);
    }

    if (!strcmp(action, "dtf"))
    {
      int num, denom;
      const int percision = 1000000;
      double decimal;
      scanf("%lf", &decimal);
      
      num = (int)(decimal * percision);
      denom = percision;
      int gcdval = gcd(num, denom);
      num /= gcdval;
      denom /= gcdval;
      printf("%d/%d\n", num, denom);
    }

    if (!strcmp(action, "reduce"))
    {
      int num, denom;
      scanf("%d%d", &num, &denom);
      int gcdval = gcd(num, denom);
      num /= gcdval;
      denom /= gcdval;
      printf("%d/%d\n", num, denom);
      
    }

    if (!strcmp(action, "rt"))
    {
      char type[2];
      scanf("%s", type);
      if (!strcmp(type, "lf"))
      {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%lf\n", pow(a, 1/b));
      }
      if (!strcmp(type, "f"))
      {
        float a, b;
        scanf("%f%f", &a, &b);
        printf("%f\n", pow(a, 1/b));
      }
      if (!strcmp(type, "l"))
      {
        long double a, b;
        scanf("%Lf%Lf", &a, &b);
        printf("%Lf\n", pow(a, 1/b));
      }
    }

    if (!strcmp(action, "lcm"))
    {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", lcm(a, b));
    }

    if (!strcmp(action, "gcd"))
    {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", gcd(a,b));
    }
  }
}
