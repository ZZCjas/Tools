#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
	cout<<"��������:\n";
	string s; 
	cin>>s;
	cout<<"���������ʼ!\n";
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
	cout<<"���㵽!"<<endl; 
	system("pause");
}
