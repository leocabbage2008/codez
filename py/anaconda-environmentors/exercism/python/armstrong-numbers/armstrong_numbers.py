def is_armstrong_number(number):
    n = len(str(number))
    t = number
    sum = 0
    while(number > 0):
        number = int(number)
        sum += (number % 10)**n
        number /= 10
    print(sum)
    return sum == t
