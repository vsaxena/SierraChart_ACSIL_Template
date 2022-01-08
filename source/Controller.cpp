#include "Controller.h"
#include "test_study_1.h"

/********************************************
*   ACSIL entryway access to study controller
********************************************/
Study* Study::StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_) {
    
    // Check to see if this is a study's first call on initial chart loading
    const bool IsDLLInit = sc_.SetDefaults && sc_.ArraySize == 0;

    /********************************************
    *   If first load, leave null for later assignment
    *   If not first load, retrieve persistent pointer to class
    ********************************************/
    Study* study = IsDLLInit ? NULL : static_cast<Study*>(sc_.GetPersistentPointer(1));

    /********************************************
    *   If first load, create study class object and assign 
    *   to sc persistent pointer
    ********************************************/
    if (study == NULL) {
        switch (StudyType_) {
        case TEST_STUDY1:
            study = new Test_1(sc_);
            break;
        /******************************************* 
        *   Add additional studies to controller
        *   where new Test_1(sc_) is the study class constructor
        *   and where TEST_STUDY1 is the enum value for study
        ********************************************
        case TEST_STUDY1:
            study = new Test_1(sc_);
            break;
        *********************************************/
        }
        sc_.SetPersistentPointer(1, study); 
    }
    /********************************************
    *   These next study calls will be to the SetRef
    *   and run funcs that live inside the specific  
    *   study that is currently being controlled.
    ********************************************/
    study->SetReferences(&sc_);
    study->Run();

    /********************************************* 
    *   Cleanup for deleting study / closing chart
    *   or if we arrived here and DLL isn't init,
    *   then we want to clean up and prepare for
    *   study's next iteration, for proper assignment
    *********************************************/
    if (sc_.LastCallToFunction || IsDLLInit) {
        delete study;
        study = NULL;
        sc_.SetPersistentPointer(1, study);
    }
    return study;
}
