# 🪙 Coin Change Algorithms (C++)

A C++ implementation comparing **Greedy**, **Dynamic Programming**, and **Hybrid** approaches to the classic Coin Change problem — with robust user input handling.

---

## 📁 Project Files

| File | Description |
|------|-------------|
| `coin_code.cpp` | Main C++ source file with input validation |
| `coin_change.html` | Interactive browser visualizer |
| `README.md` | This file |

---

## 🚀 Compile & Run (Windows PowerShell)

### Step 1 — Compile
```powershell
g++ coin_code.cpp -o coin_code.exe
```

### Step 2 — Run
```powershell
.\coin_code.exe
```

> ⚠️ Always use `.\coin_code.exe` not `coin_code.exe` in PowerShell.

---

## 🖥️ Sample Run

```
Enter number of coin denominations: 3
Enter 3 coin denominations (space separated): 1 3 4
Enter target amount: 6

Coins : 1 3 4
Amount: 6

Greedy result : 2 coins
DP     result : 2 coins
Hybrid result : 2 coins
```

---

## ⌨️ Input Rules

| Rule | ✅ Correct | ❌ Wrong |
|------|-----------|---------|
| Separate coins with spaces | `1 3 4` | `1,3,4` |
| Enter count as single number | `3` | `2,3` |
| Only positive integers for coins | `1 5 10` | `-1 0 5` |
| Amount must be non-negative | `6` | `-2` |

> The program will show an error and ask again if you enter invalid input — it will **not** crash.

---

## ⚙️ Algorithms

### 1. Greedy
Picks the **largest coin first** and keeps subtracting until the amount is zero.

```
Sort coins descending → pick largest → repeat
```

**Limitation:** Not always optimal for arbitrary coin sets.

> Example: Coins `{1, 3, 4}`, Amount `6`
> Greedy: 4 + 1 + 1 = **3 coins** ❌
> Optimal: 3 + 3 = **2 coins** ✅

---

### 2. Dynamic Programming (DP)
Builds a table `dp[0..amount]` bottom-up.

```
dp[0] = 0
For i from 1 to amount:
    For each coin c:
        dp[i] = min(dp[i], dp[i - c] + 1)
```

Always finds the **globally optimal** answer.

---

### 3. Hybrid
Runs both Greedy and DP, returns the **minimum** of the two.

```
hybrid = min(greedy_result, dp_result)
```

Always optimal — uses greedy as a fast check, DP as a correctness guarantee.

---

## ⏱️ Time & Space Complexity

| Algorithm | Time | Space | Always Optimal |
|-----------|------|-------|----------------|
| Greedy | O(n log n + n·A) | O(1) | ❌ No |
| Dynamic Programming | O(n · A) | O(A) | ✅ Yes |
| Hybrid | O(n · A) | O(A) | ✅ Yes |

> **n** = number of coin denominations &nbsp;|&nbsp; **A** = target amount

---

## 🔢 DP Table Example

**Input:** Coins = `{1, 3, 4}`, Amount = `6`

| Amount    | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-----------|---|---|---|---|---|---|---|
| Min Coins | 0 | 1 | 2 | 1 | 1 | 2 | 2 |

**Traceback:** `dp[6]` → coin `3` → `dp[3]` → coin `3` → `dp[0]`  
**Answer:** 3 + 3 = **2 coins**

---



