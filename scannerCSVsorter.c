/* #include <dirent.h> */
/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <sys/types.h> */

/* //#include "header.h" */
/* //#include "movies.c" */
/* //#include "mergesort.c" */

/* int main(int argc, char** argv){ */
/*   if(argc%2 ==0){ */
/*     return -1; */
/*   } */
/*   if(argc >7){ */
/*     return -1; */
/*   } */
/*   if(argv[1] != "-c"){ */
/*     return -1; */
/*   } */
/*   if(argv[2] == NULL){ */
/*     return -1;  */
/*   } */
  
/*   DIR* dir; */
/*   struct dirent* ptr; */

/*   dir = opendir("project1"); */
/*   if(dir == NULL){ */
/*     return -1; */
/*   } */
 
/*   while((ptr = readdir(dir)) != NULL){ */
/*     //fork */
/*     //while */
/*     //new method: if ptr->d_name is csv,return 1. if direc, return 0. else return -1 */
/*     //if csv,   */
/*   } */

 /*
		void directChild(DIR* dir = opendir(dirc1)){
			struct dirent* ptr;
			while((ptr = readdir(dir))!= null){
				if directory
					fork()
					process++;
						if child
							directChild(); //recurse
							print PID
						if parent
							continue;
				if csv
					fork();
					process++;
						if child
							mergesort();
							print PID
						if parent
							continue;
				if else
					continue;
			}
		}
	*/
/*   return 0; */
/* } */
