#include<stdio.h>

long long n,S;
long long sumF[11000],sumT[11000],st[40000],dp[11000];

double HH(int a,int b)
{
	return (double)(dp[a]-dp[b])/(double)(sumT[a]-sumT[b]);
}

int main()
{
	long long i,j,a,b,l,r;

	while(EOF!=scanf("%lld",&n))
	{
		scanf("%lld",&S);
		sumF[n+1]=sumT[n+1]=0;
		for(i=1;i<=n;i++)
			scanf("%lld %lld",&sumT[i],&sumF[i]);

		for(i=n;i>=1;i--)
			sumT[i]+=sumT[i+1],sumF[i]+=sumF[i+1];

		l=1,r=0;
		dp[n]=(S+sumT[n])*sumF[n];
		st[++r]=n;
		for(i=n-1;i>=1;i--)
		{

			while(r-l+1>=2&&HH(st[l],st[l+1])<sumF[i])
				 l++;

			j=st[l];
			dp[i]=dp[j]+(S+sumT[i]-sumT[j])*sumF[i];

			while(r-l+1>=2&&HH(r-1,r)>HH(r,i))
				 r--;
			st[++r]=i;
		}

        printf("%lld\n",dp[1]);
	}
	return 0;
}