
#include <stdio.h>
#include <stdlib.h>

#include "file.h"

#include "read_write.h"

int write_data(char*filename)
{
    // filename="data.bin";
    FILE *write_file = fopen(filename, "wb"); // write only

    if(write_file==0)
    {
        return file_not_opened;
    }

    if(fwrite(&NofStudents,sizeof(int),1,write_file)!=1)
    {
        return data_not_written;
    }

    if(fwrite(&students,sizeof(std_t),NofStudents,write_file)!=NofStudents)
    {
        return data_not_written;
    }
/*
    for(int i=0; i<NofStudents; i++)
    {
        //if(students[i].NofBrothers>0)
        //{
          //  fwrite(&students[i].NofBrothers,sizeof(int),1,write_file);

            if(fwrite(students[i].brother,sizeof(students[i].brother),1,write_file)!=1)
            {
                return data_not_written;
            }
        //}
    }

*/
    if(fclose(write_file)!=0)
    {
        return file_not_close;
    }

    return data_written;
}



int read_data(char*filename)
{

    FILE *read_file = fopen(filename, "rb"); // write only
    if(read_file==0)
    {
        return file_not_opened;
    }
    if(fread(NofStudents,sizeof(int),1,read_file)!=1)
    {   printf("1\n");
        return data_not_read;
    }

    if(fread(students,sizeof(std_t),NofStudents,read_file)!=NofStudents)
    {   printf("2\n");
        return data_not_read;
    }
/*
    for(int i=0; i<NofStudents; i++)
    {


        if(students[i].NofBrothers>0)
        {
            /*
            if(fread(students[i].NofBrothers,sizeof(int),1,read_file)!=1);
            {
                 return data_not_read;

            }
*/
/*
            if(fread(students[i].brother,sizeof(students[i].brother),1,read_file)!=1)
            {
                return data_not_read;
            }
        }
   }

*/
    if(fclose(read_file)==EOF)
    {
        return file_not_close;
    }

    return data_readed;

}

