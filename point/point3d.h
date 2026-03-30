#ifndef POINT_H 
#define POINT_H
#include "../bitatom/bitatom.h"

typedef struct {
    float x;
    float y;
    float z;
    ATOM *at;
} POINT;
 

void lego_def(POINT *ptr1);

void lego_print(POINT *ptr);
 
void lego(POINT *ptr2, float, float, float);

void lego_copy(POINT *ptr3, POINT *ptr2);

void _lego_dist(POINT *ptr);

void in_o(POINT *ptr);

void compr(POINT *, POINT *);

void setter(POINT *ptr, float x, float y, float z);

void inc(POINT *ptr);

void dec(POINT *ptr);

void dist(POINT *ptr1, POINT *ptr2);

void bias(POINT *, POINT *, POINT *);

void p_rand(POINT *);

void eiler(POINT *,float corner, char ch);

#endif
