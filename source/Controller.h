#pragma once
#include "sierrachart.h"
#include <cmath>

// Add additional Study names to enum when created
typedef enum StudyType
{
    TEST_STUDY1
    /***************** 
    *   samplestudy1, 
    *   samplestudy2,
    *   samplestudy3
    ******************/
}StudyType_ ;

typedef s_sc* SCPtr;

// Base class that controls studies
class Study {
    public:
        Study(SCStudyInterfaceRef sc_) { return; }
        virtual ~Study() {};
        static Study* StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_);

    protected:
        // Pure virtual funcs for study classes to inherit/define
        virtual void Run() = 0;
        virtual void SetReferences(SCPtr sc_) = 0;
        virtual void DoSetDefaults() = 0;
        virtual void DoStudy() = 0;
        virtual void DoInit() = 0;
        virtual void DoCleanUp() = 0;
        SCPtr _sc;
};
