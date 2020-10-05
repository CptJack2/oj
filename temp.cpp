
#include<stdio.h>
//城市的尺寸 
int n;
//城市的地图，最多是4*4
char map[4][4];
//最多放的炮塔数
int bestn;
//看炮塔是否能够放置 
int canput(int row,int col)
{
	int i;
	for(i=row-1;i>=0;i--)
	{
		if(map[i][col]=='X')
		{
			break;
		}
		if(map[i][col]=='o')
		{
			return 0;
		}
	}
	for(i=col-1;i>=0;i--)
	{
		if(map[row][i]=='X')
		{
			break;
		}
		if(map[row][i]=='o')
		{
			return 0;
		}
	}
	return 1;
}
//K表示放置炮塔的位置 
void backtrack(int k,int current)
{
	int x,y;
	if(k>=n*n)
	{
		if(current>bestn)
		{
			bestn=current;
		}
		return;
	}
	else
	{
		x=k/n;
		y=k%n;
		if(map[x][y]=='.'&&canput(x,y))
		{
			map[x][y]='o';
			backtrack(k+1,current+1);
			map[x][y]='.';
		}
		backtrack(k+1,current);
	}
}
void initial()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			map[i][j]='.';
		}
	}
}
int main()
{
	scanf("%d",&n);
	while(n)
	{
		int i,j;
		bestn=0;
		initial();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				char ch;
				ch=getchar();
				if(ch=='\n')
				{
					j--;
					continue;
				}
				else
				{
					map[i][j]=ch;
				}
			}
		}
		backtrack(0,0);
		printf("%d\n",bestn);
		scanf("%d",&n);
	}

	return 0;
}