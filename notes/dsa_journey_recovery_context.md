# DSA Journey --- Recovery Context & Progress

**Last updated:** 2026-08-16

> Purpose: Upload this file back to ChatGPT if conversation context is
> lost. It records the DSA roadmap, completed material, important
> patterns, teaching preferences, and exact continuation point.

## 1. Learning style and plan

The learner is studying DSA in C++ and prefers this flow:

1.  Explain the concept simply.
2.  Show a small example or simulation.
3.  Explain how to recognize the pattern.
4.  Give a problem to attempt independently.
5.  Give hints before the full solution when useful.
6.  Review submitted code by identifying exact mistakes rather than
    unnecessarily rewriting everything.
7.  Prefer understanding and reconstructing algorithms over memorizing
    code.
8.  Use concise flow diagrams for tricky algorithms.

Previously stated LeetCode solved count: **123**.

After the Arrays foundation is complete, provide a curated **40--55
LeetCode problem list**, preferably mostly new problems rather than
duplicates already solved.

Do not alter the normal learning pace because of any previous one-day
target to finish Arrays.

------------------------------------------------------------------------

## 2. Arrays roadmap and current position

  Topic                     Status
  ------------------------- -----------
  Array Fundamentals        Complete
  Binary Search             Complete
  Binary Search on Answer   Complete
  Sorting                   Complete
  Hashing                   Complete
  Two Pointers              **NEXT**
  Sliding Window            Remaining

After Two Pointers and Sliding Window, give the requested 40--55 problem
Arrays LeetCode practice set.

------------------------------------------------------------------------

# 3. Array Fundamentals

Covered:

-   Array input/output and traversal
-   Sum
-   Maximum/minimum
-   Even/odd count
-   Reverse array
-   Palindrome using two pointers
-   Second largest
-   Check ascending order
-   Frequency array
-   Mode
-   Linear search
-   Last index
-   Count occurrences
-   Search from end

Useful snippets:

``` cpp
for(int i = 0; i < n; i++){
    cin >> arr[i];
}
```

``` cpp
int mx = *max_element(arr, arr + n);
int mn = *min_element(arr, arr + n);
```

``` cpp
int sum = accumulate(arr, arr + n, 0);
```

For large sums:

``` cpp
long long sum = accumulate(arr, arr + n, 0LL);
```

------------------------------------------------------------------------

# 4. Binary Search

Generic pattern:

``` cpp
int left = 0;
int right = n - 1;

while(left <= right){
    int mid = left + (right - left) / 2;

    if(arr[mid] == target){
        // found
    }
    else if(target < arr[mid]){
        right = mid - 1;
    }
    else{
        left = mid + 1;
    }
}
```

Important lesson: `mid` is an index. Compare `arr[mid]` with the target,
not `mid` itself.

Important variations covered included:

-   Standard Binary Search
-   First/last occurrence
-   Lower/upper-bound style reasoning
-   Floor/ceil ideas
-   Rotated sorted array patterns
-   Minimum in rotated array
-   Peak-element style search
-   Binary Search on Answer

------------------------------------------------------------------------

# 5. Binary Search on Answer

Recognition:

> Guess an answer `mid`, efficiently check whether it works, and exploit
> monotonic feasibility.

Minimum valid:

``` text
X X X X ✓ ✓ ✓
        ^
   minimum valid
```

``` cpp
if(possible(mid)){
    answer = mid;
    right = mid - 1;
}else{
    left = mid + 1;
}
```

Maximum valid:

``` text
✓ ✓ ✓ ✓ X X X
      ^
 maximum valid
```

``` cpp
if(possible(mid)){
    answer = mid;
    left = mid + 1;
}else{
    right = mid - 1;
}
```

The most important skill is choosing `left`, `right`, and writing the
feasibility helper.

## Koko Eating Bananas

Search eating speed:

``` cpp
left = 1;
right = maxPile;
```

Ceiling division:

``` cpp
totalHours += (arr[i] + speed - 1) / speed;
```

Feasible when:

``` cpp
totalHours <= h
```

Smaller speed gives more hours; if `mid` works, search left for a
smaller speed.

## Ship Packages Within D Days

Search minimum capacity:

``` cpp
left = *max_element(arr, arr + n);
right = accumulate(arr, arr + n, 0);
```

Helper:

``` cpp
bool canLoad(int arr[], int n, int capacity, int D){
    int days = 1;
    int currentLoad = 0;

    for(int i = 0; i < n; i++){
        if(currentLoad + arr[i] <= capacity){
            currentLoad += arr[i];
        }else{
            days++;
            currentLoad = arr[i];
        }
    }

    return days <= D;
}
```

Key idea: packages remain consecutive; greedily fill each day until the
next package would exceed capacity.

## Aggressive Cows

Array values are stall positions. Sort first.

``` cpp
sort(arr, arr + n);

left = 1;
right = arr[n - 1] - arr[0];
```

Goal: **maximize the minimum distance**.

``` cpp
bool canPlace(int arr[], int n, int k, int distance){
    int cowCount = 1;
    int lastPosition = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] - lastPosition >= distance){
            cowCount++;
            lastPosition = arr[i];
        }

        if(cowCount >= k)
            return true;
    }

    return false;
}
```

If feasible, move right:

``` cpp
answer = mid;
left = mid + 1;
```

## Book Allocation

Allocate contiguous books while minimizing the maximum pages assigned to
a student.

``` cpp
left = *max_element(arr, arr + n);
right = accumulate(arr, arr + n, 0);
```

Why max for `left`: somebody must receive the largest individual book.

``` cpp
int distribution_possible(int arr[], int n, int mid){
    int students = 1;
    int currentPages = 0;

    for(int i = 0; i < n; i++){
        if(currentPages + arr[i] <= mid){
            currentPages += arr[i];
        }else{
            students++;
            currentPages = arr[i];
        }
    }

    return students;
}
```

If students required exceed `m`, `mid` is too small.

## Minimum Days to Make M Bouquets

`bloomDay[i]` is the absolute day flower `i` blooms.

Need `m` bouquets of `k` adjacent flowers.

``` cpp
left = *min_element(arr, arr + n);
right = *max_element(arr, arr + n);
```

Flower available by guessed day:

``` cpp
arr[i] <= mid
```

``` cpp
int bouquetsFormed(int arr[], int n, int k, int mid){
    int bouquets = 0;
    int flowers = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] <= mid){
            flowers++;

            if(flowers >= k){
                bouquets++;
                flowers = 0;
            }
        }else{
            flowers = 0;
        }
    }

    return bouquets;
}
```

Impossible case:

``` cpp
if(1LL * m * k > n)
    return -1;
```

## Smallest Divisor Given a Threshold

``` cpp
left = 1;
right = *max_element(arr, arr + n);
```

At divisor `max(arr)`, every positive element already contributes its
minimum possible value `1`, so larger divisors are unnecessary.

``` cpp
int helper(int arr[], int n, int divisor){
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += (arr[i] + divisor - 1) / divisor;
    }

    return sum;
}
```

If sum `<= threshold`, divisor works; search left.

## Split Array Largest Sum

Split into `k` non-empty contiguous subarrays and minimize the largest
subarray sum.

``` cpp
left = *max_element(arr, arr + n);
right = accumulate(arr, arr + n, 0);
```

``` cpp
int helper(int arr[], int n, int mid){
    int count = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++){
        if(currentSum + arr[i] <= mid){
            currentSum += arr[i];
        }else{
            count++;
            currentSum = arr[i];
        }
    }

    return count;
}
```

If `count <= k`, `mid` is feasible and we search for a smaller maximum.

Important intuition:

> Check whether `currentSum + arr[i]` would exceed `mid` **before**
> adding the element.

------------------------------------------------------------------------

# 6. Sorting

Completed:

-   Bubble Sort
-   Selection Sort
-   Insertion Sort
-   Merge Sort
-   Quick Sort
-   STL `sort()`
-   Custom comparators

## Bubble Sort

> Repeatedly compare adjacent elements and push the largest remaining
> value toward the end.

``` cpp
for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j < i; j++){
        if(arr[j] > arr[j + 1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
```

Time `O(n^2)`, space `O(1)`.

## Selection Sort

> Find the smallest value in the unsorted portion and put it at the
> front.

``` cpp
for(int i = 0; i < n - 1; i++){
    int minIndex = i;

    for(int j = i + 1; j < n; j++){
        if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }

    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}
```

Remember:

``` text
minIndex      = index
arr[minIndex] = value
```

Find the minimum first, then swap once.

## Insertion Sort

> Take the current element and move/insert it into the correct position
> in the already-sorted left portion.

Swap-based version:

``` cpp
for(int i = 1; i < n; i++){
    for(int j = i; j > 0; j--){
        if(arr[j] < arr[j - 1]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }else{
            break;
        }
    }
}
```

Standard shift version:

``` cpp
for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}
```

## Merge Sort

Pattern: Divide and Conquer.

> Split until one element remains, then merge sorted halves back
> together.

``` cpp
void mergeSort(int arr[], int left, int right){
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
```

Merge pointers:

``` text
i = left
j = mid + 1
k = 0
```

``` cpp
void merge(int arr[], int left, int mid, int right){
    int temp[right - left + 1];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(int x = 0; x < k; x++){
        arr[left + x] = temp[x];
    }
}
```

Time `O(n log n)`, auxiliary space `O(n)`.

## Quick Sort

Pattern: Divide and Conquer.

> Choose pivot → partition → pivot becomes fixed → recursively sort both
> sides.

The implementation learned chooses the last element:

``` cpp
int pivot = arr[high];
```

**Partition definition:** Rearranges the range around a pivot so smaller
elements are on its left and larger elements are on its right, placing
the pivot in its correct sorted position.

``` cpp
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
```

`j` scans; `i` marks the end of the smaller-than-pivot zone.

If an element is bigger than the pivot, simply skip it.

At the end we swap with `arr[high]` because that is where our chosen
pivot was stored.

``` cpp
void quickSort(int arr[], int low, int high){
    if(low >= high)
        return;

    int pivotPosition = partition(arr, low, high);

    quickSort(arr, low, pivotPosition - 1);
    quickSort(arr, pivotPosition + 1, high);
}
```

Average `O(n log n)`, worst `O(n^2)`.

## STL Sort

C-style array:

``` cpp
sort(arr, arr + n);
```

Vector:

``` cpp
sort(v.begin(), v.end());
```

Descending:

``` cpp
sort(arr, arr + n, greater<int>());
```

## Custom Comparator

Interpret a comparator as:

> Should `a` come before `b`?

Example: first ascending; when tied, second descending.

``` cpp
bool comparator(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}
```

``` cpp
sort(arr, arr + n, comparator);
```

------------------------------------------------------------------------

# 7. Hashing

Main structures:

``` cpp
unordered_map
unordered_set
```

Difference:

``` text
unordered_map = key + associated value
unordered_set = existence of a value
```

Average insertion/search is usually `O(1)`.

## Frequency Count

``` cpp
unordered_map<int,int> freq;

for(int i = 0; i < n; i++){
    freq[arr[i]]++;
}
```

``` cpp
for(auto elem : freq){
    cout << elem.first << " " << elem.second << endl;
}
```

`elem.first` is the key; `elem.second` is its frequency.

`unordered_map` does not guarantee output order.

## First Repeating Element

Build frequency map, then scan the **original array** from left to
right:

``` cpp
for(int i = 0; i < n; i++){
    if(freq[arr[i]] > 1){
        cout << arr[i] << endl;
        break;
    }
}
```

This preserves first-occurrence meaning.

## Two Sum

Brute-force `O(n^2)` was implemented first.

Optimized hash-map pattern:

``` cpp
unordered_map<int,int> seen;

for(int i = 0; i < n; i++){
    int needed = target - arr[i];

    if(seen.find(needed) != seen.end()){
        cout << seen[needed] << " " << i << endl;
        return 0;
    }

    seen[arr[i]] = i;
}
```

Store:

``` text
number -> index
```

Memory line:

> Calculate needed → check map → if absent, store current.

Check before storing so an element does not match itself.

LeetCode 1.

## Contains Duplicate

``` cpp
unordered_set<int> seen;

for(int i = 0; i < n; i++){
    int current = arr[i];

    if(seen.find(current) != seen.end()){
        // duplicate
    }

    seen.insert(current);
}
```

Pattern:

``` text
already seen -> duplicate
not seen     -> insert
```

## Intersection of Two Arrays

Unique common values:

``` cpp
unordered_set<int> set1;
unordered_set<int> answer;

for(int i = 0; i < n; i++)
    set1.insert(arr1[i]);

for(int i = 0; i < m; i++){
    if(set1.find(arr2[i]) != set1.end()){
        answer.insert(arr2[i]);
    }
}
```

Second set prevents duplicate answers.

## Longest Consecutive Sequence

LeetCode 128.

Example:

``` text
[100, 4, 200, 1, 3, 2]

1 -> 2 -> 3 -> 4
answer = 4
```

Store everything:

``` cpp
unordered_set<int> seen;

for(int i = 0; i < n; i++)
    seen.insert(arr[i]);
```

Only begin counting when there is no predecessor:

``` cpp
if(seen.find(current - 1) == seen.end())
```

Then:

``` cpp
int length = 1;

while(seen.find(current + 1) != seen.end()){
    current++;
    length++;
}
```

Core idea:

> Store all values → identify sequence starts (no predecessor) → count
> forward.

Average `O(n)` time, `O(n)` space.

------------------------------------------------------------------------

# 8. Important C++ Notes

## max_element / min_element

They return iterators/pointers:

``` cpp
int mx = *max_element(arr, arr + n);
int mn = *min_element(arr, arr + n);
```

## accumulate

``` cpp
#include <numeric>
```

``` cpp
int sum = accumulate(arr, arr + n, 0);
```

Use `0LL` for a `long long` accumulation.

## Ceiling division

For positive integers:

``` cpp
(a + b - 1) / b
```

This is important in Koko and Smallest Divisor.

## unordered_map / unordered_set find

Exists:

``` cpp
container.find(x) != container.end()
```

Does not exist:

``` cpp
container.find(x) == container.end()
```

## return from main

`return` from `int main()` is an exit status; it does not print the
answer.

Use:

``` cpp
cout << answer << endl;
return 0;
```

In a LeetCode function returning `bool`, `int`, `vector<int>`, etc.,
return the requested result normally.

## Runtime-sized C-style arrays

Learning code often used:

``` cpp
int arr[n];
```

This is supported by some compilers as an extension but is not standard
C++ for runtime `n`.

Standard C++/LeetCode code usually prefers:

``` cpp
vector<int> arr(n);
```

Do not derail the current learning flow over this; introduce vectors
naturally.

------------------------------------------------------------------------

# 9. High-value Pattern Summary

## Binary Search on Answer

``` text
Guess mid -> test feasibility -> use monotonicity
```

## Contiguous grouping under a maximum

Used in Shipping, Book Allocation, Split Array:

``` cpp
if(current + arr[i] <= limit){
    current += arr[i];
}else{
    groups++;
    current = arr[i];
}
```

## Ceiling division

``` cpp
(value + divisor - 1) / divisor
```

## Two Sum complement

``` cpp
needed = target - current;
```

Then hash lookup.

## Set existence

Use `unordered_set` when only membership matters.

## Longest consecutive start

Only start when:

``` cpp
current - 1
```

does not exist.

------------------------------------------------------------------------

# 10. Representative Problems Completed

-   Standard Binary Search
-   Binary Search variations: first/last occurrence, lower/upper-bound
    reasoning, rotated array, minimum/peak-style searches
-   Koko Eating Bananas
-   Ship Packages Within D Days
-   Aggressive Cows
-   Book Allocation
-   Minimum Days to Make M Bouquets
-   Smallest Divisor Given a Threshold
-   Split Array Largest Sum
-   Bubble Sort
-   Selection Sort
-   Insertion Sort
-   Merge Sort
-   Quick Sort
-   STL sorting
-   Custom Comparator
-   Frequency Count
-   First Repeating Element
-   Two Sum
-   Contains Duplicate
-   Intersection of Two Arrays
-   Longest Consecutive Sequence

------------------------------------------------------------------------

# 11. EXACT RECOVERY POINT

Do not restart completed topics unless revision is explicitly requested.

Current state:

``` text
Array Fundamentals        COMPLETE
Binary Search             COMPLETE
Binary Search on Answer   COMPLETE
Sorting                   COMPLETE
Hashing                   COMPLETE

Two Pointers              START NEXT
Sliding Window            AFTER THAT
```

The next teaching topic should therefore be:

# TWO POINTERS

Teach:

1.  What two pointers means.
2.  When to recognize it.
3.  Opposite-direction vs same-direction pointers.
4.  Show a simple array simulation.
5.  Give a practice problem and let the learner attempt it.
6.  Continue with enough representative questions to establish the
    pattern.

Then teach Sliding Window.

------------------------------------------------------------------------

# 12. After Arrays

Once Two Pointers and Sliding Window are complete, provide a curated
**40--55 LeetCode problem set**.

Requirements:

-   At least 40, at most 55.
-   Prefer genuinely new problems.
-   Progress from easier reinforcement to Medium and stronger
    Medium/Hard.
-   Cover the full Arrays foundation.
-   Include array fundamentals, Binary Search, Binary Search on Answer,
    sorting reasoning, hashing, Two Pointers, and Sliding Window.
-   Do not unnecessarily label every question with the exact technique
    if pattern-recognition practice would be more useful.
-   Previously stated solved count was 123.

------------------------------------------------------------------------

# 13. Future-session Teaching Instructions

-   Keep explanations simple, concise, and practical.
-   Let the learner code.
-   Give hints before full solutions when appropriate.
-   When reviewing code, point to the exact incorrect line and explain
    why.
-   Avoid rewriting the whole solution when only a small fix is needed.
-   Use concrete examples for intuition.
-   Use text flow diagrams and array simulations for tricky algorithms.
-   Repeatedly clarify index vs value where relevant.
-   Explain `left` and `right` boundaries in plain language.
-   Reinforce why binary-search direction changes.
-   Favor reconstruction over memorization.
-   Mark a topic complete once sufficiently practiced.
-   Continue at the normal learning pace.
-   After Arrays, remember the requested 40--55 LeetCode set.

------------------------------------------------------------------------

# 14. Minimal Recovery Instruction

If context is lost, upload this file and say:

> Continue my DSA journey from the EXACT RECOVERY POINT section and
> follow the teaching instructions in this file.

Correct continuation from this version:

> **Start Two Pointers.**
