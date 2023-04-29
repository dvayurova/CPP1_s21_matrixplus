#include <cstdio>
#include "s21_matrix_oop.h"
 

int main()
{   
S21Matrix m;
double el = m.getElem(1, 1);
printf("elem: %f", el);
try {
S21Matrix p(-2,3);
double elP = p.getElem(1,2);
printf("\np elem: %f", elP);
printf("\ncols = %d, rows = %d", p.getCols(), p.getRows());}
catch (...) {
    printf("\nerror!");
}

return 0;
}