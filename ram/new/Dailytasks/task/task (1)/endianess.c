//Write an API to determine the endianness of your system.
#include <stdio.h>
int main ()
{
  unsigned int x;
  printf("enter the X\n");
  scanf("%d",&x);
  unsigned int *c=&x; 
  //printf ("*c is: 0x%x\n", *c);
  if (*c==x)
  {
    printf ("little endian\n");
  }
  else
  {
    printf ("big endian\n");
  } 
  return 0;
}
