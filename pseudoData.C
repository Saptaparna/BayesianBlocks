#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"
#include <TCanvas.h>
#include <TLatex.h>
#include "TGraphErrors.h"
#include "TLegend.h"
#include <TPad.h>
#include <sstream>
#include "TVectorD.h"
#include "TChain.h"
#include "TGraph.h"
#include "TFile.h"
#include "TH1F.h"
#include "Taxis.h"
#include "TF1.h"

using std::string;
using std::cout;
using std::endl;
using std::istringstream;

void pseudoData(){

  TCanvas* c1 = new TCanvas("c1", "c1", 600, 400);
  
  TF1 *fa1 = new TF1("fa1","2.3949e+06*3.74*(0.67472+x/(13000.0))^(-10.1809)", 2600, 20000); 
  double x1 = fa1->GetRandom(); 
  TH1F *h1 = new TH1F("h1", "h1", 174, 2600.0, 20000.0);
  h1->FillRandom("fa1", 100000);
  c1->SetLogy();
  h1->Draw();



} 
