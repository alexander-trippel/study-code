#include <stdio.h>
#include <string.h>



int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp = 45;
    printf("x = %d/n", **pp);

    /*
    4. What are the types of the following expressions?
    - x --> integer, x = 10
    - p --> pointer to address of x
    - *p --> pointer to value of x
    - pp --> pointer to pointer to address of x
    - *pp --> pointer to address of pointer p
    - **pp -- pointer to pointer to value of x
    */

    

    return 0;
}