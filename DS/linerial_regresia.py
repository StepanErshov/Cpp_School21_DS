import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

# Генерируем некоторые данные
# X - независимая переменная (например, количество часов обучения)
# y - зависимая переменная (например, оценка на экзамене)
X = np.array([[1], [2], [3], [4], [5], [6], [7], [8], [9], [10]])
y = np.array([1.5, 1.7, 3.0, 3.5, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0])

# Разделяем данные на обучающую и тестовую выборки
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Создаем модель линейной регрессии
model = LinearRegression()

# Обучаем модель
model.fit(X_train, y_train)

# Делаем предсказания
y_pred = model.predict(X_test)

# Выводим результаты
print("Предсказанные значения:", y_pred)
print("Истинные значения:", y_test)

# Визуализируем результаты
plt.scatter(X, y, color='blue', label='Исходные данные')
plt.plot(X, model.predict(X), color='red', label='Линия регрессии')
plt.xlabel('Часы обучения')
plt.ylabel('Оценка на экзамене')
plt.legend()
plt.show()