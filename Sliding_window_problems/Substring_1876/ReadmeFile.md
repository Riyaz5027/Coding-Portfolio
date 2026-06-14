# Count Substrings of Size Three With Distinct Characters

**Source:** LeetCode Problem #1876
**Difficulty:** Easy

## Topics

* String
* Sliding Window
* Hash Map
* Frequency Counting

---

# 📌 Problem Summary

You are given a string consisting of lowercase English letters.

Your task is to count how many substrings of length exactly `3` contain three distinct characters.

A substring is considered valid if no character repeats within that substring.

Return the total number of valid substrings.

---

# 📝 Sample Scenario

Consider:

```cpp
s = "xyzzaz"
```

Possible substrings of length 3:

```text
xyz
yzz
zza
zaz
```

Check each one:

```text
xyz  → Valid ✅
yzz  → Invalid ❌
zza  → Invalid ❌
zaz  → Invalid ❌
```

Answer:

```cpp
1
```

---

# 🎯 What Should We Notice First?

Most beginners see a string and immediately think:

❌ Two Pointers

❌ Prefix Sum

❌ Dynamic Programming

❌ Recursion

But before selecting an algorithm, ask:

> What exactly is the problem asking me to examine?

The problem asks us to examine:

```text
Every substring of length 3
```

The phrase:

```text
Substring of fixed size
```

is one of the biggest clues in DSA.

Whenever you see:

```text
Fixed Length Window
Fixed Size Subarray
Fixed Size Substring
```

you should immediately think:

✅ Sliding Window

---

# 🧠 How To Think When You See String Problems

Ask yourself:

---

## Question 1

Do I need to examine every substring?

Think:

```text
Sliding Window
```

---

## Question 2

Is the window size fixed?

Examples:

```text
Length 3
Length k
Exactly 5 characters
```

Think:

```text
Fixed Size Sliding Window
```

---

## Question 3

Do I need character frequencies?

Examples:

```text
Unique Characters
Duplicates
Anagrams
Character Counts
```

Think:

```text
Hash Map
Frequency Array
```

---

## Question 4

Do I need the longest or shortest substring?

Think:

```text
Variable Size Sliding Window
```

---

For this problem:

```text
Fixed Size Window     ✅
Character Frequency   ✅
Substring Problem     ✅

Prefix Sum            ❌
Binary Search         ❌
DP                    ❌
```

Therefore:

```text
Sliding Window + Frequency Counting
```

is the natural pattern.

---

# 🤔 Why Sliding Window?

Let's look at:

```cpp
s = "aababcabc"
```

All length-3 substrings:

```text
aab
aba
bab
abc
bca
cab
abc
```

Notice:

We are repeatedly checking:

```text
3 consecutive characters
```

The window size never changes.

Instead of rebuilding every substring from scratch:

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
Cumulative Information
```

Examples:

```text
Pivot Index
Running Sum
Subarray Sum Problems
```

This problem never asks for sums.

Therefore:

```text
Prefix Sum ❌
```

---

# ❌ Why Not Two Pointers?

Two Pointers are usually used for:

```text
Sorted Arrays
Pairs
Triplets
Opposite-End Traversal
```

Examples:

```text
Two Sum II
Container With Most Water
```

This problem is about examining every fixed-size substring.

Therefore:

```text
Two Pointers ❌
```

---

# 🔍 Core Observation

A substring is valid when:

```text
All 3 characters are distinct
```

Example:

```text
abc
```

Valid ✅

Because:

```text
a
b
c
```

are all different.

---

Example:

```text
aba
```

Invalid ❌

Because:

```text
a appears twice
```

---

Therefore our task becomes:

```text
For every window of size 3,
check whether all characters are unique.
```

---

# 💡 Mathematical Insight

Window Size:

```cpp
3
```

If a frequency map contains:

```cpp
3 unique keys
```

then:

```text
All characters are distinct
```

because the window itself contains exactly 3 characters.

Therefore:

```cpp
freq.size() == 3
```

immediately tells us:

```text
Current window is valid
```

This is the key observation behind the solution.

---

# 🐢 Approach 1: Brute Force

## Idea

Generate every substring of length 3.

For each substring:

1. Check all characters.
2. Verify they are distinct.
3. Increase answer if valid.

---

## Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(n)       |
| Space  | O(1)       |

Because the window size is fixed at 3.

---

# 🚀 Approach 2: Sliding Window + Frequency Map (Optimal)

## Idea

Maintain a window of size 3.

For every move:

1. Remove the left character.
2. Add the new right character.
3. Check:

```cpp
freq.size() == 3
```

If true:

```text
Valid Window Found
```

---

## Dry Run

```cpp
s = "xyzzaz"
```

Initial Window:

```text
xyz
```

Frequency:

```text
x → 1
y → 1
z → 1
```

Size:

```text
3
```

Valid ✅

Count = 1

---

Slide Window:

```text
yzz
```

Frequency:

```text
y → 1
z → 2
```

Size:

```text
2
```

Invalid ❌

Count remains:

```text
1
```

Continue until end.

Final Answer:

```text
1
```

---

# ⚡ Complexity Analysis

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(n)       |
| Space  | O(1)       |

Note:

Although a map is used, the alphabet contains only lowercase letters.

Maximum unique characters:

```cpp
26
```

Therefore space remains constant.

---

# 📊 Complexity Comparison

| Approach       | Time | Space |
| -------------- | ---- | ----- |
| Brute Force    | O(n) | O(1)  |
| Sliding Window | O(n) | O(1)  |

---

# 🧪 Driver Code For Local Testing

```cpp
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {

        map<char,int> freq;
        int count = 0;

        for(int i = 0; i < 3; i++)
            freq[s[i]]++;

        if(freq.size() == 3)
            count++;

        for(int i = 3; i < s.size(); i++) {

            freq[s[i-3]]--;

            if(freq[s[i-3]] == 0)
                freq.erase(s[i-3]);

            freq[s[i]]++;

            if(freq.size() == 3)
                count++;
        }

        return count;
    }
};

int main() {

    string s = "xyzzaz";

    Solution obj;

    cout << "Good Substrings = "
         << obj.countGoodSubstrings(s);

    return 0;
}
```

Output:

```text
Good Substrings = 1
```

---

# 🔥 Edge Cases

## Minimum Length

```cpp
s = "abc"
```

Answer:

```cpp
1
```

---

## All Same Characters

```cpp
s = "aaaaa"
```

Answer:

```cpp
0
```

---

## Every Window Valid

```cpp
s = "abcdef"
```

Windows:

```text
abc
bcd
cde
def
```

Answer:

```cpp
4
```

---

# 🎤 Interview Takeaways

✅ Fixed Size Substring → Think Sliding Window

✅ Distinct Characters → Think Frequency Counting

✅ Window Size = 3 is a huge clue

✅ `freq.size() == 3` directly tells us all characters are unique

✅ Most fixed-length substring problems can be optimized using Sliding Window

---

# 🔗 Related Problems

* Longest Substring Without Repeating Characters
* Permutation in String
* Find All Anagrams in a String
* Maximum Number of Vowels in a Substring of Given Length
* Repeated DNA Sequences
