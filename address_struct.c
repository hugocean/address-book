#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100


struct STU
{
	char n[20];
	int a;
	char s;
	char t[20];
};

int menu()
{
	system("clear");
	int choise;
	printf("***********welcome******************\n");
	printf("*1.input              	**********  \n");
	printf("*2.show list       		**********  \n");
	printf("*3.find name       		**********  \n");
	printf("*4.delete list num 		**********  \n");
	printf("*5.change list menber 	**********  \n");
	printf("*6.sort list menber 	**********  \n");
	printf("*7.exit       	 		**********  \n");
	printf("***********welcome******************\n");
	printf("please input you choise \n");
	scanf("%d",&choise); 
	return choise;
}

int inputlist(struct STU *p[],int j)
{
	int n,i,num;
	
	printf("please input num you want input : \n");
	scanf("%d",&n);
	for(i = j; i < n + j ; i++)
	{
		printf("please input name age sex and phone\n");
		scanf("%s%d %c%s",p[i]->n, &p[i]->a, &p[i]->s, p[i]->t);	
	}
	printf("input finish\n");
	getchar();
	num = j + n;
	return num;
}

int showlist(struct STU *p[],int n)
{
	int i;
	printf("show list \n");
	
	for(i = 0; i < n; i++)
	{
		printf("%s %d %c %s\n",p[i]->n, p[i]->a, p[i]->s, p[i]->t);	
	}
	printf(" \n");
	getchar();
	getchar();
	return 0;
	
}
int findlist(struct STU *p[], int n)
{
	int i;
	char name[20];
	printf("please input name you want find \n");
	scanf("%s",name);
	for(i = 0; i < n; i++)
	{
		if(strcmp(name,p[i]->n) == 0)
		{
			printf("you want find %s informations is: \n" , name);
			printf("%s %d %c %s\n",p[i]->n, p[i]->a, p[i]->s, p[i]->t);	
		}
		
	}
	getchar();
	getchar();
	return 0;

}
int deletelist(struct STU *p[], int n)
{
	int i,j;
	char name[20];
	printf("please input name you want del \n");
	scanf("%s",name);
	for(i = 0; i < n; i++)
	{
		if(strcmp(name,p[i]->n) == 0)
		{
			for(j = i; j < n; j++)
			{
				strcpy(p[j]->n,p[j + 1]->n);
				p[j]->a = p[j + 1]->a;
				p[j]->s = p[j + 1]->s;
				strcpy(p[j]->t,p[j + 1]->t);
			}
			printf("delete finish \n");
			n--;	
		}
		
	}

	getchar();
	getchar();
	return n;
}


int changelist(struct STU *p[], int n)
{
	int i;
	char name[20];
	printf("please input name you want change \n");
	scanf("%s",name);
	for(i = 0; i < n; i++)
	{
		if(strcmp(name,p[i]->n) == 0)
		{
			//strcpy(p[i]->n,'\0');
		//	p[i]->a = 0;
		//	p[i]->s = 0;
		//	strcpy(p[i]->t,'\0');
			
			printf("please input name you want change : \n");
			scanf("%s",p[i]->n);
			printf("please input age you want change : \n");
			scanf("%d",&p[i]->a);
			printf("please input sex you want change : \n");
			getchar();
			scanf("%c",&p[i]->s);
			printf("please input phone you want change : \n");
			scanf("%s",p[i]->t);
		}
		printf("change finish \n");
	}
	getchar();
	getchar();
	return 0;
}

int sortlist(struct STU *p[], int n)
{
	int i,j,m;
	char x;
	char a[20];
	char b[20]; 
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(strcmp(p[j]->n,p[j+1]->n) > 0)
			{
				strcpy(a , p[j+1]->n);
				strcpy(p[j+1]->n , p[j]->n);
				strcpy(p[j]->n , a);
				strcpy(b , p[j+1]->t);
				strcpy(p[j+1]->t , p[j]->t);
				strcpy(p[j]->t , b);
				m=p[j+1]->a;
				p[j+1]->a=p[j]->a;
				p[j]->a = m;
				x=p[j+1]->s;
				p[j+1]->s=p[j]->s;
				p[j]->s = x;
			}		
		}
	}
	getchar();
	getchar();
	printf("sort finished \n");
	return 0;
}


int main()
{
	struct STU *stu[SIZE];
	int i;	
	for(i = 0 ; i < SIZE; i++)
	{
		stu[i] = (struct STU*)malloc(sizeof(struct STU));
	}
	int num=0,n;
	while(1)
	{
		n = menu();
		switch(n)
		{
			case 1:
				num = inputlist(stu,num);
				break;
			
			case 2:
				showlist(stu,num);		
				break;
			
			case 3:
				findlist(stu,num);
				break;
			
			case 4:
				num = deletelist(stu,num);
				break;
			
			case 5:
				changelist(stu,num);
				break;
			
			case 6:
				sortlist(stu,num);
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



