#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000
void numChar(char* a,char* b,char* sum)
{
  int carry=0;
  for(int i=SIZE-1;i>=0;i--)
  {
    int result=(a[i] - '0') + (b[i] - '0') + carry;
    sum[i]=result%10 + '0';
    carry=result/10;
  }
}
int main()
{
  char prevFiboNum[SIZE],curFiboNum[SIZE],finalFiboNum[SIZE];
  for(int i=0;i<SIZE;i++)
  {
    prevFiboNum[i]=curFiboNum[i]=finalFiboNum[i]='0';
  }
  curFiboNum[SIZE-1]='1';
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  if(n==0 || n==1)
  {
    printf("%c",n+'0');
    return 0;
  }
  for(int i=2;i<n;i++)
  {
    numChar(prevFiboNum, curFiboNum, finalFiboNum);
    for(int i=SIZE-1;i>=0;i--)
    {
      prevFiboNum[i]=curFiboNum[i];
      curFiboNum[i]=finalFiboNum[i];
    }
  }
  printf("%dth fibonacci number is: ");
  int flag=0;
  for (int i=0;i<SIZE;i++)
  {
    if (finalFiboNum[i]!='0')
    { 
        flag=1;
    }
    if(flag)
    {
      printf("%c", finalFiboNum[i]);
    }
  }
  printf("\n");
  return 0;
} 