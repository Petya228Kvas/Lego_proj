#include <stdbool.h>
#ifndef CONT_H
#define CONT_H
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
/*
typedef struct{    //Выравнивание полей структры с помощью _Alignas
    _Alignas(4) bool metal;
    _Alignas(4) UI atom_num; // всего 118 элементов
    _Alignas(4) UI group; // всего 18 групп
    _Alignas(4) UI period; //всего 7 периодов
    DICT *cont;
 
}ATOM_D;

typedef struct{
    float x, y, z;
    ATOM_D *at;

}POINT_D;
*/


#endif
