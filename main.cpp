// DEVOIR DE GAME PROGRAMMING

#include <iostream>

// 1)calcul de la longueur de la chaine
size_t LongueurChaine(const char* chaine) {
    const char* debut = chaine;
    while (*chaine != '\0')
        chaine++;
    return chaine - debut;
}

// 2)copier la chaine
void CopierChaine(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

// 3)concatener la chaine
void ConcatenerChaines(char* destination, const char* source) {
    while (*destination != '\0')
        destination++;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

// 4)trouver un caractere
char* TrouverCaractere(const char* chaine, char caractere) {
    while (*chaine != '\0') {
        if (*chaine == caractere)
            return (char *)chaine;
        chaine++;
    }
    return nullptr;
}

// 5)calcul du nombre d'occurrences
size_t CompterOccurrences(const char* chaine, char caractere){
    size_t i = 0;
    while (*chaine != '\0') {
        if (*chaine == caractere) i++;
        chaine++;
    }
    return i;
}

// 6)extraire une sous chaine
void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur) {
    size_t i = 0;
    while (i < debut && source[i] !='\0') i++;
    size_t j = 0;
    while (j < longueur && source[i] != '\0') {
        destination[j] = source[i];
        i++;
        j++;
    }
    destination[j] = '\0';
    }

    // 8)copier la memoire
    void CopierMemoire(void* destination, const void* source, size_t taille) {
    unsigned char* dest = (unsigned char*)destination;
    for (size_t i=0; i < taille; i++) {
        dest[i] = ((const unsigned char*)source)[i];
    }
}

    // 9)initialiser la memoire
    void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    unsigned char* ptr = (unsigned char*)zone;
    for (size_t i = 0; i < taille; i++)
    ptr[i] = valeur;
}

    // 10)comparer les chaines
    int ComparerChaines(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
    if (*chaine1 != *chaine2);
    return *chaine1 - *chaine2;
    }
    return 0;
}


// MAIN POUR TESTER LES FONCTION

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compiler avec C++ et CLang++" << std::endl << std::endl;

    // 1)test du calcul de la longueur
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    

    std::cout << "\n";

    // 2)test de la copie
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;

    std::cout << "\n";

    // 3)test de la concatenation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concatenation: '" << salutation << "'" << std::endl;

    std::cout << "\n";

    // 4)test de la recherche de caractere
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractere 'j' trouver a la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractere 'j' non trouver" << std::endl;
    }

    std::cout << "\n";


    // 5)test du calcul du nombre d'occurences
     std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;

    std::cout << "\n";

    // 6)test de l'extraction d'une sous chaine
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaine (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;

    std::cout << "\n";

    // 8)test de la copie memoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie memoire (5 octets): '" << zone2 << "'" << std::endl;

     std::cout << "\n";

     // 9)test de l'initialisation memoire
     char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation memoire: '" << zone3 << "'" << std::endl;

    std::cout << "\n";
    
    // 10)test de la comparaison des chaines
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
}