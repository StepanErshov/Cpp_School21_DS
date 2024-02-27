#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Formula();

int main(){
    
    Formula();
    return 0;

}

double Formula(){
    
    FILE* file_for_Va;
    file_for_Va = fopen("fila_for_Va.txt", "wt");
    double Y = 398600.4; 
    double EarthRadius = 6371; 
    double Ra = 45000;
    double H = 7001;
    double Rp = 7000; 
    
    for(int H = 0; H <= 60000; H += 1){
        
        double Va = sqrt((2 * Y * Rp)/((H + EarthRadius) * (H + EarthRadius + Rp)));
        fprintf(file_for_Va, "%.12lf\n", Va);
    
    }
    
}