/* https://leetcode.com/problems/find-peak-element/solution/ */


/* assume a != b != c */
int maxnum (int a, int b, int c) {

    if (a >= b)
        return (a > c ? a : c);

    else
        return (b > c ? b : c);
}

int findPeakElement(int* nums, int numsSize){

    int a, b, c, peak;


    if (numsSize <= 1)
        return 0;

    if (numsSize == 2) {
        if (nums [0] > nums[1]) return 0;
        else return 1;
    }

    /* take first 3 elements */
    a = 0; b = 1; c = 2;


    while (c < numsSize) {
        /* check if the middle element is the maxnum (peak) */
        peak = maxnum(nums[a], nums[b], nums[c]);

        /* if yes, return the middle index. */
        if (peak == nums[b])
            return b;

        /* else, move the indices by 1 and continue till we reach end */
        a++; b++; c++;
    }


    if (b < numsSize) {
        peak = maxnum(nums[a], nums[b], 0);

        if (peak == nums[b])
            return b;
    }

    return 0;
}
