from random import randint, random
from tqdm import tqdm

TEST_CASES = 120
BOUND = 2048
N = 0
X = 100

def initialise(values, *, left=0, right=-1):
    global N
    if left == right: return
    middle = left + (right-left)//2
    values[middle] = f"{N}+{N}i"
    N = N - 1
    initialise(values, left=left, right=middle)
    initialise(values, left=middle+1, right=right)

if __name__ == "__main__":
    print(TEST_CASES)
    for i in tqdm(list(range(TEST_CASES))):
        N = (i + 1)**2
        out = str(N)
        values = [""]*N
        initialise(values, right=N)
        out += " " +" ".join(values)
        print(out)
