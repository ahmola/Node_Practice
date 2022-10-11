#ifndef _NODEHEADER_
#define _NODEHEADER_
#pragma once

#define SIZE 256

typedef struct USERDATA {
	char userName[SIZE];
	char userNumber[SIZE];
} UserData;

typedef struct NODE {
	char data[SIZE];
	struct NODE* next;
	struct NODE* back;
} Node;

Node* Head;
Node* Tail;
int total;

int init(void);

void setNext(Node* target, Node* next);
void setBack(Node* target, Node* back);
void setData(Node* target, char* data);

int insertNode(char* data);
Node* findNode(char* data);
int deleteNode(char* data);
void printNode(void);
void printBack(void);
void freeNode(void);

#endif