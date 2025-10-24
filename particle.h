# pragma once
# include <TObject.h>

class particle : public TObject {
    public:
        particle(); // default constructor
        particle(Double_t x, Double_t y, Double_t z); // some other constructor
        virtual ~particle(); // destructor

        Double_t getMagnitude() const;

        Double_t getPx() const { 
            return px; 
        }
        Double_t getPy() const { 
            return py; 
        }
        Double_t getPz() const { 
            return pz; 
        }


    private:
        Double_t px;
        Double_t py;
        Double_t pz;

    ClassDef(particle, 1);
};