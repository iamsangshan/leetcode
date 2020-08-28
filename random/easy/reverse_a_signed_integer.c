/*
 *
 * Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 */

int reverse(int x){

    
    int num = 0;
    int sign = 0;
    
   
    while (x) {
        if (num > INT_MAX/10 || (num == INT_MAX && (x%10) > 7))
            return 0;
         if (num < INT_MIN/10 || (num == INT_MIN && (x%10) < -8))
            return 0;
        
        num = num * 10 + x % 10;
        x = x/10;
    }

   return num;
}
