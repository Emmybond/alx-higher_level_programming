#!/usr/bin/python3
# 12-fizzbuzz.py


def fizzbuzz():
    """Prints the numbers from 1 to 100 separated by a space.

    For multiples of three, It prints Fizz instead of the number.
    For multiples of five, It prints Buzz instead of the number.
    For multiples of three and five, It prints FizzBuzz instead of the number.
    """
    for number in range(1, 101):
        if number % 3 == 0 and number % 5 == 0:
            print("FizzBuzz ", end="")
        elif number % 3 == 0:
            print("Fizz ", end="")
        elif number % 5 == 0:
            print("Buzz ", end="")
        else:
            print("{} ".format(number), end="")


