#include "TMath.h"
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


bool mysort (double i, double j) { return (i > j); }

void HGG_SoverSqrtB(){

  double signal7TeV[15] = {7.7, 9.2, 3.5, 4.3, 17.9, 24.3, 9.0, 11.8, 1.9, 2.5, 0.3, 0.2, 0.4, 0.4, 0.2};
  double sumSignal7TeV = 0.0;
  for (int i=0; i<15; i++)
  {
    sumSignal7TeV += signal7TeV[i];
  }   

  cout << "sumSignal7TeV = " << sumSignal7TeV << endl;

  double signal8TeV[16] = {36.6, 48.7, 16.2, 22.7, 69.9, 105.1, 35.1, 51.7, 9.2, 10.5, 1.4, 0.8, 2.2, 1.7, 0.4, 0.6};
  double sumSignal8TeV = 0.0;
  for (int i=0; i<16; i++)
  {
    sumSignal8TeV += signal8TeV[i];
  }

  cout << "sumSignal8TeV = " << sumSignal8TeV << endl;

  double bkgHiggs1257TeV[15] = {31.0, 48.0, 27.0, 31.0, 70.0, 142.0, 75.0, 131.0, 3.0, 6.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double sumBkgHiggs1257TeV = 0.0;
  for (int i=0; i<16; i++)
  {
    sumBkgHiggs1257TeV += bkgHiggs1257TeV[i];
  }

  cout << "sumBkgHiggs1257TeV = " << sumBkgHiggs1257TeV << endl;

  double bkgHiggs1258TeV[16] = {104.0, 201.0, 89.0, 152.0, 268.0, 605.0, 275.0, 478.0, 7.0, 19.0, 0.0, 1.0, 5.0, 2.0, 1.0, 1.0};
  double sumBkgHiggs1258TeV = 0.0;
  for (int i=0; i<16; i++)
  {
    sumBkgHiggs1258TeV += bkgHiggs1258TeV[i];
  }

  cout << "sumBkgHiggs1258TeV = " << sumBkgHiggs1258TeV << endl;
  std::vector<double> sOverSqrtb;
  std::vector<double> sOverSqrtSPlusb;


  for (int i=0; i<15; i++)
  {
    //cout << "S/sqrt(S+B) 7 TeV = " << signal7TeV[i]/TMath::Sqrt(signal7TeV[i]+bkgHiggs1257TeV[i]) << " cat " << i << endl; 
    sOverSqrtb.push_back(signal7TeV[i]/TMath::Sqrt(signal7TeV[i]+bkgHiggs1257TeV[i]));
  }

  for (int i=0; i<16; i++)
  {
    //cout << "S/sqrt(S+B) 8 TeV = " << signal8TeV[i]/TMath::Sqrt(signal8TeV[i]+bkgHiggs1258TeV[i]) << " cat " << i << endl;
    sOverSqrtb.push_back(signal8TeV[i]/TMath::Sqrt(signal8TeV[i]+bkgHiggs1258TeV[i]));
  }

  for (int i=0; i<15; i++)
  {
    //if(bkgHiggs1257TeV[i] > 0.0) cout << "S/sqrt(B) 7 TeV = " << signal7TeV[i]/(TMath::Sqrt(bkgHiggs1257TeV[i])) << " cat " << i  << endl;
    if(bkgHiggs1257TeV[i] > 0.0)sOverSqrtSPlusb.push_back(signal7TeV[i]/(TMath::Sqrt(bkgHiggs1257TeV[i])));
  }

  for (int i=0; i<16; i++)
  {
    if(bkgHiggs1258TeV[i] > 0.0) cout << "S/sqrt(B) 8 TeV = " << signal8TeV[i]/(TMath::Sqrt(bkgHiggs1258TeV[i])) << " cat " << i  << endl;
    if(bkgHiggs1258TeV[i] > 0.0) sOverSqrtSPlusb.push_back(signal8TeV[i]/(TMath::Sqrt(bkgHiggs1258TeV[i])));
  }

  std::sort(sOverSqrtb.begin(), sOverSqrtb.end(), mysort);
  std::sort(sOverSqrtSPlusb.begin(), sOverSqrtSPlusb.end(), mysort);

  for (int i=0; i<15; i++)
  {
    cout << "Sorted s/sqrt(s+b) = " << sOverSqrtb.at(i) << endl;
  }

  for (int i=0; i<16; i++)
  {
    cout << "Sorted s/sqrt(b) = " << sOverSqrtSPlusb.at(i) << endl; 
  }
}
