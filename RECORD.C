		 /* program of student managment system */
#include<stdio.h>
#include<string.h>
void insert_record();
void display_record();
void search_record();
void del_record();
struct student
{ int roll;
  char sec[10];
  char name[40];
  int marks;
  float grade;
};
   struct student s;
void main()
{  int ch;
   clrscr();
   while(ch!=7)
   { clrscr();
   printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("\n\\nt*****STUDENT MANAGMENT SYSTEM*****\n");
   printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      printf("\t~*~*~AVALIBLE FUNCTIONALITES~*~*~*\n");
      printf("\t press 1: insert student record\n");
      printf("\t press 2: display student record\n");
      printf("\t press 3: search student record\n");
      printf("\t press 4: delete student record\n");
      printf("\t press 5: exit\n");
      printf("\t ENTER YOUR CHOICE : ");
      scanf("%d",&ch);
      switch(ch)
      {        case 1: clrscr();
	       insert_record();
	       break;
	       case 2: clrscr();
	       display_record();
	       break;
	       case 3: clrscr();
	       search_record();
	       break;
	       case 4:clrscr();
	       del_record();
	       break;
	       case 5: exit(1);
	       default :
	       printf("\n\tWORNG CHOICE ENTERED");
	       }
	       printf("\n\tPRESS any key to countinue ");
	       getch();
       }

 }
void insert_record()
{ FILE *fp;
      fp=fopen("stu.txt","ab+");
      if(fp==NULL)
	   { printf("\n\t\tERROR : FILE NOT FOUND!!!");
	     return;
	   }
      printf("\t_____previous store data______");
      display_record();
      printf("\n\n\t******ENTER NEW STUDENT RECORD****");
      printf("\n\t enter student roll number : ");
      scanf("%d",&s.roll);
      fflush(stdin);
      printf("\n\t enter student name : ");
      scanf("%s",s.name);
      printf("\n\t enter student section : ");
      scanf("%s",s.sec);
      printf("\n\t enter student total number : ");
      scanf("%d",&s.marks);
      printf("\n\t enter student grade : ");
      scanf("%f",&s.grade);
      fwrite(&s,sizeof(s),1,fp);
      {
       printf("\n\t ____STUDENT RECORD INSERT SUCESSFULLY\n");
      }
      fclose(fp);
      printf("\n\t\t UPDATE RECORD !!\n");
      display_record();
}


 void display_record()
 {
 FILE *fp;
 fp=fopen("stu.txt","rb");
  if(fp==NULL)
  { printf("\n\t ERROR : FILE NOT FOUND !!!");
   return;
   }
   printf("\n\t\t ~~~~~STUDENT DETAILS ARE AS FOLLOW~~~~~\n");
   printf("\nROLL.NO\t NAME OF STUDENT \t SECTION \t MARKS \t \t GRADES\n");
   while(fread(&s,sizeof(s),1,fp)==1)
   {   printf("%d\t\t%s\t\t%s \t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
   }
   fclose(fp);
 }

 void search_record()
{  int ro,flag=0;
   FILE *fp;
   fp=fopen("stu.txt","rb");
   if(fp==NULL)
   {  printf("\n\t\t ERROR : FILE NOT FOUND !!!!");
	 return;
   }
   printf("\n\t\t enter roll number which you want to search : ");
   scanf("%d",&ro);
   while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
   {
	    if(s.roll==ro)
	    {  flag=1;
	    printf("\n\n\t SUCESSFULL FOUND ");
	    printf("\nROLL.no\tNAME Of STUDENT\tSECTION \tMARKS\t GRADE");
	    printf("%d\t%s\t\t%s  \t\t%d\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
	    }
   }
   if(flag==0)
   { printf("\n\n\t NO SUCH RECORD FOUND!!!\n");
   }
   fclose(fp);
   }

 void del_record()
 {
     char name[40];
     unsigned flag=0;
     FILE *fp,*ft;
     fp=fopen("stu.txt","rb");
     if(fp==NULL)
     {  printf("\n\n\t ERROR : NOT SUCH FILE FOUND ");
       return;
     }
   printf("\n\t *** previous storee data***");
   display_record();
   printf("\n\n\t ENTER student name Which you want to delete ");
   scanf("%s",name);
   ft=fopen("stu1.txt","ab+");
   while(fread(&s,sizeof(s),1,fp)==1)
   {
       if(strcmp(name,s.name)!=0)
       { printf("\n\t\tRECORD DELETED SUCESSFULLY \n");
	 fwrite(&s,sizeof(s),1,ft);
	 }
	 else flag=1;
    }
    if(flag==0)
    { printf("\n\n\t NO SUCH RECORD FOUND !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("stu.txt");
    rename("stu1.txt","stu.txt");
    printf("\n\n\t UPTADETED RECORD !!!\n");
    display_record();
 }


x