#include<stdio.h>
#include<Windows.h>
#include<iostream> 
#include<ctime>
using namespace std;
void FindFile(char* ,char* );
int count=0;
char fname[32];
long long t1;
#define BUFSIZE 256
int main(int argc,char* argv[])
{
char szLogicalDriveStrings[BUFSIZE];
DWORD iLength;
int iSub;
printf("����Ҫ�������ļ���(���Ϻ�׺):\n");
scanf("%s",fname);
t1=time(0);
system("cls");
printf("�Ѳ��ҵ����ļ�·��:\n");
ZeroMemory(szLogicalDriveStrings, BUFSIZE);
iLength = GetLogicalDriveStringsA(BUFSIZE-1, szLogicalDriveStrings);
for(iSub=0; iSub<iLength; iSub+=4) 
{
if(GetDriveType(szLogicalDriveStrings+iSub)!=3)
continue;
FindFile(szLogicalDriveStrings+iSub,"*.*");
}
printf("һ������%d���ļ�...\n",count);
cout<<"��������"<<time(0)-t1<<"��"<<endl;
system("pause");
return 0;
}
void FindFile(char* pfilename,char* pfilter)
{
WIN32_FIND_DATA findfiledate; 
HANDLE hfind;
char filename[512];
char lpFileName[512];
char _lpFileName[512];
int i;
int result;
for(i=0;*(pfilename+i)!='\0';i++)
filename[i]=*(pfilename+i);
filename[i]='\0';
if(filename[strlen(filename)-1]!='\\') 
strcat(filename,"\\"); 
strcpy(lpFileName,filename);
strcat(lpFileName,pfilter);
hfind=FindFirstFile(lpFileName,&findfiledate);
if(hfind==INVALID_HANDLE_VALUE) 
return;
do
{
if(!(findfiledate.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
{
if(0==strcmp(fname,findfiledate.cFileName))
{ 
printf("%s%s\n",filename,findfiledate.cFileName);
count++;
}
}
else
{
if(findfiledate.cFileName[0]!='.')
{
strcpy(_lpFileName,filename);
strcat(_lpFileName,findfiledate.cFileName);
FindFile(_lpFileName,pfilter);
}
}
}
while(FindNextFile(hfind,&findfiledate));
{
	FindClose(hfind);
}
return;
}
