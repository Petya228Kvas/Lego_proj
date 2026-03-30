#ifndef BITATOM_H
#define BITATOM_H
#include <stdbool.h>

//#define FIRST
#define SECOND

#define METAL_MASK  0x0001 // 0000 0000 0000 0001
#define PERIOD_MASK 0x000E // 0000 0000 0000 1110
#define GROUP_MASK  0x01F0 // 0000 0001 1111 0000
#define NUM_MASK    0xFE00 // 1111 1110 0000 0000

#define PERIOD_SHIFT 1 
#define GROUP_SHIFT 4
#define NUM_SHIFT 9

#define NUM_MAX 118
#define GRP_MAX 18
#define MET_MAX 1
#define PER_MAX 7

typedef unsigned int UI;

#ifdef FIRST 
typedef struct{
    UI metal : 1;
    UI period : 3; //всего 7 периодов
    UI group : 5; // всего 18 групп
    UI atom_num : 7; // всего 118 элементов
    
} ATOM;
#endif
 

#ifdef SECOND
typedef struct{    //Выравнивание полей структры с помощью _Alignas
    _Alignas(4) bool metal;
    _Alignas(4) UI atom_num; // всего 118 элементов
    _Alignas(4) UI group; // всего 18 групп
    _Alignas(4) UI period; //всего 7 периодов
    DICT *dt; 
} ATOM;
#endif

typedef struct{
    float x, y, z;
    ATOM *at;
   
}POINT;


void lego_bit(POINT *obj, UI num, UI met, UI grp, UI per); //Конструктор
void def_bit(POINT *obj); // Дефолтный конструктор
void destr_bit(POINT *obj); //Деструктор
void p_ar(POINT *obj); // Вывод объекта

void atom_destr(UI *atom); // Деструктор
void add_at(UI *atom, UI num, UI grp, UI per, UI met); //Конструктор
void set_num(UI *atom, UI num); //Сеттеры
void set_grp(UI *atom, UI grp);
void set_per(UI *atom, UI per);
void set_met(UI *atom, UI met);

UI get_num(UI *atom); // Гетеры
UI get_grp(UI *atom);
UI get_per(UI *atom);
UI get_met(UI *atom);

void print_atom(UI *atom); // Вывод атома

#endif
