#include<stdio.h>

void prims();

int cost[10][10],vis[10],vt[10],et[10][10];
int e=0,i,j,k,u,v,sum=0,n,m;

void main()
{
    printf("Enter Number of Vertices : ");
    scanf("%d",&n);

    printf("Enter Adjecent Matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
        vis[i]=0;
    }

    prims();

    printf("MST------------->\n");
    for(i=1;i<=e;i++)
    {
        printf("%d -> %d \n",et[i][1],et[i][2]);
    }
    printf("total cost= %d \n",sum);
}

void prims()
{
    int x=1,min;

    vt[x]=1;
    vis[x]=1;

    for (i=1;i<n;i++)
    {
        min=999;

        for (j=1;j<=x;j++)
        {
            k=vt[j];

            for (m=1;m<=n;m++)
            {
                if (cost[k][m] < min && vis[m]==0)
                {
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
        }

        vt[++x]=v;
        et[e+1][1]=u;
        et[e+1][2]=v;
        e++;

        vis[v]=1;
        sum = sum + cost[u][v];
    }
}
