#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int print_menu();
int jeu(int val);
int print_menu_2();
int niveau();

int main(void){
    int choix = print_menu();
    while (choix == 1){
        jeu(rand() % niveau());
        choix = print_menu_2();
        if (choix == 3){
            choix = print_menu();
        }
    }
}

int print_menu(){
    int choix;
    printf("        Bienvenue de le jeu        \n");  
    printf("\n");
    printf("Jouer : 1");
    printf("                            Quitter : 2\n");
    printf("\n");
    scanf("%d", &choix);
    return choix;
}

int niveau(){
    int choix;
    printf("        Saisissez le niveau de difficulté       \n");
    printf("Facile: 1   Moyen: 2    Difficile: 3\n");
    scanf("%d", &choix);
    if (choix == 1){
        return 50;
    }
    if (choix == 2){
        return 100;
    }
    else {
        return 500;
    }
}

int jeu(int val){
    int val_user, essai = 1;
    printf("Saisissez une premiere valeur: ");
    scanf("%d", &val_user);
    while(val_user != val && essai <= 15){
        if (val_user > val){
            printf("Saisissez plus petit: ");
            scanf("%d", &val_user);
            essai ++;
        }
        if (val_user < val){
            printf("saisissez plus grands: ");
            scanf("%d", &val_user);
            essai ++;
        }
    }
    if (val_user == val){
        printf("Vous avez gagné avec %d essai(s)\n", essai);
    }
    else {
        printf("Vous avez perdu(e), la bonne réponse est: %d\n", val);
    }
    return 1;
}

int print_menu_2(){
    int choix = 0;
    printf("        Voulez vous rejouer: appuyez sur 1\n        quitter: appuyez sur 2\n        revenir au menu: appuyez sur 3.\n");
    printf("\n");
    scanf("%d", &choix);
    return choix;
}