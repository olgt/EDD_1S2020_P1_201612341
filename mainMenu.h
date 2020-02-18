#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include <curses.h>
#include "structures.h"

void showMenu();
void switchOfOptions();

int size = 6;

string infoStudents[6] = {"Universidad de San Carlos de Guatemala", "Facultad de Ingenieria",
                        "Estructura de Datos", "Practica 1", "Oscar Lopez", "201612341"};

string stringsOfOptions[6] = {"Menu", "1. Crear Archivo", "2. Abrir Archivo",
                    "3. Archivos Recientes", "4. Salir"};

//const char newline = '\n';


//This is the specification for each optioin of the menu
void switchOfOptions()
{
    bool keepRunning = TRUE;

    while(keepRunning)
    {
        int optionSelected = getch();

        switch(optionSelected)
        {
            case '1':
                clear();
                option1();
                showMenu();
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                keepRunning = FALSE;
                clear();
                mvprintw(1,1,"Exiting, Press 4 again..");
                break;
            default:
                break;
        }
    }
}

//Method to print menu, contains switchOfOptions for the specification for each option pressed
void showMenu()
{
    initscr(); //Initializes Curses, with Window
    noecho(); //No Echo?
    stdscr = newwin(25, 70, 1, 1); //Sets Size and position of box
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0); //Draws the border

    //Prints Information of student to Screen
    for(int i = 0; i < size; i++)
    {
        mvprintw(i+1, 1, infoStudents[i].c_str()); //Mvprintw (y, x, "string");
    }

    //Prints Options to Screen
    for(int i = 0; i < size; i++)
    {
        mvprintw(i+10, 20, stringsOfOptions[i].c_str());
    }

    //Puts Cursor at x = 2, y = 20
    move(40, 2);
    //Opens the process for the option Menu
    switchOfOptions();
    //Terminates Program
    endwin();
}



#endif // MAINMENU_H_INCLUDED
