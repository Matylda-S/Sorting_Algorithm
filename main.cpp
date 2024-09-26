#include "sort.h"
#include <chrono>
#include <fstream>
#define DataType int
using namespace std;

/*Function that checks if an tableis sorted */
template<typename typ>
void check(typ tab[],int number_of_elem){
    for(int i=0;i<number_of_elem-1;i++){
        if(tab[i]>tab[i+1]){
            cout<<"A table is not sorted";
            cin.get();
            exit(1);
        }
    }
}

/*Function that sorts a table*/
template<typename typ>
void sort_p(typ tab[],int number_of_elem,float percentage){
    int a=number_of_elem*percentage/100;
    sort(tab,tab+a);
}

/*Function that sorts a table in a riverse order*/
template<typename typ>
void reverse_sort(typ tab[],int end){
    sort(tab,tab+end+1);
    for(int i=0;i<=end/2;i++){
        swap(tab[i],tab[end-i]);
    }
}

/*Function that creates a table*/
template<typename typ>
typ *create_table(int number_of_elem){
    return new typ[number_of_elem];
}

/*Function that delete a table*/
template<typename typ>
void delete_table(typ tab[]){
    delete[] tab;
}

/*Function that prints a table*/
template<typename typ>
void show_table(typ tab[],int number_of_elem){
       for(int i=0;i<number_of_elem;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

/*Function that fills table with random values*/
template<typename typ>
void fill_random(typ tab[],int number_of_elem){
    srand(time(NULL)*getpt());
    for(int i=0;i<number_of_elem;i++){
        tab[i]=rand()%100000;
        
    }
}

/*Function that measures the time of merge sort*/
template<typename typ>
double time_merge_sort(typ tab[],int begin,int number_of_elem){
  auto t_start=chrono::high_resolution_clock::now();
    merge_sort(tab,begin,number_of_elem);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
/*Function that measures the time of quicksort*/
template<typename typ>
double time_quicksort(typ tab[],int begin,int number_of_elem){
    auto t_start=chrono::high_resolution_clock::now();
    quicksort(tab,begin,number_of_elem-1);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
/*Function that measures the time of introsort*/
template<typename typ>
double time_introsort(typ tab[],int begin,int number_of_elem){
    auto t_start=chrono::high_resolution_clock::now();
    int Max=2*log2(number_of_elem);
    introsort(tab,begin,number_of_elem,Max);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
/*Function that measures the time of heap sort*/
template<typename typ>
double time_heap_sort(typ tab[],int begin,int number_of_elem){
    auto t_start=chrono::high_resolution_clock::now();
    heap_sort(tab,begin,number_of_elem);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}

int main(){
    
    int number_of_tab;
    int number_of_elem=1000000;
    DataType *tab=create_table<DataType>(number_of_elem);
    DataType *tab_2=create_table<DataType>(number_of_elem);
    DataType *tab_3=create_table<DataType>(number_of_elem);
    DataType *tab_4=create_table<DataType>(number_of_elem);
    int begin=0;
    float a,b,c,d;
    fill_random<DataType>(tab, number_of_elem);
    a=time_merge_sort(tab,begin,number_of_elem);
    cout<<"time merge sort: "<<a<<endl;
    check(tab,number_of_elem);
    delete_table(tab);
    fill_random<DataType>(tab_2, number_of_elem);
    b=time_quicksort(tab_2,begin,number_of_elem);
    cout<<"time quicksort: "<<b<<endl;
    check(tab_2,number_of_elem);
    delete_table(tab_2);
    fill_random<DataType>(tab_3, number_of_elem);
    c=time_heap_sort(tab_3,begin,number_of_elem);
    cout<<"time heap sort: "<<c<<endl;
    check(tab_3,number_of_elem);
    delete_table(tab_3);
    d=time_introsort(tab_4,begin,number_of_elem);
    cout<<"time introsort: "<<d<<endl;
    check(tab_4,number_of_elem);
    delete_table(tab_4);


}