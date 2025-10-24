#include "particle.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TCanvas.h>

void read(){
// initialize your object
particle *p = nullptr;
// open your file
// TFile *f = new TFile("tree_file.root", "READ");
auto file = TFile::Open("tree_file.root");
// get your tree
TTree *T = static_cast<TTree*>(file->Get("T"));
// remember to set the branch address
T->SetBranchAddress("p", &p);
Int_t N = T->GetEntries();

TH2F *hist = new TH2F("hist", "px over py", 50, -0.1, 0.1, 50, -0.1, 0.1);
for (Int_t i{0}; i<N; i++){ // loop over the whole tree
    T->GetEntry(i);
    hist->Fill(p->getMagnitude(), p->getMagnitude());
// do something
}
TCanvas *c = new TCanvas("c", "px over py", 800, 600);
hist->Draw("COLZ");
}
