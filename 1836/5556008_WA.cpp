#include<cstdio>
#include<cstring>
#include<cmath>
const double eps=1e-9;
double x[1100],q[1100];
int N,M,K,left,right,mid,top,ans,test,flag;

int main()
{
	int i,y;
	while(EOF!=scanf("%d",&N))
	{
	   for(i=1;i<=N;++i)
		   scanf("%lf",&x[i]);
	   ans=N+1;
	   for(M=1;M<=N;M++)
	   {
		                 ////求1-M严格单调上升子序列,M-N严格单调下降子序列
		                ////必须先找到第一个比x[M]小的。
           test=0;
		   top=0;
		   q[0]=-1.0;
		   for(i=1;i<M;++i)  
			   if(x[i]<=x[M])
			   {
			      if(x[i]>=q[top])
			        q[++top]=x[i];
			     else
				 {
				    left=1;
				    right=top;
				
				    while(left<=right)
					{
					   mid=(left+right)/2;
				
					   if(x[i]>=q[mid])
						   left=mid+1;
					   else
						   right=mid-1;
				   }
				
				       q[left]=x[i];
				 }
			   }
		   test+=M-1-top;
		   q[0]=-1.0;
		   top=0;
		   for(i=N;i>M;i--)
			   if(x[i]<=x[M])
		   {
                if(x[i]>=q[top])
					q[++top]=x[i];
				else
				{
                   left=1;
				   right=top;
				
				   while(left<=right)
				   {
					   mid=(left+right)/2;
				
					   if(x[i]>=q[mid])
						   left=mid+1;
					   else
						   right=mid-1;
				   }
				
				}
		   }
		   y=test;
		   test+=(N-M-top);
		  // printf("%d %d\n",y,test);
		   if(test<ans)
			   ans=test;
	   }
	   printf("%d\n",ans);
	}
	return 0;
}
