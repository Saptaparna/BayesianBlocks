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

void DrawLimitPlot_Comparison()
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
  std::vector<double> xsec_1, xsec_2;
  std::vector<double> expNeg2_1, expNeg1_1, expPos1_1, expPos2_1, expNeg2_2, expNeg1_2, expPos1_2, expPos2_2;
  
  for (unsigned int i_mass=0; i_mass<mass.size(); ++i_mass)
  {
    std::string mass_string=itoa(mass.at(i_mass));
    std::string filename1="DataCard_BlackMaxLHArecord_BH1_BM_MD4000_MBH"+mass_string+"_n6.log";
    std::ifstream file1(filename1.c_str(), ios::in);
 
    std::string line1;
    getline(file1, line1);
    getline(file1, line1);
    getline(file1, line1);

    getline(file1, line1); double d_obs=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass); 
    getline(file1, line1); double d_xsecNeg2=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file1, line1); double d_xsecNeg1=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file1, line1); double d_xsec=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass); xsec_1.push_back(d_xsec);
    getline(file1, line1); double d_xsecPos1=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file1, line1); double d_xsecPos2=atof(line1.substr(line1.find("<")+1).c_str())*xsec_theory.at(i_mass);

    expNeg2_1.push_back(d_xsec-d_xsecNeg2);
    expNeg1_1.push_back(d_xsec-d_xsecNeg1);
    expPos1_1.push_back(d_xsecPos1-d_xsec);
    expPos2_1.push_back(d_xsecPos2-d_xsec);
    
    if (
        mass_string=="5000" ||
        mass_string=="6000" ||
        mass_string=="7000" ||
        mass_string=="8000" || mass_string=="9000" || mass_string=="10000" || mass_string=="11000")
         std::cout<<mass_string<<" & "<<d_obs<< " & "<<d_xsec<<" & "<<d_xsecNeg1<<" & "<<d_xsecPos1<<" & "<<d_xsecNeg2<<" & "<<d_xsecPos2<<" \\\\ "<<std::endl;
    
  }

  for (unsigned int i_mass=0; i_mass<mass.size(); ++i_mass)
  {
    std::string mass_string=itoa(mass.at(i_mass));
    std::string filename2="BayesianBlocks_BH_Mul8_MBH_"+mass_string+"GeV.log";
    std::ifstream file2(filename2.c_str(), ios::in);

    std::string line2;
    getline(file2, line2);
    getline(file2, line2);
    getline(file2, line2);

    getline(file2, line2); double d_obs=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass); 
    getline(file2, line2); double d_xsecNeg2=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file2, line2); double d_xsecNeg1=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file2, line2); double d_xsec=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass); xsec_2.push_back(d_xsec);
    getline(file2, line2); double d_xsecPos1=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass);
    getline(file2, line2); double d_xsecPos2=atof(line2.substr(line2.find("<")+1).c_str())*xsec_theory.at(i_mass);

    expNeg2_2.push_back(d_xsec-d_xsecNeg2);
    expNeg1_2.push_back(d_xsec-d_xsecNeg1);
    expPos1_2.push_back(d_xsecPos1-d_xsec);
    expPos2_2.push_back(d_xsecPos2-d_xsec);

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
  TGraph *g_xsec_1=new TGraph(mass.size(), &mass[0], &xsec_1[0]);
  g_xsec_1->SetTitle("; m_{BH} [GeV]; 95 \% CL limit #sigma [pb]");
  g_xsec_1->SetLineWidth(3);
  g_xsec_1->SetLineStyle(2);
  g_xsec_1->SetMaximum(1.0); g_xsec_1->SetMinimum(0.001);
  g_xsec_1->Draw("AL");
  
  TGraph *g_xsec_2=new TGraph(mass.size(), &mass[0], &xsec_2[0]);
  g_xsec_2->SetTitle("; m_{BH} [GeV]; 95 \% CL limit #sigma [pb]");
  g_xsec_2->SetLineWidth(3);
  g_xsec_2->SetLineStyle(2);
  g_xsec_2->SetLineColor(kBlue);
  g_xsec_2->SetMaximum(10.0); g_xsec_2->SetMinimum(0.0001);
  g_xsec_2->Draw("L");
 
  TGraph *g_xsec_theory=new TGraph(mass.size(), &mass[0], &xsec_theory[0]);
  g_xsec_theory->SetLineColor(kRed);
  g_xsec_theory->SetLineWidth(2);
  g_xsec_theory->Draw("L");
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
  leg->SetTextFont(132);
  leg->SetFillStyle(1); leg->SetFillColor(kWhite); leg->SetLineColor(kWhite); leg->SetTextSize(0.020);
  leg->AddEntry(g_xsec_1, "Expected limit Standard Analysis", "L");
  leg->AddEntry(g_xsec_2, "Expected limit Bayesian Blocks  Multiplicity >= 8", "L");
  leg->AddEntry(g_xsec_theory, "Theoretical cross section", "L");
  leg->Draw();
  c_xsec->SetLogy(); 
  c_xsec->SaveAs("c_xsec_Comparison.png");
  c_xsec->SaveAs("c_xsec_Comparison.pdf");

  double m_exp=5000.0;
  while (m_exp<=11000.0 and g_xsec_1->Eval(m_exp)<g_xsec_theory->Eval(m_exp)) m_exp+=0.01;
  std::cout << "mass limit expected = " << m_exp << endl;

  while (m_exp<=11000.0 and g_xsec_2->Eval(m_exp)<g_xsec_theory->Eval(m_exp)) m_exp+=0.01;
  std::cout << "mass limit expected = " << m_exp << endl;

}    
