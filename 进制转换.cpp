#include<bits/stdc++.h>
using namespace std;
string l;
int c[10000000],d,e,f,g,sum,ans;
int main()
{
	cout<<"输入的是什么进制？\n" ;
    scanf("%d",&d);
    cout<<"输入什么？\n";
    cin>>l;
    cout<<"转换成什么进制？\n";
    scanf("%d",&f);
    system("cls");
    for(int x=0;x<l.size();x++){
        if(l[x]<'A'){
            e=pow(d,l.size()-x-1);
            e*=(l[x]-'0');
            sum+=e;
        }
        else{
            e=pow(d,l.size()-1-x);
            e*=(l[x]-'A'+10);
            sum+=e;
        }
    }
        while(sum>0){
        c[g++]=sum%f;
        sum/=f;
    }
    for(int x=g-1;x>=0;x--){
        if(c[x]>=10)
		{
			printf("%c",c[x]+'A'-10);
		}
        else
		{
			printf("%d",c[x]);
		} 
    }
    cout<<"\n结果如上\n";
    system("pause"); 
    return 0;
}
