/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/* Algo:

    Let X be the node to be deleted.

    3 cases:
    
    1. The node X has no children -> delete and free the node. 
    2. The node has 1 children -> delete the node and attach the child to its grandparent
    3. The node has 2 children -> delete the node but find the next successor 
       (max of its left child tree or min of its right child tree). 
       Copy that value to the node X. And delete that successor node.
       (again this deletion falls to case 1 or 2)


*/

struct TreeNode* binary_search (int key, struct TreeNode* curr, struct TreeNode** parent)
{
    if (!curr){
        return NULL;
    }
    
    if (curr->val == key) {
        return curr;
    }
    
    *parent = curr;
    if (curr->val < key) {
        return binary_search(key, curr->right, parent);
    } else {
        return binary_search(key, curr->left, parent);
    }
}

/* assuming root not null */
struct TreeNode* findminnode (struct TreeNode* root) {
    
   while (root && root->left) {
       findminnode(root->left);
   }
    
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    
    struct TreeNode *parent = NULL, *curr = NULL, *succ = NULL;
    
    /* starting from root, search for the node with the given key */
    curr = binary_search(key, root, &parent);
    if (!curr) {
        return NULL;
    }
    
    /* store the parent node of each current node as we traverse */
    /* once we find the node, apply logic handling all 3 cases */
    
    if (curr->right && curr->left) {
        /* 2 childs. find the next successor to this curr, 
        copy that key to curr and free the successor */
        succ = findminnode(curr->right);
        curr->val = succ->val;
        deleteNode(curr, succ->val);
    } else if (curr->right || curr->left) {
        /* 1 child. attach it to the child's grandparent and free the node */
        if (curr->right) 
            succ = curr->right;
        else
            succ = curr->left;
        
        if (!parent)
            root = succ;
        else if ((parent)->right == curr)
            parent->right = succ;
        else if ((parent)->left == curr)
            (parent)->left = succ;
        
        free(curr);
        curr=NULL;
    } else {
        /* no child, just free the node */
        free(curr);
        curr = NULL;
    }
    
    return root;
}

