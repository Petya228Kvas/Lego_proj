#include <stdio.h>
#include "bitatom.h"


void lego_bit(POINT *obj, UI num, UI met, UI grp, UI per){
    obj->x=0;
    obj->y=0;
    obj->z=0;
    
    if(num < 0 || num > 118 ){
        obj->at->atom_num = 118;
    } else obj->at->atom_num = num;
    
    if(met < 0 || met > 1 ){
        obj->at->metal = 1;
    } else obj->at->metal = met;
    
    if(grp < 0 || grp > 18 ){
        obj->at->group= 18;
    } else obj->at->group = grp;
    
    if(per < 0 || per > 7 ){
        obj->at->period = 7;
    } else obj->at->period = per;

    printf("Коснтруктор: %u, %d, %u, %u\n", obj->at->atom_num, obj->at->metal, obj->at->group, obj->at->period );

}
void def_bit(POINT *obj){
    obj->x=0;
    obj->y=0;
    obj->z=0;

    obj->at->atom_num = 0;
    obj->at->metal = 0;
    obj->at->group = 0;
    obj->at->period = 0;

    printf("Коснтруктор: %u, %u, %u, %u\n", obj->at->atom_num, obj->at->metal, obj->at->group, obj->at->period );

}

void destr_bit(POINT *obj){
    obj->at->atom_num = 0;
    obj->at->metal = 0;
    obj->at->group = 0;
    obj->at->period = 0;
    free(obj->at);
    
    obj->x=0;
    obj->y=0;
    obj->z=0;
    free(obj);
    puts("Память очищена!\n");
}
void atom_destr(UI *atom){
    free(atom);
    puts("Память очищена!\n");
}

void p_ar(POINT *obj){
    printf("\n\tДанные объекта:\n Атомный номер: %u\n Метал/Неметал: %u\n Группа: %u\n Период: %u\n", obj->at->atom_num, obj->at->metal, obj->at->group, obj->at->period );
}


void add_at(UI *atom, UI num, UI grp, UI per, UI met){ //Конструктор вызывает сеттеры для инициализации объекта
    set_num(atom, num);
    set_grp(atom, grp);
    set_per(atom, per);
    set_met(atom, met);
}

void set_num(UI *atom, UI num){
    if(num < 0 || num > NUM_MAX){ // Если не удв-ет условиям, то присваивается максимальное значение
        *atom &= ~NUM_MASK; //Инверсия маски(Обнуляем биты соответствующему полю)
        *atom |= ((NUM_MAX << NUM_SHIFT) & NUM_MASK);
        //Сдвигаем Макс-ое значение на нужную позицию, благодоря маске не выходим за пределы поля
    }
    else{ 
        *atom &= ~NUM_MASK;
        *atom |= ((num << NUM_SHIFT) & NUM_MASK);
    }
}
void set_grp(UI *atom, UI grp){
    if(grp < 0 || grp > GRP_MAX){
        *atom &= ~GROUP_MASK;
        *atom |= ((GRP_MAX << GROUP_SHIFT) & GROUP_MASK);
    }
    else{ 
        *atom &= ~GROUP_MASK;
        *atom |= ((grp << GROUP_SHIFT) & GROUP_MASK);
    }
}
void set_per(UI *atom, UI per){
    if(per < 0 || per > PER_MAX){
        *atom &= ~PERIOD_MASK;
        *atom |= ((PER_MAX << PERIOD_SHIFT) & PERIOD_MASK);
    }
    else{ 
        *atom &= ~PERIOD_MASK;
        *atom |= ((per << PERIOD_SHIFT) & PERIOD_MASK);
    }
}
void set_met(UI *atom, UI met){
    if(met < 0 || met > MET_MAX){
        *atom &= ~METAL_MASK;
        *atom |= ((MET_MAX << 0) & METAL_MASK);
    }
    else{ 
        *atom &= ~METAL_MASK;
        *atom |= ((met << 0) & METAL_MASK);
    }
}

UI get_num(UI *atom){
    return ((*atom) & NUM_MASK) >> NUM_SHIFT;   //Вытаскиваем нужное значение сдвигом
}
UI get_grp(UI *atom){
    return ((*atom) & GROUP_MASK) >> GROUP_SHIFT;   
}
UI get_per(UI *atom){
    return ((*atom) & PERIOD_MASK) >> PERIOD_SHIFT;   
}
UI get_met(UI *atom){
    return ((*atom) & METAL_MASK) >> 0;   
}

void print_atom(UI *atom){
    UI num = get_num(atom);
    UI grp = get_grp(atom);
    UI per = get_per(atom);
    UI met = get_met(atom);

    printf("\n--Данные атома--\n");
    printf("Номер: %u\nГруппа: %u\nПериод: %u\nМеталл: %u\n\n", num, grp, per, met);
}
