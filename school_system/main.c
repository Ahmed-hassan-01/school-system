#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#include "read_write.h"




int main()
{
int welcome;
char scan_str[20]={2};

if(read_data("data.bin")==data_readed)
   {
       printf("data readed sucsessfuly\n");
   }
   else if(read_data("data.bin")==data_not_read)
   {
       printf(" data_not_read ");
   }
    else if(read_data("data.bin")==file_not_opened)
    {
         printf("  file_not_opened");
    }
    else if(read_data("data.bin")==file_not_close)
    {
         printf("  file_not_close,");
    }
   printf("%d",students[0].NofBrothers);
welcome=welcome_message();

/*
for(int i=0;i<4;i++)
{

    printf("student name is %s\n",students[i].name);
    printf("student age is %d    academic year%d\n",students[i].age,students[i].academic_year);
     printf("student address is %s\n",students[i].address);



}
*/

 strcpy(students[0].name,"mo");



while(1)

{

    switch(welcome)
    {

        case 1:{print_allstudents();break;}
        case 2:{add_student();break;}
        case 3:{edite_student();break;}
        case 4:{ scanstring(scan_str);  search_student(scan_str,1);break;}
        case 5:{ scanstring(scan_str); if(delete_student(scan_str)){printf("ok");}else{printf("wrong");};break;}
       /* case 6:{sort_studentbyname();break;}
        case 7:{sort_studentbyage();break;}*/
        default:{break;}
cmdClearScreen();
        }


welcome=welcome_message();

}


}
