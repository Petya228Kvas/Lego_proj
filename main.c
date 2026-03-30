#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point/point3d.h"
#include "bitatom/bitatom.h"
#include "contdict.h"
#include "point/point3d.c"
#include "bitatom/bitatom.c"
#include "contdict.c"

void bit_a();
void POINT_f();

int main(){
   POINT_f();
//   bit_a();


   return 0;

}

void bit_a(){
    
    printf("%zu\n", sizeof(ATOM));

//Созда ём объект структуры POINT
    POINT *obj1 = malloc(sizeof(POINT));
    obj1->at = malloc(sizeof(ATOM)); // В нём же создаём объект типа struct ATOM
    lego_bit(obj1, 101, 1, 8, 5); //Инициализируем объекта конструктором 
    destr_bit(obj1); // Вызов деструктора

    POINT *obj2 = malloc(sizeof(POINT)); // Также второй объект
    obj2->at = malloc(sizeof(ATOM));
    def_bit(obj2); // Дефолтный конструктор
    destr_bit(obj2);

    POINT *obj3 = malloc(sizeof(POINT));
    obj3->at = malloc(sizeof(ATOM));
    POINT *obj4 = malloc(sizeof(POINT));
    obj4->at = malloc(sizeof(ATOM));
    lego_bit(obj3, 102, 1, 9, 6);
    lego_bit(obj4, 132, 4, 19, 9); //Демонстрация того, если будет превышено значение

#ifdef SECOND   
// Для оценки на 4.
// Показ адресов полей объекта.
    printf("& num: %p\n", &obj3->at->atom_num);  
    printf("& metal: %p\n", &obj3->at->metal); 
    printf("& group: %p\n", &obj3->at->group); 
    printf("& period: %p\n", &obj3->at->period); 
    printf("& x: %p\n", &obj3->x); 
    printf("& y: %p\n", &obj3->y); 
    printf("& z: %p\n", &obj3->z); 
#endif

    printf("Размер структуры: %zu байт\n", sizeof(obj3->at));
    printf("Выравнивание структуры: %zd\n", _Alignof(obj3->at));

    p_ar(obj3); //Вывод данных атома
   
    destr_bit(obj3);
    destr_bit(obj4);

    puts("~~Оценка 5~~");

    UI *iron = malloc(sizeof(UI)); //Создание динамической переменной
    add_at(iron, 100, 15, 2, 0); // Инициализация переменной значениями
    print_atom(iron); // Вывод атома
    set_num(iron, 22); // Изменение данных атома по отдельности
    set_met(iron, 1);
    set_per(iron, 10);
    set_grp(iron, 55);
    print_atom(iron);
    atom_destr(iron);//деструктор

 
}

void POINT_f(){
    POINT *obj1 = malloc(sizeof(POINT));
    lego_def(obj1); //конструктор дефолтный
    lego_print(obj1);

    POINT *obj2 = malloc(sizeof(POINT));
    lego(obj2, 2, 3.5, 7); //обычный конструктор 

    POINT *obj3 = malloc(sizeof(POINT));
    lego_copy(obj3, obj2); //конструктор копирования

    _lego_dist(obj1);
    _lego_dist(obj2); //очистка объектов(ресурсов)
    _lego_dist(obj3);

    puts("\n----Методы на оценку \"3\".----\n\n"); 
    POINT *obj4 = malloc(sizeof(POINT));
    POINT *obj5 = malloc(sizeof(POINT));
    POINT *obj6 = malloc(sizeof(POINT));
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
    POINT *obj7 = malloc(sizeof(POINT));
    POINT *obj8 = malloc(sizeof(POINT));

    POINT *obj9 = malloc(sizeof(POINT));
    POINT *objnew = malloc(sizeof(POINT));
    POINT *vec1 = malloc(sizeof(POINT));
    POINT *obj10 = malloc(sizeof(POINT));
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
    POINT *obj11 = malloc(sizeof(POINT));
   /* POINT *new_corner1 = malloc(sizeof(POINT));
    POINT *new_corner2 = malloc(sizeof(POINT));
    POINT *new_corner3 = malloc(sizeof(POINT));
 */ in_o(obj11);  //заполняем поля объекта
    eiler(obj11, 30, 'z'); // крутим точку вокруг всех осей
    eiler(obj11, 30, 'x');
    eiler(obj11, 30, 'y');

    _lego_dist(obj11);
 
}
