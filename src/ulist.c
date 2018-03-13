//
// Created by Ahmed Alkabir on 9/27/2017.
//

#include <stdlib.h>
#include <string.h>

#include <ulist.h>

uList *ulist_init(void (*destroy)(void *data)){
    uList *list = (uList *)malloc(sizeof(uList));
    list->size  = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void ulist_destroy(uList *list){
    void *data;

    while(ulist_size(list) > 0){
        if(ulist_remove(list,ulist_tail(list), (void **)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(uList));
}

int ulist_ins_next(uList *list, uListElement *element, const void *data){

    uListElement *new_element;

    if(element == NULL && ulist_size(list) != 0)
        return -1;

    if((new_element = (uListElement *)malloc(sizeof(uListElement))) == NULL)
        return -1;

    // insert the new element into the list
    new_element->data = (void *)data;

    if(ulist_size(list) == 0){
        // handle insertion when the  list is empty.
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    }else{
        new_element->next = element->next;
        new_element->prev = element;

        if(element->next == NULL)
            list->tail = new_element;
        else
            element->next->prev = new_element;

        element->next = new_element;
    }

    list->size++;

    return 0;
}

int ulist_ins_prev(uList *list, uListElement *element, const void *data){
    uListElement *new_element;

    // don not allow a null element unless the list is empty
    if(element == NULL && ulist_size(list) != 0)
        return -1;

    // allocate storage to be managed by the abstract datatype.
    if((new_element = (uListElement *)malloc(sizeof(uListElement))) == NULL)
        return -1;

    // insert the new element into the list.
    new_element->data = (void *)data;
    if(ulist_size(list) == 0){
        // handle insertion when the list is empty.
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    }else{
        // handle insertion when the list is not empty
        new_element->next = element;
        new_element->prev = element->prev;

        if(element->prev == NULL)
            list->head = new_element;
        else
            element->prev->next = new_element;

        element->prev = new_element;
    }

    list->size++;

    return 0;
}

int ulist_remove(uList *list, uListElement *element, void **data){
    // do not allow a null element or removal from an empty list.
    if(element == NULL || ulist_size(list) == 0)
        return -1;

    // remove the element from the list.
    *data = element->data;

    if(element == list->head){
        list->head = element->next;

        if(list->head == NULL)
            list->tail = NULL;
        else
            element->next->prev = NULL;
    }else{
        // handle removal from other than the head of the list.

        element->prev->next = element->next;

        if(element->next == NULL)
            list->tail = element->prev;
        else
            element->next->prev = element->prev;
    }

    free(element);

    list->size--;

    return 0;
}

