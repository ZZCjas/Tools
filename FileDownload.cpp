#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime> 
#include <windows.h>
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")
using namespace std;
BOOL FileExistsStatus(const CHAR* path)
{
	DWORD dwAttribute=GetFileAttributes((LPCSTR)path);
	if(dwAttribute==0XFFFFFFFF) 
	{
		return false; 
	}
	else 
	{
		return true;
	}
}
BOOL DownloadFiles(const CHAR* url,const CHAR* downloadPath)
{
	if(URLDownloadToFile(NULL, (LPCSTR)url, (LPCSTR)downloadPath, 0, 0) == S_OK && FileExistsStatus(downloadPath)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
clock_t start,eend;
int main(int argc,char* argv[])
{
	if(argv[1]==""||argv[2]=="")
	{
		cout<<"Error!\n";
		return -1;
	}
	start=clock();
	cout<<"Downloading. . .\n";
	if(DownloadFiles(argv[1],argv[2]))
	{
		eend=clock();
		cout<<"Succeed!\nUse ";
		cout.precision(3);
		cout<<fixed<<(double)(eend-start)/CLOCKS_PER_SEC<<"s to download\n";
	}
	else
	{
		cout<<"Fail!\n";
	}
}
