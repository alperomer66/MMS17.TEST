#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// structura na car
typedef struct {
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

// leksigografsko sravnenie po nizhodyasht red
int compareByModelAscending(const void* a, const void* b) {
    return strcmp(((const Car*)a)->model, ((const Car*)b)->model); //smenyame mestata na a i b  ->
}

// leksicografsko sravnenie po nizhodyasht red
int compareByModelDescending(const void* a, const void* b) {
    return strcmp(((const Car*)b)->model, ((const Car*)a)->model);
}

// max speeed vuzhodyasht
int compareByMaxSpeedAscending(const void* a, const void* b) {
    return ((const Car*)a)->maxspeed - ((const Car*)b)->maxspeed;
}

// obratnoto na gornoto
int compareByMaxSpeedDescending(const void* a, const void* b) {
    return ((const Car*)b)->maxspeed - ((const Car*)a)->maxspeed;
}

// cena - vuzhodyasht red
int compareByPriceAscending(const void* a, const void* b) {
    if (((const Car*)a)->price < ((const Car*)b)->price) return -1;
    if (((const Car*)a)->price > ((const Car*)b)->price) return 1;
    return 0;
}

//obratnoto na gornoto
int compareByPriceDescending(const void* a, const void* b) {
    if (((const Car*)b)->price < ((const Car*)a)->price) return -1;
    if (((const Car*)b)->price > ((const Car*)a)->price) return 1;
    return 0;
}

//nachini za sravnenie v konzolata izpirame 
int (*comparators[6])(const void*, const void*) = {
    compareByModelAscending, //1
    compareByModelDescending,//2                       //// !!!! proveri vsckii dali rabotyat!!!!!
    compareByMaxSpeedAscending,//3
    compareByMaxSpeedDescending,//4
    compareByPriceAscending,//5
    compareByPriceDescending//6
};


int (*getComparator(int n))(const void*, const void*) {
    if (n >= 1 && n <= 6) {
        return comparators[n - 1];
    } else {
        return NULL;
    }
}

int main() {
    // 10cars arr
    Car cars[10];
    // random
    for (int i = 0; i < 10; i++) {
        sprintf(cars[i].model, "Car%d", i+1);
        cars[i].maxspeed = rand() % 201 + 100;
        cars[i].price = (rand() % 990001) / 100.0 + 1000.0; 
    }


    printf("Несортиран масив:\n");
    for (int i = 0; i < 10; i++) {
        printf("Марка: %s, Макс. скорост: %d, Цена: %.2f\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    int choice;
    printf("\nИзберете начин на сортиране (1-6): ");
    scanf("%d", &choice);

    // proverka za validnost na izbora 1-6
    if (choice < 1 || choice > 6) {
        printf("Невалиден избор. Изход...\n");
        return 1;
    }

    int (*comparator)(const void*, const void*) = getComparator(choice);

    //  qsort()
    qsort(cars, 10, sizeof(Car), comparator);

    printf("\nСортиран масив:\n");
    for (int i = 0; i < 10; i++) {
        printf("Марка: %s, Макс. скорост: %d, Цена: %.2f\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}
