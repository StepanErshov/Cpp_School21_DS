#include <stdio.h>
#include <math.h>

double speed();

int main(){
    speed();
    return 0;
}

double speed(){
    FILE* rezult;
    rezult = fopen("rezult.txt", "wt");
    double Ny = 398600.4;
    double Rc = 6371;
    double Hc = 60000;
    double i = 0;
    for(int i = 0; i <= Hc; i++){
        double Vc = sqrt(Ny/(Rc + i));
        fprintf(rezult, "%.12f\n", Vc);
    }
    return 0;
}

