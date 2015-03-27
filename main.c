#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ermac.h"

clear (void){
  while ( getchar() != '\n' );
}

int main(){
        char operando;
        double alfa[2];
        double beta[2];
        double *resolucao = NULL;
        float expoente = 0;
        bool menu = true;

        do {
                if (menu){
                        printf("\n");
                        printf("|------------------------------------------\n");
                        printf("| Esse programa executa propagação de erro.\n");
                        printf("| Escolha a forma de propagação desejada.\n");
                        printf("|\t( + ) - Soma.\n");
                        printf("|\t( - ) - Subtraçãp.\n");
                        printf("|\t( * ) - Multiplicação.\n");
                        printf("|\t( / ) - Divisão.\n");
                        printf("|\t( ^ ) - Potência.\n");
                        printf("| Outras opções:\n");
                        printf("|\t( o ) - Desativar esse menu\n");
                        printf("|\t( q ) - Sair\n");
                        printf("|------------------------------------------\n");
                        printf("\n");
                } else {
                        printf("Pressione O para reativar o menu\n\n");
                }

                scanf("%c", &operando);

                switch (operando){
                        case '+':
                                printf("\e[1;1H\e[2J");
                                printf("Entre com os valores na forma de:\n");
                                printf("A, ErroA, B, ErroB\n\n");

                                scanf("%lf %lf %lf %lf",&alfa[0] ,&alfa[1] ,&beta[0] ,&beta[1]);
                                resolucao = uncertainSum(alfa[0], alfa[1], beta[0], beta[1]);

                                printf("Resultado = %lf +/- %lf\n", resolucao[0], resolucao[1]);

                                clear();
                                break;
                        case '-':
                                printf("\e[1;1H\e[2J");
                                printf("Entre com os valores na forma de:\n");
                                printf("A, ErroA, B, ErroB\n\n");

                                scanf("%lf %lf %lf %lf",&alfa[0] ,&alfa[1] ,&beta[0] ,&beta[1]);
                                resolucao = uncertainSub(alfa[0], alfa[1], beta[0], beta[1]);

                                printf("Resultado = %lf +/- %lf\n", resolucao[0], resolucao[1]);

                                clear();
                                break;
                        case '*':
                                printf("\e[1;1H\e[2J");
                                printf("Entre com os valores na forma de:\n");
                                printf("A, ErroA, B, ErroB\n\n");

                                scanf("%lf %lf %lf %lf",&alfa[0] ,&alfa[1] ,&beta[0] ,&beta[1]);
                                resolucao = uncertainMult(alfa[0], alfa[1], beta[0], beta[1]);

                                printf("Resultado = %lf +/- %lf\n", resolucao[0], resolucao[1]);

                                clear();
                                break;

                        case '/':
                                printf("\e[1;1H\e[2J");
                                printf("Entre com os valores na forma de:\n");
                                printf("A, ErroA, B, ErroB\n\n");

                                scanf("%lf %lf %lf %lf",&alfa[0] ,&alfa[1] ,&beta[0] ,&beta[1]);
                                resolucao = uncertainDiv(alfa[0], alfa[1], beta[0], beta[1]);

                                printf("Resultado = %lf +/- %lf\n", resolucao[0], resolucao[1]);

                                clear();
                                break;
                        case '^':
                                printf("\e[1;1H\e[2J");
                                printf("Entre com os valores na forma de:\n");
                                printf("A, ErroA, expoente\n\n");

                                scanf("%lf %lf %f",&alfa[0] ,&alfa[1], expoente);
                                resolucao = uncertainPow(alfa[0], alfa[1], expoente);

                                printf("Resultado = %lf +/- %lf\n", resolucao[0], resolucao[1]);

                                clear();
                                break;

                        case 'o': case 'O':
                                menu = !menu;
                                clear();
                                break;

                        case 'q': case 'Q':
                                printf ("Saindo do programa.\n");
                                printf ("Obrigado por utilizá-lo.\n");
                                return 0;
                                break;

                        default:
                                printf("\e[1;1H\e[2J");
                                printf ("Existe um erro na entrada escolhida\n");
                                clear();
                                break;
                }
        } while (operando != 'Q' && operando != 'q');
}
