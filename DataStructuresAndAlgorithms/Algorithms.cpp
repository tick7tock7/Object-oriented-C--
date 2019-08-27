//Searching algorithms
bool isFound(int[] arr, int x)
{
    bool found = false;
    for(int i=0; i<arr.length(); i++) {
        if(arr[i] == x)
        {
            found = true;
        }
    }
    return found;
}

bool isFound(int[] arr, int x)
{
    bool found = false;
    for(int i=0; i<arr.length(); i++) {
        for(int j=i; j<arr.length; j++) {
            if(arr[i] == x)
            {
                found = true;
            }
        }
    }
    return found;
}

bool isFound(int[] arr, int x)
{
    bool found = false;
    for(int i=0; i<arr.length(); i+=10) {
        for(int j=i; j<arr.length(); j++)
        {
            if(arr[j]==x) {
                found = true;
            }
        }
    }
    return found;
}

//Most frequent number in an array
{
    int most_frequent = arr[0];
    int frequency = 1;
    for(int i=0; i<arr.length(); i++) {
        int i_freq = 0;
        for(int j=0; j<arr.length(); j++){
            if(arr[i]==arr[j]) {
                i_freq++;
            }
        }
        if(i_freq > frequency) {
            frequency = i_freq;
            most_frequent = arr[i];
        }
    }
}
