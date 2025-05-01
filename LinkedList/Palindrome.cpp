#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* createLL(int arr[], int N)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(int i = 1; i < N; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

void printLL(Node* head)
{
    Node *temp = head;
    
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
        return true;
        
    Node *left = head;
    Node *right = head;
    int last = -1;

    while(left != NULL)
    {
        if(last == left->data)
        {
            right = left;
            break;
        }

        last = left->data;
        left = left->next;
    }

    if(right == head)
        return false;
    
    left->next = NULL;
    left = head;
    Node *prev = NULL;

    while(left != NULL)
    {
        Node *temp = left->next;
        left->next = prev;
        prev = left;
        left = temp;
    }

    left = prev;
    while(left != NULL && right != NULL)
    {
        if(left->data != right->data)
            return false;
        
        left = left->next;
        right = right->next;
    }

    if(left)
        std::cout << left->data << "\n";
    if(right)
        std::cout << right->data << "\n";

    if(left)
        return false;

    if(right)
        return false;
    
    return true;
}

Node* deleteMiddle(Node* head) {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast->next = fast->next->next;
    }

    if(prev == NULL)
        head = head->next;
    else
    {
        prev->next = slow->next;
        slow->next = NULL;
    }

    return head;
}

int main()
{
    int arr[7] = {1, 3, 4, 7, 1, 2, 6};

    Node *head = createLL(arr, 7);
    printLL(deleteMiddle(head));
    
    return 0;
}