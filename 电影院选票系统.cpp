#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// 结构体定义（电影、放映厅、订单、顾客、管理员）
struct Movie {
    char movieNum[20];    // 电影编号
    char movieName[20];  // 电影名称
    double price;        // 电影单价
    char date[20];       // 电影放映日期
    char time[20];       // 放映时间
    char movieHouse[20];  // 所在放映厅编号
    char setState[101];  // 当前状态
    struct Movie *next;
};
struct movieHouse {
    char houseNum[20];    // 放映厅编号
    char houseName[30];  // 放映厅名称
    int houserow;         // 放映厅行数
    int housecol;        // 放映厅列数
    char houseState [10];  // 放映厅状态open or close 
    struct movieHouse *next;
};
struct Order {
    char custName[20];   // 顾客用户名
    char movieName[20];  // 电影名称
    int ticketNum;       // 购买数量
    char set[40];        // 所选座位
    double ticketCost;   // 总价格
    char OrderDate[20];  // 购买日期
    struct Order *next;
};
struct Customer {
    char CustName[20];  // 顾客名称
    char CustCode[20];  // 密码
    
};
struct Customer cust[200];
struct Manager {
    char username[20];  // 管理员用户名
    char password[20];  // 密码
    struct Manager *next;
}; 
//2个主登录函数 
void loginCustomer(); //顾客登录 里面包含注册 // 顾客信息相关函数声明
void loginManager();//管理员登录 // 管理员信息相关函数声明 
//链表创建函数
Movie *Creat_Movie_Doc();  // 创建电影场次信息链
movieHouse *Create_House_Doc(); //创建放映厅链表

//2个管理总函数 
void HouseControl();  //放映厅管理
void MovieControl(); //电影管理 
// 电影信息相关函数声明
void Printf_Movie_Doc(Movie *mhead);  // 输出电影场次信息
Movie *Insert_movie_Doc(Movie *mhead);  //插入链表，增加电影数目
Movie *Delete_Movie_Doc(Movie *mhead);  //删除电影场次信息
void After_Movie_Doc(Movie *mhead);   //修改电影场次信息
void InMoviefile(Movie * mhead);   // 将电影信息写入movie.txt 文件 
void sortMovie(Movie *mhead);  //  对电影编号进行升序排列排序
// 放映厅信息相关函数声明 
movieHouse *Insert_House_Doc(movieHouse *head,movieHouse *p); //放映厅链表的插入   增加放映厅数据   
void print_House_Doc(movieHouse *head); // 遍历链表 ，输出放映厅信息
movieHouse* Delete_House_Doc(movieHouse * head,char houseNum[]) ;// 删除放映厅数据 
void After_House_Doc(movieHouse *head); // 修改已有放映厅的信息
void InHouseFile(movieHouse *head);   // 修改的信息写入文件
// 订单信息相关函数声明
void Ordercheck(Order *ohead, char name[]); //查看订单 
Order * MovieOrder(Order *ohead, Movie *mhead, char custName[]);//电影购票 
Order *Create_Order_Doc(); // 创建订单链表和文件进入链表
void InorderFile(Order *ohead);//  将订单链表导入文件
Order *Insert_Order_Doc(Order *ohead,Order *p);  // 将顾客的选择插入链表中
//查看注册人数 
int readCustomer(struct Customer cust[]); 

int main() {
    // 主程序代码
   //初始化一组顾客密码
    strcpy(cust[0].CustName, "zhanghaobo");
    strcpy(cust[0].CustCode, "zhanghaobo");
    // ...  
    int i; 
	int userType;  // 1表示管理员，2表示顾客  
	
	onceagain: 
	printf("==================================\n");
	printf("\n");
	printf("       请输入登录类型              \n");
	printf("\n");
	printf("    1.管理员\t  2.用户            \n");
	printf("\n"); 
	printf("==================================\n");
	printf("\n请输入您想要进行的操作： ");
	scanf("%d",&userType);
	system ("cls");
	// 根据用户输入来设置userType，可以通过菜单让用户选择管理员登录还是顾客登录
    if (userType == 1) {
        loginManager();
		// 管理员登录
        // 调用登录管理员的函数 loginManager，并根据返回值决定是否执行电影信息修改等操作
        // ... 
		again_01:
	printf("==================================\n");
	printf("    1. 电影放映厅信息管理        \n"); 
	printf("    2. 电影场次信息管理          \n");
	printf("    0. 退出                      \n");
	printf("==================================\n");
	int choice;
	printf("请输入你想要进行的操作：    ");
	scanf("%d",&choice);
	system ("cls");
	switch(choice)
	{
		case 1:
			HouseControl();
			goto again_01;
			break;   // 进行放映厅的管理
		case 2:
			MovieControl(); 
			goto again_01;
			break;  // 电影场次管理
		case 0: exit(0);break;
		default : goto again_01; break;
	}  
} 	else if (userType == 2) {
        loginCustomer();
		// 顾客选择登录还是注册 
        // 调用登录顾客的函数 loginCustomer和registerCustomer，并根据返回值决定是否执行订票等操作
        // ...    
    } else {
        printf("\n\n您的输入有误，请重新选择\n");
			Sleep(1000);
			system ("cls");
			goto  onceagain;
    }
	
    // ...

    return 0;
}
//下面开始写函数
//1先写管理员登陆函数
	void loginManager() 
{
    int maxLoginAttempts = 5; // 最大登录尝试次数
    int remainingAttempts = maxLoginAttempts;
    
    // 假设存在一个管理员账号和密码的数组，可以包含多个管理员账号
    struct Manager adminAccounts[3]; // 假设有3个管理员账号
    strcpy(adminAccounts[0].username, "1111");
    strcpy(adminAccounts[0].password, "1111");
    strcpy(adminAccounts[1].username, "2222");
    strcpy(adminAccounts[1].password, "2222");
    strcpy(adminAccounts[2].username, "3333");
    strcpy(adminAccounts[2].password, "3333");
    
    while (remainingAttempts > 0) {
        char username[20];
        char password[20];
        
        printf("\n请输入管理员账号： ");
        scanf("%s", username);
        printf("\n请输入密码： ");
        scanf("%s", password);
        
        // 验证管理员账号和密码
        int isAdmin = 0; // 标记是否是管理员
        for (int i = 0; i < 3; i++) { // 假设有3个管理员账号
            if (strcmp(username, adminAccounts[i].username) == 0 &&
                strcmp(password, adminAccounts[i].password) == 0) {
                isAdmin = 1; // 验证通过，是管理员
                break;
            }
        }
        
        if (isAdmin) {
            printf("\n登录成功！\n");
            // 在这里可以执行管理员操作
            break; // 退出登录循环
        } else {
            remainingAttempts--;
            printf("\n账号或密码错误，剩余尝试次数：%d\n", remainingAttempts);
            if (remainingAttempts > 0) {
                printf("\n请重新输入\n");
            } else {
                printf("\n登录失败，达到最大尝试次数，程序退出\n");
                exit(0);
            }
        }
    }
    // 在这里可以执行其他管理员操作...
    
}
	void loginCustomer()
{	
	FILE *fp = fopen("customer.txt", "a+");
	if (fp==NULL)
	{
		printf(" file open error!\n");
		exit (0);
	}
	//初始化一组密码 
	//fprintf(fp, "zhanghaobo zhang\n");//运行完第一次或者写进去就注释 
	int custCount = readCustomer(cust);
	char name[20],code[20];
	int choice,inputValid=0;
	again_1:
	printf("\n\n*******************************\n");
	printf(" \n    欢迎来到东莱影城       \n");
	printf("\n");
	printf(" \n  1. 登录\t  2.注册          \n");
	printf("\n");
	printf("\n*******************************\n");
	printf("请输入您的选择:   ");
	while (!inputValid)
	{
	scanf("%d", &choice);
	int flag =1,time=0;
	switch (choice) {
		case 1:
				// 执行登录操作
				again_2:
				custCount = readCustomer(cust); 
				printf("\n请输入用户名: ");
    			scanf("%s", name);
    			printf("\n请输入密码: ");
    			scanf("%s", code);
			for (int i=0;i<=custCount;i++) 
			{
				if ((strcmp(name,cust[i].CustName)==0) && (strcmp(code,cust[i].CustCode) == 0))
				{
					flag =0;
					break;
				}
			}	
			if (flag)
			{
	 			printf("账号或密码错误，请重新输入！ \n");
	 			time++;
	 			printf("你还有%d 次输入次数",(5-time));
	 			system("pause"); //  可以实现冻结屏幕，便于观察程序执行结果 
	 			system ("cls");
	 			goto again_2;
			}
			else 
			{
				printf("登录成功！\n");
				system("pause"); //  可以实现冻结屏幕，便于观察程序执行结果 
	 			system ("cls");  // 清屏命令 
			}	
				inputValid = 1; // 输入有效，退出循环
				break;
		case 2:
				// 执行注册操作
				again_3:
				printf("请输入您的用户名：  ");
				scanf("%s",name);
					for (int i=0;i<custCount;i++)
				{
						if (strcmp(name,cust[i].CustName) == 0)   //  比较两个参数的大小，相同返回零 
						{
						printf("该用户名已存在");
						system("pause"); //  可以实现冻结屏幕，便于观察程序执行结果 
	 					system ("cls");
				   		goto  again_3;		 
						}	
				}
					printf("请输入密码： ");
					scanf("%s",code);
					strcpy (cust[custCount].CustName,name);
					strcpy (cust[custCount].CustCode,code);	//fscanf  从文件中读取数据保存到前面的链表中去 
					fprintf(fp,"%s   %s\n",cust[custCount].CustName,cust[custCount].CustCode);
					//   将新增加的用户的用户名和密码写入文件中去 
					printf("注册成功！\n");
					system("pause"); //  可以实现冻结屏幕，便于观察程序执行结果 
	 				system ("cls");	
					inputValid = 1; // 输入有效，退出循环
					goto again_2; 
					break;
		default:
			printf("您的输入有误，请重新选择想要操作的内容 :  ");
			Sleep(1000);
			system ("cls");
			goto again_1;
				break;
		}
	}
	
	if (fclose(fp))
	{
		printf("can not close the file \n");
		exit(0);
	}
	Order *ohead;
	ohead = Create_Order_Doc();
	Movie *mhead;
	mhead = Creat_Movie_Doc();
	again_9:
	printf("*************************************\n");
	printf("           1.进行电影订票            \n");
	printf("           2.查看我的订单            \n");
	printf("           0.退出                    \n");
	printf("*************************************\n");
	int select;
	printf("请输入您的选择:  ");
	scanf("%d",&select);
	system ("cls");
 	
	switch (select)
	{
		case 1:
			ohead =MovieOrder(ohead,mhead,name);
			InorderFile(ohead);
			goto again_9;
			break;   // 电影订票 
		case 2:
		Ordercheck(ohead,name);
		goto again_9;
		break;   //  查看订票
		case 0:return;break;
	    default:
	    	{
	    		printf("您的输入错误，请重新选择！ ");
	    		Sleep(1000);
	    		system ("cls");
	    		goto again_9;
	    	    break;
			}
	}	
}	
int readCustomer(struct Customer cust[]) {
    FILE *fp;
    int custCount = 0;

    if ((fp = fopen("customer.txt", "r")) == NULL) {
        printf("文件打开失败!\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", cust[custCount].CustName, cust[custCount].CustCode) == 2) {
        custCount++;
    }

    fclose(fp);

    return custCount;
}
void HouseControl(){
	movieHouse *head;
	head=Create_House_Doc();
	again_4:
	printf("---------------------------------------\n");
	printf("1. 增加放映厅 \n");
	printf("2. 删除放映厅 \n");
	printf("3. 对已有放映厅进行改变\n");
	printf("4. 查看放映厅 \n");
	printf("0. 退出\n");
	printf("---------------------------------------\n");
	int choice;
	printf("请输入你想要进行的操作:  ");
	scanf("%d",&choice);
	system ("cls");
	switch (choice)
	{
		case 1:
			print_House_Doc(head);
			printf("请输入你想要增加的放映厅的编号，名字，行，列，状态：\n");
			movieHouse * p;
			p=(struct movieHouse*)malloc(sizeof(struct movieHouse));
			scanf("%s %s %d %d %s",p->houseNum,p->houseName,&p->houserow,&p->housecol,p->houseState);
			system ("cls");
			head =Insert_House_Doc(head,p);
			InHouseFile(head);
			print_House_Doc(head);
			goto again_4;
			break;
		case 2:
			print_House_Doc(head);
			printf("请输入你想去掉的放映厅的编号：");
			char housenum[20];
			scanf("%s",housenum);
			system("cls");
			head = Delete_House_Doc(head,housenum);
			InHouseFile(head);
			print_House_Doc(head);
			goto again_4;
			break;
		case 3:
			print_House_Doc(head);
			After_House_Doc(head);
			InHouseFile(head);
			print_House_Doc(head);
			goto again_4;
			break;
		case 4:
			print_House_Doc(head);
			system("pause");
			system("cls");
			goto again_4;
			break;
		case 0: return;
		default: goto again_4;break;
	}
 
} 

movieHouse *Create_House_Doc()
{
	FILE *fp=fopen("movie_house.txt","rt");
	if (fp==NULL)
	{
		printf("file  open error");
		exit(-1);
	}
	movieHouse *head;
	head  = (movieHouse *)malloc (sizeof (movieHouse));
	head->next =NULL;
	movieHouse *p,*p1,*q;
	p = (movieHouse *)malloc (sizeof (movieHouse));
	p=head;
	p1 = (movieHouse *)malloc (sizeof (movieHouse));
	p1->next =NULL;
	if (fscanf(fp,"%s %s %d %d %s",p1->houseNum,p1->houseName,&p1->houserow,&p1->housecol,p1->houseState)!=EOF) 
	{
		p->next =p1;
		while(p->next)
		{
			p = p->next;
		}
		while (fgetc(fp)!=EOF)  //  判断文件是否到末尾   s是否为空 
		{
			q = (movieHouse *)malloc (sizeof (movieHouse));
			fscanf(fp,"%s %s %d %d %s",q->houseNum,q->houseName,&q->houserow,&q->housecol,q->houseState);
			p->next = q;    // 尾插法 
			q->next =NULL;
			p = p->next;
		 }
	    movieHouse *p2 = (movieHouse *)malloc (sizeof (movieHouse));
	    p2 = head;  //  删除最后一个节点 
	    while (p2->next->next)
	    {
	    	p2 = p2->next;
		}
		p2->next = NULL;
	}
	else
		return NULL;
	fclose(fp);
	return head;
}
void print_House_Doc(movieHouse *head)
{
    movieHouse *current = head->next; // 跳过头节点

    printf("放映厅信息：\n");
    while (current != NULL) {
        printf("放映厅编号：%s\t", current->houseNum);
        printf("放映厅名称：%6s\t", current->houseName);
        printf("座位行数：%d\t", current->houserow);
        printf("座位列数：%d\t", current->housecol);
        printf("放映状态：%s\t", current->houseState);
        printf("\n");
		current = current->next;
    }
} 
movieHouse *Insert_House_Doc(movieHouse *head, movieHouse *p) {
    // 如果头节点为空，直接将p作为新的头节点
    if (head == NULL) {
        return p;
    }

    // 遍历链表找到最后一个节点
    movieHouse *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // 将p插入到链表末尾
    current->next = p;
    p->next = NULL;

    return head;
}
movieHouse* Delete_House_Doc(movieHouse* head, char houseNum[])
{
    if (head == NULL) {
        printf("放映厅链表为空，无法删除。\n");
        return head;
    }

    movieHouse* current = head;
    movieHouse* previous = NULL;

    // 遍历链表找到待删除的放映厅
    while (current != NULL && strcmp(current->houseNum, houseNum) != 0) {
        previous = current;
        current = current->next;
    }

    // 如果未找到对应放映厅
    if (current == NULL) {
        printf("未找到放映厅编号为 %s 的放映厅，无法删除。\n", houseNum);
        return head;
    }

    // 找到了待删除的放映厅，从链表中移除它
    if (previous == NULL) {
        // 如果待删除的放映厅是链表的第一个元素
        head = head->next;
    } else {
        previous->next = current->next;
    }

    free(current); // 释放内存

    printf("放映厅编号为 %s 的放映厅已成功删除。\n", houseNum);

    return head; // 返回更新后的头指针
}
void InHouseFile(movieHouse *head)
{
	FILE * fp;
	if ((fp=fopen("movie__house.txt","w"))==NULL)
	{
		printf("file open error");
		exit(0);
	}
	movieHouse *p1;
	for (p1= head ->next;p1!=NULL;p1=p1->next)
	{
		fprintf(fp,"%s %s %d %d %s",p1->houseNum,p1->houseName,&p1->houserow,&p1->housecol,p1->houseState);
	}
	if (fclose(fp))
	{
		printf("con not close the file\n ");
		exit(0);
	}
}
void After_House_Doc(movieHouse *head)
{
    int choice;
    char name[20];
    movieHouse *ptr, *p;
    printf("请输入你想要修改的放映厅名称： ");
    scanf("%s", name);
    printf("===========================\n");
    printf("1.状态\n");
    printf("===========================\n");
    printf("\n请输入你想要修改的信息： ");
    scanf("%d", &choice);

    for (ptr = head->next; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->houseName, name) == 0)
        {
            p = ptr;
            break;
        }
    }

    switch (choice)
    {
        case 1:
            char newState[20];
            printf("请输入你想要修改成的状态： ");
            scanf("%s", newState);
            strcpy(p->houseState, newState);
            break;
        default:
            printf("无效的选项\n");
            break;
    }
    InHouseFile(head);
}
void MovieControl()  // 电影场次的管理 
{
	Movie *mhead;
//	mhead = (Movie*)malloc(sizeof(Movie));
//	mhead->next =NULL;
	mhead = Creat_Movie_Doc();
	sortMovie(mhead);
	///  此处需要一个建立头节点的链表    同时导入电影文件 
	again_02:
	printf("****************************************\n");
	printf("1.增加电影\n");
	printf("2.删除已存在的电影\n");
	printf("3.修改电影信息\n");
	printf("4.输出电影场次信息\n");
	printf("0.退出\n");
	printf("****************************************\n");
	int choice;
	printf("请输入您的选择：\n");
	scanf("%d",&choice);
	system("cls");
	switch (choice)
	{
		case 1: 
			Printf_Movie_Doc(mhead);
			Insert_movie_Doc(mhead);
			system("cls");
			InMoviefile(mhead);
			Printf_Movie_Doc(mhead);
			goto again_02;
			break;
		case 2:
			Printf_Movie_Doc(mhead);
			system("cls");
			Delete_Movie_Doc(mhead);
			system("cls");
			Printf_Movie_Doc(mhead);
			goto again_02;
			break;
		case 3: 
			Printf_Movie_Doc(mhead);
			After_Movie_Doc(mhead);
		 	system("cls");
			Printf_Movie_Doc(mhead);
			goto again_02;
			break;
		case 4: 
			Printf_Movie_Doc(mhead);
			system("pause");
			system("cls"); 
			goto again_02;
			break;
		case 0: return;break;
	}
}
Movie *Creat_Movie_Doc()
{
	FILE *fp = fopen("movie.txt", "rt");
	if (fp == NULL)
	{
		printf("File open error");
		exit(-1);
	}
	Movie *mhead;
	mhead = (Movie *)malloc(sizeof(Movie));
	mhead->next = NULL;
	Movie *p, *p1, *q;
	p = (Movie *)malloc(sizeof(Movie));
	p = mhead;
	p1 = (Movie *)malloc(sizeof(Movie));
	p1->next = NULL;
	if (fscanf(fp, "%s %s %lf %s %s %s %s", p1->movieNum, p1->movieName, &p1->price, p1->date, p1->time, p1->movieHouse, p1->setState) != EOF)
	{
		p->next = p1;
		while (p->next)
		{
			p = p->next;
		}
		while (fgetc(fp) != EOF) // 判断文件是否到末尾 s是否为空
		{
			q = (Movie *)malloc(sizeof(Movie));
			fscanf(fp, "%s %s %lf %s %s %s %s", q->movieNum, q->movieName, &q->price, q->date, q->time, q->movieHouse, q->setState);
			p->next = q; // 尾插法
			q->next = NULL;
			p = p->next;
		}
		Movie *p2 = (Movie *)malloc(sizeof(Movie));
		p2 = mhead; // 删除最后一个节点
		while (p2->next->next)
		{
			p2 = p2->next;
		}
		p2->next = NULL;
	}
	else
		return NULL;
	fclose(fp);
	return mhead;
}

Movie *Insert_movie_Doc(Movie *mhead) //插入链表，增加电影数目
{
	Movie *ptr,*ptr1,*p;
	ptr = (Movie *)malloc (sizeof (Movie));
	ptr = mhead;
	int n;
	printf("\n\n请输入你想要增加的电影场数：\n ");
	scanf("%d",&n);
 
		while (n)
		{
			p = (Movie *)malloc (sizeof (Movie));
			printf("\n\n请输入电影的 编号，名字，价格，放映日期，放映时间，放映地点,现在状态\n");
			scanf("%s %s %ld %s %s %s %s",p->movieNum,p->movieName,&p->price,p->date,p->time,p->movieHouse,p->setState);
			if (ptr->next ==NULL)
			{
				ptr->next =p;
				p->next = NULL;
			}
			else 
			{
				 p->next = ptr ->next;
				 ptr->next = p;
			}
			n--;
		}
	return mhead;
}
Movie *Delete_Movie_Doc(Movie *mhead) //删除电影场次信息
{
	Movie *ptr1,*ptr2;
	int n;
	printf("\n\n请输入你想要删除的电影的数目：  ");
	scanf("%d",&n);
	ptr1 = (Movie *)malloc (sizeof (Movie));
	ptr2 = (Movie *)malloc (sizeof (Movie));
	ptr1 = mhead;
	ptr2 = mhead->next;
 
	char num[20];
	while(n)
	{
		printf("\n\n请输入你想要删除的电影的编号：  ");
		scanf("%s",num);
		while(ptr2!=NULL)
		{
			if ((strcmp(ptr2->movieNum,num))==0)
			{
				ptr1->next = ptr2->next;
				free(ptr2);
			}
			ptr1 = ptr2;  // 判断编号不相同，ptr1 移动到ptr2 的位置 
			ptr2= ptr2->next;  //ptr2 往后移动一个结点 
		}
		n--;
	}
	return mhead;
	
}

void After_Movie_Doc(Movie *mhead)   //修改电影场次信息
{
	int choice;
	char name[20];
	Movie *ptr,*p;
	movieHouse* ptr1;
	printf("请输入你想要修改的电影名称： ");
	scanf("%s",name);
	printf("===========================\n");
	printf("1.价格\n");
	printf("2.所在放映厅编号\n");
	printf("3.放映时间\n");
	printf("===========================\n");
	printf("\n请输入你想要修改的信息： ");
	scanf("%d",&choice);
	for (ptr=mhead->next;ptr!=NULL;ptr=ptr->next)
	{
		if (strcmp(ptr->movieName,name)==0)
		{
			p=ptr;
			break;
		}
	}
	switch(choice)
	{
		case 1:
			double price;
			printf("请输入你想要修改成为的价格：");
			scanf("%lf",&price);
			p->price=price;
			break;
		case 2:
			char num[20];
			printf("请输入你想要修改成的编号： ");
			scanf("%s",num);
			strcpy(p->movieHouse,num);
		///	memcpy(p->movieHouse,num);
			break;
		case 3:
			char time[20];
			printf("请输入你想要改成的时间： ");
			scanf("%s",time);
			strcpy(p->time,time);
		//	p->time=time[20];
		//	memcpy(p->time,time);
			break;
	}
	InMoviefile(mhead);	
}
void InMoviefile(Movie * mhead)   // 将电影信息写入文件，实现文件的更新 
{
	FILE * fp;
	if ((fp=fopen("movie.txt","w"))==NULL)
	{
		printf("file open error");
		exit(0);
	}
	Movie *ptr;
	for (ptr= mhead ->next;ptr!=NULL;ptr=ptr->next)
	{
		fprintf(fp,"%s %s %lf %s %s %s %s\n",ptr->movieNum,ptr->movieName,ptr->price,ptr->date,ptr->time,ptr->movieHouse,ptr->setState);
	}
	if (fclose(fp))
	{
		printf("con not close the file\n ");
		exit(0);
	}
}
void sortMovie(Movie *mhead)  // 对电影编号进行升序 
{
	Movie *p,*q,*r;
	r = NULL;
	while (r!=mhead->next)
	{
		p=mhead;
		q = p->next;
		while (q->next != r)
		{
			if (strcmp(p->next->movieNum,q->next->movieNum)==1)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
		r = q;
	}	
}
void Printf_Movie_Doc(Movie *mhead)
{
    printf("\n===========================\n");
    printf("   电影信息\n");
    printf("===========================\n");
    printf("编号\t  名称   \t价格\t   日期  \t时间   放映厅    状态\n");
    Movie *ptr;
    for (ptr = mhead->next; ptr != NULL; ptr = ptr->next)
    {
        printf("%s\t%10s\t%.2lf\t%s\t%s\t%s\t%s\n", ptr->movieNum, ptr->movieName, ptr->price, ptr->date, ptr->time, ptr->movieHouse, ptr->setState);
    }
}
Order *Create_Order_Doc() // 创建订单链表和文件进入链表
{
	FILE *fp=fopen("order.txt","rt");
	if (fp==NULL)
	{
		printf("file  open error");
		exit(-1);
	}
	Order *ohead;
	ohead  = (Order *)malloc (sizeof (Order));
	ohead->next =NULL;
	Order *p,*p1,*q;
	p = (Order *)malloc (sizeof (Order));
	p=ohead;
	p1 = (Order *)malloc (sizeof (Order));
	p1->next =NULL;
	if (fscanf(fp, "%s %s %d %s %lf %s", p1->custName, p1->movieName, &p1->ticketNum, p1->set, &p1->ticketCost, p1->OrderDate)==EOF) 
	{
		p->next =p1;
		while(p->next)
		{
			p = p->next;
		}
		while (fgetc(fp)!=EOF)  //  判断文件是否到末尾   s是否为空 
		{
			q = (Order *)malloc (sizeof (Order));
			fscanf(fp,"%s %s %d %s %lf %s", p1->custName, p1->movieName, &p1->ticketNum, p1->set, &p1->ticketCost, p1->OrderDate);
			p->next = q;    // 尾插法 
			q->next =NULL;
			p = p->next;
		 }
	    Order *p2 = (Order *)malloc (sizeof (Order));
	    p2 = ohead;  //  删除最后一个节点 
	    while (p2->next->next)
	    {
	    	p2 = p2->next;
		}
		p2->next = NULL;
	}
	else
		return NULL;
	fclose(fp);
	return ohead;

} 
void InorderFile(Order *ohead) {
    FILE *fp = fopen("order.txt", "w");
    if (fp == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    // 遍历订单链表，将每个订单写入到文件中
    Order *current = ohead;
    while (current != NULL) {
        fprintf(fp, "%s %s %d %s %.2lf %s\n", current->custName, current->movieName, current->ticketNum, current->set, current->ticketCost, current->OrderDate);
        current = current->next;
    }

    fclose(fp);
}
Order * MovieOrder(Order *ohead, Movie *mhead, char custName[]) {
    // 显示所有电影
    Printf_Movie_Doc(mhead);

    // 让顾客选择电影
    char movieNum[20];
    printf("请输入你想要购票的电影编号： ");
    scanf("%s", movieNum);

    // 在电影链表中找到顾客选择的电影
    Movie *selectedMovie = NULL;
    Movie *currentMovie = mhead->next;
    while (currentMovie != NULL) {
        if (strcmp(currentMovie->movieNum, movieNum) == 0) {
            selectedMovie = currentMovie;
            break;
        }
        currentMovie = currentMovie->next;
    }

    // 如果没有找到顾客选择的电影，返回错误
    if (selectedMovie == NULL) {
        printf("未找到编号为 %s 的电影。\n", movieNum);
        return ohead;
    }

    // 让顾客输入购票数量
    int ticketNum;
    printf("请输入购票数量： ");
    scanf("%d", &ticketNum);

    // 创建新的订单
    Order *newOrder = (Order *)malloc(sizeof(Order));
    strcpy(newOrder->custName, custName);
    strcpy(newOrder->movieName, selectedMovie->movieName);
    newOrder->ticketNum = ticketNum;
    strcpy(newOrder->set, selectedMovie->movieHouse);
    newOrder->ticketCost = ticketNum * selectedMovie->price;
    strcpy(newOrder->OrderDate, selectedMovie->date);
    // 将新的订单插入到订单链表中
    ohead = Insert_Order_Doc(ohead, newOrder);

    return ohead;
}	
void Ordercheck(Order *ohead, char name[]) {
    FILE* fp = fopen("order.txt", "r"); // 以只读模式打开文件
    if (fp == NULL) {
        printf("文件打开错误。\n");
        return;
    }
    printf("姓名  电影名称  票数  放映厅  票价  订单日期\n");
    printf("=========================================\n");

    struct Order currentOrder;

    // 逐行读取文件中的订单信息并输出到控制台
    while (fscanf(fp, "%s %s %d %s %lf %s", currentOrder.custName, currentOrder.movieName, &currentOrder.ticketNum,
                  currentOrder.set, &currentOrder.ticketCost, currentOrder.OrderDate) != EOF) {
        if (strcmp(currentOrder.custName, name) == 0) {
            printf("%s   %s   %d     %s    %.2lf %s\n", currentOrder.custName, currentOrder.movieName,
                   currentOrder.ticketNum, currentOrder.set, currentOrder.ticketCost, currentOrder.OrderDate);
        }
    }
    printf("=========================================\n");
    fclose(fp); // 关闭文件
}

Order *Insert_Order_Doc(Order *ohead,Order *p)  // 将顾客的选择插入链表中
{
// 如果头节点为空，直接将p作为新的头节点
    if (ohead == NULL) {
        return p;
    }

    // 遍历链表找到最后一个节点
    Order *current = ohead;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // 将p插入到链表末尾
    current->next = p;
    p->next = NULL;
    return ohead;
} 
