const int MAX = 100;

class Stack : public AbstractStack<int> {
private:
    int a[MAX];
    int top;

    bool full() const;

public:
    Stack();
    bool empty() const;
    void push(int const& x);
    int pop();
    int peek() const;
};

Stack::Stack() : top(-1) {}

bool Stack::empty() const{
    return top == -1;
}

bool Stack::full() {
    return top == MAX-1;
}

void Stack::push(int const& x) {
    if(full()) {
        cerr << "Error! FULL STACK!" << endl;
    }
    else
        a[++top] = x;
}

int Stack::pop() {
    if(empty()) {
        cerr << "STACK IS EMPTY!" << endl;
        return 0;
    }
    return a[top--];
}

int Stack::peek() const {
    if(empty()) {
        cerr << "STACK IS EMPTY!" << endl;
        return 0;
    }
    return a[top];
}
