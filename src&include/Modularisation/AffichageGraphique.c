/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "AffichageGraphique.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

void rectangle(int y1, int x1, int y2, int x2){
    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}


void afficher_position(Position pos){
    int i, j, centrage;

    /*On met cette valeur afin de pouvoir centrer la tablette*/
    centrage = ((COLS/2) - (((pos.chocolat).m)*2));

    /*On parcourt les cases du tableau à double dimensions*/
    for(i = 0; i < (pos.chocolat).n ; i++){

        for(j = 0; j < (pos.chocolat).m ; j++){

            /*Première itération, on affiche le poison dans la couleur déifnie dans le main*/
            if(j == 0 && i == 0){
                attron(COLOR_PAIR(1));
                mvprintw(1, 2 + centrage, "°");
                mvvline(0, 4, 2, 4);
                attroff(COLOR_PAIR(1));
            }

            /*Si la case du tableau à une valeur égale à 1 on peut afficher la case*/
            if((pos.chocolat).tab[i][j] == 1){
                rectangle(i * 2, (j * 4) + centrage, (i + 1) * 2, ((j + 1) * 4) + centrage);
            }
        }
    }
    /*On actualises les élements graphiques de la fenêtre*/
    refresh();
}