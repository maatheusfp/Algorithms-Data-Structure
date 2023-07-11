#ifndef _LIST_H
#define _LIST_H

typedef struct list List;
List* create_list(int size);
void clear(List* l);
void insert(List* l, int item);
void moveToStart(List* l);
void moveToEnd(List* l);
void prev(List* l);
void next(List* l);
int remove(List* l);

#endif