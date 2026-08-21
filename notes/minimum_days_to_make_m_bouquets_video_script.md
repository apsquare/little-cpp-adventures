# 🌸 Minimum Days to Make M Bouquets — Short Walkthrough

**File:** [Minimum Days to make M Bouquets.cpp](Minimum%20Days%20to%20make%20M%20Bouquets.cpp) · **Runtime:** ~3 min

🎙️ = say it · 🖥️ = show it

---

### 1. The problem

```cpp
// You are given an array bloomDay, where:
// bloomDay[i] is the day on which the i-th flower blooms.
// You need to make exactly m bouquets.
// Each bouquet requires k adjacent flowers, and each flower can be used only once.
```
*lines 7–14*

🎙️ "We've got a row of flowers. Each one has a day it blooms on. We want to make `m` bouquets, and every bouquet needs `k` flowers sitting **right next to each other**. Question is: what's the earliest day we can pull that off?"

---

### 2. The idea

🖥️ No code here — just a day line on screen:
```
Day:    1    2    3    4    5    6    7    8    9
Works?  ❌   ❌   ❌   ❌   ❌   ❌   ✅   ✅   ✅
                                   ↑ answer
```

🎙️ "Here's the whole trick. Once a flower blooms, it stays bloomed. So if day 7 works, day 8 definitely works too — you've only got more flowers. And if day 7 doesn't work, day 6 has no chance.

So the answer line is all NOs, then all YESes. It flips once and never flips back. That means we don't have to check every day — we can **jump to the middle and cut the rest in half**, over and over, until we land on that flip. We're searching the days, not the flowers."

---

### 3. The impossible case

```cpp
if (1LL * m * k > n) {
    cout << -1 << endl;
    return 0;
}
```
*lines 47–51*

🎙️ "First, the easy out. `m` bouquets times `k` flowers each — that's how many flowers we need. If the garden has fewer than that, waiting won't help. There just aren't enough flowers. Print `-1` and go home."

🖥️ Zoom on `1LL`

🎙️ "Quick note on that `1LL`. If `m` and `k` are big, multiplying two `int`s can wrap around and give you a garbage number, and your check quietly passes when it shouldn't. Sticking `1LL` in front makes it use the bigger number type, so it can't wrap. Tiny thing, real bug avoided."

---

### 4. Counting the bouquets

```cpp
int current_bouquets = 0;
int current_flowers = 0;
```
*lines 17–18*

🎙️ "This function answers one question: **if I walk into the garden on day `mid`, how many bouquets can I make?**

Two counters. One for bouquets so far, one for how many bloomed flowers we've seen in a row — think of it as a streak."

```cpp
if (arr[i] <= mid) {
  current_flowers++;
  if (current_flowers >= k) {
    current_bouquets++;
    current_flowers = 0;
  }
}
```
*lines 20–25*

🎙️ "Walk the row left to right. If this flower bloomed on or before day `mid`, it's ready — streak goes up. The second the streak hits `k`, snip, that's a bouquet. Count it, and **reset the streak to zero** — those flowers are used up, they can't go in another bouquet."

```cpp
} else {
  current_flowers = 0;
}
```
*lines 26–28*

🎙️ "And if the flower hasn't bloomed yet? Streak dies. Back to zero. That one line is doing all the heavy lifting — it's what makes the flowers have to be next to each other. An un-bloomed flower is basically a wall in the middle of the row."

🖥️ Quick run-through on screen:
```
[1, 10, 3, 10, 2]   k = 1   mid = 3
 ✅  ❌   ✅  ❌   ✅   →  3 bouquets
```

---

### 5. The search

```cpp
int right  = *max_element(arr, arr+n);
int left   = *min_element(arr, arr+n);
int answer = right;
```
*lines 56–58*

🎙️ "Now, where do we search? Earliest day worth checking is the smallest bloom day — before that, nothing's open. Latest is the biggest bloom day — by then every flower is open, so waiting longer changes nothing."

```cpp
while (left <= right) {
  int mid = left + (right-left)/2;

  if (bouqeuetsFormed(arr,n,m,k,mid) >= m) {
    answer = mid;
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}
```
*lines 59–68*

🎙️ "Jump to the middle day and ask our counter: enough bouquets?

Yes? Great, save it — but maybe an even earlier day works, so throw away everything to the right and keep looking left.

No? Too early, not enough flowers are open yet. Throw away the left half and look later.

Every round cuts the days in half. When the loop finishes, `answer` is the earliest day that works."

```cpp
cout << answer << endl;
```
*line 70*

🎙️ "Print it. Done. 🌸"

---

### 6. Close

🎙️ "Speed-wise: we halve the days each round, and each check walks the garden once. Memory-wise, just two counters — nothing extra.

And here's the part worth remembering. Any time a problem asks for the smallest or largest something, and you can write a quick yes-or-no check that only flips once from no to yes — that's this exact same solution. Koko eating bananas, ship packages in D days, same thing wearing a different hat. Learn it once, get a bunch of problems for free."

```cpp
while (left <= right) {
    mid = left + (right - left) / 2;
    if (isFeasible(mid)) { answer = mid; right = mid - 1; }
    else                 { left = mid + 1; }
}
```

---

### 📋 Highlight cheat sheet

| Beat | Lines |
|---|---|
| Problem | 7–14 |
| The idea | — |
| `-1` case | 47–51 (zoom `1LL`) |
| Counter | 17–18 → 20–25 → 26–28 |
| Search | 56–58 → 59–68 → 70 |

### 🎬 Demo inputs

```
5              5
1 10 3 10 2    1 10 3 10 2
3              3
1              2
→ 3            → -1
```

*Heads up: the helper is spelled `bouqeuetsFormed`, and its `m` parameter is never used inside — the `>= m` check happens on line 62.*
