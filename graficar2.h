#ifndef GRAFICAR2_H_INCLUDED
#define GRAFICAR2_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <stdio.h>
#include <string.h>

FILE *archivografico;
char cadena[1000];
char ubicacion[250]= "C:/Users/Oscar/Dropbox/EDD_2020_1er_Semestre/Practica1/lista.dot";

void recorrerColaGraficar(nodeChar *firstChar){
        	strcpy(cadena,"digraph G {rankdir = LR; \r\n node [shape=circle]\r\n ");
            struct nodeChar* aux = firstChar;
            if(!aux){
                strcat(cadena, "Lista_Vacia");
            }else{
            while(aux){
                char buffer[5] = "";
                sprintf(buffer, "%c", aux->character);
                if(aux->siguiente){
                    strcat(cadena, buffer);
                    strcat(cadena,"->");
                }else{
                    strcat(cadena, buffer);
                    strcat(cadena,"->");
                    strcat(cadena, "NULO");
                }
            aux = aux->next;
            }

            }

            strcat(cadena,"}");
}

void GraficarCola(){
        archivografico = fopen(ubicacion,"w+");
            if(archivografico){
			// Copiamos el contenido de la variable "cadena" en el archivo
            fprintf(archivografico,"%s",cadena);
            fclose(archivografico);
			// Compilamos el archivo lista.dot
            system("dot C:/Users/Oscar/Dropbox/EDD_2020_1er_Semestre/Practica1/lista.dot -Tjpg -o C:/Users/Oscar/Desktop/Cola.jpg ");
            }else{
                printf("%s\n","Error abriendo el archivo :(");
            }
        }

#endif // GRAFICAR2_H_INCLUDED
