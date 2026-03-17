// do map ke common nikalne ke liye ek se dusre ki freq check karke operation karne ke baad 
// dusre wale ko bhi check karlena warna uske andar elemnts bache rahenge 
class Solution {
    public:
        int minCost(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int , int>mp;
            unordered_map<int , int>mp1;
            
            for(int i=0; i<nums1.size(); i++){
                mp[nums1[i]]++;
            }
            for(int i=0; i<nums2.size();i++){
                mp1[nums2[i]]++;
            }
            long long ans =0;
            
            for(auto it : mp){
                int temp = mp1[it.first]-it.second;
                temp = abs(temp);
                if(temp %2 ==0){
                    ans+=temp/2;
                    mp1[it.first]=0;
                }else{
                    return -1;
                }
            }
            // second map ko bhi check kara ek baari aur taaki uske and ar ke elements pe bhi operations ho jaaye 
            for(auto it : mp1){
                if(it.second ==0)continue;
                if(it.second%2 ==0 ){
                    ans +=it.second/2;
                }else{
                    return -1;
                }
                
            }
            return ans/2;
            
    
            
    
            
        }
    };



    // aage aur bhi likhunga 
    // 
// next smaller elemnt 
    for(int i=n-1; i>=0; i--){

        while(!st.empty() && st.top().first>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            nexts.push_back(n);
        }else{
            nexts.push_back(st.top().second);
        }
        st.push({heights[i], i});
    }
    reverse(nexts.begin(), nexts.end());

    // prev smaller elemnt 

    for(int i=0; i<n; i++){

        while(!st.empty() && st.top().first>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            prevs.push_back(-1);
        }else{
            prevs.push_back(st.top().second);
        }
        st.push({heights[i], i});
    }