#include<stdio.h>

#define INT_MAX 999999

int n=4;
int dp[16][4];
int path[16][4];
int dist[10][10]={
{0,20,42,25},
{20,0,30,34},
{42,30,0,10},
{25,34,10,0}
};

int tsp(int mask, int pos)
{

if(mask==(1<<n)-1)
return dist[pos][0];

int ans=INT_MAX;

if(dp[mask][pos]!=-1)
return dp[mask][pos];

for(int city=0;city<n;city++)

{
	if((mask & (1<<city))==0)
	{
	int newAns= dist[pos][city] + tsp((mask|(1<<city)),city);
	if(newAns<ans)
	ans=newAns;
	path[mask][pos]=city;
	}
}

return dp[mask][pos]=ans;
}


void result(int mask ,int pos)
{

printf("0->");

for(int i=0;i<n-1;i++)
{
int nextcity=path[mask][pos];
printf("%d->",nextcity);
mask |= (1<<nextcity);
pos=nextcity;

}


printf("0\n");

}


int main()
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<4;j++)
		{
		dp[i][j]=-1;
		}
	}

printf("shortest path is %d\n",tsp(1,0));
result(1,0);
return 0;

}
