class LFUCache {

    struct Node {
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    int minFreq;

    // key -> node
    unordered_map<int, Node*> keyMap;

    // frequency -> DLL
    unordered_map<int, pair<Node*, Node*>> freqMap;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void remove(Node* node) {

        int freq = node->freq;

        Node* head = freqMap[freq].first;
        Node* tail = freqMap[freq].second;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        // If list becomes empty
        if (head->next == tail) {
            delete head;
            delete tail;

            freqMap.erase(freq);
        }
    }

    void insert(Node* node) {

        int freq = node->freq;

        // Create DLL if frequency doesn't exist
        if (freqMap.find(freq) == freqMap.end()) {

            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            freqMap[freq] = {head, tail};
        }

        Node* head = freqMap[freq].first;

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        remove(node);

        node->freq++;

        insert(node);

        // Update minFreq
        if (oldFreq == minFreq &&
            freqMap.find(oldFreq) == freqMap.end()) {

            minFreq++;
        }
    }

    int get(int key) {

        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            node->value = value;

            increaseFreq(node);

            return;
        }

        // Cache full
        if (keyMap.size() == capacity) {

            Node* head = freqMap[minFreq].first;
            Node* tail = freqMap[minFreq].second;

            // Least recently used node
            Node* victim = tail->prev;

            keyMap.erase(victim->key);

            remove(victim);

            delete victim;
        }

        Node* node = new Node(key, value);

        keyMap[key] = node;

        minFreq = 1;

        insert(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */