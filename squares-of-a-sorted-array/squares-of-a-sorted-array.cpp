class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> vec;
     int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back((nums[i])*(nums[i]));
        }
//        for(int count=1;count<=n-1;count++){
//            int flag = 0;
//         for(int j=0;j<=n-2;j++){

//             if(vec[j] > vec[j+1]){
//                 swap(vec[j],vec[j+1]);
//                 flag = 1;
//             }
//         }
//         if(flag==0)                /// array is already sorted
//             break;                /// come out of loop
//        }
        sort(vec.begin(),vec.end());
        
        return vec;
    }
};