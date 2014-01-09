import operator
def most_common(lst):
    return max(set(lst), key=lst.count)

if __name__ == "__main__":
    with open("cipher1.txt") as f:
        for line in f:
            numbers = [int(x) for x in line.split()]
        f.close()
    list1 = [numbers[i] for i in range(len(numbers)) if i % 3 == 0]
    list2 = [numbers[i] for i in range(len(numbers)) if i % 3 == 1]
    list3 = [numbers[i] for i in range(len(numbers)) if i % 3 == 2]
    dict1 = {x:list1.count(x) for x in list1}
    sorted_dict1 = sorted(dict1.items(), key=lambda x:x[1], reverse=True)
    dict2 = {x:list2.count(x) for x in list2}
    sorted_dict2 = sorted(dict2.items(), key=lambda x:x[1], reverse=True)
    dict3 = {x:list3.count(x) for x in list3}
    sorted_dict3 = sorted(dict3.items(), key=lambda x:x[1], reverse=True)

    #for i in range(len(numbers)):
    #    if i % 3 == 0:
    #        print (chr(i^103)),
    #    elif i % 3 == 1:
    #        print (chr(i^111)),
    #    else:
    #        print (chr(i^100)),
    list11 = [(x^103) for x in list1]
    list22 = [(x^111) for x in list2]
    list33 = [(x^100) for x in list3]
    print (sum(list11) + sum(list22) + sum(list33))
