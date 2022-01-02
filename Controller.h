#pragma once
#include "sierrachart.h"
#include <cmath>

typedef enum StudyType
{
    TEST_STUDY1
    //TEST_STUDY2,
    //TEST_STUDY3
}StudyType_ ;

typedef s_sc* SCPtr;

class Study {
	public:
        Study(SCStudyInterfaceRef sc_) { return; }

        static Study* StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_);

    protected:
        virtual void Run() = 0;
        virtual void SetReferences(SCPtr sc_) = 0;
        virtual void DoSetDefaults() = 0;
        virtual void DoStudy() = 0;
        virtual void DoInit() = 0;
        virtual void DoCleanUp() = 0;
        SCPtr _sc;

    private:
        static Study* study;
        bool Initialized = FALSE;
};


  

