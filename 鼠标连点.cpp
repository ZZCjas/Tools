#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <windows.h>
#include <typeinfo>
using namespace std;
double times;
int n;
int main()
{
    cout<<"����������ʱ����:";
    cin>>times;
    while(1)
    {
        if(typeid(times)!=typeid(double))
        {
            cout<<"��������������ʱ����:";
            cin>>times;
        }
        else
		{
			break;
		}
    }
    cout<<"ģʽѡ��:\n";
    cout<<"1.���¿ո�����Զ�����,ESC���˳�\n2.���¿ո��ʱ����,ESC���˳�\n";
    cout<<"��ѡ��:";
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
