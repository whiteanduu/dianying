#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// �ṹ�嶨�壨��Ӱ����ӳ�����������˿͡�����Ա��
struct Movie {
    char movieNum[20];    // ��Ӱ���
    char movieName[20];  // ��Ӱ����
    double price;        // ��Ӱ����
    char date[20];       // ��Ӱ��ӳ����
    char time[20];       // ��ӳʱ��
    char movieHouse[20];  // ���ڷ�ӳ�����
    char setState[101];  // ��ǰ״̬
    struct Movie *next;
};

struct movieHouse {
    char houseNum[20];    // ��ӳ�����
    char houseName[20];  // ��ӳ������
    int houserow;         // ��ӳ������
    int housecol;        // ��ӳ������
    char houseState [10];  // ��ӳ��״̬open or close 
    struct movieHouse *next;
};

struct Order {
    char custName[20];   // �˿��û���
    char movieName[20];  // ��Ӱ����
    int ticketNum;       // ��������
    char set[40];        // ��ѡ��λ
    double ticketCost;   // �ܼ۸�
    char OrderDate[20];  // ��������
    struct Order *next;
};

struct Customer {
    char CustName[20];  // �˿�����
    char CustCode[20];  // ����
    
};
struct Customer cust[200];

struct Manager {
    char username[20];  // ����Ա�û���
    char password[20];  // ����
    struct Manager *next;
}; 
//2������¼���� 
void loginCustomer(); //�˿͵�¼ �������ע�� // �˿���Ϣ��غ�������
void loginManager();//����Ա��¼ // ����Ա��Ϣ��غ������� 
//����������
Movie *Creat_Movie_Doc();  // ������Ӱ������Ϣ��
movieHouse *Create_House_Doc(); //������ӳ������

//2�������ܺ��� 
void HouseControl();  //��ӳ������
void MovieControl(); //��Ӱ���� 
// ��Ӱ��Ϣ��غ�������
void Printf_Movie_Doc(Movie *mhead);  // �����Ӱ������Ϣ
Movie *Insert_movie_Doc(Movie *mhead);  //�����������ӵ�Ӱ��Ŀ
Movie *Delete_Movie_Doc(Movie *mhead);  //ɾ����Ӱ������Ϣ
void After_Movie_Doc(Movie *mhead);   //�޸ĵ�Ӱ������Ϣ
void InMoviefile(Movie * mhead);   // ����Ӱ��Ϣд��movie.txt �ļ� 
void sortMovie(Movie *mhead);  //  �Ե�Ӱ��Ž���������������
// ��ӳ����Ϣ��غ������� 
movieHouse *Insert_House_Doc(movieHouse *head,movieHouse *p); //��ӳ������Ĳ���   ���ӷ�ӳ������   
void print_House_Doc(movieHouse *head); // �������� �������ӳ����Ϣ
movieHouse* Delete_House_Doc(movieHouse * head,char houseNum[]) ;// ɾ����ӳ������ 
void After_House_Doc(movieHouse *head); // �޸����з�ӳ������Ϣ
void InHouseFile(movieHouse *head);   // �޸ĵ���Ϣд���ļ�
// ������Ϣ��غ�������
void Ordercheck(Order *ohead, char name[]); //�鿴���� 
Order * MovieOrder(Order *ohead, Movie *mhead, char custName[]);//��Ӱ��Ʊ 
Order *Create_Order_Doc(); // ��������������ļ���������
void InorderFile(Order *ohead);//  �������������ļ�
Order *Insert_Order_Doc(Order *ohead,Order *p);  // ���˿͵�ѡ�����������
//�鿴ע������ 
int readCustomer(struct Customer cust[]); 

int main() {
    // ���������
   //��ʼ��һ��˿�����
    strcpy(cust[0].CustName, "zhanghaobo");
    strcpy(cust[0].CustCode, "zhanghaobo");
    // ...  
    int i; 
	int userType;  // 1��ʾ����Ա��2��ʾ�˿�  
	
	onceagain: 
	printf("==================================\n");
	printf("\n");
	printf("       �������¼����              \n");
	printf("\n");
	printf("    1.����Ա\t  2.�û�            \n");
	printf("\n"); 
	printf("==================================\n");
	printf("\n����������Ҫ���еĲ����� ");
	scanf("%d",&userType);
	system ("cls");
	// �����û�����������userType������ͨ���˵����û�ѡ�����Ա��¼���ǹ˿͵�¼
    if (userType == 1) {
        loginManager();
		// ����Ա��¼
        // ���õ�¼����Ա�ĺ��� loginManager�������ݷ���ֵ�����Ƿ�ִ�е�Ӱ��Ϣ�޸ĵȲ���
        // ... 
		again_01:
	printf("==================================\n");
	printf("    1. ��Ӱ��ӳ����Ϣ����        \n"); 
	printf("    2. ��Ӱ������Ϣ����          \n");
	printf("    0. �˳�                      \n");
	printf("==================================\n");
	int choice;
	printf("����������Ҫ���еĲ�����    ");
	scanf("%d",&choice);
	system ("cls");
	switch(choice)
	{
		case 1:
			HouseControl();
			goto again_01;
			break;   // ���з�ӳ���Ĺ���
		case 2:
			MovieControl(); 
			goto again_01;
			break;  // ��Ӱ���ι���
		case 0: exit(0);break;
		default : goto again_01; break;
	}  
} 	else if (userType == 2) {
        loginCustomer();
		// �˿�ѡ���¼����ע�� 
        // ���õ�¼�˿͵ĺ��� loginCustomer��registerCustomer�������ݷ���ֵ�����Ƿ�ִ�ж�Ʊ�Ȳ���
        // ...    
    } else {
        printf("\n\n������������������ѡ��\n");
			Sleep(1000);
			system ("cls");
			goto  onceagain;
    }
	
    // ...

    return 0;
}
//���濪ʼд����
//1��д����Ա��½����
	void loginManager() 
{
    int maxLoginAttempts = 5; // ����¼���Դ���
    int remainingAttempts = maxLoginAttempts;
    
    // �������һ������Ա�˺ź���������飬���԰����������Ա�˺�
    struct Manager adminAccounts[3]; // ������3������Ա�˺�
    strcpy(adminAccounts[0].username, "1111");
    strcpy(adminAccounts[0].password, "1111");
    strcpy(adminAccounts[1].username, "2222");
    strcpy(adminAccounts[1].password, "2222");
    strcpy(adminAccounts[2].username, "3333");
    strcpy(adminAccounts[2].password, "3333");
    
    while (remainingAttempts > 0) {
        char username[20];
        char password[20];
        
        printf("\n���������Ա�˺ţ� ");
        scanf("%s", username);
        printf("\n���������룺 ");
        scanf("%s", password);
        
        // ��֤����Ա�˺ź�����
        int isAdmin = 0; // ����Ƿ��ǹ���Ա
        for (int i = 0; i < 3; i++) { // ������3������Ա�˺�
            if (strcmp(username, adminAccounts[i].username) == 0 &&
                strcmp(password, adminAccounts[i].password) == 0) {
                isAdmin = 1; // ��֤ͨ�����ǹ���Ա
                break;
            }
        }
        
        if (isAdmin) {
            printf("\n��¼�ɹ���\n");
            // ���������ִ�й���Ա����
            break; // �˳���¼ѭ��
        } else {
            remainingAttempts--;
            printf("\n�˺Ż��������ʣ�ೢ�Դ�����%d\n", remainingAttempts);
            if (remainingAttempts > 0) {
                printf("\n����������\n");
            } else {
                printf("\n��¼ʧ�ܣ��ﵽ����Դ����������˳�\n");
                exit(0);
            }
        }
    }
    // ���������ִ����������Ա����...
    
}
	void loginCustomer()
{	
	FILE *fp = fopen("customer.txt", "a+");
	if (fp==NULL)
	{
		printf(" file open error!\n");
		exit (0);
	}
	//��ʼ��һ������ 
	//fprintf(fp, "zhanghaobo zhang\n");//�������һ�λ���д��ȥ��ע�� 
	int custCount = readCustomer(cust);
	char name[20],code[20];
	int choice,inputValid=0;
	again_1:
	printf("\n\n*******************************\n");
	printf(" \n    ��ӭ��������Ӱ��       \n");
	printf("\n");
	printf(" \n  1. ��¼\t  2.ע��          \n");
	printf("\n");
	printf("\n*******************************\n");
	printf("����������ѡ��:   ");
	while (!inputValid)
	{
	scanf("%d", &choice);
	int flag =1,time=0;
	switch (choice) {
		case 1:
				// ִ�е�¼����
				again_2:
				custCount = readCustomer(cust); 
				printf("\n�������û���: ");
    			scanf("%s", name);
    			printf("\n����������: ");
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
	 			printf("�˺Ż�����������������룡 \n");
	 			time++;
	 			printf("�㻹��%d ���������",(5-time));
	 			system("pause"); //  ����ʵ�ֶ�����Ļ�����ڹ۲����ִ�н�� 
	 			system ("cls");
	 			goto again_2;
			}
			else 
			{
				printf("��¼�ɹ���\n");
				system("pause"); //  ����ʵ�ֶ�����Ļ�����ڹ۲����ִ�н�� 
	 			system ("cls");  // �������� 
			}	
				inputValid = 1; // ������Ч���˳�ѭ��
				break;
		case 2:
				// ִ��ע�����
				again_3:
				printf("�����������û�����  ");
				scanf("%s",name);
					for (int i=0;i<custCount;i++)
				{
						if (strcmp(name,cust[i].CustName) == 0)   //  �Ƚ����������Ĵ�С����ͬ������ 
						{
						printf("���û����Ѵ���");
						system("pause"); //  ����ʵ�ֶ�����Ļ�����ڹ۲����ִ�н�� 
	 					system ("cls");
				   		goto  again_3;		 
						}	
				}
					printf("���������룺 ");
					scanf("%s",code);
					strcpy (cust[custCount].CustName,name);
					strcpy (cust[custCount].CustCode,code);	//fscanf  ���ļ��ж�ȡ���ݱ��浽ǰ���������ȥ 
					fprintf(fp,"%s   %s\n",cust[custCount].CustName,cust[custCount].CustCode);
					//   �������ӵ��û����û���������д���ļ���ȥ 
					printf("ע��ɹ���\n");
					system("pause"); //  ����ʵ�ֶ�����Ļ�����ڹ۲����ִ�н�� 
	 				system ("cls");	
					inputValid = 1; // ������Ч���˳�ѭ��
					goto again_2; 
					break;
		default:
			printf("������������������ѡ����Ҫ���������� :  ");
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
	printf("           1.���е�Ӱ��Ʊ            \n");
	printf("           2.�鿴�ҵĶ���            \n");
	printf("           0.�˳�                    \n");
	printf("*************************************\n");
	int select;
	printf("����������ѡ��:  ");
	scanf("%d",&select);
	system ("cls");
 	
	switch (select)
	{
		case 1:
			ohead =MovieOrder(ohead,mhead,name);
			InorderFile(ohead);
			goto again_9;
			break;   // ��Ӱ��Ʊ 
		case 2:
		Ordercheck(ohead,name);
		goto again_9;
		break;   //  �鿴��Ʊ
		case 0:return;break;
	    default:
	    	{
	    		printf("�����������������ѡ�� ");
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
        printf("�ļ���ʧ��!\n");
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
	printf("1. ���ӷ�ӳ�� \n");
	printf("2. ɾ����ӳ�� \n");
	printf("3. �����з�ӳ�����иı�\n");
	printf("4. �鿴��ӳ�� \n");
	printf("0. �˳�\n");
	printf("---------------------------------------\n");
	int choice;
	printf("����������Ҫ���еĲ���:  ");
	scanf("%d",&choice);
	system ("cls");
	switch (choice)
	{
		case 1:
			print_House_Doc(head);
			printf("����������Ҫ���ӵķ�ӳ���ı�ţ����֣��У��У�״̬��\n");
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
			printf("����������ȥ���ķ�ӳ���ı�ţ�");
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
		while (fgetc(fp)!=EOF)  //  �ж��ļ��Ƿ�ĩβ   s�Ƿ�Ϊ�� 
		{
			q = (movieHouse *)malloc (sizeof (movieHouse));
			fscanf(fp,"%s %s %d %d %s",q->houseNum,q->houseName,&q->houserow,&q->housecol,q->houseState);
			p->next = q;    // β�巨 
			q->next =NULL;
			p = p->next;
		 }
	    movieHouse *p2 = (movieHouse *)malloc (sizeof (movieHouse));
	    p2 = head;  //  ɾ�����һ���ڵ� 
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
    movieHouse *current = head->next; // ����ͷ�ڵ�

    printf("��ӳ����Ϣ��\n");
    while (current != NULL) {
        printf("��ӳ����ţ�%s\t", current->houseNum);
        printf("��ӳ�����ƣ�%s\t", current->houseName);
        printf("��λ������%d\t", current->houserow);
        printf("��λ������%d\t", current->housecol);
        printf("��ӳ״̬��%s\t", current->houseState);
        printf("\n");
		current = current->next;
    }
} 
movieHouse *Insert_House_Doc(movieHouse *head, movieHouse *p) {
    // ���ͷ�ڵ�Ϊ�գ�ֱ�ӽ�p��Ϊ�µ�ͷ�ڵ�
    if (head == NULL) {
        return p;
    }

    // ���������ҵ����һ���ڵ�
    movieHouse *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // ��p���뵽����ĩβ
    current->next = p;
    p->next = NULL;

    return head;
}
movieHouse* Delete_House_Doc(movieHouse* head, char houseNum[])
{
    if (head == NULL) {
        printf("��ӳ������Ϊ�գ��޷�ɾ����\n");
        return head;
    }

    movieHouse* current = head;
    movieHouse* previous = NULL;

    // ���������ҵ���ɾ���ķ�ӳ��
    while (current != NULL && strcmp(current->houseNum, houseNum) != 0) {
        previous = current;
        current = current->next;
    }

    // ���δ�ҵ���Ӧ��ӳ��
    if (current == NULL) {
        printf("δ�ҵ���ӳ�����Ϊ %s �ķ�ӳ�����޷�ɾ����\n", houseNum);
        return head;
    }

    // �ҵ��˴�ɾ���ķ�ӳ�������������Ƴ���
    if (previous == NULL) {
        // �����ɾ���ķ�ӳ��������ĵ�һ��Ԫ��
        head = head->next;
    } else {
        previous->next = current->next;
    }

    free(current); // �ͷ��ڴ�

    printf("��ӳ�����Ϊ %s �ķ�ӳ���ѳɹ�ɾ����\n", houseNum);

    return head; // ���ظ��º��ͷָ��
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
    printf("����������Ҫ�޸ĵķ�ӳ�����ƣ� ");
    scanf("%s", name);
    printf("===========================\n");
    printf("1.״̬\n");
    printf("===========================\n");
    printf("\n����������Ҫ�޸ĵ���Ϣ�� ");
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
            printf("����������Ҫ�޸ĳɵ�״̬�� ");
            scanf("%s", newState);
            strcpy(p->houseState, newState);
            break;
        default:
            printf("��Ч��ѡ��\n");
            break;
    }
    InHouseFile(head);
}
void MovieControl()  // ��Ӱ���εĹ��� 
{
	Movie *mhead;
//	mhead = (Movie*)malloc(sizeof(Movie));
//	mhead->next =NULL;
	mhead = Creat_Movie_Doc();
	sortMovie(mhead);
	///  �˴���Ҫһ������ͷ�ڵ������    ͬʱ�����Ӱ�ļ� 
	again_02:
	printf("****************************************\n");
	printf("1.���ӵ�Ӱ\n");
	printf("2.ɾ���Ѵ��ڵĵ�Ӱ\n");
	printf("3.�޸ĵ�Ӱ��Ϣ\n");
	printf("4.�����Ӱ������Ϣ\n");
	printf("0.�˳�\n");
	printf("****************************************\n");
	int choice;
	printf("����������ѡ��\n");
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
		while (fgetc(fp) != EOF) // �ж��ļ��Ƿ�ĩβ s�Ƿ�Ϊ��
		{
			q = (Movie *)malloc(sizeof(Movie));
			fscanf(fp, "%s %s %lf %s %s %s %s", q->movieNum, q->movieName, &q->price, q->date, q->time, q->movieHouse, q->setState);
			p->next = q; // β�巨
			q->next = NULL;
			p = p->next;
		}
		Movie *p2 = (Movie *)malloc(sizeof(Movie));
		p2 = mhead; // ɾ�����һ���ڵ�
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

Movie *Insert_movie_Doc(Movie *mhead) //�����������ӵ�Ӱ��Ŀ
{
	Movie *ptr,*ptr1,*p;
	ptr = (Movie *)malloc (sizeof (Movie));
	ptr = mhead;
	int n;
	printf("\n\n����������Ҫ���ӵĵ�Ӱ������\n ");
	scanf("%d",&n);
 
		while (n)
		{
			p = (Movie *)malloc (sizeof (Movie));
			printf("\n\n�������Ӱ�� ��ţ����֣��۸񣬷�ӳ���ڣ���ӳʱ�䣬��ӳ�ص�,����״̬\n");
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
Movie *Delete_Movie_Doc(Movie *mhead) //ɾ����Ӱ������Ϣ
{
	Movie *ptr1,*ptr2;
	int n;
	printf("\n\n����������Ҫɾ���ĵ�Ӱ����Ŀ��  ");
	scanf("%d",&n);
	ptr1 = (Movie *)malloc (sizeof (Movie));
	ptr2 = (Movie *)malloc (sizeof (Movie));
	ptr1 = mhead;
	ptr2 = mhead->next;
 
	char num[20];
	while(n)
	{
		printf("\n\n����������Ҫɾ���ĵ�Ӱ�ı�ţ�  ");
		scanf("%s",num);
		while(ptr2!=NULL)
		{
			if ((strcmp(ptr2->movieNum,num))==0)
			{
				ptr1->next = ptr2->next;
				free(ptr2);
			}
			ptr1 = ptr2;  // �жϱ�Ų���ͬ��ptr1 �ƶ���ptr2 ��λ�� 
			ptr2= ptr2->next;  //ptr2 �����ƶ�һ����� 
		}
		n--;
	}
	return mhead;
	
}

void After_Movie_Doc(Movie *mhead)   //�޸ĵ�Ӱ������Ϣ
{
	int choice;
	char name[20];
	Movie *ptr,*p;
	movieHouse* ptr1;
	printf("����������Ҫ�޸ĵĵ�Ӱ���ƣ� ");
	scanf("%s",name);
	printf("===========================\n");
	printf("1.�۸�\n");
	printf("2.���ڷ�ӳ�����\n");
	printf("3.��ӳʱ��\n");
	printf("===========================\n");
	printf("\n����������Ҫ�޸ĵ���Ϣ�� ");
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
			printf("����������Ҫ�޸ĳ�Ϊ�ļ۸�");
			scanf("%lf",&price);
			p->price=price;
			break;
		case 2:
			char num[20];
			printf("����������Ҫ�޸ĳɵı�ţ� ");
			scanf("%s",num);
			strcpy(p->movieHouse,num);
		///	memcpy(p->movieHouse,num);
			break;
		case 3:
			char time[20];
			printf("����������Ҫ�ĳɵ�ʱ�䣺 ");
			scanf("%s",time);
			strcpy(p->time,time);
		//	p->time=time[20];
		//	memcpy(p->time,time);
			break;
	}
	InMoviefile(mhead);	
}
void InMoviefile(Movie * mhead)   // ����Ӱ��Ϣд���ļ���ʵ���ļ��ĸ��� 
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
		fprintf(fp,"%s %s %ld %s %s %s %s\n",ptr->movieNum,ptr->movieName,ptr->price,ptr->date,ptr->time,ptr->movieHouse,ptr->setState);
	}
	if (fclose(fp))
	{
		printf("con not close the file\n ");
		exit(0);
	}
}
void sortMovie(Movie *mhead)  // �Ե�Ӱ��Ž������� 
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
    printf("   ��Ӱ��Ϣ\n");
    printf("===========================\n");
    printf("���\t  ����   \t�۸�\t   ����  \tʱ��   ��ӳ��    ״̬\n");
    Movie *ptr;
    for (ptr = mhead->next; ptr != NULL; ptr = ptr->next)
    {
        printf("%s\t%10s\t%.2lf\t%s\t%s\t%s\t%s\n", ptr->movieNum, ptr->movieName, ptr->price, ptr->date, ptr->time, ptr->movieHouse, ptr->setState);
    }
}
Order *Create_Order_Doc() // ��������������ļ���������
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
		while (fgetc(fp)!=EOF)  //  �ж��ļ��Ƿ�ĩβ   s�Ƿ�Ϊ�� 
		{
			q = (Order *)malloc (sizeof (Order));
			fscanf(fp,"%s %s %d %s %lf %s", p1->custName, p1->movieName, &p1->ticketNum, p1->set, &p1->ticketCost, p1->OrderDate);
			p->next = q;    // β�巨 
			q->next =NULL;
			p = p->next;
		 }
	    Order *p2 = (Order *)malloc (sizeof (Order));
	    p2 = ohead;  //  ɾ�����һ���ڵ� 
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
        printf("�޷����ļ���\n");
        return;
    }

    // ��������������ÿ������д�뵽�ļ���
    Order *current = ohead;
    while (current != NULL) {
        fprintf(fp, "%s %s %d %s %.2lf %s\n", current->custName, current->movieName, current->ticketNum, current->set, current->ticketCost, current->OrderDate);
        current = current->next;
    }

    fclose(fp);
}
Order * MovieOrder(Order *ohead, Movie *mhead, char custName[]) {
    // ��ʾ���е�Ӱ
    Printf_Movie_Doc(mhead);

    // �ù˿�ѡ���Ӱ
    char movieNum[20];
    printf("����������Ҫ��Ʊ�ĵ�Ӱ��ţ� ");
    scanf("%s", movieNum);

    // �ڵ�Ӱ�������ҵ��˿�ѡ��ĵ�Ӱ
    Movie *selectedMovie = NULL;
    Movie *currentMovie = mhead->next;
    while (currentMovie != NULL) {
        if (strcmp(currentMovie->movieNum, movieNum) == 0) {
            selectedMovie = currentMovie;
            break;
        }
        currentMovie = currentMovie->next;
    }

    // ���û���ҵ��˿�ѡ��ĵ�Ӱ�����ش���
    if (selectedMovie == NULL) {
        printf("δ�ҵ����Ϊ %s �ĵ�Ӱ��\n", movieNum);
        return ohead;
    }

    // �ù˿����빺Ʊ����
    int ticketNum;
    printf("�����빺Ʊ������ ");
    scanf("%d", &ticketNum);

    // �����µĶ���
    Order *newOrder = (Order *)malloc(sizeof(Order));
    strcpy(newOrder->custName, custName);
    strcpy(newOrder->movieName, selectedMovie->movieName);
    newOrder->ticketNum = ticketNum;
    strcpy(newOrder->set, selectedMovie->movieHouse);
    newOrder->ticketCost = ticketNum * selectedMovie->price;
    strcpy(newOrder->OrderDate, selectedMovie->date);
    // ���µĶ������뵽����������
    ohead = Insert_Order_Doc(ohead, newOrder);

    return ohead;
}	
void Ordercheck(Order *ohead, char name[]) {
    FILE* fp = fopen("order.txt", "r"); // ��ֻ��ģʽ���ļ�
    if (fp == NULL) {
        printf("�ļ��򿪴���\n");
        return;
    }
    printf("����  ��Ӱ����  Ʊ��  ��ӳ��  Ʊ��  ��������\n");
    printf("=========================================\n");

    struct Order currentOrder;

    // ���ж�ȡ�ļ��еĶ�����Ϣ�����������̨
    while (fscanf(fp, "%s %s %d %s %lf %s", currentOrder.custName, currentOrder.movieName, &currentOrder.ticketNum,
                  currentOrder.set, &currentOrder.ticketCost, currentOrder.OrderDate) != EOF) {
        if (strcmp(currentOrder.custName, name) == 0) {
            printf("%s   %s   %d     %s    %.2lf %s\n", currentOrder.custName, currentOrder.movieName,
                   currentOrder.ticketNum, currentOrder.set, currentOrder.ticketCost, currentOrder.OrderDate);
        }
    }
    printf("=========================================\n");
    fclose(fp); // �ر��ļ�
}

Order *Insert_Order_Doc(Order *ohead,Order *p)  // ���˿͵�ѡ�����������
{
// ���ͷ�ڵ�Ϊ�գ�ֱ�ӽ�p��Ϊ�µ�ͷ�ڵ�
    if (ohead == NULL) {
        return p;
    }

    // ���������ҵ����һ���ڵ�
    Order *current = ohead;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // ��p���뵽����ĩβ
    current->next = p;
    p->next = NULL;
    return ohead;
} 
