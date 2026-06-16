# Minimum Recolors to Get K Consecutive Black Blocks

**Source:** LeetCode Problem #2379
**Difficulty:** Easy

## Topics

* String
* Sliding Window
* Fixed Size Window
* Counting

---

# 📌 Problem Summary

You are given a string consisting of:

```text
'B' → Black Block
'W' → White Block
```

You may recolor any white block into a black block.

Your goal is to find the **minimum number of recolors** required to obtain **at least one sequence of k consecutive black blocks**.

Return the minimum number of recolors needed.

---

# 📝 Sample Scenario

Consider:

```cpp
blocks = "WBBWWBBWBW"
k = 7
```

Possible windows of length 7:

```text
WBBWWBB
BBWWBBW
BWWBBWB
WWBBWBW
```

Count white blocks in each window:

```text
WBBWWBB → 3 whites
BBWWBBW → 3 whites
BWWBBWB → 3 whites
WWBBWBW → 4 whites
```

Minimum:

```cpp
3
```

Answer:

```cpp
3
```

---

# 🎯 What Should We Notice First?

Most beginners see:

```text
Minimum Operations
Recolor Blocks
Black and White
```

and immediately think:

❌ Greedy

❌ Dynamic Programming

❌ Recursion

❌ Backtracking

But the most important clue is:

```text
k Consecutive Blocks
```

The word:

```text
Consecutive
```

should always grab your attention.

And when combined with:

```text
Exactly k
```

it becomes an even bigger clue.

---

# 🧠 Beginner Thinking Process

Ask yourself:

> What exactly am I checking?

The problem asks:

```text
Among all windows of size k,
which one requires the fewest recolors?
```

Notice:

We are not searching for:

```text
Pairs
Triplets
Subsequences
```

We are only examining:

```text
Every substring of length k
```

This immediately suggests:

✅ Fixed Size Sliding Window

---

# 🔍 Pattern Recognition

Whenever you see:

### Exactly k Consecutive Elements

Examples:

```text
Length k
Size k
Exactly k characters
Exactly k elements
```

Think:

```text
Fixed Size Sliding Window
```

---

### Need Information About Every Window

Examples:

```text
Count Whites
Count Vowels
Count Zeros
Count Distinct Elements
```

Think:

```text
Sliding Window
Frequency Tracking
```

---

### Looking For Minimum / Maximum Window Property

Examples:

```text
Minimum Operations
Maximum Sum
Maximum Frequency
```

Think:

```text
Sliding Window
```

---

For this problem:

```text
Fixed Window Size      ✅
Consecutive Elements   ✅
Counting Characters    ✅

Prefix Sum            ❌
Binary Search         ❌
DP                    ❌
```

---

# 🤔 Why Sliding Window?

Suppose:

```cpp
blocks = "WBBWWBBWBW"
k = 7
```

First window:

```text
WBBWWBB
```

Whites:

```text
3
```

Now instead of recounting the next window from scratch:

```text
BBWWBBW
```

we can simply:

```text
Remove Left Character
Add Right Character
```

This is exactly what Sliding Window was designed for.

---

# ❌ Why Not Prefix Sum?

Prefix Sum is useful when we need:

```text
Range Sums
Running Totals
Numerical Queries
```

Examples:

```text
Pivot Index
Subarray Sum Equals K
Range Sum Query
```

This problem is not about sums.

We only need:

```text
Count of White Blocks
```

inside a fixed window.

Therefore:

```text
Prefix Sum ❌
```

(Although a Prefix Sum solution can be built, Sliding Window is more natural.)

---

# ❌ Why Not Two Pointers?

Two pointers are useful when:

```text
Window size changes
```

Examples:

```text
Longest Substring Without Repeating Characters
Minimum Window Substring
```

Here:

```text
Window size never changes.
```

Therefore:

```text
Fixed Size Sliding Window
```

is sufficient.

---

# 💡 Core Observation

Suppose:

```cpp
blocks = "WBBWWBBWBW"
k = 7
```

A window becomes perfect when:

```text
All characters are B
```

If a window contains:

```text
3 White Blocks
```

then:

```text
3 recolors are needed.
```

Therefore:

The problem becomes:

```text
Find the window
with the minimum number of W characters.
```

This is the key insight.

---

# 🐢 Approach 1: Brute Force

## Idea

For every window of size k:

1. Count white blocks.
2. Keep track of minimum count.

---

## Example

```cpp
blocks = "WBBWWBBWBW"
k = 7
```

Window:

```text
WBBWWBB
```

White Count:

```cpp
3
```

Window:

```text
BBWWBBW
```

White Count:

```cpp
3
```

Continue until end.

---

## Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(n × k)   |
| Space  | O(1)       |

---

# 🚀 Approach 2: Sliding Window (Optimal)

## Idea

Instead of recounting whites in every window:

Maintain:

```cpp
whiteCount
```

For every slide:

### Remove Left Character

If:

```cpp
blocks[left] == 'W'
```

decrease:

```cpp
whiteCount--
```

---

### Add Right Character

If:

```cpp
blocks[right] == 'W'
```

increase:

```cpp
whiteCount++
```

---

Update answer:

```cpp
answer = min(answer, whiteCount)
```

---

# 🔍 Dry Run

```cpp
blocks = "WBBWWBBWBW"
k = 7
```

Initial Window:

```text
WBBWWBB
```

White Count:

```cpp
3
```

Answer:

```cpp
3
```

---

Slide Window

Remove:

```cpp
W
```

White Count:

```cpp
2
```

Add:

```cpp
W
```

White Count:

```cpp
3
```

Window:

```text
BBWWBBW
```

Answer:

```cpp
3
```

Continue until end.

Final Answer:

```cpp
3
```

---

# ✅ Optimal Code

```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int whiteCount = 0;

        for(int i = 0; i < k; i++) {

            if(blocks[i] == 'W')
                whiteCount++;
        }

        int answer = whiteCount;

        for(int i = k; i < blocks.size(); i++) {

            if(blocks[i - k] == 'W')
                whiteCount--;

            if(blocks[i] == 'W')
                whiteCount++;

            answer = min(answer, whiteCount);
        }

        return answer;
    }
};
```

---

# ⚡ Complexity Analysis

## Time Complexity

Initial Window:

```cpp
O(k)
```

Sliding Window Traversal:

```cpp
O(n)
```

Total:

```cpp
O(n)
```

---

## Space Complexity

```cpp
O(1)
```

---

# 📊 Complexity Comparison

| Approach       | Time     | Space |
| -------------- | -------- | ----- |
| Brute Force    | O(n × k) | O(1)  |
| Sliding Window | O(n)     | O(1)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int whiteCount = 0;

        for(int i = 0; i < k; i++) {

            if(blocks[i] == 'W')
                whiteCount++;
        }

        int answer = whiteCount;

        for(int i = k; i < blocks.size(); i++) {

            if(blocks[i - k] == 'W')
                whiteCount--;

            if(blocks[i] == 'W')
                whiteCount++;

            answer = min(answer, whiteCount);
        }

        return answer;
    }
};

int main() {

    string blocks = "WBBWWBBWBW";
    int k = 7;

    Solution obj;

    cout << "Minimum Recolors = "
         << obj.minimumRecolors(blocks, k);

    return 0;
}
```

### Output

```text
Minimum Recolors = 3
```

---

# 🔥 Edge Cases

## Already Has K Consecutive Black Blocks

```cpp
blocks = "BBBBBBB"
k = 7
```

Answer:

```cpp
0
```

No recoloring needed.

---

## All White Blocks

```cpp
blocks = "WWWWW"
k = 3
```

Window:

```text
WWW
```

Need:

```cpp
3
```

recolors.

Answer:

```cpp
3
```

---

## k = 1

```cpp
blocks = "WBWB"
```

Any single black block already satisfies the condition.

Answer:

```cpp
0
```

---

# 🎤 Interview Takeaways

✅ Fixed Length Substring → Think Sliding Window

✅ "Consecutive" is often a strong clue

✅ Instead of counting blacks, count whites

✅ The minimum whites in a window equals the minimum recolors needed

✅ Most fixed-size window problems can be optimized by maintaining a running count

---

# 🔗 Related Problems

* Count Good Substrings of Size Three
* Find the K-Beauty of a Number
* Maximum Number of Vowels in a Substring of Given Length
* Permutation in String
* Find All Anagrams in a String

These problems all use the Fixed Size Sliding Window pattern.
