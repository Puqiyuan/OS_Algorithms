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

  return 0;
}


int main(int argc, char *argv[])
{
  int m;//The m variable represent how many kind of resources in your system.
  printf("Please input the number of kind of source:\n");
  scanf("%d", &m);

  int *Avai= (int*)malloc(m * sizeof(int));//The Available array contains m elements,
  //the meaning of value of each each element is that how many sources can be use at system.
  //For example, if Available[i] = K, it's say there are K sources for kind i source
  //is available. And the value will be changed when system running. 

  printf("Please input the number of source for each kind when system power on ");
  printf("parting by enter or space:\n");
  
  init_avai(Avai, m);
  
  t_init_avai(Avai, m);


  int n, i; //The n variable represent how many process you want.
  printf("Please input the number of processes:\n");
  scanf("%d", &n);

  int **Max = (int**)malloc(n * sizeof(int*)); // The Max array record for each process i,
  //it will request the maximum sources of kind j. For example, Max[i][j] = K, it's say process
  //i will request source j by maximum K.
  for (i = 0; i <= n - 1; i++)
    Max[i] = (int*)malloc(m * sizeof(int));

  printf("Please input the maximum sources for each process each source, one row one process,\n");
  printf("and from left to right is kind 1 source, 2 source, 3 source...\n");
  
  init_max(Max, n, m);

  t_init_max(Max, n, m);
  
  return 0;
}
