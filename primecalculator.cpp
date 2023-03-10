#include <iostream>
#include <cmath>
#include <ctime>

//Prime number calculator

/// @brief "Checks the given square root to see if it is a whole number"
/// @param squareRoot "The number that you wish to check"
/// @return "Returs true if the number is whole and false otherwise"
bool isSqrtWhole(float squareRoot) {
    int squareWhole = squareRoot;
    if(squareRoot - squareWhole == 0) {
        return true;
    }
    return false;
}

int main() {
    
    int primeAmount;

    //Check if the number is a number above 0
    while(true) {
    std::cout << "Up to which number would you like to calculate the prime numbers for?" << "\n";
    std::cin >> primeAmount;
    if(!(primeAmount <= 0)) {
        break;
    }
    std::cout << "Please enter a natural number above 0 \n";
    }
    
    clock_t timer;

    int counter = 0;
    
    timer = clock();
    //For each number from 1 to the primeAmount
    for(int i = 1; i <= primeAmount; i++) {
        bool isPrime = true;
        
        //Get the square root of i
        float squareRoot = sqrt(i);

        //Check if the squareroot is a whole number
        if(!isSqrtWhole(squareRoot)) {
            //Check if any number from 2 to squareRoot - 1 is a factor of i
            for(int j = 2; j < squareRoot; j++)
            {
                //If the remainder is 0, the number is a factor, and therefore, i cannot be prime
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) {
                std::cout << i << " is prime" << "\n";
                counter++;
            }
        }
    }

    //Calculate time taken
    timer = clock() - timer;

    std::cout << '\n';

    if(counter == 1) {
        std::cout << counter << " prime number, why...\n\n";
    }
    else {
        std::cout << counter << " prime numbers\n\n";
    }

    std::cout << "Total time taken: " << (float(timer) / CLOCKS_PER_SEC) << " seconds\n";

    std::cout << "Press Enter to Exit";
    while(true) {
        std::cin.ignore();
        if(std::cin.get() == '\n') {
            break;
        }
    }
    return 0;
}