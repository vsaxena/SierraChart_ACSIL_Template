#include "test_study_1.h"

Test_1::Test_1(SCStudyInterfaceRef sc) : Study(sc) {}

/*********************************************	
*	if any other classes exist that create
*	objects during a study call, use study
*	class destructor to clean them up
*********************************************/
Test_1::~Test_1() {	
	return;
}

/*********************************************
*	If your study happens to create objects
*	that need instantiated only once, do here
*********************************************/
void Test_1::DoInit() {
	Test_1::Initialized = TRUE;
}

/*********************************************
*	If you created any other objects, they'll
*	need to be cleaned up at the end of the 
*	study's life
*********************************************/
void Test_1::DoCleanUp() {}

/*********************************************
*	Setup of study input values before study runs
*********************************************/
void Test_1::SetReferences(SCPtr sc_) {
	_sc = sc_;
	
	// Access Chart Data **not necessarily necessary in this manner**
	HLAvg = &(_sc->HLAvg);

	// Access Subgraphs
	int sg = 0;
	Mid = &(_sc->Subgraph[sg++]);

	// Access User Inputs
	int ind = 0;
	samp1 = &(_sc->Input[ind++]);
	
	// Set any other refs you want
	cI = (_sc->Index);
}

/*********************************************
*	Setup of sc defaults, this is the normal 'if(sc.SetDefaults)'
*	block from a vanilla acsil study
*********************************************/
void Test_1::DoSetDefaults() {
	// SC variables
	_sc->GraphName = "Template Study";
	_sc->StudyDescription = "Template Study";
	_sc->AutoLoop = 1;
	_sc->GraphRegion = 0;
	// Subgraphs
	Mid->Name = "Temp";
	Mid->PrimaryColor = RGB(100,200,230);
	Mid->LineWidth = 3;
	// User Inputs
	samp1->Name = "Temp";
	samp1->SetInt(5);
}

/*********************************************
*	Entry point into study execution, this
*	is where the actual calculations and
*	anything else needed will be done
*********************************************/ 
void Test_1::DoStudy() {
	
	// Sample output to test working
	Mid->Data.ElementAt(cI) = HLAvg->ElementAt(cI) * (samp1->GetInt()/samp1->GetInt());
	// This func does the same as above line,
	// serve as example for further organization
	SampleIntermediateCalc();

}

/********************************************
*	This is kind of like our study's own
*	'main' func if you will, in that this
*	controls the study calculation lifecycle
*********************************************/
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

/********************************************
*	Sample class function for calculations
*********************************************/
void Test_1::SampleIntermediateCalc() {
	// Sample output to test working
	Mid->Data.ElementAt(cI) = HLAvg->ElementAt(cI) * (samp1->GetInt() / samp1->GetInt());
}