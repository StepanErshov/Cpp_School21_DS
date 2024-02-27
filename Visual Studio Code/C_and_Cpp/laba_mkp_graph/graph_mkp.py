import matplotlib.pyplot as plt
import math

with open("C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp.txt", 'r') as file:
    lines = [float(line.strip()) for line in file]
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp1.txt', 'r') as file:
    lines1 = [float(line.strip()) for line in file]
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp2.txt', 'r') as file:
    lines2 = [float(line.strip()) for line in file]
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp3.txt', 'r') as file:
    lines3 = [float(line.strip()) for line in file]
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp4.txt', 'r') as file:
    lines4 = [float(line.strip()) for line in file]
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba1/laba_mkp5.txt', 'r') as file:
    lines5 = [float(line.strip()) for line in file]


t = 28545
x = [0] * t
y = [0] * t
for i in range(t):
    x[i] = i



fig, axs = plt.subplots(nrows= 3 , ncols= 2 )
fig. suptitle('Plots Stacked Vertically')
axs[0, 0].plot(x, lines, label = "E iteration")
axs[1, 0].plot(x, lines1, label = "E divisiom")
axs[2, 0].plot(x, lines2,  label = "E golden")
axs[0, 1].plot(x, lines3,  label = "E Newton")
axs[1, 1].plot(x, lines4,  label = "M")
axs[2, 1].plot(x, lines5, label = "IST")
plt.legend()
plt.show()
