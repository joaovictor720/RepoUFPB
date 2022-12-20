//
//  main.cpp
//  TheDoleQueue
//
//  Created by Leonardo Chianca on 28/10/22.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

// Node Class
class Node {
private:
    Node* next;
    Node* previous;
    int value;
public:
    // Constructor
    Node();
    virtual ~Node();

    // Get methods
    Node* getNext();
    Node* getPrevious();
    int getValue();

    // Set methods
    void setNext(Node*);
    void setPrevious(Node*);
    void setValue(int);
};

Node::Node() {
    next = NULL;
    previous = NULL;
}

Node::~Node() {}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrevious() {
    return previous;
}

int Node::getValue() {
    return value;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

void Node::setValue(int value) {
    this->value = value;
}

// List Class
class CircularList {
private:
    Node* first;
    Node* last;
    int count;
public:
    // Constructor and Destructor
    CircularList();
    virtual ~CircularList();

    bool isEmpty();
    int length();

    void insert(int, int);
    void remove(int);

    int getValue(int);
    int getPos(int);

    void theDoleQueue(int, int);
};

CircularList::CircularList() {
    first = NULL;
    last = NULL;
    count = 0;
}

CircularList::~CircularList() {}

bool CircularList::isEmpty() {
    return count == 0;
}

int CircularList::length() {
    return count;
}

void CircularList::insert(int pos, int value) {
    if(isEmpty() && pos != 1) {
        return;
    }

    if(pos <= 0 || pos > count + 1) {
        return;
    }

    Node* newNode = new Node();
    newNode->setValue(value);

    if(pos == 1) {
        newNode->setNext(first);
        newNode->setPrevious(last);

        if(isEmpty()) {
            last = newNode;
        } else {
            first->setPrevious(newNode);
            last->setNext(newNode);
        }

        first = newNode;
    } else if(pos == length() + 1) {
        newNode->setPrevious(last);
        newNode->setNext(first);
        first->setPrevious(newNode);
        last->setNext(newNode);
        last = newNode;
    } else {
        Node* auxNode = first;

        for(int i = 1; i < pos - 1; i++) {
            auxNode = auxNode->getNext();
        }

        newNode->setPrevious(auxNode);
        newNode->setNext(auxNode->getNext());

        auxNode->getNext()->setPrevious(newNode);
        auxNode->setNext(newNode);
    }

    count++;
}

void CircularList::remove(int pos) {
    if(isEmpty() || pos < 1 || pos > length()) {
        return;
    }

    if(pos == length()) {
        Node* removeNode = last;

        last = removeNode->getPrevious();
        last->setNext(first);
        first->setPrevious(last);

        delete removeNode;
    } else {
        Node* removeNode = first;

        if(pos == 1) {
            first = removeNode->getNext();
            first->setPrevious(last);
            last->setNext(first);
        } else {
            for(int i = 1; i < pos; i++) {
                removeNode = removeNode->getNext();
            }

            removeNode->getPrevious()->setNext(removeNode->getNext());
            removeNode->getNext()->setPrevious(removeNode->getPrevious());
        }

        delete removeNode;
    }

    count--;
}

int CircularList::getValue(int pos) {
    if(isEmpty() || pos < 1 || pos > length()) {
        return -1;
    }

    Node* auxNode;

    if(pos > length() / 2) {
        auxNode = last;

        for(int i = length(); i > pos; i--) {
            auxNode = auxNode->getPrevious();
        }
    } else {
        auxNode = first;

        for(int i = 1; i < pos; i++) {
            auxNode = auxNode->getNext();
        }
    }

    return auxNode->getValue();
}

int CircularList::getPos(int value) {
    if(isEmpty()) {
        return -1;
    }

    Node* auxNode = first;

    for(int i = 1; i <= length(); i++) {
        if(auxNode->getValue() == value) {
            return i;
        }

        auxNode = auxNode->getNext();
    }

    return -1;
}

void CircularList::theDoleQueue(int jumpNext, int jumpPrevious) {
    Node* horario = last;
    Node* antihorario = first;

    while(1) {
        if(length() == 1) {
            cout << "  " << getValue(1) << endl;
            remove(1);
            return;
        }

        for(int i = 0; i < jumpNext; i++) {
            horario = horario->getNext();
        }

        for(int i = 0; i < jumpPrevious; i++) {
            antihorario = antihorario->getPrevious();
        }

        if(horario == antihorario) {
            int pos = getPos(horario->getValue());
            cout << " " << horario->getValue() << ", ";
            horario = horario->getPrevious();
            antihorario = antihorario->getNext();
            remove(pos);
            continue;
        }

        int posHorario = getPos(horario->getValue());
        cout << "  " << horario->getValue();
        horario = horario->getPrevious();
        remove(posHorario);

        int posAnti = getPos(antihorario->getValue());
        cout << "  " << antihorario->getValue() << ", ";
        antihorario = antihorario->getNext();
        remove(posAnti);
    }
}

int main(int argc, const char * argv[]) {
    int numberOfElements, jumpNext, jumpPrevious;

    while(cin >> numberOfElements >> jumpNext >> jumpPrevious) {
        if(numberOfElements == 0 && jumpNext == 0 && jumpPrevious == 0) {
            break;
        }

        CircularList list = CircularList();

        for(int i = 1; i <= numberOfElements; i++) {
            list.insert(i, i);
        }

        list.theDoleQueue(jumpNext, jumpPrevious);
    }

    return 0;
}
