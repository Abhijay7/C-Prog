/* Student Database */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void addrec();
void delrec();
void display();
void modify();
void search();

// defining structure
struct student
{
    char name[30];
    char fname[30];
    char mname[30];
    char gender;
    char address[50];
    char dob[30];
    char num[10];
    float cgpa;
    char course[10];
    int year;
}s;                     // declaring structure variable

// declaring file pointers
FILE *p, *tmp;

// main driver function
void main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    system("cls");


    // opening the file
    p=fopen("sdbms.txt","rb+");

    int choice;
    printf("\t\t\t\t\t\t\t\t\t\tSTUDENT DATABASE SYSTEM\n\n\n");
    printf("Developed By Abhijay Rawat\n\n\n");
    system("pause");

    do
    {
        system("cls");

        if(p==NULL)
        {
            perror("Can't Open File.");
        }

        printf("\t\t\t\t\t\t\t\t\t\tSTUDENT DATABASE\n\n\n");
        printf("Press 1. to Display records.\n\n");
        printf("Press 2. to Add a new record.\n\n");
        printf("Press 3. to View specific student's record.\n\n");
        printf("Press 4. to Modify a record.\n\n");
        printf("Press 5. to Delete a record.\n\n ");
        printf("Press 6. to Exit");

        printf("\n\nEnter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            system("cls");
            display();      //calling display function
            break;

            case 2:
            system("cls");
            addrec();       //calling addrec function
            break;

            case 3:
            system("cls");
            search();       //calling search function
            break;

            case 4:
            system("cls");
            modify();       //calling modify function
            break;

            case 5:
            system("cls");
            delrec();       //calling delrec function
            break;

            case 6:
            fclose(p);      //closing the file
            exit(0);
            break;

            default:
            printf("\nInvalid Choice");
            break;
        }

    }while(1);
}

// function to add record
void addrec()
{
    char c='y';

    while(c=='y')
    {
        system("cls");
        printf("Enter the Name of the student:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.name);

        printf("\nEnter the Name of the student's father:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.fname);

        printf("\nEnter the name of the student's mother:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.mname);

        printf("\nEnter the gender of the student:");
        fflush(stdin);
        scanf("%c",&s.gender);

        printf("\nEnter the address of the student:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.address);

        printf("\nEnter the dob of the student:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.dob);

        printf("\nEnter the contact number of the student:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.num);

        printf("\nEnter the C.G.P.A. of the student:");
        fflush(stdin);
        scanf("%f",&s.cgpa);

        printf("\nEnter the course student is pursuing:");
        fflush(stdin);
        scanf("%[^\n]%*c",s.course);

        printf("\nEnter the student's academic year:");
        fflush(stdin);
        scanf("%d",&s.year);

        fwrite(&s, sizeof(s), 1, p);

        printf("\n\nDo you want to enter the record of another student (y/n):");
        fflush(stdin);
        scanf("%c",&c);
    }
}


// function to display record
void display()
{
    rewind(p);
    printf("Name\t\t\t\t");
    printf("Course\t\t\t");
    printf("Contact\t\t\t\t");
    printf("Gender\t\t\t");
    printf("D.O.B\n");

    while(fread(&s, sizeof(s), 1, p)==1)
    {
        printf("%s\t\t\t%s\t\t\t%s\t\t\t%c\t\t\t%s",s.name,s.course,s.num,s.gender,s.dob);

        printf("\n\n\n");
    }

        system("pause");

}


// function to search record
void search()
{
    system("cls");
    
    char c='y';

    char student[30];

    while(c=='y')
    {
        
        printf("Enter the name of the student whose record you want to search:");
        fflush(stdin);
        scanf("%[^\n]%*c",student);
        rewind(p);

        while(fread(&s, sizeof(s), 1, p)!=feof(p))
        {
            if(strcmp(s.name,student)==0)
            {
                system("cls");
                fseek(p, -sizeof(s), SEEK_CUR);
                printf(" Name of the student:%s\n\n",s.name);
        
                printf("Name of the student's father:%s\n\n",s.fname);
        
                printf("Name of the student's mother:%s\n\n",s.mname);

                printf("Gender of the student:%c\n\n",s.gender);

                printf("Address of the student:%s\n\n",s.address);
        
                printf("DOB of the student:%s\n\n",s.dob);
        
                printf("Contact: %s\n\n",s.num);
        
                printf("Enter the C.G.P.A. of the student:%f\n\n",s.cgpa);

                printf("Enter the course student is pursuing:%s\n\n",s.course);
        
                printf("Enter the student's academic year:%d\n\n",s.year);
                break;
            }


        }

        printf("Do you want to view record of any other student (y/n):");
        fflush(stdin);
        scanf("%c",&c);
    }
}


// function to modify record
void modify()
{
    char c='y';
    char student[30];

    while(c=='y')
    {
        printf("Enter the name of student whose record you want to modify:");
        fflush(stdin);
        scanf("%[^\n]%*c",student);

        rewind(p);

        while(fread(&s, sizeof(s), 1, p)==1)
        {
            if(strcmp(s.name,student)==0)
            {
                printf("Enter the new details:\n\n");  

                printf("Enter the Name of the student:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.name);

                printf("\nEnter the Name of the student's father:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.fname);

                printf("\nEnter the name of the student's mother:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.mname);

                printf("\nEnter the gender of the student:");
                fflush(stdin);
                scanf("%c",&s.gender);

                printf("\nEnter the address of the student:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.address);

                printf("\nEnter the dob of the student:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.dob);

                printf("\nEnter the contact number of the student:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.num);

                printf("\nEnter the C.G.P.A. of the student:");
                fflush(stdin);
                scanf("%f",&s.cgpa);

                printf("\nEnter the course student is pursuing:");
                fflush(stdin);
                scanf("%[^\n]%*c",s.course);

                printf("\nEnter the student's academic year:");
                fflush(stdin);
                scanf("%d",&s.year);

                fseek(p, -sizeof(s), SEEK_CUR);
                fwrite(&s, sizeof(s), 1, p);
                break;
            }
                else
                {  
                    printf("No Such Record Found.");          
                    break;
                }
        }

        printf("\n\nWant to modify another record (y/n):");
        fflush(stdin);
        scanf("%c",&c);
    }

}




// function to delete record
void delrec()
{
    char c='y';
    char student[30];

    while(c=='y')
    {
        printf("Enter the student whose name you want to delete:");
        fflush(stdin);
        scanf("%[^\n]%*c",student);
        

        tmp=fopen("temp.txt","wb");         // opening a temporary file in order to store data in it temporarily
        if(tmp==NULL)
        {
            perror("Error");
        }
        rewind(p);

        while(fread(&s, sizeof(s), 1, p)==1)
        {
            if(strcmp(s.name,student)!=0)
            {
                fwrite(&s, sizeof(s), 1, tmp);
                break;
            }
            

            
        }
        fclose(p);  // closing the file
        fclose(tmp); // closing the temporary file

        remove("sdbms.txt");   //removing the original file
        rename("temp.txt","sdbms.txt");     //renaming the temporary file as original file
        p=fopen("sdbms.txt","rb+");     //re-opening the re-named temporary file as original file 
        if(p==NULL)
        {
            perror("Error");
        }

        printf("Do you want to delete another record (y/n):");
        fflush(stdin);
        scanf("%c",&c);

    }

}