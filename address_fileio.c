#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUFF_SIZE

#define BUFF_SIZE 1024
#endif

struct ADDRESS
{
	char name[15];
	char unit[15];
	char phone[15];
};
/*int count()
{
	
	return num;
}
*/

int main(int argc, char *argv[])
{

	int n,i;
	struct ADDRESS add[50];
	if(argc < 2 || strcmp(argv[1],"--help") == 0 )
	{
		printf(" Usage: \n "); 
		printf(" \"-input\":add informations to list \n ");
		printf(" \"-show\": show address list \n ");
		printf(" \"-del \":delete name information you want \n ");
		printf(" \"-sort\":sort the list \n ");
		printf(" \"-find\":find a list name you want \n  ");
	
	}
	if(strcmp(argv[1],"-input") == 0)
	{
		FILE * fp;
		printf("please input record num you want to input \n");
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			printf("input a name a unit a phonenum\n");
			scanf("%s%s%s",add[i].name, add[i].unit, add[i].phone);
		}
		fp = fopen("./tfile","a");
		
		for(i = 0; i < n; i++)
		{
			fprintf(fp, "%s%15s%15s \n",add[i].name , add[i].unit , add[i].phone);
		}
		fclose(fp);

	
	
	}

	
	if(strcmp(argv[1],"-show") == 0)
	{

		FILE * fp;
		int len,num=0;
		char buffer[100];
		char flag;
		
		fp = fopen("./tfile","r");
		while(!feof(fp))
		{
			flag = fgetc(fp);
			if(flag == '\n')
			{
				num++;	
			}
		}
		printf("show address list \n");
		fseek(fp , 0L , SEEK_END);
		len = ftell(fp);
		rewind(fp);
		fread(buffer , 1 , len ,fp);
		printf("%s",buffer);
		fclose(fp);

		printf("this list has %d lines informaions! \n",num);	
	}
	
	if(strcmp(argv[1],"-sort") == 0)
	{
		struct ADDRESS *v = NULL;
		int n = 0,num = 0;
		int i,j, x;
		char flag;
		char a[15];
		char b[15]; 
		char c[15];
		
		FILE *fp = fopen("./tfile","r");
		while(!feof(fp))
		{
			flag = fgetc(fp);
			if(flag == '\n')
			{
				num++;	
			}
		}
		n = num;

		fseek(fp,0,SEEK_SET);

		v = (struct ADDRESS*)malloc(sizeof(*v) * n);

		for(i = 0; i < n; i++)
		{
			if(fscanf(fp,"%15s%15s%15s", &v[i].name, &v[i].unit, &v[i].phone) != 3)
			{
				break;
			}
		}
	
		fclose(fp);
		
		for(i = 0; i < n - 1; i++)
		{
			for(j = 0; j < n - i - 1; j++)
			{
				if(strcmp(v[j].name,v[j+1].name) > 0)
				{
					strcpy(a , v[j+1].name);
					strcpy(v[j+1].name , v[j].name);
					strcpy(v[j].name , a);
					strcpy(b , v[j+1].unit);
					strcpy(v[j+1].unit , v[j].unit);
					strcpy(v[j].unit , b);
					strcpy(c , v[j+1].phone);
					strcpy(v[j+1].phone , v[j].phone);
					strcpy(v[j].phone , c);
				}		
			}
		}
		
		FILE *fq = fopen("./tfile","w+");

		for(i = 0; i < n; i++)
		{
			printf("%s%15s%15s\n",v[i].name, v[i].unit, v[i].phone);
		}
		for(i = 0; i < n; i++)
		{
			fprintf(fq,"%s%15s%15s\n",v[i].name, v[i].unit, v[i].phone);
		}
		fclose(fq);
		free(v);
		printf("this list has %d lines informaions! \n",num);	
		
	}
	if(strcmp(argv[1],"-find") == 0)
	{
		struct ADDRESS *v = NULL;
		int n = 0,num = 0;
		int i,j, x;
		char flag;
		char a[15];

		FILE *fp = fopen("./tfile","r");
		while(!feof(fp))
		{
			flag = fgetc(fp);
			if(flag == '\n')
			{
				num++;	
			}
		}
		n = num;

		fseek(fp,0,SEEK_SET);

		v = (struct ADDRESS*)malloc(sizeof(*v) * n);

		for(i = 0; i < n; i++)
		{
			if(fscanf(fp,"%15s%15s%15s", &v[i].name, &v[i].unit, &v[i].phone) != 3)
			{
				break;
			}
		}
	
		fclose(fp);
	
		printf("please input name you want find : \n");
		scanf("%s",a);

		for(i = 0; i < n; i++)
		{
			if(strcmp(v[i].name, a) == 0)
			{
				printf("%s%15s%15s\n",v[i].name, v[i].unit, v[i].phone);
				printf("this information is in line: %d \n",i + 1);
			}
			else
			{
				printf("this list do not has this name information \n");
			}
		}
		free(v);
	
	
		printf("this list has %d lines informaions! \n",num);	
	}
	


	if(strcmp(argv[1],"-del") == 0)
	{
		struct ADDRESS *v = NULL;
		int n = 0,num = 0;
		int i,j, x;
		char flag;

		printf("please input record num you want to delete \n");
		scanf("%d",&x);

		
		
		FILE *fp = fopen("./tfile","r");
		fseek(fp,0,SEEK_SET);
		while(!feof(fp))
		{
			flag = fgetc(fp);
			if(flag == '\n')
			{
				num++;	
			}
		}
		n = num;

		fseek(fp,0,SEEK_SET);

		v = (struct ADDRESS*)malloc(sizeof(*v) * n);

		for(i = 0; i < n; i++)
		{
			if(fscanf(fp,"%15s%15s%15s", &v[i].name, &v[i].unit, &v[i].phone) != 3)
			{
				break;
			}
		}
		fclose(fp);
		
		for(j = x; j < n; j++)
		{
			strcpy(v[j - 1].name,v[j].name);
			strcpy(v[j - 1].unit,v[j].unit);
			strcpy(v[j - 1].phone,v[j].phone);
		}
		
		FILE *fq = fopen("./tfile","w+");
		for(i = 0; i < n - 1 ; i++)
		{
			printf("%s%15s%15s\n",v[i].name, v[i].unit, v[i].phone);
		}
		for(i = 0; i < n - 1 ; i++)
		{
			fprintf(fq,"%s%15s%15s\n",v[i].name, v[i].unit, v[i].phone);
		}
		fclose(fq);
		free(v);
		
		printf("this list has %d lines informaions! \n",num - 1);	
	}
}

