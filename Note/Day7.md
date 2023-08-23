### 求模积和
$$\sum_{i=1}^{n}\sum_{j=1}^{m} (n \bmod i) \times (m \bmod j) ,(i \ne j)$$

$$=\sum_{i=1}^{n}\left(nm-ni\lfloor\frac{m}{i}\rfloor-mi\lfloor\frac{n}{i}\rfloor+i^2\right)\lfloor\frac{n}{i}\rfloor\lfloor\frac{m}{i}\rfloor$$

### 求$1^2+2^2+ \dots + n^2$
$$=\frac{n(n+1)(2n+1)}{6}$$

### 求$1^3+2^3+ \dots + n^3$
$$=\left[\frac{n(n+1)}{2}\right]^2$$

### 求

$$\sum_{i=1}^ni(i+1)=\sum_{i=1}^n\frac{i(i+1)(i+2)-(i-1)i(i+1)}{3}$$

$$=\frac{n(n+1)(n+2)}{3}$$

$$\frac{n(n+1)(n+2)}{3}-\frac{n(n+1)}{2}=\frac{n(n+1)}{2}(\frac{n+2}{3}-\frac 12)$$

$$\frac{n(n+1)(n+2)}{3}-\frac{n(n+1)}{2}=\frac{n(n+1)}{2}(\frac{2n+1}3)$$

> 为什么可以裂项？

$$\frac{i(i+1)}{2}=\frac{i(i+1)(i+2)}{{6}}-\frac{(i-1)i(i+1)}{6}$$

$$\binom{i+1}{2}=\binom{i+2}{3}-\binom{i+1}{3}$$

$$\binom{n}{m}-\binom{n-1}{m}=\binom{n-1}{m-1}$$

$$\dfrac{a}{b}+\dfrac{c}{d} \geq \dfrac{(\sqrt{a}+\sqrt{c})^2}{b+d}$$