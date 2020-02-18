#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <iostream>
#include <string>

#include "TextStructure.h"
#include "LogStructure.h"
#include "RecentFileStructure.h"
#include "savingFile.h"
#include "graficar.h"
#include <curses.h>

using namespace std;


void printingProcess();
void printMenuOption1();
void searchAndReplace();
void printSearchAndReplaceMenu();
void printWriteReplaceMenu();

int x = 1;
int y = 7;

void option1()
{
    printMenuOption1();
    x = 1;
    y = 7;
    bool keepWriting = TRUE;

    while(keepWriting)
    {
        nodeChar *pressedCharacter = new nodeChar();
        int key = getch();

        switch(key)
        {
            case '9':
                keepWriting = FALSE;
                clear();
                break;
            case '8':
                saveFile();
                printMenuOption1();
                break;
            case '7':
                searchAndReplace();
                printMenuOption1();
                break;
            case '6':
                graphTheText();
                getch();
                printMenuOption1();
               break;
            case '\n':
                //y++;
                //x = 1;
                //move(y,x);
                break;
            case '\b':
                deleteLastNode();
                mvprintw(y, x, "%c", ' ');

                if(x == 1 and y == 7)
                {}
                else if(x == 1 and y != 7)
                {
                    x = 68;
                    move(--y,x);
                    mvprintw(y, x, "%c", ' ');
                }
                else
                {
                    move(y,--x);
                    mvprintw(y, x, "%c", ' ');
                }

                break;

            default:
                pressedCharacter->character = key;
                addCharacterNode(pressedCharacter);
                mvprintw(y, x, "%c", pressedCharacter->character);

                if(x == 68)
                {x = 1; y++;}
                else{ x++;}

                break;
        }
    }
}

void searchAndReplace()
{
    printSearchAndReplaceMenu();
    printWriteReplaceMenu();

    sentinelCharacter = firstChar;
    sentinelSearchedWord = searchedWord;

    nodeChar *firstCharacterReplaceInText = new nodeChar();
    nodeChar *lastCharacterReplaceInText = new nodeChar();

    bool isFirstWordOfText = FALSE;

    while (sentinelCharacter != NULL)
        {
            printw("%s", "again");
            getch();
            /*printw("%c", sentinelSearchedWord->character);
            printw("%c", sentinelCharacter->character);
            getch();*/

            if(sentinelCharacter->character == sentinelSearchedWord->character)
            {
                //printw("%s", "Character matched");

                if(sentinelCharacter->previous == NULL && sentinelCharacter->next != NULL)
                {
                    if(sentinelCharacter->next->character == ' ')
                    {
                        firstChar->character = replaceWord->character;
                        break;
                    }
                    else
                    {
                        firstCharacterReplaceInText = sentinelCharacter;
                        sentinelSearchedWord = sentinelSearchedWord->next;
                        isFirstWordOfText = TRUE;
                        printw("%s", "-Begin-");
                    }
                }
                else if(sentinelCharacter->previous != NULL && sentinelCharacter->next != NULL && sentinelCharacter->character != ' ')
                {
                    if(sentinelCharacter->next->character == ' ' && sentinelSearchedWord->next == NULL)
                    {
                        assignLasNodeOfReplaceWord();//We get the last Node of the replace word

                        lastCharacterReplaceInText = sentinelCharacter;
                        lastCharacterReplaceInText->next->previous = lastNodeReplaceWord; //We Put the previous of the new replaced word

                        lastNodeReplaceWord->next = lastCharacterReplaceInText->next;

                        if(isFirstWordOfText)
                        {
                            firstChar = replaceWord;
                            isFirstWordOfText = FALSE;
                            replaceWord->previous = firstCharacterReplaceInText->previous;
                        } else
                        {
                            firstCharacterReplaceInText->previous->next = replaceWord; //We assign the first
                            replaceWord->previous = firstCharacterReplaceInText->previous;
                        }
                        printw("%s", "-End-");

                        sentinelSearchedWord = searchedWord; // Goes back to the first node
                        getch();
                        break;
                    }
                    if(sentinelCharacter->previous != NULL && sentinelCharacter->previous->character == ' ')
                    {
                        /*
                        printw("%s", "Begin");
                        firstCharacterReplaceInText = sentinelCharacter;
                        sentinelSearchedWord = sentinelSearchedWord->next;
                        */
                    }
                    else if(sentinelSearchedWord->next != NULL)
                    {
                        sentinelSearchedWord = sentinelSearchedWord->next;
                    }

                }
                else if(sentinelCharacter->next != NULL && sentinelCharacter->next->character == ' ')
                {

                }
                else if(sentinelCharacter->previous != NULL && sentinelCharacter->previous->character == ' ')
                {

                }
                else if(sentinelCharacter->previous != NULL && sentinelCharacter->next != NULL && sentinelCharacter->next->character == ' ' &&
                        sentinelCharacter->previous->character == ' ')
                {

                }
            }
            sentinelCharacter = sentinelCharacter->next;
        }
    searchedWord = NULL;
}

void printMenuOption1()
{
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0); //Draws the border
    mvprintw(1, 1, "CTRL + W - Reemplazar"); //Mvprintw (y, x, "string");
    mvprintw(2, 1, "CTRL + Z - Revertir");
    mvprintw(3, 1, "CTRL + S - Grabar");
    mvprintw(4, 1, "CTRL + Z - Realizar Reportes");
    mvprintw(5, 1, "CTRL + X - Cancelar");
    move(7,1);

    if(firstChar != NULL)
    {
        x = 1;
        y = 7;
        sentinelCharacter = firstChar;

        while (sentinelCharacter != NULL)
        {
            mvprintw(y, x, "%c", sentinelCharacter->character);
            sentinelCharacter = sentinelCharacter->next;
            if(x == 68)
            {
                x = 1;
                y++;
            } else
            {
                x++;
            }
        }
    }
}

void printSearchAndReplaceMenu() //Printing into the console as well/ Creates the structure for the searched word
{
    clear();
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0); //Draws the border
    mvprintw(22, 1, "Ingrese la palabra a reemplazar: ");
    move(22,1);
    x = 1;
    y = 23;

    bool keepWritingSearchedWord = TRUE;

    while(keepWritingSearchedWord)
    {
        nodeChar *pressedCharacter = new nodeChar();
        int key = getch();

        switch(key)
        {
            case '\n':
                keepWritingSearchedWord = FALSE;
                clear();
                break;
            case '\b':
                deleteLastNodeSearchedWord();
                mvprintw(y, x, "%c", ' ');

                if(x == 1 and y == 24)
                {}
                else if(x == 1 and y != 7)
                {
                    x = 68;
                    move(--y,x);
                    mvprintw(y, x, "%c", ' ');
                }
                else
                {
                    move(y,--x);
                    mvprintw(y, x, "%c", ' ');
                }

                break;

            default:
                pressedCharacter->character = key;
                addCharacterNodeSearchedWord(pressedCharacter);
                mvprintw(y, x, "%c", pressedCharacter->character);

                if(x == 68)
                {x = 1; y++;}
                else{ x++;}

                break;
        }
    }
}

void printWriteReplaceMenu() //Printing into the console as well/ Creates the structure for the searched word
{
    clear();
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0); //Draws the border
    mvprintw(22, 1, "Ingrese la nueva palabra: ");
    move(22,1);
    x = 1;
    y = 23;

    bool keepWritingSearchedWord = TRUE;

    while(keepWritingSearchedWord)
    {
        nodeChar *pressedCharacter = new nodeChar();
        int key = getch();

        switch(key)
        {
            case '\n':
                keepWritingSearchedWord = FALSE;
                clear();
                break;
            case '\b':
                deleteLastNodeReplaceWord();
                mvprintw(y, x, "%c", ' ');

                if(x == 1 and y == 24)
                {}
                else if(x == 1 and y != 7)
                {
                    x = 68;
                    move(--y,x);
                    mvprintw(y, x, "%c", ' ');
                }
                else
                {
                    move(y,--x);
                    mvprintw(y, x, "%c", ' ');
                }

                break;

            default:
                pressedCharacter->character = key;
                addCharacterNodeReplaceWord(pressedCharacter);
                mvprintw(y, x, "%c", pressedCharacter->character);

                if(x == 68)
                {x = 1; y++;}
                else{ x++;}

                break;
        }
    }
}

#endif // STRUCTURES_H_INCLUDED
