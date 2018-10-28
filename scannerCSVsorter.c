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
   
   Node * head=NULL;
	 
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
   DIR* out;
   //struct dirent* ptr; 

   dir = opendir(inDir); //opens a directory
   out = opendir(outDir);	 
	 
   if(dir == NULL){ 
     printf("Incorrect Input: Input directory specified does not exist");
     return -1; 
   }
   if(outDir==NULL){
     printf("Incorrect Input: Output directory specified does not exist");
     return -1; 
   }
	 
   directChild(dir);
   printVals(getpid(), head, processCounter);
   return 0; 
 } 

void directChild(DIR* dir = opendir(dirc1)){
  int pid;
  struct dirent* ptr; //points to the directory that is read
  while((ptr = readdir(dir))!= null){
	pid = fork();
	processCounter++;
	if(ptr->d_type == DT_DIR){//directory
		if (pid == 0){//child pid
			directChild(ptr->d_name); //recurse
			childpid(head, pid);
        	}
		else if (pid ==1){//parent pid
			continue;
        	}
	}
	else{
		if (pid == 0){
			if(isCSV(ptr->d_name) == 1){
				mergesort();
				childpid(head, pid);
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

Node* childpid(Node * head, pid_t pid){
	Node *temp= (Node *)malloc(sizeof(Node));
	Node *p=NULL;
	
	if(head==NULL){
		head = (Node *)malloc(sizeof(Node));
		head->data=pid;
	}
	else{
		p=head;
		while(p->next !=NULL){
			p=p->next;
		}
		p->next =temp;
		temp->data=pid;
	}
	return head;
}

void printVals(pid_t pid, Node *head, int counter){
	printf("Initial PID: %d\n", pid);
	printf("PID of all child processes:");
	Node *p=NULL;
  	p=head;
  	while (p!= NULL){
    		printf("%d", p->data, ", ");
    		p = p->next;
 	 }
	printf("\n Total number of processes: %lf\n", pow(2, counter));
	return;
}
