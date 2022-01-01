#include "test_study_3.h"
#include "Controller.h"

Test_3::Test_3(SCStudyInterfaceRef sc) : Study(sc) {}

Test_3::~Test_3() { return; }

void Test_3::DoInit() { 
	Test_3::Initialized = TRUE; 
}

void Test_3::DoCleanUp() {}

// Setup of study input values
void Test_3::SetReferences(SCPtr sc_) {

}

// setup of sc defaults
void Test_3::DoSetDefaults() {
	int t = 0;
	int	i = 0;
	_sc->GraphName = "Abc";
	_sc->StudyDescription = "Abc";
	_sc->AutoLoop = 1;
	_sc->GraphRegion = 0;
	_sc->Subgraph[t].Name = "Abc";
	_sc->Subgraph[++t].Name = "Abc";
	_sc->Input[i].Name = "Abc";
	_sc->Input[++i].Name = "Abc";
}

// Entry point into study execution
void Test_3::DoStudy() {
}

