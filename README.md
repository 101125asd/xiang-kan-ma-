#include<stdio.h>
#include<string.h>
typedef struct student;
struct student{
	 char number[20];//准考证号
	 char text_number[10];//试机座位号
	 char seating_number[10];//考试座位号
}*p;
int main() {
	int n;
	scanf("%d", &n);
	p = (struct student*)malloc(sizeof(struct student)*n);//创建
	
	int i;
	for (i = 0;i < n;i++)//输入信息
		scanf("%s %s %s", (p + i)->number, (p + i)->text_number, (p + i)->seating_number);
		
 	int num, search,m;
 	scanf("%d", &num);
	for (m = 1;m <= num;m++) {
		i = 0;
		scanf("%d", &search);
		while (search != atoi((p+i)->text_number))//找试机座位号
			i++;
		printf("%s %s\n", (p + i)->number, (p + i)->seating_number);//找到后输出
	}
	return 0;
}
