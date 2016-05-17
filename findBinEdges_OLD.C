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

using std::string;
using std::cout;
using std::endl;
using std::istringstream;

void findBinEdges(std::string outfile){

  TFile* fileData = TFile::Open("StandardBinned_BH_Tree_QCD_HT-2000_inf_25ns.root");
  TH1F *h_ST_mul8 = (TH1F*) fileData->Get("h_ST_mul8");
  TH1F *h_ST_mul8_Corr = (TH1F*) h_ST_mul8->Clone("h_ST_mul8_Corr");
  int nbins = (int) h_ST_mul8_Corr->GetXaxis()->GetNbins();
  cout << "nbins = " << nbins << endl;
  int counter=0;

  double nominalContent = 0.0001;

  for (int ibin = 1; ibin <= nbins; ibin++){
    if(h_ST_mul8_Corr->GetBinContent(ibin)==0){
      h_ST_mul8_Corr->SetBinContent(ibin, nominalContent);
      counter++;
    }
  }

  if(h_ST_mul8_Corr->Integral() > 0.0) h_ST_mul8_Corr->Scale(h_ST_mul8->Integral()/h_ST_mul8_Corr->Integral());

  /*
  for (int ibin = 1; ibin <= nbins; ibin++){
    if(h_ST_mul8->GetBinContent(ibin)==0){
      cout << "ibin = " << ibin << endl;
      counter++;
    }
  }
  cout << "counter = " << counter << endl; 

  for (double_t xvalue = 2800.0; xvalue<=20000.0; xvalue++){
    cout << "xvalue = " << xvalue << " number = " << h_ST_mul8->GetXaxis()->FindBin(xvalue) << endl;

  }*/
 
  std::string histfilename=(outfile+".root").c_str();
  TFile *tFile=new TFile(histfilename.c_str(), "RECREATE");
  h_ST_mul8_Corr->Write();
}
