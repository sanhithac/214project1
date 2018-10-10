#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "simpleCSVsorter.h"

int isGreaterThan(Node* node1, Node* node2)
{
    if(!node1 || !node2)
    {
        return 0;
    }
    if(node1->isString)
    {
        return (strcmp(node1->sortByValue, node2->sortByValue)) > 0;
    }
    else 
    {
        return atof(node1->sortByValue) > atof(node2->sortByValue);
    }
}

void mergeArr(Node** arr, int s1, int e1, int s2, int e2)
{
    int i = s1;
    int j = s2;
    int idx = 0;

    Node** tmpArr = (Node**)malloc((e2-s1+1)*sizeof(Node*));

    while((i <= e1) && (j <= e2))
    {
        if(isGreaterThan(arr[i], arr[j]))
	{
	    tmpArr[idx++] = arr[j];
	    j++;
	}
	else
	{
	    tmpArr[idx++] = arr[i];
	    i++;
	}
    }
    while(i <= e1)
    {
        tmpArr[idx++] = arr[i++];
    }
    while(j <= e2)
    {
        tmpArr[idx++] = arr[j++];
    }
    for(i=s1, j=0; i<= e2; i++, j++)
    {
        arr[i] = tmpArr[j];
    }
    if(tmpArr)
    {
        free(tmpArr);
    }
}

void mergeSortArr(Node** arr, int start, int end)
{
    int mid = (start + end) / 2;
    if(start < end)
    {
        mergeSortArr(arr, start, mid);
        mergeSortArr(arr, mid+1, end);
        mergeArr(arr, start, mid, mid+1, end);
    }
}
