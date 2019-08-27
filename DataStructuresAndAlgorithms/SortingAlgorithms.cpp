//BUBBLE SORT
void bubbleSort(int arr[], int n) {
    int i,j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//SELECTION SORT
void selectionSort(int arr[], int n)
{
    int i,j;
    for(j=0; j<n-1; j++) {
        int iMin = j;
        for(i=j+1; i<n; i++) {
            if(arr[i] < arr[iMin]) {
                iMin = i;
            }
        }

        if(iMin != j) {
            swap(arr[j], arr[iMin]);
        }
    }
}

//INSERTION SORT
void insertionSort(int arr[]) {
    for(int i=1; i<arr.length; i++){
        int key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

//MERGE SORT
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        mergeSort(arr, l, (l+r)/2);
        mergeSort(arr, (l+r)/2+1, r);
        merge(arr, l, m, r); //FUNCTION THAT MERGES TWO ARRAYS
    }
}

void merge(int arr[], int start, int middle, inr end) {
    int i=0;
    int j=0;
    int k=start;

    while(i<arr1.length; j<arr2.length) {

    }
}

//QUICK SORT
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, high);
    return i;
}

//COUNTING SORT
void countingSort(char arr[]) {
    char arr_copy[] = new char[arr.length];
    for(int i=0; i<arr.length; ++i) {
        arr_copy[i]  = arr[i];
    }
    int count[] = new int[256];
    for(int i=0; i<n; ++i) {
        count[arr[i]] = count[arr[i]]+1;
    }
    for(int i=1; i<=255; ++i) {
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--) {
        arr[count[arr_copy[i]]-1] = arr_copy[i];
        count[arr_copy[i]] = count[arr_copy[i]]-1;
    }
}

//----------------------------------------------------------------
//RANDOMIZED QUICK SORT

int random_partition(int arr[], int low, int high) {
    swap(arr, high, random(arr.length));
    partition(arr, low, high);
}
//----------------------------------------------------------------
