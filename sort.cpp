#include "sort.h"
using namespace std;
/*Quicksort algorithm*/
template<typename typ>
void quicksort(typ tab[], int begin, int end){
    int i,j,pivot;
    if(begin<end) {
        i=begin;
        j=end;
        pivot=begin;

        // Loop to partition the table
        while(i<=j){
            while((i<=end)&&(tab[i]<=tab[pivot])){
                i++;
            }
            while(tab[j]>tab[pivot]){
                j--;
            }
            if(i<j){
                swap(tab[i],tab[j]);
            }
            
        }
    swap(tab[pivot],tab[j]);
    //sort the left part
	quicksort(tab, begin, j-1);
    //sort the right part
	quicksort(tab, j+1, end);
    }   
}

/*Merge sort algorithm*/
template<typename typ>
void merge_sort(typ tab[],int begin, int number_of_elem){
    if((number_of_elem-1) > begin) { 
        //Divide the table into two parts
        int middle=(begin+number_of_elem)/2;
        int k=number_of_elem-middle;
        int *helper1=new int[middle];
        int *helper2=new int[k];
        int m=0;
        int n=0;
        // copy elements into the helper tables
        for(int i=begin;i<middle;i++){
            helper1[m]=tab[i];
            m++;
        }
        for(int i=middle;i<number_of_elem;i++){
            helper2[n]=tab[i];
            n++;
        }
        //recursively sort the left part
        merge_sort(helper1,begin,middle);
        //recursively sort the right part
        merge_sort(helper2,begin,k);  
        m=0;
        n=0;
        int i=0;
        //merge the sorted parts
        while((m<middle)&&(n<k)){
            if(helper1[m]<helper2[n]){
                tab[i]=helper1[m];
                m++;
            }
            else{
                tab[i]=helper2[n];
                n++;
            }
            i++;
        }
         //copy any remaining elements from the left and right helper tables
        while(m<middle){
            tab[i]=helper1[m];
            m++;
            i++;
        }
        while(n<k){
            tab[i]=helper2[n];
            n++;
            i++;
        }
        //free the memory
        delete[] helper1;
        delete[] helper2;
   }
}

/*Heap sort algorithm*/
template<typename typ>
void heap_sort(typ *tab,int begin, int number_of_elem){
    //build the heap by ensuring that each parent node is larger than its children
    for(int i=1;i<number_of_elem;i++){
        int parent=(i-1)/2;
        int current=i;
       // Fix the heap by switching the current node with its parent if it's bigger
        while((tab[current]>tab[parent])&&(parent>=0)){
            swap(tab[current],tab[parent]);
            current=parent;
            parent=(current-1)/2;
        }
    }        
    int bigger_elem=0;
    //sort the table
    for(int i=number_of_elem-1;i>0;i--){
        swap(tab[0],tab[i]);
        int j=0;
        int k=1;
        // rebuild the heap for the remaining elements
        while(k<i){
            if((tab[k]<tab[k+1])&&(k+1<i)){
                bigger_elem=k+1;
            }
            else
                bigger_elem=k;
            // wwap the current node with its larger child if necessary
            if(tab[bigger_elem]>tab[j]){
                swap(tab[bigger_elem],tab[j]);
                j=bigger_elem;
                k=2*j+1;
            }
            else break;
          }
    }
}

/*Introsort algorithm*/
template<typename typ>
void introsort(typ tab[],int begin, int number_of_elem,int Max){
    if(Max>0){
        int end=number_of_elem-1;
        //perform the Quick Sort partitioning
        if(begin<end) {
            int i=begin;
            int j=end;
            int pivot=begin;
            while(i<j){
                while((i<=end)&&(tab[i]<=tab[pivot])){
                    i++;
                }
                while(tab[j]>tab[pivot]){
                    j--;
                }
                if(i<j){
                    swap(tab[i],tab[j]);
                }
                
            }
            swap(tab[pivot],tab[j]);
            //recursively sort the partitions, decreasing the recursion depth limit
            introsort(tab,begin, number_of_elem,Max-1);
        }
    }
    //switch to Heap sort
    else {
        heap_sort(tab,begin,number_of_elem);
    }
}


    
template void quicksort<int>(int*, int, int);
template void merge_sort<int>(int*, int, int);
template void heap_sort<int>(int*, int, int);
template void introsort<int>(int*, int, int,int);
