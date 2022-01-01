#pragma once
#include "Controller.h"
#include "sierrachart.h"

	class Test_1: public Study
	{
		public:

			Test_1(SCStudyInterfaceRef sc);
			~Test_1(); 
			
			void DoInit();
			void DoCleanUp();

			void SetReferences(SCStudyInterfaceRef sc_);
			void DoSetDefaults(SCStudyInterfaceRef sc_);
			void DoStudy(SCStudyInterfaceRef sc_);
			void Run(SCStudyInterfaceRef sc_);
			
			bool Initialized = FALSE;

			int mid;
	};