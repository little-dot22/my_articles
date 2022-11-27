# 9.14
# 注意
两个大作业50％，用matlab
# Chapter 0 Fundamentals
## 0.1 Evaluation a Polynomial
Q1：Evaluate $P(x) = 2x^4+4x^3-7x^2+5x-1$ at x=3.
- M1: 10次乘法，4次加法。
- M2：计算$x^4$时前面的乘方都算过了，所以乘法次数减少为7次。
- M3：$P(x)=-1+x[5-7x+4x^2+2x^3]=-1+x{5+x[-7+x(4+2x)]}$, 4次乘法，4次加法。
**优秀的算法可以减少乘法运算次数，提高效率。n次多项式用n次乘法n次加法。**
## 0.2 How Computer Stores a Real Number
小数的精度问题(IEEE):  
- Absolute Error: $|x_\varepsilon-x|$  
- Relative Error: $\frac{|x_\varepsilon-x|}{|x|}$
- Relative rounding Error: $\frac{|fl(x)-x|}{|x|}\leq\frac{1}{2}\varepsilon_{MACH}$, where $\varepsilon_{MACH} = 2^{-52}$
# Chapter 1 Solving Equations
## 1.1 The bisection method
$\because f(a)<0,f(b)>0$
$\therefore r\in(a,b)$,
$c = \frac{b-a}{2}$,
if $f(c)>0$,then $b=c$
if $f(c)<0$,then $a=c$
if $f(c)=0$,then $answer=c$
- Solution error: $|x_\epsilon-r|<\frac{b-a}{2^{n+1}}$
- Function evaluation: n+2 
- Correct with p decimal places if $|x_\epsilon-r|$<$0.5*10^{-p}$.
- According to 3, we need to evaluate n by using the equation.
## 1.2 Limits of Accuracy
Forward(Output) Error: $|r-x_a|$
Backward(Input) Error:$f(x_a)$
Backward error很小时，不一定能够控制Forward error很小。
算法迭代停止条件(or):
- forward error自身i+1与i比较。
- backward error的限制。
- 迭代次数。
# 9.21
# Chapter 2 System of Equation
## 2.1 Gaussian Elimination
Only evaluate the total number of mul/div.
## 2.2 The LU Factorization