#include "Joueur.h"

const float markerSize = 0.105f;
extern vector<Model_OBJ> objets;

Joueur::Joueur(int nb)
{
    m_nb=nb;
}

void Joueur::afficher()
{
    switch(m_typeAffichage)
    {
        case TYPE_EVOLUTION2:
            m_typeAffichage=TYPE_EVOLUTION1;
        case TYPE_COMBAT:
            switch(m_carte)
            {
                case PLANTE:
                    glColor3f(0.4f,1,0.4f);
                    break;
                case FEU:
                    glColor3f(1,0.4f,0.4f);
                    break;
                case EAU:
                    glColor3f(0.4f,0.4f,1);
                    break;
            }
            break;
        case TYPE_EVOLUTION1:
            glColor3f(1,1,1);
            if(m_evolutionEau==3 || m_evolutionFeu==3 || m_evolutionPlante==3)
                m_typeAffichage=TYPE_EVOLUTION2;
            break;
        case TYPE_MORT:
            glColor3f(0,0,0);
            break;
        case TYPE_SANS:
            return;
            break;
    }

    switch(m_carte)
    {
        case PLANTE:
            switch(m_evolutionPlante)
            {
                case 1:
                    glScalef(0.13f*markerSize ,0.13f*markerSize, 0.13f*markerSize );
                    objets[0].Draw();
                    break;
                case 2:
                    glScalef(0.13f*markerSize ,0.13f*markerSize, 0.13f*markerSize );
                    objets[1].Draw();
                    break;
                case 3:
                    glScalef(0.13f*markerSize ,0.13f*markerSize, 0.13f*markerSize );
                    objets[2].Draw();
                    break;
            }
            break;
        case FEU:
            switch(m_evolutionFeu)
            {
                case 1:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[3].Draw();
                    break;
                case 2:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[4].Draw();
                    break;
                case 3:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[5].Draw();
                    break;
            }
            break;
        case EAU:
            switch(m_evolutionEau)
            {
                case 1:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[6].Draw();
                    break;
                case 2:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[7].Draw();
                    break;
                case 3:
                    glScalef(0.2f*markerSize ,0.2f*markerSize, 0.2f*markerSize );
                    objets[8].Draw();
                    break;
            }
            break;
    }
}
