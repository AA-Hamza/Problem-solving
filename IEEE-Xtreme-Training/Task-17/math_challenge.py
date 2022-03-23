from math import factorial, pow
import math

def power(x, y, p) :
    res = 1     # Initialize result
 
    # Update x if it is more
    # than or equal to p
    x = x % p
     
    if (x == 0) :
        return 0
 
    while (y > 0) :
         
        # If y is odd, multiply
        # x with result
        if ((y & 1) == 1) :
            res = (res * x) % p
 
        # y must be even now
        y = y >> 1      # y = y/2
        x = (x * x) % p
         
    return res

class GFG:
    def nCr(self, n, r):
       
        # Base case
        if r > n: 
            return 0
           
        # C(n,r) = C(n,n-r) Complexity for this
        # code is lesser for lower n-r
        if n - r > r: 
            r = n - r
             
        # List to store smallest prime factor
        # of every number from 1 to n
        SPF = [i for i in range(n+1)]
        for i in range(4, n+1, 2):
           
            # set smallest prime factor of
            # all even numbers as 2
            SPF[i] = 2
     
        for i in range(3, n+1, 2): 
         
            if i*i > n:
                break
               
            # Check if i is prime
            if SPF[i] == i: 
                 
                # All multiples of i are composite
                # (and divisible by i) so add i to
                # their prime factorization getpow(j,i) times
                for j in range(i*i, n+1, i):
                    if SPF[j] == j:
                       
                        # set smallest prime factor
                        # of j to i only if it is
                        # not previously set
                        SPF[j] = i
         
         # dictionary to store power of each prime in C(n,r)
        prime_pow = {} 
         
        # For numerator count frequency
        # of each prime factor
        for i in range(r+1, n+1):
            t = i
             
            # Recursive division to
            # find prime factorization of i
            while t > 1:
                if not SPF[t] in prime_pow:
                    prime_pow[SPF[t]] = 1
                else:
                    prime_pow[SPF[t]] += 1
                t //= SPF[t]
         
        # For denominator subtract the
        # power of each prime factor
        for i in range(1, n-r+1): 
            t = i
             
            # Recursive division to
            # find prime factorization of i
            while t > 1: 
                prime_pow[SPF[t]] -= 1
                t //= SPF[t]
        ans = 1
        mod = 10**9 + 7
         
         # Use (a*b)%mod = (a%mod * b%mod)%mod
        for i in prime_pow:
           
            # pow(base,exp,mod) is used to
            # find (base^exp)%mod fast
            ans = (ans*(power(i, prime_pow[i], mod))) % mod
        return ans


def fac(n, k):
    # since C(n, k) = C(n, n - k)
    if(k > n - k):
        k = n - k
    # initialize result
    res = 1
    # Calculate value of
    # [n * (n-1) *---* (n-k + 1)] / [k * (k-1) *----* 1]
    for i in range(k):
        res = res * (n - i)
        res = res // (i + 1)
    return res

def _power(x, y):
    result = 1
    while (y > 0): 
        if (y % 2 == 0): 
        # y is even
          
            x = x * x
            y = y / 2
          
        else:
        # y isn't even
          
            result = result * x
            y = y - 1
          
      
    return result


def _fac(n, r):
     
    if (r > n):
        return 0
         
    m = 1000000007
    inv = [0 for i in range(r + 1)]
    inv[0] = 1;
    if(r+1>=2):
        inv[1] = 1;
 
    # Getting the modular inversion
    # for all the numbers
    # from 2 to r with respect to m
    # here m = 1000000007
    for i in range(2, r + 1):
        inv[i] = m - (m // i) * inv[m % i] % m
 
    ans = 1
 
    # for 1/(r!) part
    for i in range(2, r + 1):
        ans = ((ans % m) * (inv[i] % m)) % m
 
    # for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for i in range(n, n - r, -1):
        ans = ((ans % m) * (i % m)) % m
         
    return ans

t = int(input())
ob = GFG()
for _ in range(t):
    a, b, c = map(int, input().split())
    print(int( power(a, ob.nCr(b, c), (10**9+7)) ))

