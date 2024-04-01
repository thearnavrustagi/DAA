import matplotlib.pyplot as plt
import numpy as np

if __name__ == "__main__":
    X,Y = [], []
    plot_title = input("enter plot title: ")
    for _ in range(int(input("number of test cases: "))):
        (x,y) = tuple(input(">").split())
        x,y = int(x), int(y)
        X.append(x)
        Y.append(y)
    plt.plot(X,Y, label="average case", marker=".", markersize=12)

    X,Y = [], []
    for _ in range(int(input("number of test cases: "))):
        (x,y) = tuple(input(">").split())
        x,y = int(x), int(y)
        X.append(x)
        Y.append(y)
    plt.plot(X,Y, label="best case", marker=".", markersize=12)

    X,Y = [], []
    for _ in range(int(input("number of test cases: "))):
        (x,y) = tuple(input(">").split())
        x,y = int(x), int(y)
        X.append(x)
        Y.append(y)
    plt.plot(X,Y, label="worst case", marker=".", markersize=12)


    plt.xlabel("The input size")
    plt.ylabel("the number of comparisions")
    plt.legend()
    plt.title(plot_title)
    plt.show()
