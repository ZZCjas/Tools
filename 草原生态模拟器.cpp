//��ԭ��̬ģ����,By���ϳ� 
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
inline void run_en()
{
	int x,y;
	FILE *load=fopen(store.c_str(),"r");
	fscanf(load,"%d%d",&x,&y);
	char en[x+1][y+1];
	for(register int i=1;i<=x;i++)
	{
		fscanf(load,"%s",en[i]);
	}
	system("cls");
	system("title ģ����");
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
		cout<<"��"<<d<<"��:\n"; 
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				putchar(en[i][j]);
			}
			putchar('\n');
		}
		A:cout<<"������ָ��:\n";
		string s;
		cin>>s;
		if(s=="help")
		{
			cout<<"�����ȫ:\n";
			cout<<"kill����,����x��y,ָ��Ҫɱ���ķ���,ɱ�����Ϊ�յ�\n";
			cout<<"kill_line����,����x,ָ��Ҫɱ���ĺ���,ɱ�����Ϊ�յ�\n";
			cout<<"kill_square����,����x1,y1,x2,y2,ָ��Ҫɱ���Ķ�ά����,ɱ�����Ϊ�յ�\n";
			cout<<"change����,����x,y���ַ�c,ָ��Ҫ�ı�ķ���\n";
			cout<<"change_line����,����x���ַ�c,ָ��Ҫ�ı�ĺ���\n";
			cout<<"change_square����,����x1,y1,x2,y2���ַ�c,ָ��Ҫ�ı�Ķ�ά����\n";
			cout<<"next����,������һ��\n";
			cout<<"exit����,�˳�����\n";
			cout<<"help����,��ȡ�����ȫ�ͷ����ַ���ȫ\n";
			cout<<"Atom_Bomb����,�ú˵�ը�ٲ�ԭ,��������ͳͳɱ��,ֻ���¿յ�\n";
			cout<<"save����,�浵\n\n";
			cout<<"�����ַ���ȫ:\n";
			cout<<"w������,�ǻ���������ҵ���\n";
			cout<<"s������,�����������ҵĲ�\n";
			cout<<"#�����,�ݻ����������ҵĿյ�����\n";
			cout<<".����յ�\n\n";
			system("pause");
			system("cls");
		}
		else if(s=="kill")
		{
			cout<<"���������:\n";
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
			cout<<"���������:\n";
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
			cout<<"���������:\n";
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
			C:cout<<"���������:\n";
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
			B:cout<<"���������:\n";
			int h;
			char zzz;
			cin>>h>>zzz;
			if(zzz!='#'&&zzz!='.'&&zzz!='s'&&zzz!='w')
			{
				cout<<"Bad Command!\n";
				goto B;
			}
			for(int i=1;i<=x;i++)
			{
				en[i][h]=zzz;
			}
			system("cls");
		}
		else if(s=="change")
		{
			D:cout<<"���������:\n";
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
			cout<<"���������嶼�ѱ��˵��ݻ�!������!\n";
			color(1000);
			system("pause");
			system("cls");
		}
		else if(s=="save")
		{
			FILE *save=fopen(store.c_str(),"w");
			fprintf(save,"%d %d\n",x,y);
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					fprintf(save,"%c",en[i][j]);
				}
				fprintf(save,"\n");
			}
			fclose(save);
			cout<<"�浵�ɹ�!\n";
			system("pause");
			system("cls");
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
				en[i][j]='.';//�� 
			}
			if(r==4)
			{
				en[i][j]='.';//�� 
			}
			if(r==3)
			{
				en[i][j]='s';//�� 
			}
			if(r==2)
			{
				en[i][j]='w';//�� 
			}
			if(r==1)
			{
				en[i][j]='#';//�� 
			}
			if(r==5)
			{
				en[i][j]='#';//�� 
			}
		}
	}
	system("cls");
	system("title ���ɵ�ͼ��...");
	Sleep(1000);
	system("title ģ����");
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
		cout<<"��"<<d<<"��:\n"; 
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				putchar(en[i][j]);
			}
			putchar('\n');
		}
		A:cout<<"������ָ��:\n";
		string s;
		cin>>s;
		if(s=="help")
		{
			cout<<"�����ȫ:\n";
			cout<<"kill����,����x��y,ָ��Ҫɱ���ķ���,ɱ�����Ϊ�յ�\n";
			cout<<"kill_line����,����x,ָ��Ҫɱ���ĺ���,ɱ�����Ϊ�յ�\n";
			cout<<"kill_square����,����x1,y1,x2,y2,ָ��Ҫɱ���Ķ�ά����,ɱ�����Ϊ�յ�\n";
			cout<<"change����,����x,y���ַ�c,ָ��Ҫ�ı�ķ���\n";
			cout<<"change_line����,����x���ַ�c,ָ��Ҫ�ı�ĺ���\n";
			cout<<"change_square����,����x1,y1,x2,y2���ַ�c,��Ҫ�ı�Ķ�ά����\n";
			cout<<"next����,������һ��\n";
			cout<<"exit����,�˳�����\n";
			cout<<"help����,��ȡ�����ȫ�ͷ����ַ���ȫ\n";
			cout<<"Atom_Bomb����,�ú˵�ը�ٲ�ԭ,��������ͳͳɱ��,ֻ���¿յ�\n";
			cout<<"save����,�浵\n\n";
			cout<<"�����ַ���ȫ:\n";
			cout<<"w������,�ǻ���������ҵ���\n";
			cout<<"s������,�����������ҵĲ�\n";
			cout<<"#�����,�ݻ����������ҵĿյ�����\n";
			cout<<".����յ�\n\n";
			system("pause");
			system("cls");
		}
		else if(s=="kill")
		{
			cout<<"���������:\n";
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
			cout<<"���������:\n";
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
			cout<<"���������:\n";
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
			C:cout<<"���������:\n";
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
			B:cout<<"���������:\n";
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
			D:cout<<"���������:\n";
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
			cout<<"���������嶼�ѱ��˵��ݻ�!������!\n";
			color(1000);
			system("pause");
			system("cls");
		}
		else if(s=="save")
		{
			cout<<"�����뱣��·��:\n";
			cin>>path;
			FILE *save=fopen(path.c_str(),"w");
			fprintf(save,"%d %d\n",x,y);
			for(int i=1;i<=x;i++)
			{
				for(int j=1;j<=y;j++)
				{
					fprintf(save,"%c",en[i][j]);
				}
				fprintf(save,"\n");
			}
			fclose(save);
			cout<<"�浵�ɹ�!\n";
			system("pause");
			system("cls");
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
	system("title ��ԭ��̬ģ����");
	color(2);
	cout<<"��ԭ��̬ģ����\n";
	color(7);
	cout<<"By ���ϳ�\n������Windowsϵͳ\n";
	color(1);
	cout<<"С��ʾ:����ģ��ģʽ���ͨ������help�����ȡ�����ȫ�뷽���ַ���ȫ\n"; 
	color(7);
	cout<<"�Ƿ����?\n1.����\n2.������\n������:";
	cin>>n;
	if(n==2)
	{
		cout<<"�������µ�ͼ�ĳ��Ϳ�(�Ƽ�Ϊ25*25,���1000*1000):\n";
		cin>>x>>y;
		if(x>1000||y>1000)
		{
			cerr<<"Map size too large\n";
			throw "Map size too large";
		}
		new_en(x,y);
	}
	else
	{
		cout<<"������浵�ļ�·��:";
		cin>>store;
		FILE *tester=fopen(store.c_str(),"r");
		if(tester==NULL)
		{
			color(4);
			cerr<<"��Ч�浵�ļ�·��!\n";
			color(7);
			throw "No file";
		}
		color(2);
		cout<<"�����ɹ�!���ڼ���...";
		color(7);
		Sleep(1000);
		run_en();
	}
} 
