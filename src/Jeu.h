#ifndef JEU_H
#define JEU_H

#include "Joueur.h"

#include <aruco/aruco.h>
#include <chrono>

#define STATE_INITIAL 1
#define STATE_COMBAT 2
#define STATE_EVOLUTION 3
#define STATE_REPOS 4
#define STATE_FIN 5

// Namespaces
using namespace std;
using namespace chrono;
using namespace cv;
using namespace aruco;

class Jeu{
    public:
        Jeu();
        void jouer(vector<Marker>);
        void afficher(int);
        void rejouer();

    private:
        int m_state=STATE_INITIAL;
        Joueur m_joueur1=Joueur(1);
        Joueur m_joueur2=Joueur(2);
        time_point<system_clock> m_timeStartNewState=system_clock::now();

};

#endif
