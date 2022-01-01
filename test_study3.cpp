#include "test_study_3.h"
#include "Controller.h"

Test_3::Test_3(SCStudyInterfaceRef sc) : Study(sc) {}
Test_3::~Test_3() { return; }
void Test_3::DoInit() { Test_3::Initialized = TRUE; }
void Test_3::DoCleanUp() {}
// Setup of study input values
void Test_3::SetReferences(SCStudyInterfaceRef sc_) {
	/*
	SampIn1 = (sc_.Input[0]);
	SampIn2 = (sc_.Input[1]);
	SampIn3 = (sc_.Input[2]);
	*/
}
// setup of sc defaults
void Test_3::DoSetDefaults(SCStudyInterfaceRef sc_) {
	sc_.GraphName = "Mid$ Prediction";
	sc_.StudyDescription = "Testing Study for simple mid $ prediction.";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[0].Name = "Pred_Mid";
	sc_.Subgraph[1].Name = "dMid";
	sc_.Input[0].Name = "Sample Input";
	sc_.Input[0].SetInt(5);
}
// Entry point into study execution
void Test_3::DoStudy(SCStudyInterfaceRef sc_) {
	int nInd = sc_.Index + 1;
	int cInd = sc_.Index;
	int pInd = sc_.Index - 1;
	SCFloatArray& Mid = (sc_.HLAvg);

	SCSubgraph260Ref& Pred_dMid = (sc_.Subgraph[0]);  // <-- Ulitmately what we care about
	// NOTE: Need to figure out OTHER acsil structures that
	//		 will save values we need that aren't subgraphs.
	SCFloatArrayRef& dMid = (sc_.Subgraph[0].Arrays[0]);
	SCFloatArrayRef& err = (sc_.Subgraph[0].Arrays[1]);
	
	// Make array that is stored to save change in mid$s
	dMid[cInd] = Mid[cInd] - Mid[pInd];

	/*	The idea is to create a simple linear model
		that has trainable variables. We want to use
		the previous changes in mid price, the bar
		range size, and other simple inputs that 
		can have weights attached to them and fit
		every new bar that opens, and fit the model
		to the last x many bars, such as 30. And it
		can also predict a few bars forward at a time,
		using its next forecast. 

		Good inputs will be values that are in a
		similar value range to the change in mid$.
		For example, the change in range size squared, 
		we would want it squared, because a much
		larger increace in range size (times a direction
		indicator variable) would allow for a "jump"
		type action in Mid$ prediction.
	
	*/














}

void Test_3::Run(SCStudyInterfaceRef sc_) {
	if (!Initialized) {
		DoInit();
	}
	if (sc_.SetDefaults) {
		DoSetDefaults(sc_);
	}
	if (sc_.LastCallToFunction) {
		DoCleanUp();
		return;
	}
	DoStudy(sc_);
}