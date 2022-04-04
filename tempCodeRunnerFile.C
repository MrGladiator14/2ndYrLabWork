#include <bits/stdc++.h>
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
    //    NODE *root;

public:
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
    BIN_TREE operator+(int k)
    {
        NODE *temp = new NODE(k);
        if (root == NULL)
        {
            root == temp;
        }
        else
        {
            /*NODE* n=root;
            if(n->left==NULL)
                n->left=temp;
            else if(n->right==NULL)
                n->right=temp;
            else */
            queue<NODE *> q;
            q.push(root);

            while (!q.empty())
            {
                NODE *temp2 = q.front();
                q.pop();

                if (temp2->left != NULL)
                    q.push(temp->left);
                else
                {
                    temp2->left = temp;
                    return *this;
                }

                if (temp2->right != NULL)
                    q.push(temp->right);
                else
                {
                    temp2->right = temp;
                    return *this;
                }
            }
        }
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

    return 0;
}