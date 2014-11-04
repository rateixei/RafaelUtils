#include "include/RPlotter1D.h"

void Test(){
	gROOT->ProcessLine(".L src/RPlotter1D.cpp");
	TH1F* h1 = new TH1F("h1", "h1", 10, 0, 10);
	TH1F* h2 = new TH1F("h2", "h2", 10, 0, 10);
	TH1F* h3 = new TH1F("h3", "h3", 10, 0, 10);
	h1->Fill(1, 20);
	h2->Fill(2, 10);
	h3->Fill(3, 10);
	RPlotter1D* plotter = new RPlotter1D("Test", "Number of Whatever", "Events");
	plotter->AddHist(h1, "h1");
	plotter->AddHist(h2, "h2");
	plotter->AddHist(h3, "h3");
	plotter->SaveAs("test.pdf");
	
}