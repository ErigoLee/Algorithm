#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int num;
    struct node_t* left;
    struct node_t* right;
} Node;

Node* head = NULL;

Node* create_node(int num)
{
    Node* new_Node = (Node*)malloc(sizeof(Node));

    new_Node->num = num;
    new_Node->left = NULL;
    new_Node->right = NULL;

    return new_Node;
}
void left_connect(Node* node, int num);
void right_connect(Node* node, int num);

void left_connect(Node* node, int num)
{
    if (node->left == NULL)
        node->left = create_node(num);
    else
    {
        if (node->left->num > num)
            left_connect(node->left, num);
        else
            right_connect(node->left, num);
    }

}

void right_connect(Node* node, int num)
{
    if (node->right == NULL)
        node->right = create_node(num);
    else
    {
        if (node->right->num > num)
            left_connect(node->right, num);
        else
            right_connect(node->right, num);
    }
}

void connect_node(int num)
{
    if (head == NULL)
    {
        head = create_node(num);
    }
    else
    {
        if (head->num > num)
            left_connect(head, num);
        else
            right_connect(head, num);
    }
}

void inorder(Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    inorder(node->right);
    printf("%d\n", node->num);

}

int main(void) {

    int num;
    //int a=0;
    //scanf("%d", &num) !=EOF
    while (scanf("%d", &num) != EOF)
    {
        //scanf("%d",&num);
        connect_node(num);
        //a++;
    }


    inorder(head);

    return 0;
}