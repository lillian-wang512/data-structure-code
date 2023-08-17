#include "student.h"
#include <stdlib.h>
 
int choose;/*���ڽ����û���ѡ��*/
STUDENT *headLink;/*�����ͷָ��*/
 
/************************************
�������ܣ����ļ��ж�ѧ����Ϣ��������
************************************/
 
void ReadInfoFormFile(void)
{
    FILE *fp;
    STUDENT *p;
    fp=fopen("student.txt","r");
    
    if(!fp)
    {
        printf("�ļ������ڣ������Ѵ������ļ�\n");
        FILE *fp=fopen("student.txt", "a+");
        return;
    }
    p=MallocNode();
    while(fscanf(fp,"%s%s%f%f%f",p->studentNumber,p->studentName,&(p->mark1),&(p->mark2),&(p->mark3))>0)
    {
        InsertOneNode(p);
        p=MallocNode();
    }
    fclose(fp);
}
 
 
/************************************
�������ܣ���ʾ�˵��������û�������
�����Ӧ�Ĺ���
************************************/
 
void DesplayMenu(void)
{
    STUDENT *p;
    printf("                     ##############ѧ���ɼ�����ϵͳ###############\n");
    printf("                     *********************************************\n");
    printf("                     ***************��ѡ�����Ĳ���****************\n");
    printf("                     #         1 ����ѧ��                      #\n");
    printf("                     #         2 ��������ѯ                    #\n");
    printf("                     #         3 ���ѧ���ɼ���                #\n");
    printf("                     #         4 ɾ��ѧ��                      #\n");
    printf("                     #         5 �������޸�ѧ���ɼ�            #\n");
    printf("                     #         6 ��ѧ���޸�ѧ���ɼ�            #\n");
    printf("                     #         7 ��ƽ���ɼ��������ѧ����Ϣ  #\n");
    printf("                     #         8 ��ʾѧ���ɼ�������/������   #\n");
    printf("                     #         9 ������Ϣ���ļ���              #\n");
    printf("                     #         10 �����ļ�                     #\n");
    printf("                     #         11 �˳�����                      #\n");
    printf("                     #         12 �ָ�������                     #\n");
    printf("                     *********************************************\n");
    printf("                     #############################################\n");
 
    scanf("%d",&choose);/*ȡ���û���ѡ��*/
    switch(choose)
    {
    case 1:
        p=MallocNode();/*������һ���½��*/
        GetInformation(p);/*Ҫ���û�������Ϣ���½����*/
        InsertOneNode(p);/*���½��ӵ�������*/
 
        break;
    case 2:
        DesplayInfoBystudentName();
 
        break;
    case 3:
        OutputInformation();/*��ʾ����ѧ������Ϣ*/
 
        break;
    case 4:
        DeleteNodeBystudentNumber();/*�����û������ѧ��ɾ����ѧ��*/
        break;
    case 5:
        ChangeMarkByName();/*�����û�����������޸�ѧ���ɼ�*/
        break;
    case 6:
        ChangeMarkByNumber();/*�����û������ѧ���޸�ѧ���ɼ�*/
        break;
    case 7:
        CompositorByTotalMark();/*��ƽ���ɼ�����*/
        break;
    case 8:
        DesplayMarkSegment();/*��ʾѧ���ɼ�*/
        break;
    case 9:
        SaveLinkToFile();/*��������*/
        break;
    case 10:
    	Backupfiles();//�����ļ� 
    	break;
    case 11:
        SaveLinkToFile();/*�������ݺ����˳�*/
 
        free(headLink);
        //exit(0);
        break;
    case 12:
    	void Reserve();
    	break;
    
    default:
        break;
    }
    if(choose!=11)
    DesplayMenu();/*�ݹ����*/
}
/************************************
�������ܣ����������ͷ
************************************/
void CreateHeadLink(void)
{
    STUDENT *p;
    p=(STUDENT*)malloc(sizeof(STUDENT));
    headLink=p;
    p->next=NULL;
}

/************************************
�������ܣ�����һ���½�㣬�������ʼ��
************************************/
 
 
STUDENT *MallocNode(void)
{
    STUDENT *p;
    int i;
    p=(STUDENT*)malloc(sizeof(STUDENT));
    if(p==NULL)
        return NULL;
    for(i=0; i<10; i++)
        p->studentNumber[i]='\0';
    for(i=0; i<20; i++)
        p->studentName[i]='\0';
    for(i=0; i<20; i++)
        p->mark1=0.0;
    p->mark2=0.0;
    p->mark3=0.0;
    p->next=NULL;
    return p;
}
 
/************************************
�������ܣ�ȡ���û������ѧ����Ϣ
************************************/
 
void GetInformation(STUDENT *t)
{
    printf("������ѧ��ѧ�ţ�\n");
    scanf("%s",t->studentNumber);
    printf("������ѧ��������\n");
    scanf("%s",t->studentName);
    printf("�������1�ųɼ���\n");
    scanf("%f",&(t->mark1));
    printf("�������2�ųɼ���\n");
    scanf("%f",&(t->mark2));
    printf("�������3�ųɼ���\n");
    scanf("%f",&(t->mark3));
}
 
/************************************
�������ܣ�������Ľ�β������һ�����
************************************/
 
void InsertOneNode(STUDENT *t)
{
    STUDENT *p;
    p=headLink;
    while(p->next)
    {
        p=p->next;
    }
    p->next=t;
}
 
 
 
 
/************************************
�������ܣ������û������ѧ������
      ��ʾ��ѧ������Ϣ
************************************/
 
 
void DesplayInfoBystudentName(void)
{
    STUDENT *p;
    char studentName[20];
    char flag=0;
    p=headLink->next;
    printf("������ѧ��������\n");
    scanf("%s",studentName);
    while(p)
    {
        if(strcmp(p->studentName,studentName)==0)
        {
            printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
            DesplayOneNode(p);
            flag=1;
            break;
        }
        p=p->next;
    }
    if(!flag)
        printf("�Բ��𣬲����ڸ�ѧ��\n",studentName);
}

/************************************
�������ܣ����һ��������Ϣ
************************************/
void DesplayOneNode(STUDENT *t)
{
    printf("%s\t",t->studentNumber);
    printf("%s\t",t->studentName);
    printf("%.2f\t",t->mark1);
    printf("%.2f\t",t->mark2);
    printf("%.2f\t",t->mark3);
    printf("%.2f\t",t->mark1+t->mark2+t->mark3);
    printf("%.2f\t\n",(t->mark1+t->mark2+t->mark3)/3);
}

 
/************************************
�������ܣ������û������ѧ��
         ɾ����ѧ��
************************************/
 
void DeleteNodeBystudentNumber(void)
{
    char studentNumber[10];
    STUDENT *p,*q;
    char flag=0;
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s",studentNumber);
    p=headLink;
    q=headLink->next;
    while(q)
    {
        if(strcmp(q->studentNumber,studentNumber)==0)
        {
            p->next=q->next;
            free(q);
            flag=1;
            break;
 
        }
        p=p->next;
        q=q->next;
    }
    if(!flag)
    {
        printf("�����ڸ�ѧ�ŵ�ѧ��\n");
        return;
    }
    printf("�ɹ�ɾ��\n");
}
 
 
 
/************************************
�������ܣ���ʾ����ѧ������Ϣ
************************************/
 
void OutputInformation(void)
{
    STUDENT *p;
    p=headLink->next;
    float m1=0;
    float m2=0;
    float m3=0;
    int n=0;
    if(p==NULL)
    {
        printf("����û��ѧ����Ϣ����������ѧ����Ϣ\n\n");
        return;
    }
    printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
    while(p)
    {
        DesplayOneNode(p);
        m1+=p->mark1;
        m2+=p->mark2;
        m3+=p->mark3;
        p=p->next;
        n++;
    }
    printf("�༶�ɼ�\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\n\n",m1/n,m2/n,m3/n,m1+m2+m3,(m1/n+m2/n+m3/n)/n);
}

/************************************
�������ܣ��������������
         �޸ĳɼ�
************************************/
void ChangeMarkByName(void)
{
    STUDENT *p;
    int a;
    char studentName[20];
    char flag=0;
    float mark1,mark2,mark3;
    p=headLink->next;
    printf("������ѧ��������\n");
    scanf("%s",studentName);
    while(p)
    {
        if(strcmp(p->studentName,studentName)==0)
        {
 
            printf("�������µĵ�1�ųɼ���\n");
            scanf("%f",&mark1);
            printf("�������µĵ�2�ųɼ���\n");
            scanf("%f",&mark2);
            printf("�������µĵ�3�ųɼ���\n");
            scanf("%f",&mark3);
            p->mark1=mark1;
            p->mark2=mark2;
            p->mark3=mark3;
            flag=1;
            printf("�޸ĳɹ�\n");
            break;
 
        }
        p=p->next;
    }
    if(!flag)
        printf("�Բ��𣬲����ڸ�ѧ��\n",&a,studentName);
}
 
 
/************************************
�������ܣ����������ѧ��
         �޸ĳɼ�
************************************/
 
void ChangeMarkByNumber(void)
{
    STUDENT *p;
    int b;
    char studentNumber[20];
    char flag=0;
    float mark1,mark2,mark3;
    p=headLink->next;
    printf("������ѧ��ѧ�ţ�\n");
    scanf("%s",studentNumber);
    while(p)
    {
        if(strcmp(p->studentNumber,studentNumber)==0)
        {
            printf("�������µĵ�1�ųɼ���\n");
            scanf("%f",&mark1);
            printf("�������µĵ�2�ųɼ���\n");
            scanf("%f",&mark2);
            printf("�������µĵ�3�ųɼ���\n");
            scanf("%f",&mark3);
            p->mark1=mark1;
            p->mark2=mark2;
            p->mark3=mark3;
            flag=1;
            printf("�޸ĳɹ�\n");
            break;
 
        }
        p=p->next;
    }
    if(!flag)
        printf("�Բ��𣬲�����ѧ��Ϊ %s ��ѧ��\n",studentNumber);
}
/************************************
�������ܣ������������ݵ��ļ���
************************************/
void SaveLinkToFile(void)
{
    STUDENT *p;
    FILE *fp;
    p=headLink->next;
    if(p==NULL)
    {
        printf("����û��ѧ����Ϣ����������ѧ����Ϣ\n\n");
        return;
    }
    fp=fopen("student.txt","w+");
    if(!fp)
    {
        printf("�ļ�������\n");
        return;
    }
    while(p)
    {
        fprintf(fp,"%s %s %f %f %f\n",p->studentNumber,p->studentName,p->mark1,p->mark2,p->mark3);
        p=p->next;
    }
    fclose(fp);
 
}
 
/************************************
�������ܣ�������ѧ���ɼ�
************************************/
void DesplayMarkSegment(void)
{
	system("color f1");
    STUDENT *p;
    int count=0;
    int choice;
    printf("��ѡ���ѯ����1������ 2��������");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		p=headLink->next;
            printf("60������(����)��ѧ���ɼ����£�\n");
            printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
            while(p)
            {
            if((60<=((int)(p->mark1)))&&(60<=((int)(p->mark2)))&&(60<=((int)(p->mark3))))//ÿһ�ƶ�������϶�Ϊ���� 
            {
            count++;
            DesplayOneNode(p);
            }
            p=p->next;
            }
            printf("�����ѧ��һ����%d��\n",count);
            break;
    	case 2:
    		p=headLink->next;
            printf("60������(������)��ѧ���ɼ����£�\n");
            printf("ѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
            while(p)
            {
            if((6>((int)(p->mark1/10)))||(6>((int)(p->mark2/10)))||(6>((int)(p->mark3/10))))/*ֻҪ��һ�Ʋ��������Ϊ����������*/
            {
             count++;
             DesplayOneNode(p);
            }
            p=p->next;
            }
            printf("�������ѧ��һ����%d��\n",count);
            break;
	}
 
    
}
 
 
 
/************************************
�������ܣ���ƽ���ɼ�����
************************************/
 
void CompositorByTotalMark(void)
{
    STUDENT exchange,*r,*p,*q;
    r=headLink->next;
    if(r==NULL)
    {
        printf("���ڻ�ûѧ����Ϣ,��������ѧ����Ϣ\n");
        return;
    }
    while(r)/*����whileѭ��ʵ������*/
    {
        p=r;
        q=r->next;
        while(q)
        {
            if((q->mark1+q->mark2+q->mark3)>(p->mark1+p->mark2+p->mark3))
            {
 
                strcpy(exchange.studentNumber,q->studentNumber);/*�ȸ���q�����Ϣ��exchange*/
                strcpy(exchange.studentName,q->studentName);
                exchange.mark1=q->mark1;
                exchange.mark2=q->mark2;
                exchange.mark3=q->mark3;
 
                strcpy(q->studentNumber,p->studentNumber);/*�ٸ���p�����Ϣ��q*/
                strcpy(q->studentName,p->studentName);
                q->mark1=p->mark1;
                q->mark2=p->mark3;
                q->mark3=p->mark3;
                strcpy(p->studentNumber,exchange.studentNumber);/*�����exchange�����Ϣ��p*/
                strcpy(p->studentName,exchange.studentName);
                p->mark1=exchange.mark1;
                p->mark2=exchange.mark2;
                p->mark3=exchange.mark3;
            }
            q=q->next;
        }
        r=r->next;
    }
    OutputInformation();
}
//�����ļ� 
void Backupfiles(void)
{
    FILE *fp = fopen("student.txt", "r"),
    *fp1 = fopen("backups.txt", "w");
    if (!fp && !fp1)
    {
        //��ʧ�����������ԭ��
        printf("fopen error");
        
    }
    //����һ���ַ���������ļ�����
    char arr[100] = {0};
    //ʹ��whileѭ�����ļ���д�ļ�
    while (1)
    {
        //���շ���ֵ
        int ret = fread(arr, 1, 1, fp);
        //д��ȡ�����ݵ��µ��ļ���
        fwrite(arr, 1, 1, fp1);
        //�ж��Ƿ��ļ�ĩβ ���ļ�ĩβ����0
        if (ret == 0)
        {
            break;
        }
    }
    //�ر��ļ�
    fclose(fp);
    fclose(fp1);
}

void Reserve(void)
{
	FILE *fp;
    STUDENT *p;
	fp=fopen("backups.txt","r");
	p=MallocNode();
    while(fscanf(fp,"%s%s%f%f%f",p->studentNumber,p->studentName,&(p->mark1),&(p->mark2),&(p->mark3))>0)
    {
        InsertOneNode(p);
        p=MallocNode();
    }
    fclose(fp);
}

#include "student.h"
int main()
{   system("color f4");
    CreateHeadLink();
    ReadInfoFormFile();
 
    DesplayMenu();
    return 0;
}


