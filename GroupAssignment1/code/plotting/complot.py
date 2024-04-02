import matplotlib.pyplot as plt
import numpy as np

msize = 8

if __name__ == "__main__":
    X,Y = [], []
    plot_title = input("enter plot title: ")
    for _ in range(int(input("number of test cases: "))):
        (x,y) = tuple(input(">").split())
        x,y = int(x), int(y)
        X.append(x)
        Y.append(y)
    plt.plot(X,Y, label="Quick Sort", marker=".", markersize=msize)

    X,Y = [], []
    for _ in range(int(input("number of test cases: "))):
        (x,y) = tuple(input(">").split())
        x,y = int(x), int(y)
        X.append(x)
        Y.append(y)
    plt.plot(X,Y, label="Heap Sort", marker=".", markersize=msize)

    X = np.array(X)
    plt.xlabel("The input size")
    plt.ylabel("the number of comparisions")
    plt.legend()
    plt.title(plot_title)
    plt.show()
