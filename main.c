#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  char action[256];
  int fn, fd, sn, sd, gcdval, cd;
  long double a, b, size;
  while (1) {
    scanf("%s", action);

    // Program part
    if (!strcmp(action, "exit") || !strcmp(action, "ex"))
      return 0;

    if (!strcmp(action, "clear") || !strcmp(action, "cl"))
      system("clear");

    // Base actions
    if (!strcmp(action, "add")) {
      scanf("%Lf%Lf", &a, &b);
      printf("%Lf\n", a + b);
    }

    if (!strcmp(action, "sub")) {
      scanf("%Lf%Lf", &a, &b);
      printf("%Lf\n", a - b);
    }

    if (!strcmp(action, "mul")) {
      scanf("%Lf%Lf", &a, &b);
      printf("%Lf\n", a * b);
    }

    if (!strcmp(action, "div")) {
      scanf("%Lf%Lf", &a, &b);
      printf("%Lf\n", a / b);
    }

    if (!strcmp(action, "rod")) {
      scanf("%d%d", &fn, &sn);
      printf("%d\n", fn % sn);
    }

    if (!strcmp(action, "gcd")) {
      scanf("%d%d", &fn, &sn);
      printf("%d\n", gcd(fn, sn));
    }

    if (!strcmp(action, "lcm")) {
      scanf("%d%d", &fn, &sn);
      printf("%d\n", lcm(fn, sn));
    }

    if (!strcmp(action, "pow")) {
      scanf("%Lf%Lf", &a, &b);
      printf("%Lf\n", powl(a, b));
    }

    if (!strcmp(action, "cos")) {
      scanf("%Lf", &a);
      printf("%Lf\n", cosl(a));
    }

    if (!strcmp(action, "sin")) {
      scanf("%Lf", &a);
      printf("%Lf\n", sinl(a));
    }

    if (!strcmp(action, "tan")) {
      scanf("%Lf", &a);
      printf("%Lf\n", tanl(a));
    }

    // Fraction part
    if (!strcmp(action, "rd")) {
      scanf("%d%d", &fn, &sn);
      gcdval = gcd(fn, sn);
      printf("%d/%d %d\n", fn / gcdval, sn / gcdval, gcdval);
    }

    if (!strcmp(action, "itm")) {
      scanf("%d%d", &fn, &fd);
      sn = fn / fd;
      fn %= fd;
      printf("%d %d/%d\n", sn, fn, fd);
    }

    if (!strcmp(action, "tif")) {
      scanf("%d%d%d", &sn, &fn, &fd);
      fn = fd * sn + fn;
      printf("%d/%d\n", fn, fd);
    }

    if (!strcmp(action, "af") || !strcmp(action, "sf")) {
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      cd = lcm(fd, sd);
      fn *= cd / fd;
      sn *= cd / sd;
      if (!strcmp(action, "af"))
        fn += sn;
      else
        fn -= sn;
      gcdval = gcd(fn, cd);
      printf("%d/%d %d\n", fn, cd, gcdval);
    }

    if (!strcmp(action, "mf") || !strcmp(action, "df")) {
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      if (!strcmp(action, "mf")) {
        fn *= sn;
        fd *= sd;
      } else {
        fn *= sd;
        fd *= sn;
      }
      gcdval = gcd(fn, fd);
      printf("%d/%d %d\n", fn, fd, gcdval);
    }

    if (!strcmp(action, "dtf")) {
      fd = 1e6;
      scanf("%Lf", &a);
      fn = (int)(a * fd);
      gcdval = gcd(fn, fd);
      fn /= gcdval;
      fd /= gcdval;
      printf("%d/%d\n", fn, fd);
    }

    if (!strcmp(action, "tad")) {
      scanf("%Lf%Lf%Lf", &a, &b, &size);
      a = a / (b / size);
      printf("%Lf\n", a);
    }
  }
  return 0;
}
