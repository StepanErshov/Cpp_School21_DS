import pandas as pd

# Создание датафрейма
data = {
    'apples': [3, 2, 0, 1],
    'oranges': [0, 3, 7, 2],
    'lemons': [1, 0, 3, 9]
}

purchases = pd.DataFrame(data)

# Фильтрация и получение суммы проданных яблок
result = purchases[purchases['oranges'] > 2][:-1]['apples'].sum()

print(result)