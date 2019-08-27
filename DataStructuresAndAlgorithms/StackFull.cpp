class item {
    friend class Stack;
private:
    item(int x=0) {
        inf=x;
        link=0;
    }
    int inf;
    item* link;
};

class Stack {
public:
    Stack();
    Stack(int x);
    ~Stack();
    Stack(Stack const&);
    Stack& operator=(Stack const&);
    int push(int const&);
    int pop(int &x);
    int top() const;
    bool empty() const;
    void print();

private:
    item *start;
    void delStack();
    void copy(Stack const&);
};

Stack::Stack() {
    start = NULL;
}

Stack::Stack(int x) {
    start = new item(x);
}

Stack::~Stack() {
    delStack();
}

Stack::Stack(Stack const& r) {
    copy(r);
}

Stack& Stack::operator=(Stack const& r) {
    if(this != &r) {
        delStack();
        copy(r);
    }
    return *this;
}


