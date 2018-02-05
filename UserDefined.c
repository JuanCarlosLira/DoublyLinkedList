#include <stdio.h>                                    // Used for printf
#include <stdlib.h>                     // Used for malloc, & EXIT codes
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
  newItem->theString = theString;

  return newItem;
}

int FreeItem (const void *data_p){
  node_p p = (node_p)data_p;
  free(p);
  p == NULL;

  if(p == NULL){
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
