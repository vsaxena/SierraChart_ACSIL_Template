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

		void SetReferences(SCPtr sc_);
		void DoSetDefaults();
		void DoStudy();
		void Run();

	protected:
		s_SCInput_145* samp1;
		SCFloatArray* mid;
		s_SCSubgraph_260* Mid;

	private:
		bool Initialized = FALSE;
		int cI;
};
