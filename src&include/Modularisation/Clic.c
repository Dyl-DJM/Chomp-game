/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "Clic.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


int ClicVersCase(Position pos, int x, int y, int *case_x, int *case_y){
    int i, j, centrage;

    centrage = ((COLS / 2) - (((pos.chocolat).m) * 2));

    /*On reparcourt le tableau dessiné dans la fonction afficher_position*/
    for(i = 0; i < (pos.chocolat).n ; i++){

        for(j = 0; j < (pos.chocolat).m ; j++){

            /*Si les coordonnées du clic sont bien comprises entre celle de la case courante on renvoie 1 et on affecte les valeurs correpodantnes*/
            if((((j * 4) + centrage) <= x) && ((((j + 1) * 4) + centrage) >= x)
                        && ((i * 2) <= y) && (((i + 1) * 2) >= y)){
                *case_x = j;
                *case_y = i;
                return 1;
            }
        }
    }

    return 0;
}