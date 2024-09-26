#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <math.h>
template<typename typ>
void quicksort(typ tab[], int begin, int number_of_elem);
template<typename typ>
void merge_sort(typ tab[],int begin, int number_of_elem);
template<typename typ>
void introsort(typ tab[],int begin, int number_of_elem,int Max);
template<typename typ>
void heap_sort(typ *tab,int begin, int number_of_elem);