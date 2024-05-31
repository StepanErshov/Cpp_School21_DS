#include "Keplerian_Elements.h"

void disturbance(std::vector<double> THETA, int rounds) {

  double tempP = P;
  double tempE = e;
  double tempU = U;
  double tempo = U;
  double tempO = OMEGA;
  double tempS = 0;
  double tempT = 0;
  double tempW = 0;
  double tempI = I;
  int tmp = 0;

  std::vector<double>::iterator iter = THETA.begin();

  std::ofstream radius;
  radius.open("C:/projects/Visual Studio "
              "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/radius.txt");
  radius << std::setprecision(30);

  std::ofstream p;
  p.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/p.txt");
  p << std::setprecision(30);

  std::ofstream ke;
  ke.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/k.txt");
  ke << std::setprecision(30);

  std::ofstream qe;
  qe.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/q.txt");
  qe << std::setprecision(30);

  std::ofstream ecc;
  ecc.open("C:/projects/Visual Studio "
           "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/ecc.txt");
  ecc << std::setprecision(30);

  std::ofstream omega;
  omega.open("C:/projects/Visual Studio "
             "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/sigma.txt");
  omega << std::setprecision(30);

  std::ofstream i;
  i.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/i.txt");
  i << std::setprecision(30);

  std::ofstream sigma;
  sigma.open("C:/projects/Visual Studio "
             "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/"
             "omega.txt");
  sigma << std::setprecision(30);

  std::ofstream S;
  S.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/S.txt");
  S << std::setprecision(30);

  std::ofstream T;
  T.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/T.txt");
  T << std::setprecision(30);

  std::ofstream W;
  W.open("C:/projects/Visual Studio "
         "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/W.txt");
  W << std::setprecision(30);

  for (int step = 0; step < (360 * rounds) + 1; step += 15.0) {

    double tempTHETA = *(iter + tmp);
    double tempR = tempP / (1.0 + tempE * cos(tempTHETA));
    double q = ((pow(Wz, 2.0) * pow(Re, 3.0)) / mu);
    double Polar_compression = 1.0 / 298.25;
    double param = mu * pow(Re, 2.0) * (Polar_compression - (q / 2.0));
    double tempk = tempE * sin(tempo);
    double tempQe = tempE * cos(tempo);

    tempS = (param / pow(tempR, 4.0)) *
            (3.0 * pow(sin(tempTHETA), 2.0) * pow(sin(tempI), 2.0) - 1.0);
    tempT = -(param / pow(tempR, 4.0)) *
            (pow(sin(tempI), 2.0) * sin(2.0 * tempTHETA));
    tempW = -(param / pow(tempR, 4.0)) * sin(2.0 * tempI) * sin(tempTHETA);

    double gamma = 1.0 - ((tempW * pow(tempR, 3.0)) / ((mu * tempP)) *
                          sin(tempTHETA) * (cos(tempI) / sin(tempI)));

    double uChange = ((sqrt(mu * tempP) / pow(tempR, 2.0))) * gamma;

    double pChange = ((2.0 * tempT) / gamma) * (pow(tempR, 3.0) / mu);

//     double eChange = (pow(tempR, 2.0) / (gamma * mu)) *
//                      (tempS * sin(tempTHETA) +
//                       tempT * ((1.0 + (tempR / tempP)) * cos(tempTHETA) +
//                                tempE * (tempR / tempP)));

    double omChange =
        (pow(tempR, 2.0) / (gamma * mu * tempE)) *
        (-tempS * cos(tempTHETA) +
         (tempT * (1.0 + (tempR / tempP) * sin(tempTHETA) -
                   (tempW * (tempR / tempP) * tempE *
                    (cos(tempI) / sin(tempI)) * sin(tempTHETA)))));

    double iChange =
        (pow(tempR, 3.0) / (gamma * mu * tempP)) * (tempW * cos(tempTHETA));

    double OmChange = (pow(tempR, 3.0) / (gamma * mu * tempP)) *
                      (tempW * (sin(tempTHETA) / sin(tempI)));

    double qeChange = (pow(tempR, 2) / (gamma * mu)) *
                      ((tempS * sin(tempTHETA)) +
                       (tempT * ((1 + (tempR / tempP) * cos(tempTHETA)) +
                                 ((tempR / tempP) * tempQe))) +
                       (tempW * (tempR / tempP) * tempk *
                        (cos(tempI) / sin(tempI)) * sin(tempTHETA)));

    double kChange = (pow(tempR, 2) / (gamma * mu)) *
                         ((-tempS * cos(tempTHETA)) +
                          (tempT * (((1 + (tempR / tempP)) * sin(tempTHETA)) +
                                    ((tempR / tempP) * tempk)))) -
                     (tempW * (tempR / tempP) * tempQe * (cos(tempI) / sin(tempI)) *
                      sin(tempTHETA));

//     std::cout << "delta p = " << pChange << "; delta e = " << eChange
//               << "; delta OMEGA = " << omChange << "; delta i = " << iChange
//               << "; delta OMEGABOL = " << OmChange << "." << std::endl;

    radius << tempR << " ";
    p << tempP << " ";
    ecc << tempE << " ";
    omega << tempo << " ";
    i << tempI << " ";
    sigma << tempO << " ";
    S << tempS << " ";
    T << tempT << " ";
    W << tempW << " ";
    ke << tempk << " ";
    qe << tempQe << " ";

    tempP += (15.0 * PI / 180.0) * pChange;
    tempk += (15.0 * PI / 180.0) * kChange;
    tempQe += (15.0 * PI / 180.0) * qeChange;
    tempo = atan(tempk/tempQe);
    tempE += tempQe / cos(tempo);
    tempU += (15.0 * PI / 180.0) * uChange;
    tempI += (15.0 * PI / 180.0) * iChange;
    tempO += (15.0 * PI / 180.0) * OmChange;
    tmp++;
  }

  radius.close();
  p.close();
  ecc.close();
  omega.close();
  i.close();
  sigma.close();
  S.close();
  T.close();
  W.close();
}