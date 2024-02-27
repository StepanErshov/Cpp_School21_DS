#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main(){
    
    //file connection
    
    FILE* file_for_Vi;
    file_for_Vi = fopen("file_for_Vi.txt", "wt");
    
    //entering variables

    double EarthRadius = 6371;
    double Height = 60000;
    double We = 0.000072921159;
    double Degree;
    double Vi;

    //entering a degree for speed research
    
    printf("Enter degree:\n");
    scanf("%lf", &Degree);
    Degree = Degree * (PI / 180);

    //loop for calculating speed at different heights
    
    for(int H = 0; H <= Height; H++){

        Vi = We * (EarthRadius + H) * cos(Degree);
        fprintf(file_for_Vi, "%.12f\n", Vi);

    }

    return 0;

}