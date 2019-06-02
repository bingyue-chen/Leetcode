class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int left, right;
        
        for(auto token : tokens){
            if(token == "+"){
                right = numbers.top(); numbers.pop();
                numbers.top() += right;
            }
            else if(token == "-"){
                right = numbers.top(); numbers.pop();
                numbers.top() -= right;
            }
            else if(token == "*"){
                right = numbers.top(); numbers.pop();
                numbers.top() *= right;
            }
            else if(token == "/"){
                right = numbers.top(); numbers.pop();
                numbers.top() /= right;
            }
            else{
                numbers.push(stoi(token));
            }
        }
        
        return numbers.top();
    }
};