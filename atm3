#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
struct Account
{
	char username[100];//修改处
	char password[100];
	char password1[100];
	int money;
	char sfz[19];
	char number[12];
	char name[100];
	
	struct Account * next;
};
typedef struct Account Account;

Account * head=NULL;
Account * tail=NULL;
Account * curAccount=NULL;//记录当前账户 

Account * otherAccount=NULL;//记录对方账户

struct TransactionRecord
{
	char username[100];
	time_t timestamp;//时间戳 
	int type;//交易类型 0-取钱，1-存钱，2-转出，3-转入
	int amount;//数额 
	
	struct TransactionRecord * next; 
}; 
typedef struct TransactionRecord TR;

TR * trHead=NULL;
TR * trTail=NULL; 

void drawMoney()//取款
{	
	int money;
	system("cls");
	printf("请输入取款金额：");
	scanf("%d",&money);
	
	//从账户里面扣钱 
	if(money>curAccount->money)
	{
		printf("余额不足！\n");
	}
	else
	{
		//记录交易记录 创建结点，赋值初始化，添加结点到链表
		TR * newNode=(TR*)malloc(sizeof(TR));

		curAccount->money-=money;
		printf("取款成功！\n");
		
		
		
		newNode->next=NULL;
		strcpy(newNode->username,curAccount->username);
		newNode->type=0;
		newNode->amount=money;
		newNode->timestamp=time(NULL);
		
		if(trHead==NULL)
		{
			trHead=newNode;
			trTail=newNode; 
		}
		else
		{
			trTail->next=newNode;
			trTail=newNode;
		}
	}
	
}

void loadData()//保存数据
{
	FILE* fp=fopen("D:/atm.txt","r"); 
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//创建结点
			Account *newNode=(Account *)malloc(sizeof(Account));
			
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s %f\n",newNode->username,newNode->password,&newNode->money);
			
			//添加结点到链表 
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		fclose(fp); 
	}
}

int findAccount(Account a)
{
	Account * curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
	}
	return 0;
}
void mima()//登录时的密码
{
	Account a;
	int num=0;
	while(num<3)
	{
		printf("请输入6位数的存储密码\n");
		for(int i=0;i<6;i++)
		{
			a.password[i]=getchar();
			printf("*");
		}
		printf("\n");
		a.password[6]='\0';
		printf("请再一次确认密码\n");
		for(int j=0;j<6;j++)
		{
			a.password1[j]=getchar();
			printf("*");
		}
		printf("\n");
	    a.password1[6]='\0';
		if(strcmp(a.password,a.password1)==0)
		{
			printf("密码正确,单击任意键进入主菜单\n");
		}
		else
		{
			num++;
			printf("您输入的密码有错误，请重新输入\n");
		}
		if(num==3)
		{
			system("cls");
			printf("对不起您的三次密码均错误\n");
			printf("感谢您的使用，再见!\n");
			exit(0);
		}
	}
}
void signIn()//登录
{
	Account a; 
	printf("请输入账号：");
	scanf("%s",a.username);
	
	if(findAccount(a))
	{
		mima();
		printf("登录成功！\n");
	}
	else
	{
		printf("登录失败！\n");
	}
	system("cls");

	printf("单击任意键返回主菜单\n");
		getchar();
} 

void saveMoney()//存款
{
	system("cls");
	int money;
	printf("请输入存钱金额：");
	
	scanf("%d",&money);
	curAccount->money+=money;
	printf("存款成功！单击任意键返回主菜单\n");
	getchar();
}

void saveTransactionRecord()
{
	FILE* fp=fopen("D:/ATM.txt","w");
	TR* curP=trHead;
	while(curP!=NULL)
	{
		fprintf(fp,"%s %ld %d %f\n",curP->username,curP->timestamp,curP->type,curP->amount);
		curP=curP->next;
	}
	fclose(fp);
}

int findOtherAccount(char otherUsername[])
{
	Account* curp=head;
	while(curp!=NULL)
	{
		if(strcmp(curp->username,otherUsername)==0)
		{
			otherAccount=curp;
			return 1;
		}
		curp=curp->next;
	}
	return 0;
}

void transfer()
{
	char otherUsername[100];
	int money;
	//输入对方账户
	printf("请输入对方账户：");
	
	scanf("%s",otherUsername);

	//验证账号的合法性
	if(findOtherAccount(otherUsername))
	{
	

		//输入转账金额
		printf("请输入转账金额：");
		
		scanf("%d",&money);

		//验证金额合法性
		if(curAccount->money>=money)
		{
			//记录转账记录：转出(创建交易记录结点，初始化，添加到链表)
			TR * newNodeOut=(TR*)malloc(sizeof(TR));

			//转账（原账户的钱减少，对方账户的钱增多）
			curAccount->money-=money;
			otherAccount->money+=money;
				

			//输出提示转账成功
			printf("转账成功！\n");


			
		
			newNodeOut->next=NULL;
			strcpy(newNodeOut->username,curAccount->username);
			newNodeOut->type=2;
			newNodeOut->amount=money;
			newNodeOut->timestamp=time(NULL);
			
			if(trHead==NULL)
			{
				trHead=newNodeOut;
				trTail=newNodeOut; 
			}
			else
			{
				trTail->next=newNodeOut;
				trTail=newNodeOut;
			}


			//记录转账记录：转入
			TR * newNodeIn=(TR*)malloc(sizeof(TR));
		
			newNodeIn->next=NULL;
			strcpy(newNodeIn->username,curAccount->username);
			newNodeIn->type=3;
			newNodeIn->amount=money;
			newNodeIn->timestamp=time(NULL);
			
			if(trHead==NULL)
			{
				trHead=newNodeIn;
				trTail=newNodeIn; 
			}
			else
			{
				trTail->next=newNodeIn;
				trTail=newNodeIn;
			}
		}
		else
		{
			printf("余额不足!\n");
		}
	}
	else
	{
		printf("账户错误！\n");
	}
}

void gaimi()//改密码
{
	char mima[7];
//	int *curpAccount=NULL;//修改处
	printf("请输入原密码:\n");
	scanf("%s",&mima);
	while(1)
	{
		if(strcmp(curAccount->password,mima)==0)//修改处（curp改为cur）
		{
			printf("请输入新密码\n");
			scanf("%s",curAccount->password);
			break;
		}
		else
		{
			printf("密码与原密码不符，请重新输入\n");
		}//k
	};
	printf("密码修改成功,点击任意键返回主菜单\n");
	getchar();
}
void zhuche()
{
	Account a;
	printf("请输入身份证号:\n");
	scanf("%s",a.sfz);
	printf("请输入电话号码\n");
	scanf("%s",a.number);
	printf("请输入姓名\n");
	scanf("%s",a.name);
	printf("%s %s %s\n",a.name,a.number,a.sfz);
	printf("请用户确认信息，若信息无误，单击任意键返回主菜单");
	getchar();
}
void shanchu()
{
	Account *curp=head;
	char name[100];
	char number[12];
	char sfz[19];
	scanf("%s %s %s",name,number,sfz);
	while(head!=NULL)
	{
	if(strcmp(curp->name,name)==0&&strcmp(curp->number,number)==0&&strcmp(curp->sfz,sfz)==0)
	{
		 	
	}
	}

}
void kaihu()
{
	
	Account a;

			char aab=rand()%1000000+1;
			//char *abb=aab+'0';//字符转换
			a.username=aab;
			//（修改处）

	printf("您的卡号是：\n");
	printf("%s\n",a.username);
	printf("开户成功，单击任意键返回主菜单\n");
	getchar();
}
int main()

{
	printf("=======================欢迎使用ATM============================\n");
	printf("请输入相应的数字:\n");
	printf("===========1.保存数据\t2.登录\t3.取款\t4.存款\t5.转账===========\n");
	printf("===========6.修改密码\t7.开户\t8.中英文\t9.注册\t10.退出程序=============\n");
	printf("================================================================\n");
	int num;
	scanf("%d",&num);
	while(num<=10&&num>=1)
	{
	
		switch(num)
		{
			case 1:
			loadData();break;
			case 2:
			signIn();break; 
			case 3:
			drawMoney();break;
			case 4:
			saveMoney();break;
			case 5:
			transfer();break;
			case 6:
			gaimi();break;
			case 7:
			kaihu();break;
			//case 8:
			//english();break;   （修改处）
			case 9:
			zhuche();break;
		}
	}

	return 0;
}
