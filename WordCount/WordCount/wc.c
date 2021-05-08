#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE* stream;
	if(--argc==2)
	{
		if(strcmp(argv[1],"-c")==0)
		{
			if(stream=fopen(argv[2],"r"))
			{
				printf("�ַ�����%d",totalcharacter(stream));
			}
			else
			{
				printf("Invalid filename input");
			}
		}
		else if(strcmp(argv[1],"-w")==0)
		{
			if(stream=fopen(argv[2],"r"))
			{
				printf("��������%d",totalword(stream));
			}
			else
			{
				printf("Invalid filename input");
			}
		}
		else
		{
			printf("Invalid parameter input\n");
			printf("%d",strcmp(argv[1],"-c"));
		}
	}
	else
	{
		printf("Wrong number of parameters");
	}
	system("pause");
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
	return Sum-1;//ʲô��дҲ��һ���ַ� 
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
	return Sum+1;//��һ������û��ʲô�������� 
}
