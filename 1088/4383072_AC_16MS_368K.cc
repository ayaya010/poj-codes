#include<stdio.h>
int f[102][102],a[102][102],R,C;
int dp(int i,int j)
{
   if(i<1||i>R||j<1||j>C)
	   return 0;
   if(f[i][j]>0)
    return f[i][j];
   int max=1;
  if(a[i][j]<a[i+1][j])
     max=dp(i+1,j)+1>max?dp(i+1,j)+1:max;
  if(a[i][j]<a[i-1][j])
   max=dp(i-1,j)+1>max?dp(i-1,j)+1:max;
  if(a[i][j]<a[i][j-1])
     max=dp(i,j-1)+1>max?dp(i,j-1)+1:max;
  if(a[i][j]<a[i][j+1])
     max=dp(i,j+1)+1>max?dp(i,j+1)+1:max;
   return f[i][j]=max;
}
int main()
{
  int max,i,j;
  scanf("%d%d",&R,&C);
   for(i=1;i<=R;i++)
      for(j=1;j<=C;j++)
	  {
		  scanf("%d",&a[i][j]);
          f[i][j]=0;
	  }
   max=-1;
   for(i=1;i<=R;i++)
     for(j=1;j<=C;j++)
     {
     f[i][j]=dp(i,j);
     if(f[i][j]>max)
         max=f[i][j];
     }
  printf("%d\n",max);
return 0;
}
