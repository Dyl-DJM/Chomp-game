/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/


#include "Regles.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


Coup lire_coup(Position pos){
    int touche, clic_valide, centrage, case_x, case_y;
    MEVENT ev;
    Coup clic;

    centrage = ((COLS / 2) - (((pos.chocolat).m) * 2));
    case_x = -1;
    case_y = -1;
    clic_valide = 0;

    do{
        /*On attend un eventuel clic*/
        touche = getch();

        /*S'il s'agit d'un clic*/
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {

            /*On recupère les coordonnées du clic*/
            clic.x = ev.x;
            clic.y = ev.y;

            /*On calcule et affecte à clic.x et clic.y la conversion du clic en case du tableau correcpondante*/
            ClicVersCase(pos, clic.x, clic.y, &case_x, &case_y);
            clic.x = case_x;
            clic.y = case_y;
        }

        /*Si le coup est légal et que l'on a bien trouvé l'équivalent en case du tableau du clic
        de l'utilisateur on arrête la boucle*/
        if(case_x != -1 && est_legal(pos, clic)){
             clic_valide = 1;
        }
    }while(clic_valide == 0);

    return clic;
}


void jouer_coup(Position *pos, Coup coup){
    manger(&((*pos).chocolat),coup.x, coup.y);
    (*pos).tour = adversaire((*pos).tour);
}