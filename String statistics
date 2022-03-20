#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100];
	char *ch;
	int n,count=0;
	printf("请输入：\n");
	gets(a);
	n=strlen(a);
ch=(char*)malloc(sizeof(char));
	printf("请输入一个想要统计的字符：\n");
	
	scanf("%s",ch);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{	
			a[i]=a[i]-32;
		if(a[i]==*ch)
		{
			if(a[i+1]==*(ch+1))
			{
				count++;
			}
			
		}
		else if(a[i]>='A'&&a[i]<='z')
		{
			a[i]=a[i]+32;
			if(a[i]==*ch)
			{
				
				if(a[i+1]==*(ch+1))
				{
				count++;
				}
			}
		}
		}		
	}
	printf("%d\n",count);
	return 0;
}
