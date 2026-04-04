#ifndef CONT_H
#define CONT_H
#include <stdbool.h>
#define DICT_SIZE 16381
#define GET_TIP(x) _Generic((x), \
                        int: 0, \
                        float: 1, \
                        double: 2, \
                        char: 3, \
                        default: 4 \
                   )
#define T_INT 0
#define T_DOUBLE 1
#define T_CHAR 2

typedef unsigned int UI;

typedef struct PAIR{
    void *key;
    void *value;
    int t_key;
    int t_value;
    struct PAIR *next;

}PAIR;

typedef struct{
    PAIR **head;
    int pair_size;

}DICT;

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
void d_put(POINT_D *obj, void* key, void* value, int k, int v);
UI hash_int(void* s);
UI hash_char(void* s);
bool d_empty(POINT_D *obj);
void d_pr(POINT_D *obj);
void *d_get(POINT_D *obj, void *key, int k);
bool d_cont_k(POINT_D *obj, void* key, int k);
void d_remove(POINT_D *obj, void* key, int k);
void **d_key(POINT_D *obj);
void **d_value(POINT_D *obj);
int get_t_key(POINT_D *obj, void *key);
int  get_t_value(POINT_D *obj, void *value);
POINT_D *d_copy(POINT_D *obj1, POINT_D *obj2);
#endif
