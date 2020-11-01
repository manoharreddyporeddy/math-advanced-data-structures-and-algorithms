function binomialCoefficient_nCr(n, r) {
    //  C(n, r)
    let prod = 1;

    // since C(n, r) = C(n, n-r)
    if (r > n - r) r = n - r;

    // calc [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1]
    for (let i = 0; i < r; ++i) {
        prod *= n - i;
        prod /= i + 1;
    }

    // console.log(prod);
    return prod;
}
