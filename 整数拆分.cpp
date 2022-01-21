#include<iostream>
using namespace std;
int n, p[11]={1}, cnt=1, m;
int ct=0; 
void print(int aa){
	for(int i=1; i<aa; i++)
		cout<<p[i]<<"+";
	cout<<p[aa]<<endl;
}
void dfs(int a){
	for(int i=p[a-1]; i<=m; i++){
		if(i==n) continue;
		p[a]=i;
		m-=i;
		if(m==0)
		{
			print(a);ct++;	
		}  
		else dfs(a+1); 
		m+=i;
	}
}
int main(){
	cin>>n;
	m=n;
	dfs(1);
	cout<<(char)7;
	cout<<ct<<"ÖÖ\n";
	system("pause"); 
	return 0;
}
