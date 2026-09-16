class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> choice;
        for(int i = 0;i < size;i++){
            choice.push(students[i]);
        }

        int rotations = 0, i = 0;
        while(choice.size() && rotations < choice.size()){
            if(choice.front() == sandwiches[i]){
                choice.pop();
                i++;
                rotations = 0;
            } else {
                int c = choice.front();
                choice.pop();
                choice.push(c);
                rotations++;
            }
        }
        return choice.size();
    }
};