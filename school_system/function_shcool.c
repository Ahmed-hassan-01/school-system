
#include <stdio.h>
#include <stdlib.h>
#include "cmd_handler.h"
#include "file.h"
#include "read_write.h"

std_t students[1000]= {0} ;


int NofStudents=0;

//char test=
void scanstring(char*str)
{
    printf("please enter the student name \n");
fflush(stdin);
        gets(str);

}




/*
struct student {

char name[30];
char address[40];
char grade;
int age;
char number[11];
peroson_t father;
peroson_t mother;
int NofBrothers;
peroson_t *brtother;

};
*/

void print_student(int i)
{ int j;
    printf("student name is %s\n",students[i].name);
    printf("academic year is %d\n",students[i].academic_year);
    printf("student age is %d \n",students[i].age);
    printf("student address is %s\n",students[i].address);
    printf("student grade is %c\n",students[i].grade);
    /*data of father's student */
    printf("the name of student's father is %s \n",students[i].father.name);
    printf("the age of student's father is %d \n",students[i].father.age);
    printf("the number of student's father is %s \n",students[i].father.number);


    printf("the name of student's mother is %s \n",students[i].mother.name);
    printf("the age of student's mother is %d \n",students[i].mother.age);
    printf("the number of student's mother is %s \n",students[i].mother.number);

    /*data of  student's brothers */
    for(j=0; j<students[i].NofBrothers; j++)
    {
        printf("the name of the %d brother is %s \n",j+1,students[i].brother[j].name);

        printf("the age of the %d brother is %d \n",j+1,students[i].brother[j].age);

        printf("the number of the %d brother is %s \n",j+1,students[i].brother[j].number);


    }

}




void print_allstudents(void)
{
    int i;
    for(i=0; i<NofStudents; i++)
    {


        print_student(i);
       cmdSetConsoleColour(TEXT_Blue);
        printf("====================================================\n");
        cmdResetConsoleColour();
    }






}


void add_student(void)
{

    fflush(stdin);
    printf("please enter the name of student \n");
    gets(students[NofStudents].name);

    printf("please enter the age of student \n");
    scanf("%d",&students[NofStudents].age);
    fflush(stdin);


    printf("please enter academic year of the student  \n");
    scanf("%d",&students[NofStudents].academic_year);
    fflush(stdin);


    printf("please enter student grade \n");
    scanf("%c",&students[NofStudents].grade);

    fflush(stdin);

    printf("please enter the address of student \n");
    gets(students[NofStudents].address);
    fflush(stdin);

    printf("please enter the name of student's father \n");
    gets(students[NofStudents].father.name);

    printf("please enter the age of student's father \n");
    scanf("%d",&students[NofStudents].father.age);
    fflush(stdin);

    printf("please enter the number of student's father \n");
    gets(students[NofStudents].father.number);

    printf("please enter the name of student's mother \n");
    gets(students[NofStudents].mother.name);

    printf("please enter the age of student's mother \n");
    scanf("%d",&students[NofStudents].mother.age);
    fflush(stdin);

    printf("please enter the number of student's mother \n");
    gets(students[NofStudents].mother.number);


    printf("please enter the number of brother \n");
    scanf("%d",&students[NofStudents].NofBrothers);

    students[NofStudents].brother=malloc(students[NofStudents].NofBrothers*sizeof(peroson_t));

    for(int i=0; i<students[NofStudents].NofBrothers; i++)
    {
        printf("please enter name of the %d brother \n",i+1);
        fflush(stdin);
        gets(students[NofStudents].brother[i].name);
        fflush(stdin);
        printf("please enter age of the %d brother \n",i+1);
        scanf("%d",&students[NofStudents].brother[i].age);
        fflush(stdin);
        printf("please enter number of the %d brother \n",i+1);
        gets(students[NofStudents].brother[i].number);

    }
     NofStudents++;
     switch(write_data(FILENAME))
     {
     case data_written: {printf("student saved\n");break;}
     case data_not_written:{printf("file not opened\n");break;}
     case file_not_close:{printf("file not close\n");break;}
     case file_not_opened:{printf("file not opened\n");break;}
     default :break;

     }

}



int string_compare(char*s1,char*s2)
{
    int i;

    for(i=0; s1[i]&&s2[i]; i++)
    {
        if(((s1[i])>=(0+'a'))&&(s1[i]<=(0+'z')))
        {

        }
        else if(((s1[i])<=(0+'a'))&&(s1[i]>=(0+'z')))
        {
            s1[i]=(s1[i]-'A'+'a');
        }

        if(((s2[i])>=(0+'a'))&&(s2[i]<=(0+'z')))
        {

        }
        else if(((s2[i])<=(0+'a'))&&(s2[i]>=(0+'z')))
        {
            s2[i]=(s2[i]-'A'+'a');
        }

        if(s1[i]!=s2[i])
        {
            return -1;
        }

    }

    return 0;
}


int search_student(char* student_name,int PrintOrNot)
{
    int i,res;
    for(i=0; i<NofStudents; i++)
    {
        res=string_compare(student_name,students[i].name);
        if(res==-1)
        {   //not found go to the next student

            continue;
        }
        else
        {   //found

            if(PrintOrNot==1)
            {
                print_student(i);
            }

            return i;
        }

    }
if(PrintOrNot==1)
{   cmdSetConsoleColour(TEXT_Red);
    printf("wrong there is no student name %s \n",student_name);
    cmdResetConsoleColour();
}
    return -1;
}


int search_student_brothers(char* brother_name,int index)
{
    int i,res;
    for(i=0; i<students[index].NofBrothers; i++)
    {
        res=string_compare(brother_name,students[index].brother[i].name);
        if(res==1)
        {
            continue;
        }
        else
        {
            return i;
        }

    }

    return -1;
}




void edite_student(void)
{
    int res,edit, index;char name[20];
    printf("please enter the name of the student to edit his data\n");
    /*make array of character to scan the string(name) from user*/
    fflush(stdin);
    gets(name);

    /*search for name to get his index */
    index= search_student(name,0);

    if(index==-1)
    {  cmdSetConsoleColour(TEXT_Red);
        printf("there is no student's name %s in school \n",name);
         cmdResetConsoleColour();
        edite_student();
    }

    printf("please enter:\n 1 to change his name\n 2 to change his age \n 3 to change his address \n 4 to change academic year \n 5 to change his number \n ");
    printf("6 to edit the data of student's father \n 7 to to edit the data of student's mother \n 8 to edit the data of student's brothers");

    scanf("%d",&edit);

    switch(edit)
    {
    case 1:
    {
        printf("enter the new name ");
        fflush(stdin);
        gets(students[index].name);
        printf("saved the new name \n");
        break;
    };
    case 2:
    {
        printf("enter the new age");
        scanf("%d",&students[index].age);
         printf("saved the new age \n");
        break;
    };
    case 3:
    {

        printf("enter the new address");
        fflush(stdin);
        gets(students[index].address);
         printf("saved the new address \n");
        break;
    };
    case 4:
    {
        printf("enter the new academic year");
        scanf("%d",&students[index].academic_year);
        printf("saved the new academic year \n");
        break;
    };
    case 5:
    {
        printf("enter the new number");
        gets(students[index].number);
        printf("saved the new number \n");
        break;
    };
    default:
    {
        break;
    };



    }

    if(edit==6)
    {
        printf("please enter:\n 1 to change his name\n 2 to change his age \n 3 to change his number\n");
        scanf("%d",&edit);
        switch(edit)
        {
        case 1:
        {
            printf("enter the new name of father");
            gets(students[index].father.name);
            return;
            break;
        };
        case 2:
        {
            printf("enter the new age of father ");
            scanf("%d",&students[index].father.age);
            return;
            break;
        };

        case 3:
        {
            printf("enter the new number of father");
            gets(students[index].father.number);
            return;
            break;
        };
        }


    }

    if(edit==7)
    {
        printf("please enter:\n 1 to change her name\n 2 to change her age \n 3 to change her number\n");
        scanf("%d",&edit);
        switch(edit)
        {
        case 1:
        {
            printf("enter the new name of mother");
            gets(students[index].mother.name);
            return;

            break;
        };
        case 2:
        {
            printf("enter the new age of mother ");
            scanf("%d",&students[index].mother.age);
            return;

            break;
        };

        case 3:
        {
            printf("enter the new number of mother");
            gets(students[index].mother.number);
            return;
            break;
        };

        }

    }


    if(edit==8)
    {
        char brother_name[20];
        printf("please enter the name of the brother you would to edit\n");
        fflush(stdin);
        gets(brother_name);
        res=search_student_brothers(brother_name,index);
        if(res==-1)
        {
            cmdSetConsoleColour(TEXT_Red);
            printf("wrong there is no brother's name of %s is %s \n",students[index].name,brother_name);
             cmdResetConsoleColour();
            return;
        }

        printf("please enter:\n 1 to change his name\n 2 to change his age \n 3 to change his number\n");
        scanf("%d",&edit);

        switch(edit)
        {
        case 1:
        {
            printf("enter the new name of brother");
            gets(students[index].brother[res].name);
            return;

            break;
        };
        case 2:
        {
            printf("enter the new age of brother ");
            scanf("%d",&students[index].brother[res].age);
            return;

            break;
        };

        case 3:
        {
            printf("enter the new number of brother");
            gets(students[index].brother[res].number);
            return;
            break;
        };

        }

    }

    write_data(FILENAME);

}


int welcome_message(void)
{
    printf("please enter 1 to print all students\n");
    printf("please enter 2 to add student\n");
    printf("please enter 3 to edite student\n");
    printf("please enter 4 to search student\n");
    printf("please enter 5 to delete student\n");
    printf("please enter 6 to sort student by name\n");
    printf("please enter 7 to sort student by age \n");
    int x;
    scanf("%d",&x);
    return x;



}

int delete_student(char*student)
{ int student_index,i;
std_t st_temp;
 student_index = search_student(student,0);
if(student_index==0)
{
    printf("there is no name of student %s\n",student);
    return 0;
}

    for(i=student_index;i<NofStudents;i++)
    {
       st_temp=students[i];
       students[i]=students[i+1];
       students[i+1]=st_temp;

    }
    NofStudents--;


if(write_data(FILENAME))
{
    printf("the student deleted successfully");
}

return 1;

}




