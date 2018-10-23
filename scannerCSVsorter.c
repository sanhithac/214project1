#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include "simpleCSVsorter.c" 

 int main(int argc, char** argv){ 
   //input and output directories
   char *inDir=".";
   char *outDir=".";
	 
   if(argc%2 ==0){ //even
     printf("Incorrect Input");
     return -1; 
   } 
   if(argc >7){ //too long
     printf("Incorrect Input");
     return -1; 
   } 
   if(argv[1] != "-c"){ //no -c
     printf("Incorrect Input: No column flag");
     return -1; 
   } 
   if(argv[2] == NULL){ //no category
     printf("Incorrect Input: No column name");
     return -1;  
   } 
   if(argv[3] == "-d"){//input directory specified
     if(argc[4] == NULL)
	     printf("Incorrect Input: No directory specified");
     else
   	  inDir=strcat(inDir, argv[4]);
   }
   if(argv[5] == "-o"){//output directory specified
     if(argc[6] == NULL)
	     printf("Incorrect Input: No directory specified");
     else
             outDir=strcat(outDir, argv[6]);
   }
	 
   int count=0;
  
   DIR* dir; 
   //struct dirent* ptr; 

   dir = opendir(inDir); 
   if(dir == NULL){ 
	   //print output values
     return -1; 
   }
directChild(dir);
   return 0; 
 } 
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
	
