#ifndef BARREL_HPP
#define BARREL_HPP
class Barrel{
    double max_V;
    double V;
    double conc = 0.0;
public:
    Barrel(double V, double concentration);
    void fill_to_other(Barrel& other,double tV);
    double get_conc();
};
#endif