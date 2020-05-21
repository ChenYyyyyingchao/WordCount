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
	if((fp=fopen(Filename,"r"))==NULL)
	{
		printf("文件不能打开，请输入正确的文件名！");
		exit(0);
	}
	while(!feof(fp))
	{
		c=fgetc(fp);
		if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9')
		{
			while (c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9' || c=='_')
			{
				c = fgetc(fp);
			}
			wordCount++;
			c = fgetc(fp);
		}
		c = fgetc(fp);
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

