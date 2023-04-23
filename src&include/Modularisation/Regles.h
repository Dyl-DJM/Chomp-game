/*Regles.h */
#ifndef __REGLES__
#define __REGLES__

#include "Position.h"
#include "Coup.h"

    /*Cette fonction renvoie 1 si le coup 'coup' touche une case du tableau de 'pos' égale à 1 et 0 sinon*/
    int est_legal(Position pos, Coup coup);

    /*Cette fonction renvoie 1 et affecte à 'joueur' le joueur gagnant si la première case de la tablette de 'pos' vaut 0 cad
    que le poison a été mangé renvoie 0 sinon*/
    int est_jeu_termine(Position pos, Joueur *joueur_gagnant);


#endif