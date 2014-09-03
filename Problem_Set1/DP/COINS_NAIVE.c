# include<stdio.h>
long long mem[1000000];
long long solve(long long a) {
  if(a==0) return 0;
  if(a<1000000 && mem[a]!=0) return mem[a];
  long long ret=solve(a/2) + solve(a/3) + solve(a/4) ;
  ret= ret > a ? ret:a;
  if(a<1000000) mem[a]=ret;
  return ret;

}
int main()
{
long long test;
while(scanf("%lld",&test)==1) {
  printf("%lld\n",solve(test));
}
return 0;
}



