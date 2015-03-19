#include "Jeu.h"

Jeu::Jeu()
{
}

void Jeu::rejouer()
{
    if(m_state==STATE_FIN)
    {
        m_joueur1=Joueur(1);
        m_joueur2=Joueur(2);

        m_joueur1.m_typeAffichage=TYPE_SANS;
        m_joueur2.m_typeAffichage=TYPE_SANS;

        m_state=STATE_REPOS;
        m_timeStartNewState=system_clock::now();
    }
}

void Jeu::jouer(vector<Marker> markers)
{
    cout << "Temps depuis dernier changement : " << duration_cast<seconds>(system_clock::now()-m_timeStartNewState).count() << endl;
    cout << "Etat : " << m_state << endl;
    if(markers.size()!=2)
    {
        if(m_state==STATE_REPOS)
        {
            m_state=STATE_INITIAL;
            m_timeStartNewState=system_clock::now();
        }
        else
            return;
    }
    else
    {
        if(m_state==STATE_INITIAL)
        {
            cout << "Initialisation" << endl;
            for(int i=0;i<2;i++)
            {
                cout << "type de marker :" << markers[i].id/150 << endl;
                switch(markers[i].id/150)
                {
                    case 0:
                        m_joueur1.m_carte=PLANTE;
                        break;
                    case 1:
                        m_joueur1.m_carte=FEU;
                        break;
                    case 2:
                        m_joueur1.m_carte=EAU;
                        break;
                    case 3:
                        m_joueur2.m_carte=PLANTE;
                        break;
                    case 4:
                        m_joueur2.m_carte=FEU;
                        break;
                    case 5:
                        m_joueur2.m_carte=EAU;
                        break;
                    default:
                        cerr << "Marker non reconnu" << endl;
                        break;
                }
            }
            m_joueur1.m_typeAffichage=TYPE_COMBAT;
            m_joueur2.m_typeAffichage=TYPE_COMBAT;
            m_state=STATE_COMBAT;
            m_timeStartNewState=system_clock::now();
        }

        if(m_state==STATE_COMBAT && (duration_cast<seconds>(system_clock::now()-m_timeStartNewState).count())>3)
        {
            cout << "Combat" << endl;
            if(m_joueur1.m_carte==PLANTE && m_joueur2.m_carte==FEU)
            {
                m_joueur1.m_evolutionPlante=1;
                m_joueur2.m_evolutionFeu++;
                m_joueur1.m_typeAffichage=TYPE_MORT;
                m_joueur2.m_typeAffichage=TYPE_EVOLUTION1;
            }
            if(m_joueur1.m_carte==PLANTE && m_joueur2.m_carte==EAU)
            {
                m_joueur1.m_evolutionPlante++;
                m_joueur2.m_evolutionEau=1;
                m_joueur1.m_typeAffichage=TYPE_EVOLUTION1;
                m_joueur2.m_typeAffichage=TYPE_MORT;
            }
            if(m_joueur1.m_carte==EAU && m_joueur2.m_carte==FEU)
            {
                m_joueur1.m_evolutionEau++;
                m_joueur2.m_evolutionFeu=1;
                m_joueur1.m_typeAffichage=TYPE_EVOLUTION1;
                m_joueur2.m_typeAffichage=TYPE_MORT;
            }
            if(m_joueur1.m_carte==EAU && m_joueur2.m_carte==PLANTE)
            {
                m_joueur1.m_evolutionEau=1;
                m_joueur2.m_evolutionPlante++;
                m_joueur1.m_typeAffichage=TYPE_MORT;
                m_joueur2.m_typeAffichage=TYPE_EVOLUTION1;
            }
            if(m_joueur1.m_carte==FEU && m_joueur2.m_carte==EAU)
            {
                m_joueur1.m_evolutionFeu=1;
                m_joueur2.m_evolutionEau++;
                m_joueur1.m_typeAffichage=TYPE_MORT;
                m_joueur2.m_typeAffichage=TYPE_EVOLUTION1;
            }
            if(m_joueur1.m_carte==FEU && m_joueur2.m_carte==PLANTE)
            {
                m_joueur1.m_evolutionFeu++;
                m_joueur2.m_evolutionPlante=1;
                m_joueur1.m_typeAffichage=TYPE_EVOLUTION1;
                m_joueur2.m_typeAffichage=TYPE_MORT;
            }
            m_state=STATE_EVOLUTION;
            m_timeStartNewState=system_clock::now();
        }

        if(m_state==STATE_EVOLUTION && (duration_cast<seconds>(system_clock::now()-m_timeStartNewState).count())>2)
        {
            if( m_joueur1.m_evolutionFeu==3 ||
                m_joueur1.m_evolutionEau==3 ||
                m_joueur1.m_evolutionPlante==3 ||
                m_joueur2.m_evolutionFeu==3 ||
                m_joueur2.m_evolutionEau==3 ||
                m_joueur2.m_evolutionPlante==3)
            {
                m_state=STATE_FIN;
                m_timeStartNewState=system_clock::now();
            }
            else
            {
                m_joueur1.m_typeAffichage=TYPE_SANS;
                m_joueur2.m_typeAffichage=TYPE_SANS;

                m_state=STATE_REPOS;
                m_timeStartNewState=system_clock::now();
            }
        }
    }
}

void Jeu::afficher(int id)
{
    if(id/450==0)
        m_joueur1.afficher();
    else
        m_joueur2.afficher();
}
