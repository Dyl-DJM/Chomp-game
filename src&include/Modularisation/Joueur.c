/* Auteur : Dylan DE JESUS
 * Date creation : 08-03-2021
 * Date modification : 14-03-2021*/

#include "Joueur.h"


Joueur adversaire(Joueur joueur){

    if(joueur == JOUEUR_1)
        return JOUEUR_2;

    if(joueur == JOUEUR_2)
        return JOUEUR_1;
    return 0;
}