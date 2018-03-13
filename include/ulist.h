//
// Created by Ahmed Alkabir on 9/27/2017.
//

#pragma once

#include <stdlib.h>

/** Structure of Linked List Elements
 *
 *  I would use Doubly-linked list
 * */

typedef struct uListElmt_{
    void                *data;
    struct uListElmt_  *prev;
    struct uListElmt_  *next;
} uListElement;

/**
 *  Structure of linked lists
 * */
typedef struct uList_{
    int size;

    int (*match)(const void *key_1, const void *key_2);
    void (*destroy)(void *data);

    // head of linked list
    uListElement *head;

    // tail of linked list
    uListElement *tail;
}uList;

/** Interface of Linked lList
 * */
void ulist_init(uList *list, void(*destory)(void *data));

uList *ulist_init_(void (*destroy)(void *data));

void ulist_destroy(uList *list);

int ulist_ins_next(uList *list, uListElement *element, const void *data);

int ulist_ins_prev(uList *list, uListElement *element, const void *data);

int ulist_remove(uList *list, uListElement *element, void **data);

#define ulist_size(list) ((list)->size)

#define ulist_head(list) ((list)->head)

#define ulist_tail(list) ((list)->tail)

#define ulist_is_head(element) ((element)->prev == NULL ? 1 : 0)

#define ulist_is_tail(element)   ((element)->next == NULL ? 1 : 0)

#define ulist_data(element)  ((element)->data)

#define ulist_next(element)  ((element)->next)

#define ulist_prev(element)  ((element)->prev)

