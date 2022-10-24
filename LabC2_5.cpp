#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<class T>
class ringBuffer{
    private:
        T* data = nullptr;
        unsigned int capacity;
        unsigned int amountOfContent;
    public:
        
        class Iterator : public iterator<random_access_iterator_tag, T> {
    private:
        T *current;
    public:
        
        Iterator &operator+=(int value) {
            current += value;
            return *this;
        }

        Iterator operator+(int value) {
            current += value;
            return *this;
        }

        Iterator &operator++() {
            ++current;
            return *this;
        }

        Iterator &operator-=(int value) {
            *this += -value;
            return *this;
        }

        Iterator operator-(int value) {
            current -= value;
            return *this;
        }

        int operator-(const Iterator &other) {
            return current - other.current;
        }

        Iterator operator--() {
            current--;
            return *this;
        }

        T &operator*() const {
            return *current;
        }

        [[nodiscard]] T *getCurrent() const {
            return current;
        }    

        T *operator->() const {
            return current;
        }

        Iterator &operator=(T *other) {
            current = other;
            return *this;
        }

        bool operator==(const Iterator &other) {
            return current = other.current;
        }

        bool operator!=(const Iterator &other) {
            return current != other.current;
        }

        bool operator>(const Iterator &other) {
            return current > other.current;
        }

        bool operator>=(const Iterator &other) {
            return current >= other.current;
        }

        bool operator<(const Iterator &other) {
            return current < other.current;
        }

        bool operator<=(const Iterator &other) {
            return current <= other.current;
        }

        explicit Iterator(T *current) {
            this->current = current;
        }
        };
        ringBuffer(unsigned int userCapacity):
            capacity(userCapacity),
            amountOfContent(0),
            data(new T[userCapacity]){}

        ringBuffer(const ringBuffer& tmp):
            capacity(tmp.capacity),
            amountOfContent(tmp.amountOfContent),
            data(tmp.data){}

        ~ringBuffer(){
            delete []data;
        }

        bool isEmpty()const{
            return amountOfContent == 0;
        }

        bool isFull()const{
            return capacity == amountOfContent;
        }

        Iterator begin(){
            return Iterator(data);
        }

        Iterator end(){
            return Iterator(data + amountOfContent);
        }
        
        void operator=(ringBuffer &other){
            capacity = other.capacity;
            amountOfContent = other.amountOfContent;
            data = new T[capacity];
        }

        T operator[](unsigned ind){
                    return data[ind];
        }

        
        void write_back(T elem){
            if (isFull()){
                throw runtime_error("Not enough space");
            }
            amountOfContent++;
            data[amountOfContent - 1] = elem;
        }

        void write_front(T elem){
            if (isFull()){
                throw runtime_error("Not enough space");
            }
            for(int i = amountOfContent; i > 0; i--){
                data[i] = data[i-1];
            }
            data[0] = elem;
            amountOfContent++;
        }

        void del_back(){
            data[amountOfContent-1] = 0;
            amountOfContent--;
        }

        void del_front(){
            for(int i = 1; i < amountOfContent; i++){
                data[i-1] = data[i];
            }
            amountOfContent--;
        }

        T show_front(){
            return data[0];
        }

        T show_back(){
            return data[amountOfContent-1];
        }

        void capacityChange(unsigned int newCapacity){
            T *newData = new T[newCapacity];
            for(int i = 0; i < newCapacity; i++){
                if(i == capacity){break;}
                newData[i] = data[i]; 
            }
            data = newData;
            capacity = newCapacity;
        }

        void show(){
            cout << "[";
            for(int i = 0; i < amountOfContent - 1; i++){
                cout << data[i] << ",";
            }
            cout << data[amountOfContent - 1] << "]" << endl;
        }
};

void more2(const int &n){
        cout << (n > 2) << " ";
}

int main(){
    int arr[] = {1,2,3};
    unsigned int t = 6;
    ringBuffer<int> tmp(3);
    tmp.write_back(1);
    tmp.write_back(2);
    tmp.write_back(3);
    tmp.show();
    tmp.del_front();
    tmp.write_back(4);
    tmp.show();
    for(const auto &elem: tmp){
        cout << elem << " ";
    }
    cout << endl;
    sort(tmp.begin(), tmp.end());
    tmp.show();

    
    for_each(tmp.begin(), tmp.end(), more2);
    return 0;
}