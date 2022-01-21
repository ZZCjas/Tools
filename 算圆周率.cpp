#include <cstdio>
#include <iostream> 
using namespace std;
int a=10000,b,c=70000,d,e,f[70001],g,n=-1,len;
char str[100005]="141";
int main() {
	scanf("%d",&len);
    for(;b-c;) f[b++]=a/5;
    for(;d=0,(g=c*2)&&n<=len;c-=14,~n&&sprintf(str+n, "%.4d",e+d/a),n+=4,e=d%a)
        for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b);
	printf("3.");
	for(register int i=0;i<len;i++) {
		if (!(i%10)) printf("");
		if (!(i%50)) printf("");
		printf("%c", str[i]);
	}
	system("pause"); 
    return 0;
}
