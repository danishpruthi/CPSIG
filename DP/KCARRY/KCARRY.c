#include<stdio.h>

unsigned mod_mult(unsigned a, unsigned b)
{
	const unsigned mbase=1000000007;
	unsigned long long prod=a;
	prod*=b;return prod%mbase;
}

int main()
{
	const unsigned mbase=1000000007;
	unsigned t,nmax=0,i,j;
	unsigned ns[500],ks[500];
	unsigned f0[1001][1001],f1[1001][1001];
	const unsigned f010=55,f011=45,f110=45,f111=55;
	scanf("%u",&t);
	for(i=0;i<t;++i)
	{
		scanf("%u%u",ns+i,ks+i);
		if(nmax<ns[i])nmax=ns[i];
	}

	for(i=0;i<=nmax;++i)for(j=0;j<=nmax;++j)
	{f0[i][j]=0;f1[i][j]=0;}
	f0[0][0]=1;f1[0][0]=1;
	f0[1][0]=f010;f0[1][1]=f011;
	f1[1][0]=f110;f1[1][1]=f111;

	for(i=2;i<=nmax;++i)
	{
		f0[i][0]=mod_mult(f010,f0[i-1][0]);
		f1[i][0]=mod_mult(f110,f0[i-1][0]);
		for(j=1;j<=i;++j)
		{
			f0[i][j]=(mod_mult(f010,f0[i-1][j])+mod_mult(f011,f1[i-1][j-1]))%mbase;
			f1[i][j]=(mod_mult(f110,f0[i-1][j])+mod_mult(f111,f1[i-1][j-1]))%mbase;
		}
	}

	for(i=0;i<t;++i)
	{printf("%u\n",f0[ns[i]][ks[i]]);}
	return 0;
}
