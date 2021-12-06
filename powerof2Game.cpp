// Louise and Richard have developed a numbers game. 
// They pick a number (1 ≤ n < 264) and check to see if it is a power of 2. 
// If it is, they divide it by 2. 
// If not, they reduce it by the next lower number which is a power of 2. 
// Whoever reduces the number to 1 wins the game. Louise always starts.

// Given an initial value, determine who wins the game.

// As an example, let the initial value n = 132. 
// It's Louise's turn so she first determines that 132 is not a power of 2. 
// The next lower power of is 128, so she subtracts that from 132 and passes 4 to Richard. 
// 4 is a power of 2, so Richard divides it by 2 and passes 2 to Louise. 
// Likewise, 2 is a power so she divides it by 2 and reaches 1. 
// She wins the game.

// If they initially set counter to 1, Richard wins. 
// Louise cannot make a move so she loses.


#include<iostream>
using namespace std;
int main()
{
    int n = -4;
    int turn = 0;
    long current = 2;
    long previous = 2;
    if (n == 1) cout << "Louise";
    else if(n <= 0) cout << "Invalid Output";
    while (true) {
        if (current == n) 
        {
            n /= 2;
            if (n == 1) break;
            else 
            {
                turn ^= 1;
                current = 2;
                previous = 2;
            }
        } 
        else if (current < n) 
        {
            previous = current; // prev = 2,4,8,16 | 2, 4
            current *= 2; // curr = 4,8,16,32 | 4, 8
            continue;
        } 
        else 
        {
            n = n - previous;// 21 - 16 = 5 | 5 - 4 = 1
            if (n == 1) break;
            turn ^= 1; // t = 1
            current = 2; 
            previous = 2;
        }
    }

    if(turn == 1) cout << "Richard" << " " << turn; 
    else cout << "Louise" << " " << turn;
    return 0;
}