def find_max_fives(grades):
    # Переменные для подсчета количества пятерок и текущей позиции
    max_fives = 0
    current_position = 0
    
    # Проходим по всем оценкам
    for i in range(len(grades)):
        if grades[i] == 5:
            # Если оценка - пятерка, увеличиваем счетчик
            max_fives += 1
        elif grades[i] == 2 or grades[i] == 3:
            # Если оценка - двойка или тройка, начинаем новый подсчет
            current_position = i + 1
            max_fives = 0
    
    # Возвращаем максимальное количество пятерок
    return max_fives

# Чтение входных данных
n = int(input())
grades = list(map(int, input().split()))

# Вывод результата
print(find_max_fives(grades))