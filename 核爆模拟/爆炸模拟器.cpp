#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#define speed 320
#define PI 3.14
#define ms 3
#define rkmd 1
using namespace std;
int main()
{
	int t;
	cout<<"�������Ľ��?\n";
	cin>>t;
	system("cls");
	cout.precision(4);
	getch();
	for(int i=10;i>=0;i--)
	{
		cout<<i;
		Sleep(1000);
		system("cls"); 
	}
	cout<<"\a����!\n";
	Sleep(800); 
	long int range=1;
	long int c=1;
	long int tem=30000000;
	while(c<=t*2)
	{
		system("cls");
		cout.precision(4);
		cout<<"�����Ӱ�췶Χ:"<<(long double)range/1000<<"ǧ��"<<endl;
		cout<<"�������̳��������:"<<(long double)((PI*((range/2)*(range/2))/30)/1000000)<<"ƽ��ǧ��\n";
		cout<<"Ģ���Ƹ߶�:"<<ms*c*2<<"��\n"; 
		cout<<"��������:"<<(unsigned long int)((PI*((range/2)*(range/2))/30)*rkmd)/6<<"��"<<endl;
		cout<<"�����¶�:"<<tem<<"��\n";
		cout<<"��"<<(long double)c/2<<"��\n";
		Sleep(500);
		range=range+speed;
		c++;
		if(tem!=30)
		{
			tem-=500;		
		}
	}
	cout<<"\n";
	system("pause");
} 
