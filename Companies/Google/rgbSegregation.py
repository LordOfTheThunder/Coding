# Company: Google
# Question: Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
# Example:
"""
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
"""
# Solution: Swap R's to their correct place. Then swap G's to their correct place. This only takes at most 2 passes over array so time and space are linear

def rgbSegregation(arr):
    def swap(arr, first, second):
        tmp = arr[first]
        arr[first] = arr[second]
        arr[second] = tmp

    first = 0
    while first < len(arr) and arr[first] is 'R':
        first = first + 1
    second = first + 1
    # Put 'R' in place
    while second < len(arr):
        if arr[second] is 'R':
            swap(arr, first, second)
            first += 1
        second += 1

    second = first + 1
    # Put 'G' in place
    while second < len(arr):
        if arr[second] is 'G':
            swap(arr, first, second)
            first += 1
        second += 1

    return arr


if __name__ == "__main__":
    assert (rgbSegregation(['G', 'B', 'R', 'R', 'B', 'R', 'G']) == ['R', 'R', 'R', 'G', 'G', 'B', 'B'])
    assert (rgbSegregation(['B', 'G', 'R']) == ['R', 'G', 'B'])