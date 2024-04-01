from random import randint, random
from tqdm import tqdm

TEST_CASES = 1024
BOUND = 2048

def initialise(values, n, *, left=0, right=-1):
    if left == right: return
    middle = left + (right-left)//2
    print(values[left:right], middle)
    values[middle] = n
    initialise(values, n-1, left=0, right=middle)
    initialise(values, n-1, left=middle+1, right=right)

if __name__ == "__main__":
    print(TEST_CASES)
    for i in (list(range(TEST_CASES))):
        n = (2 + 1)**2
        out = str(n)
        values = [""]*n
        initialise(values, n+1, right=n)
        print(values)
        break
