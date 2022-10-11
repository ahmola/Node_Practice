#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NodeHeader.h"

#define _CRT_SECURE_NO_WARNINGS


int init(void) {
    Head = NULL;
    Tail = NULL;
    total = 0;

    printf("Initiate\n");
    return 1;
}

void setNext(Node *target, Node *next) { target->next = next; }

void setBack(Node *target, Node *back) { target->back = back; }

void setData(Node *target, char *data) { strcpy(target->data, data); }

int insertNode(char *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  memset(newNode, 0, sizeof(Node));
  setData(newNode, data);

  if (Head == NULL) {
    Head = newNode;
  } else {
    setNext(newNode, Head);
    setBack(Head, newNode);
    Head = newNode;
  }

  printf("insert %s at %p\n", newNode->data, newNode);

  if (total == 0)
    Tail = newNode;

  total++;
  return total;
}

Node *findNode(char *data) {
  Node *finding = Tail;
  
  while (strcmp(finding->data, data) && finding != NULL) {
      finding = finding->back;
  }

  if (finding == NULL) {
    printf("Cannot Find\n");
    return NULL;
  }
  printf("Find %p, %s\n", finding, finding->data);

  return finding;
}

int deleteNode(char *data) {
  Node *del = findNode(data);

  if (Head == NULL) {
    printf("There is no NODE\n");
    return 1;
  }

  printf("delete %p, %s\n", del, del->data);
  if (del == Head) {
    Head = del->next;
    if(Head != NULL)
        Head->back = NULL;
    free(del);
;  } else if (del == Tail) {
    Tail = del->back;
    Tail->next = NULL;
    free(del);
  } else {
    del->back->next = del->next;
    del->next->back = del->back;
    free(del);
  }

  return 1;
}

void printNode(void) {
  Node *printer = Head;
  while (printer != NULL) {
    printf("address : %p, data : %s\n", printer, printer->data);
    printer = printer->next;
  }
}

void printBack(void) {
  Node *printer = Tail;
  while (printer != NULL) {
    printf("address : %p, data : %s\n", printer, printer->data);
    printer = printer->back;
  }
}

void freeNode(void) {
  Node *next = 0;
  while (Head != NULL) {
    next = Head->next;
    printf("Free %p, %s\n", Head, Head->data);
    free(Head);
    Head = next;
  }
  printf("Free Done\n");
}