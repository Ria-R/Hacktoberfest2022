#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//for ria: functions needed are checker, up, down, left, right, fill up zeroes, main, win (when 2048), display
int checker(int arr[][5]);
void right(int a[5][5]);
int i = 0;
int j = 0;

int checker(int arr[][5]) //function to check if further computations are possible; returns true if there are
{
    int flag = 0;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
       {
            if (arr[i][j+1] == arr[i][j] || arr [i][j-1] == arr[i][j]  || arr[i-1][j] == arr[i][j]||  arr[i+1][j]  == arr[i][j])
            {
                flag =  1; 
                
            }
                   
            }
        }
        if(arr[0][0] == arr[0][1] || arr[0][0] == arr[1][0])
        { 
            flag = 1;
        }
        else if(arr[0][5] == arr[0][4] || arr[0][5] == arr[4][5])
        {
            flag = 1;
        }
        else if(arr[5][0] == arr[5][4] ||arr[5][0] ==  arr[4][0])
        {
            flag = 1;
        }
        else if(arr[5][5] == arr[5][4] ||arr[5][5] == arr[4][5])
        {
            flag = 1;
        }

        return flag;
        
    }

int check_zero(int a[][5])// 0 for presence of 0
{

  int flag = 1;
  for (i = 0; i < 5; i++)
  {
    for(j = 0; j < 5; j++)
    {
      if(a[i][j]== 0)
      {
        flag = 0;
        break;
      }
    }

  }
  return flag;
}

void check_win(int a[][5]) //0 for presence of 2048
{
  int flag = 1;
  for (i = 0; i < 5; i++)
  {
    for(j = 0; j < 5; j++)
    {
      if(a[i][j]== 2048)
      {
        flag = 0;
        break;
      }
    }

  }
  if(flag == 0)
  {
    printf("\n You reached 2048! \n");
  }
}


void left(int a[][5]) //shifts left and merges
{
  int n = 0;
  while(n < 5)
  {
    for(i = 0; i < 5; i++)
    {
      for(j = 4; j > 0; j--)
      {
        if(a[i][j] == a[i][j-1])
        {
          a[i][j] = a[i][j] + a[i][j-1];
          a[i][j-1] = 0;
        }
        if(a[i][j] == 0)
        {
          a[i][j] = a[i][j-1];
          a[i][j-1] = 0;
        }
      }
    }
    n = n + 1;
  }
}

void up(int a[][5])// shifts up and merges
{
  int n = 0;
  while(n < 5)
  {
    for(j = 0; j < 5; j++)
    {
      for(i = 0; i < 4; i++)
      {
        if(a[i][j] == a[i+1][j])
        {
          a[i][j] = a[i][j] + a[i+1][j];
          a[i+1][j] = 0;
        }
        if(a[i][j] == 0)
        {
          a[i][j] = a[i+1][j];
          a[i+1][j] = 0;
        }
      }
    }
    n = n + 1;
  }
}

void down(int a[][5])// shifts down and merges
{
  int n = 0;
  while(n < 5)
  {
  for(j = 0; j < 5; j++)
    {
      for(i = 4; i > 0; i--)
      {
        
        if(a[i][j] == 0)
        {
          a[i][j] = a[i-1][j];
          a[i-1][j] = 0;
        }

        if(a[i][j] == a[i-1][j])
        {
          a[i][j] = a[i][j] + a[i-1][j];
          a[i-1][j] = 0;
        }  
      }
    }   
    n = n +1;
  }
    
}

void right(int a[][5])// shifts right and merges
{
  int n = 0;
  while(n < 5)
  {
    for(i = 0; i < 5; i++)
    {
      for(j = 0; j < 4; j++)
      {
        if(a[i][j] == a[i][j+1])
        {
          a[i][j] = a[i][j] + a[i][j+1];
          a[i][j+1] = 0;
        }
        if(a[i][j] == 0)
        {
          a[i][j] = a[i][j+1];
          a[i][j+1] = 0;
        }
      }
    }
    n = n + 1;
  }
}
void display(int a[][5])// displays matrix
{
  for(i = 0; i < 5; i++)
  {
    for(j = 0;j < 5; j++)
    {
      printf("%d \t", a[i][j]);
    }
    printf("\n");
  }
}
void rand_num(int a[][5])// random number generator
{
  int flag = 1;
  while (flag == 1){
  srand((int)time(NULL));
  int b[] = {2,4};
    int m = rand()%5;
    int n = rand()%5;
    if(a[m][n] == 0)
    {
      a[m][n] = b[rand()%2];
      flag = 0;
    }
  }
}
int main()
 {
  int move = 0;

  printf("Hello! Tis' a game of 2048 \n");
  int arr[5][5] = {0};
  rand_num(arr);
  display(arr);
  int result_z = 0;
  int result_ch = 1;

  while((result_z == 0) || (result_ch == 1))
  {
    rand_num(arr);
    printf("\nPick a way to move up(1), down(2), left(3), right(4) \n");
    scanf(("%d"), &move);
    switch(move)
    {
    case 1:
    up(arr);
    printf("\n");
    display(arr);
    break;
    
    

   case 2:
    down(arr);
    printf("\n");
    display(arr);
    break;
    
    

   case 3: 
    right(arr);
    printf("\n");
    display(arr);
    break;
    
    
   case 4:
    left(arr);
    printf("\n");
    display(arr);
    break;
  

  default:
   printf("\nPick a valid character \n");
   printf("\nPick a way to move up(u), down(d), left(l), right(r) \n");
   scanf(("%c"), &move);
   break;
  

    }
  check_win(arr);
  result_z = check_zero(arr);
  result_ch = checker(arr);
    }


  }

 

 
