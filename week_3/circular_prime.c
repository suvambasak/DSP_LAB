#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to get number of digit.
int numberofdigits(int num)
{
    int counter = 0;
    while ((++counter) && (num /= 10))
        ;
    return counter;
}

// Function to check prime.
int isprime(int num)
{
    int i;
    for (i = 2; i <= (num / 2); i++)
        if ((num % i) == 0)
            return 0;
    return 1;
}

// Function for number rotation.
int rotate(int num)
{
    return ((num % 10) * pow(10, numberofdigits(num) - 1) + (num / 10));
}

// Function for rotate and check each number is prime or not.
int circular_parmut(int num)
{
    // Invalid input.
    if (num <= 0)
        return -1;
    if (num == 1)
        return 0;

    int number_of_digits = numberofdigits(num);
    int i;

    // Checking each rotation.
    for (i = 1; i <= number_of_digits; i++)
    {
        if (isprime(num))
        {
            num = rotate(num);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

// Main function.
int main()
{
    int number;

    printf("\nENTER A NUMBER : ");
    scanf("%d", &number);

    printf("%d", circular_parmut(number));

    return 0;
}

/*

A number is circular prime if the number and all its cyclic permutations are prime.

For example:

The number 3779 is circular prime because all the cyclic permutations

3779, 9377, 7937, 7793 are prime numbers.

Where as the number 3877 is not circular prime because one of its cyclic permutation 7738 is not a prime number.

Input/Output Specification:

 - Any input <= 0 to be treated as invalid input. Any input > 0 to be treated as valid input

 - If the number <= 0, your program should print -1

 - If the number is circular prime, your program should print 1

 - If the number is not circular prime, your program should print 0

Sample Input/Output:

Input:

 -100

 Output:

 -1

Input:

 0

 Output:

 -1

Input:

 3779

 Output:

 1

 Input:

 3877

 Output:

 0

 */