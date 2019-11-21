#include<stdio.h>
struct node
{
    int dist[20];
    int from[20];
    
}rt[10];

int main()
{
    int costmat[20][20];
    int nodes,i,j,count=0;
   // clrscr();
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(int i=0;i<nodes;i++)            
            for(int j=0;j<nodes;j++)
            for(int k=0;k<nodes;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        
        for(int i=0;i<nodes;i++)
        {
            printf("\n For router %d \n",i);
            for(int j=0;j<nodes;j++)
            {
                printf("\n node %d to %d via %d Distance %d ",i,j,rt[i].from[j],rt[i].dist[j]);
            }
        }
    printf("\n\n");
    //getc();
    return 0;
}

output:
Enter the number of nodes : 3

Enter the cost matrix :
0	2	3
2	0	1
3	1	0

 For router 0 

 node 0 to 0 via 0 Distance 0 
 node 0 to 1 via 1 Distance 2 
 node 0 to 2 via 2 Distance 3 
 For router 1 

 node 1 to 0 via 0 Distance 2 
 node 1 to 1 via 1 Distance 0 
 node 1 to 2 via 2 Distance 1 
 For router 2 

 node 2 to 0 via 0 Distance 3 
 node 2 to 1 via 1 Distance 1 
 node 2 to 2 via 2 Distance 0 
