#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    FILE * rezult2;
    rezult2 = fopen("rezult2.txt", "wt");
    double Y = 398600.4; // км^3/c^2
    int Radius_Earth = 6371; // км
    int Ra = 45000;// км
    int High = 7001; // км, тк Ra не должно быть меньше Rp
    double Rp = 7000; // км
    
    for(int High = 0; High <= 60000; High += 1){
        
        double Va = sqrt((2 * Y * Rp)/((High + Radius_Earth) * (High + Radius_Earth + Rp)));
        fprintf(rezult2, "%.12lf\n", Va);
    
    }
    return 0;
}