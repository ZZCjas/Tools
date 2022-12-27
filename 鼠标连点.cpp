#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <windows.h>
#include <typeinfo>
using namespace std;
int times;
int n,x;
int key=VK_SPACE; 
DWORD mouse; 
int main()
{
    cout<<"请输入连点时间间隔(毫秒):";
    cin>>times;
    while(1)
    {
        if(typeid(times)!=typeid(int))
        {
            cout<<"请重新输入连点时间间隔(毫秒):";
            cin>>times;
        }
        else
		{
			break;
		}
    }
    cout<<"模式选择:\n";
    cout<<"1.按下开始键后自动连点,ESC键退出\n2.按下开始键时连点,ESC键退出\n";
    cout<<"请选择:";
    cin>>n;
    cout<<"选择开始键:\n";
    cout<<"1.空格键\n2.回车键\n请选择:";
    cin>>x;
    if(x==2)
    {
    	key=VK_RETURN;
	}
	cout<<"选择连点鼠标左键还是鼠标右键:\n";
	cout<<"1.鼠标左键\n2.鼠标右键\n请选择:";
	cin>>x;
	if(x==1)
	{
		mouse=(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP);
	}
	else                    
	{ 
		mouse=(MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP);
	}
    if(n==1)
    {
    	bool f=0;
    	while(!f)
    	{
     	    if(GetAsyncKeyState(key))
        	{
        		while(1)
        		{
         			mouse_event(mouse,0,0,0,0);
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
    		if(GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
     	    if(GetAsyncKeyState(key))
        	{
         		mouse_event(mouse,0,0,0,0);
            	Sleep(times);
       		}
    	}
	}
    return 0;
}
