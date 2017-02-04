/*#######################################################*/
/*______________________                                 */
/*Written by Aziz OKAY on 1 june 2014                    */
/*                                                       */
/*Description                                            */
/*_______________                                        */
/*Student Automation                                     */
/*                                                       */
/*                                                       */
/*İnputs                                                 */
/*   initial files                                       */
/*                                                       */
/*Outputs                                                */
/*some process about student and instructor              */
/*#######################################################*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*#define DEBUG*/

/******* define of function *********/
typedef struct{
	char *ID;
	char *name;
	char *instructor;
	char *prerequisities;
	char is_open;				/*struct that includes course elements*/
	char is_add_remove_open;
	char stdntID[11];
	int grade;
	char situation;
	
}course_t;


typedef struct{
	char *TCNo;
	char *name;
	char *surname;			/*struct that includes student elements*/
	char *studentNo;
	char *startYear;
}student_t;

typedef struct{
	char *TCNo;
	char *name;				/*struct that includes instructor elements*/
	char *surname;
}instructor_t;

typedef struct{
	char *ID;
	char *userType;
	char *userName;			/*struct that includes user elements*/
	char *passWord;
}user_t;

	/****** End of structs *******/


/*define of function*/

void t_format(void);
int read_line(FILE *p, char *arr);
int line_num(FILE *ptr);
int check_user_passwrd(char *u_name, char *passwrd, user_t *usr,
		 char *type, int line_num, char *userID);
int read_stdnt_file(FILE *ptr, student_t *st);
int read_ins_file(FILE *ptr, instructor_t *ins);
int read_users_file(FILE *ptr, user_t *usr);
int read_course_file(FILE *ptr, course_t *crs);
void print_stdnt(student_t *student,int size);
void print_instrctr(instructor_t *ins, int size);
void print_users(user_t *usr, int size);
void print_courses(course_t *crs, int size);
int print_listOfIns(course_t *crs, char *user, char onOrOff, int size);
int list_open_courses(char *user, course_t *crs, int size);
int menu_instructor(char *user);
int menu_student(char *user);
int open_courses(char *user, course_t *crs, int size);
void save_open_course(course_t *crs, int size);
int add_course(char *user, student_t *std, course_t *crs, int sizeOfCrs, int sizeOfstd);
int find_indis(student_t *std, char *user, int size);
int printListOfStd(course_t *crs, int sizeOfCrs);


	/*End of definition*/
	





