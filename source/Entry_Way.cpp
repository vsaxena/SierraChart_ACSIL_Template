#include "Controller.cpp"

// Study Pack Name
SCDLLName("Study Design Template")

SCSFExport scsf_Test_Study_1(SCStudyInterfaceRef sc_)
{
	/*********************************************	
	*	Entryway to study. Controller class uses
	*	enum value to know which class to construct
	*   and passes an SCStudyInterfaceRef to 
	*   use for accessing sierrachart code things 
	*********************************************/ 
	Study::StartStudy(TEST_STUDY1, sc_);
}

/*********************************************
*	add additional studies with extra: 
*
SCSFExport scsf_Test_Study_1(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY1, sc_);
}
*********************************************/