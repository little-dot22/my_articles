# Assignment 2
## 2.1 Exercises: 8
**Q:**
If a system of 3000 equations in 3000 unknowns can be solved by Gaussian elimination in 5 seconds on a given computer, how many back substitutions of the same size can be done per second?

**A:**
Elimination takes on the order of $\frac{2}{3}n^3$ operations and back substitution takes on the order of $n^2$. So we estimate the time for back substitution to be
$\frac{5*3000^2}{\frac{2}{3}*3000^3}=0.0025s$
## 2.1  Computer Problems: 1
**Q:**
Put together the code fragments in this section to create a MATLAB program for “naive” Gaussian elimination (meaning no row exchanges allowed). Use it to solve the systems of Exercise 2.

**A：**
**(a)**
code:
Gauss.m:

    function x = Gauss(n, a, b)
    for j = 1 : n-1
        if abs(a(j,j))<eps; error('zero pivot encountered'); end
        for i = j+1 : n
            mult = a(i,j)/a(j,j);
            for k = j+1:n
                a(i,k) = a(i,k) - mult*a(j,k);
            end
            b(i) = b(i) - mult*b(j);
        end
    end
    for i = n : -1 : 1
        for j = i+1 : n
            b(i) = b(i) - a(i,j)*x(j);
        end
        x(i) = b(i)/a(i,i);
    end
main.m:

    a = [2 -2 -1;4 1 -2;-2 1 -1];
    b = [-2 1 -3];
    Gauss(3, a, b)
results:

    ans =

        1     1     2
**(b)**
code: 
Gauss.m: same as (a)
main.m:

    a = [1 2 -1;0 3 1;2 -1 1];
    b = [2 4 2];
    Gauss(3, a, b)
results:

    ans =

        1     1     1
**(c)**
code: 
Gauss.m: same as (a)
main.m:

    a = [2 1 -4;1 -1 1;-1 3 -2];
    b = [-7 -2 6];
    Gauss(3, a, b)
results:

    ans =

        -1     3     2
## 2.2 Exercises: 6
**Q:**
Given the 1000 × 1000 matrix A, your computer can solve the 500 problems $A_x = b_1,..., A_x = b_{500}$ in exactly one minute, using A = LU factorization methods. How much of the minute was the computer working on the A = LU factorization? Round your answer to the nearest second.

**A:**
The approximate number of operations with the LU approach is $\frac{2}{3}n^3 + 2kn^2$ which includes $2kn^2$ operations for back substitutions and $\frac{2}{3}n^3$ operations for LU factorization. So, the time for LU factorization is: $60*\frac{\frac{2}{3}n^3}{\frac{2}{3}n^3+2kn^2}=24s$
## 2.2 Computer Problems: 1
**Q:**
Use the code fragments for Gaussian elimination in the previous section to write a MATLAB script to take a matrix A as input and output L and U. No row exchanges are allowed—the program should be designed to shut down if it encounters a zero pivot. Check your program by factoring the matrices in Exercise 2.

**A:**
**(a)**
code:
LU.m:

    function[L, U] = LU(n, a)
    L = ones(1, n);
    L = diag(L);
    for j = 1 : n-1
        if abs(a(j,j))<eps; error('zero pivot encountered'); end
        for i = j+1 : n
            mult = a(i,j)/a(j,j);
            L(i,j) = mult;
            for k = j+1:n
                a(i,k) = a(i,k) - mult*a(j,k);
            end
        end
    end
    for i = 2 : n
        for j = 1 : i-1
            a(i,j) = 0;
        end
    end
    U=a;
main.m:

    a = [3 1 2;6 3 4;3 1 5];
    [L,U] = LU(3,a)
results:

    L =

        1     0     0
        2     1     0
        1     0     1


    U =

        3     1     2
        0     1     0
        0     0     3
**(b)**
code: 
LU.m: same as (a)
main.m:

    a = [4 2 0;4 4 2;2 2 3];
    [L,U] = LU(3,a)
results:

    L =

        1.0000         0         0
        1.0000    1.0000         0
        0.5000    0.5000    1.0000


    U =

        4     2     0
        0     2     2
        0     1     2
**(c)**
code:
LU.m: same as (a)
main.m:

    a = [1 -1 1 2;0 2 1 0;1 3 4 4;0 2 1 -1];
    [L,U] = LU(4,a)
results:

    L =

        1     0     0     0
        0     1     0     0
        1     2     1     0
        0     1     0     1


    U =

        1    -1     1     2
        0     2     1     0
        0     0     1     2
        0     0     0    -1
## 2.3 Exercises: 5
**Q:**
Find the relative forward and backward errors and error magnification factor for the following approximate solutions of the system $x_1−2x_2=3,3x_1−4x_2=7: $
(a) [−2,−4]
(b) [−2,−3]
(c) [0,−2] 
(d) [−1,−1] 
(e) What is the condition number of the coefficient matrix?

**A:**
The correct solution is x = [1, -1], $||b||_{\infty}=7$, $||x||_{\infty}=1$
**(a)**
The backward error is
$$||b-Ax_a||_{\infty} =\left|\left|\left[\begin{matrix}3 \\7  \\\end{matrix}\right]-\left[\begin{matrix}1 & -2\\3 & -4\\\end{matrix}\right]\left[\begin{matrix}-2\\-4\\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}-3 \\-3  \\\end{matrix}\right]\right|\right|_\infty=3.$$
So, the relative backward error is $\frac{3}{7}.$
The forward error is
$$||x-x_a||_{\infty} =\left|\left|\left[\begin{matrix}1 \\-1 \\\end{matrix}\right]-\left[\begin{matrix}-2 \\-4 \\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}3 \\3  \\\end{matrix}\right]\right|\right|_\infty=3.$$
The forward error is backward error is 3.
The error magnification factor is $\frac{3}{\frac{3}{7}}=7$.
**(b)**
The backward error is
$$||b-Ax_a||_{\infty} =\left|\left|\left[\begin{matrix}3 \\7  \\\end{matrix}\right]-\left[\begin{matrix}1 & -2\\3 & -4\\\end{matrix}\right]\left[\begin{matrix}-2\\-3\\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}-1 \\1  \\\end{matrix}\right]\right|\right|_\infty=1.$$
So, the relative backward error is $\frac{1}{7}.$
The forward error is
$$||x-x_a||_{\infty} =\left|\left|\left[\begin{matrix}1 \\-1 \\\end{matrix}\right]-\left[\begin{matrix}-2 \\-3 \\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}3 \\2  \\\end{matrix}\right]\right|\right|_\infty=3.$$
The forward error is backward error is 3.
The error magnification factor is $\frac{3}{\frac{1}{7}}=21$.
**(c)**
The backward error is
$$||b-Ax_a||_{\infty} =\left|\left|\left[\begin{matrix}3 \\7  \\\end{matrix}\right]-\left[\begin{matrix}1 & -2\\3 & -4\\\end{matrix}\right]\left[\begin{matrix}0\\-2\\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}-1 \\-1  \\\end{matrix}\right]\right|\right|_\infty=1.$$
So, the relative backward error is $\frac{1}{7}.$
The forward error is
$$||x-x_a||_{\infty} =\left|\left|\left[\begin{matrix}1 \\-1 \\\end{matrix}\right]-\left[\begin{matrix}0 \\-2 \\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}1 \\1  \\\end{matrix}\right]\right|\right|_\infty=1.$$
The forward error is backward error is 1.
The error magnification factor is $\frac{1}{\frac{1}{7}}=7$.
**(d)**
The backward error is
$$||b-Ax_a||_{\infty} =\left|\left|\left[\begin{matrix}3 \\7  \\\end{matrix}\right]-\left[\begin{matrix}1 & -2\\3 & -4\\\end{matrix}\right]\left[\begin{matrix}-1\\-1\\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}2 \\6  \\\end{matrix}\right]\right|\right|_\infty=6.$$
So, the relative backward error is $\frac{6}{7}.$
The forward error is
$$||x-x_a||_{\infty} =\left|\left|\left[\begin{matrix}1 \\-1 \\\end{matrix}\right]-\left[\begin{matrix}-1 \\-1 \\\end{matrix}\right]\right|\right|_\infty=\left|\left|\left[\begin{matrix}2 \\0  \\\end{matrix}\right]\right|\right|_\infty=2.$$
The forward error is backward error is 2.
The error magnification factor is $\frac{2}{\frac{6}{7}}=\frac{7}{3}$.
**(e)**
$$cond(A)=||A||\cdot||A^{-1}||=\left|\left|\left[\begin{matrix}
    1&-2\\3&-4
\end{matrix}\right]\right|\right|\cdot\left|\left|\left[\begin{matrix}
    -2&1\\-1.5&0.5
\end{matrix}\right]\right|\right|=21$$
## 2.3 Computer Problems: 1
**Q:**
For the n × n matrix with entries $A_{ij} = 5/(i + 2 j − 1)$, set x = [1,...,1]T and b = Ax. Use the MATLAB program from Computer Problem 2.1.1 or MATLAB’s backslash command to compute xc, the double precision computed solution. Find the infinity norm of the forward error and the error magnification factor of the problem Ax = b, and compare it with the condition number of A: (a) n = 6 (b) n = 10.

**A:**
**(a)**
code:
create_A_b.m:

    function [A, b] = create_A_b(n)
    A = zeros(n);
    for i = 1 : n
        for j = 1 : n
            A(i, j) = 5/(i+2*j-1);
        end
    end
    x = ones(n, 1);
    b = A*x;
condition_number.m:

    function x = condition_number(n, A)
    B = inv(A);
    tem = 0;
    max_a = 0;
    max_b = 0;
    for i = 1 : n
        for j = 1 : n
            tem = tem + abs(A(i, j));
        end
        if tem>max_a
            max_a = tem;
        end
        tem = 0;
    end
    for i = 1 : n
        for j = 1 : n
            tem = tem + abs(B(i, j));
        end
        if tem>max_b
            max_b = tem;
        end
        tem = 0;
    end
    x = max_a*max_b;
main.m:

    format long
    n = 6;
    [A, b] = create_A_b(n);
    x = ones(n,1);
    xa = A \ b;
    FE = max(abs(xa - x));
    BE = max(abs(b-A*xa));
    RFE = FE/1;
    RBE = BE/max(b);
    EMF = RFE/RBE;
    cond = condition_number(n, A);
    FE
    EMF
    cond
results:

    FE =

        4.994282765125035e-11


    EMF =

        6.888251562500000e+05


    cond =

        7.034201393053748e+07
**(b)**
code:
main.m:

    format long
    n = 10;
    [A, b] = create_A_b(n);
    x = ones(n,1);
    xa = A \ b;
    FE = max(abs(xa - x));
    BE = max(abs(b-A*xa));
    RFE = FE/1;
    RBE = BE/max(b);
    EMF = RFE/RBE;
    cond = condition_number(n, A);
    FE
    EMF
    cond
results:

    FE =

        9.656930505175243e-04


    EMF =

        7.961475491035258e+12


    cond =

        1.313370644644960e+14
## 2.4 Exercises: 2
**Q:**
 Find the PA = LU factorization (using partial pivoting) of the following matrices:
(a)$\left[\begin{matrix}
    1&1&0\\2&1&-1\\-1&1&-1
\end{matrix}\right]$
(b)$\left[\begin{matrix}
    0&1&3\\2&1&1\\-1&-1&2
\end{matrix}\right]$
(c)$\left[\begin{matrix}
    1&2&-3\\2&4&2\\-1&0&3
\end{matrix}\right]$
(d)$\left[\begin{matrix}
    0&1&0\\1&0&2\\-2&1&0
\end{matrix}\right]$

**A:**
**(a)**
First, rows 1 and 2 need to be exchanged, according to partial pivoting:
$$ P=\left[\begin{matrix}
    0&1&0\\1&0&0\\0&0&1
\end{matrix}\right] $$
$\left[\begin{matrix}
    1&1&0\\2&1&-1\\-1&1&-1
\end{matrix}\right]\longrightarrow$$\left[\begin{matrix}
    2&1&-1\\1&1&0\\-1&1&-1
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&1&-1\\\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\-1&1&-1
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&1&-1\\\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\-\frac{1}{2}&\frac{3}{2}&-\frac{3}{2}
\end{matrix}\right]$
Then, rows 2 and 3 need to be exchanged:
$$ P=\left[\begin{matrix}
    0&1&0\\0&0&1\\1&0&0
\end{matrix}\right] $$
$\longrightarrow\left[\begin{matrix}
    2&1&-1\\-\frac{1}{2}&\frac{3}{2}&-\frac{3}{2}\\\frac{1}{2}&\frac{1}{2}&\frac{1}{2}
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&1&-1\\-\frac{1}{2}&\frac{3}{2}&-\frac{3}{2}\\\frac{1}{2}&\frac{1}{3}&1
\end{matrix}\right]$
So,
$$\left[\begin{matrix}
    0&1&0\\0&0&1\\1&0&0
\end{matrix}\right]\left[\begin{matrix}
    1&1&0\\2&1&-1\\-1&1&-1
\end{matrix}\right]=\left[\begin{matrix}
    1&0&0\\-\frac{1}{2}&1&0\\\frac{1}{2}&\frac{1}{3}&1
\end{matrix}\right]\left[\begin{matrix}
    2&1&-1\\0&\frac{3}{2}&-\frac{3}{2}\\0&0&1
\end{matrix}\right]$$
**(b)**
First, rows 1 and 2 need to be exchanged, according to partial pivoting:
$$ P=\left[\begin{matrix}
    0&1&0\\1&0&0\\0&0&1
\end{matrix}\right] $$
$\left[\begin{matrix}
    0&1&3\\2&1&1\\-1&-1&2
\end{matrix}\right]\longrightarrow$$\left[\begin{matrix}
    2&1&1\\0&1&3\\-1&-1&2
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&1&1\\0&1&3\\-\frac{1}{2}&-\frac{1}{2}&\frac{5}{2}
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&1&1\\0&1&3\\-\frac{1}{2}&-\frac{1}{2}&4
\end{matrix}\right]$
So, 
$$ \left[\begin{matrix}
    0&1&0\\1&0&0\\0&0&1
\end{matrix}\right]\left[\begin{matrix}
    0&1&3\\2&1&1\\-1&-1&2
\end{matrix}\right]=\left[\begin{matrix}
    1&0&0\\0&1&0\\-\frac{1}{2}&-\frac{1}{2}&1
\end{matrix}\right]\left[\begin{matrix}
    2&1&1\\0&1&3\\0&0&4
\end{matrix}\right] $$
**(c)**
First, rows 1 and 2 need to be exchanged, according to partial pivoting:
$$ P=\left[\begin{matrix}
    0&1&0\\1&0&0\\0&0&1
\end{matrix}\right] $$
$\left[\begin{matrix}
    1&2&-3\\2&4&2\\-1&0&3
\end{matrix}\right]\longrightarrow$$\left[\begin{matrix}
    2&4&2\\1&2&-3\\-1&0&3
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&4&2\\\frac{1}{2}&0&-4\\-1&0&3
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    2&4&2\\\frac{1}{2}&0&-4\\-\frac{1}{2}&2&4
\end{matrix}\right]$
Then, rows 2 and 3 need to be exchanged:
$$ P=\left[\begin{matrix}
    0&1&0\\0&0&1\\1&0&0
\end{matrix}\right] $$

$\longrightarrow\left[\begin{matrix}
    2&4&2\\-\frac{1}{2}&2&4\\\frac{1}{2}&0&-4
\end{matrix}\right]$
So, 
$$\left[\begin{matrix}
    0&1&0\\0&0&1\\1&0&0
\end{matrix}\right]\left[\begin{matrix}
    1&2&-3\\2&4&2\\-1&0&3
\end{matrix}\right]=\left[\begin{matrix}
    1&0&0\\-\frac{1}{2}&1&0\\\frac{1}{2}&0&1
\end{matrix}\right]\left[\begin{matrix}
    2&4&2\\0&2&4\\0&0&-4
\end{matrix}\right]$$
**(d)**
First, rows 1 and 3 need to be exchanged, according to partial pivoting:
$$ P=\left[\begin{matrix}
    0&0&1\\0&1&0\\1&0&0
\end{matrix}\right] $$
$\left[\begin{matrix}
    0&1&0\\1&0&2\\-2&1&0
\end{matrix}\right]\longrightarrow$$\left[\begin{matrix}
    -2&1&0\\1&0&2\\0&1&0
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    -2&1&0\\-\frac{1}{2}&\frac{1}{2}&2\\0&1&0
\end{matrix}\right]$
Then, rows 2 and 3 need to be exchanged:
$$ P=\left[\begin{matrix}
    0&0&1\\1&0&0\\0&1&0
\end{matrix}\right] $$

$\longrightarrow\left[\begin{matrix}
    -2&1&0\\0&1&0\\-\frac{1}{2}&\frac{1}{2}&2
\end{matrix}\right]\longrightarrow\left[\begin{matrix}
    -2&1&0\\0&1&0\\-\frac{1}{2}&-\frac{1}{2}&2
\end{matrix}\right]$
So, 
$$\left[\begin{matrix}
    0&0&1\\1&0&0\\0&1&0
\end{matrix}\right]\left[\begin{matrix}
    0&1&0\\1&0&2\\-2&1&0
\end{matrix}\right]=\left[\begin{matrix}
    1&0&0\\0&1&0\\-\frac{1}{2}&-\frac{1}{2}&1
\end{matrix}\right]\left[\begin{matrix}
    -2&1&0\\0&1&0\\0&0&2
\end{matrix}\right]$$