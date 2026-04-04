#ifndef LIST_HPP
#define LIST_HPP
#include "Circle.hpp"
#include <cstddef>
#include <iostream>

class Node{
    friend class List;
    Node* pPrev;
    Node* pNext;
    Circle data;

public:
    Node();
    Node(Circle data);
    Node(Node* pPrev, Node* pNext, Circle data);
};

class List{
    Node* head;
    Node* tail;
    size_t size;
public:
    class Iterator{
        Node* ptr;
    public:
        Iterator(Node* ptr);
        Circle& operator*();
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Circle* operator->();
    };

    List();
    List(const List& other);
    List(List&& other);

    List& operator=(const List& other);
    List& operator=(List&& other);

    ~List();

    void push_back(Circle data);
    void push_front(Circle data);

    void pop_back();
    void pop_front();

    bool remove(Circle data);
    size_t remove_all(Circle data);

    size_t index(Circle data) const;
    size_t count(Circle data) const;

    bool is_empty() const;

    void clear();
    size_t get_size() const;

    Iterator begin() const;
    Iterator end() const;

    Circle& operator[](int i);
    const Circle& operator[](int i) const;

    void print();

    List copy(int from = 0, int to = -1) const;


    void insert(Circle data, size_t i);
    void erase(size_t i);

    void split(List& left,List& right);
    void sort();
    void reverse();

    void extend(List&& other);
    void extend(const List& other);
};

std::ostream& operator<<(std::ostream& out, const List& list);
std::istream& operator>>(std::istream& in, List& list);

#endif