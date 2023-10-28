#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int* zeroize(int *mass, size_t size){
    for (int i = 0; i < size; ++i) {
        mass[i] = 0;
    }
    return mass;
}

void fill(int *mass, size_t size){
    for (int i = 0; i < size; ++i) {
        scanf("%d", &mass[i]);
    }
}

void fill_random(int *mass, size_t size, int a, int b){
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        mass[i] = rand() % (b - a + 1) + a;
    }
}

void print(int *mass, size_t size){
    for (int i = 0; i < size; ++i) {
        printf("%d ", mass[i]);
    }
    printf("\n");
}

int max(int* mass, size_t size){
    int max = 0;
    for(int i = 0; i < size; ++i){
        if(mass[i] > max){
            max = mass[i];
        }
    }
    return max;
}

float average(int* mass, size_t size, int a, int b){
    int sum = 0;
    int count = 0;
    for(int i = a-1; i < b; ++i){
        sum += mass[i];
        count++;
    }
    return (float)sum / count;
}

//Вспомогательная функция
bool find_elem(int* mass, size_t size, int elem){
    for(int i = 0; i < size; ++i){
        if(mass[i] == elem){
            return true;
        }
    }
    return false;
}


int main() {
    size_t size_m1 = 10;
    size_t size_m2 = 8;
    size_t size_m3 = 6;
    int m1[size_m1];
    int m2[size_m2];
    int m3[size_m3];
    fill(m1, size_m1);
    fill(m2, size_m2);
    fill(m3, size_m3);
    int a, b;
    scanf("%d %d", &a, &b);
    //printf("\n");
    printf("%d %d %d\n", max(m1, size_m1), max(m2, size_m2), max(m3, size_m3));
    printf("%.1f\n", average(m3, size_m3, a, b));
    int res[9];
    int k = 0;
    for(int i = 12; i < 21; ++i){
        int count = 0;
        if(find_elem(m1, size_m1, i)){
            count++;
        }
        if(find_elem(m2, size_m2, i)){
            count++;
        }
        if(find_elem(m3, size_m3, i)){
            count++;
        }
        if(count >= 2) {
            res[i - 12] = i;
        }
        else{
            res[i - 12] = 0;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if(res[i] != 0) {
            if(i != 8) {
                printf("%d ", res[i]);
            }
            else{
                printf("%d\n", res[i]);
            }
        }
    }
    printf("\n");
    return 0;
}

