#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <windows.h>
#include <typeinfo>
using namespace std;
double times;
int n;
int main()
{
    cout<<"请输入连点时间间隔:";
    cin>>times;
    while(1)
    {
        if(typeid(times)!=typeid(double))
        {
            cout<<"请重新输入连点时间间隔:";
            cin>>times;
        }
        else
		{
			break;
		}
    }
    cout<<"模式选择:\n";
    cout<<"1.按下空格键后自动连点,ESC键退出\n2.按下空格键时连点,ESC键退出\n";
    cout<<"请选择:";
    cin>>n;
    if(n==1)
    {
    	bool f=0;
    	while(!f)
    	{
     	    if(GetAsyncKeyState(VK_SPACE))
        	{
        		while(1)
        		{
         			mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            		Sleep(times);
            		if(GetAsyncKeyState(VK_ESCAPE))
					{
						f=1;
						break;
					}
				}
       		}
    	}
	}
	else
	{
		while(1)
    	{
     	    if(GetAsyncKeyState(VK_SPACE))
        	{
         		mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            	Sleep(times);
            	if(GetAsyncKeyState(VK_ESCAPE))
				{
					break;
				}
       		}
    	}
	}
    return 0;
}
