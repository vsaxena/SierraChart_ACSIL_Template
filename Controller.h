#pragma once
#include "sierrachart.h"
#include <cmath>

typedef enum StudyType
{
    TEST_STUDY1,
    TEST_STUDY2,
    TEST_STUDY3
}StudyType_ ;


class Study {
	public:
        Study(SCStudyInterfaceRef sc_) { return; }

        static Study* StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_);

        virtual void Run(SCStudyInterfaceRef sc_);
        virtual void SetReferences(SCStudyInterfaceRef sc_) {};
      
    private:
        static Study* study;
};


  

