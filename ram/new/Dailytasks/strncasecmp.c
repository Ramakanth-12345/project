#include <stdio.h>
#include <strings.h>

int main()
{
  char *str1 = "STRING ONE";
  char *str2 = "string one";
  int result;

  result = strncasecmp(str1, str2,10);

  if (result == 0)
    printf("Strings compared equal.\n");
  else if (result < 0)
    printf("\"%s\" is less than \"%s\".\n", str1, str2);
  else
    printf("\"%s\" is greater than \"%s\".\n", str1, str2);

  return 0;
}

