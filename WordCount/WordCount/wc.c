#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE* stream;
	if(strcmp(argv[1],"-c")==0)
	{
		if(stream=fopen(argv[2],"r"))
			printf("�ַ�����%d",totalcharacter(stream));
		else
			printf("Invalid filename input");//��Ч���ļ�������
	}

	else if(strcmp(argv[1],"-w")==0)
	{
		if(stream=fopen(argv[2],"r"))
			printf("��������%d",totalword(stream));
		else
			printf("Invalid filename input");
	}

	else
		printf("Invalid parameter input\n"); //��Ч�Ĳ�������
	
	return 0;
}

int totalcharacter(FILE* stream)
{
	//feof() �����ļ�βʱ������ֵ
	//fgetc() �����ж�һ���ַ�
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
	return Sum-1;//��ȥ�ַ����Ľ����� '\0' 
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
	return Sum+1;//��һ������ǰ�治Ϊ��
}
