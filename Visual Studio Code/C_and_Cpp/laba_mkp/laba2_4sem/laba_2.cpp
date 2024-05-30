#include "Keplerian_Elements.h"

std::vector<double> createTHETA(int rounds);

int main() {
  int rounds = 3;
  std::vector<double> THETA = createTHETA(rounds);
  undisturbance();
  disturbance(THETA, rounds);
  return 0;
}

std::vector<double> createTHETA(int rounds) {
  std::ofstream file;
  std::ofstream unperturbedRadius;
  unperturbedRadius.open(
      "C:/projects/Visual Studio "
      "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/unperturbedRadius.txt");
  std::vector<double> THETA;
  file.open("C:/projects/Visual Studio "
            "Code/C_and_Cpp/laba_mkp/laba2_4sem/files/THETAparams.txt");

  for (int step = 0; step < (360 * rounds) + 1; step += 15) {
    double stepPI = step * PI / 180.0;
    THETA.push_back(stepPI);
    unperturbedRadius << (P / (1.0 + e * cos(stepPI))) << " ";
    file << step << " ";
  }
  file.close();
  unperturbedRadius.close();
  return THETA;
}