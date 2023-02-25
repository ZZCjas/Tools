//草原生态模拟器,By赵紫辰 
#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
#include <random>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <ctime>
using namespace std;
string path,store;
void color(int x)
{
	if(x>=0&&x<=15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
void error(string s)
{
	color(4);
	cerr<<s<<endl;
	color(7);
	throw s.c_str();
	exit(-1);
}
inline void run_en()
{
	int x=0,y=0;
	long long d=0; 
	FILE *load=fopen(store.c_str(),"r");
	if(fscanf(load,"%d%d%lld",&x,&y,&d)!=3)
	{
		error("存档文件已损坏!");
	}
	if(x>1000||y>1000||x<1||y<1)
	{
		error("Map size error");
	} 
	char en[x+1][y+1];
	for(register int i=1;i<=x;i++)
	{
		if(fscanf(load,"%s",en[i])!=1)
		{
			error("存档文件已损坏!");
		}
	}
	system("cls");
	system("title 模拟中");
	for(;;d++)
	{
		if(d!=1)
		{
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					if(en[i][j]=='w')
					{
						if(en[i-1][j]=='s')
						{
							en[i-1][j]='.';
						}
						if(en[i][j-1]=='s')
						{
							en[i-1][j]='.';
						}
						if(en[i+1][j]=='s')
						{
							en[i+1][j]='.';
						}
						if(en[i][j+1]=='s')
						{
							en[i][j+1]='.';
						} 
						if(en[i-1][j]=='.')
						{
							en[i-1][j]='w';
						}
						else if(en[i+1][j]=='.')
						{
							en[i+1][j]='w';
						}
						else if(en[i][j+1]=='.')
						{
							en[i][j+1]='w';
						}
						else if(en[i][j-1]=='.')
						{
							en[i][j-1]='w';
						}
					}
					else if(en[i][j]=='s')
					{
						if(en[i-1][j]=='#')
						{
							en[i-1][j]='.';
						}
						if(en[i][j-1]=='#')
						{
							en[i-1][j]='.';
						}
						if(en[i+1][j]=='#')
						{
							en[i+1][j]='.';
						}
						if(en[i][j+1]=='#')
						{
							en[i][j+1]='.';
						}
						else if(en[i-1][j]=='.')
						{
							en[i-1][j]='s';
						}
						else if(en[i+1][j]=='.')
						{
							en[i+1][j]='s';
						}
						else if(en[i][j+1]=='.')
						{
							en[i][j+1]='s';
						}
						else if(en[i][j-1]=='.')
						{
							en[i][j-1]='s';
						}
					}
					else if(en[i][j]=='#')
					{
						if(en[i-1][j]=='.')
						{
							en[i-1][j]='#';
						}
						if(en[i][j-1]=='.')
						{
							en[i-1][j]='#';
						}
						if(en[i+1][j]=='.')
						{
							en[i+1][j]='#';
						}
						if(en[i][j+1]=='.')
						{
							en[i][j+1]='#';
						}
					}
				}
			}
		}
		cout<<"第"<<d<<"天:\n"; 
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				putchar(en[i][j]);
			}
			putchar('\n');
		}
		A:cout<<"请输入指令:";
		string s;
		cin>>s;
		if(s=="help")
		{
			cout<<"命令大全:\n";
			cout<<"kill命令,参数x和y,指定要杀死的方块,杀死后变为空地\n";
			cout<<"kill_line命令,参数x,指定要杀死的横行,杀死后变为空地\n";
			cout<<"kill_square命令,参数x1,y1,x2,y2,指定要杀死的二维区间,杀死后变为空地\n";
			cout<<"change命令,参数x,y和字符c,指定要改变的方块\n";
			cout<<"change_line命令,参数x和字符c,指定要改变的横行\n";
			cout<<"change_square命令,参数x1,y1,x2,y2和字符c,定要改变的二维区间\n";
			cout<<"next命令,进入下一天\n";
			cout<<"exit命令,退出程序\n";
			cout<<"help命令,获取命令大全和方块字符大全\n";
			cout<<"Atom_Bomb命令,用核弹炸毁草原,将生命体统统杀死,只留下空地\n";
			cout<<"save命令,存档\n";
			cout<<"file_format命令,获取存档文件格式\n\n";
			cout<<"方块字符大全:\n";
			cout<<"w代表狼,狼会吃上下左右的羊,也会向四周的空地繁育后代\n";
			cout<<"s代表羊,羊会吃上下左右的草,也会向四周的空地繁育后代\n";
			cout<<"#代表草,草会向上下左右的空地生长\n";
			cout<<".代表空地\n\n";
			system("pause");
			goto A;
		}
		else if(s=="kill")
		{
			cout<<"请输入参数:\n";
			int g,l;
			cin>>g>>l;
			en[g][l]='.'; 
			system("cls");
		}
		else if(s=="next")
		{
			system("cls");
			continue;
		}
		else if(s=="exit")
		{
			system("pause");
			exit(0);
		}
		else if(s=="kill_line")
		{
			cout<<"请输入参数:\n";
			int h;
			cin>>h;
			for(int i=1;i<=x;i++)
			{
				en[i][h]='.';
			}
			system("cls");
		}
		else if(s=="kill_square")
		{
			cout<<"请输入参数:\n";
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int i=x1;i<=x2;i++)
			{
				for(int j=y1;j<=y2;j++)
				{
					en[i][j]='.';
				}
			}
			system("cls");
		}
		else if(s=="change_square")
		{
			C:cout<<"请输入参数:\n";
			int x1,y1,x2,y2;
			char zz;
			cin>>x1>>y1>>x2>>y2>>zz;
			if(zz!='#'&&zz!='.'&&zz!='s'&&zz!='w')
			{
				cout<<"Bad Command!\n";
				goto C;
			}
			for(int i=x1;i<=x2;i++)
			{
				for(int j=y1;j<=y2;j++)
				{
					en[i][j]=zz;
				}
			}
			system("cls");
		}
		else if(s=="change_line")
		{
			B:cout<<"请输入参数:\n";
			int h;
			char zzz;
			cin>>h>>zzz;
			if(zzz!='#'&&zzz!='.'&&zzz!='s'&&zzz!='w')
			{
				cout<<"Bad Command!\n";
				goto B;
			}
			for(int i=1;i<=y;i++)
			{
				en[h][i]=zzz;
			}
			system("cls");
		}
		else if(s=="change")
		{
			D:cout<<"请输入参数:\n";
			int g,l;
			char zzzz;
			cin>>g>>l>>zzzz;
			if(zzzz!='#'&&zzzz!='.'&&zzzz!='s'&&zzzz!='w')
			{
				cout<<"Bad Command!\n";
				goto D;
			}
			en[g][l]=zzzz; 
			system("cls");
		}
		else if(s=="Atom_Bomb")
		{
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					en[i][j]='.';
				}
			}
			color(4);
			cout<<"所有生命体都已被核弹摧毁!哈哈哈!\n";
			color(1000);
			system("pause");
			system("cls");
		}
		else if(s=="save")
		{
			FILE *save=fopen(store.c_str(),"w");
			fprintf(save,"%d %d %lld\n",x,y,d);
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					fprintf(save,"%c",en[i][j]);
				}
				fprintf(save,"\n");
			}
			fclose(save);
			cout<<"存档成功!\n";
			system("pause");
			goto A;
		}
		else if(s=="file_format")
		{
			cout<<"存档文件格式:\n第一行3个正整数,分别表示地图的长,地图的宽,和已过去的天数\n下面就是地图内容了\n";
			system("pause");
			goto A;
		}
		else
		{
			cout<<"Bad Command!\n";
			goto A;
		}
	}
}
inline void new_en(int x,int y)
{
	char en[x+1][y+1];
	mt19937 rander(time(0)+clock());
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			int r=rander()%6;
			if(r==0)
			{
				en[i][j]='.';//土 
			}
			if(r==4)
			{
				en[i][j]='.';//土 
			}
			if(r==3)
			{
				en[i][j]='s';//羊 
			}
			if(r==2)
			{
				en[i][j]='w';//狼 
			}
			if(r==1)
			{
				en[i][j]='#';//草 
			}
			if(r==5)
			{
				en[i][j]='#';//草 
			}
		}
	}
	system("cls");
	system("title 生成地图中...");
	Sleep(1000);
	system("title 模拟中");
	for(long long d=1;;d++)
	{
		if(d!=1)
		{
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					if(en[i][j]=='w')
					{
						if(en[i-1][j]=='s')
						{
							en[i-1][j]='.';
						}
						if(en[i][j-1]=='s')
						{
							en[i-1][j]='.';
						}
						if(en[i+1][j]=='s')
						{
							en[i+1][j]='.';
						}
						if(en[i][j+1]=='s')
						{
							en[i][j+1]='.';
						} 
						if(en[i-1][j]=='.')
						{
							en[i-1][j]='w';
						}
						else if(en[i+1][j]=='.')
						{
							en[i+1][j]='w';
						}
						else if(en[i][j+1]=='.')
						{
							en[i][j+1]='w';
						}
						else if(en[i][j-1]=='.')
						{
							en[i][j-1]='w';
						}
					}
					else if(en[i][j]=='s')
					{
						if(en[i-1][j]=='#')
						{
							en[i-1][j]='.';
						}
						if(en[i][j-1]=='#')
						{
							en[i-1][j]='.';
						}
						if(en[i+1][j]=='#')
						{
							en[i+1][j]='.';
						}
						if(en[i][j+1]=='#')
						{
							en[i][j+1]='.';
						}
						else if(en[i-1][j]=='.')
						{
							en[i-1][j]='s';
						}
						else if(en[i+1][j]=='.')
						{
							en[i+1][j]='s';
						}
						else if(en[i][j+1]=='.')
						{
							en[i][j+1]='s';
						}
						else if(en[i][j-1]=='.')
						{
							en[i][j-1]='s';
						}
					}
					else if(en[i][j]=='#')
					{
						if(en[i-1][j]=='.')
						{
							en[i-1][j]='#';
						}
						if(en[i][j-1]=='.')
						{
							en[i-1][j]='#';
						}
						if(en[i+1][j]=='.')
						{
							en[i+1][j]='#';
						}
						if(en[i][j+1]=='.')
						{
							en[i][j+1]='#';
						}
					}
				}
			}
		}
		cout<<"第"<<d<<"天:\n"; 
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				putchar(en[i][j]);
			}
			putchar('\n');
		}
		A:cout<<"请输入指令:";
		string s;
		cin>>s;
		if(s=="help")
		{
			cout<<"命令大全:\n";
			cout<<"kill命令,参数x和y,指定要杀死的方块,杀死后变为空地\n";
			cout<<"kill_line命令,参数x,指定要杀死的横行,杀死后变为空地\n";
			cout<<"kill_square命令,参数x1,y1,x2,y2,指定要杀死的二维区间,杀死后变为空地\n";
			cout<<"change命令,参数x,y和字符c,指定要改变的方块\n";
			cout<<"change_line命令,参数x和字符c,指定要改变的横行\n";
			cout<<"change_square命令,参数x1,y1,x2,y2和字符c,定要改变的二维区间\n";
			cout<<"next命令,进入下一天\n";
			cout<<"exit命令,退出程序\n";
			cout<<"help命令,获取命令大全和方块字符大全\n";
			cout<<"Atom_Bomb命令,用核弹炸毁草原,将生命体统统杀死,只留下空地\n";
			cout<<"save命令,存档\n";
			cout<<"file_format命令,获取存档文件格式\n\n";
			cout<<"方块字符大全:\n";
			cout<<"w代表狼,狼会吃上下左右的羊,也会向四周的空地繁育后代\n";
			cout<<"s代表羊,羊会吃上下左右的草,也会向四周的空地繁育后代\n";
			cout<<"#代表草,草会向上下左右的空地生长\n";
			cout<<".代表空地\n\n";
			system("pause");
			goto A;
		}
		else if(s=="kill")
		{
			cout<<"请输入参数:\n";
			int g,l;
			cin>>g>>l;
			en[g][l]='.'; 
			system("cls");
		}
		else if(s=="next")
		{
			system("cls");
			continue;
		}
		else if(s=="exit")
		{
			system("pause");
			exit(0);
		}
		else if(s=="kill_line")
		{
			cout<<"请输入参数:\n";
			int h;
			cin>>h;
			for(int i=1;i<=x;i++)
			{
				en[i][h]='.';
			}
			system("cls");
		}
		else if(s=="kill_square")
		{
			cout<<"请输入参数:\n";
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int i=x1;i<=x2;i++)
			{
				for(int j=y1;j<=y2;j++)
				{
					en[i][j]='.';
				}
			}
			system("cls");
		}
		else if(s=="change_square")
		{
			C:cout<<"请输入参数:\n";
			int x1,y1,x2,y2;
			char zz;
			cin>>x1>>y1>>x2>>y2>>zz;
			if(zz!='#'&&zz!='.'&&zz!='s'&&zz!='w')
			{
				cout<<"Bad Command!\n";
				goto C;
			}
			for(int i=x1;i<=x2;i++)
			{
				for(int j=y1;j<=y2;j++)
				{
					en[i][j]=zz;
				}
			}
			system("cls");
		}
		else if(s=="change_line")
		{
			B:cout<<"请输入参数:\n";
			int h;
			char zzz;
			cin>>h>>zzz;
			if(zzz!='#'&&zzz!='.'&&zzz!='s'&&zzz!='w')
			{
				cout<<"Bad Command!\n";
				goto B;
			}
			for(register int i=1;i<=x;i++)
			{
				en[i][h]=zzz;
			}
			system("cls");
		}
		else if(s=="change")
		{
			D:cout<<"请输入参数:\n";
			int g,l;
			char zzzz;
			cin>>g>>l>>zzzz;
			if(zzzz!='#'&&zzzz!='.'&&zzzz!='s'&&zzzz!='w')
			{
				cout<<"Bad Command!\n";
				goto D;
			}
			en[g][l]=zzzz; 
			system("cls");
		}
		else if(s=="Atom_Bomb")
		{
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					en[i][j]='.';
				}
			}
			color(4);
			cout<<"所有生命体都已被核弹摧毁!哈哈哈!\n";
			color(1000);
			system("pause");
			system("cls");
		}
		else if(s=="save")
		{
			cout<<"请输入保存路径:";
			cin>>path;
			FILE *save=fopen(path.c_str(),"w");
			fprintf(save,"%d %d %lld\n",x,y,d);
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					fprintf(save,"%c",en[i][j]);
				}
				fprintf(save,"\n");
			}
			fclose(save);
			cout<<"存档成功!\n";
			system("pause");
			goto A;
		}
		else if(s=="file_format")
		{
			cout<<"存档文件格式:\n第一行3个正整数,分别表示地图的长,地图的宽,和已过去的天数\n下面就是地图内容了\n";
			system("pause");
			goto A;
		}
		else
		{
			cout<<"Bad Command!\n";
			goto A;
		}
	}
}
int x,y,n;
int main()
{
	system("title 草原生态模拟器");
	color(2);
	cout<<"草原生态模拟器\n";
	color(7);
	cout<<"By 赵紫辰\n适用于Windows系统\n";
	color(1);
	cout<<"小提示:开始模拟后可通过输入help命令获取命令大全与方块字符大全\n"; 
	color(7);
	cout<<"模拟器模式:\n1.创建新草原生态\n2.读档\n请输入:";
	cin>>n;
	if(n==1)
	{
		cout<<"请输入新地图的长和宽(推荐为25*25,最大1000*1000):\n";
		cin>>x>>y;
		if(x>1000||y>1000||x<1||y<1)
		{
			error("Map size error");
		}
		new_en(x,y);
	}
	else if(n==2) 
	{
		cout<<"请输入存档文件路径:";
		cin>>store;
		FILE *tester=fopen(store.c_str(),"r");
		if(tester==NULL)
		{
			error("无效存档文件路径!");
		}
		color(2);
		cout<<"读档中!正在加载...\n";
		color(7);
		Sleep(1000);
		run_en();
	}
	return 0;
} 
