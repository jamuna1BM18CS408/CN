#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
#define bucketsize 256
void bktinput(int a, int b);
int main()
{
int op,pktsize,pktsize[]={100, 345, 230,78, 980, 130, 7, 89, 670, 256};
cout<<"Enter output rate:";
cin>>op; //50(Mbps)
for(int i=0;i<10;i++)
{
usleep(rand()%1000);
cout<<"\nPacket no"<<i+1<<"\tPacket size="<<pktsize[i];
bktinput(pktsize[i],op);
}
return 0;
}
void bktinput(int a,int b)
{
if(a>bucketsize)
cout<<"\n\t\tBucket overflow";
else{
usleep(500);
while(a>b)
{
cout<<"\n\t\t"<<b<<"bytes outputted";
a-=b;
usleep(500);
}
if(a>0)
cout<<"\n\t\tlast"<<a<<"bytes sent\t";
cout<<"\n\t\t Bucket output successful";
}
}
