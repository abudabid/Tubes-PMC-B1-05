//Last Edit:    01 April 2019 16:44
//Library
#include <stdio.h>
#include <stdlib.h>

//Tipe bentukan
typedef struct koordinat{
    int x;
    int y;
}koordinat_t;

typedef struct komponen{
    char nama[10];
    koordinat_t kaki_1;
    koordinat_t kaki_2;
    koordinat_t kaki_3;                               //Hanya untuk transistor
}komponen_t;

typedef struct grid{                               //Variabel untuk grid matriks pcb
    char nama[10];
    char node[10];
}grid_t;






int main(){
    //Variabel-variabel
    int N,M;                                            //Ukuran matriks pcb    
    komponen_t pcb_komponen[100];                       //Array untuk menyimpan komponen-komponen
    int komponen_counter;                               //Counter untuk jumlah komponen
    int i,j;                                            //Counter untuk matriks


    


    printf("input N,M:");
    scanf("%d %d", &N,&M);
    grid_t pcb_layout[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("Masukkan komponen: %d %d: ",i,j);
            scanf(" %[^\n]%*c",pcb_layout[i][j].nama);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf(" %s ",pcb_layout[i][j].nama);
        }
        printf("\n");
    }


    
}




