#include <stdio.h>
#include <string.h>

int
main ()
{
  char *q0 = "q0";
  char *q1 = "q1";
  char *q2 = "q2";
  char *q3 = "q3";


    char *atual = q0;
    char *final = q2;
    char cod[] = "01100000";


  int i;
  for (i = 0; i < strlen (cod); i++)
    {
      if (atual == q0)
    {
      if (cod[i] == '0')
        {
          atual = q0;
        }
      else if (cod[i] == '1')
        {
          atual = q1;
        }
    }
      else if (atual == q1)
    {
      if (cod[i] == '0')
        {
          atual = q3;
        }
      else if (cod[i] == '1')
        {
          atual = q2;
        }
    }
      else if (atual == q2)
    {
      if (cod[i] == '0')
        {
          atual = q2;
        }
      else if (cod[i] == '1')
        {
          atual = q3;
        }
    }
    }

  if (atual != final)
    {
      printf ("Str nao aceita\n");
    }
  else
    {
      printf ("Str aceita\n");
    }

  return 0;
}