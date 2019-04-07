#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Storage.h"
#define kosong ""
void NewProject(fname *nama, BesarMatriks *bm)
{	
	char Nama[100];
	printf("====== Membuat Proyek Baru ======\n");
	printf("Masukkan nama proyek: ");
	gets(Nama);
	strcpy(nama->namaFile_Layout,Nama);
	strcpy(nama->namaFile_Routing,Nama);
	//Buat memastikan agar gak inputnya gak idiot
	printf("Masukkan ukuran PCB NxM (N,M<40): ");
	int m,n;
	scanf("%d %d" ,&n,&m);
	bm->m = m;
	bm->n = n;
	FILE *fp_layout;
	strcat(nama->namaFile_Layout, "_Layout.csv");
	fp_layout = fopen(nama->namaFile_Layout,"w");//untuk membuat file Layout
	FILE *fp_routing;
	strcat(nama->namaFile_Routing, "_Routing.csv");
	fp_routing = fopen(nama->namaFile_Routing,"w");//untuk membuat file Routing
	fclose(fp_routing);
	fclose(fp_layout);
}
void SaveProject(PCB Board, fname *nama, BesarMatriks *bm)
{
	int I,J,K;
	char empty [3] = {'\0'};
	char *c= NULL;
	char *temp = "";
	FILE *fp_layout;
	fp_layout = fopen(nama->namaFile_Layout,"w");
	FILE *fp_routing;
	fp_routing = fopen(nama->namaFile_Routing,"w");
	for (I=1; I<bm->m; I++)
	{
		for (J=1; J<bm->n; J++)
		{
			if (strcmp(Board.pin[I][J].Name,empty) == 0 )
			{
				fprintf(fp_layout," ,");
			}else if (strcmp(Board.pin[I][J].Name,empty) != 0 )
			{
				fprintf(fp_layout,"%s,",Board.pin[I][J].Name);
			}			
		}
		fprintf(fp_layout,"\n");
	}
	for (I=1; I<bm->m; I++)
	{
		for (J=1; J<bm->n; J++)
		{	
			//temp = &Board.pin[I][J].Simbol;
			if (Board.pin[I][J].Simbol == *temp)
			{
				fprintf(fp_routing," ,");
				printf("debug1");
			}else
			{
				fprintf(fp_routing,"%c,",Board.pin[I][J].Simbol);
				printf("debug");
			}			
		}
		fprintf(fp_routing,"\n");
	}
	fclose(fp_layout);
	fclose(fp_routing);
}

void NewProject(fname *nama, BesarMatriks *bm);
void SaveProject(PCB Board, fname *nama, BesarMatriks *bm);	
	

