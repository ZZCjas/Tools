#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <windows.h>
 
using namespace std;
void Game_Menu(HANDLE hout);
void Game_description(HANDLE hout);
void gotoxy(HANDLE hout, int x, int y);
int DrawMap(HANDLE hout);
void Move(HANDLE hout);
int finish();
void setmap(int n);
void color(int m);
bool flag = true;
int pass = 1;
#define R 10
#define C 10
#define framex 20
#define framey 14 
int map[R][C] = {0};
//�ؿ�1 
int map1[R][C] = {
{ 0,0,1,1,1,0,0,0 },
{ 0,0,1,3,1,0,0,0 },
{ 0,0,1,0,1,1,1,1 },
{ 1,1,1,0,0,4,3,1 },
{ 1,3,4,4,0,1,1,1 },
{ 1,1,1,5,4,1,0,0 },
{ 0,0,0,1,3,1,0,0 },
{ 0,0,0,1,1,1,0,0 }
};
//��ͼ 2���ؿ�2��
int map2[R][C]={
{1,1,1,1,1,0,0,0,0,0},
{1,5,0,0,1,0,0,0,0,0},
{1,0,4,4,1,0,1,1,1,0},
{1,0,4,0,1,0,1,3,1,0},
{1,1,1,0,1,1,1,3,1,0},
{0,1,1,0,0,0,0,3,1,0},
{0,1,0,0,0,1,0,0,1,0},
{0,1,0,0,0,1,1,1,1,0},
{0,1,1,1,1,1,0,0,0,0}
};
//��ͼ 3���ؿ�3��
int map3[R][C]={
{ 0,0,0,1,1,1,1,1,1,1 },
{ 0,0,1,1,0,0,1,0,5,1 },
{ 0,0,1,0,0,0,1,0,0,1 },
{ 0,0,1,4,0,4,0,4,0,1 },
{ 0,0,1,0,4,1,1,0,0,1 },
{ 1,1,1,0,4,0,1,0,1,1 },
{ 1,3,3,3,3,3,0,0,1,0 },
{ 1,1,1,1,1,1,1,1,1,0 },
};
void Game_Menu(HANDLE hout){//��Ϸ��ʼ�˵� 
 system("cls");
 gotoxy(hout, framex, 1);
 cout << "*******************";
 gotoxy(hout, framex, 3);
 cout << "   ������    ";
 gotoxy(hout, framex, 5);
 cout << "  ��s��S��ʼ   ";
 gotoxy(hout, framex, 7);
 cout << "  ��q��Q�˳�   ";
 gotoxy(hout, framex, 9);
 cout << "��Ϸǰ�ر��������� ";
 gotoxy(hout, framex, 11);
 cout << "*******************";
 _getch();
};
void Game_description(HANDLE hout){//������ʾ 
 system("cls");
 gotoxy(hout, framex, 1);
 cout << "*****************************";
 gotoxy(hout, framex, 3);
 cout << "   ����������������ƶ�  ";
 gotoxy(hout, framex, 5);
 cout << " �������ӵ���Ŀ�ĵ���Ϸʤ�� ";
 gotoxy(hout, framex, 7);
 cout << "     ��q��Q�˳�     ";
 gotoxy(hout, framex, 9);
 cout << "*****************************";
};
void gotoxy(HANDLE hout, int x, int y){
 COORD pos;
 pos.X = x;
 pos.Y = y;
 SetConsoleCursorPosition(hout, pos);
};
void print(int i){//����mapֵ�����Ӧ��ͼ�� 
 switch(i){
 case 0:
 color(0x7);
 cout << " "; //�յء����?���??��
 break;
 case 1:
 color(8);
 cout << "��";//ǽ��
 break;
 case 3:
 color(0xE);
 cout << "��";//Ŀ�ĵ�
 break;
 case 4:
 color(4);
 cout << "��";//���� 
 break;
 case 5:
 color(3);
 cout << "��"; //��
 break;
 case 7:   //4+3  ���ӵ���Ŀ�ĵ�
 color(6);  
 cout << "��";
 break;
 case 8:   //5+3 ����Ŀ�ĵ��غ�
 color(3);
 cout << "��";
 break;
 default:
 break;
 }
}
int DrawMap(HANDLE hout){//�µĹؿ���ʼʱ�����ͼ 
 //HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
 gotoxy(hout, framex + C, framey - 3);
 color(0xF);
 cout << "��" << pass << "��";
 //printf("��%d��", pass); 
 for(int i = 0; i < R; i++){
 gotoxy(hout, framex, framey + i);
 for(int j = 0; j < C; j++){
  
 print(map[i][j]);
 }
 }
 return 0;
};
void Move(HANDLE hout){//�ƶ�С�� 
 int x = 0, y = 0;
 for(int i = 0; i < R; i++){
 for(int j = 0; j < C; j++){
 if(map[i][j] == 5 || map [i] [j] == 8){
 x = i;
 y = j;
 break;
 }
 }
 }
 gotoxy(hout, framex, framey + R);
 color(0xF);
 printf("��ǰλ��:(%d, %d)", x, y);
 int ch = _getch();
  
 switch(ch){
  
 case 'w':
 case 'W':
 case 72:
 if(map[x - 1][y] == 0 || map[x - 1][y] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x - 1][y] += 5;
 gotoxy(hout, framex + 2 * y, framey + x - 1);
 print(map[x - 1][y]);
 }
 else if(map[x - 1][y] == 4 || map[x - 1][y] == 7){
 if(map[x - 2][y] == 0 || map[x - 2][y] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x - 1][y] += 1;
 gotoxy(hout, framex + 2 * y, framey + x - 1);
 print(map[x - 1][y]);
 map[x - 2][y] += 4;
 gotoxy(hout, framex + 2 * y, framey + x - 2);
 print(map[x - 2][y]);
 }
 }
 break;
  
 case 's':
 case 'S':
 case 80:
 if(map[x + 1][y] == 0 || map[x + 1][y] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x + 1][y] += 5;
 gotoxy(hout, framex + 2 * y, framey + x + 1);
 print(map[x + 1][y]);
 }
 else if(map[x + 1][y] == 4 || map[x + 1][y] == 7){
 if(map[x + 2][y] == 0 || map[x + 2][y] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x + 1][y] += 1;
 gotoxy(hout, framex + 2 * y, framey + x + 1);
 print(map[x + 1][y]);
 map[x + 2][y] += 4;
 gotoxy(hout, framex + 2 * y, framey + x + 2);
 print(map[x + 2][y]);
 }
 }
 break;
  
 case 'a':
 case 'A':
 case 75:
 if(map[x][y - 1] == 0 || map[x][y - 1] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x][y - 1] += 5;
 gotoxy(hout, framex + 2 * y - 2, framey + x);
 print(map[x][y - 1]);
 }
 else if(map[x][y - 1] == 4 || map[x][y - 1] == 7){
 if(map[x][y - 2] == 0 || map[x][y - 2] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x][y - 1] += 1;
 gotoxy(hout, framex + 2 * y - 2, framey + x);
 print(map[x][y - 1]);
 map[x][y - 2] += 4;
 gotoxy(hout, framex + 2 * y - 4, framey + x);
 print(map[x][y - 2]);
 }
 }
 break;
  
 case 'd':
 case 'D':
 case 77:
 if(map[x][y + 1] == 0 || map[x][y + 1] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x][y + 1] += 5;
 gotoxy(hout, framex + 2 * y + 2, framey + x);
 print(map[x][y + 1]);
 }
 else if(map[x][y + 1] == 4 || map[x][y + 1] == 7){
 if(map[x][y + 2] == 0 || map[x][y + 2] == 3){
 map[x][y] -= 5;
 gotoxy(hout, framex + 2 * y, framey + x);
 print(map[x][y]);
 map[x][y + 1] += 1;
 gotoxy(hout, framex + 2 * y + 2, framey + x);
 print(map[x][y + 1]);
 map[x][y + 2] += 4;
 gotoxy(hout, framex + 2 * y + 4, framey + x);
 print(map[x][y + 2]);
 }
 }
 break;
 case 'q':
 case 'Q':
 flag = false;
 default:
 break;  
 }
};
int finish(){//�ж���Ϸ���� 
 for(int i = 0; i < R; i++){
 for(int j = 0; j < C; j++){
 if(map[i][j] == 4)return 0;
 }
 }
 return 1;
};
void setmap(int n){
 switch(n){
 case 1:
 memcpy(map, map1, sizeof(map1));
 break;
 case 2:
 memcpy(map, map2, sizeof(map2));
 break;
 case 3:
 memcpy(map, map3, sizeof(map3));
 break;
 }
};
void color(int m){//�ı�������ŵ���ɫ 
 HANDLE consolehend;
 consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(consolehend, m); 
};
int main(){
 HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
  
 Game_Menu(hout);
 char ch = getch();
 setmap(pass);
 Game_description(hout);
 DrawMap(hout);
 if(ch == 'q' || ch == 'Q'){
 return 0;
 }
 while(flag){
 Move(hout);
 if(finish()){  
 DrawMap(hout);
 gotoxy(hout, framex, framey + R);
 cout << " ��ϲ���ɹ����أ�";
 gotoxy(hout, framex, framey + R + 2);
 cout << "����(R)";
 ch = getch();
 system("cls");
 pass++;
 if(ch == 'r' || ch == 'R')pass--;
 if(pass > 3) { 
 gotoxy(hout, framex, framey);
 cout << " ����ͨ��ȫ���ؿ���";
 getch();
 flag = false;
 } 
 else{
 setmap(pass);
 Game_description(hout);
 DrawMap(hout);
 }
 }
 }
 return 0; 
}
