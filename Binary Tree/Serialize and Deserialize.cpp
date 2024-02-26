/*
Approach
Serialization:
1.Depth-First Search (DFS) Traversal:
We initiate the serialization process by performing a depth-first search (DFS) traversal of the binary tree.
During the traversal, we visit each node in a pre-order manner, starting from the root.

2.Encoding Node Values:
For each node encountered during traversal, we append its value to the serialized string.
If the node is a leaf node (having no children), we add its value to the string.

3.Handling Null Nodes:
If a node is None (indicating a null node), we append the character "N" to the serialized string to represent the absence of a node.
This ensures that the serialized string preserves the tree's structure, including the positions of null nodes.

4.Pre-order Traversal:
By traversing the binary tree in a pre-order manner, we ensure that the serialized string reflects the root value followed by values of its left and right subtrees.


Deserialization:
1.Splitting Serialized String:
To reconstruct the binary tree, we split the serialized string using the specified delimiter ("," in this case).
The split string provides us with the values of nodes encountered during the pre-order traversal.
2.Recursive Reconstruction:
We recursively reconstruct the binary tree based on the pre-order traversal sequence obtained from the split serialized string.
At each step, we examine the current value from the split string.
3.Node Creation:
If the current value is "N," indicating a null node, we return None to represent the absence of a node.
If the current value is a valid integer, we create a new TreeNode with that integer value.
4.Recursive Construction of Subtrees:
After creating the current node, we recursively construct its left and right subtrees by making recursive calls.
This process continues until we have reconstructed the entire binary tree.

*/
class Codec {
public:

    string serialize(TreeNode* root) {
        // Create an output string stream to store serialized data
        ostringstream temp;
        
        // Call the helper function to serialize the tree
        ToString(root, temp);
        
        // Convert the output string stream to a string and return
        return temp.str();
    }

    TreeNode* deserialize(string data) {
        // Create an input string stream to read serialized data
        istringstream temp(data);
        
        // Call the helper function to deserialize the tree and return the root
        return ToStructure(temp);
    }
    
private:
    
    void ToString(TreeNode* root, ostringstream& temp) {
        // Base case: If the current node is NULL, append "N" to represent null node
        if (root == NULL) {
            temp << "N ";
            return;
        }
        
        // Append the value of the current node followed by a space
        temp << root->val << " ";
        
        // Recursively serialize left and right subtrees
        ToString(root->left, temp);
        ToString(root->right, temp);
    }
    
    TreeNode* ToStructure(istringstream& temp) {
        // Read the next value from the input string stream
        string value = "";
        temp >> value;
        
        // If the value is "N", indicating a null node, return NULL
        if (value == "N") {
            return NULL;
        }
        
        // Otherwise, create a new TreeNode with the integer value
        TreeNode* root = new TreeNode(stoi(value));
        
        // Recursively construct left and right subtrees
        root->left = ToStructure(temp);
        root->right = ToStructure(temp);
        
        // Return the root of the reconstructed tree
        return root;
    }
    
};