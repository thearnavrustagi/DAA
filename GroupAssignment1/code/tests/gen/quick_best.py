from random import randint, random

from tqdm import tqdm

TEST_CASES = 120
BOUND = 2048
N = 0
X = 100


def initialise(arr, best):
    if len(arr) == 0:
        return
    middle = len(arr) // 2
    best.append(arr[middle])
    initialise(arr[:middle], best)
    initialise(arr[middle + 1 :], best)


if __name__ == "__main__":
    print(TEST_CASES)
    for i in tqdm(list(range(TEST_CASES))):
        N = (i + 1) ** 2
        out = str(N)
        best = []
        values = []
        for i in range(N):
            values.append(f"{i}+{i}i")
        initialise(values, best)
        out += " " + " ".join(best)
        print(out)
