//LINEAR SEARCH
bool linear_search(int[] arr, int x) {
    for(int i=0; i<arr.length; i++) {
        if(arr[i] == x) {
            return true;
        }
    }
    return false;
}

//BINARY SEARCH
bool binary_search(int[] sorted, int x, int start, int end) {
    if(start > end) {
        return false;
    }

    if(arr[(end+start)/2] == x) return true;
    if(arr[(end+start)/2] > x) return binary_search(sorted, x, start, middle-1);
    if(arr[(end+start)/2] < x) return binary_search(sorted, x, middle+1, end);
}

//TERNARY SEARCH
bool ternarySearch(arr, x, left, right) {
    if(right < left) return false;

    int mid1 = (2*left + right)/3;
    int mid2 = (left + 2*right)/3;
    if(arr[mid1] == x || arr[mid2] == x) return true;

    if(arr[mid1] > x) return ternarySearch(arr, x, left, mid1-1);
    if(arr[mid2] > x) return ternarySearch(arr, x, mid1+1, mid2-1);

    return ternarySearch(arr, x, mid2+1, right);
}

//JUMP SEARCH
bool jumpSearch(int[] arr, int x) {
    int step = (int)Math.floor(Math.sqrt(arr.length));

    int prev = 0;
    int next = prev + step;
    while(arr[Math.min(next, n)-1] < x) {
        prev = next;
        next += step;
        if(prev > n)
            return false;
    }

    while(arr[prev] < x) {
        prev++;
        if(prev == Math.min(step, n))
            return false;
    }

    if(arr[prev] == x)
        return true;

    return false;
}

//"K" biggest element in an array
int randomized_select(arr, left, right, k) {
    if(left == right) return arr[left];
    q = randomized_partition(arr, left, right);
    int i = q - left + 1;

    if(i == k) return arr[q];

    if(i < k) return randomized_select(arr, left, q-1, k);

    return randomized_select(arr, q+1, right, k);
}
