// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>


// struct contact
// {
// 	char name[100];
// 	char mobileno[100];
// 	char email[200];
// };
#include "cm.h"
struct contact s[100],temp;
void add_contact();
void validate();
// int delete_contact(char *);
// int search_contact();
void display_contact();
void sort();
int choice,i,count=0,j=0,k=0,m,n,c=0;
char temp_name[100],temp_mobile[100],temp_email[100];
char empty[100]="";
int main()
{
	while(1)
	{
		printf("\nCONTACT MANAGEMENT SYSTEM\n1) ADD_CONTACT\n2) DELETE_CONTACT\n3) SEARCH_CONTACT\n4) CONTACT BOOK\n5) EXIT\nEnter Your Choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				add_contact();
				break;	
			}	
			case 2: 
			{
			    printf("Enter the Name\t");
	            scanf("%s",temp_name);
				if(delete_contact(temp_name,i,j,s,empty,c)){
                    printf("\nContact Successfully Deleted!\n");
                }
                else{
                    printf("\nContact Not found!\n");
                }
				break;	
			}
			case 3:
			{
                printf("Enter the Name\t");
	            scanf("%s",temp_name);
				if(search_contact(temp_name,i,j,s)){
                    printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
                }
                else{
                    printf("\n Contact Not Found\n");
                }
				break;	
			}
			case 4:
			{
                display_contact();
				break;	
       			
			}
			case 5:
			{
				exit(1);
				break;	
			}
			default:
			{
				printf("\nPlease Enter the valide choice\n");
				break;	
			}
		}	
	}
}
void validate()
{
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			printf("Name already existed!\n");
			exit(1);	
		}
	}
	if(i==j)
	{
		count=0;
		for(i=0;temp_email[i]!='\0';i++)
		{
			if(temp_email[i]=='@' || temp_email[i]=='.')
			{
				count++;	
			}	
		}	
		if(count!=2)
		{
			printf("Please Enter correct Email\n");
			exit(1);
		}
		else
		{
			if(!(strlen(temp_email)>=5))
			{
				printf("\nPlease Enter correct Email\n");
				exit(1);	
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(strlen(temp_mobile)!=10 || temp_mobile[0]=='0')
		{
			printf("Please Enter the valid Mobile Number");
			exit(1);	
		}
		else if(!(temp_mobile[i]>='0' && temp_mobile[i]<='9'))
		{
			printf("Please Enter the valid Mobile Number");
			exit(1);	
		}	
	}
	for(i=0;i<j;i++)
	{
		if(!strcmp(temp_mobile,s[i].mobileno))
		{
			printf("Phone Number already existed in contact book\n");
			exit(1);	
		}	
	}
}
void add_contact()
{
	printf("Enter the Name\t");
	scanf("%s",temp_name);
	printf("Enter the Mobile Number\t");
	scanf("%s",&temp_mobile);
	printf("Enter the email\t");
	scanf("%s",temp_email);
	validate();
	strcpy(s[j].name,temp_name);
	strcpy(s[j].mobileno,temp_mobile);
	strcpy(s[j].email,temp_email);
	j++;
	c++;
	printf("\n\nContact saved successfully\n");
}
// int delete_contact(char temp_name[100])
// {
// 	// printf("Enter the Name\t");
// 	// scanf("%s",temp_name);
// 	for(i=0;i<j;i++)
// 	{
// 		if(!strcmp(s[i].name,temp_name))
// 		{
// 			strcpy(s[i].name,empty);
// 			strcpy(s[i].mobileno,empty);
// 			strcpy(s[i].email,empty);
// 			// printf("\nContact Successfully Deleted!\n");
// 			c--;
// 			return 1;
// 		}
// 	}
// 	if(i==j)
// 	{
// 		// printf("\nContact Not found!\n");
//         return 0;
// 	}
// }
// int search_contact(char temp_name[100])
// {
// 	// printf("Enter the Name\t");
// 	// scanf("%s",temp_name);
// 	for(i=0;i<j;i++)
// 	{
// 		if(!strcmp(s[i].name,temp_name))
// 		{
// 			// printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
//             return 1;
// 		}	
// 	}
// 	if(i==j)
// 	{
// 		// printf("\n Contact Not Found\n");	
//         return 0;
// 	}
//}
void sort()
{
	for(m=1;m<j;m++)
	{
		for(n=0;n<j-m;n++)
		{
			if(strcmp(s[n].name,s[n+1].name)>0)
			{
				temp=s[n];
				s[n]=s[n+1];
				s[n+1]=temp;
			}
		}	
	}
}
void display_contact()
{
	if(c==0)
	{
		printf("\n\nNo Contact to display_contact!!\n\n");
	}
	else
	{
		sort();
		printf("\n\n-----------Your Contact Book is-------------\n\n");	
		for(i=0;i<j;i++)
		{
			if(strcmp(s[i].name,empty))
			{
				printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
				printf("\n--------------\n");
			}
		}
		printf("\n\n-------THE END--------\n\n");
	}
}