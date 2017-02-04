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



		/******* MAİN ********/
int main(int argc, char *argv[])
{
	int r, l_num_usr, control;
	char type, *user_id;
	student_t *std;
	instructor_t *ins;
	user_t *usr;
	FILE *p_stdnt, *p_ins, *p_usr, *p_cors;
	/*END_OF_VARIABLES*/
	
	p_usr  =  fopen("Users.csv" , "rb");
	
	 if(argc != 3){
        t_format();
        return 0;
    }
    user_id = (char *) malloc(11 * sizeof(char));
    l_num_usr = line_num(p_usr);
    usr = (user_t *) malloc(l_num_usr * sizeof(user_t));
    rewind(p_usr);
    read_users_file(p_usr, usr);
  	
    control = check_user_passwrd(argv[1], argv[2], usr, &type, l_num_usr, user_id);
    
    if(control == 1){
            printf("You are in.\n");
            
            if(type == '1'){
            	menu_student(user_id);
            }
            else
           		if(type == '2'){
           		
           		menu_instructor(user_id);
           }
            else{
            	printf("Undefine user Type!!!\n");
            }        
    }            
    else
    	if(control == -1){
        	printf("wrong username or password !!!\n");
            t_format();
            return 0;
    	}     
	else
	 	if(control == 0){
	 	printf("there is no sach a user on record\n");
	 	}	
	
	fclose(p_usr);
		/******* END_OF_MAIN *******/
return 0;
}












