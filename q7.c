client.c
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[512];
int main( )
{
int readfd, writefd, fd;
ssize_t n;
char buff[512];
char end[5]="end";
int cmp = 0;
int le;
char st[80];
writefd=open(FIFO1, O_WRONLY, 0);
readfd =open(FIFO2, O_RDONLY, 0);
printf("Connected..\n");
while(1)
{
printf("Enter thr string " );
fgets(st,sizeof(st),stdin);
le = strlen(st);
st[le-1]='\0';
cmp = strcmp(st,"end");
if(cmp==0)
{
write(writefd,st,strlen(st)+1);printf("end");
break;
}
else
{
write(writefd,st,strlen(st)+1);
printf("%s\n",st);
}
}
printf("Waiting for reply from server ......\n");
while((n=read(readfd,buff,512))>0)
{
write(1,buff,n);
}
printf("\n");
close(readfd); unlink(FIFO1);
close(writefd); unlink(FIFO2);
}
server.c
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[80];
int sam = 0;
char fil[20]="hello.txt";
int main( )
{
int readfd, writefd, fd;
ssize_t n;
char buff[512];
char end[10];
int siz = 0;
FILE *f = fopen("hello.txt","w");
fclose(f);f = fopen("hello.txt","a");
if (mkfifo(FIFO1, PERMS)<0)
printf("Cant Create FIFO Files\n");
if (mkfifo(FIFO2, PERMS)<0)
printf("Cant Create FIFO Files\n");
printf("Waiting for connection Request..\n");
readfd =open(FIFO1, O_RDONLY, 0);
writefd=open(FIFO2, O_WRONLY, 0);
printf("Connection Established..\n");
strcpy(end,"end");
while(1)
{
siz = read(readfd, fname,sizeof(fname));
fname[siz]='\0';
sam = strcmp(fname,end);
if(sam!=0)
{
printf("received = %s\n",fname);
fprintf(f,"%s ",fname);
}
else
{
fclose(f);
break;
}
}
if ((fd=open(fil,O_RDWR))<0)
{
strcpy(buff,"File does not exist..\n");
write(writefd, buff, strlen(buff));
}
else
{
while((n=read(fd, buff,512))>0)
{
printf("reading");
write(writefd, buff, n);
}
}
close(readfd); unlink(FIFO1);
close(writefd); unlink(FIFO2);}
