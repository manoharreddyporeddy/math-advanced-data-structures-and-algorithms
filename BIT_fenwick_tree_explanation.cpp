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
    0  0  0  5 10 15 20 25 25 25  (desired cumulative sums, sum[i])
----
 0  0  0  5 10 15 20 25  25  25  (desired cumulative sums, sum[i])
is
 0  1  2  3  4  5  6  7   8   9  (index i)
*0  0  0  5  5  5  5  5   0   0  (cumm1)
+0  0  0 10 10 10 10 10 -25 -25  (cumm2)
where, sum[i] = i * cumm1[i] - cumm2[i]
----
*0  0  0  5  5  5  5  5   0   0  (cumm1)
+0  0  0 10 10 10 10 10 -25 -25  (cumm2)
is
*0  0  0 +5  0  0  0  0  -5   0  (cumm1sum)
+0  0  0 10  0  0  0  0 -35   0  (cumm2sum)
where, sum[i] = i * cumm1sum[i] - cumm1sum[i]
is (in general form)
.              i           j j+1
*0  0  0      +V  0  0  0  0  -V   0  (cumm1sum)
+0  0  0 (i-1)*V  0  0  0  0 -35   0  (cumm2sum)
where, sum[i] = i * cumm1sum[i] - cumm1sum[i]
----

*/
