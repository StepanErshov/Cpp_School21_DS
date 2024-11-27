import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans

# Генерация синтетических данных
X, y_true = make_blobs(n_samples=300, centers=4, cluster_std=0.60, random_state=0)

# Визуализация исходных данных
plt.scatter(X[:, 0], X[:, 1], s=30)
plt.title("Сгенерированные данные")
plt.xlabel("Признак 1")
plt.ylabel("Признак 2")
plt.show()

# Применение K-средних для кластеризации
kmeans = KMeans(n_clusters=4)
kmeans.fit(X)
y_kmeans = kmeans.predict(X)

# Визуализация результатов кластеризации
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, s=30, cmap='viridis')
centers = kmeans.cluster_centers_
plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.75, marker='X')  # Центры кластеров
plt.title("Результаты кластеризации K-средних")
plt.xlabel("Признак 1")
plt.ylabel("Признак 2")
plt.show()