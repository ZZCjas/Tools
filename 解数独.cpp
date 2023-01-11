#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node
{
    int x,y,num;
};
node data[100];
int g[15][15],h[15][15],l[15][15],a[15][15],t;
vector<int>jc[10][10];
inline bool cmp(const node &a,const node &b)
{
  	if(a.num!=b.num)
    {
      	return a.num<b.num;
    }
  	if(a.x!=b.x)
    {
      	return a.x<b.x;
    }
  	if(a.y!=b.y)
    {
      	return a.y<b.y;
    }
}
inline int gt(int x,int y)
{
	if(x<=3&&y<=3)return 1;
	if(x<=3&&y>3&&y<=6)return 2;
	if(x<=3&&y>6&&y<=9)return 3;
	if(x>3&&x<=6&&y<=3)return 4;
	if(x>3&&x<=6&&y>3&&y<=6)return 5;
	if(x>3&&x<=6&&y>6&&y<=9)return 6;
	if(x>6&&x<=9&&y<=3)return 7;
	if(x>6&&x<=9&&y>3&&y<=6)return 8;
	if(x>6&&x<=9&&y>6&&y<=9)return 9;
}
inline void show()
{
	for(register int i=1;i<=9;i++)
	{
		for(register int j=1;j<=9;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
}
inline void dfs(int i)
{
	if(i==82)
	{
		show(); 
		exit(0);
	}
	if(data[i].num==0)
	{
		dfs(i+1);
	}
	else
	{
    	for(register int k=0;k<data[i].num;k++)
		{
    	    int x=data[i].x,y=data[i].y;
    	    int d=jc[x][y][k];
    	    if((!h[x][d])&&(!l[y][d])&&(!g[gt(x,y)][d]))
			{
				h[x][d]=1;
				l[y][d]=1;
				g[gt(x,y)][d]=1;
				a[x][y]=d;
				dfs(i+1);
				h[x][d]=0;
				l[y][d]=0;
				g[gt(x,y)][d]=0;
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(register int i=1;i<=9;i++)
	{
		for(register int j=1;j<=9;j++)
		{
			cin>>a[i][j];
			h[i][a[i][j]]=1;
			l[j][a[i][j]]=1;
			g[gt(i,j)][a[i][j]]=1;
		}
	}
    for(register int i=1;i<=9;i++)
	{
		for(register int j=1;j<=9;j++)
		{
			for(register int k=1;k<=9;k++)
			{
			 	if(a[i][j]!=0)
			 	{
			 		continue;	
				}
                if(h[i][k]==0&&l[j][k]==0&&g[gt(i,j)][k]==0)
				{
		      	  	jc[i][j].push_back(k);
		    	}
			}
		}
	}
	for(register int i=1;i<=9;i++)
	{
		for(register int j=1;j<=9;j++)
		{
		   data[++t]={i,j,jc[i][j].size()};
		}
	}
    stable_sort(data+1,data+82,cmp);
	dfs(1);
	return 0;
}
