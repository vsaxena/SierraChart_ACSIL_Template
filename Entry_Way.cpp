#include "Controller.cpp"

#pragma comment(lib, "comctl32.lib")

SCDLLName("Static Factory Design Template")

SCSFExport scsf_Test_Study_1(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY1, sc_);
}

SCSFExport scsf_Test_Study_2(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY2, sc_);
}


SCSFExport scsf_Test_Study_3(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY3, sc_);
}


