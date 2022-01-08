#include "Controller.h"
#include "test_study_1.h"

Study* Study::StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_) {
         
    const bool IsDLLInit = sc_.SetDefaults && sc_.ArraySize == 0;

    Study* study = IsDLLInit ? NULL : static_cast<Study*>(sc_.GetPersistentPointer(1));

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
        */
        }
        sc_.SetPersistentPointer(1, study); 
    }

    study->SetReferences(&sc_);
    study->Run();

    if (sc_.LastCallToFunction || IsDLLInit) {
        delete study;
        study = NULL;
        sc_.SetPersistentPointer(1, study);
    }
    return study;
}
