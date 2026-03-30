#ifndef CONT_H
#define CONT_H
#include <stdbool.h>

#define GET_TIP(x) _Generic((x), \
                        int: 0, \
                        float: 1, \
                        double: 2, \
                        default: 3 \
                   )

typedef unsigned int UI;

typedef struct PAIR{
    void *key;
    void *value;
    struct PAIR *next;

}PAIR;

typedef struct{
    PAIR *head;
    int size;

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
void d_free(POINT_D *obj);
void d_put(POINT_D *obj, void* k, void *v);


#endif
