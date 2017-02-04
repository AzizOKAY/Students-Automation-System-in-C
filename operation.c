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
#include "PR_101044064.h"




/*function that true format for introduction*/

void t_format(void)
{
	printf("True format is...\n\n<username> <password>\n\n");
}


/*** function that read just one line in file ***/
int read_line(FILE *p, char *arr)
{
	int i=0;
	char c;
	while(fread(&c, sizeof(char), 1, p) != 0 && c != '\n'){
			arr[i] = c;
			++i;
	}
	arr[i] = '\0';
	
	return i;	
}


/*** function that count and return line number in given file ***/
int line_num(FILE *ptr)
{
	int i=0;
	char buffer[256];
	while(read_line(ptr,buffer) !=0)
		++i;
	return i;
}


/*** function that read student file ***/

int read_stdnt_file(FILE *ptr, student_t *st)
{
	int i=0, status,counter=0,j=0, result=1;
	char buffer[256], *token;
	
		while(read_line(ptr,buffer) != 0){
			#ifdef DEBUG 
			printf("%s\n", buffer);
			#endif
		 	token = strtok(buffer,",\n");
		 	
	 		while (token != NULL){
            	if(j==0){
            		st[counter].TCNo=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy(st[counter].TCNo,token);
    			}
    			if(j==1){
            		st[counter].name=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy(st[counter].name,token);	
            	}
            	if(j==2){
            		st[counter].surname=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( st[counter].surname,token);
            	}
            	if(j==3){
            		st[counter].studentNo=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy(st[counter].studentNo,token );
            	}
            	if(j==4){
            		st[counter].startYear=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( st[counter].startYear,token);
            	}	
            	++j;
            	token = strtok(NULL,",");	
	    	}
	    	j=0;
	    	++counter;
   	}	
   	#ifdef DEBUG 
   	print_stdnt(st,5);
   	printf("\n\n\n\n");		
   	#endif
   	
return result;	
}


/*** function that read instructors file ***/

int read_ins_file(FILE *ptr, instructor_t *ins)
{
	int i=0, status,counter=0,j=0, result=1;
	char buffer[256], *token;
	
		while(read_line(ptr,buffer) != 0){
			#ifdef DEBUG
			printf("%s\n",buffer);
			#endif
		 	token = strtok(buffer,",");
		 	
	 		while (token != NULL){
            	if(j==0){
            		ins[counter].TCNo=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy(ins[counter].TCNo,token);
    			}
    			if(j==1){
            		ins[counter].name=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy(ins[counter].name,token);	
            	}
            	if(j==2){
            		ins[counter].surname=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( ins[counter].surname,token);
            	}	
            	++j;
            	token = strtok(NULL,",");	
	    	}
	    	j=0;
	    	++counter;
   	}	
   	#ifdef DEBUG
   	print_instrctr(ins, 3);
   	printf("\n\n\n\n");	
   	#endif	
return result;	
}


/*** function that read users file ***/

int read_users_file(FILE *ptr, user_t *usr)
{
	int i=0, status,counter=0,j=0, result=1;
	char buffer[256], *token;
	
		while(read_line(ptr,buffer) != 0){
			#ifdef DEBUG
			printf("%s\n",buffer);
			#endif
		 	token = strtok(buffer,",");
		 	
	 		while (token != NULL){
            	if(j==0){
            		usr[counter].ID=(char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( usr[counter].ID,token);
            		
    			}
    			if(j==1){
            		usr[counter].userType = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( usr[counter].userType, token);	
            	}
            	if(j==2){
            		usr[counter].userName = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( usr[counter].userName, token);
            	}
            	if(j==3){
            		usr[counter].passWord = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( usr[counter].passWord, token );
            	}	
            	++j;
            	token = strtok(NULL, ",\n");	
	    	}
	    	j=0;
	    	++counter;
   	}		
   	#ifdef DEBUG
   	print_users(usr, 9);
   	printf("\n\n\n\n");
    #endif	
return result;	
}


    /*** function that read courses file ***/
int read_course_file(FILE *ptr, course_t *crs)
{
	int i=0, status,counter=0,j=0, result=1;
	char buffer[256], *token;
	FILE *is_open;
	is_open = fopen("openCourses.bin" , "rb");
	
		while(read_line(ptr,buffer) != 0){
			#ifdef DEBUG
			printf("%s\n",buffer);
			#endif
		 	token = strtok(buffer,",");
		 	
	 		while (token != NULL){
            	if(j==0){
            		crs[counter].ID = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( crs[counter].ID,token);
    			}
    			if(j==1){
            		crs[counter].name = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( crs[counter].name, token);	
            	}
            	if(j==2){
            		crs[counter].instructor = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( crs[counter].instructor, token);
            	}
            	if(j==3){
            		crs[counter].prerequisities = (char *)malloc(strlen(token)*sizeof(char*));
            		strcpy( crs[counter].prerequisities, token );
            	}	
            	++j;
            	token = strtok(NULL, ",");	
	    	}
	    	j=0;
	    	++counter;
   	}	
    if(is_open != NULL){
	   	for(i=0; i<5;i++){
	   		fread(&crs[i].is_open, sizeof(char), 1, is_open);
	   	}
   	}
   	
   	#ifdef DEBUG
   	print_courses(crs, 5);
	printf("\n\n\n\n");
	#endif
		
return result;
}

	/**** function that chack user name and password ****/
int check_user_passwrd(char *u_name, char *passwrd, user_t *usr, char *type, int line_num, char *userID)
{
	int i, result=0, size;
	for(i=0; i<line_num; i++){
		if(strcmp(usr[i].userName, u_name) == 0){
			if(strcmp(usr[i].passWord, passwrd) == 0){
				strcpy(type, usr[i].userType);
				strcpy(userID, usr[i].ID);
				return 1;
			}
			else
				result = -1;
		}
	}
	return result;
}

	/*** function that print student elements on console ****/
void print_stdnt(student_t *student,int size)
{
	int i=0;
	printf("%-15s%-15s%-15s%-15s%-15s\n","TC","NAME","SURNAME","STUDENT NUMBER","START YEAR");
	for(i=0;i<size;++i){
		printf("%-15s",student[i].TCNo);
		printf("%-15s",student[i].name);
		printf("%-15s",student[i].surname);
		printf("%-15s",student[i].studentNo);
		printf("%-15s\n",student[i].startYear);
	}
}


	/*** function that print instructor elements on console ****/
void print_instrctr(instructor_t *ins, int size)
{
	int i=0;
	printf("%-15s%-15s%-15s\n","TC","NAME","SURNAME");
	for(i=0;i<size;++i){
		printf("%-15s",ins[i].TCNo);
		printf("%-15s",ins[i].name);
		printf("%-15s\n",ins[i].surname);
	}

}

	
	/*** function that print users elements on console ****/
void print_users(user_t *usr, int size)
{
	int i=0;
	printf("%-15s%-15s%-15s%-15s\n","ID","userType","userName","passWord");
	for(i=0;i<size;++i){
		printf("%-15s",usr[i].ID);
		printf("%-15s",usr[i].userType);
		printf("%-15s",usr[i].userName);
		printf("%-15s\n",usr[i].passWord);
	}
}


	/*** function that print courses elements on console ****/
void print_courses(course_t *crs, int size)
{
	int i=0;
	printf("%-19s%-19s%-19s%-19s%-19s\n","ID","NAME","instructor","prerequisities","is_open");
	for(i=0;i<size;++i){
		printf("%-19s",crs[i].ID);
		printf("%-19s",crs[i].name);
		printf("%-19s",crs[i].instructor);
		printf("%-19s",crs[i].prerequisities);
		printf("%-19c\n",crs[i].is_open);
	}
}
	/*** instructor menu ****/
int menu_instructor(char *user)
{
	int l_num_cors, choice;
	course_t *crs;
	FILE *p_cors;
	
	p_cors =  fopen("Courses.csv" , "rb");
	
	l_num_cors = line_num(p_cors);
	rewind(p_cors);
	crs = (course_t *) malloc(l_num_cors * sizeof(course_t));
	read_course_file(p_cors, crs);
	
	printf("For Open a course enter ______________________1\n");
	printf("For Finalize a course_________________________2\n");
	printf("For Assign grades_____________________________3\n");
	printf("For Edit grades_______________________________4\n");
	printf("For List open courses_________________________5\n");
	printf("For List grades_______________________________6\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			if(open_courses(user, crs, l_num_cors) == 1){ 
				save_open_course(crs, l_num_cors);	
			 }
			
		break;
		
		case 2:

		break;
		
		case 3:

		break;
		
		case 4:

		break;
		
		case 5:
			list_open_courses(user, crs, l_num_cors);
		break;
		
		case 6:

		break;
		
		default :
			printf("Wrong choice try again!!!\n");
			break;
	}
	
	fclose(p_cors);
	
return 0;	
}


	/*** student menu ****/
int menu_student(char *user)
{
	int l_num_cors, l_num_std, choice;
	student_t *std;
	course_t *crs;
	FILE *p_cors, *p_std;
	
	p_std = fopen("Students.csv" , "rb");
	p_cors =  fopen("Courses.csv" , "rb");
	
	l_num_std = line_num(p_std);
	l_num_cors = line_num(p_cors);
	rewind(p_cors);
	rewind(p_std);
	
	std = (student_t *) malloc(l_num_std * sizeof(student_t));
	crs = (course_t *) malloc(l_num_cors * sizeof(course_t));
	/*std.stdntID = (std.stdntID *) malloc(l_num_std * sizeof(std.stdntID));
	std.situation = (std.situation *) malloc(l_num_std * sizeof(std.situation));
	std.grade = (std.grade *) malloc(l_num_std * sizeof(std.grade));*/
	read_stdnt_file(p_std, std);
	read_course_file(p_cors, crs);
	
	printf("For Add a course enter ____________________________1\n");
	printf("For Remove a course________________________________2\n");
	printf("For List courses___________________________________3\n");
	printf("For Shows transcript_______________________________4\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			add_course(user, std, crs, l_num_cors, l_num_std);	
		break;
		
		case 2:

		break;
		
		case 3:

		break;
		
		case 4:

		break;
		
		default :
			printf("Wrong choice try again!!!\n");
			break;
	}
	
	fclose(p_cors);
	fclose(p_std);
	
}


	/* function that print course that instructor will open */
int print_listOfIns(course_t *crs, char *user, char onOrOff, int size)
{
	int i, result=0;
	printf("%-19s%-19s%-19s%-19s%-19s\n","ID","NAME","instructor","prerequisities","is_open");
	for(i=0; i<size; i++){
		if(strcmp(user, crs[i].instructor) == 0){
			if(crs[i].is_open != onOrOff){
				printf("%-19s%-19s    ", crs[i].ID, crs[i].name);
				printf("%-19s%-19s", crs[i].instructor, crs[i].prerequisities);
				printf("%-19c\n", crs[i].is_open);
				result++;
			}
		}
	}
	if(result == 0)
		printf("There is no closed course for you.\n");
	return result;
}

	/* function that list open courses for instructor */
int list_open_courses(char *user, course_t *crs, int size)
{
	int result=0, i, choise;
	char comma=',', n_line='\n';
	FILE *p;
	p = fopen("hoca_openCourses.csv" , "wb");
	
	if(print_listOfIns(crs, user, '0', size) > 0){
		printf("For save this in file enter 1.\n");
		printf("For exsit eny other key.\n");
		scanf("%d", &choise);
		if(choise == 1){
			for(i=0; i<size; i++){
				if(strcmp(user, crs[i].instructor) == 0){
					if(crs[i].is_open != 1){
						fwrite(crs[i].ID, sizeof(char), strlen(crs[i].ID), p);
						fwrite(&comma, sizeof(char), 1, p);
						fwrite(crs[i].name, sizeof(char), strlen(crs[i].name), p);
						fwrite(&n_line, sizeof(char), 1, p);
						result = 1;
					}
				}
			}	
		}
		}
	if(result == 1)
		printf("Corses was saved in file\n");
		
return result;	
}

	/*function that open courses for students */
int open_courses(char *user, course_t *crs, int size)
{
	int clsed_crs, i, j, counter=0, result=0;
	char str[5];
	
	clsed_crs = print_listOfIns(crs, user, '1', size);
	if(clsed_crs != 0){
		for(i=0; i<clsed_crs; i++)
		{
			printf("Enter ID of course that you want to open.\n");
			scanf("%s", str);
			for(j=0; j<size; j++){
				counter++;
				if(strcmp(str,crs[j].ID) == 0){
					result = 1;
					if(crs[j].is_open != 1){
						crs[j].is_open = '1';
						printf("course was opened\n");
					}
					else{
						printf("course already not closd\n");
					}	
				}
			}
			if(counter == 0)	
				printf("There is no same course ID in Data\n");
		}
	}
	return result;
}

	/* function that save opened course for student */
void save_open_course(course_t *crs, int size)
{
	int i;
	FILE *p;
	p = fopen("openCourses.bin" , "wb");
	for(i=0; i<size; i++){
		fwrite(&crs[i].is_open, sizeof(char), 1, p);
	}
	
	fclose(p);
}

		/* function that add courses  */
int add_course(char *user, student_t *std, course_t *crs, int sizeOfCrs, int sizeOfstd)
{
	int open_crs, i, j, counter=0, result=0, pre_s=0;
	char str[5], filename[30], even = 'A';
	FILE *p;
	
	open_crs = printListOfStd(crs, sizeOfCrs);
	
	if(open_crs != 0){
		for(i=0; i<open_crs; i++)
		{
			printf("Enter ID of course that you want to add.\n");
			printf("For exit save enter E.\n");
			scanf("%s", str);
			if(strcmp(str, "E") != 0){
				for(j=0; j<sizeOfCrs; j++){
					if(strcmp(str, crs[j].ID) == 0){
						if(crs[j].is_open == '1' && crs[j].is_add_remove_open != '0'){
							strcpy(filename, crs[j].ID);
							strcat(filename, ".bin");
							p = fopen(filename, "ab+");
							fwrite(user, sizeof(char), strlen(user), p);
							fwrite(&even, sizeof(char), 1, p);
						}
					}
				}
			}else
				break;
		}
		
	}
	else{
		printf("There is no course to open.\n");
	}
	
	fclose(p);
	return result;
}

	/*function for find indis of student in file*/
int find_indis(student_t *std, char *user, int size)
{

	int i, result=-1;
	for(i=0; i<size; i++){
		if(strcmp(std[i].TCNo, user) == 0 ){
			result = i;
			break;	
		}
	}
	return result;
}


	/*function for print courses for student (user)*/
int printListOfStd(course_t *crs, int sizeOfCrs)
{
	int i, result=0;
	printf("%-19s%-19s%-19s%-19s%-19s\n","ID","NAME","instructor","prerequisities","is_open");
	for(i=0; i<sizeOfCrs; i++){
		if(crs[i].is_open == '1'){
			printf("%-19s%-19s    ", crs[i].ID, crs[i].name);
			printf("%-19s%-19s", crs[i].instructor, crs[i].prerequisities);
			printf("%-19c\n", crs[i].is_open);
			result++;
		}
	}
	if(result == 0)
		printf("There is no opened course for you.\n");
	return result;
}





