struct Node {
    int data;
    struct Node *next;
};

class List {
private:
    Node *head;
    Node *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }
};

void insertAtEnd(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void insertAtStart(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void print() {
    node *temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insert_position(int pos, int value) {
    node *pre;
    node *cur;
    node *temp = new node;
    temp->data = value;
    cur = head;
    for(int i=1; i<pos; i++) {
        pre = cur;
        cur = cur->next;
    }

    pre->next = temp;
    temp->next = cur;
}

void delete_first() {
    node *temp;
    temp = head;
    head = head->next;
    delete temp;
}

void delete_last() {
    node *current;
    node *previous;
    current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next =  NULL;
    delete current;
}

void delete_position(int pos) {
    node *current;
    node *previous;
    current = head;
    for(int i=1; i<pos; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

bool search(int x) {
    node *iter = head;
    while(iter != NULL) {
        if(iter->data == x) {
            return true;
        }
        iter = iter->next;
    }
    return false;
}


