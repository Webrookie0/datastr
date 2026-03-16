class Solution {
    public:
        int longestArithmetic(vector<int>& nums) {
            // vector<int>pref(nums.size()-1);
    
            // for(int i=1; i<nums.size(); i++){
            //     pref[i-1]= nums[i]-nums[i-1];
            // }
            // here we calculated the left and right arrys with the maxm same difference between adjacent elemnts 
            int n = nums.size();
            if (n <= 2)
                return n;
            vector<int> left(nums.size());
            vector<int> right(nums.size());
            left[0] = 1;
            left[1] = 2;
            right[n - 2] = 2;
            right[nums.size() - 1] = 1;
            for (int i = 2; i < n; i++) {
                if ( nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                    left[i] = left[i - 1] + 1;
                } else {
                    left[i] = 2;
                }
            }
            // here we calculated the right array with the maxm same difference between adjacent elemnts 
            for (int i = nums.size() - 3; i >= 0; i--) {
                if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                    right[i] = right[i + 1] + 1;
                } else {
                    right[i] = 2;
                }
            }
            // here we calculated the maxm same difference between adjacent elemnts in the left and right arrays
            int res = *max_element(right.begin(), right.end());
            res = max(res, *max_element(left.begin(), left.end()));
            if (res != n) {
                res++;
            }
            // agar left aur right arry merge nahi hue to uss case mein left aur right ka maxm +1 hmara answer hoga kyuki ek na ek element to hm change kar hi sakte hai 
    
            for (int i = 1; i < n - 1; i++) {
                // har element ke liye uska gap nikal lenge 
                
                int gap = nums[i + 1] - nums[i - 1];
    
                // if(temp %2==0 && (temp/2 == pref[i-1])  ){
                if (gap % 2 != 0)
                    continue;
    
                int temp = gap / 2;
                // gap ka half agar aage ke gap ke barabar hai aur peeche ke bhi barabar hai to uss case mein hm ek element ko change kar sakte hai 
                int leftDiff = (i >= 2 ? nums[i - 1] - nums[i - 2] : temp);
                int rightDiff = (i + 2 < n ? nums[i + 2] - nums[i + 1] : temp);
                // idhar mai bohot baar indexing mein fasa tha to dhyaan se dekhna ki i-2 tabhi lena jab i>=2 ho 
                // aur n-2 se chhota ho i tabhi i+2 lena 
                if (leftDiff == rightDiff && temp == leftDiff) {
                    res = max(res, 1 + left[i - 1] + right[i + 1]);
                }
                // left diff aur right diff aagya to usko 1+ left[i-1] + right[i+1] lelo
                if (temp == leftDiff) {
                    res = max(res, 2 + left[i - 1]);
                }
                // incase nahi aaya aur ek side ka hi diff barabar aaya to usd side ka +2 karke ans mein daal lo 
                if (temp == rightDiff) {
                    res = max(res, 2 + right[i + 1]);
                }
            }
            return res;
    
            // }
            
        }
        
    };