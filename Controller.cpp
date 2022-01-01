#include "Controller.h"
#include "test_study_1.h"
#include "test_study_2.h"
#include "test_study_3.h"

Study* Study::StartStudy(StudyType StudyType_, SCStudyInterfaceRef sc_) {
         
    const bool IsDLLInit = sc_.SetDefaults && sc_.ArraySize == 0;

    Study* study = IsDLLInit ? NULL : static_cast<Study*>(sc_.GetPersistentPointer(1));

    if (study == NULL) {

        switch (StudyType_) {
        case TEST_STUDY1:
            study = new Test_1(sc_);
            break;
        case TEST_STUDY2:
            study = new Test_2(sc_);
            break;
        case TEST_STUDY3:
            study = new Test_3(sc_);
            break;
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

void Study::Run() {
    if (!Initialized) {
        DoInit();
    }
    if (_sc->SetDefaults) {
        DoSetDefaults();
    }
    if (_sc->LastCallToFunction) {
        DoCleanUp();
        return;
    }
    DoStudy();
}
