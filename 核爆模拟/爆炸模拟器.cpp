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
	cout<<"看几秒后的结果?\n";
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
	cout<<"\a引爆!\n";
	Sleep(800); 
	long int range=1;
	long int c=1;
	long int tem=30000000;
	while(c<=t*2)
	{
		system("cls");
		cout.precision(4);
		cout<<"冲击波影响范围:"<<(long double)range/1000<<"千米"<<endl;
		cout<<"放射性烟尘覆盖面积:"<<(long double)((PI*((range/2)*(range/2))/30)/1000000)<<"平方千米\n";
		cout<<"蘑菇云高度:"<<ms*c*2<<"米\n"; 
		cout<<"死亡人数:"<<(unsigned long int)((PI*((range/2)*(range/2))/30)*rkmd)/6<<"人"<<endl;
		cout<<"爆心温度:"<<tem<<"℃\n";
		cout<<"第"<<(long double)c/2<<"秒\n";
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
