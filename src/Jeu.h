#ifndef JEU_H
#define JEU_H

#include "Joueur.h"

class Jeu{
    public:
        Jeu();
        void jouer(int nAruco);

    private:
        Joueur joueur1;
        Joueur joueur2;
};

#endif
