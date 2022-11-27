# Assignment 6
## 5.1 Computer Problems: 1
**Q:**
Make a table of the error of the three-point centered-difference formula for f 	 (0), where f (x) = sin x − cos x, with h = 10−1,...,10−12, as in the table in Section 5.1.2. Draw a plot of the results. Does the minimum error correspond to the theoretical expectation?

**A:**
**code:**

    format long
    table = zeros(12,3);
    for i = 1:12
        h = 10^(-i);
        table(i,1) = h;
        table(i,2) = ((sin(h)-cos(h))-(sin(-h)-cos(-h)))/(2*h);
        table(i,3) = cos(0)+sin(0)-table(i,2);
    end
    table
**results:**

    table =

    0.100000000000000   0.998334166468282   0.001665833531718
    0.010000000000000   0.999983333416665   0.000016666583335
    0.001000000000000   0.999999833333376   0.000000166666624
    0.000100000000000   0.999999998332890   0.000000001667110
    0.000010000000000   0.999999999984347   0.000000000015653
    0.000001000000000   0.999999999973245   0.000000000026755
    0.000000100000000   0.999999999473644   0.000000000526356
    0.000000010000000   0.999999999473644   0.000000000526356
    0.000000001000000   1.000000027229220  -0.000000027229220
    0.000000000100000   1.000000082740371  -0.000000082740371
    0.000000000010000   1.000000082740371  -0.000000082740371
    0.000000000001000   1.000033389431110  -0.000033389431110
The minimum error is 0.000000000015653 when $h=10^{-5}$. It corresponds to the theoretical expectation.

## 5.2 Computer Problems: 1(a, c)
**Q:**
Use the composite Trapezoid Rule with m = 16 and 32 panels to approximate the definite integral. Compare with the correct integral and report the two errors.
$$(a)\int_0^4\frac{xdx}{\sqrt{x^2+9}}$$
$$(c)\int_0^1xe^xdx$$

**A:**
**(a)**
**code:**

    h = 1/4;
    summ = 0;
    for i=1:15
        summ = summ+i*h/((i*h)^2+9)^(0.5);
    end
    summ = 2*summ + 4/5;
    0.5*h*summ
**results:**

    ans =

        1.998638181470279
The correct integral is 2, the error is $1.36*10^{-3}$.
**code:**

    h = 1/8;
    summ = 0;
    for i=1:31
        summ = summ+i*h/((i*h)^2+9)^(0.5);
    end
    summ = 2*summ + 4/5;
    0.5*h*summ
**results:**

    ans =

        1.999659678077911
The correct integral is 2, the error is $3.40*10^{-4}$.
**(c)**
**code:**

    h = 1/16;
    summ = 0;
    for i=1:15
        summ = summ+i*h*exp(i*h);
    end
    summ = 2*summ + exp(1);
    0.5*h*summ
**results:**

    ans =

        1.001444027067708
The correct integral is 1, the error is $1.44*10^{-3}$.
**code:**

    h = 1/32;
    summ = 0;
    for i=1:31
        summ = summ+i*h*exp(i*h);
    end
    summ = 2*summ + exp(1);
    0.5*h*summ
**results:**

    ans =

        1.000361038046700
The correct integral is 1, the error is $3.61*10^{-4}$.

## 5.5 Exercises: 3(a)
**Q:**
Approximate the integrals in Exercise 1, using n = 4 Gaussian Quadrature, and give the error.
$$(a)\int_{-1}^1(x^3+2x)$$

**A:**
$$\int_{-1}^1f(x)dx\approx c_1f(x_1)+c_2f(x_2)+c_3f(x_3)+c_4f(x_4)$$
$x_1=-x_4$
$x_2=-x_3$
$\because$ f(x) is an odd function
$\therefore f(x_1)=-f(x_4), f(x_2)=-f(x_3)$
$\because c_1=c_4, c_2=c_3$
$\therefore c_1f(x_1)+c_2f(x_2)+c_3f(x_3)+c_4f(x_4)=0$
$\therefore \int_{-1}^1f(x)dx\approx0$, the error is 0.