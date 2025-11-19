/*
 * cash.c
 * CS50x – Week 1: Greedy Algorithms
 *
 * Overview:
 *   This program calculates the minimum number of coins needed to make
 *   a given amount of change in U.S. currency. It is part of the Week 1
 *   problem set and introduces:
 *
 *   - Greedy algorithms
 *   - Integer arithmetic
 *   - Loops and repeated subtraction
 *   - Input validation
 *   - Basic problem decomposition
 *
 * What this program demonstrates:
 *   • How a greedy algorithm works: always use the largest possible coin first.
 *   • Handling floating-point input safely by converting dollars → cents.
 *   • Using division and modulo to compute coin counts.
 *   • Validating user input and reprompting if necessary.
 *
 * Why it matters:
 *   This is the first CS50 problem where algorithmic strategy matters.
 *   You must think step-by-step:
 *     - What is the largest coin I can use?
 *     - How many of them fit into this amount?
 *     - What remains afterward?
 *
 *   It reinforces the idea that efficient problem solving requires:
 *     • simplifying a real-world task into strict operations
 *     • eliminating error-prone floating-point calculations
 *     • testing edge cases (0.01, 0.41, 1.00, 4.20, etc.)
 *
 * Usage:
 *   Compile:
 *       clang cash.c -o cash
 *
 *   Run:
 *       ./cash
 *
 *   The program will prompt:
 *       Change owed:
 *
 * Expected Behavior:
 *   Input: 0.41
 *   Output (as coin count):
 *       4
 *   Explanation: 25¢ + 10¢ + 5¢ + 1¢ = 41¢ → 4 coins
 */
