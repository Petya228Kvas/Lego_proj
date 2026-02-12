#include "point3d.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void lego_def(point *ptr1){    //Конструктор устанавливающий дефолтные значения полей
    ptr1->x=0.0;
    ptr1->y=0.0;
    ptr1->z=0.0;

    printf("Конструктор Дефолтный:\n");
    printf("%.1f %.1f %.1f\n\n", ptr1->x, ptr1->y, ptr1->z);

}

void lego(point *ptr1, float a, float b, float c){ //стандартный конструктор
    ptr1->x=a;
    ptr1->y=b;
    ptr1->z=c;
    
    printf("Конструктор обычный:\n");
    printf("%.1f %.1f %.1f\n\n", ptr1->x, ptr1->y, ptr1->z);
}
void _lego_dist(point *ptr){  //деструктор
    printf("Память очищена.\n");
    free(ptr);
}

void lego_copy(point *ptr3, point *ptr2){ //конструктор копирования
    ptr3->x = ptr2->x;
    ptr3->y = ptr2->y;
    ptr3->z = ptr2->z;

    printf("Конструктор копирования:\n");
    printf("%.1f %.1f %.1f\n\n", ptr3->x, ptr3->y, ptr3->z);
}

void in_o(point *ptr){ //метод ввода/вывода
    printf("Введите координаты(x y z): ");
    if(scanf("%f %f %f", &ptr->x, &ptr->y, &ptr->z) != 3){
        printf("~~~~Неправильный ввод, Артём Леонидович!~~~~\n");
        return;
    }

    printf("Ваши координаты: x: %.1f; y: %.1f; z: %.1f\n", ptr->x, ptr->y, ptr->z);

}

void compr(point *ptr1, point *ptr2){ //метод сравнения точек 
    if(ptr1->x > ptr2->x) printf("obj4(x) больше obj5(x)\n\n");
    else if(ptr1->x < ptr2->x) printf("obj4(x) меньше obj5(x)\n\n");
    else printf("X равны\n\n");

    if(ptr1->y > ptr2->y) printf("obj4(y) больше obj5(y)\n\n");
    else if(ptr1->y < ptr2->y) printf("obj4(y) меньше obj5(y)\n\n");
    else printf("Y равны\n\n");

    if(ptr1->z > ptr2->z) printf("obj4(z) больше obj5(z)\n\n");
    else if(ptr1->z < ptr2->z) printf("obj4(z) меньше obj5(z)\n\n");
    else printf("Z равны\n\n");

}
void setter(point *ptr, float x, float y, float z){ //сеттер(проверка значений и присваивание им значения)
    if(x < 100 && y < 100 && z < 100){
        ptr->x = x;
        ptr->y = y;
        ptr->z = z;
        printf("Ваши координаты от сеттера: x: %.1f; y: %.1f; z: %.1f\n\n", ptr->x, ptr->y, ptr->z);
 
    }
    else {
        printf("Слишком большие точки или точка!\n\n");
    }
}

void inc(point *ptr){ //инкрементирование координат точек
    printf("Ваши координаты до инкрементации были такими: x: %.1f; y: %.1f; z: %.1f\n", ptr->x, ptr->y, ptr->z);
    ptr->x++;
    ptr->y++;
    ptr->z++;
    printf("Ваши координаты стали такими после инкрементации: x: %.1f; y: %.1f; z: %.1f\n", ptr->x, ptr->y, ptr->z);

}
void dec(point *ptr){ // декрементирование координат точек
    printf("Ваши координаты до декрементации были такими: x: %.1f; y: %.1f; z: %.1f\n", ptr->x, ptr->y, ptr->z);
    ptr->x--;
    ptr->y--;
    ptr->z--;
    printf("Ваши координаты стали такими после декрементации: x: %.1f; y: %.1f; z: %.1f\n", ptr->x, ptr->y, ptr->z);

}

void dist(point *ptr1, point *ptr2){ // определение дистанции между точками
    float ptr, a, b, c;
    a = (ptr2->x - ptr1->x); 
    b = (ptr2->y - ptr1->y); 
    c = (ptr2->z - ptr1->z); 
    ptr = a*a + b*b + c*c;
    printf("Дистанция от одной точки до другой равна: %.1f\n\n", sqrt(ptr));
}
void bias(point *ptr, point *new, point *vec){ // сдвиг точки по вектору
    new->x = ptr->x + vec->x;
    new->y = ptr->y + vec->y;
    new->z = ptr->z + vec->z;
    printf("Точка сместилась по координатам: х: %.1f; y: %.1f; z: %.1f.\n\n", new->x, new->y, new->z);
}
void p_rand(point *ptr){ // генерация точки в рандомном месте
    srand(time(NULL));
    ptr->x = rand() % 100;
    ptr->y = rand() % 100;
    ptr->z = rand() % 100;
    printf("Точка была создана случайно в координатах: x: %.1f; y: %.1f; z: %.1f.\n\n", ptr->x, ptr->y, ptr->z);
}
void eiler(point *ptr, float corner, char ch){ //поворот точка в пространстве Эйлера
    float rad;
    rad = corner * M_PI/180;
    char axis = tolower(ch);
    switch(axis){
    // Поворот вокруг Z
        case 'z': ptr->x = ptr->x*cos(-rad) - ptr->y*sin(-rad);
                  ptr->y = ptr->x*sin(-rad) + ptr->y*cos(-rad);
                  ptr->z = ptr->z; 
                  break;
    // Поворот вокруг Х
        case 'x': ptr->x = ptr->x; 
                  ptr->y = ptr->y*cos(-rad) - ptr->z*sin(-rad);
                  ptr->z = ptr->y*sin(-rad) + ptr->z*cos(-rad);
                  break;
    // Поворот вокруг У
        case 'y': ptr->x = ptr->x*cos(-rad) + ptr->z*sin(-rad);
                  ptr->y = ptr->y; 
                  ptr->z = -ptr->x*sin(-rad) + ptr->z*cos(-rad);
                  break;
        default: printf("Неправильная ось вращение!\n"); return;

}   
    printf("Точка после поворота по часовой стрелке в пространстве Эйлера по оси %c: x: %.1f; y: %.1f; z: %.1f.\n\n", axis, ptr->x, ptr->y, ptr->z);
}
