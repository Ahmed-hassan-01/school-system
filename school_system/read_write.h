
#define FILENAME "data.bin"


typedef enum{
file_not_opened,
data_not_written,
data_not_read,
file_not_close,
data_readed,
data_written

};
int write_data(char*filename);
int read_data(char*filename);
