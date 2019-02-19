# Company: Facebook
# Question: Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
# Example:

# Solution: Reservoir Sampling

import random

def pick(big_stream):
    random_element = None
    for i, e in enumerate(big_stream):
        if i == 0:
            random_element = e
        elif random.randint(1, i + 1) == 1:
            random_element = e
    return random_element

if __name__ == "__main__":
    pass
