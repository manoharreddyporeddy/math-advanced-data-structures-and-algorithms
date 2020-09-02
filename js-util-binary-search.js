
    let binary_search = (a, left = 0, right = a.length - 1, trgt = -1) => {
        // console.log(a, left, right, trgt);

        while (left <= right) {
            let mid = left + Math.trunc((right - left) / 2);
            // console.log("mid ", mid);
            if (trgt == a[mid]) return mid;
            else if (trgt > a[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    };
