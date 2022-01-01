#include "Controller.cpp"

#pragma comment(lib, "comctl32.lib")

SCDLLName("Study Building Template")

SCSFExport scsf_Testing_Mid(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY1, sc_);
}

SCSFExport scsf_Testing_Single_Bar_Vola(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY2, sc_);
}

/*
SCSFExport scsf_Test_Study_3(SCStudyInterfaceRef sc_)
{
	Study::StartStudy(TEST_STUDY3, sc_);
}
*/


/*

SCSFExport scsf_studyname(SCStudyInterfaceRef sc_)

here SCSFExport is the TYPE of function, meaning inside the sierrachart code base
there exists a class for this function

the scsf_ before our studyname is just a style that sierrachart uses for study names, we always
need to make sure that is there ,, this names our study

the SCStudyInterfaceRef is a TYPE of variable we are passing into this function... and sc_ is the 
variable

now it just so happens that because of whewre this code gets run inside sierrachart, that puts us inside the sierrachart scopes, such that SCStudyInterfaceRef is a TYPE of variable thatr is a POINTER

a POINTER is something that is unique to c++ lanuage, its for faster running... it points directly to the 
location in memory.

that sc_ is how we reference things in teh study we write

now in this example above this is the code template im working on for serious c++ dev in sierrachart, but well look at another sierra study that is more traditional
*/