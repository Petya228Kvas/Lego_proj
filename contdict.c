#include "contdict.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

POINT_D *d_create(){
    POINT_D *obj = malloc(sizeof(POINT_D)); 
    obj->at = malloc(sizeof(ATOM_D));
    obj->at->ct = malloc(sizeof(DICT));

    obj->at->ct->pair_size = 0;
    obj->at->ct->head = calloc(DICT_SIZE, sizeof(PAIR*));

    return obj; 
}

//POINT_D* d_copy(POINT_D *obj1, POINT_D *obj2){
    
//}

int d_size(POINT_D *obj){
    return obj->at->ct->pair_size;
}
bool d_empty(POINT_D *obj){
    return obj->at->ct->pair_size==0;
}
UI hash_int(void* s){

    return  ((unsigned int)(*(int*)s)*2654435761u) % DICT_SIZE;    
}
UI hash_char(void* s){
   const char *str = (const char*)s;
   UI hash = 5381;
   int c;
   while((c=*str++))
       hash = ((hash << 5)+hash) +c;
   return hash % DICT_SIZE;
    
}

void **d_key(POINT_D *obj){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return NULL;
    }

    void **keys = malloc(sizeof(void*)*DICT_SIZE);
    int index = 0;
    for(int i =0; i< DICT_SIZE; i++){
        PAIR* cur= obj->at->ct->head[i];
        while(cur != NULL){
            keys[index++] = cur->key;
            cur = cur->next;
        }
    }
    printf("Массив ключей заполнен!\n");
    return keys;
}
void **d_value(POINT_D *obj){
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return NULL;
    }

    void **values= malloc(sizeof(void*)*DICT_SIZE);
    int index = 0;
    for(int i =0; i< DICT_SIZE; i++){
        PAIR* cur= obj->at->ct->head[i];
        while(cur != NULL){
            values[index++] = cur->value;
            cur = cur->next;
        }
    }
    printf("Массив значений заполнен!\n");
    return values;
}
void d_remove(POINT_D *obj, void *key, int k){
       if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }    
    if(!d_cont_k(obj, key, k)){
        puts("Такого ключа нет!");
        return;
    }
    UI i;
    if(k == T_INT){
        i = hash_int(key);
        printf("%u\n", i);
    }
    else if(k == T_CHAR){
        i = hash_char(key);
        printf("%u\n", i);
    }
    else{
        puts("Неизвестный тип!");
        return;
    }

    PAIR *cur = obj->at->ct->head[i];
    PAIR *prev = NULL;
    while(cur){
        if(cur->t_key == T_INT){
            if(cur->key == key){
                if(prev) prev->next = cur->next;
                else obj->at->ct->head[i] = cur->next;
                free(cur);
                obj->at->ct->pair_size--;
                puts("Элемент удалён!\n");
                return;
            }
        }
        else if(cur->t_key == T_CHAR){
            if(!strcmp((char*)cur->key, (char*)key)){
                if(prev) prev->next = cur->next;
                else obj->at->ct->head[i] = cur->next;
                free(cur);
                obj->at->ct->pair_size--;
                puts("Элемент удалён!\n");
                return;
            }
        }
        prev = cur; cur = cur->next;
    }

}

bool d_cont_k(POINT_D *obj, void *key, int k){
      if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return obj;
    }   
    UI i;
    if(k == T_INT){
        i = hash_int(key);
        printf("%u\n", i);
    }
    else if(k == T_CHAR){
        i = hash_char(key);
        printf("%u\n", i);
    }
    else{
        puts("Неизвестный тип!");
        return NULL;
    }

    PAIR *cur = obj->at->ct->head[i];
    while(cur){
        if(k == T_INT){
            if(cur->key == key)
                return true;
        }
        else if(k == T_CHAR){
            if(!strcmp((char*)cur->key, (char*)key))
                return true;
        }
        cur = cur->next;
    }
    return false;
}

void *d_get(POINT_D* obj, void *key, int k){
    if(!d_cont_k(obj, key, k)){
        puts("Такого ключа нет!");
        return NULL;
    }
    UI i;
    if(k == T_INT){
        i = hash_int(key);
        printf("%u\n", i);
    }
    else if(k == T_CHAR){
        i = hash_char(key);
        printf("%u\n", i);
    }
    else{
        puts("Неизвестный тип!");
        return NULL;
    }
    PAIR *cur = obj->at->ct->head[i];
    while(cur){
        if(k == T_INT){
            if(cur->key == key){
                return cur->value;
            }
        }
        else if(k == T_CHAR){
            if(!strcmp((char*)cur->key, (char*)key)){
                return cur->value;
            }
        }
        cur = cur->next;
    }
    return NULL;
    
}
int get_t_key(POINT_D *obj, void* key){
    for(int i = 0; i < DICT_SIZE; i++){
        PAIR *cur = obj->at->ct->head[i];
        while(cur){
            if(cur->t_key == T_INT && cur->key == key){
                return cur->t_key;
            }
            cur = cur->next;
        }
    }
    return 0;
}

void d_put(POINT_D* obj, void *key, void *value, int k, int v){
    UI i;
    if(k == T_INT){
        i = hash_int(key);
        printf("%u\n", i);
    }
    else if(k == T_CHAR){
        i = hash_char(key);
        printf("%u\n", i);
    }
    else{
        puts("Неизвестный тип!");
        return;
    }
    PAIR *cur = obj->at->ct->head[i];
    while(cur){
        if(k == T_INT){
            if(cur->t_key == T_INT && cur->key ==key){
                cur->t_value = k;
                cur->value = value;
                return;
            }
        }
        else if(k == T_CHAR){
            if(cur->t_key == T_CHAR && !strcmp((char*)cur->key, (char*)key)){
                cur->t_value = k;
                cur->value = value;
                return;
            }
        }
        cur = cur->next;
    }
    PAIR *new = malloc(sizeof(PAIR));
    if(new == NULL){
        printf("Ошибка выделения памяти!\n");
        return;
    }
    new->key = key;
    new->t_key = k;
    new->value = value;
    new->t_value = v;
    new->next = obj->at->ct->head[i];
    obj->at->ct->head[i] = new;
    obj->at->ct->pair_size++;
}
POINT_D *d_clear(POINT_D *obj){
     if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return obj;
    }
    for(int i = 0; i < obj->at->ct->pair_size; i++){
        PAIR *cur = obj->at->ct->head[i];
        while(cur){
            PAIR* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(obj->at->ct->head);
    obj->at->ct->pair_size = 0;
    puts("\nСписок очищен!\n");
    return obj;
}
void d_pr(POINT_D *obj){

     if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    }   
    for(int i =0; i<DICT_SIZE; i++){
        PAIR *cur = obj->at->ct->head[i];
        while(cur){
            printf("Index: %d\n", i);
            printf("Addres: %p\n", cur);
            printf("Next: %p\n", cur->next);
            if(cur->t_key == T_INT)
                printf("KEY: %d\n", (int)(intptr_t)cur->key);
            else if(cur->t_key == T_CHAR)
                printf("KEY: %s\n", (char*)cur->key);
            printf("t_key: %d\n", cur->t_key);
            if(cur->t_value == T_INT)
                printf("VALUE: %d\n", (int)(intptr_t)cur->value);
            else if(cur->t_value == T_CHAR)
                printf("VALUE: %s\n", (char*)cur->value);
            printf("t_value: %d\n", cur->t_value);
            puts("");
            cur = cur->next;  
        }
    }
}
/*
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
    return (obj->at->ct->pair_size == 0);
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
    if(d_empty(obj)){ 
        puts("Словарь пуст!\n");
        return;
    

    PAIR *cur = obj->at->ct->head;
    while(cur){
        if(cur->key == k || !strcmp((char*)cur->key, (char*)k)){
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
*/
