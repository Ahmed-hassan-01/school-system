
extern int NofStudents;
void print_allstudents(void);
void add_student(void);
void print_allstudents(void);
int search_student(char* student_name,int PrintOrNot);
void edite_student(void);
int welcome_message(void);
void print_student(int i);
void scanstring(char*str);








typedef struct peroson_t{

char name[30];
char number[11];
int age;

}peroson_t;



typedef struct std_t {

char name[30];
char address[40];
char grade;
int academic_year;
int age;
char number[11];
 peroson_t father;
 peroson_t mother;
int NofBrothers;
 peroson_t *brother;

}std_t;
extern  std_t students[1000] ;
