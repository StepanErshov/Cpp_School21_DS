import matplotlib.pyplot as plt

#          ↓вот здесь надо ввести свой путь до файла в каждом with open и всё↓   вот здесь ничего не менять
with open('C:/projects/Visual Studio Code/C_and_C++/kursovaya/rezult_for_Vi.txt', 'r') as file:
    Vc = [float(line.strip()) for line in file]
#          ↓вот здесь надо ввести свой путь до файла в каждом with open и всё↓   вот здесь ничего не менять    
with open('C:/projects/Visual Studio Code/C_and_C++/kursovaya/rezult.txt', 'r') as file:
    Vi = [float(line.strip()) for line in file]
#          ↓вот здесь надо ввести свой путь до файла в каждом with open и всё↓    вот здесь ничего не менять
with open('C:/projects/Visual Studio Code/C_and_C++/kursovaya/hw8.txt', 'r') as file:
    Va = [float(line.strip()) for line in file]

#дальше тоже менять ничего не надо

Height = [0] * 60001
for i in range(60001):
    Height[i] = i



plt.title('Графики')
plt.plot(Height, Vc, label='Vc', color = 'green', marker='o', markersize = 2)
plt.plot(Height, Vi, label='Vi', color = 'blue', marker='o', markersize = 2)
plt.xlabel('Высота')
plt.ylabel('Скорость')
plt.grid()
plt.legend()
plt.show()