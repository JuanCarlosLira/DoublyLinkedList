#include <stdio.h>                                    // Used for printf
#include <stdlib.h>                     // Used for malloc, & EXIT codes
#include <string.h>                        // For strcmp, strlen, strcpy
#include "UserDefined.h"               // All the user defined functions

int PrintItem (const void *data_p){
  node_p p = (node_p)data_p;
  if(p != NULL){
    printf("Data element %d: %s\n", p->number, p->theString);
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}

int PrintList (GList * myList_p){
  GList *l;
  int result = EXIT_FAILURE;
  for(l = myList_p; l != NULL; l = l->next){
    result = PrintItem(l->data);
    if(result == EXIT_FAILURE){
      break;
    }
  }
  return result;
}

node_p NewItem (int theNumber, char * theString){
  node_p newItem = (node_p)malloc(sizeof(myData));
  newItem->number = theNumber;
  newItem->theString = strdup(theString);

  return newItem;
}

int FreeItem (const void *data_p){
  node_p p = (node_p)data_p;
  free(p->theString);
  free(p);

  return EXIT_SUCCESS;
  /*if(p == NULL){
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }*/
}

int compareSingleStr(node_p value_p1,char * value_p2) {
  char *str1 = value_p1->theString;
  char *str2 = value_p2;
  //printf("str1=%s , str2=%s\n", str1,str2);
  if (strcmp(str1, str2) > 0) {
    return 1;
  }
  if (strcmp(str1, str2) == 0) {
    return 0;
  }
  if (strcmp(str1, str2) < 0) {
    return -1;
  }
  return 0;
}

int compareSingleInt(node_p value_p1,int *value_p2) {
  int x = value_p1->number;
  int y = *value_p2;
  //printf("x=%d , y=%d\n", x,y);
  if (x > y) {
    return 1;
  }
  if (x == y) {
    return 0;
  }
  if (x < y) {
    return -1;
  }
  return 0;
}

int compareStr(node_p value_p1,node_p value_p2) {
  char *str1 = value_p1->theString;
  char *str2 = value_p2->theString;
  //printf("str1=%s , str2=%s\n", str1,str2);
  if (strcmp(str1, str2) > 0) {
    return 1;
  }
  if (strcmp(str1, str2) == 0) {
    return 0;
  }
  if (strcmp(str1, str2) < 0) {
    return -1;
  }
  return 0;
}

int compareInt(node_p value_p1,node_p value_p2) {
  int x = value_p1->number;
  int y = value_p2->number;
  //printf("x=%d , y=%d\n", x,y);
  if (x>y) {
    return 1;
  }
  if (x==y) {
    return 0;
  }
  if (x<y) {
    return -1;
  }
  return 0;
}

GList * FindInList (GList * myList_p, const void *value_p, int key) {
  switch (key) {
    case INT:
        myList_p = g_list_find_custom (myList_p, value_p, (GCompareFunc)compareInt);
        break;
    case STR:
        myList_p = g_list_find_custom (myList_p, value_p, (GCompareFunc)compareStr);
        break;
    case SINGLEINT:
        myList_p = g_list_find_custom (myList_p, value_p, (GCompareFunc)compareSingleInt);
        break;
    case SINGLESTR:
        myList_p = g_list_find_custom (myList_p, value_p, (GCompareFunc)compareSingleStr);
        break;
    default:
        myList_p = NULL;
        break;

  }
  return myList_p;
}
