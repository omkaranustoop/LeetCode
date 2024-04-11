class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(char c:s){
            if(c == '(' || c == '{' || c == '['){
                ss.push(c);
            }
            else{
                if(c == ')'){
                    if(ss.empty()){
                        return false;
                    }
                    else{
                        if(ss.top() == '('){
                            ss.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
                else if(c == '}'){
                    if(ss.empty()){
                        return false;
                    }
                    else{
                        if(ss.top() == '{'){
                            ss.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
                else{
                    if(ss.empty()){
                        return false;
                    }
                    else{
                        if(ss.top() == '['){
                            ss.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        if(!ss.empty())return false;
        return true;
    }
};