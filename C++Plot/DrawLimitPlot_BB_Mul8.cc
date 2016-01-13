#include <TROOT.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFile.h"
#include "TLatex.h"
#include "TDRStyle.h"

std::string itoa(int i) 
{
  char res[4];
  sprintf(res, "%d", i);
  std::string ret(res);
  return ret;
}

void DrawLimitPlot_BB_Mul8()
{
  double mass_array[]={5000, 6000, 7000, 8000, 9000, 10000, 11000};
  double array1 = 6.69698E+00;
  double array2 = 1.23067E+00;
  double array3 = 1.84871E-01;
  double array4 = 2.06980E-02;
  double array5 = 1.53694E-03;
  double array6 = 6.01490E-05;
  double array7 = 8.59628E-07;
  double xsec_theory_array[] = {array1, array2, array3, array4, array5, array6, array7}; 
  std::vector<double> mass(mass_array, mass_array+sizeof(mass_array)/sizeof(double));
  std::vector<double> xsec_theory(xsec_theory_array, xsec_theory_array+sizeof(xsec_theory_array)/sizeof(double));
  std::vector<double> xsec;
  std::vector<double> obs;
  std::vector<double> expNeg2, expNeg1, expPos1, expPos2;
  
  for (unsigned int i_mass=0; i_mass<mass.size(); ++i_mass)
  {
    std::string mass_string=itoa(mass.at(i_mass));
    std::string filename="BayesianBlocks_BH_Mul8_MBH_"+mass_string+"GeV.log";
    std::ifstream file(filename.c_str(), ios::in);
 
    std::string line;
    getline(file, line);
    getline(file, line);
    getline(file, line);
//    getline(file, line);
//    getline(file, line);

    getline(file, line); double d_obs=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass); obs.push_back(d_obs);
    getline(file, line); double d_xsecNeg2=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file, line); double d_xsecNeg1=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file, line); double d_xsec=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass); xsec.push_back(d_xsec);
    getline(file, line); double d_xsecPos1=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file, line); double d_xsecPos2=atof(line.substr(line.find("<")+1).c_str())*xsec_theory.at(i_mass);

    expNeg2.push_back(d_xsec-d_xsecNeg2);
    expNeg1.push_back(d_xsec-d_xsecNeg1);
    expPos1.push_back(d_xsecPos1-d_xsec);
    expPos2.push_back(d_xsecPos2-d_xsec);
    
    if (
        mass_string=="5000" ||
        mass_string=="6000" ||
        mass_string=="7000" ||
        mass_string=="8000" || mass_string=="9000" || mass_string=="10000" || mass_string=="11000")
         std::cout<<mass_string<<" & "<<d_obs<< " & "<<d_xsec<<" & "<<d_xsecNeg1<<" & "<<d_xsecPos1<<" & "<<d_xsecNeg2<<" & "<<d_xsecPos2<<" \\\\ "<<std::endl;
    
  }
  
  TStyle *tdrStyle=setTDRStyle();
  tdrStyle->cd();
  tdrStyle->SetPadLeftMargin(0.14);
  tdrStyle->SetTitleYOffset(1.6);
  
  TCanvas *c_xsec=new TCanvas("c_xsec", "c_xsec", 700, 700);
  TGraph *g_xsec=new TGraph(mass.size(), &mass[0], &xsec[0]);
  g_xsec->SetTitle("; m_{BH} [GeV]; 95 \% CL limit #sigma [pb]");
  g_xsec->SetLineWidth(2);
  g_xsec->SetLineStyle(2);
  TGraphAsymmErrors *g_xsec_1sigma=new TGraphAsymmErrors(mass.size(), &mass[0], &xsec[0], 0, 0, &expNeg1[0], &expPos1[0]);
  g_xsec_1sigma->SetLineColor(kGreen);
  g_xsec_1sigma->SetFillColor(kGreen);
  TGraphAsymmErrors *g_xsec_2sigma=new TGraphAsymmErrors(mass.size(), &mass[0], &xsec[0], 0, 0, &expNeg2[0], &expPos2[0]);
  for (unsigned int i_mass=0; i_mass<mass.size(); ++i_mass){
    std::cout << "expNeg1.at(i_mass) = " << expNeg1.at(i_mass) << std::endl;
    std::cout << "expNeg2.at(i_mass) = " << expNeg2.at(i_mass) << std::endl;
  }
  g_xsec_2sigma->SetLineColor(kYellow);
  g_xsec_2sigma->SetFillColor(kYellow);
  g_xsec->SetMaximum(10.0); g_xsec->SetMinimum(0.0001);
  g_xsec->Draw("AL");
  g_xsec_2sigma->Draw("3");
  g_xsec_1sigma->Draw("3");
  g_xsec->Draw("L");
  TGraph *g_xsec_theory=new TGraph(mass.size(), &mass[0], &xsec_theory[0]);
  g_xsec_theory->SetLineColor(kRed);
  g_xsec_theory->SetLineWidth(2);
  g_xsec_theory->Draw("L");
  TGraph *g_obs=new TGraph(mass.size(), &mass[0], &obs[0]);
  g_obs->SetLineWidth(2);
  g_obs->SetLineStyle(1);
  g_obs->SetMarkerStyle(20);
  g_obs->Draw("LP SAME");
  c_xsec->SetTicks(1, 1);
  TLatex* text1 = new TLatex(1.10061,18.08044,"CMS Preliminary, 2.2 fb^{-1} at #sqrt{s} = 13 TeV");
  text1->SetNDC();
  text1->SetTextAlign(10);
  text1->SetX(0.15);
  text1->SetY(0.90);
  text1->SetTextFont(42);
  text1->SetTextSize(0.03);
  text1->SetTextSizePixels(15);
  text1->Draw();
  TLegend *leg = new TLegend(0.3994253,0.6919643,0.7485632,0.86,NULL,"brNDC");
  //TLegend *leg=new TLegend(0.30, 0.65, 0.90, 0.85);
  leg->SetFillStyle(1); leg->SetFillColor(kWhite); leg->SetLineColor(kWhite); leg->SetTextSize(0.04);
  leg->AddEntry(g_xsec, "Expected upper limit", "L");
  leg->AddEntry(g_xsec_1sigma, "Expected #pm 1 #sigma", "F");
  leg->AddEntry(g_xsec_2sigma, "Expected #pm 2 #sigma", "F");
  leg->AddEntry(g_xsec_theory, "Theoretical cross section", "L");
  leg->AddEntry(g_obs, "Observed upper limit", "LP");
  leg->Draw();
  c_xsec->SetLogy(); 
  c_xsec->SaveAs("c_xsec_BB_Mul8.png");
  c_xsec->SaveAs("c_xsec_BB_Mul8.pdf");

  double m=5000.0;
  while (m<=11000.0 and g_obs->Eval(m)<g_xsec_theory->Eval(m)) m+=0.01;
  std::cout << "mass limit observed = " << m << endl;

  double m_exp=5000.0;
  while (m_exp<=11000.0 and g_xsec->Eval(m_exp)<g_xsec_theory->Eval(m_exp)) m_exp+=0.01;
  std::cout << "mass limit expected = " << m_exp << endl;

}    
