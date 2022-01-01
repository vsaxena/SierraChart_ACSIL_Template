#include "test_study_2.h"
#include "Controller.h"

Test_2::Test_2(SCStudyInterfaceRef sc) : Study(sc) {}

Test_2::~Test_2() {return;}

void Test_2::DoInit() {
	Test_2::Initialized = TRUE;
}

void Test_2::DoCleanUp() {}

// Setup of study input values
void Test_2::SetReferences(SCPtr sc_) {
	
}

// setup of sc defaults
void Test_2::DoSetDefaults() {
	_sc->GraphName = "Abc";
	_sc->StudyDescription = "Abc";
	_sc->AutoLoop = 1;
	_sc->GraphRegion = 0;
	_sc->Subgraph[0].Name = "Abc";
	_sc->Input[0].Name = "Abc";
}

// Entry point into study execution
void Test_2::DoStudy() {
	
}

