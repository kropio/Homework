#include "broken.h"

float Broken::pointToPoint(Point &a, Point &b) const{
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}
Broken::Broken(){
};
Broken::Broken(Point m[], int k){
    for(int i = 0; i < k; i++)
    v.push_back(m[i]);
};
Broken::Broken(std::vector<Point> &m){
    v = m;
};
Broken::Broken(Broken &p){
    v = p.v;
};
void Broken::operator=(const Broken &t){
    v = t.v;
};
float Broken::getLength(){
    float t = 0;
    for(int i = 0; i < v.size() - 1; i++) t += pointToPoint(v[i], v[i + 1]);
    return t;
};