#include <iostream>
#include "MD5.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace md5;
MD5 check;
stringstream ss;
string s,sss;
int main(int argc,char *argv[])
{
	if(argc>=2)
	{
		ifstream fin(argv[1]);
		if(!fin)
		{
			throw "No file";
		}
		ss<<fin.rdbuf();
		cout<<"Encoding...\n";
		s=check.encode(ss.str());
		cout<<argv[1]<<"\'s MD5 value:"<<s<<endl;
	}
	else
	{
		cout<<"Please input the path of the file:";
		cin>>s;
		ifstream fin(s);
		if(!fin)
		{
			throw "No file";
		}
		ss<<fin.rdbuf();
		cout<<"Encoding...\n";
		sss=check.encode(ss.str());
		fflush(stdout);
		fflush(stdin);
		cin.sync();
		cout.clear();
		cin.clear();
		cout<<s<<"\'s MD5 value:"<<sss<<endl;
		cout<<"Press Enter key to continue...";
		cin.get(); 
	}
}
