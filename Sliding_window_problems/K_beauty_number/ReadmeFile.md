# Find the K-Beauty of a Number

**Source:** LeetCode Problem #2269
**Difficulty:** Easy

## Topics

* Math
* String
* Sliding Window
* Simulation

---

# 📌 Problem Summary

You are given:

* A positive integer `num`
* An integer `k`

A number contributes to the answer if:

1. It is formed by taking a substring of length `k` from the decimal representation of `num`.
2. The value of that substring is not `0`.
3. `num` is divisible by that value.

Your task is to count how many such valid substrings exist.

---

# 📝 Sample Scenario

Consider:

```cpp
num = 240
k = 2
```

Convert number into string:

```text
"240"
```

Possible substrings of length 2:

```text
24
40
```

Check:

```text
240 % 24 = 0 ✅
240 % 40 = 0 ✅
```

Answer:

```cpp
2
```

---

# 🎯 What Should We Notice First?

Most beginners see:

```text
Number
Division
Modulo
```

and immediately think:

❌ Number Theory

❌ Prime Factors

❌ GCD

❌ Dynamic Programming

But let's slow down.

The problem repeatedly mentions:

```text
Substring
Length k
Consecutive Digits
```

This is the biggest clue.

Whenever you see:

```text
Fixed Length Substring
```

you should immediately think:

✅ Sliding Window

---

# 🧠 Beginner Thinking Process

Suppose:

```cpp
num = 430043
k = 2
```

Convert it into:

```text
"430043"
```

Possible substrings:

```text
43
30
00
04
43
```

Question:

```text
How do we examine every substring of length k?
```

Many beginners try:

```text
Nested Loops
Generate Everything
```

But notice:

```text
Length of every substring is fixed.
```

Fixed-size substring problems often become:

```text
Sliding Window Problems
```

---

# 🔍 Pattern Recognition

Whenever you see:

### Fixed Length Substring

Examples:

```text
Length 2
Length 3
Length k
```

Think:

```text
Sliding Window
```

---

### Character/Digit Processing

Examples:

```text
Digits
Letters
Substring Extraction
```

Think:

```text
String Traversal
```

---

### Divisibility Check

Examples:

```text
a % b == 0
```

Think:

```text
Math + Simulation
```

---

For this problem:

```text
Fixed Length Window      ✅
Substring Processing     ✅
Divisibility Check       ✅

Prefix Sum              ❌
Two Pointers            ❌
Binary Search           ❌
Dynamic Programming     ❌
```

---

# 🤔 Why Sliding Window?

Let's examine:

```cpp
num = 430043
k = 2
```

String form:

```text
430043
```

Window 1:

```text
43
```

Window 2:

```text
30
```

Window 3:

```text
00
```

Window 4:

```text
04
```

Window 5:

```text
43
```

Notice:

```text
Every valid candidate
is simply a window of size k.
```

Therefore:

```text
Sliding Window is the natural pattern.
```

---

# ❌ Why Not Prefix Sum?

Prefix Sum is useful when:

```text
Range Sums
Running Totals
Cumulative Information
```

Examples:

```text
Pivot Index
Subarray Sum
Running Sum
```

This problem never asks for sums.

Therefore:

```text
Prefix Sum ❌
```

---

# ❌ Why Not Two Pointers?

Two Pointers are usually useful when:

```text
Window Size Changes
Pairs
Triplets
Sorted Arrays
```

Examples:

```text
Two Sum II
Container With Most Water
```

This problem uses:

```text
Fixed Size Window
```

Therefore:

```text
Two Pointers ❌
```

---

# 💡 Core Observation

After converting:

```cpp
num = 430043
```

into:

```text
"430043"
```

every valid candidate is simply:

```text
A substring of length k
```

For each substring:

Step 1:

Convert it to an integer.

Example:

```text
"43"
```

becomes:

```cpp
43
```

Step 2:

Ignore:

```cpp
0
```

because division by zero is impossible.

Step 3:

Check:

```cpp
num % value == 0
```

If true:

```text
Count++
```

---

# 🐢 Approach 1: Brute Force

## Idea

Generate every substring of length `k`.

For each substring:

1. Convert to integer.
2. Ignore zero.
3. Check divisibility.

Increase answer if valid.

---

## Dry Run

```cpp
num = 240
k = 2
```

String:

```text
240
```

Substring:

```text
24
```

Check:

```cpp
240 % 24 == 0
```

Valid ✅

Count:

```cpp
1
```

---

Substring:

```text
40
```

Check:

```cpp
240 % 40 == 0
```

Valid ✅

Count:

```cpp
2
```

Final Answer:

```cpp
2
```

---

# 🚀 Optimal Approach

## Observation

The brute-force solution is already efficient.

Why?

Maximum length of `num` is small.

For every position:

```cpp
substring(i, k)
```

takes constant work.

Therefore:

```text
Simply sliding across the string
is enough.
```

---

## Optimal Code

```cpp
class Solution {
public:

    int divisorSubstrings(int num, int k) {

        string s = to_string(num);

        int count = 0;

        for(int i = 0; i <= s.size() - k; i++) {

            int value =
                stoi(s.substr(i, k));

            if(value != 0 &&
               num % value == 0)
            {
                count++;
            }
        }

        return count;
    }
};
```

---

# ⚡ Complexity Analysis

Let:

```cpp
n = number of digits
```

### Time Complexity

```cpp
O(n * k)
```

Because:

```cpp
substr()
stoi()
```

process at most `k` digits.

---

### Space Complexity

```cpp
O(k)
```

for the temporary substring.

---

# 📊 Complexity Comparison

| Approach                 | Time     | Space |
| ------------------------ | -------- | ----- |
| Brute Force              | O(n × k) | O(k)  |
| Sliding Window Traversal | O(n × k) | O(k)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    int divisorSubstrings(int num, int k) {

        string s = to_string(num);

        int count = 0;

        for(int i = 0; i <= s.size() - k; i++) {

            int value =
                stoi(s.substr(i, k));

            if(value != 0 &&
               num % value == 0)
            {
                count++;
            }
        }

        return count;
    }
};

int main() {

    int num = 240;
    int k = 2;

    Solution obj;

    cout << "K-Beauty = "
         << obj.divisorSubstrings(num, k);

    return 0;
}
```

### Output

```text
K-Beauty = 2
```

---

# 🔥 Edge Cases

## Contains Zero

```cpp
num = 430043
k = 2
```

Substring:

```text
00
```

Value:

```cpp
0
```

Cannot divide by zero.

Ignore it.

---

## Entire Number Is One Window

```cpp
num = 120
k = 3
```

Substring:

```text
120
```

Check:

```cpp
120 % 120 == 0
```

Answer:

```cpp
1
```

---

## No Valid Substrings

```cpp
num = 123
k = 2
```

Substrings:

```text
12
23
```

Neither divides 123.

Answer:

```cpp
0
```

---

# 🎤 Interview Takeaways

✅ Fixed Length Substring → Think Sliding Window

✅ Digits can often be converted into strings for easier processing

✅ Always handle division-by-zero cases

✅ Not every sliding-window problem needs frequency maps

✅ Sometimes the window is only used to generate candidates

---

# 🔗 Related Problems

* Count Good Substrings of Size Three
* Maximum Number of Vowels in a Substring of Given Length
* Find All Anagrams in a String
* Repeated DNA Sequences
* Longest Substring Without Repeating Characters

These problems also involve substring traversal and sliding-window thinking.
