#ifndef RPLOTTER1D_H
#define RPLOTTER1D_H

//ROOT includes
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLegend.h>
#include <THStack.h> 
#include <TObjArray.h>
#include <iostream>

using namespace std;

class RPlotter1D {
	private:
		TObjArray* _vhists;
		TCanvas* _canv;
		TLegend* _leg;
		TString _title;
		TString _titleX;
		TString _titleY;
	public:
		RPlotter1D(TString title = "", TString xAxis = "", TString yAxis = "");
		~RPlotter1D();
		//Add macros
		void AddHist(TH1F* hist, TString Handle);
		void AddLegend(TString Handle, TString Description);
		void SetTitle(TString title);
		//Return macros
		TH1F* GetHist(TString Handle);
		TCanvas* GetCanvas(){ return _canv; };
		TLegend* GetLegend(){ return _leg; };
		//Utils
		
		void Clear();
		void SaveAs(TString FileName);
		
};

#endif