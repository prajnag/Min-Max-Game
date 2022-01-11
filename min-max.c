#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
void minmax(char *s)
{
    int n=strlen(s);
    char op[n/2];
    int m=0; int p=0;
    int num[n-n/2];
    int len_num=n-n/2;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            num[m]=s[i]-'0';
            m++;
        }
        else
        {
            op[p]=s[i];
            p++;
        }
    }
   int minval[len_num][len_num];
   int maxval[len_num][len_num];
   for(int i=0; i<len_num; i++)
   {
       for(int j=0; j<len_num; j++)
       {
           minval[i][j]=100000000;
           maxval[i][j]=0;
           if(i==j)
           {
               minval[i][j]=num[i];
               maxval[i][j]=num[i];
           }
       }
   }
  for(int l=2; l<=len_num; l++)
  {
      for(int i=0; i<len_num-l+1;i++)
      {
         int j=i + l - 1;
          for(int k=i; k<j; k++)
          {
              int max=0; int min=0;
              if(op[k] == '+') 
                { 
                    min = minval[i][k] + minval[k + 1][j]; 
                    max = maxval[i][k] + maxval[k + 1][j];  
                } 
                else if(op[k] == '*') 
                { 
                    min = minval[i][k] * minval[k + 1][j]; 
                    max = maxval[i][k] * maxval[k + 1][j]; 
                } 
                if (min <= minval[i][j]) 
                    minval[i][j] = min; 
                if (max >= maxval[i][j]) 
                    maxval[i][j] = max; 
                
          }
      }
  }
   printf("%d %d\n", maxval[0][len_num-1],minval[0][len_num-1] );
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<1;i++)
    {
        char s[100];
        scanf("%s", s);
        minmax(s);
    }
    return 0;
}