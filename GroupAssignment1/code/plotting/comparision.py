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
    X,Y = X[1:], Y[1:]
    plt.plot(X,Y, label="exact", marker=".", markersize=msize)

    X = np.array(X)
    print(np.array(Y) / (X*np.log2(X)))
    c = np.mean(np.array(Y) / (X**2), axis=0)
    plt.plot(X,c*X*(X), label=f"asymptotic (for c={c})", marker=".", markersize=msize)

    plt.xlabel("The input size")
    plt.ylabel("the number of comparisions")
    plt.legend()
    plt.title(plot_title)
    plt.show()
