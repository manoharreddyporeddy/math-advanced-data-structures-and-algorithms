/*
Logic for Range update


=====
NOTE: This is in progress.
=====


----
Assume
    0  0  0  0  0  0  0  0  0  0  (array)
so  0  0  0  0  0  0  0  0  0  0  (cumulative sums, sum[i])

Now +5 to [3..7]
    0  0  0  5  5  5  5  5  0  0  (array)
    0  0  0  5 10 15 20 25 25 25  (desired cumulative sums, sum[i]s)
----
 0  0  0  5 10 15 20 25  25  25  (desired cumulative sums, sum[i]s)
is
 0  1  2  3  4  5  6  7   8   9  (index i)
*0  0  0  5  5  5  5  5   0   0  (X1)
+0  0  0 10 10 10 10 10 -25 -25  (X2)
where, sum[i] = i * X1[i] - X2[i]
----
*0  0  0  5  5  5  5  5   0   0  (X1)
+0  0  0 10 10 10 10 10 -25 -25  (X2)
is
*0  0  0 +5  0  0  0  0  -5   0  (X1_sum)
+0  0  0 10  0  0  0  0 -35   0  (X2_sum)
where, sum[i] = i * X1_sum[i] - X1_sum[i]
is (in general form)
 0  1  2       3  4  5  6  7    8   9  (index i)
.              i           j  j+1
*0  0  0      +V  0  0  0  0   -V   0  (X1_sum)
+0  0  0 (i-1)*V  0  0  0  0 -j*V   0  (X2_sum)
where, sum[i] = i * X1_sum[i] - X1_sum[i]
----

*/
