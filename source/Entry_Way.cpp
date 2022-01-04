#include "\Controller.cpp"


SCDLLName("Study Design Template")

SCSFExport scsf_Test_Study_1(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY1, sc_);
}
