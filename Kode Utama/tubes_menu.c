//Tanggal : 01 Maret 19
//Jam : 03.11
//Update 01.03.19 Menambahkan prosedur in_pcb_size dan Fungsi  print layout
//Update by Tamam

//Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "layout_otomatis_lib.c"
#include "layout_manual_lib.c"
#include "routing_manual_lib.c"


//HEADER
void menu_utama(int * in);
void submenu(int n, int m);
void print_menu_utama();
void print_sub_menu();
void print_layout(int x, int y);
void print_routing(int x, int y);
int input_validation(char * line, int range_bawah, int range_atas);
void in_pcb_size(int * n,int * m);
int keluar(char * line);
//HEADER

int main() {
	int input;
	int isExit = 0;
	
	while (isExit == 0) {	
		menu_utama(&input);
		
		switch(input){
			case 1: //Buat Proyek Baru
				printf("\n====== Membuat Proyek Baru ======");
				printf("\nMasukkan nama proyek: ");
				in_pcb_size(&n,&m);
				submenu(n,m);
				break;
				
			case 2: // Muat Proyek dari Berkas
				printf("====== Memuat Proyek ======");
				printf("\nMasukkan nama proyek: ");
				submenu(n,m);
				break;
				
			case 3: //Keluar
				isExit = keluar("Keluar...");
				break;
		}
		printf("\n\n\n");
	}
	
	return 0;
}

void menu_utama(int * in) {
	print_menu_utama();
	*in = input_validation("Masukan: ",1,3);
}

void submenu(int n, int m) {
	int input;
	int isExit = 0;
	
	while (isExit == 0) {
		//system("cls");
		print_sub_menu();
		input = input_validation("Pilih Mode: ",1,8);
		
		switch(input){
			case 1: //Tampilkan Layout
				printf("\n[Layout Rangkaian pada PCB Dot Matriks]\n");
				print_layout(n,m);
				break;
				
			case 2: // Layout Manual
				printf("\n[Mode Layout]\n");
				layout_manual();
				break;
				
			case 3: // Tampilkan Routing
				printf("\n[Routing Rangkaian pada PCB Dot Matriks]\n");
				print_routing(n,m);
				break;
				
			case 4: // Routing Manual
				printf("\n[Mode Routing]\n");
				routing_manual();
				break;
				
			case 5: // Layout Otomatis
				printf("\n[Mode Auto-Layout]\n");
				layout_otomatis();
				break;
				
			case 6: // Routing Otomatis
				printf("\n[Mode Auto-Routing]\n"); 
				break;
				
			case 7: //  Design Rule Checker
				printf("\n[DRC]\n");
				break;
				
			case 8: //Simpan Proyek dan Keluar
				isExit = keluar("Kembali...");
				break;
		}
	}
}

void print_menu_utama() {
	printf("Menu :\n");
	printf("\t1. Buat Proyek Baru\n");
	printf("\t2. Muat Proyek dari Berkas\n");
	printf("\t3. Keluar\n");
}

void print_sub_menu() {
	printf("\n\n [Menu Utama]\n");
	printf("Pilih Mode:\n");
	printf("\t1. Tampilkan Layout \n");
	printf("\t2. Layout Manual\n");
	printf("\t3. Tampilkan Routing \n");
	printf("\t4. Routing Manual \n");
	printf("\t5. Layout Otomatis\n");
	printf("\t6. Routing Otomatis \n");
	printf("\t7. Design Rule Checker \n");
	printf("\t8. Simpan Proyek dan Keluar \n");
}

/*Fungsi Print Layout */
void print_layout(int x, int y) {
	printf("   ");
    for(int a=0;a<n;a++){
            printf("%2d ", (a+1));
        }
    printf("\n");
    for(int b=0;b<m;b++){
        printf("%d  ",(b+1));
        for(int a=0;a<n;a++){
            printf("%s ", pcb_layout[a][b].nama);
        }
        printf("\n");
    }
}

void print_routing(int x, int y){
	printf("   ");
    for(int a=0;a<n;a++){
            printf("%2d ", (a+1));
        }
    printf("\n");
    for(int b=0;b<m;b++){
        printf("%d  ",(b+1));
        for(int a=0;a<n;a++){
            printf("%c ", matriksPCB[a][b]);
        }
        printf("\n");
    }
}

/*Fungsi input dengan validasi range input dan pesan custom */
int input_validation(char * line, int range_bawah, int range_atas){
	int isValid = 0;
	int in;
	while (isValid == 0) {
		printf("%s",line);
		scanf("%d", &in);
		if (in >= range_bawah && in <=range_atas) {
			isValid = 1;
		} else {
			printf("Error! %d bukan input yang valid.\n",in);
		}
	}
	return in;
}

void in_pcb_size(int * n,int * m) {
	int valid_n = 0;
	int valid_m = 0;
	while (valid_n == 0 || valid_m == 0) {
		printf("\nMasukkan ukuran PCM NxM (N,M<=40): ");
		scanf("%d %d",n,m);
		if (*n > 0 && *n < 41) {
			valid_n = 1;
		} else {
			printf("Input N salah!");
			valid_n = 0;
		}	
		if (*m > 0 && *m < 41) {
			valid_m = 1;
		} else {
			printf("Input M salah!");
			 valid_m = 0;
		}
	}
}

/*Fungsi keluar(mengubah validasi keluar menjadi 1) dengan pesan custom*/
int keluar(char * line) { 
	printf("%s",line);
	return 1;
}
