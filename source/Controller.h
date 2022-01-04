#pragma once
#include "sierrachart.h"
#include <cmath>

typedef enum StudyType
{
    TEST_STUDY1

}StudyType_ ;


// Using ifndef here so this only occurs once,
// but is still in the 'global' scope, since
// study class files need to #include controller.h
// ?? is this necessary since we're doing #pragma once?
#ifndef typedef s_sc* SCPtr;
typedef s_sc* SCPtr;
#endif


class Study {
    public:
        Study(SCStudyInterfaceRef sc_) { return; }
        virtual ~Study() {};
        static Study* StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_);

    protected:
        virtual void Run() = 0;
        virtual void SetReferences(SCPtr sc_) = 0;
        virtual void DoSetDefaults() = 0;
        virtual void DoStudy() = 0;
        virtual void DoInit() = 0;
        virtual void DoCleanUp() = 0;
        SCPtr _sc;
};
