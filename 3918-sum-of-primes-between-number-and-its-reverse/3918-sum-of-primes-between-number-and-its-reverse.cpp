class Solution {
public:
    int reverse(int n) {
        bool isNegative = n < 0;
        string num = to_string(abs(n));
        
        string reversed = "";
        for(int i = num.length() - 1; i >= 0; i--){
            reversed += num[i]; 
        }

        int result = stoi(reversed);
        return isNegative ? -result : result;
    }

    bool isPrime(int num) {
        if(num < 2) return false;
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);

        int low = min(n, rev);
        int high = max(n, rev);

        int sum = 0;

        for(int i = low; i <= high; i++){
            if(isPrime(i)){
                sum += i;
            }
        }

        return sum;
    }
};