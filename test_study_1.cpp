#include "test_study_1.h"
#include "Controller.h"

Test_1::Test_1(SCStudyInterfaceRef sc) : Study(sc) {}
Test_1::~Test_1() {return;}

void Test_1::DoInit() {
	// here would be the place where we load a saved neural network
	// the idea is that then it would exist in memory and we could
	// just call it when we need it for a prediction, every time 
	// the study runs, which we will have set to 'on bar close'
	
	Test_1::Initialized = TRUE;
}

void Test_1::DoCleanUp() {}

// Setup of study input values
void Test_1::SetReferences(SCStudyInterfaceRef sc_) {

	/*
	SampIn1 = (sc_.Input[0]);
	SampIn2 = (sc_.Input[1]);
	SampIn3 = (sc_.Input[2]);
	*/
}

// setup of sc defaults
void Test_1::DoSetDefaults(SCStudyInterfaceRef sc_) {
	sc_.GraphName = "Testing MID Price";
	sc_.StudyDescription = "Mid Tester";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[0].Name = "Mid Price Tester";
	sc_.Input[0].Name = "Sample Input";
	sc_.Input[0].SetInt(5);
}

// Entry point into study execution
void Test_1::DoStudy(SCStudyInterfaceRef sc_) {
	int cI = sc_.Index;
	SCFloatArray&  mid = (sc_.HLAvg);
	SCSubgraph260Ref& Mid = sc_.Subgraph[0];

	Mid[cI] = mid[cI] ;

}

void Test_1::Run(SCStudyInterfaceRef sc_) {
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