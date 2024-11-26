import time
from threading import Thread

class BreathSensor:
    def __init__(self):
        self.oxygen_level = 95  # Начальный уровень кислорода в крови
        self.co2_level = 40     # Начальный уровень углекислого газа в крови
    
    def measure(self):
        # Симулируем измерения
        self.oxygen_level += 0.1 if self.oxygen_level < 100 else 0
        self.co2_level -= 0.05 if self.co2_level > 35 else 0
        return self.oxygen_level, self.co2_level

class BreathController:
    def __init__(self):
        self.target_oxygen = 98
        self.target_co2 = 40
        self.breath_rate = 12  # Частота дыхания в вдохах/выдохах в минуту
    
    def regulate(self, oxygen, co2):
        if oxygen < self.target_oxygen:
            self.breath_rate += 0.5
        elif oxygen > self.target_oxygen:
            self.breath_rate -= 0.5
        
        if co2 < self.target_co2:
            self.breath_rate += 0.5
        elif co2 > self.target_co2:
            self.breath_rate -= 0.5
        
        return max(8, min(self.breath_rate, 20))  # Ограничиваем частоту от 8 до 20 вдохов/выдохов в минуту

class BreathActuator:
    def __init__(self):
        self.is_inhaling = False
    
    def breathe(self, breath_rate):
        inhale_time = 60 / (breath_rate * 2)  # Время вдоха в секундах
        
        if self.is_inhaling:
            print("Выдыхаю...")
            time.sleep(inhale_time)
        else:
            print("Вдыхаю...")
            time.sleep(inhale_time)
        
        self.is_inhaling = not self.is_inhaling

def main():
    sensor = BreathSensor()
    controller = BreathController()
    actuator = BreathActuator()

    while True:
        oxygen, co2 = sensor.measure()
        breath_rate = controller.regulate(oxygen, co2)
        actuator.breathe(breath_rate)

        print(f"Уровень кислорода: {oxygen:.2f}%, Уровень CO2: {co2:.2f}%, Частота дыхания: {breath_rate:.2f} вдохов/выдохов в минуту")
        time.sleep(1)  # Измеряем каждую секунду

if __name__ == "__main__":
    main_thread = Thread(target=main)
    main_thread.start()