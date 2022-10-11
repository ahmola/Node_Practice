#include <stdio.h>

#include "NodeHeader.h"

int main(void) {

    printf("");

    init();
    
    for (int i = 1; i <= 10; i++) {
      char buf[10];
      sprintf(buf, "%d", i);
      insertNode(buf);
    }

    printf("\n");

    for (int i = 1; i <= 10; i++) {
      char buf[10];
      sprintf(buf, "%d", rand() % 10 + 1);
      findNode(buf);
    }

    printf("\nTotal Node : %d\n\n", total);

    printNode();
    printf("\n");

    for (int i = 1; i <= 5; i++) {
      char buf[10];
      sprintf(buf, "%d", i);
      deleteNode(buf);
    }
    printf("\n");

    freeNode();
  
    return 0;
}