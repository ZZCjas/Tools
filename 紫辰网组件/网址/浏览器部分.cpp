#include "algorithms.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
using namespace std;
char web[100001],go[100007]="start ";
int main()
{
	while(1)
	{
		system("cls");
		cout<<"�����ĸ���ַ?\n";
		cin>>web;
		for(int i=0;i<=strlen(web);i++)
		{
			go[i+6]=web[i];
		}
		cout<<"����";
		for(int i=1;i<=6;i++)
		{
			Sleep(150);
			cout<<'.';
		}
		cout<<endl;
		system("cls"); 
		system(go);
		Sleep(1000); 
	}
	return 0;
}
