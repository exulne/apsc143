#include <stdio.h>
#include <math.h>


double inverseFactorial(int n);
double taylorSeries(double x, double minTermSize);
double integralTaylorSeries(double lowerLimit, double upperLimit, double minTermSize);
double riemannSum(double lowerLimit, double upperLimit, int numRectangles);



int main(void){
    printf("%f\n", taylorSeries(0.5, 0.0001));
    printf("%f\n", integralTaylorSeries(-2.0, 0.0, 0.1));
    printf("%f\n", riemannSum(-0.5, 1.5, 100000));

    return 0;
}

// multiply some initial variable 1 (Because 0! = 1) by the inverse of i for every term in some factorial n!
double inverseFactorial(int n){
    double result = 1;
    for (double i = 1.0; i <= n; i++){
        result *= (1.0/i);
    }
    return result;
}


double taylorSeries(double x, double minTermSize){
    double sum = 0;
    // while loop that doesn't increment n within actual loop code. 
    for (double n = 0;;n++){
        double term = inverseFactorial(n) * pow(x, 2 * n);
        // check to see if term is greater than minimum, add term to total if it is otherwise terminate
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
        // check to see if term is greater than minimum, add term to total if it is otherwise terminate
        if (term > minTermSize){
            sum += term;
        }
        else{
            return sum;
        }
    }
}

// approximate riemann sum using left riemann sum 
double riemannSum(double lowerLimit, double upperLimit, int numRectangles){
    double sum = 0;
    for (double i = 0; i < numRectangles; i++){
        double deltaX = (upperLimit - lowerLimit) / numRectangles;
        double Xi = lowerLimit + i * deltaX;

        // calculate the area of the rectangles
        double rectArea = exp(pow(Xi, 2)) * deltaX;

        sum += rectArea;
    }

    return sum;


}