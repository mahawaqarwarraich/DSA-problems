#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// This is the given random function that gives number between 20 to 50
int rand20to50() {
    return rand() % 31 + 20; // 31 values: 20 to 50
    // rand() // range 0-rand max
    // rand() % 31 [0-30]
    // rand() % 31 + 20 -> add 20 in the above range -> 0+20 and 30+20 -> [20, 50]
}

// Now we create our rand10to70 function using scale approach
int rand10to70() {
    while (true) {
        int a = rand20to50() - 20; // range: 0 to 30, total 31
        int b = rand20to50() - 20; // range: 0 to 30

        int index = a * 31 + b;    // a(31) * b(31) = 961 values, *31 (unique values)

//         961 ÷ 61 = 15.75 → Not a whole number!
// This means:

// Some numbers would appear 16 times

// Others would appear 15 times

//We are mapping random values from a large range (0 to 960) to a smaller, fair range (10 to 70), which has 61 numbers.

//How many times can we fully fit 61 numbers into the range 0–960?

// 961/61 = 15.75

//15 full groups × 61 numbers = 915(fair)



        // we want 10-70, 61 values, 
        if (index < 915) {     // Keep only first 976 numbers (good for even distribution)
            return 10 + (index % 61); // If you just did this without condition Then some numbers would repeat more than others. That would be unfair.
        }
    }
}

// Test it
int main() {
    srand(time(0)); // Seed random generator with current time

    // Generate and print 10 random numbers from rand10to70
    for (int i = 0; i < 10; i++) {
        cout << rand10to70() << " ";
    }

    return 0;
}
