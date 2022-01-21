#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
	cout<<"输入名单:\n";
	string s; 
	cin>>s;
	cout<<"按任意键开始!\n";
	getch();
	system("cls");
	int cnt=rand()%s.size()+1;
	for(int i=0;i<=cnt;i++)
	{
		if(s[i]!=' '||s[i]!='\n')
		{
			cout<<s[i];		
		}
		else
		{
			Sleep(300);
			system("cls");
		}
	}
	cout<<"被点到!"<<endl; 
	system("pause");
}
