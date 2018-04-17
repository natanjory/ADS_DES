#ifndef RNGEXP_H
#define RNGEXP_H

class rngExp {
public:
    rngExp(double vseed);
    double exp(double lambda);
    double myrand();

private:
    unsigned int seed;
};

#endif /* RNGEXP_H */

