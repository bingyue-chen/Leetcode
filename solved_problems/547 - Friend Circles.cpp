
class Solution {
public:
    struct Node {
        int n;
        Node *belong_to;
    };
    
    int findCircleNum(vector<vector<int>>& M) {

        vector<Node*> circles;
        
        int size = M.size();
        
        for(int i = 0; i< size; i++){
            Node *node = new Node;
            node->n = i;
            node->belong_to = NULL;
            circles.push_back(node);
        }
        
        Node *A, *B;
        
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(M[i][j] == 1){
                    A = find_head(circles[i]);
                    B = find_head(circles[j]);
                    if(A->n != B->n){
                        B->belong_to = A;
                    }
                }
            }
        }
        
        int circle_count = 0;
        
        for(Node* n : circles){
            if(n->belong_to == NULL) circle_count++;
            delete n;
        }
        
        circles.clear();
        
        return circle_count;
    }
    
    Node* find_head(Node* node){
        while(node->belong_to != NULL) node = node->belong_to;
        return node;
    }
    
};