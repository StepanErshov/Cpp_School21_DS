#### ООП :
##### [Классы и объекты](https://proglib.io/p/python-oop):
###### В Python каждый класс наследуется от встроенного базового суперкласса object  ######

Класс объединяет в себя методы и свойства его объектов.
Инициализация: 
```python
	size_x = 5
	size_y = 6
	
Class Table(<Родительские классы>):
	
	def __init__ (self, size_x,size_y): ## метод инициализации
		self.size_x = size_x
		self_size_y = size_y
		
	def clean(self):
		...
```

Можно написать @staticmethod, он позволяет не писать self. Доступ к методам класса можно получать из экземпляров класса, и из самого класса.
```python
Table.clean() # --- Можно так
table1 = Table() # --- А можно так
table1.clean
```

@classmethod создает классовый метод. Он аналогичен методам экземпляров, но выполняется не в контексте объекта, а в контексте самого класса. Требует указание на класс (cls).
```python
Table.clean() # --- Можно только так

#Тогда в реализации метода должно быть:
def clean(cls):
	...
```


Объекты создаются при вызове класса:
```python
table_1 = Table()
```

##### [Наследование](https://www.geeksforgeeks.org/inheritance-in-python/):

Способность одного класса выводить или наследовать свойства из другого класса.

```python
Class BaseClass:
	{Body}
Class DerivedClass(BaseClass):
	{Body}
```

!! Если в родительском классе не вызвать init(), то переменные его экземпляра будут недоступны дочернему классу. !! 

```python
Class Person(object):
	def __ init__(self, name, ...):
		self.name = name
		...

Class Worker(Pesron):
	def __ init__(self, name, salary):
		self.salary = salary
		Person.__ init__(self, name) **ИЛИ** super().__init__(self, name)
		...
```

Функция super() позволяет из дочернего класса взаимодействовать с методами родительского класса без необходимости явно ссылаться на них. 

Особенно полезен, если методы родителя были перегружены в __ init__ дочери
###### Виды наследования:

>- Одиночное наследование: когда дочерний класс наследует только от одного родительского класса
>- Множественное наследование: когда дочерний класс наследует от нескольких родительских классов. При нем так же нужно писать super().__ init(...) для каждого родителя
>- Многоуровневое наследование: дочерние отношения с внуком. Он наследует от матери, она от своего родителя 
> 
>- Иерархическое наследование: у одного родителя больше 1 дочернего класса
>- Гибридное наследование: более одной формы наследования

##### [Полиморфизм](https://www.geeksforgeeks.org/polymorphism-in-python/)

Одно и то же имя функции (но разные сигнатуры), используемое для разных типов.

Примеры встроенного полиморфизма: функция len(). Работает со строками, массивами и др.

Аргументы функций по умолчанию тоже является полиморфизмом
###### Полиморфизм в классах
В классах можно итерировать по их объектам во кортеже, вызывая методы разных объектов, если они названы одинаково:


```python
Class Person():
	def say():
		print('fuck')
Class Politician():
	def say():
		print('Hello...')

a = Person()
b = Politician()
for human in (a,b):
	human.say()
```

###### Полиморфизм в наследовании
 При наследовании можно _переопределить_ методы родительского класса в дочернем, присвоив им имя родительского метода

```python
Class Bird():
	def say():
		print('CHIRP')
Class Sparrow('Bird'):
	def say():
		print('BOOO')
obj_bird = Bird()
obj_bird.say()

>> CHIRP

obj_sparrow = Sparrow()
obj_sparrow.say()

>> BOOO
```
###### Полиморфизм с функцией и объектами
Функция будет принимать любой объект и вызывать его методы, если такие определены в классе.
```python
def do(obj):
	obj.say()
	obj.walk()

Class Person():
	def say():
		print('fuck!')
	def walk():
		print('Шагаю нахуй')
		
Class Politician():
	def say():
		print('Hello...')
	def walk():
		print('Не шагаю, а летаю...')
		
a = Person()
b = Politician()

do(a)
>>> "fuck!" 
>>> "Шагаю нахуй"

do(b)
>>>"Hello..." 
>>>"Не шагаю, а летаю..."
```


##### [Инкапсуляция](https://www.geeksforgeeks.org/encapsulation-in-python/)

Упаковка данных и методы, которые работают с данными в рамках одного блока. Это накладывает ограничения на прямой доступ к переменным. (Частные переменные)

Сам класс является примером инкапсуляции, т.к. содержит свои переменные и методы.
###### Защищенные переменные

Переменные в классе можно защитить, добавив перед ней знак одинарного подчеркивания (Это часть соглашения, ни на что не влияет). 
По идее, к защищенным переменным _не нужно_ обращаться вне тела класса.  

###### Закрытые переменные

К закрытым переменным _не нужно_ обращаться ни вне его тела, ни в дочерних классах

##### [Абстракция](https://www.geeksforgeeks.org/abstract-classes-in-python/)

Все, что нужно для абстракции, есть в библиотеке ABC. **ABC** работает, оформляя методы базового класса как абстрактные, а затем регистрируя конкретные классы как реализации абстрактной базы.

**Абстрактный класс**

Позволяет создавать набор абстрактных методов для реализации у его дочерних классов. Используется, когда нужно создать общий интерфейс для различных реализаций. 
Абстрактный метод — метод, у которого есть объявление, но нет реализации. Оформляется декоратором @abstractmethod

```python
from abc import ABC, abstractmethod

class Polygon(ABC):

	@abstractmethod
	def noofsides(self):
		pass


class Triangle(Polygon):

	# overriding abstract method
	def noofsides(self):
		print("I have 3 sides")
		
class Pentagon(Polygon):

	# overriding abstract method
	def noofsides(self):
		print("I have 5 sides")

# Driver code
R = Triangle()
R.noofsides()
>>> I have 3 sides

R = Pentagon()
R.noofsides()
>>> I have 5 sides

```

> При множественном наследовании от ABC есть риск получить конфликт метакласов. Рекомендуется указывать это так:
> [Вот почему](https://docs.python.org/3/library/abc.html#abc.ABCMeta)

```python
class MyABC(metaclass=ABCMeta)
```
###### Реализация наследованием

Абстрактный класс можно реализовать наследованием, но тогда получится найти все реализации методов, запросив у родительского класса список его детей.

```python
import abc

class parent:	
	def geeks(self):
		pass

class child(parent):
	def geeks(self):
		print("child class")

print( issubclass(child, parent))
>>> True

print( isinstance(child(), parent))
>>> True
```

###### Конкретные методы в абстрактных классах

Ими можно пользоваться, вызывая super() в дочерних классах:

```python
import abc
from abc import ABC, abstractmethod

class R(ABC):
	def rk(self):
		print("Abstract Base Class")

class K(R):
	def rk(self):
		super().rk()
		print("subclass ")

# Driver code
r = K()
r.rk()
>>> Abstract Base Class
	subclass
```

> **Не получится создать объект абстрактного класса, так как он является неполным.**

##### [Переменные класса и объекта](https://pythonist.ru/peremennye-klassa-i-ekzemplyara-v-python/?ysclid=lnex7n8yob71939825)

###### Переменные класса

При создании класса явно указываются его переменные. К ним имеет доступ каждый экземпляр.

```python
Class Human():
	legs = 2
	arms = 2
matvey = Human()
print(matvey.legs, matvey.arms)
>>> 2,2
```

###### Переменные объекта

Индивидуальны и различны для каждого экземпляра, создаются при инициализации.

```python
Class Human():
	def __init__(self):
		self.voice = voice
		self.character = character

matvey = Human(voice="Soft",character="Cool")

print(matvey.voice,matvey.character)
>>> "Soft", "Cool"
```

Это все можно комбинировать:

```python
Class Human():
	penis = True
	legs = 3
	
	def __init__(self,voice,character):
		self.voice = voice
		self.character = character

matvey = Human(voice="Soft",character="Cool")

print(matvey.voice,matvey.character)
>>> "Soft", "Cool"

print(matvey.penis,matvey.legs)
>>> True, 3
```