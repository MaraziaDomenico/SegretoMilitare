#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define ND 7
#define NDA 3


typedef char n_dipendente[20];
typedef char n_dipendenteaut[20];


int main()
{
    int orarioentr,orariousc,i,scelta,a,contrpass,s=0,controllo,num,b;
    int password[NDA],totoredipendenteaut[NDA],contdipendenteaut[NDA],totoredipendente[ND],forzdipendente[ND];

    n_dipendente dipendente[ND];
    n_dipendenteaut dipendenteaut[NDA];

    for(i=0; i<ND; i++){
        totoredipendente[i]=0;
        forzdipendente[i]=0;
    }
    for(i=0; i<NDA; i++){
        totoredipendenteaut[i]=0;
        contdipendenteaut[i]=0;
    }



    for(i=0; i<ND; i++){
        printf("Inserire il cognome del dipendente %d: ",i+1);
        scanf("%s",&dipendente[i]);

    }
    system("cls");

    for(i=0; i<NDA; i++){
        printf("Inserire il cognome del dipendente autorizzato %d: ",i+1);
        scanf("%s",&dipendenteaut[i]);
        printf("\nInserire la sua password numerica: ");
        scanf("%d",&password[i]);
        system("cls");
    }

    a=0;
    while(a==0)
    {
         printf("\t\t===SEGRETO MILITARE===");
         printf("\n\n\n");
         printf("\n1.Accesso al reparto riservato");
         printf("\n2.Accesso al reparto riservato senza autorizzazione");
         printf("\n3.Pannello di controllo amministratore");
         printf("\n\n\nInserire scelta --> ");
         scanf("%d",&scelta);
         switch(scelta)
         {
         case 1:
            system("cls");
            printf("Inserire la password -> ");
            scanf("%d",&contrpass);
            for(i=0; i<NDA; i++){
                if(contrpass==password[i]){
                    system("cls");
                    printf("Benvenuto nel reparto riservato %s",dipendenteaut[i]);
                    printf("\n\nInserire l'orario di entrata --> ");
                    scanf("%d",&orarioentr);
                    printf("\n\nInserire l'orario di uscita --> ");
                    scanf("%d",&orariousc);
                    totoredipendenteaut[i]=orariousc-orarioentr;
                    contdipendenteaut[i]++;
                    printf("\n\n");
                    s=1;
                    system("pause");
                    system("cls");
                }
            }
            if(s==0){
                printf("Password errata...\n");
                system("pause");
                system("cls");
            }
            break;
         case 2:
            system("cls");
            printf("Vuoi forzare l'ingresso? Si=1 No=2  --> ");
            scanf("%d",&controllo);
            if(controllo==1){
                printf("\n\nInserire il numero del dipendente --> ");
                scanf("%d",&num);
                i=num;
                printf("\n\nInserire l'orario di entrata --> ");
                scanf("%d",&orarioentr);
                printf("\n\nInserire l'orario di uscita --> ");
                scanf("%d",&orariousc);
                totoredipendente[i]=orariousc-orarioentr;
                forzdipendente[i]++;
                printf("\n\n");
                system("pause");
                system("cls");
            }
            system("cls");
            break;
         case 3:
            system("cls");
            b=0;
            while(b==0){
            printf("\t\t===PANNELLO DI CONTROLLO===");
            printf("\n\n\n");
            printf("\n1.Storico entrate dipendenti autorizzati");
            printf("\n2.Storico entrate dipendenti non autorizzati");
            printf("\n3.Ritorna alla schermata principale");
            printf("\n\nInserire la scelta --> ");
            scanf("%d",&scelta);
            switch(scelta)
                   {
                   case 1:
                    system("cls");
                    for(i=0; i<NDA; i++){
                        printf("\t====Storico del dipendente %s====",dipendenteaut[i]);
                        printf("\n\n\n");
                        printf("Il dipendente e' entrato nel reparto riservato %d volte",contdipendenteaut[i]);
                        printf("\nE ha totalizzato %d ore nel reparto",totoredipendenteaut[i]);
                        printf("\n");
                        system("pause");
                        system("cls");

                    }
                    break;
                   case 2:
                       for(i=0; i<ND; i++){
                        printf("\t====Storico del dipendente %s====",dipendente[i]);
                        printf("\n\n\n");
                        printf("Il dipendente ha forzato l'ingresso %d volte",forzdipendente[i]);
                        printf("\nE ha totalizzato %d ore nel reparto",totoredipendente[i]);
                        printf("\n");
                        system("pause");
                        system("cls");

                    }
                    break;
                   case 3:
                    system("cls");
                    b=1;
                   default:
                    printf("Errore");
                    system("cls");

                   }


            }
            break;
                   default:
                       printf("Errore");
                       system("cls");


         }



    }



    return 0;
}



