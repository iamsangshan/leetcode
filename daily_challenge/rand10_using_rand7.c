// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

/* the idea here is to generate numbers from 1 to 10 with 
 * equal probability. 
 * 
 * Idea of a random num generator is to use a % 
 * 
 * going by that fact, 
 *
 * we can generate 1 by taking % of 11 (11%10 == 1)
 * 2 by % (12), 3 by % (13) and so on... 
 *
 * we need to generate from 1 to 10
 *
 * so for 9, we need % (19%10 == 9)
 
 */
 

/* Intuition
 *
 * Identify the min num of times you can call rand7() to generate nums from 1 to 10.
 *
 * 2 times
 *
 * Do Rejection Sampling.
 *
 * Each num 1 to 10 occurs in this range at least once. by %. 
 * Find the distribution such that there are less number of rejection and equal probability distribution
 *
 * from 1 to 49 (rand7() * rand7())
 *
 * 1, 11, 21, 31, 41 - 5 times for 1 (when %10)
 * 2, 12, 22, 32, 42 - 5 times for 2 and so on ...
 *
 * 9, 19, 29, 39, 49 - 5 times for 9
 *
 * but
 * 10, 20, 30, 40  - 4 times for 10
 *
 * so to make it even ...
 *
 * define out-of-range values (val > 11)
 *
 * idea is to equalluy distribute the probability 
 */

#define MAX_RANDOM 10

int rand10() {

    int val  = 0;

    do {
        val = 7 * rand7() + rand7();
    } while (val > 50 || val < 11);

    return val%10?val%10:10;
}
