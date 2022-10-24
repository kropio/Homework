#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

template <typename T>
class Rational{
    T num, den;
public:
    Rational():num(0), den(1){};
    Rational(const T value): num(value), den(1){};
    Rational(const T _num, const T _den): num(_num), den(_den){
        if (this->den < 0){
            this->num = -this->num;
            this->den = -this->den;
        }
        reduce();
    }
    Rational<T> operator=(const Rational<T> &other){
        num = other.num;
        den = other.den;
        return *this;
    }
    Rational<T> operator=(const T value){
        num = value;
        den = 1;
        return *this;
    }
    Rational<T> operator+(const Rational<T> &other) const{
        return Rational<T>{num * other.den + other.num * den, den*other.den};
    }
    Rational<T> operator += (const Rational<T> &other){
        *this = *this + other;
        return *this;
    }
    Rational<T> operator - (const Rational<T> &other) const{
        return -other + *this;
    }
    Rational<T> operator -=(const Rational<T> &other){
        *this = *this - other;
        return *this;
    }
    Rational<T> operator*(const Rational<T> &other) const{
        return Rational<T>{num*other.num, den*other.den};
    }
    Rational<T> operator*=(const Rational<T> &other){
        *this = *this * other;
        return *this;
    }
    Rational<T> operator/(const Rational<T> &other) const{
        return Rational<T>{num*other.den, den*other.num};
    }
    Rational<T> operator/=(const Rational<T> &other){
        *this = *this / other;
        return *this;
    }
    Rational<T> operator -()const{
        return Rational<T>{-num, den};
    }
    bool operator<(const Rational<T> &other) const{
        return num*other.den < other.num * den;
    }
    bool operator>(const Rational<T> &other) const{
        return other < *this;
    }
    bool operator<=(const Rational<T> &other) const{
        return !(other < *this);
    }
    bool operator>=(const Rational<T> &other) const{
        return !(*this < other);
    }
    bool operator==(const Rational<T> &other) const{
        return num == other.num && den == other.den;
    }
    bool operator!=(const Rational<T> &other) const{
        return !(*this == other);
    }
private:
    void reduce(){
        auto g = gcd(num < 0 ? -num : num, den);
        num /= g;
        den /= g;
    }

    T gcd(T a, T b) const{
        while(a){
            auto t = b % a;
            b = a;
            a = t;
        }
        return b;
    }
};
template<class T>
bool Less10(T t) {
    if(t < 10) return true;
    else return false;
 };

template<class T>
bool isNegative(T t) {
    if(t < 0) return true;
    else return false;
 };

template<typename T, typename P>
bool all_of(const T &s, const T &e, P &p) {
    for (T i = s; i != e; ++i){
        if (p(*i) == false) return false;
    }
    return true;
};

template<typename T, typename P>
bool any_of(const T &s, const T &e, P &p){
    for (T i = s; i != e; ++i){
        if(p(*i) == true) return true;
    }
    return false;
}

template<typename T, typename P>
bool none_of(const T &s, const T &e, P &p){
    for (T i = s; i != e; ++i){
        if(p(*i) == true) return false;
    }
    return true;
}

template<typename T, typename P>
bool one_of(const T &s, const T &e, P &p){
    int count = 0;
    for (T i = s; i != e; i++){
        if(p(*i) == true) {
        	if (count)
        		return false;
        	count++;
        }
    }
    if(count == 1) return true;
    else return false;
}

template<typename T, typename P>
bool is_sorted(const T &s, const T &e, P &p){
    for (T i = s; i != e; i++){
        i++;
        if (i != e){
            i--;
            T elem = i;
            i++;
            if(p(*elem, *i) == false) return false;
            i--;
        }
        else i--;
    }
    return true;
}

template<typename T, typename P>
bool is_partitioned(const T &s, const T &e, P &p){
    bool check = p(*s);
    bool switch_ch = false;
    for (T i = s; i != e; ++i){
        if((p(*i) == check) and switch_ch) return false;
        else if((p(*i) != check) and !(switch_ch)) switch_ch = true;
    }
    if(switch_ch) return true;
    else return false;
}

template<typename T, typename P>
P find_not(const T &s, const T &e, P p){
    for (T i = s; i != e; ++i){
        if (*i != p) return *i;
    }
    return p;
}

template<typename T, typename P>
bool is_palindrome(const T &s, const T &e, P &p){\
    for (T i = s, j = e; i != e; ++i, --j){
        if(p(*i) != p(*j)) return false;
    }
	return true;
}

int main(int argc, char **argv) {
    list<int> l;
    vector<char> v;
    set<float> s;
    vector<Rational<int>> vR;
    Rational<int> a(1, 2), b(2, 3), c(3, 4);
    vR.push_back(a);
    vR.push_back(b);
    vR.push_back(c);
    s.insert(-0.5);
    s.insert(-2.5);
    s.insert(-3.5);
    s.insert(-1.25);
    s.insert(-1.75);
    s.insert(-1.54);
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(4);
    cout << "is_palindrome list<int>: " << is_palindrome(l.begin(), l.end(), Less10<int>) << endl;
    cout << "is_palindrome vector<char>: " << is_palindrome(v.begin(), v.end(), Less10<char>) << endl;
    cout << "all_of set<float>: " << all_of(s.begin(), s.end(), isNegative<float>) << endl;
    cout << "one_of set<float>: " << one_of(s.begin(), s.end(), isNegative<float>) << endl;
    cout << "none_of set<float>: " << none_of(s.begin(), s.end(), isNegative<float>) << endl;
    cout << "find_not vector<char>: " << find_not(v.begin(), v.end(), 'a') << endl;
    cout << "find_not list<int>: " << find_not(l.begin(), l.end(), 1) << endl;
    return 0;
}
