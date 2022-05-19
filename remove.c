template <typename K, typename O, typename B, typename C>
void
BinarySearchTree<K,O,B,C>::remove(const K & k)
{
    //Change find the size and height
    
    if(root!=nullptr) {
        Node* node=find(k);
        if(node==nullptr){ //not found
            return;
        }
        if(node!=nullptr){
        numNodes=numNodes-1;
        
        if(node!=root){
            //finding  grandparent
            Node * grandparent=forGrandparent(root, node);
            
                if((node->left==nullptr && node->right!=nullptr)){ //if node has a right child
                if(isLessThan(grandparent->key, node->key)){ //if node is a right child
                    grandparent->right=node->right;
                    delete node;
                }
                else{ //if node is a left child                      
                    grandparent->left=node->right;
                    delete node;
                }
                
                //to balance it
                std::stack<Node*> Stack;
                findWithStack(Stack, root, grandparent);
                    
                std::queue<Node*> Queue;
                while(!(Stack.empty())){ //creating the queue
                    Node* ptr=Stack.top();
                    Queue.push(ptr);
                    ptr->height=FindHeight(ptr);
                    ptr->subsize=CountOne(ptr);
                    Stack.pop();
                }
                while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(Qptr->subsize<1||isBalanced(Qptr->height, log2(Qptr->subsize))==true)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(root->subsize<1||isBalanced(Qptr->height, log2(Qptr->subsize))==true){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                return;
            }
            
            else if(node->left==nullptr&&node->right==nullptr ){ //if node is leaf
                if(isLessThan(node->key, grandparent->key)){ //if node is a right child
                    grandparent->left=nullptr;
                    delete node;
                    
                }
                else{                                        //if node is a left child
                    grandparent->right=nullptr;
                    delete node;
                }
                
                //no balancing
                std::stack<Node*> Stack;
                findWithStack(Stack, root, grandparent);
                    
                std::queue<Node*> Queue;
                while(!(Stack.empty())){ //creating the queue
                    Node* ptr=Stack.top();
                    Queue.push(ptr);
                    ptr->height=FindHeight(ptr);
                    ptr->subsize=CountOne(ptr);
                    Stack.pop();
                }
                while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || Qptr->subsize<1)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || root->subsize<1){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                AssignHeight(root);
                CountAll(root);
                return;
            }
            
            
            
            else if((node->right==nullptr && node->left!=nullptr)){ //if node has a left child
                if(isLessThan(grandparent->key, node->key)){ //if node is a right child
                    grandparent->right=node->left;
                    delete node;
                }
                else{ //if node is a left child                                     
                    grandparent->left=node->left;
                    delete node;
                }
                //to balance it
                std::stack<Node*> Stack;
                findWithStack(Stack, root, grandparent);
                    
                std::queue<Node*> Queue;
                while(!(Stack.empty())){ //creating the queue
                   Node* ptr=Stack.top();
                    Queue.push(ptr);
                    ptr->height=FindHeight(ptr);
                    ptr->subsize=CountOne(ptr);
                    Stack.pop();
                }
               while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || Qptr->subsize<1)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || root->subsize<1){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                return;
            }
            
            else if((node->right!=nullptr && node->left!=nullptr)){ //if node has two children
                
                //find the successor
                Node* successor=minimum(node->right);
                if(successor==node->right){ //if the successor is the node's right child
                    successor->left=node->left;
                    
                    if(isLessThan(grandparent->key, node->key)){ //if the node is a right child
                        grandparent->right=successor;
                        node->left=nullptr;
                        node->right=nullptr;
                        delete node;
                    }
                    else{ //if the node is a left child                                       
                        grandparent->left=successor;
                        node->left=nullptr;
                        node->right=nullptr;
                        delete node;
                    }
                    
                    //to balance it
                    std::stack<Node*> Stack;
                    findWithStack(Stack, root, successor);
                    
                    std::queue<Node*> Queue;
                    while(!(Stack.empty())){ //creating the queue
                        Node* ptr=Stack.top();
                        Stack.pop();
                        ptr->height=FindHeight(ptr);
                        ptr->subsize=CountOne(ptr);
                        Queue.push(ptr);
                    }
                    while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || Qptr->subsize<1)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || root->subsize<1){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                    return;
                }
                else{ //if the successor is not the node's right child
                    Node* successorGrandparent=forGrandparent(root, successor);
                //std::cout<< successorGrandparent->data << successor->data << std::endl;
                    successorGrandparent->left=successor->right;
                    successor->left=node->left;
                    successor->right=node->right;
                
                    if(isLessThan(grandparent->key, node->key)){ //if the node is a right child
                        grandparent->right=successor;
                        node->left=nullptr;
                        node->right=nullptr;
                        delete node;
                    }
                    else{ //if the node is a left child                                       
                        grandparent->left=successor;
                        node->left=nullptr;
                        node->right=nullptr;
                        delete node;
                    }
                    
                    //to balance it
                    std::stack<Node*> Stack;
                    findWithStack(Stack, root, successorGrandparent);
                    
                    std::queue<Node*> Queue;
                    while(!(Stack.empty())){ //creating the queue
                        Node* ptr=Stack.top();
                    Queue.push(ptr);
                    ptr->height=FindHeight(ptr);
                    ptr->subsize=CountOne(ptr);
                    Stack.pop();
                    }
                    while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || Qptr->subsize<1)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || root->subsize<1){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                    return;
                }
            }
        }
        else{ //if the node is the root
            
            Node* temp=root;
            if(node->left==nullptr && node->right==nullptr){ //if root has no children
                root=nullptr;
                delete temp;
                //no balancing
                AssignHeight(root);
                CountAll(root);
                return;
            }
            else if((node->left==nullptr && node->right!=nullptr)){ //if root has right child
                root=root->right;
                delete temp;
                //no balancing
                AssignHeight(root);
                CountAll(root);
                return;
            }
            else if((node->left!=nullptr && node->right==nullptr)){ //if root has left child
                root=root->left;
                delete temp;
                //no balancing
                AssignHeight(root);
                CountAll(root);
                return;
            }
            else{ //if root has two children
                Node* successor=minimum(node->right);
                if(successor==root->right){ //if the successor is the root's right child
                    successor->left=root->left;
                    root=successor;
                    delete temp;
                    //to balance it
                    FindHeight(root);
                    CountOne(root);
                    if(!(isBalanced(root->height,log2(root->subsize))))
                        toCompleteBSTperNode(successor);
                        //FindHeight(root);
                        //CountOne(root);
                    return;
                }
                else{ //if successor is not the root's right child
                    Node* successorGrandparent=forGrandparent(root, successor);
                    successorGrandparent->left=successor->right;
                    successor->left=node->left;
                    successor->right=node->right;
                    root=successor;
                    delete temp;
                    
                    //to balance it
                    std::stack<Node*> Stack;
                    findWithStack(Stack, root, successorGrandparent);
                    
                    std::queue<Node*> Queue;
                    while(!(Stack.empty())){ //creating the queue
                       Node* ptr=Stack.top();
                    Queue.push(ptr);
                    ptr->height=FindHeight(ptr);
                    ptr->subsize=CountOne(ptr);
                    Stack.pop();
                    }
                    while(!(Queue.empty())){
            Node * Qptr=Queue.front();
            Queue.pop();
            if(!(Queue.empty())){
                Node * grandparent=Queue.front();
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || Qptr->subsize<1)
                {
                }
                else{
                    toCompleteBSTperNode(Qptr);
                    if(isLessThan(Qptr->key,grandparent->key)){
                        grandparent->left=Qptr;
                    }
                    else grandparent->right=Qptr;
                }
                AssignHeight(grandparent);
                CountAll(grandparent);
            }
            else{
                if(isBalanced(Qptr->height, log2(Qptr->subsize))==true || root->subsize<1){
                  
                } 
                else{
                    toCompleteBSTperNode(Qptr);
                    root=Qptr;
                }
                FindHeight(Qptr);
                CountOne(Qptr);
            }
        }
                    return;
                }
            }
        }
        }
    }
    else;
}
