class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        int unsort_size = A.size();
        vector<int>::iterator max_it;
        vector<int> sequence_pancake_flip;
        
        do{
            max_it = max_element(A.begin(), A.begin()+unsort_size);
            
            if(max_it == (A.begin()+unsort_size)){
                continue;
            }
            
            if(max_it != A.begin()){
                reverse(A.begin(), max_it+1);
                sequence_pancake_flip.push_back(max_it-A.begin()+1);
            }
            
            reverse(A.begin(), A.begin()+unsort_size);
            sequence_pancake_flip.push_back(unsort_size);
            
        }while(unsort_size--);
        
        return sequence_pancake_flip;
    }
};
