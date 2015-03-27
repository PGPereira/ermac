#include <math.h>

/*
 * Essa biblioteca foi criada com o intuito de facilitar as atividades de física laboratorial 
 * do primeiro semestre de física. Licenciada sobre LGPL.
 * Seu principal objetivo é facilitar o cálculo de propagação de incertesas.
 * Autor: Pedro Gabriel Drumond Pereira
 * Email: pedrogabriel@dcc.ufmg.br
 * GitHub: https://github.com/PGPereira
 */

/* Calculo de erros */
double relativeError (double value, double error){
        /* A incerteza relativa é um número adimensional, utilizado para propagação de incertezas */
        return error/value;
}

double errorSum (double error1, double error2){
        /* A soma de erros consiste apenas em sua soma algébrica */
        return error1 + error2;
}

/* Multiplicação de erros */
double errorBase (double A, double errorA, double B, double errorB){
        return (relativeError(A, errorA) + relativeError(B, errorB));
}

double errorDiv (double A, double errorA, double B, double errorB){
        /* Vide errorMult; */
        return errorBase(A, errorA, B, errorB) * (A / B);
}

double errorMult (double A, double errorA, double B, double errorB){
        /* A multiplicação dos erros é dada na forma de ΔQ/Q = ΔA/A + ΔB/B
         * ou seja o erro (ΔQ) = (ΔA/A + ΔB/B) * Q, onde Q equivale a AxB*/ 
        return errorBase(A, errorA, B, errorB) * (A * B);
}

double errorPow (double A, double errorA, double index){
        return index * errorMult(A, errorA, A, errorA);
}

/* Matemática com os valores absolutos e sua parte de erro */
double * uncertainSum (double A, double errorA, double B, double errorB){
        static double retorno[2];

        retorno[0] = A + B;
        retorno[1] = errorSum(errorA, errorB);

        return retorno;
}

double * uncertainSub (double A, double errorA, double B, double errorB){
         static double retorno[2];

         retorno[0] = A - B;
         retorno[1] = errorSum(errorA, errorB);

         return retorno;
}

double * uncertainMult (double A, double errorA, double B, double errorB){
        static double retorno[2];

        retorno[0] = A * B;
        retorno[1] = errorMult(A, errorA, B, errorB);

        return retorno;
}

double * uncertainDiv (double A, double errorA, double B, double errorB){
        static double retorno[2];

        retorno[0] = A / B;
        retorno[1] = errorDiv(A, errorA, B, errorB);

        return retorno;
}

double * uncertainPow (double A, double errorA, double index){
        static double retorno[2];

        retorno[0] = pow(A, index);
        retorno[1] = errorPow(A, errorA, index);

        return retorno;
}
