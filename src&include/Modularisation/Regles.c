/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "Regles.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


int est_legal(Position pos, Coup coup){

    /*On s'assure que les coordonnées du coup son positives*/
    assert(coup.x >= 0);
    assert(coup.y >= 0);

    /*Si c'est égal à 1 le carré n'a pas été mangé le coup est donc valide*/
    if ((pos.chocolat).tab[coup.y][coup.x] == 1)
        return 1;
    return 0;
}


int est_jeu_termine(Position pos, Joueur *joueur_gagnant){

    /*On s'assure que l'on pourra bien accéder à la case [0][0] du tableau*/
    assert((pos.chocolat).tab != NULL);
    assert((pos.chocolat).tab[0] != NULL);

    /*On regarde si la première case vaut 0*/
    if ((pos.chocolat).tab[0][0] == 0){
        /*Le gagnant est l'autre joueur*/
        *joueur_gagnant = adversaire(pos.tour);
        return 1;
    }
    *joueur_gagnant = adversaire(pos.tour);
    return 0;
}