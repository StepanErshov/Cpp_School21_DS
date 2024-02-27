#include <stdio.h>
#include <math.h>
#define Grav 398600.4 //constant gravitational parameter for the earth
#define Radius_Earth 6371 //radius of the earth to calculate speed

double Vc();

double Hc = 60000; //usable maximum height

int main(){
    Vc();
    return 0;
}

double Vc(){
    FILE* rezult_for_Earth;
    rezult_for_Earth = fopen("rezult_for_Earth.txt", "wt");
    for(int i = 0; i <= Hc; i++){
        double Vc = sqrt(Grav/(Radius_Earth + i));
        fprintf(rezult_for_Earth, "%.12f\n", Vc);
    }
    return 0;
}