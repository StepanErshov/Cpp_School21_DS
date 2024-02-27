import csv
with open('C:/projects/Visual studio 2022/Лабы по мкп/laba2/Vn.txt', "r") as csvfile:
    data = csv.reader(csvfile, delimiter = '|')
    minval = []
    maxval = []
    for i in data:
        minval.append(i[0])
        maxval.append(i[0])
print(min(minval))
print(max(maxval))