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

  Float_t rebin_array_Mul2[] = {2301.0, 2312.31506348, 2391.31323242, 2440.03259277, 2502.04589844, 2561.97607422, 2661.17724609, 2755.32971191, 2869.36022949, 2978.96557617, 3073.21984863, 3278.89428711, 3527.24755859, 3669.45495605, 3991.19848633, 4358.59643555, 5019.79321289, 5994.77246094, 18344.0};
  Int_t  binmul2 = sizeof(rebin_array_Mul2)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul2 = new TH1F("h_ST_mul2", "h_ST_mul2", binmul2, rebin_array_Mul2);  
  TH1F *h_ST_mul2_2 = new TH1F("h_ST_mul2_2", "h_ST_mul2_2", binmul2, rebin_array_Mul2);
  Float_t rebin_array_Mul3[] = {2301.0, 2309.96337891, 2391.81286621, 2439.99291992, 2502.04589844, 2562.02258301, 2680.63330078, 2841.73779297, 2913.54675293, 3073.21984863, 3268.73937988, 3459.54919434, 3670.48852539, 3991.19848633, 4358.59643555, 5019.79321289, 5994.77246094, 18344.0};
  Int_t  binmul3 = sizeof(rebin_array_Mul3)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul3 = new  TH1F("h_ST_mul3", "h_ST_mul3", binmul3, rebin_array_Mul3);
  TH1F *h_ST_mul3_2 = new TH1F("h_ST_mul3_2", "h_ST_mul3_2", binmul3, rebin_array_Mul3);
  Float_t rebin_array_Mul4[] = {2301.0, 2391.81286621, 2474.71850586, 2559.99621582, 2648.60327148, 2733.00708008, 2887.9317627, 3073.21984863, 3299.70166016, 3604.15795898, 3993.94665527, 4488.73754883, 5528.6784668, 18344.0};
  Int_t  binmul4 = sizeof(rebin_array_Mul4)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul4 = new  TH1F("h_ST_mul4", "h_ST_mul4", binmul4, rebin_array_Mul4);
  TH1F *h_ST_mul4_2 = new TH1F("h_ST_mul4_2", "h_ST_mul4_2", binmul4, rebin_array_Mul4); 
  Float_t rebin_array_Mul5[] = {2601.0, 2656.54211426, 2730.27819824, 2887.3972168, 3143.91430664, 3298.72265625, 3603.90588379, 4276.359375, 5528.6784668, 9458.0};
  Int_t  binmul5 = sizeof(rebin_array_Mul5)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul5 = new  TH1F("h_ST_mul5", "h_ST_mul5", binmul5, rebin_array_Mul5);
  TH1F *h_ST_mul5_2 = new TH1F("h_ST_mul5_2", "h_ST_mul5_2", binmul5, rebin_array_Mul5);
  Float_t rebin_array_Mul6[] = {2601.0, 2656.54211426, 2869.10192871, 3045.43237305, 3285.37011719, 3600.796875, 4276.359375, 5556.0};
  Int_t  binmul6 = sizeof(rebin_array_Mul6)/sizeof(Float_t) - 1; 
  TH1F *h_ST_mul6 = new  TH1F("h_ST_mul6", "h_ST_mul6", binmul6, rebin_array_Mul6);
  TH1F *h_ST_mul6_2 = new TH1F("h_ST_mul6_2", "h_ST_mul6_2", binmul6, rebin_array_Mul6);
  Float_t rebin_array_Mul7[] = {2601.0, 2869.41308594, 3224.78112793, 3523.74511719, 4208.75463867, 5556.0, 20000.0};
  Int_t  binmul7 = sizeof(rebin_array_Mul7)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul7 = new  TH1F("h_ST_mul7", "h_ST_mul7", binmul7, rebin_array_Mul7);
  TH1F *h_ST_mul7_2 = new TH1F("h_ST_mul7_2", "h_ST_mul7_2", binmul7, rebin_array_Mul7);
  Float_t rebin_array_Mul8[] = {2801.0, 3287.79711914, 3826.43811035, 5556,5656,5756,5856,5956,6056,6156,6256,6356,6456,6556,6656,6756,6856,6956,7056,7156,7256,7356,7456,7556,7656,7756,7856,7956,8056,8156,8256,8356,8456,8556,8656,8756,8856,8956,9056,9156,9256,9356,9456,9556,9656,9756,9856,9956,10056,10156,10256,10356,10456,10556,10656,10756,10856,10956,11056,11156,11256,11356,11456,11556,11656,11756,11856,11956,12056,12156,12256,12356,12456,12556,12656,12756,12856,12956,13056,13156,13256,13356,13456,13556,13656,13756,13856,13956,14056,14156,14256,14356,14456,14556,14656,14756,14856,14956,15056,15156,15256,15356,15456,15556,15656,15756,15856,15956,16056,16156,16256,16356,16456,16556,16656,16756,16856,16956,17056,17156,17256,17356,17456,17556,17656,17756,17856,17956,18056,18156,18256,18356,18456,18556,18656,18756,18856,18956,19056,19156,19256,19356,19456,19556,19656,19756,19856,19956,20000.0}; 
  //Float_t rebin_array_Mul8[] = {2801.0, 3287.79711914, 3826.43811035, 5556.0};
  Int_t  binmul8 = sizeof(rebin_array_Mul8)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul8 = new  TH1F("h_ST_mul8", "h_ST_mul8", binmul8, rebin_array_Mul8);
  TH1F *h_ST_mul8_2 = new TH1F("h_ST_mul8_2", "h_ST_mul8_2", binmul8, rebin_array_Mul8);
  //Float_t rebin_array_Mul9[] = {2816.82543945, 3254.99914551, 3881.53466797, 20000.0};
  Float_t rebin_array_Mul9[] = {2816.82543945, 3254.99914551, 3881.53466797, 5556.0, 20000.0};
  Int_t  binmul9 = sizeof(rebin_array_Mul9)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul9 = new  TH1F("h_ST_mul9", "h_ST_mul9", binmul9, rebin_array_Mul9);
  TH1F *h_ST_mul9_2 = new TH1F("h_ST_mul9_2", "h_ST_mul9_2", binmul9, rebin_array_Mul9);
  Float_t rebin_array_Mul10[] = {2971.95605469, 3224.78112793, 5355.0, 20000.0};
  //Float_t rebin_array_Mul10[] = {2971.95605469, 3224.78112793, 5355.0};
  Int_t  binmul10 = sizeof(rebin_array_Mul10)/sizeof(Float_t) - 1;
  TH1F *h_ST_mul10 = new  TH1F("h_ST_mul10", "h_ST_mul10", binmul10, rebin_array_Mul10);
  TH1F *h_ST_mul10_2 = new TH1F("h_ST_mul10_2", "h_ST_mul10_2", binmul10, rebin_array_Mul10); 
 
  int nEvents=tree->GetEntries();
  std::cout << "nEvents= " << nEvents << std::endl;

  for (int i=0; i<nEvents; ++i)
    {
      tree->GetEvent(i);

      if(ST_mul2 > 2300){
        h_ST_mul2->Fill(ST_mul2, weightTree*kfactor);
        for(int j=1; j<binmul2+1; j++) {
          h_ST_mul2_2->SetBinContent(j, (h_ST_mul2->GetBinContent(j)/h_ST_mul2->GetBinWidth(j)));
          //if(h_ST_mul2->GetBinContent(j) > 0) std::cout << "h_ST_mul2->GetBinContent(j) = "<< h_ST_mul2->GetBinContent(j) << std::endl;
          //if(h_ST_mul2->GetBinContent(j) > 0) std::cout << "h_ST_mul2->GetBinWidth(j) = "<< h_ST_mul2->GetBinWidth(j) << std::endl;
        }
      }

      if(ST_mul3 > 2300){
        h_ST_mul3->Fill(ST_mul3, weightTree*kfactor);
        for(int j=1; j<binmul3+1; j++) {
          h_ST_mul3_2->SetBinContent(j, (h_ST_mul3->GetBinContent(j)/h_ST_mul3->GetBinWidth(j)));
        }
      }

      if(ST_mul4 > 2300){
        h_ST_mul4->Fill(ST_mul4, weightTree*kfactor);
        for(int j=1; j<binmul4+1; j++) {
          h_ST_mul4_2->SetBinContent(j, (h_ST_mul4->GetBinContent(j)/h_ST_mul4->GetBinWidth(j)));
        }
      }

      if(ST_mul5 > 2600){
        h_ST_mul5->Fill(ST_mul5, weightTree*kfactor);
        for(int j=1; j<binmul5+1; j++) {
          h_ST_mul5_2->SetBinContent(j, (h_ST_mul5->GetBinContent(j)/h_ST_mul5->GetBinWidth(j)));
        }
      }          

      if(ST_mul6 > 2600){
        h_ST_mul6->Fill(ST_mul6, weightTree*kfactor);
        for(int j=1; j<binmul6+1; j++) {
          h_ST_mul6_2->SetBinContent(j, (h_ST_mul6->GetBinContent(j)/h_ST_mul6->GetBinWidth(j)));
        }
      }

      if(ST_mul7 > 2600){
        h_ST_mul7->Fill(ST_mul7, weightTree*kfactor);
        for(int j=1; j<binmul7+1; j++) {
          h_ST_mul7_2->SetBinContent(j, (h_ST_mul7->GetBinContent(j)/h_ST_mul7->GetBinWidth(j)));
        }
      }

      if(ST_mul8 > 2800){
        h_ST_mul8->Fill(ST_mul8, weightTree*kfactor);
        for(int j=1; j<binmul8+1; j++) {
          h_ST_mul8_2->SetBinContent(j, (h_ST_mul8->GetBinContent(j)/h_ST_mul8->GetBinWidth(j)));
        }
      }

      if(ST_mul9 > 2800){
        h_ST_mul9->Fill(ST_mul9, weightTree*kfactor);
        for(int j=1; j<binmul9+1; j++) {
          h_ST_mul9_2->SetBinContent(j, (h_ST_mul9->GetBinContent(j)/h_ST_mul9->GetBinWidth(j)));
        }
      }

      if(ST_mul10 > 2900){
        h_ST_mul10->Fill(ST_mul10, weightTree*kfactor);
        for(int j=1; j<binmul10+1; j++) {
          h_ST_mul10_2->SetBinContent(j, (h_ST_mul10->GetBinContent(j)/h_ST_mul10->GetBinWidth(j)));
        }
      }

    }

   std::string histfilename=(outfile+".root").c_str();
   TFile *tFile=new TFile(histfilename.c_str(), "RECREATE");
   h_ST_mul2->Write();
   h_ST_mul2_2->Write();
   h_ST_mul3->Write();
   h_ST_mul3_2->Write();
   h_ST_mul4->Write();
   h_ST_mul4_2->Write();
   h_ST_mul5->Write();
   h_ST_mul5_2->Write();
   h_ST_mul6->Write();
   h_ST_mul6_2->Write();
   h_ST_mul7->Write();
   h_ST_mul7_2->Write();
   h_ST_mul8->Write();
   h_ST_mul8_2->Write();
   h_ST_mul9->Write();
   h_ST_mul9_2->Write();
   h_ST_mul10->Write();
   h_ST_mul10_2->Write();
   tFile->Close(); 
   std::cout<<"Wrote output file "<<histfilename<<std::endl;
   for(int j=1; j<binmul2+1; j++) {
        h_ST_mul2_2->SetBinContent(j, (h_ST_mul2->GetBinContent(j)/h_ST_mul2->GetBinWidth(j)));
        if(h_ST_mul2->GetBinContent(j) > 0) std::cout << "h_ST_mul2->GetBinContent(j) = "<< h_ST_mul2->GetBinContent(j) << std::endl;
        if(h_ST_mul2->GetBinContent(j) > 0) std::cout << "h_ST_mul2->GetBinWidth(j) = "<< h_ST_mul2->GetBinWidth(j) << std::endl;
     }
   h_ST_mul2_2->Draw();
   double binx1 = h_ST_mul2_2->FindBin(2301);
   double binx2 = h_ST_mul2_2->FindBin(14140.3828125);
   cout << "h_ST_mul2_2->Integral(binx1, binx2) = " << h_ST_mul2_2->Integral(binx1, binx2) << endl;
   return 0;

  
}
