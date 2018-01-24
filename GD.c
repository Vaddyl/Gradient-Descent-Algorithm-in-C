#include <stdio.h>
#include <math.h>
#define a 0.0002 // Set a constant learning rate

/*
Pseuodocode
Dimana J(b0, b1) ada fungsi cost production (mean squared error) dan a adalah learning rate
repeat until convergence {
    b0 = b0 - a*d/db0(J(b0, b1))
    b1 = b1 - a*d/db1(J(b0, b1))
*/

// Hypothesis function
float h(int x, float b0, float b1){
    return x*b1+b0;
}

// b0 partial derivative function
float db0(int *x, int *y, int n, float b0, float b1){
    int i;
    float d = 0;
    for(i=0; i<n; i++){
        d += h(x[i], b0, b1) - y[i];
    }
    return d;
}

// b1 derivative function
float db1(int *x, int *y, int n, float b0, float b1){
    int i;
    float d = 0;
    for(i=0; i<n; i++){
        d += (h(x[i], b0, b1) - y[i])*x[i];
    }
    return d;
}


int main(){
    int n = 10, i;
    int x[10] = {31, 38, 48, 52, 63, 67, 75, 84, 89, 99}, y[10] = {553, 590, 608, 682, 752, 725, 834, 752, 845, 960};
    float b0, b1, learn_b0, learn_b1, temp0=0, temp1=0;

    // scanf("%d", &n);

    /*
    for(i=0; i<n; i++){
        scanf("%d", &x[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &y[i]);
    }
    */

    // Start from the point b0 = 0 and b1 = 0
    b0 = 0; b1 = 0;
    learn_b0 = db0(x, y, n, b0, b1);
    learn_b1 = db1(x, y, n, b0, b1);
    b0 = b0 - a*learn_b0/(float)n;
    b1 = b1 - a*learn_b1/(float)n;
    while( fabs(b0 - temp0) > 0.0001 && fabs(b1 - temp1) > 0.0001 ){
        printf("%f %f\n", b0, b1);
        temp0 = b0;
        temp1 = b1;
        learn_b0 = db0(x, y, n, b0, b1);
        learn_b1 = db1(x, y, n, b0, b1);
        b0 = b0 - a*learn_b0/(float)n;
        b1 = b1 - a*learn_b1/(float)n;
    }

    printf("b0 = %.2f dan b1 = %.2f\n", b0, b1);
    return 0;
}
