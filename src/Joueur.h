#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
    private:
        int nb;
        int evolutionPlante=1;
        int evolutionFeu=1;
        int evolutionEau=1;

    public:
        Joueur(int);
};

#endif // JOUEUR_H
