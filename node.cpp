#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
template<class T>
class SinglyNode {
private:
    T data;
    SinglyNode *next;

public:
    SinglyNode() = default;

    explicit SinglyNode(T data) {
        SinglyNode::data = data;
    }

    void setData(T data) {
        SinglyNode::data = data;
    }

    void setNext(SinglyNode *next) {
        SinglyNode::next = next;
    }

    T getData() {
        return data;
    }

    SinglyNode* getNext() {
        return next;
    }
};


template<class T>
class CircularNode : public SinglyNode<T> {
public:
    CircularNode() {
        setNext(this);
    }
};


template<class T>
class DoublyNode : public SinglyNode<T> {
private:
    DoublyNode *previous;

public:
    DoublyNode() {
        previous = nullptr;
    }

    DoublyNode *getPrevious() const {
        return previous;
    }

    void setPrevious(DoublyNode *previous) {
        DoublyNode::previous = previous;
    }
};


template<class T>
class CircularDoublyNode : public DoublyNode<T> {
public:
    CircularDoublyNode() {
        setPrevious(this);
        setNext(this);
    }
};
#pragma clang diagnostic pop