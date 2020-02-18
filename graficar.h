#ifndef GRAFICAR_H_INCLUDED
#define GRAFICAR_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

void toJPG(string textOfFile);

void graphTheText()
{
    string textOfFile;

    ofstream file;
    file.open("texto.dot");
    int count = 1;

    file << "digraph firstGraph {\n";
    file << "node [shape = record]; \n";
    file << "rankdir=LR; \n";

    textOfFile +=  "digraph firstGraph {\n";
    textOfFile += "node [shape = record]; \n";
    textOfFile += "rankdir=LR; \n";

    nodeChar *temp = firstChar;

    while(temp != NULL)
    {
        file << "node" << count << "[label=\"" << temp->character << "\"]; \n";
        file << "node" << (count) << "->node" << (count-1) << "; \n";
        file << "node" << (count-1) << "->node" << (count) << "; \n";

        string countString = to_string(count);
        string countString2 = to_string(count - 1);
        textOfFile += "node" + countString + "[label=\"" + temp->character + "\"]; \n";
        textOfFile += "node" + countString + "->node" + countString2 + "; \n";
        textOfFile += "node" + countString2 + "->node" + countString + "; \n";
        temp = temp->next;
        count++;
    }
    file << "}";
    textOfFile += "}";

    file.close();

    toJPG(textOfFile);
}

void toJPG(string textOfFile){
    FILE *archivografico;

        archivografico = fopen("C:\\Users\\Oscar\\Dropbox\\EDD_2020_1er_Semestre\\Practica1\\lista.dot","w+");
            if(archivografico){
			// Copiamos el contenido de la variable "cadena" en el archivo
            fprintf(archivografico,"%s",textOfFile);
            fclose(archivografico);
			// Compilamos el archivo lista.dot
            system("dot C:\\Users\\Oscar\\Dropbox\\EDD_2020_1er_Semestre\\Practica1\\lista.dot -Tjpg -o C:\\Users\\Oscar\\Desktop\\lista.jpg");
            }else{
                printf("%s\n","Error abriendo el archivo :(");
            }
}
#endif // GRAFICAR_H_INCLUDED
