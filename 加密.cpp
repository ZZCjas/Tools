#include<stdio.h>   
#include<stdlib.h>   
#include<string.h>   
void encfile(char *in_filename,char *pwd,char *out_filename);/*���ļ����м��ܵľ��庯��*/   
void decryptfile(char* in_filename,char *pwd,char *out_filename); /*���ļ����ܵľ��庯��*/  
int main(int argc,char *argv[])/*����main()�����������в���*/   
{   
    int option; /*����ѡ��*/  
    char in_filename[30];/*�û������Ҫ���ܵ��ļ��� ���� Ҫ���ܵ��ļ�*/   
    char out_filename[30]; /*�û�������ܺ󱣴���ļ��� ���ǽ��ܱ�����ļ���*/  
    char pwd[8];/*������������*/   
    printf("1.����         2.����\n");      
    printf("��ѡ��:\n");  
    scanf("%d",&option);  
    getchar();  
    if(argc!=4){/*�ݴ���*/   
        printf("\n�����ļ���(����·��):\n");   
        gets(in_filename);/*�õ�Ҫ���ܵ��ļ���*/   
        printf("��Կ:\n");   
        gets(pwd);/*�õ�����*/   
        printf("����ļ���:(����·��)\n");   
        gets(out_filename);/*�õ����ܺ���Ҫ���ļ���*/     
    }   
    else{/*��������в�����ȷ,��ֱ�����г���*/   
        strcpy(in_filename,argv[1]);   
        strcpy(pwd,argv[2]);   
        strcpy(out_filename,argv[3]);   
    }   
  
    switch(option){  
    case 1: //����      
        encfile(in_filename,pwd,out_filename);/*���ܺ�������*/   
        break;  
    case 2://����  
        decryptfile(in_filename,pwd,out_filename);/*���ܺ�������*/  
        break;  
    default:  
        break;  
    }       
    return 0;   
}   
/*�����Ӻ�����ʼ*/   
void encfile(char *in_filename,char *pwd,char *out_file)   
{   
    FILE *fp1,*fp2;   
    register char ch;   
    int j=0;   
    int j0=0;   
    fp1=fopen(in_filename,"r");/*��Ҫ���ܵ��ļ�*/   
    if(fp1==NULL){   
        printf("���ܴ�Ҫ���ܵ��ļ�\n"); 
		system("pause");  
        exit(1);/*������ܴ�Ҫ���ܵ��ļ�,���˳�����*/   
    }   
    fp2=fopen(out_file,"w");   
    if(fp2==NULL){   
        printf("���ܽ�������ļ�\n");  
		system("pause"); 
        exit(1);/*������ܽ������ܺ���ļ�,���˳�*/   
    }   
  
    while(pwd[++j0]);    
  
    ch=fgetc(fp1);   
  
    /*�����㷨��ʼ*/   
    while(!feof(fp1)){   
        if(j0 >7)  
           j0 = 0;  
        ch += pwd[j0++];  
        fputc(ch,fp2);   
        ch=fgetc(fp1);   
    }   
    fclose(fp1);/*�ر�Դ�ļ�*/   
    fclose(fp2);/*�ر�Ŀ���ļ�*/   
    printf("OK!\n");
    system("pause");
}   
  
/*�����Ӻ�����ʼ*/   
void decryptfile(char *in_filename,char *pwd,char *out_file)   
{   
    FILE *fp1,*fp2;   
    register char ch;   
    int j=0;   
    int j0=0;   
    fp1=fopen(in_filename,"r");/*��Ҫ���ܵ��ļ�*/   
    if(fp1==NULL){   
        printf("���ܴ�Ҫ���ܵ��ļ�\n");  
		system("pause");
        return;/*������ܴ�Ҫ���ܵ��ļ�,���˳�����*/   
    }   
    fp2=fopen(out_file,"w");   
    if(fp2==NULL){   
        printf("���ܽ�������ļ�\n");  
		system("pause");
        return;/*������ܽ������ܺ���ļ�,���˳�*/   
    }   
      
    while(pwd[++j0]);     
    ch=fgetc(fp1);   
    /*�����㷨��ʼ*/   
    while(!feof(fp1)){   
        if(j0 >7)  
           j0 = 0;  
        ch -= pwd[j0++];  
        fputc(ch,fp2);/*�ҵĽ����㷨*/  
        ch=fgetc(fp1);   
    }   
    fclose(fp1);/*�ر�Դ�ļ�*/   
    fclose(fp2);/*�ر�Ŀ���ļ�*/  
	printf("OK!\n");
	system("pause");
}   
