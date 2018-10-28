#include <stdlib.h>

typedef struct Node{
  char *data;
  char *row;
  struct Node *next;
}Node;

typedef struct pidNode{
  pid_t *pid;
  struct pidNode *next;
}pidNode;

Node* readfile(int colInd, FILE *fp);
char *remove_leading_spaces(char* str);
int columnNum(char *row, char *col);
char *tokenizer(int col, char *line);
void FrontBackSplit (Node* source, Node** frontRef, Node** backRef);
void MergeSort (Node** headRef);
Node* SortedMerge( Node* a, Node* b);
void print( Node* a);
void Finish(Node* head);


void directChild(DIR* dir);
int isDirectory(char d_name[]);
int isCSV(char d_name[]);
Node* childpid(Node * head, pid_t pid);
void printVals(pid_t pid, Node *head, int counter);

