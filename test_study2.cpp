#include "test_study_2.h"
#include "Controller.h"

Test_2::Test_2(SCStudyInterfaceRef sc) : Study(sc) {}
Test_2::~Test_2() {return;}
void Test_2::DoInit() {Test_2::Initialized = TRUE;}
void Test_2::DoCleanUp() {}
// Setup of study input values
void Test_2::SetReferences(SCStudyInterfaceRef sc_) {
	/*
	SampIn1 = (sc_.Input[0]);
	SampIn2 = (sc_.Input[1]);
	SampIn3 = (sc_.Input[2]);
	*/
}
// setup of sc defaults
void Test_2::DoSetDefaults(SCStudyInterfaceRef sc_) {
	sc_.GraphName = "Single Bar Vola";
	sc_.StudyDescription = "Testing Study for single bar Volatility measure";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[0].Name = "Vola";
	sc_.Input[0].Name = "Sample Input";
	sc_.Input[0].SetInt(5);
}
// Entry point into study execution
void Test_2::DoStudy(SCStudyInterfaceRef sc_) {
	
	int cInd = sc_.Index;
	SCFloatArray& O = (sc_.Open);
	SCFloatArray& H = (sc_.High);
	SCFloatArray& L = (sc_.Low);
	SCFloatArray& C = (sc_.Close);

	SCSubgraph260Ref& Vola = (sc_.Subgraph[0]);
	
	Vola[cInd] = sqrt(0.5 * pow(log(H[cInd]) - log(L[cInd]), 2) + 0.3979 * pow(log(C[cInd]) - log(O[cInd]), 2));
}

void Test_2::Run(SCStudyInterfaceRef sc_) {
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