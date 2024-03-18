users = [
    {"id": 0, "name": "Hero"},
    {"id": 1, "name": "Dunn"},
    {"id": 2, "name": "Sue"},
    {"id": 3, "name": "Chi"},
    {"id": 4, "name": "Thor"},
    {"id": 5, "name": "Clive"},
    {"id": 6, "name": "Hicks"},
    {"id": 7, "name": "Devin"},
    {"id": 8, "name": "Kate"},
    {"id": 9, "name": "Klevin"},
]

friendship_pairs = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 3), (3, 4), 
                    (4, 5), (5, 6), (5, 7), (6, 8), (7, 8), (8, 9)]

#Иницилизировать словарь пустым списком для индификатора
#каждого пользователя
friendship = {user["id"]: [] for user in users}
print(f"Первое действие: {friendship}")
#Перебрать все дружеские пары, заполняя их:
for i, j in friendship_pairs:
    friendship[i].append(j) #Добавить j как друга i
    friendship[j].append(i) #Добавить i как друга j
print(f"Второе действие: {friendship}")
def number_of_friends(user):
    """Сколько друзей есть у пользователя"""
    user_id = user["id"]
    friends_ids = friendship[user_id]
    return len(friends_ids)

for user in users:
    print(f"{user['name']} имеет {number_of_friends(user)} друзей.")
    