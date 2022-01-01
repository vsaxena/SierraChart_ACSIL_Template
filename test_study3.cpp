#include "test_study_3.h"
#include "Controller.h"

Test_3::Test_3(SCStudyInterfaceRef sc) : Study(sc) {}

Test_3::~Test_3() { return; }

void Test_3::DoInit() { 
	Test_3::Initialized = TRUE; 
}

void Test_3::DoCleanUp() {}

// Setup of study input values
void Test_3::SetReferences(SCStudyInterfaceRef sc_) {

}
// setup of sc defaults
void Test_3::DoSetDefaults(SCStudyInterfaceRef sc_) {
	int t = 0;
	int	i = 0;
	sc_.GraphName = "Abc";
	sc_.StudyDescription = "Abc";
	sc_.AutoLoop = 1;
	sc_.GraphRegion = 0;
	sc_.Subgraph[t].Name = "Abc";
	sc_.Subgraph[++t].Name = "Abc";
	sc_.Input[i].Name = "Abc";
	sc_.Input[++i].Name = "Abc";
}
// Entry point into study execution
void Test_3::DoStudy(SCStudyInterfaceRef sc_) {
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