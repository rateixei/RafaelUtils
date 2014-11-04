#define RPlotter1D_cxx
#include "../include/RPlotter1D.h"

RPlotter1D::RPlotter1D(TString Title, TString xAxis, TString yAxis){
	_vhists = new TObjArray();
	_canv = new TCanvas("canv", Title, 800,800);
	_titleX = xAxis;
	_titleY = yAxis;
	_title = Title;
	_leg = new TLegend(0.6,0.7,0.89,0.89);
	_leg->SetFillStyle(0);
	_leg->SetLineWidth(0);
	_leg->SetBorderSize(0);
		
	_canv->SetFillColor(0);
	_canv->SetBorderMode(0);
	_canv->SetFrameFillStyle(0);
	_canv->SetFrameBorderMode(0);
	_canv->SetTickx(0);
    _canv->SetTicky(0);
   	_canv->SetGrid();
}
RPlotter1D::~RPlotter1D(){}

//Add macros
void RPlotter1D::AddHist(TH1F* hist, TString Handle){
	cout << "Adding histogram: " << Handle << endl;
	_vhists->Add(hist);

}


void RPlotter1D::SaveAs(TString FileName){
	cout << "Number of histograms added: " << _vhists->GetEntries() << endl;
	if(_vhists->GetEntries() < 1) std::cout << "You haven't added any plots..." << std::endl;
	_canv->cd();
	TH1F* n0 = (TH1F*) _vhists->At(0);

	n0->SetStats(0);
	n0->SetLineWidth(3);
	n0->GetXaxis()->SetTitle(_titleX);
	n0->GetYaxis()->SetTitle(_titleY);
	n0->SetLineColor(1);
	_leg->AddEntry(n0, n0->GetTitle(), "l");
	
	n0->SetTitle(_title);
	n0->Draw();
	for(int i = 1; i < _vhists->GetEntries(); i++){
		TH1F* H0 = (TH1F*) _vhists->At(i);
		H0->SetStats(0);
		H0->SetLineWidth(3);
		H0->SetLineColor(i+1);
		_leg->AddEntry(H0, H0->GetTitle(), "l");
		H0->Draw("same");
	}
	_leg->Draw("same");

	_canv->Update();
	_canv->SaveAs(FileName);
	delete n0;
	delete H0;

}

void RPlotter1D::AddLegend(TString Handle, TString Description /*, TOption opt*/){}
void RPlotter1D::SetTitle(TString title){}