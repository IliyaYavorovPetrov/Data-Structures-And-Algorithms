#include<bits/stdtr1c++.h>

struct Node
{
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node* next;
};

bool has_cycle(Node* head){
    if (!head) {
        return false;
    }

    std::vector<Node*> data;
    while (head->next)
    {
        auto it = find(data.begin(), data.end(), head);
        if (it != data.end()) {
            return true;
        }

        data.push_back(head);
        head = head->next;
    }

    return false;
}

Node* get_middle(Node* head) {
    if (!head) {
        return nullptr;
    }
        
    Node* mid = head;
    int counter = 0;
    int size = 1;
    while (head) {
        if (counter == 2) {
            counter = 0;
            mid = mid->next;
        }
        ++counter;
        head = head->next;
        ++size;
    }

    // Depends from the exact task 
    if (size % 2 == 1) {
        mid = mid->next;
    }
        
    return mid;
}

void reverse(Node* head) {
    if (!head) {
        return;
    }

    std::stack<Node*> st;
    while (head) {
        st.push(head);
        head = head->next;
    }

    auto start = st.top();
    st.pop();
    while (!st.empty()) {
        start->next = st.top();
        start = st.top();
        st.pop();
    }
    start->next = nullptr;
}

bool is_palindrome(Node* head) {
    if (!head) {
        return true;
    }
        
    std::vector<int> data;
    while (head) {
        data.push_back( head->data);
        head = head->next;
    }
        
    auto rev = data;
    std::reverse(rev.begin(), rev.end());
        
    if (data != rev) {
        return false;
    }
        
    return true;
}

void remove_element(Node* head, int val) {
    while(head){
        if (head->data != val) {
            break;
        }
        head = head->next;
    }
        
    if (!head) {
        return;
    }

    Node* mov = head;
    Node* buff = nullptr;
    while (mov) {
        while (mov && mov->data == val) {
            buff->next = mov->next;
            mov = mov->next;
        }
            
        buff = mov;
        if (!mov) {
            break;
        }
        mov = mov->next;
    }
}

void remove_element(Node* node) {
    Node* prev = nullptr;
    while (node->next) {
        node->data = node->next->data;
        prev = node;
        node = node->next;
    }
    prev->next = nullptr;
}

int main()
{
    return 0;
}