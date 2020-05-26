#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp; //设置全局变量fp
//统计字符的个数
void charnumer(char *Filename)
{	
	int charCount=0;
	if((fp=fopen(Filename,"r"))==NULL)
	{
		printf("文件不能打开，请输入正确的文件名！");
		exit(0);
	}
	while(!feof(fp))//判断是否到达文件末尾
	{
		if(fgetc(fp))//读文件
			charCount++;
	}
	fclose(fp);
	printf("字符数：%d\n",charCount);
}
//统计单词的个数
void wordnumber(char *Filename)
{
	int wordCount = 0;
	char c;
	int temp=0;
	if((fp=fopen(Filename,"r"))==NULL)
	{
		printf("文件不能打开，请输入正确的文件名！");
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
	printf("单词数：%d\n",wordCount);
}
//主函数			
int main(int argc,char *argv[])
{
    if(!strcmp(argv[1],"-w"))
		wordnumber(argv[2]);
	else if(!strcmp(argv[1],"-c"))
		charnumer(argv[2]);
	return 0;
}

