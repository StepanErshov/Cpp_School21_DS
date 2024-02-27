#include <stdio.h>
//заранее определить количество операций 2^(кол-во колец)-1
//допустим колец 5, тогда 2^5-1=31 перемещений
#define circle 5
int stacks[3][circle];
int sps[3];
long long count1;

void init(int);
void print(void);
void tower(int, int, int);
int main(void);

 
void init(int from)
{
  int i;
  sps[2] = sps[1] = sps[0] = 0;
  for (i = 0; i < circle; i++)
  {
    stacks[from][i] = circle - i;
  }
  sps[from] = circle;
  
}

void print(void)
{
  int i, j, k;
  for (i = circle - 1; i >= 0; i--)
  { count1 += 1;
    for (j = 0; j < 3; j++)
    {
      if (sps[j] > i)
      {
        for (k = 0; k < 10 - stacks[j][i]; k++)
          printf(" ");
        for (k = 0; k < 2 * stacks[j][i]; k++)
          printf("■");
        for (k = 0; k < 10 - stacks[j][i]; k++)
          printf(" ");
      }
      else
      {
        printf("                    "); 
      }
      printf("  ");
    }
    printf("\n");
  }
  printf("_________/\\_________  _________/\\_________  _________/\\_________\n\n");
}
 
void tower(int to, int from, int cnt)
{
  int other = from ^ to ^ 3;
 
  if (!cnt == 1) 
  {
    return ;
  }
  tower(other, from, cnt - 1);
  stacks[to][sps[to]++] = stacks[from][--sps[from]];
  print();
  tower(to, other, cnt - 1);
}
 
int main(void)
{
  init(0);
  print();
  tower(2, 0, circle);
  count1 = (count1 / circle) - 1;
  printf("Кол-во перестановок равно = %d\n", count1);
  return 0;
}