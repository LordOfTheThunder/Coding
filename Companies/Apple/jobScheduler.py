# Company: Apple
# Question: Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
# Example:

# Solution:
import time

def f():
    print("Potato")

def jobScheduler(f, n):
    time.sleep(n * 0.01)
    eval('f()')
    pass


if __name__ == "__main__":
    jobScheduler(f, 100)
    pass
