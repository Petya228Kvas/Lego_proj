#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "point/point3d.h"
#include "contdict.h"
#include "bitatom/bitatom.h"
#include "point/point3d.c"
#include "bitatom/bitatom.c"
#include "contdict.c"

void bit_a();
void point_f();

int main(){
//   point_f();
//   bit_a();
   
    POINT_D *obj = d_create();
    
    d_put(obj, (void*)"first", (void*)"VOVA", 2, 2); 
    d_put(obj, (void*)44, (void*)949, 0, 0);
    d_put(obj, (void*)"two", (void*)"PETR", 2 ,2); 
    d_put(obj, (void*)93, (void*)9219, 0, 0);
    d_put(obj, (void*)"three", (void*)"SASHA", 2, 2); 
    d_put(obj, (void*)14, (void*)376, 0, 0);
    d_put(obj, (void*)"fiwe", (void*)"PAPA", 2, 2); 

    d_pr(obj);
  
    for(int i = 1; i<=DICT_SIZE-50; i++){
        d_put(obj, (void*)(intptr_t)i, (void*)(intptr_t)(i*2), T_INT, 0);
    } 
 

    printf("SIZE: %d\n", d_size(obj));
    
    printf("Search Value: %d\n", (int)(intptr_t)d_get(obj, (void*)8, 0));

    printf("Существует ли элемент с ключом %d: %s\n", 2, d_cont_k(obj, (void*)2, 0) ? "TRUE" :"FALSE");
    printf("SIZE: %d\n", d_size(obj));
    
    d_remove(obj, (void*)4, 0);
    d_remove(obj, (void*)6, 0);
    d_pr(obj);
    printf("Существует ли элемент с ключом %d: %s\n", 4, d_cont_k(obj, (void*)4, 0) ? "TRUE" :"FALSE");
    printf("SIZE: %d\n", d_size(obj));

    puts(">>>>>>>");
    void **keys = d_key(obj); 
    for(int i = 0; i< obj->at->ct->pair_size; i++){
        if(keys[i] != NULL){
            printf("KEY: %d\n", (int)(intptr_t)keys[i]);    
        }
    }
    void **values = d_value(obj);
    for(int i = 0; i < obj->at->ct->pair_size; i++){
        if(values[i] != NULL)
            printf("VALUE: %d\n", (int)(intptr_t)values[i]);
    }

    printf("%d", hash_char("two"));
    



    obj = d_clear(obj); 
    d_pr(obj);
    printf("%s\n", d_empty(obj) ? "CLEAR" : "NO CLEAR");
    free(obj);
    free(keys);
    free(values);

    POINT_D *obj1 = d_create();
    POINT_D *obj2 = d_create();
     for(int i = 1; i<=DICT_SIZE-75; i++){
        d_put(obj1, (void*)(intptr_t)i, (void*)(intptr_t)(i*2), T_INT, 0);
    }   
      for(int i = 1; i<=DICT_SIZE-50; i++){
        d_put(obj2, (void*)(intptr_t)i, (void*)(intptr_t)(i*3), T_INT, 0);
    }  
    d_pr(obj1);
    d_pr(obj2);

    

    obj1 = d_clear(obj1);
    obj2 = d_clear(obj2);
    free(obj1);
    free(obj2);
    return EXIT_SUCCESS;
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

void point_f(){
    point *obj1 = malloc(sizeof(point));
    lego_def(obj1); //конструктор дефолтный
    lego_print(obj1);

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
 
}
