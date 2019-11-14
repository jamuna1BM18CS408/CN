#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#define bucketsize 512
using namespace std;

void bktInput(int a,int b)
	{
	if(a>bucketsize)
	{
		cout<<"overflow\n";
	}
	else
	{
		usleep(500);
	}
	while(a>b)
	{
		cout<<"\t\t"<<b<<"bytes outputed\n";
		a-=b;
		usleep(500);
	}
	if(a>0)
	{
		cout<<"\n\t last"<<a<<"bytes sent\n";
		cout<<"\n\t bucket o/p successfully";
	}
	}
int main()
	{
		int op,pktsize;
		cout<<"enter o/p rate";
		cin>>op;
	for(int i=1;i<=5;i++)
	{
		usleep(rand()%1000);
		pktsize=rand()%1000;
		cout<<"\n packet no"<<i<<"\t packet size="<<pktsize;
		bktInput(pktsize,op);
	}
	return 0;
	}
