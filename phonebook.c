#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
     char name[20];
     long long int mobno;

};




int main()
{
     struct Person p;
     FILE *fp,*fp1;
     char c;
     int ch;
     while(1)
     {
          printf("\n 1. Add contact");
          printf("\n 2. Display list" );
          printf("\n 3. Display number of contact");
          printf("\n 4. delete");
          printf("\n 5. exit");
          printf("\n Enter Your Choice :");
          scanf("%d",&ch);

          switch(ch)
          {
               case 1:
                    fp=fopen("person.txt","a");
                    while (1)
                    {
                         printf("\n Enter Name   :  ");
                         scanf("%s",p.name);
                         fflush(stdin);
                         printf("\n Enter Mobile No.   :  ");
                         scanf("%lld",&p.mobno);
                         fflush(stdin);
                         fwrite(&p,sizeof(p),1,fp);
                         fflush(stdin);
                         printf("\n\n Do You Want to Continue?(Y/N) : ");
                         scanf("%c",&c);
                         if(c=='y' || c=='n')
                              break;
                    }
                    fclose(fp);
                    break;

               case 2:
                    fp=fopen("person.txt","r");
                    while (fread(&p,sizeof(p),1,fp))
                    {
                         while(1)
                         {
                              printf("\n Mobile No : %lld",p.mobno);
                              printf("\n Name      : %s\n ",p.name);
                              break;
                         }
                    }
                    fclose(fp);
                    break;


               case 3:
                {
                 //  struct Person p;
                 FILE *fp;
                 fp=fopen("person.txt","r");
                 fseek(fp,0,SEEK_END);
                 int n=ftell(fp)/sizeof(p);
                 printf("no of contact=%d",n);
                 fclose(fp);
                    break;
                }

               case 4:
{
struct Person p;
long long int mob;
int found=0;

fp=fopen("person.txt","r");
fp1=fopen("temp.txt","w");
printf("Enter phone no to be delete:");
scanf("%lld",&mob);
while(fread(&p,sizeof(struct Person),1,fp))
{
    if(p.mobno==mob)
    {
        found=1;
    }
    else
        fwrite(&p,sizeof(struct Person),1,fp1);
}
fclose(fp);
fclose(fp1);

if(found)
{
fp1=fopen("temp.txt","r");
fp=fopen("person.txt","w");
}
while(fread(&p,sizeof(struct Person),1,fp1))
{
    fwrite(&p,sizeof(struct Person),1,fp);
}
fclose(fp);
fclose(fp1);
break;
}



               case 5:
                {
                    exit(0);
                }

               default:
                  printf("Invalid choice");
          }
     }
     return 0;
}

