#include<stdio.h>
#include<vector>
using namespace std;
vector< int > c;
char a[110],b[110];
int i,j,k,temp,n;
void solve()
{
  int len1,len2,v;
  len1=strlen(a);len2=strlen(b);
  c.clear();
  for(j=0;j<len1;++j)//计算出每一位的累积结果 
       for(k=0;k<len2;++k)
       {
           v=(a[j]-'0')*(b[k]-'0');
           if(j+k>=c.size()) 
              c.push_back(v);
           else
              c[j+k]+=v;
       }
    for(j=0;j<c.size();++j) //集中处理进位 
    {
       if(j+1==c.size()) //如果最高位>=1000,向前进1位，压入新的进位 
        {
          if(c[j]>=10)
            {
               c.push_back(c[j]/10);
               c[j]%=10;
               break;
            }
        }
       else
           c[j+1]+=c[j]/10;
       c[j]%=10;
    }
  i=c.size()-1;
  printf("%d",c[i]);//先输出第1位 
  for(i=i-1;i>=0;--i)//输出后面的每位，如果位数不够，补足3位 
      printf("%d",c[i]);
  printf("\n");         
}
int main()
{
  while(EOF!=scanf("%s%s",a,b))
  {
    solve();//
  }
  return 0;
}
