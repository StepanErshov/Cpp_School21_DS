import numpy as np
import matplotlib.pyplot as plt
import os

def read_data(data_log_path):

    data_collection = {}
    for log_file in os.listdir(data_log_path):

        curent_file = os.path.join(data_log_path, log_file)
        with open(curent_file, "r") as c_file:

            data = c_file.read()
            tmp_list = [float(value) for value in data.split()]
            data_collection[log_file[:-4]] = tmp_list

    return data_collection

def show_data(data_collection):

    plt.style.use("seaborn")
    fig, axis = plt.subplots(nrows=2, ncols=3)
    need_params = ["ecc", "i", "sigma", "p", "radius", "THETAparam", "omega"]
    data_labels = [label for label in data_collection.keys()]
    
    #возмущённое
    
    axis[0, 0].plot(data_collection[need_params[0]], color="orange", label=need_params[0])
    axis[0, 0].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 0].set_ylabel('Экцентриситет (e)')
    axis[0, 1].plot(data_collection[need_params[1]], color="orange", label=need_params[1])
    axis[0, 1].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 1].set_ylabel('Наклонение (I), рад')  
    axis[0, 2].plot(data_collection[need_params[2]], color="orange", label="omega")
    axis[0, 2].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 2].set_ylabel('Аргумент перицентра (omega), рад')  
    axis[1, 0].plot(data_collection[need_params[3]], color="orange", label=need_params[3])
    axis[1, 0].set_xlabel('Аргумент широты (U), рад')
    axis[1, 0].set_ylabel('Фокальный параметр (Р), км')  
    axis[1, 1].plot(data_collection[need_params[-1]], color="orange", label="Omega")
    axis[1, 1].set_xlabel('Аргумент широты (U), рад')  
    axis[1, 1].set_ylabel('Долгота восходящего узла (Omega), рад')  

    axis[0, 0].legend(loc="upper left")
    axis[0, 1].legend(loc="upper left")
    axis[0, 2].legend(loc="upper left")
    axis[1, 0].legend(loc="upper left")
    axis[1, 1].legend(loc="upper left")

    plt.show()

    #скорости

    figh, axis = plt.subplots(ncols=3)
    axis[0].plot(data_collection["S"], color = 'black', label="S")
    axis[0].set_xlabel('Аргумент широты (U), рад')  
    axis[0].set_ylabel('Радиальная составляющая возмущающего ускорения (S) * 10^-5, км/с')
    axis[1].plot(data_collection["T"], color = 'black', label="T")
    axis[1].set_xlabel('Аргумент широты (U), рад') 
    axis[1].set_ylabel('Трансверсальная составляющая возмущающего ускорения (T) * 10^-5, км/с') 
    axis[2].plot(data_collection["W"], color = 'black', label="W")
    axis[2].set_xlabel('Аргумент широты (U), рад')
    axis[2].set_ylabel('Нормальная составляющая возмущающего ускорения (W) * 10^-5, км/с')  
    axis[0].legend(loc="upper left")
    axis[1].legend(loc="upper left")
    axis[2].legend(loc="upper left")

    H_apogee = 675 + 6371
    H_peregee = 675 + 6371

    semimajor_axis = (H_apogee + H_peregee) / 2.0
    ext_param = (H_apogee - H_peregee) / (H_apogee + H_peregee)
    focal_param = semimajor_axis * (1.0 - (ext_param**2.0))

    fig, axis = plt.subplots(nrows=2, ncols=3)
    Omega_data = np.ones(len(data_collection["omega"])) * (60.0 * np.pi) / 180.0 
    u_data = np.ones(len(data_collection[data_labels[0]])) * (50.0 * np.pi) / 180.0
    i_data = np.ones(len(data_collection[data_labels[0]])) * (77.6 * np.pi) / 180.0
    focal_data = np.ones(len(data_collection[data_labels[0]])) * focal_param
    ext_data = np.zeros(len(data_collection[data_labels[0]])) * ext_param
    omega_data = np.ones(len(data_collection["sigma"])) * data_collection["sigma"][0]

    #не возмущённое

    axis[0, 0].plot(ext_data, color="g", label=need_params[0])
    axis[0, 0].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 0].set_ylabel('Экцентриситет (e)')
    axis[0, 1].plot(i_data, color="g", label=need_params[1])
    axis[0, 1].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 1].set_ylabel('Наклонение (I), рад')
    axis[0, 2].plot(omega_data, color="g", label=need_params[2])
    axis[0, 2].set_xlabel('Аргумент широты (U), рад')  
    axis[0, 2].set_ylabel('Аргумент перицентра (omega), рад') 
    axis[1, 0].plot(focal_data, color="g", label=need_params[3])
    axis[1, 0].set_xlabel('Аргумент широты (U), рад')
    axis[1, 0].set_ylabel('Фокальный параметр (Р), км') 
    axis[1, 1].plot(Omega_data, color="g", label="Omega")
    axis[1, 1].set_xlabel('Аргумент широты (U), рад')  
    axis[1, 1].set_ylabel('Долгота восходящего узла (Omega), рад') 
    
    axis[0, 0].legend(loc="upper left")
    axis[0, 1].legend(loc="upper left")
    axis[0, 2].legend(loc="upper left")
    axis[1, 0].legend(loc="upper left")
    axis[1, 1].legend(loc="upper left")
    
    plt.show()

    fig, axis = plt.subplots(subplot_kw={'projection': 'polar'}, ncols=2)
    axis[0].plot(data_collection["THETAparams"], data_collection["radius"], color="b")
    axis[1].plot(data_collection["THETAparams"], data_collection["radius"], color="orange")
    plt.show()

if __name__ == "__main__":

    data_collection = read_data(data_log_path="C:/projects/Visual Studio Code/C_and_Cpp/laba_mkp/laba2_4sem/files")
    show_data(data_collection=data_collection)