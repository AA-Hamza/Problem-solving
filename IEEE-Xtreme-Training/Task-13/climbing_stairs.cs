/*
 *  Problem Link https://leetcode.com/problems/climbing-stairs/submissions/
 */
using System;

public class Solution {
    static public int Permutations(int n, int r) {
        long result = 1;
        long change = 1;
        for (int i = 0; i < r; ++i) {
            result *= n;
            if (result % (i+1) == 0) {
                result /= (i+1);
            }
            else {
                change *= (i+1);
            }
            if (change > 0 && result % (change) == 0) {
                result /= change;
                change = 0;
            }
            n--;
        }
        return (int) result;
    }
    static public int ClimbStairs(int n) {
        int ways = 0;
        int ones = n;
        int twos;
        for (twos = 0; twos <= n/2; twos++) {
            //Console.WriteLine("Arranging {1} in space of {0}", ones+twos, twos);
            ways += Permutations(ones+twos, twos);
            ones -=2 ;
        }
        return ways;
    }
    static void Main(string[] args) {
        Console.WriteLine(ClimbStairs(44));
    }
}
