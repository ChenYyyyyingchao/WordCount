#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp; //����ȫ�ֱ���fp
//ͳ���ַ��ĸ���
void charnumer(char *Filename)
{	
	int charCount=0;
	if((fp=fopen(Filename,"r"))==NULL)
	{
		printf("�ļ����ܴ򿪣���������ȷ���ļ�����");
		exit(0);
	}
	while(!feof(fp))//�ж��Ƿ񵽴��ļ�ĩβ
	{
		if(fgetc(fp))//���ļ�
			charCount++;
	}
	fclose(fp);
	printf("�ַ�����%d\n",charCount);
}
//ͳ�Ƶ��ʵĸ���
void wordnumber(char *Filename)
{
	int wordCount = 0;
	char c;
	int temp=0;
	if((fp=fopen(Filename,"r"))==NULL)
	{
		printf("�ļ����ܴ򿪣���������ȷ���ļ�����");
		exit(0);
	}
	while(!feof(fp))
	{
		c=fgetc(fp);
		if((c>='a'&&c<='z') ||(c>='A'&&c<='Z'))
		{
			temp=1;
		}
		else if(temp==1) 
		{
			wordCount++;
			temp=0;
		}
	}
	fclose(fp);
	printf("��������%d\n",wordCount);
}
//������			
int main(int argc,char *argv[])
{
    if(!strcmp(argv[1],"-w"))
		wordnumber(argv[2]);
	else if(!strcmp(argv[1],"-c"))
		charnumer(argv[2]);
	return 0;
}

