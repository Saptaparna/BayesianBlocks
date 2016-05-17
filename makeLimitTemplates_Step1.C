#include "TH1.h"
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
#include "TGraph.h"

using std::string;
using std::cout;
using std::endl;
using std::istringstream;

void makeLimitTemplates_Step1(std::string infile, std::string outfile){

  Double_t rebin_array_Mul2[15] = {2301,  2377.23449707,  2432.49060059,  2506.68054199, 2559.92858887, 2680.19091797, 2869.34680176, 3061.03283691, 3225.67944336, 3454.38293457, 3661.93933105, 3993.7598877, 4289.68041992, 5543.83276367, 14140.3828125};
  
  TFile* file0 = TFile::Open("LimitTemplate_Step0_QCD_HT-2000_inf_25ns_Double.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul2");  
  TH1F *h0_rebin = (TH1F*)h0->Rebin(14, "h0_rebin", rebin_array_Mul2);  
  
  std::string histfilename=(outfile+".root").c_str();
  TFile *tFile=new TFile(histfilename.c_str(), "RECREATE");
  h0_rebin->Write();





} 
