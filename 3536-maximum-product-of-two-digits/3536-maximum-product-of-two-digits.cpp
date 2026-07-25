class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = -1, maxi2 = -1;

        while(n > 0){
            int digit = n % 10;
            n /= 10;

            if(digit >= maxi1){
                maxi2 = maxi1;
                maxi1 = digit;
            }
            else if(digit > maxi2){
                maxi2 = digit;
            }
        }
        return maxi1 * maxi2;
    }
};