import numpy as np

def is_arithmetic_sequence(lst):
    """
    return whether the lst is arithmetic sequence
    """
    common_diff = np.diff(lst)
    return all_same(common_diff)

def all_same(lst):
    """
    return whether all items in the list is the same
    """
    return len(set(lst)) == 1

def degree_poker(hand):
    """
    return the degree of the hand card
    0 - High Card
    1 - One pair
    2 - Two pair
    3 - Three of a kind
    4 - Straight
    5 - Flush
    6 - Full House
    7 - Four of a kind
    8 - Straight Flush
    9 - Royal Flush
    """
    numbers = [hand[i][0] for i in range(5)]

    # replace chars with numbers
    for i in range(5):
        if numbers[i] == 'J':
            numbers[i] = '11'
        elif numbers[i] == 'Q':
            numbers[i] = '12'
        elif numbers[i] == 'K':
            numbers[i] = '13'
        elif numbers[i] == 'A':
            numbers[i] = '14'
    numbers = [int(x) for x in numbers]
    sorted(numbers)
    colors = [hand[i][1] for i in range(5)]

    if numbers == [10, 11, 12, 13, 14] and all_same(colors):
        return 9
    elif is_arithmetic_sequence(numbers) and all_same(colors):
        return 8
    elif all_same(numbers[0:4]) or all_same(numbers[1:]):
        return 7
    elif (all_same(numbers[0:2]) and all_same(numbers[2:])) or (all_same(numbers[0:3]) and all_same(numbers[3:])):
        return 6
    elif all_same(colors):
        return 5
    elif is_arithmetic_sequence(numbers):
        return 4
    elif all_same(numbers[0:3]) or all_same(numbers[1:4]) or all_same(numbers[2:]):
        return 3
    elif (numbers[1]==numbers[2] and numbers[3]==numbers[4]) or \
         (numbers[0]==numbers[1] and numbers[3]==numbers[4]) or \
         (numbers[0]==numbers[1] and numbers[2]==numbers[3]):
        return 2
    elif numbers[0]==numbers[1] or numbers[1]==numbers[2] or \
         numbers[2]==numbers[3] or numbers[3]==numbers[4]:
        return 1
    else:
        return 0

if __name__ == "__main__":
    h = ['2H', '2D', '4C', '4D', '4S']
    print degree_poker(h)
