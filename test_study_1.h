#pragma once
#include "Controller.h"

class Test_1: public Study
{
	public:
		Test_1(SCStudyInterfaceRef sc);
		~Test_1(); 
			
		void DoInit();
		void DoCleanUp();

		void SetReferences(SCPtr sc_);
		void DoSetDefaults();
		void DoStudy();
		void Run();
	
	protected:
		s_SCInput_145* samp1;
		SCFloatArray* HLAvg;
		s_SCSubgraph_260* Mid;

	private:
		bool Initialized = FALSE;
		int cI;
};
