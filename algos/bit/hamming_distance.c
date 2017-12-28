/*
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * - [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance)
 *
 * For instance:
 *   Input: x = 1, y = 4
 *    Output: 2
 *    Explanation:
 *       1   (0 0 0 1)
 *       4   (0 1 0 0)
 *              ↑   ↑
 * The above arrows point to positions where the corresponding bits are different.
 */

#include <assert.h>


int hamming_distance(int x, int y) {
    int distance = 0;
    int hamming = x^y;
    
    while (hamming)
    {
        if ((hamming >> 1) << 1 != hamming)
            distance++;
        hamming = hamming >> 1;
    }
    
    return distance;
}


int main(void)
{
  int distance = hamming_distance(1, 4);
  assert(distance == 2);
  return 0;
}
