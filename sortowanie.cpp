#include "sortowanie.hh"
template<typename typ>
void quicksort(typ tab[], int poczatek, int koniec){
    if(poczatek<koniec) {
        int i=poczatek;
        int j=koniec;
        int pivot=poczatek;
        while(i<j){
            while((i<=koniec)&&(tab[i]<=tab[pivot])){
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
	quicksort(tab, poczatek, j-1);
	quicksort(tab, j+1, koniec);
}   }
template<typename typ>
void scalanie(typ tab[],int poczatek, int ilosc_elem){
    if((ilosc_elem-1) > poczatek) { 
         int srodek=(poczatek+ilosc_elem)/2;
         int k=ilosc_elem-srodek;
    int *pomocnicza1=new int[srodek];
    int *pomocnicza2=new int[k];
    int m=0;
    int n=0;
    for(int i=poczatek;i<srodek;i++){
        pomocnicza1[m]=tab[i];
        m++;
    }
    for(int i=srodek;i<ilosc_elem;i++){
        pomocnicza2[n]=tab[i];
         n++;
    }
   scalanie(pomocnicza1,poczatek,srodek);
   scalanie(pomocnicza2,poczatek,k);
   
    m=0;
    n=0;
    int i=0;
    while((m<srodek)&&(n<k)){
if(pomocnicza1[m]<pomocnicza2[n]){
        tab[i]=pomocnicza1[m];
        m++;
}
else{
tab[i]=pomocnicza2[n];
        n++;
}
i++;
}
while(m<srodek){
    tab[i]=pomocnicza1[m];
        m++;
        i++;
}
while(n<k){
    tab[i]=pomocnicza2[n];
        n++;
        i++;
}
delete[] pomocnicza1;
delete[] pomocnicza2;
   }
   }
   template<typename typ>
void kopcowanie(typ *tab,int poczatek, int ilosc_elem){
          for(int i=1;i<ilosc_elem;i++){
int rodzic=(i-1)/2;
int aktualna=i;
while((tab[aktualna]>tab[rodzic])&&(rodzic>=0)){
    swap(tab[aktualna],tab[rodzic]);
aktualna=rodzic;
rodzic=(aktualna-1)/2;
}

          }
          
int wiekszy_elem=0;
          for(int i=ilosc_elem-1;i>0;i--){
          swap(tab[0],tab[i]);
          int j=0;
          int k=1;
          
          while(k<i){
          if((tab[k]<tab[k+1])&&(k+1<i)){
              wiekszy_elem=k+1;}
              else
              wiekszy_elem=k;
              if(tab[wiekszy_elem]>tab[j]){
              swap(tab[wiekszy_elem],tab[j]);
              j=wiekszy_elem;
              k=2*j+1;
          }
          else break;
          }
}
}
template<typename typ>
void introsort(typ tab[],int poczatek, int ilosc_elem,int Max){
    if(Max>0){
        int koniec=ilosc_elem-1;
        if(poczatek<koniec) {
        int i=poczatek;
        int j=koniec;
        int pivot=poczatek;
        while(i<j){
            while((i<=koniec)&&(tab[i]<=tab[pivot])){
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

   introsort(tab,poczatek, ilosc_elem,Max-1);}
       }
      else {
           kopcowanie(tab,poczatek,ilosc_elem);
}}


    
template void quicksort<int>(int*, int, int);
template void scalanie<int>(int*, int, int);
template void kopcowanie<int>(int*, int, int);
template void introsort<int>(int*, int, int,int);
