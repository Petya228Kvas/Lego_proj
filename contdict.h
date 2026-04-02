#ifndef CONT_H
#define CONT_H
#include <stdbool.h>
#define SIZE 5000
#define GET_TIP(x) _Generic((x), \
                        int: 0, \
                        float: 1, \
                        double: 2, \
                        char: 3, \
                        default: 4 \
                   )

typedef unsigned int UI;

typedef struct PAIR{
    void *key;
    void *value;
    struct PAIR *next;

}PAIR;

typedef struct{
    PAIR **head;
    int hash_size;
    int pair_size;

}HASH_TABLE;

typedef struct{    //Выравнивание полей структры с помощью _Alignas
    _Alignas(4) bool metal;
    _Alignas(4) UI atom_num; // всего 118 элементов
    _Alignas(4) UI group; // всего 18 групп
    _Alignas(4) UI period; //всего 7 периодов
    DICT *ct;
 
}ATOM_D;

typedef struct{
    float x, y, z;
    ATOM_D *at;

}POINT_D;


POINT_D *d_create();
POINT_D *d_clear(POINT_D *obj); 
int d_size(POINT_D *obj);
void d_free(POINT_D *obj);
void d_put(POINT_D *obj, void* k, void *v);
void *d_get(POINT_D *obj, void *k);
bool d_cont_k(POINT_D *obj, void* k);
bool d_empty(POINT_D *obj);
void d_remove(POINT_D *obj, void* k);
void d_pr(POINT_D *obj);
void **d_key(POINT_D *obj);
void **d_value(POINT_D *obj);
UI hash(void* s);
#endif
