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
  while (1) {
    scanf("%s", action);
    if (!strcmp(action, "exit") || !strcmp(action, "ex"))
      return 0;
    if (!strcmp(action, "cl") || !strcmp(action, "clear"))
      system("clear");
    if (!strcmp(action, "add") || !strcmp(action, "sub") ||
        !strcmp(action, "mul") || !strcmp(action, "div") ||
        !strcmp(action, "pow") || !strcmp(action, "rt") ||
        !strcmp(action, "rod")) {
      long double a, b;
      scanf("%Lf%Lf", &a, &b);
      if (!strcmp(action, "add"))
        printf("%Lf\n", a + b);
      if (!strcmp(action, "sub"))
        printf("%Lf\n", a - b);
      if (!strcmp(action, "mul"))
        printf("%Lf\n", a * b);
      if (!strcmp(action, "div"))
        printf("%Lf\n", a / b);
      if (!strcmp(action, "pow"))
        printf("%Lf\n", powl(a, b));
      if (!strcmp(action, "rt"))
        printf("%Lf\n", powl(a, 1 / b));
      if (!strcmp(action, "rod"))
        printf("%d\n", (int)a % (int)b);
    }
    if (!strcmp(action, "gcd") || !strcmp(action, "lcm") ||
        !strcmp(action, "rd") || !strcmp(action, "itm")) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (!strcmp(action, "gcd"))
        printf("%d\n", gcd(a, b));
      if (!strcmp(action, "lcm"))
        printf("%d\n", lcm(a, b));
      if (!strcmp(action, "rd")) {
        int gcdval = gcd(a, b);
        printf("%d/%d %d\n", a / gcdval, b / gcdval, gcdval);
      }
      if (!strcmp(action, "itm")) {
        int fp = a / b;
        a %= b;
        printf("%d %d/%d\n", fp, a, b);
      }
    }
    if (!strcmp(action, "tif") || !strcmp(action, "tbd")) {
      if (!strcmp(action, "tif")) {
        int fp, num, denom;
        scanf("%d%d%d", &fp, &num, &denom);
        num = denom * fp + num;
        printf("%d/%d\n", num, denom);
      }
      if (!strcmp(action, "tbd")) {
        long double num, denom, decimal;
        scanf("%Lf%Lf%Lf", &num, &denom, &decimal);
        printf("%Lf\n", num / (denom / decimal));
      }
    }
    if (!strcmp(action, "af") || !strcmp(action, "sf") ||
        !strcmp(action, "mf") || !strcmp(action, "df")) {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      if (!strcmp(action, "af") || !strcmp(action, "sf")) {
        int cd = lcm(fd, sd), gcdval;
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
        if (!strcmp(action, "mf")) {
          fn *= sn;
          fd *= sd;
        } else {
          fn *= sd;
          fd *= sn;
        }
        int gcdval = gcd(fn, fd);
        printf("%d/%d %d\n", fn, fd, gcdval);
      }
    }
    if (!strcmp(action, "dtf")) {
      int num, denom = 1000000, gcdval;
      double decimal;
      scanf("%lf", &decimal);
      num = (int)(decimal * denom);
      gcdval = gcd(num, denom);
      num /= gcdval;
      denom /= gcdval;
      printf("%d/%d\n", num, denom);
    }
    if (!strcmp(action, "cmpf")) {
      int fn, fd, sn, sd;
      scanf("%d%d%d%d", &fn, &fd, &sn, &sd);
      double ff = (double)fn / (double)fd, sf = (double)sn / (double)sd;
      if (ff > sf)
        printf("%d/%d > %d/%d\n", fn, fd, sn, sd);
      if (ff < sf)
        printf("%d/%d < %d/%d\n", fn, fd, sn, sd);
      if (ff == sf)
        printf("%d/%d = %d/%d\n", fn, fd, sn, sd);
    }
  }
}
