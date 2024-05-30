#include "Keplerian_Elements.h"

void undisturbance() {

  std::vector<double> param = {P, OMEGA, I, U, e};
  std::ofstream file;

  file.open("C:/projects/Visual Studio "
            "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/Disturbance.txt");

  for (int i = 0; i < 5; i++) {
    file << param[i] << " ";
  }

  file.close();
}