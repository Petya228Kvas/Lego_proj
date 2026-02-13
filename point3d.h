#ifndef MY_HEADER_FILE_H 
#define MY_HEADER_FILE_H
typedef struct {
    float x;
    float y;
    float z;
} point;

void lego_def(point *ptr1);

void lego_print(point *ptr);
 
void lego(point *ptr2, float, float, float);

void lego_copy(point *ptr3, point *ptr2);

void _lego_dist(point *ptr);

void in_o(point *ptr);

void compr(point *, point *);

void setter(point *ptr, float x, float y, float z);

void inc(point *ptr);

void dec(point *ptr);

void dist(point *ptr1, point *ptr2);

void bias(point *, point *, point *);

void p_rand(point *);

void eiler(point *,float corner, char ch);

#endif
