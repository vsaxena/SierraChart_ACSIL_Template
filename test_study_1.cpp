#include "test_study_1.h"
#include "Controller.h"

Test_1::Test_1(SCStudyInterfaceRef sc) : Study(sc) {}
Test_1::~Test_1() {return;}

void Test_1::DoInit() {
	Test_1::Initialized = TRUE;
}

void Test_1::DoCleanUp() {}

// Setup of study input values
void Test_1::SetReferences(SCStudyInterfaceRef sc_) {
	SCFloatArray mid = (sc_.HLAvg);

}

// setup of sc defaults
void Test_1::DoSetDefaults(SCStudyInterfaceRef sc_) {
	sc_.GraphName = "Abc";
	sc_.StudyDescription = "Abc";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[0].Name = "Abc";
	sc_.Input[0].Name = "Abc";
	sc_.Input[0].SetInt(5);
}

// Entry point into study execution
void Test_1::DoStudy(SCStudyInterfaceRef sc_) {
	int cI = sc_.Index;
	//SCFloatArray&  mid = (sc_.HLAvg);
	SCSubgraph260Ref& Mid = sc_.Subgraph[0];

	Mid[cI] =  Test_1::mid[cI]

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