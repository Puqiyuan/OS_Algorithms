/*
  The intend of this programs is to show how the banker algorithms working. The function
  start with t and it's name t_function_xx is test function for function_xx. All input should
  be integer, otherwise the result of the program is undefined.
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;// This variable use a locate for a process to running.

int compare(int **Need, int *Work, int p, int m);


int init_avai(int *Avai, int m)//Set your system how many sources can be used for each kind
//source when it power on. m is the number of source kind.
{
  int i;

  for (i = 0; i <= m - 1; i++)
    scanf("%d", &Avai[i]);

  return 1;
}


int alter_avai(int **Allo, int n, int m, int *Avai)
{
  int i, j, sum;

  i = 0;
  while (i <= m - 1)
    {
      sum = 0;
      for (j = 0;  j <= n - 1; j++)
	{
	  sum += Allo[j][i];
	}
      Avai[i] -= sum;
      i++;
    }

  return 1;
}


int t_init_avai(int *Avai, int m)
{
  int i;

  printf("All available sources: \n");

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


int judge_max(int **Max, int n, int m, int *Avai)// This function used for test maximum source
//for each process, if one kind source of amount of a process is larger than available by
//system return 0.
{
  int i = 0, j;

  while (i <= n - 1)
    {
      for (j = 0; j <= m - 1; j++)
	{
	  if (Avai[j] < Max[i][j])
	    return 0;
	}

      i++;
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


int zero_allo(int **Allo, int n, int m)
{
  int i, j;

  for (i = 0; i <= n - 1; i++)
    {
      for (j = 0; j <= m - 1; j++)
	Allo[i][j] = 0;
    }

  return 1;
}


int judge_init_allo(int **Allo, int **Max, int *Avai, int n, int m)//judge the initialized
//allocation is valid.
{
  int i, j, sum;

  for (i = 0; i <= n - 1; i++)
    {
      for (j = 0; j <= m - 1; j++)
	{
	  if (Max[i][j] < Allo[i][j])//For each process, it request amount should less than
	    //max amount that it claimed, otherwise invalid.
	    return 0; // return 0 if invalid.
	}
    }

  j = 0;
  while (j <= m - 1)// For each kind source, the sum of all processes request should less than
    //available that system supported, otherwise invalid.
    {
      sum = 0;
      
      for (i = 0; i <= n - 1; i++)
	{
	  sum += Allo[i][j];
	}
      
      if (sum > Avai[j])
	return 0;// return 0 if invalid.

      j++;
    }

  return 1;// return 1 if valid.
}


int t_init_allo(int **Allo, int n, int m)
{
  int i, j;

  printf("The sources allocated:\n");

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


int request(int *Requ, int m)
{
  int i;

  for (i = 0; i <= m - 1; i++)
    scanf("%d", &Requ[i]);

  return 1;
}


int t_request(int *Requ, int m, int req)
{
  int i;

  printf("The amount of source that you want to assign to process %d: \n", req);

  printf("Kind \t Request Amount\n");
  for (i = 0; i <= m - 1; i++)
    printf("%d \t %d\n", i + 1, Requ[i]);

  return 1;
}


int judge_requ(int *Requ, int **Need, int req, int m, int *Avai)
// This function test for request, if request
//source is larger than need, don't assign. The third argument is the requesting process.
{
  int j;

  for (j = 0; j <= m - 1; j++)
    {
      if (Requ[j] > Need[req - 1][j] || Requ[j] > Avai[j])
	return 0;// return 0 if invalid.
    }

  return 1;// return 1 if valid.
}


int try_allo(int req, int *Avai, int ** Allo, int **Need, int *Requ, int m)
// This function try assign sources to process. The first argument is the
// process that request source. Other arguments explained in main function already.
{
  int j;

  for (j = 0; j <= m - 1; j++)
    {
      Avai[j] -= Requ[j];
      Allo[req - 1][j] += Requ[j];
      Need[req - 1][j] -= Requ[j];
    }

  return 1;
}


int cand(int *Fin, int n, int **Need, int *Work, int m)
// This function used for a process, if test successfully, it will get sources and being to
//execute.
{
  int i;

  for (i = 0; i <= n - 1; i++)
    {
      if (Fin[i] == 0 && compare(Need, Work, i, m))//Test the i process if it is not finished and
	//it need sources are less than the system can be supported.
	return i;// Return the index of process.
    }

  return -1;
}


int compare(int **Need, int *Work, int p, int m)//This function is used for the the process
// that the last process index, compare it need sources between available sources.
{
  int i;

  for (i = 0; i <= m - 1; i++)
    {
      if (Need[p][i] <= Work[i])
	continue;

      else
	break;
    }

  if (i == m)
    return 1;// Return 1 if all need sources less than available.

  return 0;// otherwise return 0.
}


int check(int *Fin, int n)//This function used for test for all process in the system the
//safety of the system after someone process request source.
{
  int i;

  for (i = 0; i <= n - 1; i++)
    {
      if (Fin[i] == 0)
	return 0;// As long as find a process can not complete it's work, return 0 represent the
      //system is not safe.
    }

  return 1;// All process can finished it's work, return 1 represent the system is safe.
  
}


int print(int **Max, int **Need, int **Allo, int *Work, int *Fin, int n, int m, int c, int p)
// This function used for print the system status.
{
  int i, j;
  printf("\n\n");
  printf("---------------------------------------------\n");

  if (p != -2)
    printf("System status %d, after finished process %d:\n", c, p + 1);
  else
    printf("System status %d:\n", 0);
    
  printf("                  Max    Need  Allocation   Finished\n");
  printf("Kind: \t\t ");

  for(j = 1; j <= m; j++)
    printf("%d ", j);

  printf(" ");

  for(j = 1; j <= m; j++)
    printf("%d ", j);

  printf("  ");

  for(j = 1; j <= m; j++)
    printf("%d ", j);

  printf(" ");

  printf("\n");

  for (i = 0; i <= n - 1; i++)
    {
      printf("Process %d:\t ", i + 1);
      {
	for (j = 0; j <= m - 1; j++)
	  printf("%d ", Max[i][j]);

	printf("\t");
	
	for (j = 0; j <= m - 1; j++)
	  printf("%d ", Need[i][j]);

	printf("\t");

	for (j = 0; j <= m - 1; j++)
	  printf("%d ", Allo[i][j]);
      }

      printf("         %d", Fin[i]);

      printf("\n");
            
    }

  printf("Kind \t Available Number\n");
  for (j = 0; j <= m - 1; j++)
    printf("%d \t %d\n", j + 1, Work[j]);

  printf("---------------------------------------------\n");

  return 1;
}


int init_store_seq(int *resul, int n)
{
  int i;

  for (i = 0; i <= n - 1; i++)
    resul[i] = -1;

  return 1;
}


int store_seq(int *resul, int p, int count)
{
  resul[count] = p;

  return 1;
}


int safe_guard(int *Fin, int **Need, int *Work, int ** Allo, int n, int m, int **Max, int *resul)
// This function used for complete safe computing of the first argument
//of the system, the meaning of "unsafe" is that if after an process request source, the system
//can't find a work sequences that all process can finish their works. These arguments
//explained in main function already.
{
  int p = cand(Fin, n, Need, Work, m), j, c = 1;

  print(Max, Need, Allo, Work, Fin, n, m, c, -2);
  
  while (p != -1)// If the process that index by p is not finish, and
    //all sources it needed is less than the system can supported, so execute it and give up all
    //it's source after it finished.
    {
      /*
	Here are the codes that process to execute......
      */
      //Now the process finish it's execute, so give up it's sources.
      
      for (j = 0; j <= m - 1; j++)
	{
	  Work[j] += Allo[p][j];//Call back sources of process p.
	  Need[p][j] = 0;
	  Allo[p][j] = 0;
	  Fin[p] = 1;// Alter sign bit so that say the process p is finished.
	}

      store_seq(resul, p, count);
      count++;

      print(Max, Need, Allo, Work, Fin, n, m, c, p);
      c++;

      p = cand(Fin, n, Need, Work, m);
    }

  int flag = check(Fin, n);

  if (flag)
    return 1;

  return 0;
}


int init_work(int *Work, int *Avai, int m)//This function is used for initialize work array.
{
  int i;

  for (i = 0; i <= m - 1; i++)
    Work[i] = Avai[i];

  return 1;
}


int init_fin(int *Fin, int n)
{
  int i;

  for (i = 0; i <= n - 1; i++)
    Fin[i] = 0;

  return 1;
}


int cancel(int req, int *Avai, int **Allo, int **Need, int *Requ, int m)//If the process that
//request sources maybe lead the system to unsafe, the system will cancel assign.
{
  int j;

  for (j = 0; j <= m - 1; j++)
    {
      Avai[j] += Requ[j];
      Allo[req - 1][j] -= Requ[j];
      Need[req - 1][j] += Requ[j];
    }

  return 1;
}


int show_resul(int *resul, int n)
{
  int i;

  for (i = 0; i <= n - 1; i++)
    {
      if (resul[i] != -1)
	printf("p%d, ", resul[i] + 1);
    }

  printf("\n");

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

  while (!judge_max(Max, n, m, Avai))
    {
      printf("Sorry your maximum value is wrong, please check your data and re-enter:\n");
      init_max(Max, n, m);
    }

  


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

      if (!judge_init_allo(Allo, Max, Avai, n, m))
	{
	  printf("Sorry your initialize source allocation is wrong, please check your data\n");
	  printf("and your initialization will be zero.\n");

	  zero_allo(Allo, n, m);
	}
    }




  int **Need = (int**)malloc(n * sizeof(int*));// The Need array store how many sources
  //for each kind source needed by one process to finish task.
  for (i = 0; i <= n - 1; i++)
    Need[i] = (int*)malloc(m * sizeof(int));

  if (judge_init_allo(Allo, Max, Avai, n, m))//If initialize successfully for the first argument
    //then we need to alter the values of Need array and the third argument.
    {
      init_need(Need, Max, Allo, n, m);
      alter_avai(Allo, n, m, Avai);
    }




  printf("After initialized of allocation:\n");
  t_init_need(Need, n, m);
  t_init_avai(Avai, m);
  t_init_allo(Allo, n, m);


  

  int req; // This variable record which process that you want to assign source.
  printf("Please select which process you want to assign source(process counting from 1): ");
  scanf("%d", &req);
  
  int *Requ = (int*)malloc(m * sizeof(int));// This array used for store requested amount of
  //source of process that you want.
  printf("Please input the amount of source that you request for process %d\n", req);
  printf("from left to right is kind 1 source, kind 2 source, kind 3 ...\n");
  
  request(Requ, m);

  t_request(Requ, m, req);

  if (!judge_requ(Requ, Need, req, m, Avai))
    {
      printf("Sorry your request is invalided.\n");
      return 0;
    }
  else
    try_allo(req, Avai, Allo, Need, Requ, m);

  printf("After try assigned: \n");

  t_init_avai(Avai, m);

  t_init_allo(Allo, n, m);

  t_init_need(Need, n, m);



  int *resul = (int*)malloc(n * sizeof(int));// This variable is used for store process running
  //sequence.

  init_store_seq(resul, n);

  int *Fin = (int*)malloc(n * sizeof(int));// This function used for representing the status
  //of a process if Fin[i] = 0, it's say the process i is not complete, if Fin[i] = 1, it's say
  //the process i is finished.

  init_fin(Fin, n);
  
  int *Work = (int*)malloc(m * sizeof(int));// This array used for store current how many sources
  //can be supported by the system.

  init_work(Work, Avai, m);

  int flag = safe_guard(Fin, Need, Work, Allo, n, m, Max, resul);

  if (flag)
    {
      printf("The requested for sources of %d process is valid.\n", req);
      printf("There is a sequence that used by the system can finish all process:\n");
      show_resul(resul, n);
    }

  else if (!flag)
    {
      printf("\n\n");
      printf("Sorry the requested for sources of %d process maybe lead ", req);
      printf("the system to unsafe\n");
      printf("So the system denied to assign sources to %d process.\n", req);
      printf("As you can see until now the available sources can not meet any need of process.\n");

      printf("The system may execute only these processes:\n");
      show_resul(resul, n);
      printf("after that the system involve in\n");
      printf("unsafe status. If the sequence is null, meaning that no anyone process can be\n");
      printf("execute if that request is successfully.\n");

      cancel(req, Avai, Allo, Need, Requ, m);
      printf("Back to before allocation:\n");
      t_init_allo(Allo, n, m);
      t_init_avai(Avai, m);
    }

  
  return 1;
}
