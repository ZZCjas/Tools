#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<queue>
#include<ctype.h>
#define A 17    //��ͼ�ĸ�
#define B 17    //��ͼ�Ŀ�
#define C 30    //�׵�����
using namespace std;
 
//ȫ�ֱ���
DWORD a,b;
char map[A][B],news,spare;
int BoomTotalNum,floatx,floaty,flag[A][B],flagnum,mode,slect[A][B],game;
 
//��ɫ����
const WORD FORE_BLUE  =  FOREGROUND_BLUE;    //��ɫ�ı�����
const WORD FORE_GREEN = FOREGROUND_GREEN;    //��ɫ�ı�����
const WORD FORE_RED   =   FOREGROUND_RED;    //��ɫ�ı�����
 
//���ѵ�ͼ�ṹ��
struct node {
    int x;
    int y;
};
queue <node> dui;
 
//��ӡλ��
void position(int x,int y) {
    COORD pos={x,y};
    HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out,pos);
}
 
//���ع��
void Hide() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO CursorInfo;  
    GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
    CursorInfo.bVisible = false; //���ؿ���̨���  
    SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬   
}
 
//��ʼ��
void Beginning() {
    while(!dui.empty()) {
        dui.pop();
    }
    game=1;
    //BoomTotalNum=C;
    floatx=A/2;
    floaty=B/2;
    flagnum=0;
    BoomTotalNum=C;
    mode=0;
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
    int x,y;
    srand((unsigned)time(0));
    for(int i=0;i<A;i++) for(int j=0;j<B;j++) { 
        map[i][j]=' ';
        flag[i][j]=0;
        slect[i][j]=0;
    }
    while(BoomTotalNum) { 
        x=rand()%A;
        y=rand()%B;
        if(map[x][y]==' ') { 
            map[x][y]='@';
            BoomTotalNum--;
        }
    }
    SetConsoleTextAttribute(handle_out, FORE_GREEN);  
    for(int i=0;i<A;i++) { 
        for(int j=0;j<B;j++) printf("��");
        printf("\n");
    }
    position(floaty*2,floatx);
    SetConsoleTextAttribute(handle_out, FORE_RED);  
    printf("��");    //���λ��
    position(5,22);
    printf("�����ո��л�ģʽ");
    position(5,23);
    printf("����Enter��ȷ��");
    position(5,24);
    printf("�����������ѡ�񷽿�");
    
}
 
//��ӡ��ͼ��һ���
void Lump(int xx,int yy) { 
    switch(map[xx][yy]) { 
        case '1' : printf("��");break;    //��Χ�׵���������ͬ��
        case '2' : printf("��");break;
        case '3' : printf("��");break;
        case '4' : printf("��");break;
        case '5' : printf("��");break;
        case '6' : printf("��");break;
        case '7' : printf("��");break;
        case '8' : printf("��");break;
        case ' ' :
            if(xx==floatx&&yy==floaty) { 
                if(flag[xx][yy]==0) { 
                    if(mode%2==0) printf("��");
                    else printf("��");
                }
                else printf("��");
            }
            else { 
                if(flag[xx][yy]==0) printf("��");
                else printf("��");
            }
            break;
        case '@' :
            if(xx==floatx&&yy==floaty) { 
                if(flag[xx][yy]==0) { 
                    if(mode%2==0) printf("��");
                    else printf("��");
                }
                else printf("��");
            }
            else { 
                if(flag[xx][yy]==0) printf("��");
                else printf("��");
            }
            break;
        case 'x' : if(floatx==xx&&floaty==yy) printf("��"); else printf("  ");break;    //�Ѿ��ڿ��Ŀհ�
    }
}
 
//�ƶ����
void Move() { 
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
    int xxx,yyy;
    xxx=floatx;
    yyy=floaty;
    switch(news) { 
        case 72 : floatx--;break;    //��
        case 80 : floatx++;break;    //��
        case 75 : floaty--;break;    //��
        case 77 : floaty++;break;    //��
    }
    if(floatx==-1) floatx=A-1; floatx%=A;    //���˴�ģ����
    if(floaty==-1) floaty=B-1; floaty%=B;
    
    position(yyy*2,xxx);
    SetConsoleTextAttribute(handle_out, FORE_GREEN);
    Lump(xxx,yyy);    //ɾ��ԭλ��
    
    if(map[floatx][floaty]=='x') { 
        position(floaty*2,floatx);
        printf("  ");
    }
    
    position(floaty*2,floatx);
    SetConsoleTextAttribute(handle_out, FORE_BLUE);  
    Lump(floatx,floaty);    //������λ��
}
 
//���������ģʽ�л�
void Mode() { 
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
    mode++;
    SetConsoleTextAttribute(handle_out, FORE_BLUE);
    position(floaty*2,floatx);
    if(mode%2==0) printf("��");
    else printf("��");
    
    position(44,9);
    if(mode%2==0) { 
        SetConsoleTextAttribute(handle_out, FORE_BLUE);  
        printf("����ģʽ");
    }
    else { 
        SetConsoleTextAttribute(handle_out, FORE_RED);  
        printf("�ھ�ģʽ");
    }
}
 
//�õ���Χ������
int Boomnum(int xx,int yy) { 
    int num=0;
    if((xx-1>=0)&&(yy-1>=0)&&(map[xx-1][yy-1]=='@')) num++;
    if((xx-1>=0)&&(yy+0>=0)&&(map[xx-1][yy]=='@')) num++;
    if((xx-1>=0)&&(yy+1<B) &&(map[xx-1][yy+1]=='@')) num++;
    if((xx+0>=0)&&(yy-1>=0)&&(map[xx][yy-1]=='@')) num++;
    if((xx+0>=0)&&(yy+1<B) &&(map[xx][yy+1]=='@')) num++;
    if((xx+1<A)&&(yy-1>=0) &&(map[xx+1][yy-1]=='@')) num++;
    if((xx+1<A)&&(yy+0>=0) &&(map[xx+1][yy]=='@')) num++;
    if((xx+1<A)&&(yy+1<B)  &&(map[xx+1][yy+1]=='@')) num++;
    return num;
}
 
//���µ�ͼ
void Open() { 
    node c;
    node d;
    while(!dui.empty()) { 
        dui.pop();
    }
    c.x=floatx;
    c.y=floaty;
    dui.push(c);
    slect[c.x][c.y]=1;
    while(!dui.empty()) { 
        c=dui.front();
        dui.pop();
        if(Boomnum(c.x,c.y)!=0) { 
            map[c.x][c.y]=(Boomnum(c.x,c.y)+48);
            continue;
        }
        else { 
            map[c.x][c.y]='x';                                                                                                                                                                                                                                                                                                                                                                                                                                     
            if((c.x-1>=0)&&(c.y-1>=0)&&(map[c.x-1][c.y-1]==' ')&&(slect[c.x-1][c.y-1]==0)) { 
                d.x=c.x-1;
                d.y=c.y-1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x-1>=0)&&(c.y-0>=0)&&(map[c.x-1][c.y]==' ')&&(slect[c.x-1][c.y]==0)) { 
                d.x=c.x-1;
                d.y=c.y-0;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x-1>=0)&&(c.y+1<B)&&(map[c.x-1][c.y+1]==' ')&&(slect[c.x-1][c.y+1]==0)) { 
                d.x=c.x-1;
                d.y=c.y+1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x-0>=0)&&(c.y-1>=0)&&(map[c.x][c.y-1]==' ')&&(slect[c.x][c.y-1]==0)) { 
                d.x=c.x-0;
                d.y=c.y-1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x-0>=0)&&(c.y+1<B)&&(map[c.x][c.y+1]==' ')&&(slect[c.x][c.y+1]==0)) { 
                d.x=c.x-0;
                d.y=c.y+1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x+1<A)&&(c.y-1>=0)&&(map[c.x+1][c.y-1]==' ')&&(slect[c.x+1][c.y-1]==0)) { 
                d.x=c.x+1;
                d.y=c.y-1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x+1<A)&&(c.y-0>=0)&&(map[c.x+1][c.y]==' ')&&(slect[c.x+1][c.y]==0)) { 
                d.x=c.x+1;
                d.y=c.y-0;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
            if((c.x+1<A)&&(c.y+1<B)&&(map[c.x+1][c.y+1]==' ')&&(slect[c.x+1][c.y+1]==0)) { 
                d.x=c.x+1;
                d.y=c.y+1;
                dui.push(d);
                slect[d.x][d.y]=1;
            }
        }
    }
}
 
int main() { 
    freopen("����.txt","r",stdin);
    Relife:    //���洦
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
    
    Hide();        //���ع��
    Beginning();//��ʼ����ͼ
    a=GetTickCount();
    while(1) { 
        if(kbhit()!=0) { 
            spare=getch();
            
            //������
            if((spare!=(-32))&&(spare!=13)&&(spare!=' ')) continue;//����
            
            //��Enter
            if(spare==13) {    //ȷ��
                //����
                if(mode%2==0) { 
                    if(map[floatx][floaty]=='@'&&flag[floatx][floaty]==0) { 
                        break;    //����
                        game=0;
                    }
                    
                    if(flag[floatx][floaty]==1) continue;    //��������
                    Open();
                    position(0,0);
                    SetConsoleTextAttribute(handle_out, FORE_GREEN);
                    for(int i=0;i<A;i++) { 
                        for(int j=0;j<B;j++) Lump(i,j);
                        printf("\n");
                    }
                    position(floaty*2,floatx);
                    SetConsoleTextAttribute(handle_out, FORE_BLUE);
                    Lump(floatx,floaty);
                }
                
                //�����
                else { 
                    
                    //���ܲ���ĵط�
                    if(map[floatx][floaty]=='x'||(map[floatx][floaty]>'0'&&map[floatx][floaty]<'9'))
                        continue;    //����
                    
                    //����
                    if(flag[floatx][floaty]==0) { 
                        flagnum++;
                        flag[floatx][floaty]=1;
                        position(floaty*2,floatx);
                        SetConsoleTextAttribute(handle_out, FORE_BLUE);
                        Lump(floatx,floaty);
                    }
                    
                    //����
                    else { 
                        flagnum--;
                        flag[floatx][floaty]=0;
                        position(floaty*2,floatx);
                        SetConsoleTextAttribute(handle_out, FORE_BLUE);
                        Lump(floatx,floaty);
                    }
                }
            }
            
            //���ո�
            if(spare==' ') Mode();    //�л�ģʽ
            
            //�������
            if(spare==-32) { 
                news=getch();
                Move();    //�ƶ����
            }
            for(int i=0;i<A;i++) for(int j=0;j<B;j++) if(map[i][j]=='x'||(map[i][j]>'0'&&map[i][j]<'9')) game++;
            if(game==A*B-C+1) break;
            else game=1;
            SetConsoleTextAttribute(handle_out, FORE_RED);
            position(44,5);
            printf("ʣ��������%d ",C-flagnum);
        }
        else Sleep(10);
        b=GetTickCount();
        SetConsoleTextAttribute(handle_out, FORE_RED);
        position(44,7);
        printf("��ʱ��");    //��ʱ
        if((b-a)/60000<10) printf("0");
        printf("%d:",(b-a)/60000);
        if(((b-a)/1000)%60<10) printf("0");
        printf("%d:",((b-a)/1000)%60);
        if(((b-a)/10)%100<10) printf("0");
        printf("%d",((b-a)/10)%100);
    }
    SetConsoleTextAttribute(handle_out, FORE_RED);
    position(5,5);
    if(game==1) printf("��Ϸ������");
    else printf("����ɹ���");
    position(5,8);
    printf("���������");
    scanf("%c%c",&spare,&spare);
    system("cls");
    position(0,0);
    goto Relife;
} 
