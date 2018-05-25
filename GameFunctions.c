#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
 * loadQuestionResp(char* filename, int* nbQuest)
 * consiste a lire le contenu du fichier
 * puis stock les questions + réponses lues dans un tableau
 * ligne apres lignes
 *
 */
char ** loadQuestionResp(char* filename, int* nbQuest)
{
    FILE * fichier = NULL;
    char ligne[ 500 ];
    char* test = NULL;
    char** listQuestRep = NULL;
    int cpt = 0;
    fichier = fopen( filename,"r" );
    if( fichier != NULL )
    {
         test = fgets( ligne, 500, fichier );
         ( *nbQuest ) = atoi(ligne);
         listQuestRep = malloc( ( *nbQuest ) * 2  * sizeof( char * ) );
         int i;
         for( i = 0; i < ( *nbQuest ) * 2; i++ )
         {
             listQuestRep[ i ] = malloc( 500 * sizeof( char ) );
         }
         test = fgets( ligne, 500, fichier );
         while(test !=NULL)
         {
             strcpy( listQuestRep[ cpt ], ligne );
             cpt++;
             test = fgets( ligne, 500, fichier );
             strcpy( listQuestRep[ cpt ], ligne );
             cpt++;
             test = fgets( ligne, 500, fichier );
         }
         fclose( fichier );
    }
    return listQuestRep;
}

/**
 * randomQuestion( int NumTotQ )
 * consiste a tiré au hasard un numéro de question
 * parmi l’ensemble des questions, et retournera ce numéro
 *
 */
int randomQuestion( int NumTotQ )
{
    int nb = 0;
    srand(time(NULL));
    nb = rand()%NumTotQ;
    nb = nb*2;
    return nb;
}

/**
 * printQuestion( int RandNumb, char ** listQuestRep )
 * consiste a afficher une question en fonction de son numéro
 *
 */
void printQuestion( int RandNumb, char ** listQuestRep )
{
    printf( "\n\n%s\n", listQuestRep[ RandNumb ] );
    printf( "La bonne reponse est : %s\n", listQuestRep[ RandNumb+1 ] );
}

/**
 * getAnswer( char rep[] )
 * cette procédure demandera à l’utilisateur de saisir une réponse
 * et la stockera dans une variable de type chaine de caractères.
 *
 */
void getAnswer( char rep[] )
{
    printf( "Reponse : " );
    fgets( rep, 500, stdin );
}

/**
 * isGoodAnswer( int RandNumb, char ** listQuestRep, char *answer )
 * cette fonction prendra en entrée les questions/réponses
 * le numéro de la question posée et la réponse donnée par le joueur
 * et retournera 1 si la réponse est juste, 0 sinon
 *
 */
int isGoodAnswer( int RandNumb, char ** listQuestRep, char *answer )
{
    if( strcmp( answer, listQuestRep[ RandNumb+1 ] ) == 0 )
    {
        printf("\nReponse correct\n\n");
        return (1);
    }
    else
    {
        printf("\nReponse incorrect\n");
        printf( "La bonne reponse est : %s\n\n", listQuestRep[ RandNumb+1 ] );
        return (0);
    }
}


/**
 * printPercentSuccess( int NumTotQ, int NumTotRepJuste )
 * Cette procédure prendre en entrée le nombre de réponses justes du joueur
 * ainsi que le nombre de questions
 * et affichera à l’écran un message indiquant au joueur son score ( en pourcentage )
 *
 */
void printPercentSuccess( int NumTotQ, int NumTotRepJuste )
{
    float pcntRepJuste = ( NumTotRepJuste/NumTotQ )*100;
    char c='%';
    printf( "\n\nVous avez %d bonnes reponses", NumTotRepJuste );
    printf( "\nVous avez un score de %3.0f %c\n\n", pcntRepJuste, c );
}
