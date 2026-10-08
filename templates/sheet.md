# Hand sheet
## Number theory
- ### Number of Divisors

   - If the prime factorization of a number \(N\) is:

    $$
    N = p_1^{a_1} \times p_2^{a_2} \times \cdots \times p_k^{a_k}
    $$

   - Then the number of positive divisors of \(N\) is:

    $$
    \boxed{(a_1+1)(a_2+1)\cdots(a_k+1)}
    $$

  **Example:**

    $$
    N = 2^3 \times 3^2 \times 5^1
    $$

    Number of divisors:

    $$
    (3+1)(2+1)(1+1)=4\times3\times2=\boxed{24}
    $$

-----
- ### Numbers with Exactly `3` Divisors

  - A positive integer has exactly **3 divisors** if and only if it is the **square of a prime number**.

    $$
    \boxed{n=p^2}
    $$

       - where \(p\) is a prime number.

**Example:**

$$
4=2^2 \rightarrow \{1,2,4\}
$$

$$
9=3^2 \rightarrow \{1,3,9\}
$$

$$
25=5^2 \rightarrow \{1,5,25\}
$$

So, if a number has exactly **3 divisors**, it must be a **perfect square of a prime**.


----
- ### Number of Even Divisors

  - Suppose the prime factorization of \(N\) is:

    $$
    N = 2^a \times p_1^{a_1} \times p_2^{a_2}\times\cdots\times p_k^{a_k}
    $$

- Then the number of **even divisors** of \(N\) is:

$$
\boxed{a(a_1+1)(a_2+1)\cdots(a_k+1)}
$$

**Why?**

For a divisor to be even, it must contain at least one factor of \(2\).



**Example:**

$$
N=2^3\times3^2\times5
$$

Number of even divisors:

$$
3\times(2+1)\times(1+1)
=3\times3\times2
=\boxed{18}
$$

**Key Idea:**
An even divisor must have exponent of \(2\) **at least 1**.

----

- ### Counting Multiples in a Range

  - To count how many multiples of \(k\) are between \(1\) and \(n\):

$$
\boxed{\left\lfloor\frac{n}{k}\right\rfloor}
$$

**Example:**

  - How many multiples of \(7\) are between \(1\) and \(100\)?



$$
\left\lfloor\frac{100}{7}\right\rfloor
=\boxed{14}
$$

The multiples are:

$$
7,14,21,\ldots,98
$$
---
  - To count the number of multiples of \(`k`\) in the range \([`A`,`B`]\) work for any `k`:

     - **First multiple:**

        ```cpp
        //ceil(A / k) 
        int L = (A + k - 1) / k;
        ```

    - **Last multiple:**
      ```cpp
      // floor(B / k)
      int R = B / k;
      ```


- Therefore, the number of multiples is:
$$
\text{count}=R-L+1
$$


  

**Example:**

Count the multiples of \(7\) in \([10,98]\):

$$
\left\lceil\frac{10}{7}\right\rceil=2
$$

$$
\left\lfloor\frac{98}{7}\right\rfloor=14
$$

So:

$$
\text{count}=14-2+1=\boxed{13}
$$

The multiples are:

$$
14,21,28,\ldots,98
$$

**Key Idea:**
Use **Ceil** to find where the multiples start, and **Floor** to find where they end.


-----



- ### Trailing Zeros of \(n!\)

To count the trailing zeros of \(n!\):

```cpp
int ans = 0;

while (n > 0) {
    ans+=n/5;
    n/=5;
}
```

**Example: \(78!\)**

```text
n = 78
ans += 78 / 5  → ans = 15
n = 15

ans += 15 / 5  → ans = 18
n = 3

ans += 3 / 5   → ans = 18
n = 0
```

Therefore:

$$
\boxed{18}
$$

**Why `n /= 5`?**

It counts multiples of \(5\), then multiples of \(25\), then \(125\), etc.

$$
\boxed{
\text{ans}=
\left\lfloor\frac{n}{5}\right\rfloor+
\left\lfloor\frac{n}{25}\right\rfloor+
\left\lfloor\frac{n}{125}\right\rfloor+\cdots
}
$$


**Key Idea:**
Trailing zeros come from pairs of \(2 * 5=10\). Since factorials contain more factors of \(2\) than \(5\), we only need to count the factors of \(5\).


-----

