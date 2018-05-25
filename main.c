#include <stdio.h>
#include <stdlib.h>
#include <time.h> // ici la librairie time pour le tirage au hasard
#include <math.h>// Ici , la librairie math pour le calcul de pourcentage
#include "GameFunctions.c"



int main()
{
    int num_random = 0;
    int nbQ = 0;
    int NbDeRepJst = 0;
    char *answer[500];
    char ** questionsRep = loadQuestionResp("QuestRep.txt", &nbQ);


    printf("================== Bienvenue dans le jeu du Questions pour un champion ! ================ \n\n");

    int i;
    for(i=0; i < nbQ ; i++)
    {
        num_random = randomQuestion( nbQ );
        printQuestion( num_random, questionsRep );
        getAnswer( *answer );
        NbDeRepJst = NbDeRepJst + ( isGoodAnswer( num_random, questionsRep, *answer ) );
    }
    printf("================== Fin du jeu du Questions pour un champion ! ================ \n\n");
    printPercentSuccess( nbQ, NbDeRepJst );

    for(i=0; i< nbQ ; i++)
        free(questionsRep[i]);

    free(questionsRep);
    questionsRep=NULL;

    system("pause");
    return 0 ;
}
