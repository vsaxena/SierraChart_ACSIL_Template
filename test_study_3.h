#pragma once
#include "Controller.h"
#include "sierrachart.h"

class Test_3 : public Study
{
public:
	Test_3(SCStudyInterfaceRef sc);
	~Test_3();

	void DoInit();
	void DoCleanUp();

	void SetReferences(SCStudyInterfaceRef sc_);
	void DoSetDefaults(SCStudyInterfaceRef sc_);
	void DoStudy(SCStudyInterfaceRef sc_);
	void Run(SCStudyInterfaceRef sc_);

	bool Initialized = FALSE;
};
