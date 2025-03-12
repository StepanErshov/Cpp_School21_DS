import random as rnd

stack = ['бомж', 'теперь', 'я']

for i in stack:
    for j in stack:
        for k in stack:
            if(i != j and i != k and k != j):
                print(i + ' ' + j + ' ' + k)


print('-----------------------------------------------------------------------------------------------------------------------------')
count = 0

while(count != 3**3):
    x1 = rnd.randint(0, 2)
    x2 = rnd.randint(0, 2)
    x3 = rnd.randint(0, 2)
    stc = [3**3]
    string = ''
    if(stack[x1] != stack[x2] and stack[x1] != stack[x3] and stack[x3] != stack[x2]):
        string = stack[x1] + ' ' + stack[x2] + ' ' + stack[x3]
        print(string)
    count += 1

import asyncio

async def my_async_function():
    print("Начало асинхронной функции")
    await asyncio.sleep(1)
    print("Конец асинхронной функции")

async def main():
    print("Начал главной функции")
    await my_async_function()
    print("Конец главной функции")

# Запуск асинхронного кода
asyncio.run(main())



import asyncio

async def task(name):
    print(f"Task {name} started")
    await asyncio.sleep(1)
    print(f"Task {name} finished")

async def main():
    tasks = [task(str(i)) for i in range(5)]
    await asyncio.gather(*tasks)

asyncio.run(main())