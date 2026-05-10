#include "Circle.hpp"
#include "List.hpp"
#include <iostream>
#include <utility>


Node::Node():pPrev(nullptr),pNext(nullptr),data(){}

Node::Node(Circle data):pPrev(nullptr),pNext(nullptr),data(data){}

Node::Node(Node* pPrev, Node* pNext, Circle data):pPrev(pPrev),pNext(pNext),data(data){}


List::Iterator::Iterator(Node* ptr):ptr(ptr){}

Circle& List::Iterator::operator*(){
    return ptr->data;
}

List::Iterator& List::Iterator::operator++(){
    ptr = ptr->pNext;
    return *this;
}

bool List::Iterator::operator==(const Iterator& other) const{
    return ptr == other.ptr;
}

bool List::Iterator::operator!=(const Iterator& other) const{
    return ptr != other.ptr;
}

Circle* List::Iterator::operator->(){
    return &ptr->data;
}



List::List():head(nullptr),tail(nullptr),size(0){}

List::List(const List& other):head(nullptr),tail(nullptr),size(0){
    for(Node* tmp = other.head; tmp != nullptr; tmp = tmp->pNext){
        push_back(tmp->data);
    }
}

List::List(List&& other):head(other.head),tail(other.tail),size(other.size){
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}


List& List::operator=(const List& other){
    if(this == &other) return *this;
    clear();
    for(Node* tmp = other.head; tmp != nullptr; tmp = tmp->pNext){
        push_back(tmp->data);
    }
    return *this;
}
List& List::operator=(List&& other){
    if(this == &other) return *this;
    clear();
    head = other.head;
    tail = other.tail;
    size = other.size;
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
    return *this;
}

List::~List(){
    clear();
}

void List::push_back(Circle data){
    Node* new_node = new Node(data);
    if(head == nullptr){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->pNext = new_node;
        new_node->pPrev = tail;
    }
    tail = new_node;
    size++;
}

void List::push_front(Circle data){
    Node* new_node = new Node(data);
    if(head == nullptr){
        head = new_node;
        tail = new_node;
    }
    else{
        head->pPrev = new_node;
        new_node->pNext = head;
    }
    head = new_node;
    size++;
}

bool List::is_empty() const{
    return head == nullptr;
}

size_t List::get_size() const{
    return size;
}

List::Iterator List::begin() const{
    return Iterator(head);
}

List::Iterator List::end() const{
    return Iterator(nullptr);
}

void List::pop_back(){
    if(is_empty()){
        throw "empty list";
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* tmp = tail;
        tail = tail->pPrev;
        tail->pNext = nullptr;
        delete tmp;
    }
    size--;
}

void List::pop_front(){
    if(is_empty()){
        throw "empty list";
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* tmp = head;
        head = head->pNext;
        head->pPrev = nullptr;
        delete tmp;
    }
    size--;
}

bool List::remove(Circle data){
    if(is_empty()){
        return false;
    }
    for(Node* tmp = head; tmp != nullptr; tmp = tmp->pNext){
        if(tmp->data == data){
            if(tmp == head){
                pop_front();
            }
            else if(tmp == tail){
                pop_back();
            }
            else{
                tmp->pPrev->pNext = tmp->pNext;
                tmp->pNext->pPrev = tmp->pPrev;
                delete tmp;
                size--;
            }
            return true;
        }
    }
    return false;
}


size_t List::count(Circle data) const{
    size_t res = 0;
    for(Node* tmp = head; tmp != nullptr; tmp = tmp->pNext){
        if(tmp->data == data){
            res++;
        }
    }
    return res;
}

size_t List::index(Circle data) const{
    size_t res = 0;
    for(Node* tmp = head; tmp != nullptr; tmp = tmp->pNext){
        if(tmp->data == data){
            return res;
        }
        res++;
    }
    return res;
}

size_t List::remove_all(Circle data){
    size_t res = 0;
    if(is_empty()) return res;
    Node* tmp = head;
    while(tmp != nullptr){
        Node* next_node = tmp->pNext;
        if(tmp->data == data){
            if(tmp == head){
                pop_front();
            }
            else if(tmp == tail){
                pop_back();
            }
            else{
                tmp->pPrev->pNext = tmp->pNext;
                tmp->pNext->pPrev = tmp->pPrev;
                delete tmp;
                size--;
            }
            res++;
        } 
        tmp = next_node;
    }
    return res;
}

void List::clear(){
    while(!is_empty()){
        pop_front();
    }
}

Circle& List::operator[](int i){
    if(i<0) i=size+i;

    if(i>=size){
        throw "index out of range";
    }
    if(i<size/2){
        Node* tmp = head;
        for(size_t j = 0; j<i; j++){
            tmp = tmp->pNext;
        }
        return tmp->data;
    }
    else{
        Node* tmp = tail;
        for(size_t j = size-1; j>i; j--){
            tmp = tmp->pPrev;
        }
        return tmp->data;
    }
}

const Circle& List::operator[](int i) const{
    if(i<0) i=size+i;
    if(i>=size){
        throw "index out of range";
    }
    if(i<size/2){
        Node* tmp = head;
        for(size_t j = 0; j<i; j++){
            tmp = tmp->pNext;
        }
        return tmp->data;
    }
    else{
        Node* tmp = tail;
        for(size_t j = size-1; j>i; j--){
            tmp = tmp->pPrev;
        }
        return tmp->data;
    }
}

void List::print(){
    size_t i = 0;
    for(Node* tmp = head; tmp != nullptr; tmp = tmp->pNext){
        std::cout<<i++<<") "<<"x: "<<tmp->data.get_centre().x<<" y: "<<tmp->data.get_centre().y<<" raduis: "<<tmp->data.get_radius()<<std::endl;
    }
    std::cout<<std::endl;
}

List List::copy(int from,int to) const{
    List res;
    for(int i = from; i<to; i++){
        res.push_back((*this)[i]);
    }
    return res;
}

void List::reverse(){
    if(is_empty()) return;
    Node* tmp = head;
    head = tail;
    tail = tmp;
    while(tmp != nullptr){
        Node* next_node = tmp->pNext;
        tmp->pNext = tmp->pPrev;
        tmp->pPrev = next_node;
        tmp = next_node;
    }
}

void List::extend(List&& other){
    if(is_empty()){
        *this = std::move(other);
        return;
    }
    if(other.is_empty()){
        return;
    }
    tail->pNext = other.head;
    other.head->pPrev = tail;
    tail = other.tail;
    size += other.size;
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

void List::extend(const List& other){
    for(Node* tmp = other.head; tmp != nullptr; tmp = tmp->pNext){
        push_back(tmp->data);
    }
}

void List::insert(Circle data, size_t i){
    if(i>size){
        throw "index out of range";
    }
    if(i==0){
        push_front(data);
        return;
    }
    if(i==size){
        push_back(data);
        return;
    }
    Node* new_node = new Node(data);
    Node* tmp = head;
    for(size_t j = 0; j<i-1; j++){
        tmp = tmp->pNext;
    }
    new_node->pPrev = tmp;
    new_node->pNext = tmp->pNext;
    tmp->pNext->pPrev = new_node;
    tmp->pNext = new_node;
    size++;
}

void List::erase(size_t i){
    if(i>=size){
        throw "index out of range";
    }
    if(i==0){
        pop_front();
        return;
    }
    if(i==size-1){
        pop_back();
        return;
    }
    Node* tmp = head;
    for(size_t j = 0; j<i; j++){
        tmp = tmp->pNext;
    }
    tmp->pPrev->pNext = tmp->pNext;
    tmp->pNext->pPrev = tmp->pPrev;
    delete tmp;
    size--;
}

void List::split(List& left, List& right){
    if(!left.is_empty()) left.clear();
    if(!right.is_empty()) right.clear();
    left.head = head;
    right.tail = tail;
    Node* tmp = head;
    for(size_t i = 0; i <size/2; i++){
        tmp = tmp->pNext;
    }
    tmp->pPrev->pNext = nullptr;
    left.tail = tmp->pPrev;
    left.size = size/2;
    tmp->pPrev = nullptr;
    right.head = tmp;
    right.size = size-left.size;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

static List merge(List&& left, List&& right){
    List res;
    while(!left.is_empty() && !right.is_empty()){
        if(left[0].get_area() < right[0].get_area()){
            res.push_back(left[0]);
            left.pop_front();
        }
        else{
            res.push_back(right[0]);
            right.pop_front();
        }
    }
    res.extend(std::move(left));
    res.extend(std::move(right));
    return res;
}

void List::sort(){
    if(size<=1) return;
    List left,right;
    split(left,right);
    left.sort();
    right.sort();
    *this = std::move(merge(std::move(left),std::move(right)));
}


std::ostream& operator<<(std::ostream& out, const List& list){
    for(List::Iterator it = list.begin(); it != list.end(); ++it){
        out << it->get_centre().x << " " << it->get_centre().y << " " << it->get_radius() << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, List& list){
    double x, y, r;
    while(in >> x >> y >> r){
        list.push_back(Circle(x, y, r));
    }
    return in;
}