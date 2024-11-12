#include<iostream>
#include <stdlib.h>
#include <string>
using namespace std ;
//Déclaration des différentes fonction
int longueur(const char *chaine) ;
void copy(char *dest, const char *chaine) ;
void concatene(char *dest, const char *chaine);
int compare(const char *chaine1 , const char *chaine2);
char *cherche_char(const char *chaine , char caractere);
void inverse(char *chaine);
void to_upper(char *chaine);
void to_lower(char *chaine);
char *chercher_mot(const char *phrase, const char *mot);
int compte_mots(const char *phrase);
void sous_chaine(const char *source , char *dest , int debut, int taille);
void supprime_caractere(char *chaine , char caractere); 

//Fonction principale
int main(int argc, char const *argv[])
{
    int choix ;
    //Affichage du menu de choix
    cout <<"Quelle opération souhaitez-vous effectuer ?\n"
         <<"1- Longueur d'une chaîne de caractères\n"
         <<"2- Copie d'une chaîne de caractères\n"
         <<"3- Concaténation de chaînes\n"
         <<"4- Comparaison de chaînes\n"
         <<"5- Recherche de caractère\n"
         <<"6- Inversion de chaîne\n"
         <<"7- Conversion majuscule/minuscule\n"
         <<"8- Trouver un mot dans une phrase\n"
         <<"9- Extraction de sous-chaîne\n"
         <<"10- Suppression de caractères\n"
         <<"11- Compter les mots d'une phrase\n" ;
    cin >> choix ;
    //traitement des différents choix possibles
    if (choix == 1){
        string chaine ;
        cout <<"Entrez votre chaîne de caractères.\n" ;
        cin >> chaine ;
        cout << "La taille de votre chaîne est : "<< longueur(chaine.c_str()) << "\n"; 
        //Calcul de la longueur de la chaine aprèsl'avoir convertie en char*
    } else if (choix == 2)
    {
        string chaine1 ;
        cout <<"Entrez votre chaîne de caractères.\n" ;
        cin >> chaine1 ;
        int n = longueur(chaine1.c_str()) ;
        char chaine2[n] ;
        copy(chaine2, chaine1.c_str());
    } else if (choix == 3)
    {
        char *chaine1 ;
        string chaine2 ;
        cout <<"Entrez votre 1ère chaîne de caractères.\n" ;
        cin >> chaine1 ;
        cout <<"Entrez votre 2ème chaîne de caractères.\n" ;
        cin >> chaine2 ;
        concatene(chaine1, chaine2.c_str());
    }else if (choix == 4)
    {
        char *chaine1 , *chaine2 ;
        cout <<"Entrez votre 1ère chaîne de caractères.\n" ;
        cin >> chaine1 ;
        cout <<"Entrez votre 2ème chaîne de caractères.\n" ;
        cin >> chaine2 ;
        if (compare(chaine1 , chaine2) == 1)
        {
            cout << "La  première châine est la plus longue.\n" ;
        }else if (compare(chaine1 , chaine2) == -1)
        {
            cout << "La  deuxième châine est la plus longue.\n" ;
        }else cout << "Les deux hâines ont la même taille.\n" ;
    } else if (choix == 5)
    {
        string chaine;
        char caractere ;
        cout <<"Entrez votre chaîne de caractères.\n" ;
        cin.ignore();
        getline(cin, chaine);
        cout <<"Quel caractère recherchez-vous ?\n" ;
        cin >> caractere;
        if (cherche_char(chaine.c_str() , caractere) != NULL)
        {
            cout << "Elément trouvé\n" ;
        }else cout << "Element introuvable\n" ;
        

    }else if (choix == 6)
    {
        char *chaine ;
        cout <<"Entrez votre chaîne de caractères.\n" ;
        cin >> chaine ;
        inverse(chaine) ;
    }
    else if (choix == 7)
    {
        char *chaine ;
        int choix2 ;
        cout <<"Entrez votre chaîne de caractères.\n" ;
        cin >> chaine ;
        cout <<"Quelle conversion souhaitez-vous ?\n 1- MAJUSCULE-minuscule\n2- minuscule-MAJUSCULE\n" ;
        cin >> choix2 ;
        if (choix2 == 1)
        {
            to_lower(chaine) ;
        }else if (choix2 == 2)
        {
            to_upper(chaine) ;
        }else cout <<"Erreur\n" ;
        
        
    }
    else if (choix == 8)
    {
        string phrase , mot ;
        cout <<"Entrez votre phrase.\n" ;
        cin.ignore();
        getline(cin, phrase);
        cout <<"Quel mot recherchez-vous ?\n" ;
        cin >> mot ;
        if (chercher_mot(phrase.c_str() , mot.c_str()) != NULL)
        {
            cout << "Mot trouvé\n" ;
        }else{
            cout << "Mot introuvable\n" ;
        } 
        
    }
    else if (choix == 9)
    {
        char *source , *dest ;
        int debut , taille ; 
        cout <<"Entrez votre chaine de caractères.\n" ;
        cin >> source ;
        cout <<"A partir de quel indice souhaitez-vous faire l'extraction ?\n" ;
        cin >> debut ;
        cout <<"Quelle est la longueur de votre sous-chaine ?\n" ;
        cin >> taille ;
        dest = 0 ;
        sous_chaine(source, dest, debut, taille);
    }
    else if (choix == 10)
    {
        string chaine ; 
        char caractere ;
        cout <<"Entrez votre chaine de caractères.\n" ;
        cin >> chaine ;
        cout <<"Quel caractère souhaitez-vous supprimer ?\n" ;
        cin >> caractere ;
        char chaine2[longueur(chaine.c_str())];
        copy(chaine2, chaine.c_str());
        supprime_caractere(chaine2, caractere) ;
    }
    
    else if (choix == 11)
    {
        char *phrase ;
        cout <<"Entrez votre phrase.\n" ;
        cin >> phrase ;
        cout <<"Votre phrase compte "<< compte_mots(phrase) <<" mots.\n"  ;
    }
    
    return 0;
}
//Calcul de la longueur d'une chaine de carctères en la parcourant lettre par lettre
int longueur(const char *chaine){
    int lent = 0 ;
    while(chaine[lent] != '\0')
    {
        lent++;
    } 
    return lent ;
}
//Copie de la valeur d'une chaine de caractères dans une autre
void copy(char *dest, const char *chaine){
    int i = 0 ;
    while (i <= longueur(chaine)){
        dest[i] = chaine[i] ;
        i++ ;
    }
    cout << "Votre chaîne est : "<< dest << "\n" ;
}
//Concatenation de deux chaines de caractères
void concatene(char *dest, const char *chaine){
    int i = 0 , n = longueur(dest) ;
    while (i <= longueur(chaine)){
        dest[n+i] = chaine[i] ;
        i++ ;
    }
    cout << "La concatenation donne : "<< dest << "\n" ;
}
//Comparaison de la taille dedeux chainesde caractères
int compare(const char *chaine1 , const char *chaine2){
    int taille1 = longueur(chaine1), taille2 = longueur(chaine2);
    if (taille1 > taille2)//Cas où la première chaine est la plus longue
    {
       return 1;
    }else if (taille2 > taille1)//Cas où la deuxième chaine est la plus longue
    {
        return -1;
    } else return 0 ; //Cas où les deux ont la même taille
}
//Recherche d'un caractère dans une chaine en la parcourant lettre par lettre
char *cherche_char(const char *chaine , char caractere){
    int i = 0 ;
    while (chaine[i] != '\0')
    {
        if (chaine[i] == caractere)
        {
            return (char *)&chaine[i] ;
        }
        i++ ;  
    }
    return NULL ;
}
/*Inverson d'une chaine de caractères en la modifiant directement
Ici, on parcourt la chaine jusqu'à son milieu en inversant les caractères opposés
le 1er et le dernier, le 2èmé et l'avant-dernier, etc*/
void inverse(char *chaine){
    int i = 0 , n = longueur(chaine);
    while (i < n/2)
    {
       chaine[i] = chaine[i] + chaine[n-1-i] ;
       chaine[n-1-i] = chaine[i] - chaine[n-1-i] ;
       chaine[i] = chaine[i] - chaine[n-1-i] ;
       i++ ;
    }
    std :: cout <<"L'inverse donne : " << chaine << "\n";
}
/*Conversion en Majuscules
Ici, on utilide le code ASCII de chaque lettre*/
void to_upper(char *chaine){
    for(int i = 0 ; i < longueur(chaine) ; i++){
        if (chaine[i] >=  'a' && chaine[i] <= 'z')
        {
            chaine[i] = chaine[i] - 'a' + 'A';
        }
    }
    std :: cout << chaine ;
}
/*Conversion en minuscules
Ici, on utilide le code ASCII de chaque lettre*/
void to_lower(char *chaine){
    for(int i = 0 ; i < longueur(chaine) ; i++){
        if (chaine[i] >=  'A' && chaine[i] <= 'Z')
        {
            chaine[i] = chaine[i] - 'A' + 'a';
        }   
    }
    cout << chaine ;
}
// Recherche d'un mot dans une phrase
char *chercher_mot(const char *phrase, const char *mot){
    int i , j ;
    bool found = false ;
    for ( i = 0 ; i <= longueur(phrase) - longueur(mot) ; i++)
    {
        if (phrase[i] == mot[0]){
            for ( j = 1 ; j < longueur(mot) ; j++)
            {
                if (phrase[i + j] != mot[j])
                {
                    found = false ;
                    break;
                }else found = true ;
            }
        }
        if (found)
        {
            return (char *)&phrase[i];
        }
    }
    return NULL ;
}
/*Extraction d'une sous-chaine d'une chaine de caractère en fonction 
de l'indice du début et de la longueur de la longueur de la sous-chaine*/ 
void sous_chaine(const char *source , char *dest , int debut, int taille){
    if (debut + taille > longueur(source))
    {
        cout << "Erreur" ;
    }else{
        int i , j ;
        for (i = 0; i < taille ; i++)
        {
            dest[i] = source[debut + i];
        }
        cout << "Votre sous-chaine est : " << dest << "\n";
    }
}
// Suppression d'un caractère d'une chaine et de toutes ses occurences
void supprime_caractere(char *chaine , char caractere){
    for (int i = 0; i < longueur(chaine) ; i++)
    {
        if (chaine[i] == caractere)
        {
            while (i < longueur(chaine))
            {
                chaine[i] = chaine[i + 1];
                i++ ;
            }
        }
    }
    cout << chaine ;
}
/*Compte des mots contenus dans une phrase
On commence à compter dès le 1er élément différent d'un espace
et on prend en compte des espaces multiples entt$re les mots*/
int compte_mots(const char *phrase){
    int nbre = 0;
    bool dans_mot = false ;
    for (int i = 0; i < longueur(phrase) ; i++)
    {
        if (phrase[i] != ' ' && phrase[i] != '\t' && phrase[i] != '\n')
        {
            if (!dans_mot)
            {
                nbre = nbre + 1 ;
                dans_mot = true ;
            }
            nbre = nbre + 1 ;
        }else {
            dans_mot = false ;
        }
    }
    return nbre ;
}
