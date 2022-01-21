#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long int c,dev,m,k,cnt,d,e,jie=10,z,abc,n,b[1000][1000],a[1000][1000],cc,cd,ce,def; //c是随机行，k是随机列 
bool flag=0; 
bool check_lei(){ //用于游戏停止 
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  if(b[i][j]==999||b[i][j]==5000) def++;
 }
 }
 return (def==abc)?false:true;
}
void check(int d,int e){//附近的雷数 
 if(d<0||d>=n||e<0||e>=m){
 ce++;
 return;
 } 
 if(a[d][e]==10000){
 ce++;
 return;
 }
 if(b[d][e]!=999&&b[d][e]!=5000) return;
 b[d][e]=a[d][e];
 if(b[d][e]!=0){
 for(int i=-1;i<=1;i++){
  for(int j=-1;j<=1;j++){
  if(d+i<0||d+i>=n||e+i<0||e+i>=m){
   ce++;
   continue;
  }
  if(b[d+i][e+i]==5000) continue;
  if(b[d+i][e+j]!=999) continue;
  if(a[d+i][e+j]==10000){
   ce++;
   continue;
  }
  if(ce<=5){
   b[d+i][e+j]=a[d+i][e+j];
   ce++; 
  }
  } 
 }
 return ; 
 }
 if(cd>n/2) return;
 for(int i=-1;i<=1;i++){
 for(int j=-1;j<=1;j++){
  check(d+i,e+j);
 }
 }
 cd++;
}
void buZhi(){
 system("cls"); //清屏 
 srand(time(NULL)); //时间种子 
 for(int i=0;i<jie;i++){
 c=rand()%n;
 k=rand()%m;
 Sleep(1); //最大可能防止随机数重复 
 if(a[c][k]!=10000){
  a[c][k]=10000;
 }
 else jie++;
 } //将雷随机分配 
 if(a[0][0]!=10000){ //开始四个角的数值分配 ,左上 
 if(a[0][1]==10000) cnt++;
 if(a[1][1]==10000) cnt++;
 if(a[1][0]==10000) cnt++;
 a[0][0]=cnt;
 }
 cnt=0;
 if(a[n-1][m-1]!=10000){ //右下 
 if(a[n-1][m-2]==10000) cnt++;
 if(a[n-2][m-2]==10000) cnt++;
 if(a[n-2][m-1]==10000) cnt++;
 a[n-1][m-1]=cnt;
 }
 cnt=0;
 if(a[0][m-1]!=10000){ //右上 
 if(a[1][m-1]==10000) cnt++;
 if(a[1][m-2]==10000) cnt++;
 if(a[0][m-2]==10000) cnt++;
 a[0][m-1]=cnt;
 }
 cnt=0;
 if(a[n-1][0]!=10000){ //左下 
 if(a[n-2][1]==10000) cnt++;
 if(a[n-1][1]==10000) cnt++;
 if(a[n-2][0]==10000) cnt++;
 a[n-1][0]=cnt;
 }
 cnt=0; //到这边四个角的赋值全部结束 
 for(int i=1;i<n;i++){ //开始四条边的分配，上边 
 if(a[0][i]!=10000){
  if(a[1][i]==10000) cnt++;
  if(a[1][i+1]==10000) cnt++;
  if(a[1][i-1]==10000) cnt++;
  if(a[0][i+1]==10000) cnt++;
  if(a[0][i-1]==10000) cnt++;
  a[0][i]=cnt;
 }
 cnt=0;
 }
 for(int i=1;i<m;i++){ //左边 
 if(a[i][0]!=10000){
  if(a[i][1]==10000) cnt++;
  if(a[i+1][1]==10000) cnt++;
  if(a[i-1][1]==10000) cnt++;
  if(a[i+1][0]==10000) cnt++;
  if(a[i-1][0]==10000) cnt++;
  a[i][0]=cnt;
 }
 cnt=0;
 }
 for(int i=1;i<m;i++){ //右边 
 if(a[i][n-1]!=10000){
  if(a[i-1][n-1]==10000) cnt++;
  if(a[i+1][n-1]==10000) cnt++;
  if(a[i][n-2]==10000) cnt++;
  if(a[i-1][n-2]==10000) cnt++;
  if(a[i+1][n-2]==10000) cnt++;
  a[i][n-1]=cnt;
 }
 cnt=0;
 }
 for(int i=1;i<n;i++){ //下边 
 if(a[m-1][i]!=10000){
  if(a[m-2][i]==10000) cnt++;
  if(a[m-2][i+1]==10000) cnt++;
  if(a[m-2][i-1]==10000) cnt++;
  if(a[m-1][i+1]==10000) cnt++;
  if(a[m-1][i-1]==10000) cnt++;
  a[m-1][i]=cnt;
 }
 cnt=0;
 } //结束四条边的分配 
 for(int i=1;i<n-1;i++){
 for(int j=1;j<m-1;j++){
  if(a[i][j]!=10000){
  if(a[i-1][j]==10000) cnt++;
  if(a[i-1][j-1]==10000) cnt++;
  if(a[i-1][j+1]==10000) cnt++;
  if(a[i][j-1]==10000) cnt++;
  if(a[i][j+1]==10000) cnt++;
  if(a[i+1][j]==10000) cnt++;
  if(a[i+1][j-1]==10000) cnt++;
  if(a[i+1][j+1]==10000) cnt++;
  a[i][j]=cnt;
  }
  cnt=0;
 }
 } //基本数量分配结束 
} 
void qianYan(){
 cout<<"欢迎使用扫雷游戏,游戏规则如下：\n";
 cout<<"1.本游戏规格可以选择，雷数可以自定义\n";
 cout<<"2.本游戏中的-代表还没有扫到的地方，0-9的数字代表正常扫雷中的数字（0特殊，表示扫雷中的什么东西也没有的一格）,*代表已经标记的雷,在标记的地方被扫到的时候自动取消标记\n";
 cout<<"3.请输入行和列代表正常游戏中的点选\n"; 
 system("pause");
 system("cls");
 cout<<"请输入长(>2):";
 cin>>n;
 while(n>1000||n<=2){
 cout<<"长不合法，请重新输入";
 cin>>n;
 }
 cout<<"请输入宽(>2):";
 cin>>m;
 while(m>1000||m<=2){
 cout<<"宽不合法，请重新输入";
 cin>>m;
 }
 cout<<"请输入雷数（推荐雷数计算：规格长*宽/10四舍五入，这样可以达到比较好的效果）";
 cin>>abc;
 while(abc>n*m||abc<=0){
 cout<<"输入不合法，请重新输入";
 cin>>abc;
 }
 jie=abc; 
 buZhi();
}
void saoLei(){
 for(int i=0;i<n;i++)
 for(int j=0;j<m;j++)
  b[i][j]=999;
 while(check_lei()){
 def=0;
 dev=1;
 ce=0;
 cd=0;
 cout<<"  ";
 for(int i=0;i<m;i++)
  cout<<i+1<<' ';
 cout<<'\n';
 for(int i=0;i<n;i++){
  if(dev>9)
  cout<<dev<<' ';
  else
  cout<<dev<<" ";
  for(int j=0;j<m;j++){
  if(b[i][j]!=999&&b[i][j]!=5000)
   cout<<b[i][j]<<' ';
  else if(b[i][j]==999)
   cout<<"- ";
  else
   cout<<"* ";
  }
  cout<<'\n';
  dev++;
 }
 def=0;
 if(!check_lei()) break;
 cout<<"请输入行和列：";
 cin>>d>>e;
 while(d>n||e>m||d<0||e<0){
  cout<<"输入不合法，请重新输入";
  cin>>d>>e;
 }
 if(a[d-1][e-1]!=10000) check(d-1,e-1);//b[d-1][e-1]=a[d-1][e-1]; 
 else {
  cout<<"失败";
  flag=1; 
  return;
 }
 cout<<"是否需要标记雷(是输入1，不是输入2）？"; 
 cin>>z; 
 while(z==1){
  cout<<"请输入行和列：";
  cin>>d>>e;
  while(d>n||e>m||d<0||e<0){
  cout<<"输入不合法，请重新输入";
  cin>>d>>e;
  }
  if(b[d-1][e-1]==999){
  b[d-1][e-1]=5000;
  }
  else cout<<"标记错误：标记了已经扫到的不是雷的格子\n";
  cout<<"是否需要标记雷(是输入1，不是输入2）？";
  cin>>z;
 }
 system("pause");
 system("cls");
 cout<<"加载中";
 Sleep(300);
 cout<<".";
 Sleep(300);
 cout<<".";
 Sleep(300);
 cout<<"."; 
 system("cls"); 
 def=0;
 }
}
int main(){
 cout<<"2.2.0版本新增功能：\n";
 cout<<"显示行数和列数，找起来方便\n";
 cout<<"修复了2.1.0游戏赢不了的问题\n";
 system("pause"); 
 system("cls");
 qianYan();
 saoLei();
 if(flag==0) cout<<"太棒了\n";
 else cout<<"很遗憾\n";
 system("pause");
 cout<<"雷图如下:\n";
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  if(a[i][j]==10000)
  cout<<"*"<<' ';
  else cout<<a[i][j]<<' ';
 }
 cout<<'\n';
 }
 cout<<'\n';
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  if (b[i][j]==5000&&a[i][j]!=10000) cout<<"第"<<i+1<<"行第"<<j+1<<"列标记错误\n"; 
 } 
 } 
 system("pause");
 return 0;
}
