#include <stdio.h>
#include <math.h>
#define AngularSpeed 0.000072921159
#define M_PI 3.141592653589793

int main(){
    FILE* rezult2;
    rezult2 = fopen("rezult2.txt", "wt");
    double Radius_Earth = 6371;
    double H_max = 60000; //maximum height value
    double Degree;
    double Vi;
    printf("Enter degree:\n");
    scanf("%lf", &Degree);
    Degree = Degree * (M_PI / 180); //convert degrees to radians
    for(int Height = 0; Height <= H_max; Height++){
        Vi = AngularSpeed * (Radius_Earth + Height) * cos(Degree);
        fprintf(rezult2, "%.10f\n", Vi);
    }
    return 0;
}