Product of Array except itself
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator in O(n) time.

Example : 
Input: arr[]  = {10, 3, 5, 6, 2}
Output: prod[]  = {180, 600, 360, 300, 900}
3 * 5 * 6 * 2 product of other array 
elements except 10 is 180
10 * 5 * 6 * 2 product of other array 
elements except 3 is 600
10 * 3 * 6 * 2 product of other array 
elements except 5 is 360
10 * 3 * 5 * 2 product of other array 
elements except 6 is 300
10 * 3 * 6 * 5 product of other array 
elements except 2 is 900
/////////////////////////////////////////////  java solution/////////////////////////////////////////////
  public int[] productExceptSelf(int[] nums) {
          
        int output[] = new int[ nums.length];
        
        output[0] = 1;

        // left prefix product
        for(int i=1;i<nums.length;i++){
             output[i] = output[i-1] * nums[i-1];
        }
        
        int product = 1;

        for(int i=nums.length-1;i>=0;i--){
            
            output[i] = output[i] * product;
            
            product*= nums[i];
        }
        
        return output;
}
