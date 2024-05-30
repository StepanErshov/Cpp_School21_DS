#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

#define PI 3.1415926
using namespace std;

//Earth parameters
#define apogee_radius 450.0 + 6378.1 //apogee height
#define perigee_radius 340.0 + 6378.1 //perigee height
#define grav_param 398600.4415 //Gravitational parameter of the Earth
#define angular_vel 7.2921158553 * pow(10.0, -5.0) //Angular velocity of the Earth

#define i 20.0 * PI / 180.0 //inclanation
#define Omega 10.0 * PI / 180.0 // ascending node longitude
#define omega 0.0 // pericenter argument
#define M0 45.0 * PI / 180.0 // average anomaly

#define SMA (((apogee_radius) + (perigee_radius)) / 2) // semi-major axis
#define ECC (((apogee_radius) - (perigee_radius)) / (2 * (SMA))) //eccentricity

#define T 2 * PI * sqrt(pow((SMA), 3.0) / grav_param)

#define SIGMA (12.0 * 2.0) / (2.0 * 1500.0)

int main(){
    cout << "average anomaly start " << M0 << endl;
    double time1 = T / 13.6; //рандом
    double time2 = 0; //перегей
    double time3 = T / 2; //апогей
    double M1 = M0 + (2.0 * PI / (T)) * time1;
    double M2 = M0 + (2.0 * PI / (T)) * time2;
    double M3 = M0 + (2.0 * PI / (T)) * time3;

    cout << "random M " << M1 << endl << "perecentr M " << M2 << endl << "apocentre M " << M3 << endl;

    double E_anomaly_past1 = M1;
	double E_anomaly1 = M1 + ECC * sin(E_anomaly_past1);
    double E_anomaly_past2 = M2;
	double E_anomaly2 = M2 + ECC * sin(E_anomaly_past2);
    double E_anomaly_past3 = M3;
	double E_anomaly3 = M3 + ECC * sin(E_anomaly_past3);
    
    cout << "random E " << E_anomaly1 << endl << "perecentr E " <<  E_anomaly2 << endl << "apocentre E " << E_anomaly3 << endl;
    
    return 0;

}

