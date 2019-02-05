# Company: Google
# Question: The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
# Example:

# Solution: Use uniform distribution to check amount of number inside a (0,1)(0,1) square and how many inside the inscribed circle
# Formula for pi is : (pi * r^2) / S_square = count/NUM_OF_POINTS
# => pi = 1 / (0.5^2 * NUM_OF_POINTS)
import random

def estimatePi():
    def pointInCircle(x, y):
        return ((x - 0.5) ** 2 + (y - 0.5) ** 2) ** 0.5 < 0.5

    NUM_OF_POINTS = 10000
    count = 0
    for i in range(NUM_OF_POINTS):
        x = random.uniform(0, 1)
        y = random.uniform(0, 1)
        count += pointInCircle(x, y)
    return round(count / (0.5**2 * NUM_OF_POINTS), 3)

if __name__ == "__main__":
    print('Pi is ' + str(estimatePi()))
    pass
