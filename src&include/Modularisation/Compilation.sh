gcc -ansi -Wall -c Coup.c
gcc -ansi -Wall -c Joueur.c
gcc -ansi -Wall -c Position.c
gcc -ansi -Wall -c Tablette.c
gcc -ansi -Wall -c AffichageGraphique.c
gcc -ansi -Wall -c Regles.c
gcc -ansi -Wall -c Clic.c
gcc -ansi -Wall -c Main.c

gcc Main.o Coup.o Joueur.o Position.o Tablette.o AffichageGraphique.o Regles.o Clic.o -o Projet -lncurses

