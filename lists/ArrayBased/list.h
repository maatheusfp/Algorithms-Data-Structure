#ifndef _LIST_H
#define _LIST_H

typedef struct list List;
List* create_list(int size);
void clear(List* l);
void insert(List* l, int item);

#endif