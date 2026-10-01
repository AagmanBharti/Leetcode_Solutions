class MyLinkedList {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = newNode;
        }

        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* deleteNode = head;

            head = head->next;

            delete deleteNode;
            size--;

            if (size == 0) {
                tail = nullptr;
            }

            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;

        if (index == size - 1) {
            tail = temp;
        }

        delete deleteNode;
        size--;
    }
};