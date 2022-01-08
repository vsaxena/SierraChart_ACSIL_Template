#pragma once
#include "Controller.h"



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
	
	/********************************************* 
	*	Any variables needed for study calculation
	*	or for referencing user input or for 
	*	setting subgraph values, add to private:
	*********************************************/	
	private:
		bool Initialized = FALSE;
		int cI;
		s_SCInput_145* samp1;
		SCFloatArray* HLAvg;
		s_SCSubgraph_260* Mid;

		void SampleIntermediateCalc();
};
