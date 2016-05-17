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

int makeLimitTemplatesROOTFile_QCD_HT_2000_inf_25ns(){

  TFile* file0 = TFile::Open("output_BH_Tree_QCD_HT-2000_inf_25ns.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");  
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_QCD_HT-2000_inf_25ns_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_QCD_HT-2000_inf_25ns_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetTitle("h_ST_mul8_JecDown"); 

  TFile *tFile=new TFile("Binned_BH_Tree_QCD_HT-2000_inf_25ns_Double.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_QCD_HT_1500_2000_25ns(){

  TFile* file0 = TFile::Open("output_BH_Tree_QCD_HT-1500_2000_25ns.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_QCD_HT-1500_2000_25ns_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_QCD_HT-1500_2000_25ns_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetTitle("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_QCD_HT-1500_2000_25ns_Double.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_QCD_HT_1000_1500_25ns(){

  TFile* file0 = TFile::Open("output_BH_Tree_QCD_HT-1000_1500_25ns.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_QCD_HT-1000_1500_25ns_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_QCD_HT-1000_1500_25ns_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_QCD_HT-1000_1500_25ns_Double.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH5000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH5000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH5000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH5000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH5000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH6000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH6000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH6000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH6000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH6000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH7000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH7000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH7000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH7000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH7000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH8000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH8000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH8000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH8000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH8000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH9000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH9000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH9000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH9000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH9000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH10000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH10000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH10000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH10000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH10000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}

int makeLimitTemplatesROOTFile_BH_Tree_BH1_BM_MD4000_MBH11000_n6(){

  TFile* file0 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH11000_n6.root");
  TH1F *h0 = (TH1F*)file0->Get("h_ST_mul8");
  TH1F *h_ST_mul8_nominal = (TH1F*)h0->Clone("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetName("h_ST_mul8_nominal");
  h_ST_mul8_nominal->SetTitle("h_ST_mul8_nominal");

  TFile* file1 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH11000_n6_JecUp.root");
  TH1F *h1 = (TH1F*)file1->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecUp = (TH1F*)h1->Clone("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetName("h_ST_mul8_JecUp");
  h_ST_mul8_JecUp->SetTitle("h_ST_mul8_JecUp");

  TFile* file2 = TFile::Open("output_BH_Tree_BH1_BM_MD4000_MBH11000_n6_JecDown.root");
  TH1F *h2 = (TH1F*)file2->Get("h_ST_mul8");
  TH1F *h_ST_mul8_JecDown = (TH1F*)h2->Clone("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");
  h_ST_mul8_JecDown->SetName("h_ST_mul8_JecDown");

  TFile *tFile=new TFile("Binned_BH_Tree_BlackMaxLHArecord_BH1_BM_MD4000_MBH11000_n6.root", "RECREATE");
  h_ST_mul8_nominal->Write("h_ST_mul8_nominal");
  h_ST_mul8_JecUp->Write("h_ST_mul8_JecUp");
  h_ST_mul8_JecDown->Write("h_ST_mul8_JecDown");
  tFile->Close();

}





