#include "contdict.h"
#include <string.h>
#include <stdlib.h>
#define DICT_SIZE 100000

POINT_D *d_create(){
    POINT_D *obj = malloc(sizeof(POINT_D)); 
    obj->at = malloc(sizeof(ATOM));
    obj->at->ct = malloc(sizeof(HASH_TABLE));

    obj->at->ct->
    obj->at->ct->hash_size = 0;
    obj->at->ct->pair_size = 0;
    return obj; 
}

int d_size(POINT_D *obj){
    return obj->at->ct->size;
}

void d_pr(POINT_D *obj){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }
    PAIR *cur = obj->at->ct->head;
    while(cur){
       printf("Addres: %p\n", cur);
       printf("Next: %p\n", cur->next);
       printf("KEY: %d\n", (int)(intptr_t)cur->key);
       printf("VALUE: %d\n", (int)(intptr_t)cur->value);
       puts("");
       cur = cur->next; 
    }
    
}

void *d_get(POINT_D *obj, void* k){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return NULL;
    }

    PAIR *cur = obj->at->ct->head;
    while(cur){
        if(cur->key == k || !strcmp((char*)cur->key, (char*)k)){
            return cur->value;
        }
        cur = cur->next;
    }
    return NULL;
}
bool d_empty(POINT_D *obj){
    return (obj->at->ct->size == 0 || obj->at->ct->head == NULL);
}
bool d_cont_k(POINT_D *obj, void *k){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return false;
    }
    PAIR *cur = obj->at->ct->head;
    puts("455");
    while(cur){
  
        if(cur->key == k ){
            return true;
        }
        if( GET_TIP((intptr_t*)k) == 3){
            puts("222222");
            if(!strcmp((char*)cur->key, (char*)k)){
                return true;
            }
        }
        cur = cur->next;
    }
    return false;
}

void d_free(POINT_D *obj){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }
    PAIR *cur = obj->at->ct->head;
    while(cur){
        PAIR *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(obj->at->ct);
    free(obj->at);
    free(obj);

    printf("Память очищена!\n");
}
void d_put(POINT_D *obj, void *k, void *v){
   /* if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }*/

    PAIR *cur = obj->at->ct->head;
    while(cur){
        if(cur->key == k /*|| !strcmp((char*)cur->key, (char*)k)*/){
            cur->value = v; return;
        }
        if(GET_TIP((intptr_t*)k)==3){
            puts("3333");
            if(!strcmp((char*)cur->key, (char*)k)){
                cur->value = v; return;
            }
        }
        cur=cur->next;
    }
    PAIR* new_p = malloc(sizeof(PAIR));
    new_p->key = k;
    new_p->value = v;
    new_p->next = obj->at->ct->head;
    obj->at->ct->head = new_p;
    obj->at->ct->size++;
}

void d_remove(POINT_D *obj, void* k){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }

    PAIR* cur = obj->at->ct->head;
    PAIR *prev = NULL;
    while(cur){
        if(cur->key == k || !strcmp((char*)cur->key, (char*)k)){
            if(prev) prev->next = cur->next;
            else obj->at->ct->head = cur->next;
            free(cur);
            obj->at->ct->size--;
            puts("Элемент удалён.");
            return;
        }
        prev = cur; cur = cur->next;
    }
    
}
POINT_D *d_clear(POINT_D *obj){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return obj;
    }
    PAIR *cur = obj->at->ct->head;
    while(cur != NULL){
        PAIR *next = cur->next;
        free(cur);
        cur = next;
    }      
    obj->at->ct->head = NULL;
    obj->at->ct->size= 0;
    
    printf("\nСписок очищен!\n");
    
    return obj;
}

void **d_key(POINT_D *obj){
    void **keys = malloc(sizeof(void*)* obj->at->ct->size);
    PAIR *cur = obj->at->ct->head;
    for(int i =0; i<obj->at->ct->size; i++){
        keys[i]=cur->key;
        cur = cur->next;
    }
    return keys;
}
void **d_value(POINT_D *obj){
    void **values= malloc(sizeof(void*)* obj->at->ct->size);
    PAIR *cur = obj->at->ct->head;
    for(int i =0; i<obj->at->ct->size; i++){
        values[i]=cur->value;
        cur = cur->next;
    }
    return values;
}   
UI hash(void* s){
    return (uintptr_t)s % DICK_SIZE;    
}
