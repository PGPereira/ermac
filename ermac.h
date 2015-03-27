#ifndef ERMAC_H
#define ERMAC_H

double relativeError (double value, double error);
double errorSum (double error1, double error2);

/* Multiplicação de erros */
double errorBase (double A, double errorA, double B, double errorB);
double errorDiv (double A, double errorA, double B, double errorB);
double errorMult (double A, double errorA, double B, double errorB);
double errorPow (double A, double errorA, double index);

/* Matemática com os valores absolutos e sua parte de erro */
double * uncertainSum (double A, double errorA, double B, double errorB);
double * uncertainSub (double A, double errorA, double B, double errorB);
double * uncertainMult (double A, double errorA, double B, double errorB);
double * uncertainDiv (double A, double errorA, double B, double errorB);
double * uncertainPow (double A, double errorA, double index);

#endif

