#include <iostream>
using namespace std;

struct node 
{
  int key;
  struct node *left, *right;
};




// Inorder traversal
void traverseInOrder(struct node *root) 
{
  if (root==NULL)  // If the tree is empty
  {
    return;
  }

  traverseInOrder(root->left);  // Traverse the left subtree
  cout<<root->key<<" ";         // Display the key value of the node
  traverseInOrder(root->right); // Traverse the right subtree
}




// Insert a node
struct node *insertNode(struct node *root, int key) 
{
  if (root == NULL) // If the tree is empty 
  {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (key < root->key)      // If the key is less than the root node's key, then insert in the left subtree
    root->left = insertNode(root->left, key);
  else if (key > root->key) // If the key is greater than the root node's key, then insert in the right subtree
    root->right = insertNode(root->right, key);

  return root;
}




// Helper function to find the node with minimum key value in a given BST
struct node* minValueNode(struct node* node)
{
  struct node* current = node;
  while (current && current->left != NULL)
  {
    current = current->left;
  }
  return current;
}




// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{

  if (root == NULL) // If the tree is empty or node not found
  {
    return root;
  }

  if (key < root->key)  // If the key is less than the root node's key, then delete from the left subtree
  {
    root->left = deleteNode(root->left, key);
  }

  else if (key > root->key) // If the key is greater than the root node's key, then delete from the right subtree
  {
    root->right = deleteNode(root->right, key);
  }

  else // found the node to be deleted
  {
    if (root->left == NULL) // if the node has only a right child (or no children)
    {
      struct node *temp = root->right;  // save the right child
      delete(root); // delete the current node
      return temp;  // return the right child as the new root
    }
    else if (root->right == NULL) // if the node has only a left child
    {
      struct node *temp = root->left; // save the left child
      delete(root); // delete the current node
      return temp;  // return the left child as the new root
    }    
    struct node *temp = minValueNode(root->right);  // Find the node with minimum key value in the right subtree
    root->key = temp->key;  // Replace the key value of the node to be deleted with the minimum key value found in the right subtree
    root->right = deleteNode(root->right, temp->key); // Delete the node with the minimum key value found in the right subtree
  }

  return root;

}




// Driver code
int main() 
{
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) 
  {
    switch(operation) 
    {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}

