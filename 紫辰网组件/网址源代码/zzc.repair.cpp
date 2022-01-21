#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;
int main()
{
	cout<<"这是紫辰网维护网站.\n有什么问题?\n";
	string s;
	cin>>s;
	freopen("反馈.txt","a",stdout);
	cout<<"输入>>"<<s<<'\n';
	freopen("CON","w",stdout);
	cout<<"谢谢您的反馈!\n";
	system("pause");
    return 0;
}
