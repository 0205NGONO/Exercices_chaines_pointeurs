#include<iostream>
#include <stdlib.h>
#include <string>
using namespace std ;

int distinct_letters(const char *mot) ;
void affichage(const char *mot, bool view_letters[26]) ;
bool in_mot(const char *chaine , char caractere) ;
int longueur(const char *chaine) ;
char to_upper(char letter) ;
void affiche_mot(const char *mot) ;
char to_lower(char letter) ;
void afficherPendu(int etape) ;


int main(int argc, char const *argv[])
{
    while (true)
    {
        string mot;
        char letter ;
        bool view_letters[26] = {false};// Tableau pour suivre les lettres déjà trouvées
        int essai = 0 , letters_found = 0 , max_erreur = 10 ;

        cout <<"Quel est le mot à deviner ?\n" ;
        cin >> mot ;
        //Convertir toutes les lettres du ot en minuscule
        for (int i = 0; i < longueur(mot.c_str()); i++)
        {
            mot[i] = to_lower(mot[i]) ;
        }
        
        system ("CLS");//Effacer le mot de l'écran pour que le joueur censé le retrouver ne le voit pas
        cout <<"Retrouvez le mot caché !\n" ;
        /*Le je continue tant que le nombre d'essais nuls est inférieur au nombre de chance
        Le nombre de chence ici c'est le nombre de lettres distinctes du mot*/
        while (essai < max_erreur) 
        {
            affichage(mot.c_str() , view_letters) ;

            cout << "Entrez une lettre : ";
            cin >> letter ;
            /*Si une lettre majuscule est entrée, on la convertit en minuscule.*/
            if (letter >= 'A' && letter <= 'Z')
            {
                letter = to_lower(letter) ;
            }
            /*Signaler si le caractère entrén'est pas une lettre*/
            if (letter < 'a' || letter > 'z')
            {
                cout << "Lettre invalide" ;
            }else{
            
                int index = letter - 'a' ;//Indice de la lettre dans le tableau view_letters
                if (!view_letters[index])
                {
                    if (in_mot(mot.c_str(), letter))
                    {
                        view_letters[index] = true ;// Marquer la lettre comme trouvée
                        letters_found = letters_found + 1 ; // Incrémenter le nombre de lettres trouvées
                    }else{
                        /*Si la lettre entrée ne se trouve pas dans le mot,
                        c'est un essai perdu et on affiche un dessin*/
                        cout << "Error \n Plus que " << max_erreur - essai - 1 << "\t essais.\n" ;
                        afficherPendu(essai) ;
                        essai = essai + 1 ;
                    }
                }else{
                    //Signaler si une lettre a déjà été trouvée pour en demander une nouvelle
                    cout << "vous avez déjà trouvé cette lettre !\n" ;
                }
                if (letters_found == distinct_letters(mot.c_str()))
                {
                    //Cas où le joueur a trouvé toutes les lettres du mot, arrêt du jeu
                    affiche_mot(mot.c_str()) ;
                    cout << "\nFélicitations vous avez deviné le mot !!!!" ;
                    return false ;
                }
            }
            
        }
        /*Cas où le joueur a épuisé son nombre de chances 
        Arrêt du jeu
        et affichage d mot en entier*/
        if (essai == max_erreur) 
        {
            afficherPendu(essai) ;
            cout << "Vous avez perdu !\n Le mot était :\t" ;
            affiche_mot(mot.c_str()) ;
            cout << "\n" ;
            
            return false ;
        }
        

    }
    return 0;
}
//Calccul de la longueur du mot
int longueur(const char *chaine){
    int lent = 0 ;
    while(chaine[lent] != '\0')
    {
        lent++;
    } 
    return lent ;
}
//Gestion de l'affichage
void affichage(const char *mot, bool view_letters[26]){
    int index;
    for (int i = 0; i < longueur(mot); i++)
    {
        index = mot[i] - 'a' ;
        if (!view_letters[index])
        {
            cout << "_ " ; //Affiche un undescore pour une lettre non-trouvée
        }else cout << to_upper(mot[i]) ; 
        /*Convertit une lettre trouvée en majuscule puis, 
        l'affiche à sa position dans le mot*/
    }
    
}
//Vérifie si une lettre se trouve dans le mot
bool in_mot(const char *chaine , char caractere){
    int i = 0 ;
    while (chaine[i] != '\0')
    {
        if (chaine[i] == caractere)
        {
            return true ;
        }
        i++ ;  
    }
    return false ;
}
//Compte les lettres distinctes du mot
int distinct_letters(const char *mot){
    bool view[26] = {false} ;
    int compteur = 0 ;
    for (int i = 0; mot[i] != '\0'; i++)
    {
        char letter = mot[i] ;
        if (letter >= 'a' && letter <= 'z')
        {
            int index = letter - 'a' ;
            if (!view[index])
            {
               view[index] = true ;
               compteur ++ ;
            }
        }
    }
    return compteur ;
}
//Convertit une lettre en Majuscule
char to_upper(char letter){
        if (letter >=  'a' && letter <= 'z')
        {
            letter = letter - 'a' + 'A';
        }
    
    return letter ;
}
//convertit une lettre en minuscule
char to_lower(char letter){
        if (letter >=  'A' && letter <= 'Z')
        {
            letter = letter - 'A' + 'a';
        }   
    return letter ;
}
//Affiche chacune des lettres du mot en majuscule
void affiche_mot(const char *mot){
    for (int i = 0; i < longueur(mot); i++)
    {
        cout << to_upper(mot[i]);
    }
    
}

void afficherPendu(int etape) {
    switch (etape) {
        case 0:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |          \n"; // Vide
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 1:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 2:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |      |  \n"; // Bras gauche
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 3:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|  \n"; // Bras droit
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 4:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |          \n";
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 5:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |     /   \n"; // Jambes partielles
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 6:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |     / \\ \n"; // Jambes
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 7:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |     / \\ \n"; // Jambes
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 8:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |     / \\ \n"; // Jambes
            std::cout << "  |          \n";
            std::cout << "__|__        \n";
            break;
        case 9:
            std::cout << "  --------  \n";
            std::cout << "  |      |  \n";
            std::cout << "  |      O  \n"; // Tête
            std::cout << "  |     /|\\ \n"; // Bras
            std::cout << "  |     / \\ \n"; // Jambes
            std::cout << "  |   [FIN]  \n"; // État final
            std::cout << "__|__        \n";
            break;
    }
}