#ifndef SAVINGFILE_H_INCLUDED
#define SAVINGFILE_H_INCLUDED


#include "TextStructure.h"
#include "LogStructure.h"
#include "RecentFileStructure.h"

#include <iostream>
#include <fstream>
#include <curses.h>

void writeInFile(string);
char newFileName[100];


void saveFile()
{
    clear();
    mvprintw(1, 1, "%s", "Enter the name of your file \n");
    getnstr( newFileName, sizeof( newFileName ) - 1 );

    string name = newFileName;
    //int nameOfFile = getch();

    writeInFile(name);
}


void writeInFile(string nameOfFile)
{
    ofstream file;
    file.open(nameOfFile + ".txt");

    sentinelCharacter = firstChar;
    string text;

    while(sentinelCharacter != NULL)
    {
        text = text + sentinelCharacter->character;
        sentinelCharacter = sentinelCharacter->next;
    }
    file << text;

    file.close();
}
#endif // SAVINGFILE_H_INCLUDED
