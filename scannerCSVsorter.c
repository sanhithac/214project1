#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
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
   	  inDir=strcat(inDir, argv[4]);//or try inDir = argv[4]
   }
   if(argv[3]=="-o"){//output directory specified
     if(argc[4] == NULL)
	     printf("Incorrect Input: No directory specified");
     else
        outDir=strcat(outDir, argv[4]);
   }
   if(argv[5] == "-o"){//output directory specified
     if(argc[6] == NULL)
	     printf("Incorrect Input: No directory specified");
     else
        outDir=strcat(outDir, argv[6]);
   }
	 
   int processCounter=0;
  
   DIR* dir; 
   //struct dirent* ptr; 

   dir = opendir(inDir); //opens a directory
   if(dir == NULL){ 
     printf("Incorrect Input: Input directory specified does not exist");
     return -1; 
   }
directChild(dir);
   return 0; 
 } 

void directChild(DIR* dir = opendir(dirc1)){
  int pid;
  struct dirent* ptr; //points to the directory that is read
  while((ptr = readdir(dir))!= null){
	pid = fork();
	processCounter++;
	if(isDirectory(ptr->d_type) == DT_DIR){//directory
		if (pid == 0){//child pid
			directChild(ptr); //recurse
			childpid(pid);
        	}
		else if (pid ==1){//parent pid
			continue;
        	}
	}
	else{
		if (pid == 0){
			if(isCSV(ptr->d_name) == 1){
				mergesort();
				childpid(pid);
        		}
		}
		if (pid == 1){
			continue;
        	}
		  
      }
  }
}

//checks if the input is a directory
int isDirectory(char d_name[]){
  for(int i =0; i< strlen(d_name);i++){
    if(d_name[i].Equals('.')){
      return 0;
    }
  }
  return 1;
}

//checks if the input is a csv file
int isCSV(char d_name[]){
  if (strlen(d_name) < 5)
    return 0;
  if (!(d_name[strlen(d_name)-1].Equals('v'))){
    return 0;
  }
  if(!(d_name[strlen(d_name)-2].Equals('s')))
    return 0;
  if(!(d_name[strlen(d_name)-3].Equals('c')))
    return 0;
  if(!(d_name[strlen(d_name)-4].Equals('.')))
    return 0;

  return 1;
}
