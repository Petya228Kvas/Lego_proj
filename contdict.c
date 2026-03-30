#include "contdict.h"
#include <string.h>

POINT_D *d_create(){
    POINT_D *obj = malloc(sizeof(POINT_D)); 
    obj->at = malloc(sizeof(ATOM));
    obj->at->ct = malloc(sizeof(DICT));

    obj->at->ct->head = NULL;
    obj->at->ct->size = 0;
    return obj; 
}

void d_free(POINT_D *obj){
    if(!obj) return;
    
    PAIR *cur = obj->at->ct->head;
    while(cur){
        PAIR *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(obj);
    printf("Память очищена!\n");
}
void d_put(POINT_D *obj, void *k, void *v){
    PAIR *cur = obj->at->ct->head;
    while(cur){
        if(cur->key == k || !strcmp((char*)cur->key, (char*)k)){
            cur->value = v; return;
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
