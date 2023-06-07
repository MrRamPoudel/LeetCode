public class Solution{
    public int MaxArea(int[] height){
        int max = 0;
        int width = 0;
        int left = 0;
        int right = height.Length - 1;
        int area = 0;
        while(left < right){
            width = right - left;
            area = width * Math.Min(height[left], height[right]);
            if (area > max){
                max = area;
            }
            //Move the left pointer to right
            if (height[left] < height[right]){
                left++;
            }
            //move both pointers
            else if(height[left] == height[right]){
                left++;
                right--;
            }
            //move right pointer to left
            else{
                right--;
            }
        }
        return max;
    }
}