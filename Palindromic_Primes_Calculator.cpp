// Palindromic_Primes_Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>                                 // enables useful commands
using namespace std;                                // allows us to not have to use std:: for every command

/*
*Test values for palindromic primes and sums
* :7 is a palindrome and its sum of digits are odd (TRUE)
* :131 is a palindrome and its sum of digits are odd (TRUE)
* :919 is a palindrome (TRUE)
* :929 is a palindrome (TRUE)
* :15551 is a palindrome and its sum of digits are odd (TRUE)
* :95959 is a palindrome and its sum of digits are odd (TRUE)
*/
//Program should work for values up to 2147483647 since values are stored in ints

//The purpose of this function is to calculate the reverse of a number so that we are able to check if it is equal to the original number for palindromes
int palindromic_equation(int copy_user)
{
    int digit = 0, sum = 0, total = 0; //Declared 3 variables used within the function 

    do // Created a do while loop to iterate through each digit and reverse them
    {
        digit = copy_user % 10;
        sum = (sum * 10) + digit;
        copy_user = copy_user / 10;

    } while (copy_user != 0);

    return sum;
}

//The purpose of the function is to calculate the total of each digit in a value so we can check if its sum is odd or not
int total_equation(int copy_user)
{
    int digit, sum = 0, total = 0; //Declared 3 variables used within the function

    do // Created a do while that iterates through each value and adds each digit in a number to the total variable
    {
        digit = copy_user % 10;
        sum = (sum * 10) + digit;
        copy_user = copy_user / 10;

        total += digit;

    } while (copy_user != 0);

    return total;
}


//The purpose of this function is to get the users inputs and does minor error checking
int user_value()
{
    int user_input; //Declared a variable to get the users input
    cout << "Enter an integer greater than 1 you want to find the palindromic primes of: ";
    cin >> user_input;

    while (user_input <= 1) //Created a while loop to make sure the value is greater than 1, makes the user input a different value if it is not greater than 1
    {
        cout << "Please enter a valid number that is greater than 1 : ";
        cin >> user_input;
    }
    return user_input;
}

// Created a function that finds the prime values of number and declares whether they are palindromatic and if the sum of the numbers digits is odd.
void find_palindrom_primes()
{
    int user_input, digit, copy_user = 0, sum, total; //Declared the variables that are used within the function

    user_input = user_value(); //Calls the user_value function and stores its output value in the user_input variable


    for (int current = 2; current <= user_input; ++current) //Created nested for loops that iterate through multiple values and checks if it has any multiples to know whether it is prime or not
    {
        int inner = 2;
        for (; inner <= current - 1; inner++)
        {
            if (current % inner == 0) //Checks if the function is prime and if it is not it breaks 
                break;

        }

        if (inner == current) //Checks if a value is prime or not and prints the value if it is prime
        {
            cout << current << " ";

            sum = palindromic_equation(current); // Calls the palindromic_equation function and passes through the current value then stores it in the sum variable
            total = total_equation(current); // Calls the total_equation function and passes through the current value then stores it in the total variable

            if (current == sum) //Uses if statements to print whether a number that is primes, is also palindromic or the sum of the digits are odd
            {
                cout << ": is a palindrome ";
            }
            if (total % 2 != 0)
            {
                cout << ": sum of digits are odd ";
            }

            cout << "\n";
        }

    }
}


int main()
{
    find_palindrom_primes(); //executes the final function that outputs all the desired values 
}