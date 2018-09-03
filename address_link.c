#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 100000
#define FAILURE 100001


struct ADDRESS
{
	char name[20];
	int age;
	struct ADDRESS *next;
};

typedef struct ADDRESS Node;


int menu()
{
	system("clear");
	int choise;
	printf("***********welcome******************\n");
	printf("*1.input              	**********  \n");
	printf("*2.show list       		**********  \n");
	printf("*3.insert name       	**********  \n");
	printf("*4.delete list num 		**********  \n");
	printf("*5.locate list menber 	**********  \n");
	printf("*6.sort list menber 	**********  \n");
	printf("*7.exit       	 		**********  \n");
	printf("***********welcome******************\n");
	printf("please input you choise \n");
	scanf("%d",&choise); 
	return choise;
}

int ListInit(Node **l)
{
	*l = (Node *)malloc(sizeof(Node));
	if(*l == NULL)
	{
		return FAILURE;
	}
	(*l)->next = NULL;
	return SUCCESS;
}

int ListInput(Node **l)
{
	Node *p = *l;
	while(p->next != NULL)
	{
		p = p->next;
	}
	Node *n = (Node *)malloc(sizeof(Node));

	p->next = n;
	printf("please input name age \n");
	scanf("%s%d",n->name,&n->age);
	n->next = NULL;
	return SUCCESS;

}



int ListInsert(Node *l, int n)
{
	int k = 1;
	Node *p = l;
	
	if(NULL == l)
	{
		return FAILURE;
	}
	while(k < n && p != NULL)
	{
		p = p->next;
		k++;
	}

	if(k > n || p == NULL)
	{
		return FAILURE;
	}

	Node *q = (Node *)malloc(sizeof(Node));
	printf("please input name age \n");
	scanf("%s%d",q->name,&q->age);

	q->next = p->next;
	p->next = q;
	
	return SUCCESS;

}



int ListShow(Node *l)
{
	if(l == NULL)
	{
		return FAILURE;
	}
	Node *p = l;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%s %d \n",p->name, p->age);
	}
	getchar();
	getchar();

	return SUCCESS;
}

int ListDelete(Node *l,int p)
{
	int k = 1;
//	char name[20];
	Node *q = l;
	if(l == NULL)
	{
		return FAILURE;	
	}

	while(k < p && q != NULL)
	{
		q = q->next;
		k++;
	}
	if(k > p || q == NULL)
	{
		return FAILURE;
	}

	Node *n = q->next;
	char pname[20];
	strcpy(pname,n->name);
	char page = n->age;
	q->next = n->next;
	free(n);
	printf("menber %s %d delete ",pname, page);

	return SUCCESS;

}

int ListLocate(Node *l)
{
	char pname[20];
	int len = 1;
	if(NULL == l)
	{
		return FAILURE;
	}
	printf("please input name you want locate \n");
	scanf("%s",pname);
	Node *q = l->next;
	
	while(q != NULL)
	{
	printf("************");
		if(strcmp(pname, q->name) == 0)
		{
			printf("the name %s is in list NO%d \n",pname, &len);
			printf("%s %d \n",q->name,&q->age);
			getchar();
			return SUCCESS;
		}
		q = q->next;
		len++;
	}
	return FAILURE;
}


int main()
{
	int i,j,n;
	Node *first = NULL;
	int ret ;

	ret = ListInit(&first);
	if (ret == FAILURE)
	{
		printf("Init list success \n");
	}
	else
	{
		printf("Init failure \n");
	}
	
	while(1)
	{
		n = menu();
		switch(n)
		{
			case 1:
				printf("please in put num you want input \n");	
				scanf("%d",&n);
				for(i = 0; i < n; i++)
				{
					ret = ListInput(&first);	
					if (ret == FAILURE)
					{
						printf("List input failure \n");
					}
					else
					{
						printf("List input success \n");
					}						
				}
				break;
			
			case 2:
				ret = ListShow(first);
				if(ret == SUCCESS)
				{
					printf("this is the linklist \n");
				}
				else
				{
					printf("show failure \n");
				}
				break;
			
			case 3:
				printf("please input num you want insert : \n");
				scanf("%d",&n);
				ret = ListInsert(first,n);	
				if (ret == FAILURE)
				{
					printf("List insert failure \n");
				}
				else
				{
					printf("List insert success \n");
				}					
				break;
			
			case 4:
				printf("please input num you want delete : \n");
				scanf("%d",&n);
				ret = ListDelete(first,n);
				if (ret == FAILURE)
				{
					printf("List delete failure \n");
				}
				else
				{
					printf("List delete success \n");
				}						
				break;
			
			case 5:
				ret = ListLocate(first);
				if (ret == FAILURE)
				{
					printf("Locate list failure \n");
				}
				else
				{
					printf("Locate list success \n");
				}						

				
					
				break;
			
			case 6:
//				sortlist(stu,num);
				break;
			
			case 7:
				exit(0);
				break;
		
			default:
				printf("please input right choise \n");
	
		
		}
		
	}
	
	return 0;

}




