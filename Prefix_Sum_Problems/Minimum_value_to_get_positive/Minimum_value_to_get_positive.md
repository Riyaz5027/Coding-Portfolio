# Minimum Starting Value for a Safe Running Total

**Source:** LeetCode Problem #1413
**Difficulty:** Easy

## Topics

* Array
* Prefix Sum
* Running Sum

---

# 📌 Problem Summary

You are given an integer array.

Imagine you start with an unknown positive value called `startValue`.

You process the array from left to right and continuously add each element to your current total.

Your goal is to find the **smallest possible starting value** such that the running total never becomes smaller than `1` at any point.

---

# 📝 Sample Scenario

Consider:

```cpp
nums = [-3, 2, -3, 4, 2]
```

Suppose we start with:

```cpp
startValue = 5
```

Running totals:

```text
5
5 + (-3) = 2
2 + 2 = 4
4 + (-3) = 1
1 + 4 = 5
5 + 2 = 7
```

The running total never drops below:

```cpp
1
```

Therefore:

```cpp
Answer = 5
```

---

# 🎯 What Should We Notice First?

Most beginners immediately think about:

❌ Sorting

❌ Sliding Window

❌ Two Pointers

❌ Binary Search

However, the problem repeatedly talks about:

```text
Running Total
Current Sum
Step-by-Step Sum
```

Whenever you see phrases like these, ask yourself:

> "Do I need to know the cumulative sum up to every position?"

If the answer is YES, Prefix Sum should immediately come to mind.

---

# 🧠 How To Think When You See Array Problems

This is one of the most important sections.

Whenever you see an array problem, ask yourself the following questions.

---

## Question 1

Do I need information about all previous elements?

Examples:

```text
Running Sum
Cumulative Sum
Total Until Current Position
```

Think:

```text
Prefix Sum
```

---

## Question 2

Do I need information about future elements?

Think:

```text
Suffix Sum
```

---

## Question 3

Am I searching for a continuous subarray?

Think:

```text
Sliding Window
Kadane's Algorithm
```

---

## Question 4

Am I looking for pairs or triplets?

Think:

```text
Two Pointers
Hashing
```

---

## Question 5

Am I repeatedly calculating sums?

Think:

```text
Prefix Sum
```

---

For this problem:

```text
Running Sum        ✅
Subarray           ❌
Pairs              ❌
Sorting            ❌
Searching          ❌
```

Therefore:

```text
Prefix Sum is the natural pattern.
```

---

# 🤔 Why Prefix Sum?

Let's examine:

```cpp
nums = [-3, 2, -3, 4, 2]
```

Running sums:

```text
-3
-1
-4
0
2
```

Notice something important.

The answer does NOT depend on:

```text
Largest Element
Smallest Element
Sorted Order
Maximum Sum
```

Instead, the answer depends on:

```text
The lowest running sum
```

Running sums are exactly what Prefix Sums represent.

Therefore:

```text
Prefix Sum is the correct tool.
```

---

# ❌ Why Not Sliding Window?

Sliding Window is useful when we need:

```text
Fixed Size Subarray
Variable Size Subarray
Continuous Segment
```

Examples:

```text
Maximum Sum Subarray
Longest Substring Problems
```

This problem never asks us to find a subarray.

Therefore:

```text
Sliding Window ❌
```

---

# ❌ Why Not Two Pointers?

Two Pointers are useful when dealing with:

```text
Pairs
Triplets
Sorted Arrays
```

Examples:

```text
Two Sum II
3 Sum
Container With Most Water
```

This problem contains none of these requirements.

Therefore:

```text
Two Pointers ❌
```

---

# ❌ Why Not Binary Search?

Binary Search is useful when:

```text
Data is sorted
Search space exists
Monotonic answer exists
```

This problem does not require searching.

Therefore:

```text
Binary Search ❌
```

---

# 🔍 Core Observation

Suppose:

```cpp
nums = [-3, 2, -3, 4, 2]
```

Start with:

```cpp
startValue = x
```

Running totals become:

```text
x - 3
x - 1
x - 4
x
x + 2
```

Every value must satisfy:

```cpp
>= 1
```

The worst point occurs where the running total is smallest.

Let's compute the Prefix Sums.

```text
-3
-1
-4
0
2
```

Minimum Prefix Sum:

```text
-4
```

This is the most dangerous point.

If we can survive this point, we can survive every other point.

---

# 💡 Mathematical Insight

At the lowest point:

```text
startValue + minimumPrefix >= 1
```

Substituting:

```text
startValue + (-4) >= 1
```

Therefore:

```text
startValue >= 5
```

General Formula:

```text
startValue + minimumPrefix >= 1
```

Rearranging:

```text
startValue >= 1 - minimumPrefix
```

Therefore:

```text
Answer = 1 - minimumPrefix
```

This single formula solves the entire problem.

---

# 🐢 Approach 1: Brute Force

## Idea

Try:

```cpp
startValue = 1
startValue = 2
startValue = 3
...
```

Keep checking until a valid value is found.

---

## Code

```cpp
class Solution {
public:

    bool isValid(vector<int>& nums, int startValue) {

        int current = startValue;

        for(int num : nums) {

            current += num;

            if(current < 1)
                return false;
        }

        return true;
    }

    int minStartValue(vector<int>& nums) {

        int startValue = 1;

        while(true) {

            if(isValid(nums, startValue))
                return startValue;

            startValue++;
        }
    }
};
```

---

## Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(k × n)   |
| Space  | O(1)       |

Where `k` is the answer.

---

# 🚀 Approach 2: Prefix Sum (Optimal)

## Idea

Instead of testing every possible starting value:

1. Compute all Prefix Sums.
2. Find the minimum Prefix Sum.
3. Apply:

```text
Answer = 1 - minimumPrefix
```

---

## Dry Run

```cpp
nums = [-3,2,-3,4,2]
```

| Element | Prefix Sum | Minimum Prefix |
| ------- | ---------- | -------------- |
| -3      | -3         | -3             |
| 2       | -1         | -3             |
| -3      | -4         | -4             |
| 4       | 0          | -4             |
| 2       | 2          | -4             |

Final:

```cpp
minimumPrefix = -4
```

Answer:

```cpp
1 - (-4)
=
5
```

---

## Optimal Code

```cpp
class Solution {
public:

    int minStartValue(vector<int>& nums) {

        int prefix = 0;
        int minimumPrefix = 0;

        for(int num : nums) {

            prefix += num;

            minimumPrefix =
                min(minimumPrefix, prefix);
        }

        return 1 - minimumPrefix;
    }
};
```

---

# ⚡ Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(n)       |
| Space  | O(1)       |

---

# 📊 Complexity Comparison

| Approach             | Time     | Space |
| -------------------- | -------- | ----- |
| Brute Force          | O(k × n) | O(1)  |
| Prefix Sum (Optimal) | O(n)     | O(1)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minStartValue(vector<int>& nums) {

        int prefix = 0;
        int minimumPrefix = 0;

        for(int num : nums) {

            prefix += num;

            minimumPrefix =
                min(minimumPrefix, prefix);
        }

        return 1 - minimumPrefix;
    }
};

int main() {

    vector<int> nums = {-3, 2, -3, 4, 2};

    Solution obj;

    cout << "Minimum Start Value = "
         << obj.minStartValue(nums);

    return 0;
}
```

### Output

```text
Minimum Start Value = 5
```

---

# 🔥 Edge Cases

## Single Positive Number

```cpp
nums = [5]
```

Answer:

```cpp
1
```

---

## Single Negative Number

```cpp
nums = [-5]
```

Answer:

```cpp
6
```

---

## All Positive Numbers

```cpp
nums = [1,2,3]
```

Answer:

```cpp
1
```

Because the running total never becomes negative.

---

## All Negative Numbers

```cpp
nums = [-1,-2,-3]
```

Prefix Sums:

```text
-1
-3
-6
```

Minimum Prefix:

```cpp
-6
```

Answer:

```cpp
1 - (-6)
=
7
```

---

# 🎤 Interview Takeaways

✅ Running Sum → Think Prefix Sum

✅ The answer depends on the minimum Prefix Sum

✅ We do not need to store the entire Prefix Sum array

✅ Tracking only the current Prefix Sum and minimum Prefix Sum is enough

✅ The entire problem is solved using:

```text
Answer = 1 - minimumPrefix
```

---

# 🔗 Related Problems

* Pivot Index
* Running Sum of 1D Array
* Range Sum Query
* Subarray Sum Equals K
* Continuous Subarray Sum

These problems also rely heavily on Prefix Sum concepts.
