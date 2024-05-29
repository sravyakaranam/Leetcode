class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        res = [1] * n  # Initialize the result array with 1's.
        
        # First pass: Calculate products of all elements before each index.
        left_product = 1
        for i in range(n):
            res[i] = left_product
            left_product *= nums[i]  # Update left product for the next index.
        
        # Second pass: Calculate products of all elements after each index.
        right_product = 1
        for i in range(n - 1, -1, -1):
            res[i] *= right_product  # Multiply with the accumulated right product.
            right_product *= nums[i]  # Update right product.
        
        return res
