import numpy as np

def rectNumberIn(a, b):
    return sum([x*y for x in range(1,a+1) for y in range(1, b+1)])

if __name__ == "__main__":
    error = 10000
    error_a = 0
    error_b = 0
    for a in range(1, 5000):
        for b in range(1, 5000):
            signed_cur_error = rectNumberIn(a, b) - 2000000
            cur_error = abs(signed_cur_error)

            # we have found the error is 10000 solution, so 
            # if the cur_error is positive and > 10000, there is
            # no need to add b, since adding b only increase errors
            if signed_cur_error > 10000: 
                break
            if cur_error < error:
                error = cur_error
                error_a = a
                error_b = b

    print "error:", error
    print "error_a:", error_a
    print "error_b:", error_b
    print "area:", error_a * error_b
