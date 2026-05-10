#include "barrel.hpp"
Barrel::Barrel(double V, double concentration): V(V), conc(concentration),max_V(V){};
void Barrel::fill_to_other(Barrel& other,double tV){
    double tcV = tV*(conc) + other.V*other.conc;
    other.V += tV;
    other.conc = tcV/V;
    if (other.max_V<V) other.V = max_V;
    V -= tV;
    if (V<0) V = 0;
}

double Barrel::get_conc(){
    return conc;
}