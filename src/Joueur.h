#ifndef JOUEUR_H
#define JOUEUR_H

#include "ObjLoader.h"

#define PLANTE 10
#define FEU 11
#define EAU 12

#define TYPE_COMBAT     20
#define TYPE_EVOLUTION1 21
#define TYPE_EVOLUTION2 22
#define TYPE_MORT       23
#define TYPE_SANS       24

// OpenCV
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <aruco/aruco.h>

class Joueur {
    private:
        int m_nb;

    public:
        Joueur(int);
        void afficher();

        int m_carte;
        int m_typeAffichage;
        int m_evolutionPlante=1;
        int m_evolutionFeu=1;
        int m_evolutionEau=1;
};

#endif // JOUEUR_H
