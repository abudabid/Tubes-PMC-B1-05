#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//typedef grid{
//    char nama[10];
//    char node[10];
//}grid_t;
//
////Variable global
//grid_t pcb_routing;

int main(){
    //Deklarasi variable
    int i=0, j=0, k=0, l=0, IndKoma, InKoorLength;
    char simbol[160];
    char InKoor[5],s1[2],s2[2];
    struct point {
        int x,y;
    };

    struct point koordinat[40][40];


    printf("[Mode Routing]\n");
    printf("Isi `q` atau `Q` untuk kembali ke menu\n");
    printf("Isi `n` atau `N` untuk memulai pada simpul (node) baru\n");
    simbol[i]='a';

    //Ngebaca simbolll
    //Kalo simbol salah baca lagi
    InKoor[0]="a";
    do{
            j=0;
            do{
                printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,)): ");
                scanf(" %c", &simbol[i]);
            }
            while (!(  simbol[i] == '!' ||
                       simbol[i] == '@' ||
                       simbol[i] == '#' ||
                       simbol[i] == '$' ||
                       simbol[i] == '%' ||
                       simbol[i] == '^' ||
                       simbol[i] == '&' ||
                       simbol[i] == '*' ||
                       simbol[i] == ',' ||
                       simbol[i] == 'n' ||
                       simbol[i] == 'N' ||
                       simbol[i] == 'q' ||
                       simbol[i] == 'Q'     ));

                    //Tes hasil simbol
                    printf("hasil %c\n",simbol[i]);
                    //

       //Ngebaca Koordinattttttttt

            do{
            printf("Koordinat %d: ", (j+1));
            scanf(" %s", InKoor);
                    InKoorLength=strlen(InKoor);
                    if (InKoorLength!=1){
                    // mengubah string menjadi integer
                    for (l = 0; InKoor[l] != ','; ++l) {
                        // copying the characters by
                        // character to str2 from str1
                        s1[l] = InKoor[l];
                        IndKoma=l;
                    }
                    s1[IndKoma+1] = '\0';
                     for (l = (IndKoma+2); InKoor[l] != '\0'; ++l) {
                        // copying the characters by
                        // character to str2 from str1
                        s2[k] = InKoor[l];
                        k=k+1;
                    }
                    s2[k] = '\0';
                    k=0;
                    // printing the destination string
                    printf("String s1 : %s\n", s1);
                    printf("String s2 : %s\n", s2);

                    koordinat[i][j].x= atoi(s1);
                    koordinat[i][j].y= atoi(s2);
                    printf("koordinat x [%d][%d] : %d\n", (i+1), (j+1), koordinat[i][j].x);
                    printf("koordinat y [%d][%d] : %d\n", (i+1), (j+1), koordinat[i][j].y);
                    }
            j=j+1;
            if (InKoor[0]=='n' || InKoor[0]=='N' ){
            i=i+1;
            }

        }
        while (!(InKoor[0]=='n' || InKoor[0]=='N' || InKoor[0]=='q' || InKoor[0]=='Q'));

   }
   while(!(InKoor[0]=='q' || InKoor[0]=='Q'));
   i=0;j=0;
    //Tes hasil koordinat
                for(i=0;i<2;i++){
                printf("simbol %d %c\n", (i+1), simbol[i] );
                        for(j=0;j<3;j++){
                        printf("koordinat i=%d, j=%d : %d,%d\n", (i+1), (j+1), koordinat[i][j].x, koordinat[i][j].y);
                }}
                ////////////////////////////////
}
