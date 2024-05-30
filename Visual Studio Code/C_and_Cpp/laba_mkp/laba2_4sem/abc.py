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
    need_params = ["ecc", "i", "omega", "p", "radius", "THETAparam", "sigma"]
    data_labels = [label for label in data_collection.keys()]

    axis[0, 0].plot(data_collection[data_labels[0]], color="r", label=data_labels[0])
    axis[0, 1].plot(data_collection[data_labels[1]], color="r", label=data_labels[1])
    axis[0, 2].plot(data_collection[data_labels[2]], color="r", label=data_labels[2])
    axis[1, 0].plot(data_collection[data_labels[3]], color="r", label=data_labels[3])
    axis[1, 1].plot(data_collection[data_labels[4]], color="r", label=data_labels[4])
    axis[1, 2].plot(data_collection[data_labels[-1]], color="r", label="Omega")

    axis[0, 0].legend(loc="upper left")
    axis[0, 1].legend(loc="upper left")
    axis[0, 2].legend(loc="upper left")
    axis[1, 0].legend(loc="upper left")
    axis[1, 1].legend(loc="upper left")
    axis[1, 2].legend(loc="upper left")

    plt.show()

    H_apogee = 740 + 6371
    H_peregee = 350 + 6371

    semimajor_axis = (H_apogee + H_peregee) / 2.0
    ext_param = (H_apogee + H_peregee) / (H_apogee - H_peregee)
    focal_param = (H_apogee - H_peregee) / (2.0 * semimajor_axis)

    fig, axis = plt.subplots(nrows=2, ncols=3)
    Omega_data = np.ones(len(data_collection[data_labels[0]])) * (40.0 * np.pi) / 180.0 
    u_data = np.ones(len(data_collection[data_labels[0]])) * (70.0 * np.pi) / 180.0
    i_data = np.ones(len(data_collection[data_labels[0]])) * (37.1 * np.pi) / 180.0
    focal_data = np.ones(len(data_collection[data_labels[0]])) * focal_param
    ext_data = np.ones(len(data_collection[data_labels[0]])) * ext_param
    omega_data = np.ones(len(data_collection[data_labels[0]])) * 0

    axis[0, 0].plot(ext_data, color="g", label="ecc")
    axis[0, 1].plot(i_data, color="g", label="i")
    axis[0, 2].plot(omega_data, color="g", label="omega")
    axis[1, 0].plot(focal_data, color="g", label="focal")
    axis[1, 1].plot(data_collection[data_labels[4]], color="g", label="radius")
    axis[1, 2].plot(data_collection[data_labels[-1]], color="g", label="Omega")
    
    axis[0, 0].legend(loc="upper left")
    axis[0, 1].legend(loc="upper left")
    axis[0, 2].legend(loc="upper left")
    axis[1, 0].legend(loc="upper left")
    axis[1, 1].legend(loc="upper left")
    axis[1, 2].legend(loc="upper left")
    
    plt.show()
    

if __name__ == "__main__":

    data_collection = read_data(data_log_path="C:/projects/Visual Studio Code/C_and_Cpp/laba_mkp/laba2_4sem/files")
    show_data(data_collection=data_collection)