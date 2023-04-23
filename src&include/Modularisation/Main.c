/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "Regles.h"
#include "Clic.h"
#include "AffichageGraphique.h"

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


int main(void){
    Position pos;
    Joueur joueur;
    Coup coup;

    /*Initialisation de la tablette*/
    pos.chocolat = creer_tablette();

    /*Ecran graphique et fonctionnalités*/
    initscr();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(0);
    noecho();

    /*Definition de la couleur*/
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    /*Tant que le jeu n'est pas terminé on continue*/
    while(est_jeu_termine(pos, &joueur) != 1){
        clear();
        mvprintw(0, 0, "Joueur :  %d ", joueur + 1); /*Affichage du tour du joueur*/

        /*On affiche la tablette, on lit le coup venant de l'utilisateur, et on joue le coup pour modifier les etats
        de la tablette et du tour du joueur*/
        afficher_position(pos);
        coup = lire_coup(pos);
        jouer_coup(&pos, coup);
    }

    clear();
    /*On affiche le vainqueur*/
    mvprintw(2, (COLS/2) - 15, "Le joueur %d remporte la partie", joueur+1);

    getch();
    endwin();
    return 0;
}


