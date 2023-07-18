#include <bits/stdc++.h>
using namespace std;

/*
 * Naive Approach:
 *
 * We can traverse over all the numbers from min(A, B) to 1
 * and check if the current number divides both A and B or not. If it does, then it will be the GCD of A and B.
 */

int GCD1(int A, int B) // Time complexity of this function is O(min(A, B))
{
    int m = min(A, B), gcd;
    for (int i = m; i > 0; --i)
        if (A % i == 0 && B % i == 0)
        {
            gcd = i;
            return gcd;
        }
    return -1;
}

/*
 * Euclid’s Algorithm:
 *
 * Idea behind Euclid’s Algorithm is GCD(A, B) = GCD(B, A % B). The algorithm will recurse until A % B = 0.
 */

int GCD(int A, int B) // The time complexity of Euclid’s Algorithm is O(log(max(A, B)))
{
    if (B == 0)
        return A;
    else
        return GCD(B, A % B);
}

int main()
{
    // some important built-in functions for GCD in algorithm header

    cout << gcd(45, 10) << endl;   // this one is the better and used more it was introduced in C++17 compilers
    cout << __gcd(45, 10) << endl; // this one in C

    return 0;
}