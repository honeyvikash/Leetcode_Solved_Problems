class Solution {
public:
// intution is like break the array in 2parts such that 1 part contains a, and another part contains b
// and now there xors will be the answer

// so point is how to breakk this in 2 parts
// first remove the noise and get the xor of array this will be a^b
// now find the first poistion from right, having bit is 1 in xor

// this means that at ith position one of a and b will have 1 and other will have 0;
// so break the array such that element having 0 at ith in one part and having 1 is in another part
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for(int x : nums){
            xo  = xo^x;
        }
        
        //getting the first i where bit is 1;
        int i;
        for( i =0;i<32;i++){
            if( (xo & (1 << i))!=0 ){
                break;
            }
        }
        //x01 is the group which contains all the elements haviong 1 at ith position
        //x02 is the group which contains all the elements haviong 0 at ith position
        int xo1 =0, xo2=0;
        for(auto x : nums){
           if( (x & (1 << i))!=0 ){
               //this is 1;
               xo1 = xo1^x;
               
           }
            else{
                //this is 0;
                xo2 = xo2^x;
            }
        }
        return {xo1, xo2};
    }
};