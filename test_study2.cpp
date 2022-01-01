#include "test_study_2.h"
#include "Controller.h"

Test_2::Test_2(SCStudyInterfaceRef sc) : Study(sc) {}

Test_2::~Test_2() {return;}

void Test_2::DoInit() {
	Test_2::Initialized = TRUE;
}

void Test_2::DoCleanUp() {}

// Setup of study input values
void Test_2::SetReferences(SCStudyInterfaceRef sc_) {
	
}

// setup of sc defaults
void Test_2::DoSetDefaults(SCStudyInterfaceRef sc_) {
	sc_.GraphName = "Abc";
	sc_.StudyDescription = "Abc";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[0].Name = "Abc";
	sc_.Input[0].Name = "Abc";
}
// Entry point into study execution
void Test_2::DoStudy(SCStudyInterfaceRef sc_) {
	
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