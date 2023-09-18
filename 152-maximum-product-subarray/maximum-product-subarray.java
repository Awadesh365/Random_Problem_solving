class Solution {
public int maxProduct(int[] nums) {
    if (nums == null || nums.length == 0) {
        return 0;
    }

    int maxProduct = nums[0];
    int maxEndingHere = nums[0];
    int minEndingHere = nums[0];

    for (int i = 1; i < nums.length; i++) {
        if (nums[i] < 0) {
            // Swap maxEndingHere and minEndingHere when encountering a negative number
            int temp = maxEndingHere;
            maxEndingHere = minEndingHere;
            minEndingHere = temp;
        }

        // Update the maximum and minimum products ending at the current position
        maxEndingHere = Math.max(nums[i], maxEndingHere * nums[i]);
        minEndingHere = Math.min(nums[i], minEndingHere * nums[i]);

        // Update the overall maximum product
        maxProduct = Math.max(maxProduct, maxEndingHere);
    }

    return maxProduct;
}

}