/*
  The intend of this programs is to show how the banker algorithms working. The function
  start with t and it's name t_function_xx is test function for function_xx.
*/

#include <stdio.h>
#include <stdlib.h>


int init_avai(int *Avai, int m)//Set your system how many sources can be used for each kind
//source when it power on. m is the number of source kind.
{
  int i;

  for (i = 0; i <= m - 1; i++)
    scanf("%d", &Avai[i]);

  return 1;
}


int t_init_avai(int *Avai, int m)
{
  int i;

  printf("All available sources for each kind when system power on: \n");

  printf("Kind \t Available Number\n");
  for (i = 0; i <= m - 1; i++)
    printf("%d \t %d\n", i + 1, Avai[i]);

  return 1;
}


int init_max(int **Max, int n, int m)// Set maximum value for each kind source that each process
//will need.
{
  int i, j;

  for (i = 0; i <= n - 1; i++)
    {
      for (j = 0; j <= m - 1; j++)
	scanf("%d", &Max[i][j]);// The maximum that process i will need source j.
    }

  return 1;
}


int t_init_max(int **Max, int n, int m)
{
  int i, j;

  printf("The maximum of sources requested for each process:\n");

  printf("Kind:  \t\t ");
  for(j = 1; j <= m; j++)
    printf("%d ", j);

  printf("\n");

  for (i = 0; i <= n - 1; i++)
    {
      printf("Process %d:\t ", i + 1);
      for (j = 0;j <= m - 1; j++)
	printf("%d ", Max[i][j]);

      printf("\n");
    }

  return 1;
}


int init_allo(int **Allo, int n, int m)// Initialize source allocation for each process.
{
  int i, j;

  for (i = 0; i <= n - 1; i++)
    {
      for (j = 0; j <= m - 1; j++)
	scanf("%d", &Allo[i][j]);// Initialize how many sources of kind j for process i;
    }

  return 1;
}


int t_init_allo(int **Allo, int n, int m)
{
  int i, j;

  printf("The sources allocation that you initialized for each process:\n");

  printf("Kind: \t\t ");
  for (j = 1; j <= m; j++)
    printf("%d ", j);

  printf("\n");

  for (i = 0; i <= n - 1; i++)
    {
      printf("Process %d:\t ", i + 1);
      for (j = 0; j <= m - 1; j++)
	printf("%d ", Allo[i][j]);

      printf("\n");
    }

  return 0;
}


int init_need(int **Need, int **Max, int **Allo, int n, int m)
{
  int i, j;

  for (i = 0; i <= n - 1; i++)
    {
      for (j = 0; j <= m - 1; j++)
	Need[i][j] = Max[i][j] - Allo[i][j];
    }

  return 1;
}


int t_init_need(int **Need, int n, int m)
{
   int i, j;

  printf("For each process how many source it need for each kind:\n");

  printf("Kind:  \t\t ");
  for(j = 1; j <= m; j++)
    printf("%d ", j);

  printf("\n");

  for (i = 0; i <= n - 1; i++)
    {
      printf("Process %d:\t ", i + 1);
      for (j = 0;j <= m - 1; j++)
        printf("%d ", Need[i][j]);

      printf("\n");
    }

  return 1;
}


int main(int argc, char *argv[])
{
  int m;//The m variable represent how many kind of resources in your system.
  printf("Please input the number of kind of source: ");
  scanf("%d", &m);

  int *Avai= (int*)malloc(m * sizeof(int));//The Available array contains m elements,
  //the meaning of value of each each element is that how many sources can be use at system.
  //For example, if Available[i] = K, it's say there are K sources for kind i source
  //is available. And the value will be changed when system running. 

  printf("Please input the number of source for each kind when system power on\n");
  printf("parting by enter or space, from kind 1 to last kind:\n");
  
  init_avai(Avai, m);

  
  int n, i; //The n variable represent how many process you want.
  printf("Please input the number of processes: ");
  scanf("%d", &n);
  
  int **Max = (int**)malloc(n * sizeof(int*)); // The Max array record for each process i,
  //it will request the maximum sources of kind j. For example, Max[i][j] = K, it's say process
  //i will request source j by maximum K.
  for (i = 0; i <= n - 1; i++)
    Max[i] = (int*)malloc(m * sizeof(int));

  printf("Please input the maximum sources requested for each process each source, one row\n");
  printf("one process, and from left to right is kind 1 source, 2 source, 3 source...\n");
  
  init_max(Max, n, m);

  
  int **Allo = (int**)malloc(n * sizeof(int*));// This array is used for store allocation
  //resource, for example, if [i, j] = K, it's say for process i, now it have K sources of kind j.
  for (i = 0; i <= n - 1; i++)
    Allo[i] = (int*)malloc(m * sizeof(int));

  char op, eat;
  printf("Do you need to initialize sources allocation(y/n)? ");
  scanf("%c", &eat);
  
  scanf("%c", &op);

  if (op == 'y')
    {
      printf("Please initialize sources amount for each kind source of each process,\n");
      printf("one row one process, and from left to right is kind 1 source, 2 source, ");
      printf("3 source...\n");
      
      init_allo(Allo, n, m);
    }


  int **Need = (int**)malloc(n * sizeof(int*));// The Need array store how many sources
  //for each kind source needed by one process to finish task.
  for (i = 0; i <= n - 1; i++)
    Need[i] = (int*)malloc(m * sizeof(int));

  init_need(Need, Max, Allo, n, m);
  
  t_init_need(Need, n, m);
  
  return 1;
}
