#include "particle.h"
#include <TFile.h>
#include <TTree.h>
# include <TRandom.h>

void write(){

// Create your root file here
TFile *f = new TFile("tree_file.root", "RECREATE");
// Create your TTree here
TTree *T = new TTree("T", "particle tree");
// Initialize your object e.g. as a pointer
particle *p = nullptr;
// And the associated branches underneath
T->Branch("particle", "particle", &p);
// for example a branch with your personal object type

// Now we create our loop for filling the tree with some random data
// For loop here
const Int_t nEvents = 100;
for (Int_t i{0}; i<nEvents; i++){ // define how many events you want
    // Initialize your new object below
    Double_t px = gRandom->Gaus(0, .02);
    Double_t py = gRandom->Gaus(0, .02);
    Double_t pz = gRandom->Gaus(0, .02);
    // Now fill tree
    p = new particle(px, py, pz);
    T->Fill();
    // Remember to delete it again otherwise you will have memory leak!
    delete p;
    p = nullptr;
}
// save the tree/file
T->Write();
f->Close();
delete f;

}