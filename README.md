# usaco-guide
farmer john 👨‍🌾 sharing a fuji 🍎 with bessie the cow 🐄

## Modular Inverse
In modular arithmetic, "dividing by 2" is not the same as "integer-dividing by 2". 

This is because a modular residue `r = R (mod M)` carries no guarantee that `r` is even (even if `R` was); and the integer division `r/2` will truncate or give the wrong result whenever `r` is odd (or if `R` "wrapped around" more than once modulo `M`).

The only guaranteed way to compute `R/2 (mod M)` from `r = R (mod M)` is to multiple by the modular inverse of 2, which is `R/2 (mod M) = r x 2^{-1} (mod M)`. 

Since `M = 1_000_000_007` is prime, `2^{-1} = 500_000_004 (mod M)`. A more generalized way to calculate division of any number in modular setting is `inv(x) = pow(x, mod-2, mod)`.

[Errichto](https://codeforces.com/profile/Errichto) shared a very useful and generalized video on [Computations Modulo P in Competitive Programming](https://youtu.be/-OPohCQqi_E?si=rTvnfOQR-EzMqAFH).

[CP-Algo/Modular Multiplicative Inverse](https://cp-algorithms.com/algebra/module-inverse.html)

[USACO-Guide/Modular Arithmetic](https://usaco.guide/gold/modular?lang=cpp#modular-inverse)

Exercise: [CSES Two Sets II](https://cses.fi/problemset/task/1093/).