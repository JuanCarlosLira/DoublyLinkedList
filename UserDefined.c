#include <stdlib.h>                     // Used for malloc, & EXIT codes
#include "UserDefined.h"               // All the user defined functions

node_p NewItem (int theNumber, char * theString){
  node_p newItem = (node_p)malloc(sizeof(myData));
  newItem->number = theNumber;
  newItem->theString = theString;

  return newItem;
}
