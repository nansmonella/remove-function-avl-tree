# remove-function-avl-tree
Remove Function Of An AVL Binary Search Tree

It finds the node holding the Key parameter by exploiting binary search tree characteristics via a recursive search starting from the root position. If the Key parameter does not exist, nothing is done. Otherwise if the node holding the Key parameter is a leaf, then this node will directly be deleted. If the node has one child, pointer connections are set up with the parent and the child of the node and delete the node. Whenever a node is deleted, the number of nodes is decremented. 

The heights of the nodes that reside in the path that remove function has travelled are updated via backtracking and all visited nodes are rebalanced in accordance with the AVL tree specifications. If the deleted node had two children, heights are updated and nodes that are on the path starting from the initial position up to the root are rebalanced.
