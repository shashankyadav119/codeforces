Q3
(A)
n1 = rnorm(30, mean=5, sd=1)
n2 = rnorm(30, mean=3, sd=1)
m1 = mean(n1)
m2 = mean(n2)
sd1 = sd(n1)
sd2 = sd(n2)
sprintf("mean of n1: %s",m1)
sprintf("sd of n1: %s",sd1)
sprintf("mean of n2: %s",m2)
sprintf("sd of n2: %s",sd2)
hist(n1)
hist(n2)
(B)
n1 = rexp(30, 1/5)
n2 = rexp(30, 1/3)
m1 = mean(n1)
m2 = mean(n2)
sd1 = sd(n1)
sd2 = sd(n2)
sprintf("mean of n1: %s",m1)
sprintf("sd of n1: %s",sd1)
sprintf("mean of n2: %s",m2)
sprintf("sd of n2: %s",sd2)
hist(n1)
hist(n2)
(C)
n1 = rnorm(500, mean=5, sd=1)
n2 = rnorm(500, mean=3, sd=1)
m1 = mean(n1)
m2 = mean(n2)
sd1 = sd(n1)
sd2 = sd(n2)
sprintf("mean of n1: %s",m1)
sprintf("sd of n1: %s",sd1)
sprintf("mean of n2: %s",m2)
sprintf("sd of n2: %s",sd2)
hist(n1)
hist(n2)
(D)
n1 = rexp(500, 1/5)
n2 = rexp(500, 1/3)
m1 = mean(n1)
m2 = mean(n2)
sd1 = sd(n1)
sd2 = sd(n2)
sprintf("mean of n1: %s",m1)
sprintf("sd of n1: %s",sd1)
sprintf("mean of n2: %s",m2)
sprintf("sd of n2: %s",sd2)
hist(n1)
hist(n2)