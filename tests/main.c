#include <stdio.h>

void change_var(int  *var1, int  *var2)
{
  *var1 = *var2;
}

int main(void)
{
  int i = 5;
  int b = 6;
  change_var(&i, &b);
  printf("hello everyone %d\n", i);
  return (0);
}
