#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point3d.h"
#include "point3d.c"

int main(){
    point *obj1 = malloc(sizeof(point));
    lego_def(obj1); //конструктор дефолтный
    

    point *obj2 = malloc(sizeof(point));
    lego(obj2, 2, 3.5, 7); //обычный конструктор 

    point *obj3 = malloc(sizeof(point));
    lego_copy(obj3, obj2); //конструктор копирования

    _lego_dist(obj1);
    _lego_dist(obj2); //очистка объектов(ресурсов)
    _lego_dist(obj3);

    puts("\n----Методы на оценку \"3\".----\n\n"); 
    point *obj4 = malloc(sizeof(point));
    point *obj5 = malloc(sizeof(point));
    point *obj6 = malloc(sizeof(point));
    in_o(obj4); //метод ввод/вывод
    lego(obj5, 9, 1, 4);
    compr(obj4, obj5); //сравнение точек
    setter(obj6, 9, 9, 10); //сеттер, проверка точки на правильное значение и присваивание значения
    inc(obj6); //инкрементирование координат
    dec(obj6); //декрементирование координат
        
    _lego_dist(obj4);
    _lego_dist(obj5); //очистка памяти
    _lego_dist(obj6);

    puts("\n----Методы на оценку \"4\".----\n\n"); 
    point *obj7 = malloc(sizeof(point));
    point *obj8 = malloc(sizeof(point));

    point *obj9 = malloc(sizeof(point));
    point *objnew = malloc(sizeof(point));
    point *vec1 = malloc(sizeof(point));
    point *obj10 = malloc(sizeof(point));
    in_o(obj7); //ввод/ввывод
    in_o(obj8);
    dist(obj7, obj8); //определение дистанции от одной точки до другой

    in_o(obj9);
    in_o(vec1);
    bias(obj9, objnew, vec1); //смещение точки по заданному вектору
    p_rand(obj10); // генерация точки в рандомном месте

    _lego_dist(obj7);
    _lego_dist(obj8);
    _lego_dist(obj9);   // очистка всех использованных объектов
    _lego_dist(objnew);
    _lego_dist(vec1);
    _lego_dist(obj10);

    puts("\n----Методы на оценку \"5\".----\n\n"); 
    point *obj11 = malloc(sizeof(point));
   /* point *new_corner1 = malloc(sizeof(point));
    point *new_corner2 = malloc(sizeof(point));
    point *new_corner3 = malloc(sizeof(point));
 */ in_o(obj11);  //заполняем поля объекта
    eiler(obj11, 30, 'z'); // крутим точку вокруг всех осей
    eiler(obj11, 30, 'x');
    eiler(obj11, 30, 'y');

    _lego_dist(obj11);
    return 0;
}
