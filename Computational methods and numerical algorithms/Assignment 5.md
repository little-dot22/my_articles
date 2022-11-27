# Assignment 5
## 4.1 Exercises: 1 (a)
**Q:**
Solve the normal equations to find the least squares solution and 2-norm error for the following inconsistent systems:
(a)
$$\left[
\begin{matrix}
1 & 2\\
0 & 1\\
2 & 1
\end{matrix}
\right]
\left[
\begin{matrix}
x_1\\
x_2
\end{matrix}
\right]=
\left[
\begin{matrix}
3\\
1\\
1
\end{matrix}
\right]
$$

**A:**
The components of the normal equations are
$$A^TA=\left[\begin{matrix}1&0&2\\2&1&1\end{matrix}\right]\left[\begin{matrix}1&2\\0&1\\2&1\end{matrix}\right]=\left[\begin{matrix}5&4\\4&6\end{matrix}\right]$$
$$A^Tb=\left[\begin{matrix}1&0&2\\2&1&1\end{matrix}\right]\left[\begin{matrix}3\\1\\1\end{matrix}\right]=\left[\begin{matrix}5\\8\end{matrix}\right]$$
The normal equations
$$\left[\begin{matrix}5&4\\4&6\end{matrix}\right]\left[\begin{matrix}x_1\\x_2\end{matrix}\right]=\left[\begin{matrix}5\\8\end{matrix}\right]$$
$$(\overline{x_1},\overline{x_2})=(-\frac{1}{7},\frac{10}{7})$$
Substituting the least squares solution into the original problem yields
$$\left[\begin{matrix}1&2\\0&1\\2&1\end{matrix}\right]\left[\begin{matrix}-\frac{1}{7}\\\frac{10}{7}\end{matrix}\right]=\left[\begin{matrix}\frac{18}{7}\\\frac{10}{7}\\\frac{8}{7}\end{matrix}\right]$$
To measure our success at fitting the data, we calculate the residual of the least squares solution $\overline{x}$ as
$$r=b-A\overline{x}=\left[\begin{matrix}3\\1\\1\end{matrix}\right]-\left[\begin{matrix}\frac{19}{7}\\\frac{10}{7}\\\frac{8}{7}\end{matrix}\right]=\left[\begin{matrix}\frac{2}{7}\\-\frac{3}{7}\\-\frac{1}{7}\end{matrix}\right]$$
$$||r||_2=\sqrt{(\frac{2}{7})^2+(-\frac{3}{7})^2+(-\frac{1}{7})^2}=\frac{\sqrt{14}}{7}$$

## 4.1 Computer Problems: 1
**Q:**
Form the normal equations, and compute the least squares solution and 2-norm error for the following inconsistent systems:
$$(a)\left[\begin{matrix}3&-1&2\\4&1&0\\-3&2&1\\1&1&5\\-2&0&3\end{matrix}\right]\left[\begin{matrix}x_1\\x_2\\x_3\end{matrix}\right]=\left[\begin{matrix}10\\10\\-5\\15\\0\end{matrix}\right]$$
$$(b)\left[\begin{matrix}4&2&3&0\\-2&3&-1&1\\1&3&-4&2\\1&0&1&-1\\3&1&3&-2\end{matrix}\right]\left[\begin{matrix}x_1\\x_2\\x_3\\x_4\end{matrix}\right]=\left[\begin{matrix}10\\0\\2\\0\\5\end{matrix}\right]$$

**A:**
**(a)**
**code:**

    A = [3,-1,2;4,1,0;-3,2,1;1,1,5;-2,0,3];
    b = [10;10;-5;15;0];
    x = (A'*A)\(A'*b)
    r = A*x-b;
    norm = norm(r,2)
**results:**

    x =

        2.5246
        0.6616
        2.0934


    norm =

        2.4135
**(b)**
**code:**

    A = [4,2,3,0;-2,3,-1,1;1,3,-4,2;1,0,1,-1;3,1,3,-2];
    b = [10;0;2;0;5];
    x = (A'*A)\(A'*b)
    r = A*x-b;
    norm = norm(r,2)
**results:**

    x =

        1.2739
        0.6885
        1.2124
        1.7497


    norm =

        0.8256
## 4.3 Exercises: 2(a)
**Q:**
Apply classical Gram–Schmidt orthogonalization to find the full QR factorization of the following matrices:
$$(a)\left[\begin{matrix}4&0\\3&1\end{matrix}\right]$$

**A:**
$$y_1=A_1=\left[\begin{matrix}4\\3\end{matrix}\right]$$
$$r_{11}=||y_1||_2=\sqrt{4^2+3^2}=5$$
$$q_1=\frac{y_1}{||y_1||_2}=\left[\begin{matrix}\frac{4}{5}\\\frac{3}{5}\end{matrix}\right]$$
$$y_2=A_2-q_1q_1^TA_2=\left[\begin{matrix}0\\1\end{matrix}\right]-\left[\begin{matrix}\frac{4}{5}\\\frac{3}{5}\end{matrix}\right]\frac{3}{5}=\left[\begin{matrix}-\frac{12}{25}\\\frac{16}{25}\end{matrix}\right]$$
$$q_2=\frac{y_2}{||y_2||_2}=\frac{5}{4}\left[\begin{matrix}-\frac{12}{25}\\\frac{16}{25}\end{matrix}\right]=\left[\begin{matrix}-0.6\\0.8\end{matrix}\right]$$
$$r_{12}=q_1^TA_2=0.6, r_{22}=||y_2||_2=0.8$$
$$A=\left[\begin{matrix}0.8&-0.6\\0.6&0.8\end{matrix}\right]\left[\begin{matrix}5&0.6\\0&0.8\end{matrix}\right]=QR$$

## 4.3 Exercises: 6(a)
**Q:**
Apply Householder reflectors to find the full QR factorization of the matrices in Exercise 2.
$$(a)\left[\begin{matrix}2&3\\-2&-6\\1&0\end{matrix}\right]$$

**A:**
We need to find a Householder reflector that moves the first column x = [2,-2,1] to the vector $w = [||x||_2,0,0]$. Set v = w − x = [3,0,0]−[2,-2,1]=[1,2,−1]. Referring to Theorem 4.4, we have
$$H_1=\left[\begin{matrix}1&0&0\\0&1&0\\0&0&1\end{matrix}\right]-\frac{2}{6}\left[\begin{matrix}1&2&-1\\2&4&-2\\-1&-2&1\end{matrix}\right]=\left[\begin{matrix}\frac{2}{3}&-\frac{2}{3}&\frac{1}{3}\\-\frac{2}{3}&-\frac{1}{3}&\frac{2}{3}\\\frac{1}{3}&\frac{2}{3}&\frac{2}{3}\end{matrix}\right]$$
$$H_1A=\left[\begin{matrix}\frac{2}{3}&-\frac{2}{3}&\frac{1}{3}\\-\frac{2}{3}&-\frac{1}{3}&\frac{2}{3}\\\frac{1}{3}&\frac{2}{3}&\frac{2}{3}\end{matrix}\right]\left[\begin{matrix}2&3\\-2&-6\\1&0\end{matrix}\right]=\left[\begin{matrix}3&3\\0&-6\\0&0\end{matrix}\right]$$
$$\left[\begin{matrix}2&3\\-2&-6\\1&0\end{matrix}\right]=\left[\begin{matrix}\frac{2}{3}&-\frac{2}{3}&\frac{1}{3}\\-\frac{2}{3}&-\frac{1}{3}&\frac{2}{3}\\\frac{1}{3}&\frac{2}{3}&\frac{2}{3}\end{matrix}\right]\left[\begin{matrix}3&6\\0&0\\0&-3\end{matrix}\right]$$
$$\left[\begin{matrix}0&-1\\-1&0\end{matrix}\right]\left[\begin{matrix}0&0\\0&-3\end{matrix}\right]=\left[\begin{matrix}0&3\\0&0\end{matrix}\right]$$
$$H_2H_1A=\left[\begin{matrix}1&0&0\\0&0&-1\\0&-1&0\end{matrix}\right]\left[\begin{matrix}\frac{2}{3}&-\frac{2}{3}&\frac{1}{3}\\-\frac{2}{3}&-\frac{1}{3}&\frac{2}{3}\\\frac{1}{3}&\frac{2}{3}&\frac{2}{3}\end{matrix}\right]A=\left[\begin{matrix}3&6\\0&3\\0&0\end{matrix}\right]$$
$$A=H_1H_2\left[\begin{matrix}3&6\\0&3\\0&0\end{matrix}\right]=\left[\begin{matrix}\frac{2}{3}&-\frac{1}{3}&\frac{2}{3}\\-\frac{2}{3}&-\frac{2}{3}&\frac{1}{3}\\\frac{1}{3}&-\frac{2}{3}&-\frac{2}{3}\end{matrix}\right]\left[\begin{matrix}3&6\\0&3\\0&0\end{matrix}\right]=QR$$

## 4.3 Computer Problems: 1
**Q:**
Write a Matlab program that implements classical Gram–Schmidt to find the reduced QR factorization. Check your work by comparing factorizations of the matrices in Exercise 1 with the Matlab qr(A,0) command or equivalent. The factorization is unique up to signs of the entries of Q and R.

**A:**
**code:**
QR.m:

    function [Q,R]=QR(A,m,n)
    Q=zeros(m,n);
    R=zeros(n,n);
    for j=1:n
        y=A(:,j);
        for i=1:j-1
            R(i,j)=Q(:,i)'*A(:,j);
            y=y-R(i,j)*Q(:,i);
        end
        R(j,j)=norm(y,2);
        Q(:,j)=y./R(j,j);
    end
main.m:

    A=[1,-4;2,3;2,2];
    [Q,R]=QR(A,3,2)
    [x,y]=qr(A)
**results；**


    Q =

        0.3333   -0.9333
        0.6667    0.3333
        0.6667    0.1333


    R =

        3.0000    2.0000
            0    5.0000


    x =

    -0.3333    0.9333   -0.1333
    -0.6667   -0.3333   -0.6667
    -0.6667   -0.1333    0.7333


    y =

        -3    -2
        0    -5
        0     0
The results calculated by Classical Gram–Schmidt orthogonalization is different from full QR factorization.

## 4.3 Computer Problems: 3
**Q:**
Repeat Computer Problem 1, but implement Householder reflections.

**A:**
**code:**
HH.m:

    function R=HH(A)
    [m,n]=size(A);
    a=zeros(1,n);
    b=zeros(1,n);
    c=zeros(1,n);
    v=zeros(m,n);
    e=eye(m,n);
    for i=1:n
        a(i)=-1*sign(A(i,i))*sqrt(sum(A(i:m,i).*A(i:m,i)));
        v(:,i)=[zeros(i-1,1);A(i:m,i)]-a(i).*e(:,i);
        b(i)=v(:,i)'*v(:,i);
        if b(i)==0
            continue; 
        end
        for j=i:n
            c(j)=v(:,i)'*A(:,j);
            A(:,j)=A(:,j)-(2*c(j)/b(i)).*v(:,i); 
        end
    end
    R=A;
main.m:

    A = [1,-4;2,3;2,2];
    R = HH(A)
    [X,Y] = qr(A)
**results：**

    R =

        -3    -2
        0    -5
        0     0


    X =

    -0.3333    0.9333   -0.1333
    -0.6667   -0.3333   -0.6667
    -0.6667   -0.1333    0.7333


    Y =

        -3    -2
        0    -5
        0     0