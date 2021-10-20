import pandas as pd
import matplotlib.pyplot as plt

dir_data_input = "./data1/"
for i in range(150):
    plt.clf()
    plt.title('high density & high noise')
    plt.axis([-0.2, 7.2, -0.2, 7.2])
    data = pd.read_csv(dir_data_input + "%05d.csv" % i, header=None)
    data = data.rename(columns = {0:"x", 1:"y", 2:"v_x", 3:"v_y"})
    plt.quiver(data["x"], data["y"], data["v_x"], data["v_y"])
    plt.pause(0.05)

dir_data_input = "./data2/"
for i in range(80):
    plt.clf()
    plt.title('small density & small noise')
    plt.axis([-0.5, 25.5, -0.5, 25.5])
    data = pd.read_csv(dir_data_input + "%05d.csv" % i, header=None)
    data = data.rename(columns = {0:"x", 1:"y", 2:"v_x", 3:"v_y"})
    plt.quiver(data["x"], data["y"], data["v_x"], data["v_y"])
    plt.pause(0.05)

dir_data_input = "./data3/"
for i in range(60):
    plt.clf()
    plt.title('high density & small noise')
    plt.axis([-0.2, 5.2, -0.2, 5.2])
    data = pd.read_csv(dir_data_input + "%05d.csv" % i, header=None)
    data = data.rename(columns = {0:"x", 1:"y", 2:"v_x", 3:"v_y"})
    plt.quiver(data["x"], data["y"], data["v_x"], data["v_y"])
    plt.pause(0.05)

dir_data_input = "./data4/"
for i in range(80):
    plt.clf()
    plt.title('migration')
    plt.axis([-0.2, 5.2, -0.2, 5.2])
    data = pd.read_csv(dir_data_input + "%05d.csv" % i, header=None)
    data = data.rename(columns = {0:"x", 1:"y", 2:"v_x", 3:"v_y"})
    plt.quiver(data["x"], data["y"], data["v_x"], data["v_y"])
    plt.pause(0.05)

dir_data_input = "./data5/"
for i in range(60):
    plt.clf()
    plt.title('clustering')
    plt.axis([-0.2, 5.2, -0.2, 5.2])
    data = pd.read_csv(dir_data_input + "%05d.csv" % i, header=None)
    data = data.rename(columns = {0:"x", 1:"y", 2:"v_x", 3:"v_y"})
    plt.quiver(data["x"], data["y"], data["v_x"], data["v_y"])
    plt.pause(0.05)