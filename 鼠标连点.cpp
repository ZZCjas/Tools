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
    cout<<"����������ʱ����(����):";
    cin>>times;
    while(1)
    {
        if(typeid(times)!=typeid(int))
        {
            cout<<"��������������ʱ����(����):";
            cin>>times;
        }
        else
		{
			break;
		}
    }
    cout<<"ģʽѡ��:\n";
    cout<<"1.���¿�ʼ�����Զ�����,ESC���˳�\n2.���¿�ʼ��ʱ����,ESC���˳�\n";
    cout<<"��ѡ��:";
    cin>>n;
    cout<<"ѡ��ʼ��:\n";
    cout<<"1.�ո��\n2.�س���\n��ѡ��:";
    cin>>x;
    if(x==2)
    {
    	key=VK_RETURN;
	}
	cout<<"ѡ��������������������Ҽ�:\n";
	cout<<"1.������\n2.����Ҽ�\n��ѡ��:";
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
