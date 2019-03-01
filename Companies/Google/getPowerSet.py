from math import pow
# Company: Google
# Question: The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
# Example:
"""
For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
"""
# Solution: Recursive solution - trivial. For loop solution: for iteration i in size of power_set take only items in i's positions of set

# Recursive solution
def getPowerSet(set):
    scope = {"power_set" : [[]]}
    def getPowerSetAux(set, idx):
        if not set:
            return
        if idx >= len(set):
            if set in scope["power_set"]:
                return
            scope["power_set"].append(set.copy())
            return
        # First case: advance idx
        getPowerSetAux(set.copy(), idx + 1)
        # Second case: Remove item in idx
        del set[idx]
        getPowerSetAux(set.copy(), 0)

    getPowerSetAux(set, 0)
    return scope["power_set"]

def getPowerSetV2(set):
    power_set = []
    power_set_size = int(pow(2, len(set)))
    for counter in range(power_set_size):
        inner_set = []
        for j in range(power_set_size):
            if counter & (1 << j) > 0:
                inner_set.append(set[j])
        power_set.append(inner_set)

    return power_set

if __name__ == "__main__":
    print(getPowerSet([1, 2, 3]))
    print(getPowerSetV2([1, 2, 3]))