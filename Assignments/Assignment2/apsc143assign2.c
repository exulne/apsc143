#include <stdio.h>
#include <math.h>


double inverseFactorial(int n);
double taylorSeries(double x, double minTermSize);
double integralTaylorSeries(double lowerLimit, double upperLimit, double minTermSize);
double riemannSum(double lowerLimit, double upperLimit, double numRectangles);



int main(void){
    printf("%f\n", taylorSeries(0.5, 0.0001));
    printf("%f\n", integralTaylorSeries(-2.0, 0.0, 0.1));
    printf("%f\n", riemannSum(-0.5, 1.5, 100000));

    return 0;
}

double inverseFactorial(int n){
    double result = 1;
    for (double i = 1.0; i <= n; i++){
        result *= (1.0/i);
    }
    return result;
}

double taylorSeries(double x, double minTermSize){
    double sum = 0;

    for (double n = 0;;n++){
        double term = inverseFactorial(n) * pow(x, 2 * n);
        if (term > minTermSize){
            sum += term;
        }
        else{
            return sum;
        }
    }

    return sum;
}

double integralTaylorSeries(double lowerLimit, double upperLimit, double minTermSize){
    double sum = 0;
    for (double n = 0;;n++){
        double term = inverseFactorial(n) * (pow(upperLimit, 2 * n + 1) - pow(lowerLimit, 2 * n + 1)) / (2 * n + 1);
        if (term > minTermSize){
            sum += term;
        }
        else{
            return sum;
        }
    }
}

double riemannSum(double lowerLimit, double upperLimit, double numRectangles){
    double sum = 0;

    for (double i = 0; i < numRectangles; i++){
        double deltaX = (upperLimit - lowerLimit) / numRectangles;
        double Xi = lowerLimit + i * deltaX;

        double powEuler = exp(pow(Xi, 2)) * deltaX;

        sum += powEuler;
    }

    return sum;


}