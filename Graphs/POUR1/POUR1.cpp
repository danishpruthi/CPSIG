#include<iostream>
#include<queue>

unsigned gcd(unsigned a,unsigned b)
{
	while(true)
	{
		if(a==0)return b;
		else b%=a;
		if(b==0)return a;
		else a%=b;
	}
}

class config
{
public:
	unsigned a,b;
	config(unsigned vola,unsigned volb):a(vola),b(volb){}
	config():a(0),b(0){}
};

unsigned mta0[40001],mtaf[40001],mtb0[40001],mtbf[40001];	//moves to (a,b)
bool visa0[40001],visaf[40001],visb0[40001],visbf[40001];	//visited (a,b)?
unsigned capa,capb;

unsigned movesto(unsigned a,unsigned b)
{
	if(a==0)return mta0[b];
	else if(a==capa)return mtaf[b];
	if(b==0)return mtb0[a];
	else if(b==capb)return mtbf[a];
}

void setmovesto(unsigned a,unsigned b,unsigned m)
{
	if(a==0)mta0[b]=m;
	else if(a==capa)mtaf[b]=m;
	if(b==0)mtb0[a]=m;
	else if(b==capb)mtbf[a]=m;
}

void setvisto(unsigned a,unsigned b,bool val)
{
	if(a==0)visa0[b]=val;
	else if(a==capa)visaf[b]=val;
	if(b==0)visb0[a]=val;
	else if(b==capb)visbf[a]=val;
}

using namespace std;
int main()
{
	unsigned i,t;
	unsigned a,b,c,g,m;
	unsigned infty=-1;
	queue<config> myqueue;
	cin>>t;
	while(t--)
	{
		cin>>capa>>capb>>c;
		if(c>capa && c>capb)
		{cout<<"-1\n";continue;}
		g=gcd(capa,capb);
		if(c%g!=0)
		{cout<<"-1\n";continue;}
		capa/=g;capb/=g;c/=g;

		for(i=0;i<=capb;++i)
		{mta0[i]=infty;mtaf[i]=infty;visa0[i]=false;visaf[i]=false;}
		for(i=0;i<=capa;++i)
		{mtb0[i]=infty;mtbf[i]=infty;visb0[i]=false;visbf[i]=false;}

		//BFS
		myqueue.push(config(0,0));
		mta0[0]=mtb0[0]=0;
		while(!myqueue.empty())
		{
			a=myqueue.front().a;
			b=myqueue.front().b;
			m=movesto(a,b)+1;
			setvisto(a,b,true);
			if(a==c || b==c)
			{cout<<m-1<<endl;break;}
			//calculate reachable configs. Add unvisited ones to queue.
			//emptying
			if(a!=0 && !visa0[b])
			{myqueue.push(config(0,b));if(m<mta0[b])setmovesto(0,b,m);}
			if(b!=0 && !visb0[a])
			{myqueue.push(config(a,0));if(m<mtb0[a])setmovesto(a,0,m);}
			//filling
			if(a!=capa && !visaf[b])
			{myqueue.push(config(capa,b));if(m<mtaf[b])setmovesto(capa,b,m);}
			if(b!=capb && !visbf[a])
			{myqueue.push(config(a,capb));if(m<mtbf[a])setmovesto(a,capb,m);}
			//pouring from b to a
			if(b>0 && a<capa)
			{
				if(a+b<=capa && !visb0[a+b])
				{myqueue.push(config(a+b,0));if(m<mtb0[a+b])setmovesto(a+b,0,m);}
				else if(a+b>capa && !visaf[a+b-capa])
				{myqueue.push(config(capa,a+b-capa));if(m<mtaf[a+b-capa])setmovesto(capa,a+b-capa,m);}
			}
			//pouring from a to b
			if(a>0 && b<capb)
			{
				if(a+b<=capb && !visa0[a+b])
				{myqueue.push(config(0,a+b));if(m<mta0[a+b])setmovesto(0,a+b,m);}
				else if(a+b>capb && !visbf[a+b-capb])
				{myqueue.push(config(a+b-capb,capb));if(m<mtbf[a+b-capb])setmovesto(a+b-capb,capb,m);}
			}
			myqueue.pop();
		}
		while(!myqueue.empty())myqueue.pop();
	}
	return 0;
}
