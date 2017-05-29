/*
  Test result:
  pqy@sda1:~/.../FCFS$ ./a.out 
  Using integer representing process, say your sequence is 2, 4, 1
  It's meaning that process 2 is the first arrived, process 4 is the
  second arrived, process 1 is the third...
  Input the number of processes: 4
  Now please input the order your process arrived(POSITIVE integer):
  4 7 1 3
  These processes will be execute as this sequence:
  p4, p7, p1, p3, 
  pqy@sda1:~/.../FCFS$ 
  [pqy@sda1:0]  0:ss-local 1:bash                                           1.43 100% Mon 2017-05-29 22:15
 */

#include <stdio.h>
#include <stdlib.h>


int print(int *in, int len)
{
  int i = 0;
  printf("These processes will be execute as this sequence:\n");

  for (i = 0; i <= len - 1; i++)
    printf("p%d, ", in[i]);

  printf("\n");
  
  return 1;
}


int main(int argc, char *argv[])
{
  int *in, i = 0, n;

  
  printf("Using integer representing process, say your sequence is 2, 4, 1\n");
  printf("It's meaning that process 2 is the first arrived, process 4 is the\n");
  printf("second arrived, process 1 is the third...\n");
  printf("Input the number of processes: ");
  scanf("%d", &n);
  in = (int*)malloc(n * sizeof(int));
  
  printf("Now please input the order your process arrived(POSITIVE integer):\n");
  for (i = 0; i <= n - 1; i++)
    scanf("%d", &in[i]);

  print(in, n);
  
  return 1;
}

