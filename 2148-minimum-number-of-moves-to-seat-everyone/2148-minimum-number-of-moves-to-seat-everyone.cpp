class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int l=0,r=0;
        int moves = 0;
        while(l < seats.size() && r < students.size()){
            if(seats[l] != students[r]){
            moves += abs(students[r] - seats[l]);
            }
            l++;
            r++;
        }
        return moves;
    }
};