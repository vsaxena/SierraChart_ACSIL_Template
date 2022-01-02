#include "test_study_1.h"

Test_1::Test_1(SCStudyInterfaceRef sc) : Study(sc) {}

Test_1::~Test_1() {
	//Does anything need deleted here?	
	return;
}

void Test_1::DoInit() {
	Test_1::Initialized = TRUE;
}

void Test_1::DoCleanUp() {}

// Setup of study input values
void Test_1::SetReferences(SCPtr sc_) {
	_sc = sc_;
	
	// Access Chart Data **not necessarily necessary**
	HLAvg = &(_sc->HLAvg);

	// Access Subgraphs
	Mid = &(_sc->Subgraph[0]);

	// Access User Inputs
	samp1 = &(_sc->Input[0]);
	
	// Set any other refs
	cI = (_sc->Index);
}

// setup of sc defaults
void Test_1::DoSetDefaults() {
	_sc->GraphName = "Abc";
	_sc->StudyDescription = "Abc";
	_sc->AutoLoop = 1;
	_sc->GraphRegion = 0;
	Mid->Name = "Abc";
	Mid->PrimaryColor = RGB(100,200,230);
	Mid->LineWidth = 3;
	samp1->Name = "Abc";
	samp1->SetInt(5);
}

// Entry point into study execution
void Test_1::DoStudy() {
	// Sample output to test working
	Mid->Data.ElementAt(cI) = HLAvg->ElementAt(cI);
}

void Test_1::Run() {
	if (!Initialized) {
		DoInit();
	}
	if (_sc->SetDefaults) {
		DoSetDefaults();
	}
	if (_sc->LastCallToFunction) {
		DoCleanUp();
		return;
	}
	DoStudy();
}
