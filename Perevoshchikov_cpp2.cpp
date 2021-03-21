#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Polynom{
    private:
        vector<float> coef;

    public:
        Polynom(){};
        
        Polynom(int k, float m[]){
            for (int i = 0; i < k; i++){
                coef.push_back(m[i]);
            };
        };
        Polynom(vector<float> &m){
            coef = m;
        };
        Polynom(Polynom &m){
            coef = m.coef;
        };

        void operator=(const Polynom &m){
            coef = m.coef;
        };

        bool operator==(const Polynom &m){
            return coef == m.coef;
        };

        bool operator!=(const Polynom &m){
            return !(coef == m.coef);
        }

        Polynom operator+(const Polynom &m){
            Polynom tmp;
            if(m.coef.size() > coef.size()){
                for(int i = 0; i < coef.size(); i++){
                tmp.coef.push_back(m.coef[i] + coef[i]);
                }
                for(int i = coef.size(); i < m.coef.size(); i++){
                tmp.coef.push_back(m.coef[i]);
                }
            }
            else{
                for(int i = 0; i < m.coef.size(); i++){
                tmp.coef.push_back(m.coef[i] + coef[i]);
                }
                for(int i = m.coef.size(); i < coef.size(); i++){
                tmp.coef.push_back(coef[i]);
                }
            }
            return tmp;
        };

        Polynom operator-(const Polynom &m){
            Polynom tmp;
            if(m.coef.size() > coef.size()){
                for(int i = 0; i < coef.size(); i++){
                tmp.coef.push_back(coef[i] - m.coef[i]);
                }
                for(int i = coef.size(); i < m.coef.size(); i++){
                tmp.coef.push_back(-m.coef[i]);
                }
            }
            else{
                for(int i = 0; i < m.coef.size(); i++){
                tmp.coef.push_back(coef[i] - m.coef[i]);
                }
                for(int i = m.coef.size(); i < coef.size(); i++){
                tmp.coef.push_back(coef[i]);
                }
            }
            return tmp;
        };

        Polynom operator-() const{
            Polynom m;
            for(int i = 0; i < coef.size(); i++){
                m.coef.push_back(-coef[i]);
            }
            return m;
        };
        
        Polynom& operator++(){
            coef[0]++;
            return *this;        
        };
        
        Polynom operator++(int){
            Polynom tmp(coef);

            ++(*this);
            return tmp;        
        };

        Polynom& operator--(){
            coef[0]--;
            return *this;        
        };
        
        Polynom operator--(int){
            Polynom tmp(coef);

            --(*this);
            return tmp;        
        };

        void operator+=(const Polynom &m){
            *this = *this + m;
        };

        void operator-=(const Polynom &m){
            *this = *this - m;
        };

        Polynom operator*(const Polynom &m) const{
            Polynom tmp;
            for(int i = 0; i < m.coef.size() + coef.size() - 1; i++){
                tmp.coef.push_back(0);
            }
            for(int i = 0; i < coef.size(); i++){
                if (coef[i] != 0){
                    for(int j = 0; j < m.coef.size(); j++){
                        tmp.coef[i+j] += coef[i]*m.coef[j];
                    }
                }
            }
            return tmp;
        };

        Polynom operator/(float m) const{
            Polynom tmp;
            for(int i = 0; i < coef.size(); i++){
                tmp.coef.push_back(coef[i]/m);
            }
            return tmp;
        };

        void operator*=(const Polynom &m){
            *this = *this*m;
        };

        void operator/=(float m){
            *this = *this/m;
        };

        void operator<<(int k){
            for(int i = 0; i < k; i++){
                coef.insert(coef.begin(), 0);
            }
        };

        void operator>>(int k){
            for(int i = 0; i < k; i++){
                coef.erase(coef.begin());
            }
        };

        float operator[](int k){
            return coef[k];
        };

        void show(){
            for(int i = coef.size() - 1; i > 0; i--){
                if (coef[i] != 0){
                cout << coef[i] << "*x^" << i << " + "; 
                }
            }
            cout << coef[0] << endl;
        }
        ~Polynom(){
            delete(&coef);
        };
};

int main(){
    float m[] = {1, 2, 1};
    float n[] = {1, 2, 3, 4};
    float z[] = {1, 1};
    Polynom A(3, m);
    Polynom B(4, n);
    Polynom C;
    Polynom D(2, z);
    A.show();
    C = A;
    C.show();
    C -= B;
    C.show();
    C += B;
    C.show();
    D *= D;
    D.show();
    cout << (A == A) << endl;
    cout << (A != A) << endl;
    cout << (A == D) << endl;
    cout << (A != B) << endl;
    cout << A[1] << endl;
    D /= 2;
    D.show();
    A = -A;
    A.show();
    A = -A;
    A.show();
    A++;
    A.show();
    ++A;
    A.show();
    A--;
    A.show();
    --A;
    A.show();
    A<<1;
    A.show();
    A>>1;
    A.show(); 
}