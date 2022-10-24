#include "lockbroken.h"

LockBroken::LockBroken(Point m[], int k): Broken(m, k){
};
LockBroken::LockBroken(){
};
LockBroken::LockBroken(std::vector<Point> &m): Broken(m){
};
LockBroken::LockBroken(LockBroken &p): Broken(p){
};
void LockBroken::operator=(const LockBroken &t){
    v = t.v;
};
float LockBroken::getLength(){
    float t = Broken::getLength();
    t += pointToPoint(v[0], v[v.size() - 1]);
    return t;
};