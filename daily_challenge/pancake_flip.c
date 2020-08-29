

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Like bubble sort.
    
1. Loop through the elements, find the max value - this index is the k.
2. now do a pan cake flip at k. now do a flip at max (which is essentially reversing the whole array).
3. at the end of 2, max num will be at the end of the array.
4. repeat 1 and 2, but each time leave the sorted elements alone (i.e. max--)


note:
we dont need to do pan cake flip if k=0. just to the max flip.

*/

int findmaxindex (int *a, int size) {
    
    int maxindex = 0, i;
    
    if (!a)
        return 0;
    
    /* loop through each element and compare */
    for (i = 1; i < size; i++) {
        if (a[i] > a[maxindex])
            maxindex = i;
    }
    
    return maxindex;
}

void pancake_flip (int *a, int index) {
    
    int left = 0, right = index, tmp = 0;
    
    if (!a)
        return;
    
    while (left < right) {
        tmp = a [left];
        a[left] = a[right];
        a[right] = tmp;
        
        left++; right--;
    }
}

int* pancakeSort(int* A, int ASize, int* returnSize){
    
    int max = ASize-1;
    int maxindex = 0, flip_count = 0;
    
    /* allocate with maximum allowed */
    int *pancake_arr = malloc(10*ASize);
    

    while (max) {
        /* Loop through the array to find the maxnumindex from 0 to max */
        maxindex = findmaxindex(A, max);

        /* Do a pan cake flip at the maxnum's index K */
        if (maxindex != 0) { /* if maxnumindex is 0, no need to do pancake flip */
            pancake_flip(A, maxindex);
            pancake_arr[flip_count++] = maxindex;
        }

        /* reverse the array till max. can use same api */
        pancake_flip(A, max);
        pancake_arr[flip_count++] = max;

        /* decrement max-- */
        max--;

        /* Loop through the array till max ! = 0 */
        }

    *returnSize = flip_count;
    
    return pancake_arr;
}
