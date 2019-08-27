struct node {
    int key;
    struct node *left, *right;
};

node* insert(node* root, int key) {
    if(root == NULL) return newNode(key);

    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > node->key)
        root->right = insert(root->right, key);

    return node;
}

//INORDER PRINT
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

node* deleteNode(struct node* root, int key) {
    if(root == NULL) return root;

    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

node* minValueNode(node* node)
{
    node* current = node;
    while(current->left != NULL)
        current = current->left;

    return current;
}
