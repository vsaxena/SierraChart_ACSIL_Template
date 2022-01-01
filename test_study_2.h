#pragma once
#include "Controller.h"
#include "sierrachart.h"

class Test_2 : public Study
{
public:
	Test_2(SCStudyInterfaceRef sc);
	~Test_2();

	void DoInit();
	void DoCleanUp();

	void SetReferences(SCStudyInterfaceRef sc_);
	void DoSetDefaults(SCStudyInterfaceRef sc_);
	void DoStudy(SCStudyInterfaceRef sc_);
	void Run(SCStudyInterfaceRef sc_);
	
	/*
	s_SCInput_145& SampIn1;
	s_SCInput_145& SampIn1;
	s_SCInput_145& SampIn1;
	SCFloatArray& mid;
	SCSubgraph260Ref& Mid;
	*/
	bool Initialized = FALSE;
}; 
