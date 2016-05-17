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
#include "TChain.h"
#include "TGraph.h"
#include "TFile.h"

using std::string;
using std::cout;
using std::endl;
using std::istringstream;

int makeLimitTemplates(std::string infile, std::string outfile, double kfactor){

  std::string inputfilename=(infile+".root").c_str();
  TChain *tree=new TChain("BH_Tree");
  tree->Add(inputfilename.c_str());
  std::cout<<"Opened input file "<<inputfilename<<std::endl;

  Double_t         ST_mul2;
  Double_t         ST_mul3;
  Double_t         ST_mul4;
  Double_t         ST_mul5;
  Double_t         ST_mul6;
  Double_t         ST_mul7;
  Double_t         ST_mul8;
  Double_t         ST_mul9;
  Double_t         ST_mul10;
  Int_t            n_multiplicity;
  Double_t         weightTree;

  tree->SetBranchAddress("ST_mul2", &(ST_mul2));
  tree->SetBranchAddress("ST_mul3", &(ST_mul3));
  tree->SetBranchAddress("ST_mul4", &(ST_mul4));
  tree->SetBranchAddress("ST_mul5", &(ST_mul5));
  tree->SetBranchAddress("ST_mul6", &(ST_mul6));
  tree->SetBranchAddress("ST_mul7", &(ST_mul7));
  tree->SetBranchAddress("ST_mul8", &(ST_mul8));
  tree->SetBranchAddress("ST_mul9", &(ST_mul9));
  tree->SetBranchAddress("ST_mul10", &(ST_mul10));
  tree->SetBranchAddress("n_multiplicity", &(n_multiplicity));
  tree->SetBranchAddress("weightTree", &(weightTree));
  //using 2.2 ifb of data now
  //scale values: 1000_1500: 1064.0*2.2*1000.0*1.20/4963895.0
  //scale values: 1500_2000: 121.5*2.2*1000.0*1.20/3868886.0
  //scale values: 2000_inf : 25.4*2.2*1000.0*1.20/1961774.0 

  TH1F *h_ST_mul2 = new TH1F("h_ST_mul2", "h_ST_mul2", 177, 2300.0, 20000.0);  
  TH1F *h_ST_mul3 = new  TH1F("h_ST_mul3", "h_ST_mul3", 177, 2300.0, 20000.0);
  TH1F *h_ST_mul4 = new  TH1F("h_ST_mul4", "h_ST_mul4", 177, 2300.0, 20000.0);
  TH1F *h_ST_mul5 = new  TH1F("h_ST_mul5", "h_ST_mul5", 174, 2600.0, 20000.0);
  TH1F *h_ST_mul6 = new  TH1F("h_ST_mul6", "h_ST_mul6", 174, 2600.0, 20000.0);
  TH1F *h_ST_mul7 = new  TH1F("h_ST_mul7", "h_ST_mul7", 174, 2600.0, 20000.0);
  TH1F *h_ST_mul8 = new  TH1F("h_ST_mul8", "h_ST_mul8", 172, 2800.0, 20000.0);
  TH1F *h_ST_mul9 = new  TH1F("h_ST_mul9", "h_ST_mul9", 172, 2800.0, 20000.0);
  TH1F *h_ST_mul10 = new  TH1F("h_ST_mul10", "h_ST_mul10", 171, 2900.0, 20000.0);
  
  int nEvents=tree->GetEntries();
  std::cout << "nEvents= " << nEvents << std::endl;

  for (int i=0; i<nEvents; ++i)
    {
      tree->GetEvent(i);

      if(ST_mul2 > 2300){
        h_ST_mul2->Fill(ST_mul2, weightTree*kfactor);
      }

      if(ST_mul3 > 2300){
        h_ST_mul3->Fill(ST_mul3, weightTree*kfactor);
      }

      if(ST_mul4 > 2300){
        h_ST_mul4->Fill(ST_mul4, weightTree*kfactor);
      }

      if(ST_mul5 > 2600){
        h_ST_mul5->Fill(ST_mul5, weightTree*kfactor);
      }          

      if(ST_mul6 > 2600){
        h_ST_mul6->Fill(ST_mul6, weightTree*kfactor);
      }

      if(ST_mul7 > 2600){
        h_ST_mul7->Fill(ST_mul7, weightTree*kfactor);
      }

      if(ST_mul8 > 2800){
        h_ST_mul8->Fill(ST_mul8, weightTree*kfactor);
      }

      if(ST_mul9 > 2800){
        h_ST_mul9->Fill(ST_mul9, weightTree*kfactor);
      }

      if(ST_mul10 > 2900){
        h_ST_mul10->Fill(ST_mul10, weightTree*kfactor);
      }

    }

   std::string histfilename=(outfile+".root").c_str();
   TFile *tFile=new TFile(histfilename.c_str(), "RECREATE");
   h_ST_mul2->Write();
   h_ST_mul3->Write();
   h_ST_mul4->Write();
   h_ST_mul5->Write();
   h_ST_mul6->Write();
   h_ST_mul7->Write();
   h_ST_mul8->Write();
   h_ST_mul9->Write();
   h_ST_mul10->Write();
   tFile->Close(); 
   std::cout<<"Wrote output file "<<histfilename<<std::endl;
   return 0;
  
}
