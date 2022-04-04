// note that level order traversal has been used to delete n inserrt
#include <bits/stdc++.h>
#include <queue>
using namespace std;
class NODE
{

public:
    int data;
    NODE *left;
    NODE *right;
    NODE(int k)
    {
        data = k;
        this->left = NULL;
        this->right = NULL;
    }
    NODE()
    {
        data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};
class BIN_TREE
{
    bool search(int *arr, int s, int n)
    {

        for (int i = 0; i < s; i++)
        {
            if (arr[i] == n)
            {

                return true;
            }
        }

        return false;
    }
    void deletDeepest(NODE *d_node)
    {
        queue<NODE *> q;
        q.push(root);

        NODE *temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == d_node)
            {
                temp = NULL;
                delete (d_node);
                return;
            }
            if (temp->right)
            {
                if (temp->right == d_node)
                {
                    temp->right = NULL;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->right);
            }

            if (temp->left)
            {
                if (temp->left == d_node)
                {
                    temp->left = NULL;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->left);
            }
        }
    }

public:
    int size = 0;
    int *a = new int[100];
    NODE *root;
    BIN_TREE()
    {
        root = NULL;
    }

    void printPostorder(NODE *temp)
    {

        if (temp == NULL)
            return;

        printPostorder(temp->left);

        printPostorder(temp->right);

        cout << " " << temp->data;
    }

    void printInorder(NODE *temp)
    {
        if (temp == NULL)
            return;

        printInorder(temp->left);

        cout << " " << temp->data;
        printInorder(temp->right);
    }

    void printPreorder(NODE *temp)
    {
        if (temp == NULL)
            return;

        cout << " " << temp->data;
        printPreorder(temp->left);

        printPreorder(temp->right);
    }
    void elements(NODE *temp)
    {
        if (temp == NULL)
            return;
        a[size] = temp->data;
        size++;

        elements(temp->left);

        elements(temp->right);
    }
    BIN_TREE operator+(int k)
    {
        NODE *temp = new NODE(k);
        if (root == NULL)
        {
            root = temp;
            return *this;
        }
        else
        {
            queue<NODE *> q;
            q.push(root);

            while (!q.empty())
            {
                NODE *temp2 = q.front();
                q.pop();

                if (temp2->left != NULL)
                    q.push(temp2->left);
                else
                {
                    temp2->left = temp;
                    return *this;
                }

                if (temp2->right != NULL)
                    q.push(temp2->right);
                else
                {
                    temp2->right = temp;
                    return *this;
                }
            }
        }
    }
    bool operator==(BIN_TREE o)
    {
        elements(root);
        o.elements(o.root);
        if (size != o.size)
        {
            return false;
        }
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] != o.a[i])
                    return false;
                i--;
            }
        }
        return true;
    }
    bool operator=(int k)
    {
        elements(root);
        return search(a, size, k);
    }

    BIN_TREE operator-(int k) //deletes element & replaces with last element
    {
        if (root == NULL)
            return *this;

        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == k)
                return *this;
            else
                return *this;
        }
            queue<NODE *> q;
            q.push(root);

            NODE *temp;
            NODE *k_node = NULL;

            // Level order traversal to find deepest
            while (!q.empty())
            {
                temp = q.front();
                q.pop();

                if (temp->data == k)
                    k_node = temp;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            if (k_node != NULL)
            {
                int x = temp->data;
                deletDeepest(temp);
                k_node->data = x;
            }
            return *this;
        
    }
};
int main()
{
    BIN_TREE o;
    o = o + 1;
    o = o + 2;
    o = o + 3;

    printf("\nPreorder traversal of binary tree is \n");
    o.printPreorder(o.root);

    printf("\nInorder traversal of binary tree is \n");
    o.printInorder(o.root);

    printf("\nPostorder traversal of binary tree is \n");
    o.printPostorder(o.root);
    BIN_TREE o1;
    o1 = o1 + 1;
    o1 = o1 + 2;
    o1 = o1 + 3;
    
    
    if (o1 == o)
    {
        cout << "\nequal";
    }
    else
        cout << "\nunequal";
    if (o = 0)
    {
        cout << "\npresent";
    }
    else
        cout << "\nnot present";
    if (o = 3)
    {
        cout << "\npresent";
    }
    else
        cout << "\nnot present";
 
    printf("\nInorder traversal of binary tree is \n");
    o1.printInorder(o1.root);
    o1 = o1 + 4;
    cout << "\nyo";
    printf("\nInorder traversal of binary tree is \n");
    o1.printInorder(o1.root);
    o1 = o1 - 3;
    printf("\nInorder traversal of binary tree is \n");
    o1.printInorder(o1.root);

    return 0;
}