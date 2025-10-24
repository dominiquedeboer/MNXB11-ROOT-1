# pragma once
# include <TObject.h>

class particle : public TObject {
    public:
        particle(); // default constructor
        particle(Double_t x, Double_t y, Double_t z); // some other constructor
        virtual ~particle(); // destructor

        Double_t getMagnitude() const;

    private:
        Double_t px;
        Double_t py;
        Double_t pz;

    ClassDef(particle, 1);
};