#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE* stream;
	if(strcmp(argv[1],"-c")==0)
	{
		if(stream=fopen(argv[2],"r"))
			printf("字符数：%d",totalcharacter(stream));
		else
			printf("Invalid filename input");//无效的文件名输入
	}

	else if(strcmp(argv[1],"-w")==0)
	{
		if(stream=fopen(argv[2],"r"))
			printf("单词数：%d",totalword(stream));
		else
			printf("Invalid filename input");
	}

	else
		printf("Invalid parameter input\n"); //无效的参数输入
	
	return 0;
}

int totalcharacter(FILE* stream)
{
	//feof() 到达文件尾时返回真值
	//fgetc() 从流中读一个字符
	int Sum=0;
    if(stream != NULL)
    {
        while(!feof(stream))
        {
        	fgetc(stream);
        	Sum++; 
		}
    }
    else
        printf("fail to open! \n");
	fclose(stream);
	return Sum-1;//除去字符串的结束符 '\0' 
}

int totalword(FILE* stream)
{
	int Sum=0;
	char ch;
	if(stream != NULL)
    {
        while(!feof(stream))
        {
        	ch=fgetc(stream);
        	if(ch==' '||ch==',')
        	Sum++; 
		}
    }
    else
        printf("fail to open! \n");
	fclose(stream);
	return Sum+1;//第一个单词前面不为空
}
