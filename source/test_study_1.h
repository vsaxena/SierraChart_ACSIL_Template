#pragma once
#include "Controller.h"

// will be looking to replace class name with $safeprojectname$ or similar

class Test_1: public Study
{
	public:
		Test_1(SCStudyInterfaceRef sc);
		~Test_1(); 

	protected:
		void DoInit();
		void DoCleanUp();
		void SetReferences(SCPtr sc_);
		void DoSetDefaults();
		void DoStudy();
		void Run();
	
	private:
		bool Initialized = FALSE;
		int cI;
		s_SCInput_145* samp1;
		SCFloatArray* HLAvg;
		s_SCSubgraph_260* Mid;
};
