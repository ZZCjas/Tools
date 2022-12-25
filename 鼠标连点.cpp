#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <windows.h>
#include <typeinfo>
using namespace std;
double times;
int main()
{
    cout<<"按空格键开始,ESC键退出"<<endl;
    cout<<"请输入连点时间间隔:";
    cin>>times;
    while(1)
    {
        if(typeid(times)!=typeid(double))
        {
            cout<<"请输入连点时间间隔:";
            cin>>times;
        }
        else
		{
			break;
		}
    }
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
    return 0;
}
