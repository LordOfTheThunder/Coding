# Company: Jane Street
# Question: cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
# Example: For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

# Solution: f(a,b) = [a, b]

def cons(a, b):
        def pair(f):
            return f(a, b)
        return pair


def car(p):
    def f(a, b):
        return [a, b]
    return p(f)[0]


def cdr(p):
    def f(a, b):
        return [a, b]
    return p(f)[1]


if __name__ == "__main__":
    print(car(cons(3, 4)))
    print(cdr(cons(3, 4)))
    pass
