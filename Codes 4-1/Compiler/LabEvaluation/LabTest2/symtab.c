#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *typename[] = {"UNDEF_TYPE", "INT_TYPE", "CHAR_TYPE"};
static list_t *head = NULL;
extern int lineno;

void insert(char* name, int type) {
    if (search(name) == NULL) {
        list_t* temp = (list_t*)malloc(sizeof(list_t));
        strcpy(temp->st_name, name);
        temp->st_type = type;
        printf("In line no %d, Inserting %s with type %s in symbol table.\n", lineno, name, typename[type]);
        temp->next = head; head = temp;
    } else {
        printf("In line no %d, Same variable %s is declared more than once.\n", lineno, name);
    }
}

list_t* search(char *name) {
    list_t* cur = head;
    while (cur && strcmp(name, cur->st_name) != 0) cur = cur->next;
    return cur;
}

int idcheck(char* name) {
    if (!search(name)) { printf("In line no %d, ID %s is not declared.\n", lineno, name); return 0; }
    return 1;
}

int gettype(char *name) {
    list_t* t = search(name);
    if (!t) { printf("In line no %d, ID %s is not declared.\n", lineno, name); return UNDEF_TYPE; }
    return t->st_type;
}

int typecheck(int t1, int t2) {
    if (t1 == INT_TYPE && t2 == INT_TYPE) return INT_TYPE;
    if (t1 == CHAR_TYPE && t2 == CHAR_TYPE) return CHAR_TYPE;
    printf("In line no %d, Data type %s is not matched with Data type %s.\n", lineno,
           typename[(t1>=0&&t1<=2)?t1:0], typename[(t2>=0&&t2<=2)?t2:0]);
    return UNDEF_TYPE;
}