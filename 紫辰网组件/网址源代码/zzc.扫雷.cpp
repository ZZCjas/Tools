#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long int c,dev,m,k,cnt,d,e,jie=10,z,abc,n,b[1000][1000],a[1000][1000],cc,cd,ce,def; //c������У�k������� 
bool flag=0; 
bool check_lei(){ //������Ϸֹͣ 
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  if(b[i][j]==999||b[i][j]==5000) def++;
 }
 }
 return (def==abc)?false:true;
}
void check(int d,int e){//���������� 
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
 system("cls"); //���� 
 srand(time(NULL)); //ʱ������ 
 for(int i=0;i<jie;i++){
 c=rand()%n;
 k=rand()%m;
 Sleep(1); //�����ܷ�ֹ������ظ� 
 if(a[c][k]!=10000){
  a[c][k]=10000;
 }
 else jie++;
 } //����������� 
 if(a[0][0]!=10000){ //��ʼ�ĸ��ǵ���ֵ���� ,���� 
 if(a[0][1]==10000) cnt++;
 if(a[1][1]==10000) cnt++;
 if(a[1][0]==10000) cnt++;
 a[0][0]=cnt;
 }
 cnt=0;
 if(a[n-1][m-1]!=10000){ //���� 
 if(a[n-1][m-2]==10000) cnt++;
 if(a[n-2][m-2]==10000) cnt++;
 if(a[n-2][m-1]==10000) cnt++;
 a[n-1][m-1]=cnt;
 }
 cnt=0;
 if(a[0][m-1]!=10000){ //���� 
 if(a[1][m-1]==10000) cnt++;
 if(a[1][m-2]==10000) cnt++;
 if(a[0][m-2]==10000) cnt++;
 a[0][m-1]=cnt;
 }
 cnt=0;
 if(a[n-1][0]!=10000){ //���� 
 if(a[n-2][1]==10000) cnt++;
 if(a[n-1][1]==10000) cnt++;
 if(a[n-2][0]==10000) cnt++;
 a[n-1][0]=cnt;
 }
 cnt=0; //������ĸ��ǵĸ�ֵȫ������ 
 for(int i=1;i<n;i++){ //��ʼ�����ߵķ��䣬�ϱ� 
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
 for(int i=1;i<m;i++){ //��� 
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
 for(int i=1;i<m;i++){ //�ұ� 
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
 for(int i=1;i<n;i++){ //�±� 
 if(a[m-1][i]!=10000){
  if(a[m-2][i]==10000) cnt++;
  if(a[m-2][i+1]==10000) cnt++;
  if(a[m-2][i-1]==10000) cnt++;
  if(a[m-1][i+1]==10000) cnt++;
  if(a[m-1][i-1]==10000) cnt++;
  a[m-1][i]=cnt;
 }
 cnt=0;
 } //���������ߵķ��� 
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
 } //��������������� 
} 
void qianYan(){
 cout<<"��ӭʹ��ɨ����Ϸ,��Ϸ�������£�\n";
 cout<<"1.����Ϸ������ѡ�����������Զ���\n";
 cout<<"2.����Ϸ�е�-����û��ɨ���ĵط���0-9�����ִ�������ɨ���е����֣�0���⣬��ʾɨ���е�ʲô����Ҳû�е�һ��,*�����Ѿ���ǵ���,�ڱ�ǵĵط���ɨ����ʱ���Զ�ȡ�����\n";
 cout<<"3.�������к��д���������Ϸ�еĵ�ѡ\n"; 
 system("pause");
 system("cls");
 cout<<"�����볤(>2):";
 cin>>n;
 while(n>1000||n<=2){
 cout<<"�����Ϸ�������������";
 cin>>n;
 }
 cout<<"�������(>2):";
 cin>>m;
 while(m>1000||m<=2){
 cout<<"���Ϸ�������������";
 cin>>m;
 }
 cout<<"�������������Ƽ��������㣺���*��/10�������룬�������Դﵽ�ȽϺõ�Ч����";
 cin>>abc;
 while(abc>n*m||abc<=0){
 cout<<"���벻�Ϸ�������������";
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
 cout<<"�������к��У�";
 cin>>d>>e;
 while(d>n||e>m||d<0||e<0){
  cout<<"���벻�Ϸ�������������";
  cin>>d>>e;
 }
 if(a[d-1][e-1]!=10000) check(d-1,e-1);//b[d-1][e-1]=a[d-1][e-1]; 
 else {
  cout<<"ʧ��";
  flag=1; 
  return;
 }
 cout<<"�Ƿ���Ҫ�����(������1����������2����"; 
 cin>>z; 
 while(z==1){
  cout<<"�������к��У�";
  cin>>d>>e;
  while(d>n||e>m||d<0||e<0){
  cout<<"���벻�Ϸ�������������";
  cin>>d>>e;
  }
  if(b[d-1][e-1]==999){
  b[d-1][e-1]=5000;
  }
  else cout<<"��Ǵ��󣺱�����Ѿ�ɨ���Ĳ����׵ĸ���\n";
  cout<<"�Ƿ���Ҫ�����(������1����������2����";
  cin>>z;
 }
 system("pause");
 system("cls");
 cout<<"������";
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
 cout<<"2.2.0�汾�������ܣ�\n";
 cout<<"��ʾ����������������������\n";
 cout<<"�޸���2.1.0��ϷӮ���˵�����\n";
 system("pause"); 
 system("cls");
 qianYan();
 saoLei();
 if(flag==0) cout<<"̫����\n";
 else cout<<"���ź�\n";
 system("pause");
 cout<<"��ͼ����:\n";
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
  if (b[i][j]==5000&&a[i][j]!=10000) cout<<"��"<<i+1<<"�е�"<<j+1<<"�б�Ǵ���\n"; 
 } 
 } 
 system("pause");
 return 0;
}
