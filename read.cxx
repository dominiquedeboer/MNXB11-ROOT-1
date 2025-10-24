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

TH2F *h1 = new TH2F("h1", "px over py", 50, -0.1, 0.1, 50, -0.1, 0.1);
for (Int_t i{0}; i<N; i++){ // loop over the whole tree
    T->GetEntry(i);
    h1->Fill(p->getMagnitude(), p->getMagnitude());
// do something
}
auto canvas1 = TCanvas("c1", "", 800, 600);
h1->Draw("P");
// canvas1->SaveAS("px_vs_py.pdf");

auto canvas2 = TCanvas("c2", "", 800, 600);
T->Draw("px*py:pz", "getMagnitude()>0.01", "COLZ");
// canvas2->SaveAs("pxpy_vs_pz.pdf");

}
