
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double getMax(double r, double g, double b){
    double maxValue = (r < g) ? g : r;
    maxValue = (maxValue < b) ? b : maxValue;
    return maxValue;
}


int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){

    if(c == NULL || m == NULL || y == NULL || k == NULL){
        return 1;
    }
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
        return 1;
    }

    // Check for division by zero (r,g,b) = (0,0,0). In this case, CMYK values are (0,0,0,1)
    if(r == 0 && g == 0 && b == 0){
        *c = 0;
        *m = 0;
        *y = 0;
        *k = 1;
    }
    else {

        // Scale each r b g integer to get them to the [0, 1] range
        double rPrime = (double)r/255;
        double gPrime = (double)g/255;
        double bPrime = (double)b/255;

        double maxVal = getMax(rPrime, gPrime, bPrime);
        *k = 1 - maxVal;
        *c = (1 - rPrime - *k)/(1 - *k);
        *m = (1 - gPrime - *k)/(1 - *k);
        *y = (1 - bPrime - *k)/(1 - *k);
    }

    return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b){

    if(r == NULL || g == NULL || b == NULL){
        return 1;
    }
    if (c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1){
        return 1;
    }

    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return 0;
}