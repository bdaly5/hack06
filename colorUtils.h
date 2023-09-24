/**
 * Author: Berenice Daly
 *         bdaly5@unl.edu
 * Date: 9/20/2023
 *
 * This file contains the prototypes and documentation
 * for the colorUtils.c functions. These functions convert
 * between the RGB and CMYK models of colors.
 *
*/


/**
 * This function returns the maximum of 3
 * given doubles
 */
double getMax(double r, double g, double b);

/**
 * This function converts from an RGB color
 * model to a CMYK color model
*/
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * This function converts from a CMYK color
 * model to an RGB color model
*/
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);
