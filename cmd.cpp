#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
string s;
int main()
{
	cout<<"Executable Command\nV1.0\tCopyright 2022 Zhao Zichen\n\n";
	while(1)
	{
		cout<<">>>";
		getline(cin,s);
		if(s=="exit")
		{
			return 0;	
		} 
		//system("@echo off");
		if(system(s.c_str())==0)
		{
			cout<<"\nָ��ִ�гɹ�!\n\n";
		}
		else
		{
			cout<<"\nָ��ִ��ʧ��!\n\n";
		}
	}
}
