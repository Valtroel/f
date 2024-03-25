#pragma once
#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#define USE_SYSTEM_DATE
#define ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL

//#define AUTO_SIGN_IN
//#define TEST_SRED_BAL_UNIT
//#define NEW_CHECKS
//#define REFACTORING
//#define TEST_EXAMEN_UNIT
//#define TEST_SPLASH_UNIT
//#define TEST_LIST_DLG
//#define TEST_MAIN_UNIT
//#define USE_OLD_IF_DOES_NOT_WORK_SRED_BAL_UNIT
//#define TARGETED_CONTRACT_ENROLLMENT
//#define TESTING_EXAMENN_SPEC_UNIT
//#define ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
//#define DATABASE_SUBSTITUTE
//#define SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE
//#define SHOW_EXTRA_BUTTONS

#define NEW_EXAM_SUMMARY_LISTS

//#define DEEP_CHECK_PERSONAL_NUMBER                                            // WARNING: BE CAREFUL!!!! Works only for personal numbers until 2012.

//#define CHECK_SPECIALITY_OR_PROFILING

//#define DELETE_PREVIOUS_VERSION_OF_KOS


//#define SET_INVENTORY_DATE_BY_HAND                                              // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST AND (ListDlgUnit.cpp)


#include "enums.hpp"

//#define STATE_FROM_WORK_PC

#ifndef STATE_FROM_WORK_PC
    #ifndef NEW_INTEGRATION         // CHECKED!!!!                              EUGEN PC STATE ON 06.07.2023 21:18:52
        namespace Admissions
        {
            namespace TIME
            {
                const AnsiString
                    YEAR                 =
                        (Now ())
                            .FormatString (
                                "yyyy"
                            );
            }
            namespace INVENTORY
            {
                const AnsiString
                    #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                    DATE                 =
                        "18.07.2023";
                    #else
                    DATE                 =
                        (Now ())
                            .FormatString (
                                "dd.mm.yyyy"
                            );
                    #endif  // SET_INVENTORY_DATE_BY_HAND
            }
            namespace DEADLINE
            {
                const AnsiString
                    FOR_RECEIVING_PART_1 =
                        "05.06."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00",
                    FOR_RECEIVING_PART_2 =
                        "10.08."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00";
            }
            namespace ADDITIONAL
            {
                const AnsiString
                    ORDER_DATE_PART_1    =
                        "04.06."                    +
                            Admissions::TIME::YEAR,
                    ORDER_DATE_PART_2    =
                        "08.08."                    +
                            Admissions::TIME::YEAR;
            }
            namespace DOCUMENTS
            {
                const AnsiString
                    PROVIDE_DATE =
                        "15.06."                    +
                            Admissions::TIME::YEAR;
            }
            namespace ARRIVAL
            {
                namespace TIME
                {
                    const AnsiString
                        EVERYONE = "9:00";
                }
                namespace DATE
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            ALL =
                                "01.09."                                +
                                    Admissions::TIME::YEAR;
                    }
                    namespace EXTRAMURAL
                    {
                        namespace FULL
                        {
                            const AnsiString
                                MSTH_MNG     =
                                    "18.09."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_TOURISM =
                                    "11.09."                            +
                                        Admissions::TIME::YEAR,
                                OTHER        =
                                    "18.09."                            +
                                        Admissions::TIME::YEAR;
                        }
                        namespace SECOND_COURSE
                        {
                            const AnsiString
                                SMA          =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MS           =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                RPC          =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MSTH_MNG     =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MSTH_TOURISM =
                                    "30.10."                            +
                                        Admissions::TIME::YEAR;

                            namespace SKIING
                            {
                                const AnsiString
                                    SMA =
                                        "02.10."                        +
                                            Admissions::TIME::YEAR,
                                    MS  =
                                        "04.10."                        +
                                            Admissions::TIME::YEAR,
                                    RPC =
                                        "06.10."                        +
                                            Admissions::TIME::YEAR;
                            }
                        }
                        namespace THIRD_COURSE
                        {
                            const AnsiString
                                SMA          =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MS           =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                RPC          =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_MNG     =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_TOURISM =
                                    "04.12."                            +
                                        Admissions::TIME::YEAR;
                        }
                    }
                }
            }
        }
        namespace ContestType
        {
            const AnsiString
                GENERAL                = "�����",
                WITHOUT_ENTRANCE_EXAMS = "��� ������������� ���������",
                OUT_OF_COMPETITION     = "��� ��������",
                TARGETED_TRAINING      = "�������";
        }
        namespace Contract
        {
            namespace DOCUMENT_FILE
            {
                const AnsiString
                    BUDGET  = "������� - ������.xls",
                    BUYERS  = "������� - ��������.xls";
            }
            namespace DOCUMENT_NAME
            {
                const AnsiString
                    BUDGET = "������� - ������",
                    BUYERS = "������� - ��������";
            }
            namespace BSUPC
            {
                const AnsiString
                    PERSON = "������� ��������� �������������";

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "������������",
                        DATE   = "16.11.2021",
                        NUMBER = "13-16-45";
                }
            }
            namespace IMS
            {
                const AnsiString
                    PERSON = "���������� ����� ����������";

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "������������",
                        DATE   = "26.10.2021",
                        NUMBER = "13-16-42";
                }
            }
            namespace PAYMENT_TERM
            {
                const AnsiString
                    FIRST_SEMESTER  =
                        "�� 01.09."                                 +
                            Admissions::TIME::YEAR                  +
                        " (������������) � �� ������ "              \
                        "������� ������� ���� �������� � �������",
                    SECOND_SEMESTER =
                        "� 01.02."                                  +
                                AnsiString (
                                        StrToInt (
                                            Admissions::TIME::YEAR
                                        )
                                    +   Default::STEP
                                )                                   +
                        " �� 01.03."                                +
                                AnsiString (
                                        StrToInt (
                                            Admissions::TIME::YEAR
                                        )
                                    +   Default::STEP
                                )                                   +
                        " � �� ������ ������� ������� ���� "        \
                        "�������� � �������";
            }
            namespace COST_FOR
            {
                namespace BUDGET
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // ������, �������, ������ ����
                                "���������� ���������� �������� "               \
                                "���������� 45828,64 ("                         \
                                "����� ���� ����� ��������� �������� ������ "   \
                                "������ 64 �������) ����������� ������.",
                            SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                                "���������� ���������� �������� "               \
                                "���������� 34371,48 ("                         \
                                "�������� ������ ������ ������ ��������� ���� " \
                                "����� 48 ������) ����������� ������.";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // ������, �������, ������ ����
                                "���������� ���������� �������� "               \
                                "���������� 22914,30 ("                         \
                                "�������� ��� ������ ��������� ������������ "   \
                                "������ 30 ������) ����������� ������.",
                            SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                                "���������� ���������� �������� "               \
                                "���������� 18331,44 ("                         \
                                "������������ ����� ������ �������� ���� "      \
                                "����� 44 �������) ����������� ������.",
                            THIRD_COURSE  =                                             // ������, �������, �����٨���� ���� (3 ����)
                                "���������� ���������� �������� "               \
                                "���������� 13748,58 ("                         \
                                "���������� ����� ������� ����� ������ "        \
                                "������ 58 ������) ����������� ������.";
                    }
                }
                namespace BUYERS
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString                                                // ��������, �������, �� ���
                            ANNUAL       =
                                "���������� 3233 ("                             \
                                "��� ������ ������ �������� ��� �����"          \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            PER_SEMESTER =                                              // ��������, �������, �� ���������
                                "1616,50 ("                                     \
                                "���� ������ �������� ����������� "             \
                                "������ 50 ������) ����������� ������;";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            ANNUAL           =                                          // ��������, �������, �� ��� (����, ���, ���)
                                "���������� 1251 ("                             \
                                "���� ������ ������ ��������� ����"             \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            ANNUAL_IMS       =                                          // ��������, �������, �� ��� (�����)
                                "���������� 1335 ("                             \
                                "���� ������ ������ �������� ����"              \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            PER_SEMESTER     =                                          // ��������, �������, �� ��������� (����, ���, ���)
                                "625,50 ("                                      \
                                "�������� �������� ���� "                       \
                                "������ 50 ������) ����������� ������;",
                            PER_SEMESTER_IMS =                                          // ��������, �������, �� ��������� (�����)
                                "667,50 ("                                      \
                                "�������� ���������� ���� "                     \
                                "������ 50 ������) ����������� ������;";
                    }
                }
            }
        }
        namespace DeaneryDB
        {
            namespace QUALIFICATION
            {
                const AnsiString
                    TEACHER_PHYSICAL_CULTURE_SPORTS  =
                        "������������� ���������� �������� � ������",
                    COACHING_BY_SPORT                =
                        "������ �� ���� ������",
                    PHYSICAL_EDUCATION_TEACHER       =
                        "������� ���������� ��������",
                    TEACHER_ORGANIZER_HEALTH_TOURISM =
                        "�������-����������� ������������-��������������� "     \
                        "������ � �������",
                    TEACHER_ORGANIZER_PRESCHOOLERS   =
                        "�������-����������� ����������� ���������� � "         \
                        "���������� �����������",
                    MANAGER_SPORT_TOURISM            =
                        "�������� ������ � �������",
                    INSTRUCTOR_REHABILITATION        =
                        "����������-�������� ���������� ������������",
                    INSTRUCTOR_MEDICAL               =
                        "����������-�������� �������� ���������� ��������",
                    TEACHER_PHYSICAL_CULTURE         =
                        "������������� ���������� ��������",
                    INSTRUCTOR_BY_HEALTH             =
                        "����������-�������� �� ��������������� ���������� "    \
                        "��������",
                    INSTRUCTOR_BY_ADAPTIVE           =
                        "����������-�������� �� ���������� ���������� "         \
                        "��������",
                    INSTRUCTOR_PRESCHOOLERS          =
                        "����������-�������� ����������� ���������� � "         \
                        "���������� �����������",
                    PSYCHOLOGIST                     =
                        "��������",
                    MANAGER_SPORT                    =
                        "�������� � ������",
                    MANAGER_TUORISM                  =
                        "�������� �� �������",
                    INSTRUCTOR_RECREATIONAL          =
                        "����������-�������� �� �������",
                    MANAGER_DIRECTING                =
                        "��������-�������� ���������-�������� �����������",
                    INSTRUCTOR_BY_MEDICAL            =
                        "����������-�������� �� �������� ���������� ��������",
                    INSTRUCTOR_BY_REHABILITATION     =
                        "����������-�������� �� ���������� ������������",
                    INSTRUCTOR_BY_ERGOTHERAPY        =
                        "����������-�������� �� �����������",
                    SPECIALIST_TOURISM_HOSPITALITY   =
                        "���������� � ����� ������� � ��������������";
            }
        }
        namespace DocumentFile
        {
            namespace APPLICATION_FOR
            {
                const AnsiString
                    PARTICIPATION       = "��������� - ������ � �������.xls";
            }
            namespace LIST
            {
                const AnsiString
                    GROUPS              = "������ - �����.xls";                         // NEW (������.xls -> ������ - �����.xls)
            }
            namespace PROTOCOL
            {
                AnsiString
                    admitted            = "�������� - � ������� ������������.doc",      // NEW (OLE Issue) DELETE YEAR
                    daily               = "�������� - ����������.xls",
                    exam                = "�������� - ������� �� ����.xls";
                const AnsiString
                    GIRLS_TESTS         = "�������� - ��������� (�������).xls";
            }
            namespace REGISTRY
            {
                const AnsiString
                    BOOK                = "������ - �����������.xls";
            }
            namespace REPORT
            {
                const AnsiString
                    FORM_1              = "����� - ����� 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                    FORM_2              = "����� - ����� 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                    SUBMITTED           = "����� - ������ ���������.xls";
            }
            namespace STATISTIC
            {
                AnsiString
                    cert_result_hundred =
                        "���������� - ���������� ������������ (�����������).xls",
                    cert_result_ten     =
                        "���������� - ���������� ������������ (��������������).xls",    // (REQUIRE CHECK Range)
                    exam_result         =
                        "���������� - ���������� ����� ���������.xls";
                const AnsiString
                    ADMISSION_PROGRESS  =
                        "���������� - ��� ������.xls",
                    CONTEST             =
                        "���������� - �������.xls",                                     // NEW DELETE YEAR
                    DAILY               =
                        "���������� - ����������.xls",
                    LEVEL_OF_SPORTS     =
                        "���������� - ������� ���������� ����������.xls",
                    SCORES              =
                        "���������� - �����.xls";                                       // NOTE: INSTEAD USEING Abitur_RIO
            }
            namespace SUMMARY_LIST
            {
                const AnsiString
                    ENROLLMENT          = "��������� - ����������.xls",
                    ENTRANCE_EXAMS      = "��������� - ������������� ���������.xls";    // NEW DELETE YEAR
            }
        }
        namespace DocumentName
        {
            namespace APPLICATION_FOR
            {
                const AnsiString
                    PARTICIPATION      = "��������� - ������ � �������";
            }
            namespace LIST
            {
                const AnsiString
                    GROUPS             = "������ - �����",                              // NEW (������ -> ������ - �����)
                    BY_DESTINATIONS    = "������ - �� ������������",
                    BY_GENDER          = "������ - �� ����";
            }
            namespace PROTOCOL
            {
                AnsiString
                    daily              = "�������� - ����������",
                    exam               = "�������� - ������� �� ����";
                const AnsiString
                    GIRLS_TESTS        = "�������� - ��������� (�������)";
            }
            namespace REGISTRY
            {
                const AnsiString
                    BOOK               = "������ - �����������";
            }
            namespace REPORT
            {
                const AnsiString
                    FORM_1             = "����� - ����� 1",
                    FORM_2             = "����� - ����� 2",
                    SUBMITTED          = "����� - ������ ���������";                    // (REQUIRE CHECK Calcalation)
            }
            namespace STATISTIC
            {
                const AnsiString
                    ADMISSION_PROGRESS =
                        "���������� - ��� ������",
                    CONTEST            =
                        "���������� - �������",
                    DAILY              =
                        "���������� - ����������",
                    LEVEL_OF_SPORTS    =
                        "���������� - ������� ���������� ����������",
                    SCORES             =
                        "���������� - �����";                                           // INSTEAD USEING Abitur_RIO
            }
            namespace SUMMARY_LIST
            {
                const AnsiString
                    ENROLLMENT         = "��������� - ����������",
                    ENTRANCE_EXAMS     = "��������� - ������������� ���������";
            }
        }
        namespace EducationType
        {
            const AnsiString
                EXTRAMURAL = "�������",
                INTRAMURAL = "�������",
                EXTRA_FORM = "�������",
                INTRA_FORM = "�������";
        }
        namespace EnvelopeMessage
        {
            namespace BUDGET
            {
                const AnsiString
                    EXTRAMURAL = "������, ������� ����� ��������",
                    INTRAMURAL = "������, ������� ����� ��������";
            }
            namespace BUYERS
            {
                const AnsiString
                    EXTRAMURAL = "�� ������, ������� ����� ��������",
                    INTRAMURAL = "�� ������, ������� ����� ��������";
            }
        }
        namespace Faculty
        {
            const AnsiString
                SMA  = "����",                                                          // 1, -> Sports and Marital Arts (����)
                MS   = "���",                                                           // 2, -> Mass Sports (���)
                RPC  = "���",                                                           // 3, -> Recreational Physical Culture (�����)
                MSTH = "�����",                                                         // 4, -> Management of Sports, Tourism and Hospitality (����)
                MD   = "�����������",                                                   // 5, -> Master's Degree (�����������)
                PGS  = "�����������",                                                   // 6, -> PostGraduate Studies (�����������)
                DOC  = "������������";                                                  // 7  -> DOCtorate (������������)
        }
        namespace LegallyAuthorizedPerson
        {
            AnsiString
                edu_head_desc  = "�������� �.�.";
            const AnsiString
                DEAN_FACULTY_1 = "�.�.��������",                                        // ����  (SMA)  - Sports and Marital Arts
                DEAN_FACULTY_2 = "�.�.����������",                                      // ���   (MS)   - Mass Sports
                DEAN_FACULTY_3 = "�.�.���������",                                       // ����� (RPC)  - Recreational Physical Culture
                DEAN_FACULTY_4 = "�.�.���������",                                       // ����  (MSTH) - Management of Sports, Tourism and Hospitality
                SECRETARY      = "�.�. �����",
                SECRETARY_DESC = "����� �.�.",
                VICE_RECTOR    = "�.�.������";
        }
        namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
        {
            namespace _2009
            {
                namespace CODE
                {
                    namespace PART
                    {
                        const AnsiString
                            BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                            PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                            PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                            COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                            PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                            TOURISM_HOSPITALITY            = "1-89";
                    }
                    namespace CHAPTER
                    {
                        const AnsiString
                            PHYSIOLOGY                     = "03.03.01",                // Master degree
                            THEORY_IMPROVING               = "13.00.04",                // Master degree
                            RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                            MANAGEMENT                     = "1-26 80",                 // Master degree
                            PHYSICAL_CULTURE               = "1-88 01",
                            SPORT                          = "1-88 02",
                            TOURISM_HOSPITALITY            = "1-89 01",
                            TOURISM                        = "1-89 02",
                            HOSPITALITY                    = "1-89 03",
                            RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                            INNOVATION                     = "1-89 81";                 // Master degree
                    }
                    namespace SECTION
                    {
                        const AnsiString
                            RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                            RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                            PHYSICAL_CULTURE               = "1-88 01 01",
                            IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                            REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                            TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                            SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                            SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                            TOURISM_HOSPITALITY            = "1-89 01 01",
                            SPORTS_AND_TOURISM             = "1-89 02 01",
                            TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                            HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                            RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                            INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                            INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                            INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                            INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                    }
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL                       = "1-88 01 01-01",
                            PRESCHOOLERS                  = "1-88 01 01-02",
                            HEALTH                        = "1-88 01 02-01",
                            ADAPTIVE                      = "1-88 01 02-02",
                            REHABILITATION                = "1-88 01 03-01",
                            ERGOTHERAPY                   = "1-88 01 03-02",
                            COACHING                      = "1-88 02 01-01",
                            MANAGEMENT                    = "1-88 02 01-02",
                            PSYCHOLOGY                    = "1-88 02 01-03",
                            DIRECTING                     = "1-88 02 01-04",
                            PROMOTION                     = "1-89 01 01 01",
                            IT                            = "1-89 01 01 02",
                            LOGISTICS                     = "1-89 01 01 03",
                            SOCIAL                        = "1-89 01 01 04",
                            TRANSPORT                     = "1-89 01 01 05",
                            CATERING                      = "1-89 01 01 06",
                            ACCOMMODATION                 = "1-89 01 01 07",
                            SUPPORTING                    = "1-89 01 01 08",
                            TREATMENT                     = "1-89 01 01 09",
                            RECREATIONAL                  = "1-89 02 01-01",
                            TUORISM_MNG                   = "1-89 02 01-02",
                            RESTAURANTS                   = "1-89 03 01-01";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  = "03.03.01",
                                THEORY      = "13.00.04";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       = "1-08 80 04",
                                MANAGEMENT  = "1-26 80 04",
                                TOURISM     = "1-89 80 01";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  = "1-89 81 01",
                                TOURISM     = "1-89 81 02",
                                HOSPITALITY = "1-89 81 03",
                                TECHNO      = "1-89 81 04";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL      = "1-88 01 01-01",
                            PRESCHOOLERS = "1-88 01 01-02";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH   = "1-88 01 02-01",
                            ADAPTIVE = "1-88 01 02-02";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION = "1-88 01 03-01",
                            ERGOTHERAPY    = "1-88 01 03-02";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING = "1-88 01 04";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING   = "1-88 02 01-01",
                            MANAGEMENT = "1-88 02 01-02",
                            PSYCHOLOGY = "1-88 02 01-03",
                            DIRECTING  = "1-88 02 01-04";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION     = "1-89 01 01 01",
                            IT            = "1-89 01 01 02",
                            LOGISTICS     = "1-89 01 01 03",
                            SOCIAL        = "1-89 01 01 04",
                            TRANSPORT     = "1-89 01 01 05",
                            CATERING      = "1-89 01 01 06",
                            ACCOMMODATION = "1-89 01 01 07",
                            SUPPORTING    = "1-89 01 01 08",
                            TREATMENT     = "1-89 01 01 09";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL = "1-89 02 01-01",
                            TUORISM_MNG  = "1-89 02 01-02";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS = "1-89 03 01-01";
                    }
                }
                namespace NAME
                {
                    namespace PART
                    {
                        const AnsiString
                            BIOLOGICAL_SCIENCES        =                                // Master degree
                                "������������� �����",
                            PEDAGOGICAL_SCIENCES       =                                // Master degree
                                "�������������� �����",
                            PEDAGOGY_PROFESSIONAL      =                                // Master degree
                                "����������. ���������������� �����������",
                            COMMUNICATION_SCIENCES     =                                // Master degree
                                "����������",
                            PHYSICAL_CULTURE_AND_SPORT =
                                "���������� �������� � �����",
                            TOURISM_HOSPITALITY        =
                                "������. ��������������";
                    }
                    namespace CHAPTER
                    {
                        const AnsiString
                            PHYSIOLOGY               =                                  // Master degree
                                "����������",
                            THEORY_IMPROVING         =                                  // Master degree
                                "������ � �������� ����������� ����������, "        \
                                "���������� ����������, ��������������� � "         \
                                "���������� ���������� ��������",
                            RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                                "������� ������������ � ����������, ������������",
                            PHYSICAL_CULTURE         =
                                "���������� ��������",
                            SPORT                    =
                                "�����",
                            TOURISM_HOSPITALITY      =
                                "������ � ��������������",
                            TOURISM                  =
                                "������",
                            HOSPITALITY              =
                                "��������������",
                            RESEARCH_AND_TEACHING    =                                  // Master degree
                                "������� ������������ � ����������, ������������",
                            INNOVATION                     =                            // Master degree
                                "������������� ������������ (� ����������� "        \
                                "����������� ������������)";
                    }
                    namespace SECTION
                    {
                        const AnsiString
                            RESEARCH_SPORT                 =                            // Master degree
                                "���������� �������� � �����",
                            PHYSICAL_CULTURE              =
                                "���������� �������� (�� ������������)",
                            IMPROVING_AND_ADAPTIVE        =
                                "��������������� � ���������� ���������� �������� " \
                                "(�� ������������)",
                            REHABILITATION_ERGOTHERAPY    =
                                "���������� ������������ � ����������� "            \
                                "(�� ������������)",
                            TRAINING_MILITARY_PERSONNEL   =
                                "���������� ���������� ��������������",
                            SPORTS_AND_PEDAGOGY           =
                                "���������-�������������� ������������",
                            SPORTS_CHOREOGRAPHY           =
                                "���������� �����������",
                            TOURISM_HOSPITALITY       =
                                "������ � ��������������",
                            SPORTS_AND_TOURISM            =
                                "���������-���������� ������������ "                \
                                "(�� ������������)",
                            TOURISM_AND_NATURE_MANAGEMENT =
                                "������ � ������������������",
                            HOSPITALITY_TECHNOLOGIES      =
                                "���������� ��������� �������������� "              \
                                "(�� ������������)",
                            TOURISM_HOSPITALITY_STUDY =
                                "������ � ��������������",
                            RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                                "������ � ��������������",
                            INNOVATION_MANAGEMENT          =                            // Master degree
                                "���������� �������������� ��������� � "            \
                                "���������� ���������",
                            INNOVATION_TOURISM             =                            // Master degree
                                "������������� ���������� � ����� �������",
                            INNOVATION_HOSPITALITY         =                            // Master degree
                                "������������� ���������� � ����� ��������������",
                            INNOVATION_TECHNOLOGY          =                            // Master degree
                                "������������� ���������� � ����� ������� � "       \
                                "��������������";
                    }
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL        =
                                "���������� �������� (��������)",
                            PRESCHOOLERS   =
                                "���������� �������� (������������)",
                            HEALTH         =
                                "��������������� � ���������� ���������� �������� " \
                                "(���������������)",
                            ADAPTIVE       =
                                "��������������� � ���������� ���������� �������� " \
                                "(����������)",
                            REHABILITATION =
                                "���������� ������������ � ����������� "            \
                                "(���������� ������������)",
                            ERGOTHERAPY    =
                                "���������� ������������ � ����������� "            \
                                "(�����������)",
                            COACHING       =
                                "���������-�������������� ������������ "            \
                                "(���������� ������ � ��������� ���� ������)",
                            MANAGEMENT     =
                                "���������-�������������� ������������ "            \
                                "(���������� � ������)",
                            PSYCHOLOGY     =
                                "���������-�������������� ������������ "            \
                                "(���������� ����������)",
                            DIRECTING      =
                                "���������-�������������� ������������ "            \
                                "(���������� ���������)",
                            PROMOTION      =
                                "���������� ������������ � ����������� "            \
                                "������������� �����",
                            IT             =
                                "�������������� ���������� ������������� "          \
                                "���������",
                            LOGISTICS      =
                                "��������� � ������������� ���������",
                            SOCIAL         =
                                "���������� ���������������� ������� ��������",
                            TRANSPORT      =
                                "���������� ������������� ������� ��������",
                            CATERING       =
                                "���������� ������� ������� ��������",
                            ACCOMMODATION  =
                                "���������� ������� ���������� ��������",
                            SUPPORTING     =
                                "���������� ������������-����������������� "        \
                                "������� ��������",
                            TREATMENT      =
                                "���������� ������� ������������ � ������� "        \
                                "��������",
                            RECREATIONAL   =
                                "���������-���������� ������������ "                \
                                "(���������� � ������������� ������)",
                            TUORISM_MNG    =
                                "���������-���������� ������������ "                \
                                "(���������� � �������)",
                            RESTAURANTS    =
                                "���������� ��������� �������������� "              \
                                "(����������� ������������)";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  =
                                    "����������",
                                THEORY      =
                                    "������ � �������� ����������� ����������, "    \
                                    "���������� ����������, ��������������� � "     \
                                    "���������� ���������� ��������";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       =
                                    "���������� �������� � �����",
                                MANAGEMENT  =
                                    "����������",
                                TOURISM     =
                                    "������ � ��������������";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  =
                                    "���������� �������������� ��������� � "        \
                                    "���������� ���������",
                                TOURISM     =
                                    "������������� ���������� � ����� �������",
                                HOSPITALITY =
                                    "������������� ���������� � ����� "             \
                                    "��������������",
                                TECHNO  =
                                    "������������� ���������� � ����� ������� � "   \
                                    "��������������";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL        = "���������� �������� (��������)",
                            PRESCHOOLERS   = "���������� �������� (������������)";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH         =
                                "��������������� � ���������� ���������� �������� " \
                                "(���������������)",
                            ADAPTIVE       =
                                "��������������� � ���������� ���������� �������� " \
                                "(����������)";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION =
                                "���������� ������������ � ����������� "            \
                                "(���������� ������������)",
                            ERGOTHERAPY    =
                                "���������� ������������ � ����������� "            \
                                "(�����������)";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING       = "���������� ���������� ��������������";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING       =
                                "���������-�������������� ������������ "            \
                                "(���������� ������ � ��������� ���� ������)",
                            MANAGEMENT     =
                                "���������-�������������� ������������ "            \
                                "(���������� � ������)",
                            PSYCHOLOGY     =
                                "���������-�������������� ������������ "            \
                                "(���������� ����������)",
                            DIRECTING      =
                                "���������-�������������� ������������ "            \
                                "(���������� ���������)";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION      =
                                "���������� ������������ � ����������� "            \
                                "������������� �����",
                            IT             =
                                "�������������� ���������� ������������� ���������",
                            LOGISTICS      =
                                "��������� � ������������� ���������",
                            SOCIAL         =
                                "���������� ���������������� ������� ��������",
                            TRANSPORT      =
                                "���������� ������������� ������� ��������",
                            CATERING       =
                                "���������� ������� ������� ��������",
                            ACCOMMODATION  =
                                "���������� ������� ���������� ��������",
                            SUPPORTING     =
                                "���������� ������������-����������������� "        \
                                "������� ��������",
                            TREATMENT      =
                                "���������� ������� ������������ � ������� "        \
                                "��������";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL   =
                                "���������-���������� ������������ "                \
                                "(���������� � ������������� ������)",
                            TUORISM_MNG    =
                                "���������-���������� ������������ "                \
                                "(���������� � �������)";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS    =
                                "���������� ��������� �������������� "              \
                                "(����������� ������������)";
                    }
                }
                namespace QUALIFICATION
                {
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL        =
                                "����������-�������� �� �������� ���������� "       \
                                "��������. ������������� ���������� ��������",
                            PRESCHOOLERS   =
                                "����������-�������� ����������� ���������� � "     \
                                "���������� �����������. "                          \
                                "������������� ���������� ��������",
                            HEALTH         =
                                "����������-�������� �� ��������������� "           \
                                "���������� ��������. "                             \
                                "������������� ���������� ��������",
                            ADAPTIVE       =
                                "����������-�������� �� ���������� "                \
                                "���������� ��������. "                             \
                                "������������� ���������� ��������",
                            REHABILITATION =
                                "����������-�������� �� ���������� "                \
                                "������������. "                                    \
                                "������������� ���������� ��������",
                            ERGOTHERAPY    =
                                "����������-�������� �� �����������. "              \
                                "������������� ���������� ��������",
                            TRAINING       =
                                "���������� �� ����������. "                        \
                                "����������-�������� �� ���������� "                \
                                "����������",
                            COACHING       =
                                "������ (�� ���� ������). "                         \
                                "������������� ���������� ��������",
                            MANAGEMENT     =
                                "�������� � ������. "                               \
                                "������������� ���������� ��������",
                            PSYCHOLOGY     =
                                "��������. "                                        \
                                "������������� ���������� ��������",
                            DIRECTING      =
                                "��������-�������� ���������-�������� "             \
                                "�����������."                                      \
                                "������������� ���������� ��������",
                            PROMOTION      =
                                "���������� � ����� ������� � ��������������",
                            IT             =
                                "���������� � ����� ������� � ��������������",
                            LOGISTICS      =
                                "���������� � ����� ������� � ��������������",
                            SOCIAL         =
                                "���������� � ����� ������� � ��������������",
                            TRANSPORT      =
                                "���������� � ����� ������� � ��������������",
                            CATERING       =
                                "���������� � ����� ������� � ��������������",
                            ACCOMMODATION  =
                                "���������� � ����� ������� � ��������������",
                            SUPPORTING     =
                                "���������� � ����� ������� � ��������������",
                            TREATMENT      =
                                "���������� � ����� ������� � ��������������",
                            RECREATIONAL   =
                                "����������-�������� �� �������. "                  \
                                "������������� ���������� ��������",
                            TUORISM_MNG    =
                                "�������� �� �������. "                             \
                                "������������� ���������� ��������",
                            RESTAURANTS    = "��������. ��������";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  = "�������",
                                THEORY      = "�������";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       = "�������",
                                MANAGEMENT  = "�������",
                                TOURISM     = "�������";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  = "�������",
                                TOURISM     = "�������",
                                HOSPITALITY = "�������",
                                TECHNO      = "�������";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL        =
                                "����������-�������� �� �������� ���������� "       \
                                "��������. ������������� ���������� ��������",
                            PRESCHOOLERS   =
                                "����������-�������� ����������� ���������� � "     \
                                "���������� �����������. "                          \
                                "������������� ���������� ��������";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH         =
                                "����������-�������� �� ��������������� "           \
                                "���������� ��������. "                             \
                                "������������� ���������� ��������",
                            ADAPTIVE       =
                                "����������-�������� �� ���������� "                \
                                "���������� ��������. "                             \
                                "������������� ���������� ��������";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION =
                                "����������-�������� �� ���������� "                \
                                "������������. "                                    \
                                "������������� ���������� ��������",
                            ERGOTHERAPY    =
                                "����������-�������� �� �����������. "              \
                                "������������� ���������� ��������";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING       =
                                "���������� �� ����������. "                        \
                                "����������-�������� �� ���������� "                \
                                "����������";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING       =
                                "������ (�� ���� ������). "                         \
                                "������������� ���������� ��������",
                            MANAGEMENT     =
                                "�������� � ������. "                               \
                                "������������� ���������� ��������",
                            PSYCHOLOGY     =
                                "��������. "                                        \
                                "������������� ���������� ��������",
                            DIRECTING      =
                                "��������-�������� ���������-�������� "             \
                                "�����������."                                      \
                                "������������� ���������� ��������";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION      =
                                "���������� � ����� ������� � ��������������",
                            IT             =
                                "���������� � ����� ������� � ��������������",
                            LOGISTICS      =
                                "���������� � ����� ������� � ��������������",
                            SOCIAL         =
                                "���������� � ����� ������� � ��������������",
                            TRANSPORT      =
                                "���������� � ����� ������� � ��������������",
                            CATERING       =
                                "���������� � ����� ������� � ��������������",
                            ACCOMMODATION  =
                                "���������� � ����� ������� � ��������������",
                            SUPPORTING     =
                                "���������� � ����� ������� � ��������������",
                            TREATMENT      =
                                "���������� � ����� ������� � ��������������";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL   =
                                "����������-�������� �� �������. "                  \
                                "������������� ���������� ��������",
                            TUORISM_MNG    =
                                "�������� �� �������. "                             \
                                "������������� ���������� ��������";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS    = "��������. ��������";
                    }
                }
            }
            namespace _2022
            {
                namespace CODE
                {
                    const AnsiString
                        PHYSIOLOGY       = "03.03.01",                                  // Master degree
                        THEORY_IMPROVING = "13.00.04",                                  // Master degree
                        INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                        INNO_TOURISM     = "1-89 81 02",                                // Master degree
                        INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                        INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                        PHYSICAL_CULTURE = "6-05-1012-01",
                        COACHING         = "6-05-1012-02",
                        REHABILITATION   = "6-05-1012-03",
                        MANAGEMENT       = "6-05-1012-04",
                        TOURISM          = "6-05-1013-01",
                        NATURE           = "6-05-1013-03",
                        HOSPITALITY      = "6-05-1013-04",
                        MNG_MASTER_DEGREE = "7-06-0412-01",
                        PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                        TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                        CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
                }
                namespace NAME
                {
                    const AnsiString
                        PHYSIOLOGY       =                                              // Master degree
                            "����������",
                        THEORY_IMPROVING =                                              // Master degree
                            "������ � �������� ����������� ����������, "        \
                            "���������� ����������, ��������������� � "         \
                            "���������� ���������� ��������",
                        INNO_MANAGEMENT  =                                              // Master degree
                            "���������� �������������� ��������� � "            \
                            "���������� ���������",
                        INNO_TOURISM     =                                              // Master degree
                            "������������� ���������� � ����� �������",
                        INNO_HOSPITALITY =                                              // Master degree
                            "������������� ���������� � ����� ��������������",
                        INNO_TECHNOLOGY  =                                              // Master degree
                            "������������� ���������� � ����� ������� � "       \
                            "��������������",
                        PHYSICAL_CULTURE =
                            "���������� ��������",
                        COACHING         =
                            "���������� ������������",
                        REHABILITATION   =
                            "���������� ������������ � �����������",
                        MANAGEMENT       =
                            "����������� � ���������� ���������� ���������, "   \
                            "������� � ��������",
                        TOURISM          =
                            "������ � ��������������",
                        NATURE           =
                            "������ � ������������������",
                        HOSPITALITY      =
                            "���������� ��������� ��������������",
                        PC_MASTER_DEGREE =                                              // Master degree
                            "���������� �������� � �����",
                        TH_MASTER_DEGREE =                                              // Master degree
                            "������ � ��������������",
                        CHOREOGRAPHY     =
                            "���������� �����������";

                    namespace PHYSICAL
                    {
                        const AnsiString
                            IMPROVING      = "(���������������)",                       // "(��������������� ���������� ��������)",
                            HEALTH         = "(��������)",                              // "(�������� ���������� ��������)",
                            PRESCHOOLERS   = "(������������)",                          // "(���������� �������� ������������)",
                            ADAPTIVE       = "(����������)",                            // "(���������� ���������� ��������)",
                            DIRECTING      = "(���������� ���������)",
                            PSYCHOLOGY     = "(���������� ����������)",
                            RECREATIONAL   = "(���������� � ������������� ������)";
                    }
                    namespace COACH
                    {
                        const AnsiString
                            DEFAULT        = "(� ��������� ���� ������)";
                    }
                    namespace REHABILITATE
                    {
                        const AnsiString
                            REHABILITATION = "(���������� ������������)",
                            ERGOTHERAPY    = "(�����������)";
                    }
                    namespace MANAGE
                    {
                        const AnsiString
                            SPORT          = "(���������� � ������)",
                            TOURISM        = "(���������� � �������)";
                    }
                }
                namespace QUALIFICATION
                {
                    const AnsiString
                        PHYSIOLOGY       = "�������",                                   // Master degree
                        THEORY_IMPROVING = "�������",                                   // Master degree
                        INNO_MANAGEMENT  = "������� ����������",                        // Master degree
                        INNO_TOURISM     = "������� �������",                           // Master degree
                        INNO_HOSPITALITY = "������� ��������������",                    // Master degree
                        INNO_TECHNOLOGY  = "������� ���������",                         // Master degree
                        PHYSICAL_CULTURE = "����������-��������. �������������",
                        COACHING         = "������. �������������",
                        REHABILITATION   = "����������-��������. �������������",
                        MANAGEMENT       = "��������. �������������",
                        TOURISM          = "����������",
                        NATURE           = "���������� �� ������� � ������������������",
                        HOSPITALITY      = "��������. ��������",
                        PC_MASTER_DEGREE = "�������",                                   // Master degree
                        TH_MASTER_DEGREE = "�������",                                   // Master degree
                        CHOREOGRAPHY     = "����������-��������";
                }
            }
        }
        namespace PathTo
        {
            const AnsiString
                OUTPUT_DOCUMENTS       = "D:\\��������� �������� ��������",
                OUTPUT_DOCUMENTS_SLASH = "D:\\��������� �������� ��������\\";
        }
        namespace Payment
        {
            const AnsiString
                BUDGET = "������",
                BUYERS = "�������";
        }
        namespace KindOfSport
        {
            const AnsiString
                GYMNASTICS                   =
                    "����������",
                MANAGEMENT_SPORTS_TOURISM    =
                    "���������� ������ � �������",
                PHYSICAL_REHABILITATION      =
                    "���������� ������������",
                THERAPEUTIC                  =
                    "�������� ���������� ��������",
                ORGANIZATION_SPORTS_TOURISM  =
                    "����������� ������������-��������������� "         \
                    "������ � �������",
                PRESCHOOL_PHYSICAL_EDUCATION =
                    "���������� ���������� ����������",
                DANCE_SPORT                  =
                    "������������ �����",
                AEROBICS                     =
                    "��������",
                ROWING_OTHER                 =
                    "������� �����",
                SWIMMING                     =
                    "��������",
                SAILING                      =
                    "�������� �����",
                ATHLETICS                    =
                    "������ ��������",
                CROSS_COUNTRY_SKIING         =
                    "������ �����",
                BULLET_SHOOTING_DEANERY      =
                    "������� ��������",
                HAND_TO_HAND_COMBAT          =
                    "���������� ���",
                TAEKWONDO                    =
                    "���������",
                KARATE                       =
                    "������",
                SKIING                       =
                    "������ �����",
                AUTOMOTIVE_SPORT             =
                    "������������� �����",
                BASKETBALL                   =
                    "���������",
                BOXING                       =
                    "����",
                GRECO_FREESTYLE_WRESTLING    =
                    "�����-������� � ������� ������",
                CYCLING                      =
                    "������������ �����",
                VOLLEYBALL                   =
                    "��������",
                HANDBALL                     =
                    "�������",
                EQUESTRIAN                   =
                    "������ �����",
                SPEED_SKATING                =
                    "������������ �����",
                TENNIS                       =
                    "������",
                WEIGHTLIFTING                =
                    "������� ��������",
                FENCING                      =
                    "����������",
                FIGURE_SKATING_OLD           =
                    "�������� �������",
                FOOTBALL                     =
                    "������",
                HOCKEY                       =
                    "������",
                SAMBO_JUDO                   =
                    "�����-�����",
                WRESTLING                    =
                    "���������� ������",
                FOOTBALL_HOCKEY              =
                    "������ � ������",
                BIATHLON                     =
                    "�������",
                HEALTH_IMPROVING             =
                    "��������������� ���������� ��������",
                ADAPTIVE                     =
                    "���������� ���������� ��������",
                FREESTYLE_WRESTLING          =
                    "������� ������",
                GRECO_ROMAN_WRESTLING        =
                    "�����-������� ������",
                SAMBO                        =
                    "�����",
                JUDO                         =
                    "�����",
                TABLE_TENNIS_ABITURIENT      =
                    "������ ����������",
                ERGOTHERAPY                  =
                    "�����������",
                MANAGEMENT_SPORTS            =
                    "���������� � ������",
                SPORTS_DIRECTING_DEANERY     =
                    "���������� ���������",
                SPORTS_RECREATIONAL_TOURISM  =
                    "���������� � ������������� ������",
                MANAGEMENT_TOURISM           =
                    "���������� � �������",
                SPORTS_PSYCHOLOGY            =
                    "���������� ����������",
                BILLIARD_SPORTS              =
                    "���������� �����",
                ACROBATICS                   =
                    "����������",
                ORIENTEERING                 =
                    "���������� ��������������",
                SPORTS_DIRECTING             =
                    "���������� ���������",
                PRESCHOOLERS                 =
                    "���������� �������� ������������",
                MOUNTAINEERING               =
                    "���������",
                SKI_COMBINED                 =
                    "������ ���������",
                TOURISM_HOSPITALITY          =
                    "������ � ��������������",
                WATER_TECHNICAL_SPORTS       =
                    "�����-����������� ���� ������",
                MODEL_TECHNICAL_SPORTS       =
                    "��������-����������� ���� ������",
                ALPINE_SKIING                =
                    "����������� �����",
                BASEBALL                     =
                    "�������",
                WUSHU                        =
                    "���",
                CHESS                        =
                    "�������",
                THAI_BOXING                  =
                    "����������� ����",
                TOURISM_PROMOTION            =
                    "���������� ������������ � ����������� "            \
                    "������������� �����",
                TOURISM_IT                   =
                    "�������������� ���������� ������������� "          \
                    "���������",
                TOURISM_LOGISTICS            =
                    "��������� � ������������� ���������",
                TOURISM_SOCIAL               =
                    "���������� ���������������� ������� "              \
                    "��������",
                TOURISM_TRANSPORT            =
                    "���������� ������������� ������� ��������",
                TOURISM_FOOD                 =
                    "���������� ������� ������� ��������",
                TOURIST_ACCOMMODATION        =
                    "���������� ������� ���������� ��������",
                TOURISM_EXCURSION            =
                    "���������� ������������-����������������� "        \
                    "������� ��������",
                TOURISM_HEALTH               =
                    "���������� ������� ������������ � ������� "        \
                    "��������",
                BULLET_SHOOTING              =
                    "�������� �������",
                FIELD_HOCKEY                 =
                    "������ �� �����",
                FIGURE_SKATING               =
                    "�������� ������� �� �������",
                ROWING_AND_CANOEING          =
                    "������ �� ��������� � �����",
                ACADEMIC_ROWING              =
                    "������ �������������",
                HAND_TO_HAND_COMBAT_MS       =
                    "���������� ��� (��������� ������������)",
                BILLIARDS_RPC                =
                    "�������",
                WITHOUT_SPECIALIZATION       =
                    "��� �������������",
                MEDICAL                      =
                    "���������� ��������(��������)",
                MODERN_PENTATHLON            =
                    "����������� ���������",
                SCIENCE_HEALTH               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                PHYSIOLOGY                   =
                    "����������",
                SCIENCE_THEORY               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                RECEARCH_SPORT               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                INNOVATIVE_TOURISM           =
                    "������������� ���������� � ����� �������",
                INNOVATIVE_HOSPITALITY       =
                    "������������� ���������� � ����� ��������������",
                INNOVATIVE_TECHNOLOGIES      =
                    "������������� ���������� � ����� ������� "         \
                    "� ��������������",
                INNOVATIVE_MANAGEMENT        =
                    "���������� �������������� ��������� � "            \
                    "���������� ���������",
                BILLIARDS_SMA                =
                    "�������",
                HAND_TO_HAND_COMBAT_SMA      =
                    "���������� ��� (��������� ������������)",
                BADMINTON                    =
                    "���������",
                TABLE_TENNIS_DEANERY         =
                    "���������� ������",
                PHYSICAL_CULTURE_SPORT       =
                    "���������� �������� � �����",
                TOURISM_HOSPITALITY_MASTER   =
                    "������ � ��������������",
                SPORT_CLIMBING               =
                    "������������ ����������",
                MASTER_ANTHROPOLOGY          =
                    "������������",
                MASTER_MANAGEMENT            =
                    "����������",
                MASTER_PHYSICAL_CULTURE      =
                    "���������� �������� � �����";

            namespace DATIVE_CASE
            {
                const AnsiString
                    GYMNASTICS                   =
                        "����������",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "����������� ������ � �������",
                    PHYSICAL_REHABILITATION      =
                        "���������� ������������",
                    THERAPEUTIC                  =
                        "�������� ���������� ��������",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "����������� ������������-��������������� "         \
                        "������ � �������",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "����������� ����������� ����������",
                    DANCE_SPORT                  =
                        "������������� ������",
                    AEROBICS                     =
                        "��������",
                    ROWING_OTHER                 =
                        "�������� ������",
                    SWIMMING                     =
                        "��������",
                    SAILING                      =
                        "��������� ������",
                    ATHLETICS                    =
                        "������ ��������",
                    CROSS_COUNTRY_SKIING         =
                        "������ ������",
                    BULLET_SHOOTING_DEANERY      =
                        "������� ��������",
                    HAND_TO_HAND_COMBAT          =
                        "����������� ���",
                    TAEKWONDO                    =
                        "���������",
                    KARATE                       =
                        "������",
                    SKIING                       =
                        "������� ������",
                    AUTOMOTIVE_SPORT             =
                        "�������������� ������",
                    BASKETBALL                   =
                        "����������",
                    BOXING                       =
                        "�����",
                    GRECO_FREESTYLE_WRESTLING    =
                        "�����-������� � ������� ������",
                    CYCLING                      =
                        "������������� ������",
                    VOLLEYBALL                   =
                        "���������",
                    HANDBALL                     =
                        "��������",
                    EQUESTRIAN                   =
                        "������� ������",
                    SPEED_SKATING                =
                        "������������� ������",
                    TENNIS                       =
                        "�������",
                    WEIGHTLIFTING                =
                        "������� ��������",
                    FENCING                      =
                        "����������",
                    FIGURE_SKATING_OLD           =
                        "��������� �������",
                    FOOTBALL                     =
                        "�������",
                    HOCKEY                       =
                        "������",
                    SAMBO_JUDO                   =
                        "�����-�����",
                    WRESTLING                    =
                        "���������� ������",
                    FOOTBALL_HOCKEY              =
                        "������� � ������",
                    BIATHLON                     =
                        "��������",
                    HEALTH_IMPROVING             =
                        "��������������� ���������� ��������",
                    ADAPTIVE                     =
                        "���������� ���������� ��������",
                    FREESTYLE_WRESTLING          =
                        "������� ������",
                    GRECO_ROMAN_WRESTLING        =
                        "�����-������� ������",
                    SAMBO                        =
                        "�����",
                    JUDO                         =
                        "�����",
                    TABLE_TENNIS_ABITURIENT      =
                        "������� �����������",
                    ERGOTHERAPY                  =
                        "�����������",
                    MANAGEMENT_SPORTS            =
                        "����������� � ������",
                    SPORTS_DIRECTING_DEANERY     =
                        "���������� ���������",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "����������� � �������������� �������",
                    MANAGEMENT_TOURISM           =
                        "����������� � �������",
                    SPORTS_PSYCHOLOGY            =
                        "���������� ����������",
                    BILLIARD_SPORTS              =
                        "����������� ������",
                    ACROBATICS                   =
                        "����������",
                    ORIENTEERING                 =
                        "����������� ��������������",
                    SPORTS_DIRECTING             =
                        "���������� ���������",
                    PRESCHOOLERS                 =
                        "���������� �������� ������������",
                    MOUNTAINEERING               =
                        "����������",
                    SKI_COMBINED                 =
                        "������� ���������",
                    TOURISM_HOSPITALITY          =
                        "������� � ��������������",
                    WATER_TECHNICAL_SPORTS       =
                        "�����-����������� ����� ������",
                    MODEL_TECHNICAL_SPORTS       =
                        "��������-����������� ����� ������",
                    ALPINE_SKIING                =
                        "������������ ������",
                    BASEBALL                     =
                        "��������",
                    WUSHU                        =
                        "���",
                    CHESS                        =
                        "��������",
                    THAI_BOXING                  =
                        "������������ �����",
                    TOURISM_PROMOTION            =
                        "����������� ������������ � ����������� "            \
                        "������������� �����",
                    TOURISM_IT                   =
                        "�������������� ����������� ������������� "          \
                        "���������",
                    TOURISM_LOGISTICS            =
                        "��������� � ������������� ���������",
                    TOURISM_SOCIAL               =
                        "����������� ���������������� ������� "              \
                        "��������",
                    TOURISM_TRANSPORT            =
                        "����������� ������������� ������� ��������",
                    TOURISM_FOOD                 =
                        "����������� ������� ������� ��������",
                    TOURIST_ACCOMMODATION        =
                        "����������� ������� ���������� ��������",
                    TOURISM_EXCURSION            =
                        "����������� ������������-����������������� "        \
                        "������� ��������",
                    TOURISM_HEALTH               =
                        "����������� ������� ������������ � ������� "        \
                        "��������",
                    BULLET_SHOOTING              =
                        "�������� �������",
                    FIELD_HOCKEY                 =
                        "������ �� �����",
                    FIGURE_SKATING               =
                        "��������� ������� �� �������",
                    ROWING_AND_CANOEING          =
                        "������ �� ��������� � �����",
                    ACADEMIC_ROWING              =
                        "������ �������������",
                    HAND_TO_HAND_COMBAT_MS       =
                        "����������� ��� (��������� ������������)",
                    BILLIARDS_RPC                =
                        "��������",
                    WITHOUT_SPECIALIZATION       =
                        "��� �������������",
                    MEDICAL                      =
                        "���������� �������� (��������)",
                    MODERN_PENTATHLON            =
                        "������������ ���������",
                    SCIENCE_HEALTH               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    PHYSIOLOGY                   =
                        "����������",
                    SCIENCE_THEORY               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    RECEARCH_SPORT               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    INNOVATIVE_TOURISM           =
                        "�������������� ����������� � ����� �������",
                    INNOVATIVE_HOSPITALITY       =
                        "�������������� ����������� � ����� ��������������",
                    INNOVATIVE_TECHNOLOGIES      =
                        "������������� ����������� � ����� ������� "         \
                        "� ��������������",
                    INNOVATIVE_MANAGEMENT        =
                        "���������� �������������� ��������� � "            \
                        "���������� ���������",
                    BILLIARDS_SMA                =
                        "��������",
                    HAND_TO_HAND_COMBAT_SMA      =
                        "����������� ��� (��������� ������������)",
                    BADMINTON                    =
                        "����������",
                    TABLE_TENNIS_DEANERY         =
                        "����������� �������",
                    PHYSICAL_CULTURE_SPORT       =
                        "���������� �������� � ������",
                    TOURISM_HOSPITALITY_MASTER   =
                        "������� � ��������������",
                    SPORT_CLIMBING               =
                        "����������� ������������",
                    MASTER_ANTHROPOLOGY          =
                        "������������",
                    MASTER_MANAGEMENT            =
                        "�����������",
                    MASTER_PHYSICAL_CULTURE      =
                        "���������� �������� � ������";
            }
        }
        namespace SportsRanks
        {
            const AnsiString
                INTERNATIONAL_MASTER_OF_SPORTS =                                        // (IMS)
                    "������ ������ �������������� ������ (����)",
                HONORED_MASTER_OF_SPORTS       = "����������� ������ ������ (���)",     // (HMS)
                MASTER_OF_SPORT                = "������ ������ (��)",                  // (MS)
                CANDIDATE_IN_MASTERS_OF_SPORT  = "�������� � ������� ������ (���)",     // (CMS)
                FIRST_SPORT_CATEGORY           = "I ���������� ������ (I ������)",      // (FSC)
                SECOND_SPORT_CATEGORY          = "II ���������� ������ (II ������)",    // (SSC)
                THIRD_SPORT_CATEGORY           = "III ���������� ������ (III ������)",  // (TSC)
                FIRST_YOUTH_CATEGORY           = "I ��������� ������ (I ���������)",    // (FYC)
                SECOND_YOUTH_CATEGORY          = "II ��������� ������ (II ���������)",  // (SYC)
                FIRST_APPRENTICESHIP_DEGREE    = "1-� ����������� ������� (1 ��)",      // (FAD)
                SECOND_APPRENTICESHIP_DEGREE   = "2-� ����������� ������� (2 ��)",      // (SAD)
                THIRD_APPRENTICESHIP_DEGREE    = "3-� ����������� ������� (3 ��)",      // (TAD)
                WITHOUT                        = "���";                                 // (NO)

            namespace ABBR
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS = "����",
                    HONORED_MASTER_OF_SPORTS       = "���",
                    MASTER_OF_SPORT                = "��",
                    CANDIDATE_IN_MASTERS_OF_SPORT  = "���",
                    FIRST_SPORT_CATEGORY           = "I ������",
                    SECOND_SPORT_CATEGORY          = "II ������",
                    THIRD_SPORT_CATEGORY           = "III ������",
                    FIRST_YOUTH_CATEGORY           = "I ���������",
                    SECOND_YOUTH_CATEGORY          = "II ���������",
                    FIRST_APPRENTICESHIP_DEGREE    = "1 ��",
                    SECOND_APPRENTICESHIP_DEGREE   = "2 ��",
                    THIRD_APPRENTICESHIP_DEGREE    = "3 ��",
                    WITHOUT                        = "���";
            }
        }
        namespace StudyPeriod
        {
            namespace HIGH
            {
                const AnsiString
                    NAME           = "������ �����������",
                    FULL           = "������ ����",                                     // t_abitur_queue.term_edu = 0
                    FIRST_COURSE   = "������ ����������� (1 ����)",                     // t_abitur_queue.term_edu = 3
                    SECOND_COURSE  = "������ ����������� (2 ����)",                     // t_abitur_queue.term_edu = 4
                    THIRD_COURSE   = "������ ����������� (3 ����)";                     // t_abitur_queue.term_edu = 5
            }
            namespace SHORT
            {
                const AnsiString
                    NAME          = "C���������� ����",
                    SECOND_COURSE = "C���������� ���� (2 ����)",                        // t_abitur_queue.term_edu = 1
                    THIRD_COURSE  = "C���������� ���� (3 ����)";                        // t_abitur_queue.term_edu = 2
            }
        }
    #else
        namespace Admissions
        {
            namespace TIME
            {
                const AnsiString
                    YEAR                 =
                        (Now ())
                            .FormatString (
                                "yyyy"
                            );
            }
            namespace INVENTORY
            {
                const AnsiString
                    #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                    DATE                 =
                        "01.06.2023";
                    #else
                    DATE                 =
                        (Now ())
                            .FormatString (
                                "dd.mm.yyyy"
                            );
                    #endif  // SET_INVENTORY_DATE_BY_HAND
            }
            namespace DEADLINE
            {
                const AnsiString
                    FOR_RECEIVING_PART_1 =
                        "05.06."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00",
                    FOR_RECEIVING_PART_2 =
                        "10.08."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00";
            }
            namespace ADDITIONAL
            {
                const AnsiString
                    ORDER_DATE_PART_1    =
                        "04.06."                    +
                            Admissions::TIME::YEAR,
                    ORDER_DATE_PART_2    =
                        "08.08."                    +
                            Admissions::TIME::YEAR;
            }
            namespace DOCUMENTS
            {
                const AnsiString
                    PROVIDE_DATE =
                        "15.06."                    +
                            Admissions::TIME::YEAR;
            }
            namespace ARRIVAL
            {
                namespace TIME
                {
                    const AnsiString
                        EVERYONE = "9:00";
                }
                namespace DATE
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            ALL =
                                "01.09."                    +
                                    Admissions::TIME::YEAR;
                    }
                    namespace EXTRAMURAL
                    {
                        namespace FULL
                        {
                            const AnsiString
                                MSTH  =
                                    "05.09."                    +
                                        Admissions::TIME::YEAR,
                                OTHER =
                                    "12.09."                    +
                                        Admissions::TIME::YEAR;
                        }
                        namespace SHORT
                        {
                            const AnsiString
                                SMA   =
                                    "03.10."                    +
                                        Admissions::TIME::YEAR,
                                MS    =
                                    "05.10."                    +
                                        Admissions::TIME::YEAR,
                                RPC   =
                                    "07.10."                    +
                                        Admissions::TIME::YEAR,
                                MSTH  =
                                    "24.10."                    +
                                        Admissions::TIME::YEAR;
                        }
                    }
                }
            }
        }
        namespace ContestType
        {
            const AnsiString
                GENERAL                = "�����",
                WITHOUT_ENTRANCE_EXAMS = "��� ������������� ���������",
                OUT_OF_COMPETITION     = "��� ��������",
                TARGETED_TRAINING      = "�������";
        }
        namespace Contract
        {
            namespace DOCUMENT_FILE
            {
                const AnsiString
                    BUDGET  = "������� - ������.xls",
                    BUYERS  = "������� - ��������.xls";
            }
            namespace DOCUMENT_NAME
            {
                const AnsiString
                    BUDGET = "������� - ������",
                    BUYERS = "������� - ��������";
            }
            namespace BSUPC
            {
                const AnsiString
                    PERSON = "������� ��������� �������������";                         // Old name: CONTRACT_SIDE_BSUPC_MAIN

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "������������",                                        // Old name: CONTRACT_TYPE_POWER_DOC_MAIN
                        DATE   = "16.11.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_MAIN
                        NUMBER = "13-16-45";                                            // Old name: CONTRACT_POWER_DOC_NO_MAIN
                }
            }
            namespace IMS
            {
                const AnsiString
                    PERSON = "���������� ����� ����������";                             // Old name: CONTRACT_SIDE_BSUPC_IMST

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "������������",                                        // Old name: CONTRACT_TYPE_POWER_DOC_IMST
                        DATE   = "26.10.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_IMST
                        NUMBER = "13-16-42";                                            // Old name: CONTRACT_POWER_DOC_NO_IMST
                }
            }
            namespace PAYMENT_TERM
            {
                const AnsiString
                    FIRST_SEMESTER  =
                        "�� 31.08."                                 +
                            Admissions::TIME::YEAR                  +
                        " (������������) � �� ������ "              \
                        "������� ������� ���� �������� � �������",
                    SECOND_SEMESTER =
                        "� 01.02."                                  +
                            AnsiString (
                                    StrToInt (
                                        Admissions::TIME::YEAR
                                    )
                                +   Default::STEP
                            )                                       +
                        " �� 01.03."                                +
                            AnsiString (
                                    StrToInt (
                                        Admissions::TIME::YEAR
                                    )
                                +   Default::STEP
                            )                                       +
                        " � �� ������ ������� ������� ���� "        \
                        "�������� � �������";
            }
            namespace COST_FOR
            {
                namespace BUDGET
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // ������, �������, ������ ����
                                "���������� ���������� �������� "               \
                                "���������� 32830,32 ("                         \
                                "�������� ��� ������ ��������� �������� "       \
                                "������ 32 �������) ����������� ������.",
                            SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                                "���������� ���������� �������� "               \
                                "���������� 24622,74 ("                         \
                                "�������� ������ ������ �������� �������� ��� " \
                                "����� 74 �������) ����������� ������.";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // ������, �������, ������ ����
                                "���������� ���������� �������� "               \
                                "���������� 16415,15 ("                         \
                                "����������� ����� ��������� ���������� "       \
                                "������ 15 ������) ����������� ������.",
                            SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                                "���������� ���������� �������� "               \
                                "���������� 13132,12 ("                         \
                                "���������� ����� ��� �������� ��� "            \
                                "����� 12 ������) ����������� ������.",
                            THIRD_COURSE  =                                             // ������, �������, �����٨���� ���� (3 ����)
                                "���������� ���������� �������� "               \
                                "���������� 9849,09 ("                          \
                                "������ ����� ��������� ����� ������ "          \
                                "������ 09 ������) ����������� ������.";
                    }
                }
                namespace BUYERS
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString                                                // ��������, �������, �� ���
                            ANNUAL       =
                                "���������� 2748 ("                             \
                                "��� ������ ������� ����� ������"               \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            PER_SEMESTER =                                              // ��������, �������, �� ���������
                                "1374 ("                                        \
                                "���� ������ ������ ��������� ������"           \
                                ") ����������� ������;";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            ANNUAL           =                                          // ��������, �������, �� ��� (����, ���, ���)
                                "���������� 1065 ("                             \
                                "���� ������ ���������� ����"                   \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            ANNUAL_IMS       =                                          // ��������, �������, �� ��� (�����)
                                "���������� 1135 ("                             \
                                "���� ������ ��� �������� ����"                 \
                                ") ����������� ������ "                         \
                                "�� ������ ��� ��������.",
                            PER_SEMESTER     =                                          // ��������, �������, �� ��������� (����, ���, ���)
                                "532,50 ("                                      \
                                "������� �������� ��� "                         \
                                "����� 50 ������) ����������� ������;",
                            PER_SEMESTER_IMS =                                          // ��������, �������, �� ��������� (�����)
                                "567,50 ("                                      \
                                "������� ���������� ���� "                      \
                                "������ 50 ������) ����������� ������;";
                    }
                }
            }
        }
        #ifndef NEW_DOCUMENTS_NAMESPACES
            namespace DocumentFile
            {
                namespace APPLICATION_FOR
                {
                    const AnsiString
                        PARTICIPATION       = "��������� - ������ � �������.xls";
                }
                namespace LIST
                {
                    const AnsiString
                        GROUPS              = "������ - �����.xls";                         // NEW (������.xls -> ������ - �����.xls)
                }
                namespace PROTOCOL
                {
                    AnsiString
                        admitted            = "�������� - � ������� ������������.doc",      // NEW (OLE Issue) DELETE YEAR
                        daily               = "�������� - ����������.xls",
                        exam                = "�������� - ������� �� ����.xls";
                    const AnsiString
                        GIRLS_TESTS         = "�������� - ��������� (�������).xls";
                }
                namespace REGISTRY
                {
                    const AnsiString
                        BOOK                = "������ - �����������.xls";
                }
                namespace REPORT
                {
                    const AnsiString
                        FORM_1              = "����� - ����� 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                        FORM_2              = "����� - ����� 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                        SUBMITTED           = "����� - ������ ���������.xls";
                }
                namespace STATISTIC
                {
                    AnsiString
                        cert_result_hundred =
                            "���������� - ���������� ������������ (�����������).xls",
                        cert_result_ten     =
                            "���������� - ���������� ������������ (��������������).xls",    // (REQUIRE CHECK Range)
                        exam_result         =
                            "���������� - ���������� ����� ���������.xls";
                    const AnsiString
                        ADMISSION_PROGRESS  =
                            "���������� - ��� ������.xls",
                        CONTEST             =
                            "���������� - �������.xls",                                     // NEW DELETE YEAR
                        DAILY               =
                            "���������� - ����������.xls",
                        LEVEL_OF_SPORTS     =
                            "���������� - ������� ���������� ����������.xls",
                        SCORES              =
                            "���������� - �����.xls";                                       // NOTE: INSTEAD USEING Abitur_RIO
                }
                namespace SUMMARY_LIST
                {
                    const AnsiString
                        ENROLLMENT          = "��������� - ����������.xls",
                        ENTRANCE_EXAMS      = "��������� - ������������� ���������.xls";    // NEW DELETE YEAR
                }
            }
            namespace DocumentName
            {
                namespace APPLICATION_FOR
                {
                    const AnsiString
                        PARTICIPATION      = "��������� - ������ � �������";
                }
                namespace LIST
                {
                    const AnsiString
                        GROUPS             = "������ - �����",                              // NEW (������ -> ������ - �����)
                        BY_DESTINATIONS    = "������ - �� ������������",
                        BY_GENDER          = "������ - �� ����";
                }
                namespace PROTOCOL
                {
                    AnsiString
                        daily              = "�������� - ����������",
                        exam               = "�������� - ������� �� ����";
                    const AnsiString
                        GIRLS_TESTS        = "�������� - ��������� (�������)";
                }
                namespace REGISTRY
                {
                    const AnsiString
                        BOOK               = "������ - �����������";
                }
                namespace REPORT
                {
                    const AnsiString
                        FORM_1             = "����� - ����� 1",
                        FORM_2             = "����� - ����� 2",
                        SUBMITTED          = "����� - ������ ���������";                    // (REQUIRE CHECK Calcalation)
                }
                namespace STATISTIC
                {
                    const AnsiString
                        ADMISSION_PROGRESS =
                            "���������� - ��� ������",
                        CONTEST            =
                            "���������� - �������",
                        DAILY              =
                            "���������� - ����������",
                        LEVEL_OF_SPORTS    =
                            "���������� - ������� ���������� ����������",
                        SCORES             =
                            "���������� - �����";                                           // INSTEAD USEING Abitur_RIO
                }
                namespace SUMMARY_LIST
                {
                    const AnsiString
                        ENROLLMENT         = "��������� - ����������",
                        ENTRANCE_EXAMS     = "��������� - ������������� ���������";
                }
            }
        #else
            // Document::EXTENSION::EXCEL
            // Document::EXTENSION::WORD

            // Document::NAME::APPLICATION_FOR::PARTICIPATION
            // Document::NAME::LIST::BY_DESTINATIONS
            // Document::NAME::LIST::BY_GENDER
            // Document::NAME::LIST::GROUPS
            // Document::NAME::PROTOCOL::ADMITTED
            // Document::NAME::PROTOCOL::DAILY
            // Document::NAME::PROTOCOL::EXAM
            // Document::NAME::PROTOCOL::GIRLS_TESTS
            // Document::NAME::REGISTRY::BOOK
            // Document::NAME::REPORT::FORM_1
            // Document::NAME::REPORT::FORM_2
            // Document::NAME::REPORT::SUBMITTED
            // Document::NAME::STATISTIC::ADMISSION_PROGRESS
            // Document::NAME::STATISTIC::CERT_RESULT_HUNDRED
            // Document::NAME::STATISTIC::CERT_RESULT_TEN
            // Document::NAME::STATISTIC::CONTEST
            // Document::NAME::STATISTIC::DAILY
            // Document::NAME::STATISTIC::EXAM_RESULT
            // Document::NAME::STATISTIC::LEVEL_OF_SPORTS
            // Document::NAME::STATISTIC::SCORES
            // Document::NAME::SUMMARY_LIST::ENROLLMENT
            // Document::NAME::SUMMARY_LIST::ENTRANCE_EXAMS

            // Document::FILE::APPLICATION_FOR::PARTICIPATION
            // Document::FILE::LIST::BY_DESTINATIONS
            // Document::FILE::LIST::BY_GENDER
            // Document::FILE::LIST::GROUPS
            // Document::FILE::PROTOCOL::ADMITTED
            // Document::FILE::PROTOCOL::DAILY
            // Document::FILE::PROTOCOL::EXAM
            // Document::FILE::PROTOCOL::GIRLS_TESTS
            // Document::FILE::REGISTRY::BOOK
            // Document::FILE::REPORT::FORM_1
            // Document::FILE::REPORT::FORM_2
            // Document::FILE::REPORT::SUBMITTED
            // Document::FILE::STATISTIC::ADMISSION_PROGRESS
            // Document::FILE::STATISTIC::CERT_RESULT_HUNDRED
            // Document::FILE::STATISTIC::CERT_RESULT_TEN
            // Document::FILE::STATISTIC::CONTEST
            // Document::FILE::STATISTIC::DAILY
            // Document::FILE::STATISTIC::EXAM_RESULT
            // Document::FILE::STATISTIC::LEVEL_OF_SPORTS
            // Document::FILE::STATISTIC::SCORES
            // Document::FILE::SUMMARY_LIST::ENROLLMENT
            // Document::FILE::SUMMARY_LIST::ENTRANCE_EXAMS
            namespace Document
            {
                namespace EXTENSION
                {
                    const AnsiString
                        EXCEL = ".xls",
                        WORD  = ".doc";
                }
                namespace NAME
                {
                    namespace APPLICATION_FOR
                    {
                        const AnsiString
                            PARTICIPATION        =
                                "��������� - ������ � �������";
                    }
                    namespace LIST
                    {
                        const AnsiString
                            BY_DESTINATIONS      =
                                "������ - �� ������������",
                            BY_GENDER            =
                                "������ - �� ����",
                            GROUPS               =                                          // NEW (������ -> ������ - �����)
                                "������ - �����";
                    }
                    namespace PROTOCOL
                    {
                        const AnsiString
                            ADMITTED             =
                                "�������� - � ������� ������������",                        // NEW (OLE Issue) DELETE YEAR
                            DAILY                =
                                "�������� - ����������",
                            EXAM                 =
                                "�������� - ������� �� ����",
                            GIRLS_TESTS          =
                                "�������� - ��������� (�������)";
                    }
                    namespace REGISTRY
                    {
                        const AnsiString
                            BOOK                 =
                                "������ - �����������";
                    }
                    namespace REPORT
                    {
                        const AnsiString
                            FORM_1               =
                                "����� - ����� 1",
                            FORM_2               =
                                "����� - ����� 2",
                            SUBMITTED            =
                                "����� - ������ ���������";                                 // (REQUIRE CHECK Calcalation)
                    }
                    namespace STATISTIC
                    {
                        const AnsiString
                            ADMISSION_PROGRESS   =
                                "���������� - ��� ������",
                            CERT_RESULT_HUNDRED  =
                                "���������� - ���������� ������������ (�����������)",
                            CERT_RESULT_TEN      =
                                "���������� - ���������� ������������ (��������������)",    // (REQUIRE CHECK Range)
                            CONTEST              =
                                "���������� - �������",
                            DAILY                =
                                "���������� - ����������",
                            EXAM_RESULT          =
                                "���������� - ���������� ����� ���������",
                            LEVEL_OF_SPORTS      =
                                "���������� - ������� ���������� ����������",
                            SCORES               =
                                "���������� - �����";                                       // INSTEAD USEING Abitur_RIO
                    }
                    namespace SUMMARY_LIST
                    {
                        const AnsiString
                            ENROLLMENT           =
                                "��������� - ����������",
                            ENTRANCE_EXAMS       =
                                "��������� - ������������� ���������";
                    }
                }
                namespace FILE
                {
                    namespace APPLICATION_FOR
                    {
                        const AnsiString
                            PARTICIPATION       =
                                Document::NAME::APPLICATION_FOR::PARTICIPATION    +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace LIST
                    {
                        const AnsiString
                            BY_DESTINATIONS     =
                                Document::NAME::LIST::BY_DESTINATIONS             +
                                Document::EXTENSION::EXCEL,
                            BY_GENDER           =
                                Document::NAME::LIST::BY_GENDER                   +
                                Document::EXTENSION::EXCEL,
                            GROUPS              =
                                Document::NAME::LIST::GROUPS                      +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace PROTOCOL
                    {
                        const AnsiString
                            ADMITTED            =
                                Document::NAME::PROTOCOL::ADMITTED                +
                                Document::EXTENSION::EXCEL,
                            DAILY               =
                                Document::NAME::PROTOCOL::DAILY                   +
                                Document::EXTENSION::EXCEL,
                            EXAM                =
                                Document::NAME::PROTOCOL::EXAM                    +
                                Document::EXTENSION::EXCEL,
                            GIRLS_TESTS         =
                                Document::NAME::PROTOCOL::GIRLS_TESTS             +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace REGISTRY
                    {
                        const AnsiString
                            BOOK                =
                                Document::NAME::REGISTRY::BOOK                    +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace REPORT
                    {
                        const AnsiString
                            FORM_1              =
                                Document::NAME::REPORT::FORM_1                    +
                                Document::EXTENSION::EXCEL,
                            FORM_2              =
                                Document::NAME::REPORT::FORM_2                    +
                                Document::EXTENSION::EXCEL,
                            SUBMITTED           =
                                Document::NAME::REPORT::SUBMITTED                 +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace STATISTIC
                    {
                        const AnsiString
                            ADMISSION_PROGRESS  =
                                Document::NAME::STATISTIC::ADMISSION_PROGRESS     +
                                Document::EXTENSION::EXCEL,
                            CERT_RESULT_HUNDRED =
                                Document::NAME::STATISTIC::CERT_RESULT_HUNDRED    +
                                Document::EXTENSION::EXCEL,
                            CERT_RESULT_TEN     =
                                Document::NAME::STATISTIC::CERT_RESULT_TEN        +
                                Document::EXTENSION::EXCEL,
                            CONTEST             =
                                Document::NAME::STATISTIC::CONTEST                +
                                Document::EXTENSION::EXCEL,
                            DAILY               =
                                Document::NAME::STATISTIC::DAILY                  +
                                Document::EXTENSION::EXCEL,
                            EXAM_RESULT         =
                                Document::NAME::STATISTIC::EXAM_RESULT            +
                                Document::EXTENSION::EXCEL,
                            LEVEL_OF_SPORTS     =
                                Document::NAME::STATISTIC::LEVEL_OF_SPORTS        +
                                Document::EXTENSION::EXCEL,
                            SCORES              =
                                Document::NAME::STATISTIC::SCORES                 +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace SUMMARY_LIST
                    {
                        const AnsiString
                            ENROLLMENT          =
                                Document::NAME::SUMMARY_LIST::ENROLLMENT          +
                                Document::EXTENSION::EXCEL,
                            ENTRANCE_EXAMS      =
                                Document::NAME::SUMMARY_LIST::ENTRANCE_EXAMS      +
                                Document::EXTENSION::EXCEL;
                    }
                }
            }
        #endif  // ! NEW_DOCUMENTS_NAMESPACES
        namespace EducationType
        {
            const AnsiString
                EXTRAMURAL = "�������",
                INTRAMURAL = "�������",
                EXTRA_FORM = "�������",
                INTRA_FORM = "�������";
        }
        namespace EnvelopeMessage
        {
            namespace BUDGET
            {
                const AnsiString
                    EXTRAMURAL = "������, ������� ����� ��������",
                    INTRAMURAL = "������, ������� ����� ��������";
            }
            namespace BUYERS
            {
                const AnsiString
                    EXTRAMURAL = "�� ������, ������� ����� ��������",
                    INTRAMURAL = "�� ������, ������� ����� ��������";
            }
        }
        namespace Faculty
        {
            namespace SHORT
            {
                const AnsiString
                    SMA  = "����",                                                      // 1, -> Sports and Marital Arts (����)
                    MS   = "���",                                                       // 2, -> Mass Sports (���)
                    RPC  = "���",                                                       // 3, -> Recreational Physical Culture (�����)
                    MSTH = "�����",                                                     // 4, -> Management of Sports, Tourism and Hospitality (����)
                    MD   = "�����������",                                               // 5, -> Master's Degree (�����������)
                    PGS  = "�����������",                                               // 6, -> PostGraduate Studies (�����������)
                    DOC  = "������������";                                              // 7  -> DOCtorate (������������)
            }
            namespace NAME
            {
                const AnsiString
                    SMA  =                                                              // 1, -> Sports and Marital Arts (����)
                        "���������-�������������� ��������� "   \
                        "���������� ��� � �����������",
                    MS   =                                                              // 2, -> Mass Sports (���)
                        "���������-�������������� ��������� "   \
                        "�������� ����� ������",
                    RPC  =                                                              // 3, -> Recreational Physical Culture (�����)
                        "��������� ��������������� "            \
                        "���������� ��������",
                    MSTH =                                                              // 4, -> Management of Sports, Tourism and Hospitality (����)
                        "��������� ����������� ������, "        \
                        "������� � ��������������",
                    MD   =                                                              // 5, -> Master's Degree (�����������)
                        "�����������",
                    PGS  =                                                              // 6, -> PostGraduate Studies (�����������)
                        "�����������",
                    DOC  =                                                              // 7  -> DOCtorate (������������)
                        "������������";
            }
        }
        namespace LegallyAuthorizedPerson
        {
            const AnsiString
                DEAN_FACULTY_1 = "�.�.��������",                                        // ����  (SMA)  - Sports and Marital Arts
                DEAN_FACULTY_2 = "�.�.����������",                                      // ���   (MS)   - Mass Sports
                DEAN_FACULTY_3 = "�.�.���������",                                       // ����� (RPC)  - Recreational Physical Culture
                DEAN_FACULTY_4 = "�.�.���������",                                       // ����  (MSTH) - Management of Sports, Tourism and Hospitality
                EDU_HEAD_DESC  = "�������� �.�.",
                SECRETARY      = "�.�. �����",
                SECRETARY_DESC = "����� �.�.",
                VICE_RECTOR    = "�.�.������";
        }
        namespace PathTo
        {
            const AnsiString
                OUTPUT_DOCUMENTS       = "D:\\��������� �������� ��������",
                OUTPUT_DOCUMENTS_SLASH = "D:\\��������� �������� ��������\\";
        }
        namespace Payment
        {
            const AnsiString
                BUDGET = "������",
                BUYERS = "�������";
        }
        namespace SportsRanks
        {
            namespace ABBR
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS = "����",
                    HONORED_MASTER_OF_SPORTS       = "���",
                    MASTER_OF_SPORT                = "��",
                    CANDIDATE_IN_MASTERS_OF_SPORT  = "���",
                    FIRST_SPORT_CATEGORY           = "I ������",
                    SECOND_SPORT_CATEGORY          = "II ������",
                    THIRD_SPORT_CATEGORY           = "III ������",
                    FIRST_YOUTH_CATEGORY           = "I ���������",
                    SECOND_YOUTH_CATEGORY          = "II ���������",
                    FIRST_APPRENTICESHIP_DEGREE    = "1 ��",
                    SECOND_APPRENTICESHIP_DEGREE   = "2 ��",
                    THIRD_APPRENTICESHIP_DEGREE    = "3 ��",
                    WITHOUT                        = "���";
            }
            namespace NAME
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS =                                    // (IMS)
                        "������ ������ �������������� ������ (����)",
                    HONORED_MASTER_OF_SPORTS       =                                    // (HMS)
                        "����������� ������ ������ (���)",
                    MASTER_OF_SPORT                =                                    // (MS)
                        "������ ������ (��)",
                    CANDIDATE_IN_MASTERS_OF_SPORT  =                                    // (CMS)
                        "�������� � ������� ������ (���)",
                    FIRST_SPORT_CATEGORY           =                                    // (FSC)
                        "I ���������� ������ (I ������)",
                    SECOND_SPORT_CATEGORY          =                                    // (SSC)
                        "II ���������� ������ (II ������)",
                    THIRD_SPORT_CATEGORY           =                                    // (TSC)
                        "III ���������� ������ (III ������)",
                    FIRST_YOUTH_CATEGORY           =                                    // (FYC)
                        "I ��������� ������ (I ���������)",
                    SECOND_YOUTH_CATEGORY          =                                    // (SYC)
                        "II ��������� ������ (II ���������)",
                    FIRST_APPRENTICESHIP_DEGREE    =                                    // (FAD)
                        "1-� ����������� ������� (1 ��)",
                    SECOND_APPRENTICESHIP_DEGREE   =                                    // (SAD)
                        "2-� ����������� ������� (2 ��)",
                    THIRD_APPRENTICESHIP_DEGREE    =                                    // (TAD)
                        "3-� ����������� ������� (3 ��)",
                    WITHOUT                        =                                    // (NO)
                        "���";
            }
        }
        namespace StudyPeriod
        {
            namespace HIGH
            {
                const AnsiString
                    NAME           = "������ �����������",
                    FULL           = "������ ����",                                     // t_abitur_queue.term_edu = 0
                    FIRST_COURSE   = "������ ����������� (1 ����)",                     // t_abitur_queue.term_edu = 3
                    SECOND_COURSE  = "������ ����������� (2 ����)",                     // t_abitur_queue.term_edu = 4
                    THIRD_COURSE   = "������ ����������� (3 ����)";                     // t_abitur_queue.term_edu = 5
            }
            namespace SHORT
            {
                const AnsiString
                    NAME          = "C���������� ����",
                    SECOND_COURSE = "C���������� ���� (2 ����)",                        // t_abitur_queue.term_edu = 1
                    THIRD_COURSE  = "C���������� ���� (3 ����)";                        // t_abitur_queue.term_edu = 2
            }
        }
        #ifndef DATABASE_SUBSTITUTE
            namespace DeaneryDB
            {
                namespace QUALIFICATION
                {
                    const AnsiString
                        TEACHER_PHYSICAL_CULTURE_SPORTS  =
                            "������������� ���������� �������� � ������",
                        COACHING_BY_SPORT                =
                            "������ �� ���� ������",
                        PHYSICAL_EDUCATION_TEACHER       =
                            "������� ���������� ��������",
                        TEACHER_ORGANIZER_HEALTH_TOURISM =
                            "�������-����������� ������������-��������������� "     \
                            "������ � �������",
                        TEACHER_ORGANIZER_PRESCHOOLERS   =
                            "�������-����������� ����������� ���������� � "         \
                            "���������� �����������",
                        MANAGER_SPORT_TOURISM            =
                            "�������� ������ � �������",
                        INSTRUCTOR_REHABILITATION        =
                            "����������-�������� ���������� ������������",
                        INSTRUCTOR_MEDICAL               =
                            "����������-�������� �������� ���������� ��������",
                        TEACHER_PHYSICAL_CULTURE         =
                            "������������� ���������� ��������",
                        INSTRUCTOR_BY_HEALTH             =
                            "����������-�������� �� ��������������� ���������� "    \
                            "��������",
                        INSTRUCTOR_BY_ADAPTIVE           =
                            "����������-�������� �� ���������� ���������� "         \
                            "��������",
                        INSTRUCTOR_PRESCHOOLERS          =
                            "����������-�������� ����������� ���������� � "         \
                            "���������� �����������",
                        PSYCHOLOGIST                     =
                            "��������",
                        MANAGER_SPORT                    =
                            "�������� � ������",
                        MANAGER_TUORISM                  =
                            "�������� �� �������",
                        INSTRUCTOR_RECREATIONAL          =
                            "����������-�������� �� �������",
                        MANAGER_DIRECTING                =
                            "��������-�������� ���������-�������� �����������",
                        INSTRUCTOR_BY_MEDICAL            =
                            "����������-�������� �� �������� ���������� ��������",
                        INSTRUCTOR_BY_REHABILITATION     =
                            "����������-�������� �� ���������� ������������",
                        INSTRUCTOR_BY_ERGOTHERAPY        =
                            "����������-�������� �� �����������",
                        SPECIALIST_TOURISM_HOSPITALITY   =
                            "���������� � ����� ������� � ��������������";
                }
            }
            namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
            {
                namespace _2009
                {
                    namespace CODE
                    {
                        namespace PART
                        {
                            const AnsiString
                                BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                                PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                                PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                                COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                                PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                                TOURISM_HOSPITALITY            = "1-89";
                        }
                        namespace CHAPTER
                        {
                            const AnsiString
                                PHYSIOLOGY                     = "03.03.01",                // Master degree
                                THEORY_IMPROVING               = "13.00.04",                // Master degree
                                RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                                MANAGEMENT                     = "1-26 80",                 // Master degree
                                PHYSICAL_CULTURE               = "1-88 01",
                                SPORT                          = "1-88 02",
                                TOURISM_HOSPITALITY            = "1-89 01",
                                TOURISM                        = "1-89 02",
                                HOSPITALITY                    = "1-89 03",
                                RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                                INNOVATION                     = "1-89 81";                 // Master degree
                        }
                        namespace SECTION
                        {
                            const AnsiString
                                RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                                RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                                PHYSICAL_CULTURE               = "1-88 01 01",
                                IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                                REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                                TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                                SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                                SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                                TOURISM_HOSPITALITY            = "1-89 01 01",
                                SPORTS_AND_TOURISM             = "1-89 02 01",
                                TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                                HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                                RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                                INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                                INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                                INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                                INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                        }
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL                       = "1-88 01 01-01",
                                PRESCHOOLERS                  = "1-88 01 01-02",
                                HEALTH                        = "1-88 01 02-01",
                                ADAPTIVE                      = "1-88 01 02-02",
                                REHABILITATION                = "1-88 01 03-01",
                                ERGOTHERAPY                   = "1-88 01 03-02",
                                COACHING                      = "1-88 02 01-01",
                                MANAGEMENT                    = "1-88 02 01-02",
                                PSYCHOLOGY                    = "1-88 02 01-03",
                                DIRECTING                     = "1-88 02 01-04",
                                PROMOTION                     = "1-89 01 01 01",
                                IT                            = "1-89 01 01 02",
                                LOGISTICS                     = "1-89 01 01 03",
                                SOCIAL                        = "1-89 01 01 04",
                                TRANSPORT                     = "1-89 01 01 05",
                                CATERING                      = "1-89 01 01 06",
                                ACCOMMODATION                 = "1-89 01 01 07",
                                SUPPORTING                    = "1-89 01 01 08",
                                TREATMENT                     = "1-89 01 01 09",
                                RECREATIONAL                  = "1-89 02 01-01",
                                TUORISM_MNG                   = "1-89 02 01-02",
                                RESTAURANTS                   = "1-89 03 01-01";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  = "03.03.01",
                                    THEORY      = "13.00.04";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       = "1-08 80 04",
                                    MANAGEMENT  = "1-26 80 04",
                                    TOURISM     = "1-89 80 01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  = "1-89 81 01",
                                    TOURISM     = "1-89 81 02",
                                    HOSPITALITY = "1-89 81 03",
                                    TECHNO      = "1-89 81 04";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL      = "1-88 01 01-01",
                                PRESCHOOLERS = "1-88 01 01-02";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH   = "1-88 01 02-01",
                                ADAPTIVE = "1-88 01 02-02";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION = "1-88 01 03-01",
                                ERGOTHERAPY    = "1-88 01 03-02";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING = "1-88 01 04";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING   = "1-88 02 01-01",
                                MANAGEMENT = "1-88 02 01-02",
                                PSYCHOLOGY = "1-88 02 01-03",
                                DIRECTING  = "1-88 02 01-04";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION     = "1-89 01 01 01",
                                IT            = "1-89 01 01 02",
                                LOGISTICS     = "1-89 01 01 03",
                                SOCIAL        = "1-89 01 01 04",
                                TRANSPORT     = "1-89 01 01 05",
                                CATERING      = "1-89 01 01 06",
                                ACCOMMODATION = "1-89 01 01 07",
                                SUPPORTING    = "1-89 01 01 08",
                                TREATMENT     = "1-89 01 01 09";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL = "1-89 02 01-01",
                                TUORISM_MNG  = "1-89 02 01-02";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS = "1-89 03 01-01";
                        }
                    }
                    namespace NAME
                    {
                        namespace PART
                        {
                            const AnsiString
                                BIOLOGICAL_SCIENCES        =                                // Master degree
                                    "������������� �����",
                                PEDAGOGICAL_SCIENCES       =                                // Master degree
                                    "�������������� �����",
                                PEDAGOGY_PROFESSIONAL      =                                // Master degree
                                    "����������. ���������������� �����������",
                                COMMUNICATION_SCIENCES     =                                // Master degree
                                    "����������",
                                PHYSICAL_CULTURE_AND_SPORT =
                                    "���������� �������� � �����",
                                TOURISM_HOSPITALITY        =
                                    "������. ��������������";
                        }
                        namespace CHAPTER
                        {
                            const AnsiString
                                PHYSIOLOGY               =                                  // Master degree
                                    "����������",
                                THEORY_IMPROVING         =                                  // Master degree
                                    "������ � �������� ����������� ����������, "        \
                                    "���������� ����������, ��������������� � "         \
                                    "���������� ���������� ��������",
                                RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                                    "������� ������������ � ����������, ������������",
                                PHYSICAL_CULTURE         =
                                    "���������� ��������",
                                SPORT                    =
                                    "�����",
                                TOURISM_HOSPITALITY      =
                                    "������ � ��������������",
                                TOURISM                  =
                                    "������",
                                HOSPITALITY              =
                                    "��������������",
                                RESEARCH_AND_TEACHING    =                                  // Master degree
                                    "������� ������������ � ����������, ������������",
                                INNOVATION                     =                            // Master degree
                                    "������������� ������������ (� ����������� "        \
                                    "����������� ������������)";
                        }
                        namespace SECTION
                        {
                            const AnsiString
                                RESEARCH_SPORT                 =                            // Master degree
                                    "���������� �������� � �����",
                                PHYSICAL_CULTURE              =
                                    "���������� �������� (�� ������������)",
                                IMPROVING_AND_ADAPTIVE        =
                                    "��������������� � ���������� ���������� �������� " \
                                    "(�� ������������)",
                                REHABILITATION_ERGOTHERAPY    =
                                    "���������� ������������ � ����������� "            \
                                    "(�� ������������)",
                                TRAINING_MILITARY_PERSONNEL   =
                                    "���������� ���������� ��������������",
                                SPORTS_AND_PEDAGOGY           =
                                    "���������-�������������� ������������",
                                SPORTS_CHOREOGRAPHY           =
                                    "���������� �����������",
                                TOURISM_HOSPITALITY       =
                                    "������ � ��������������",
                                SPORTS_AND_TOURISM            =
                                    "���������-���������� ������������ "                \
                                    "(�� ������������)",
                                TOURISM_AND_NATURE_MANAGEMENT =
                                    "������ � ������������������",
                                HOSPITALITY_TECHNOLOGIES      =
                                    "���������� ��������� �������������� "              \
                                    "(�� ������������)",
                                TOURISM_HOSPITALITY_STUDY =
                                    "������ � ��������������",
                                RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                                    "������ � ��������������",
                                INNOVATION_MANAGEMENT          =                            // Master degree
                                    "���������� �������������� ��������� � "            \
                                    "���������� ���������",
                                INNOVATION_TOURISM             =                            // Master degree
                                    "������������� ���������� � ����� �������",
                                INNOVATION_HOSPITALITY         =                            // Master degree
                                    "������������� ���������� � ����� ��������������",
                                INNOVATION_TECHNOLOGY          =                            // Master degree
                                    "������������� ���������� � ����� ������� � "       \
                                    "��������������";
                        }
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL        =
                                    "���������� �������� (��������)",
                                PRESCHOOLERS   =
                                    "���������� �������� (������������)",
                                HEALTH         =
                                    "��������������� � ���������� ���������� �������� " \
                                    "(���������������)",
                                ADAPTIVE       =
                                    "��������������� � ���������� ���������� �������� " \
                                    "(����������)",
                                REHABILITATION =
                                    "���������� ������������ � ����������� "            \
                                    "(���������� ������������)",
                                ERGOTHERAPY    =
                                    "���������� ������������ � ����������� "            \
                                    "(�����������)",
                                COACHING       =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ������ � ��������� ���� ������)",
                                MANAGEMENT     =
                                    "���������-�������������� ������������ "            \
                                    "(���������� � ������)",
                                PSYCHOLOGY     =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ����������)",
                                DIRECTING      =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ���������)",
                                PROMOTION      =
                                    "���������� ������������ � ����������� "            \
                                    "������������� �����",
                                IT             =
                                    "�������������� ���������� ������������� "          \
                                    "���������",
                                LOGISTICS      =
                                    "��������� � ������������� ���������",
                                SOCIAL         =
                                    "���������� ���������������� ������� ��������",
                                TRANSPORT      =
                                    "���������� ������������� ������� ��������",
                                CATERING       =
                                    "���������� ������� ������� ��������",
                                ACCOMMODATION  =
                                    "���������� ������� ���������� ��������",
                                SUPPORTING     =
                                    "���������� ������������-����������������� "        \
                                    "������� ��������",
                                TREATMENT      =
                                    "���������� ������� ������������ � ������� "        \
                                    "��������",
                                RECREATIONAL   =
                                    "���������-���������� ������������ "                \
                                    "(���������� � ������������� ������)",
                                TUORISM_MNG    =
                                    "���������-���������� ������������ "                \
                                    "(���������� � �������)",
                                RESTAURANTS    =
                                    "���������� ��������� �������������� "              \
                                    "(����������� ������������)";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  =
                                        "����������",
                                    THEORY      =
                                        "������ � �������� ����������� ����������, "    \
                                        "���������� ����������, ��������������� � "     \
                                        "���������� ���������� ��������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       =
                                        "���������� �������� � �����",
                                    MANAGEMENT  =
                                        "����������",
                                    TOURISM     =
                                        "������ � ��������������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  =
                                        "���������� �������������� ��������� � "        \
                                        "���������� ���������",
                                    TOURISM     =
                                        "������������� ���������� � ����� �������",
                                    HOSPITALITY =
                                        "������������� ���������� � ����� "             \
                                        "��������������",
                                    TECHNO  =
                                        "������������� ���������� � ����� ������� � "   \
                                        "��������������";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL        = "���������� �������� (��������)",
                                PRESCHOOLERS   = "���������� �������� (������������)";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH         =
                                    "��������������� � ���������� ���������� �������� " \
                                    "(���������������)",
                                ADAPTIVE       =
                                    "��������������� � ���������� ���������� �������� " \
                                    "(����������)";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION =
                                    "���������� ������������ � ����������� "            \
                                    "(���������� ������������)",
                                ERGOTHERAPY    =
                                    "���������� ������������ � ����������� "            \
                                    "(�����������)";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       = "���������� ���������� ��������������";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING       =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ������ � ��������� ���� ������)",
                                MANAGEMENT     =
                                    "���������-�������������� ������������ "            \
                                    "(���������� � ������)",
                                PSYCHOLOGY     =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ����������)",
                                DIRECTING      =
                                    "���������-�������������� ������������ "            \
                                    "(���������� ���������)";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION      =
                                    "���������� ������������ � ����������� "            \
                                    "������������� �����",
                                IT             =
                                    "�������������� ���������� ������������� ���������",
                                LOGISTICS      =
                                    "��������� � ������������� ���������",
                                SOCIAL         =
                                    "���������� ���������������� ������� ��������",
                                TRANSPORT      =
                                    "���������� ������������� ������� ��������",
                                CATERING       =
                                    "���������� ������� ������� ��������",
                                ACCOMMODATION  =
                                    "���������� ������� ���������� ��������",
                                SUPPORTING     =
                                    "���������� ������������-����������������� "        \
                                    "������� ��������",
                                TREATMENT      =
                                    "���������� ������� ������������ � ������� "        \
                                    "��������";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL   =
                                    "���������-���������� ������������ "                \
                                    "(���������� � ������������� ������)",
                                TUORISM_MNG    =
                                    "���������-���������� ������������ "                \
                                    "(���������� � �������)";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS    =
                                    "���������� ��������� �������������� "              \
                                    "(����������� ������������)";
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL        =
                                    "����������-�������� �� �������� ���������� "       \
                                    "��������. ������������� ���������� ��������",
                                PRESCHOOLERS   =
                                    "����������-�������� ����������� ���������� � "     \
                                    "���������� �����������. "                          \
                                    "������������� ���������� ��������",
                                HEALTH         =
                                    "����������-�������� �� ��������������� "           \
                                    "���������� ��������. "                             \
                                    "������������� ���������� ��������",
                                ADAPTIVE       =
                                    "����������-�������� �� ���������� "                \
                                    "���������� ��������. "                             \
                                    "������������� ���������� ��������",
                                REHABILITATION =
                                    "����������-�������� �� ���������� "                \
                                    "������������. "                                    \
                                    "������������� ���������� ��������",
                                ERGOTHERAPY    =
                                    "����������-�������� �� �����������. "              \
                                    "������������� ���������� ��������",
                                TRAINING       =
                                    "���������� �� ����������. "                        \
                                    "����������-�������� �� ���������� "                \
                                    "����������",
                                COACHING       =
                                    "������ (�� ���� ������). "                         \
                                    "������������� ���������� ��������",
                                MANAGEMENT     =
                                    "�������� � ������. "                               \
                                    "������������� ���������� ��������",
                                PSYCHOLOGY     =
                                    "��������. "                                        \
                                    "������������� ���������� ��������",
                                DIRECTING      =
                                    "��������-�������� ���������-�������� "             \
                                    "�����������."                                      \
                                    "������������� ���������� ��������",
                                PROMOTION      =
                                    "���������� � ����� ������� � ��������������",
                                IT             =
                                    "���������� � ����� ������� � ��������������",
                                LOGISTICS      =
                                    "���������� � ����� ������� � ��������������",
                                SOCIAL         =
                                    "���������� � ����� ������� � ��������������",
                                TRANSPORT      =
                                    "���������� � ����� ������� � ��������������",
                                CATERING       =
                                    "���������� � ����� ������� � ��������������",
                                ACCOMMODATION  =
                                    "���������� � ����� ������� � ��������������",
                                SUPPORTING     =
                                    "���������� � ����� ������� � ��������������",
                                TREATMENT      =
                                    "���������� � ����� ������� � ��������������",
                                RECREATIONAL   =
                                    "����������-�������� �� �������. "                  \
                                    "������������� ���������� ��������",
                                TUORISM_MNG    =
                                    "�������� �� �������. "                             \
                                    "������������� ���������� ��������",
                                RESTAURANTS    = "��������. ��������";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  = "�������",
                                    THEORY      = "�������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       = "�������",
                                    MANAGEMENT  = "�������",
                                    TOURISM     = "�������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  = "�������",
                                    TOURISM     = "�������",
                                    HOSPITALITY = "�������",
                                    TECHNO      = "�������";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL        =
                                    "����������-�������� �� �������� ���������� "       \
                                    "��������. ������������� ���������� ��������",
                                PRESCHOOLERS   =
                                    "����������-�������� ����������� ���������� � "     \
                                    "���������� �����������. "                          \
                                    "������������� ���������� ��������";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH         =
                                    "����������-�������� �� ��������������� "           \
                                    "���������� ��������. "                             \
                                    "������������� ���������� ��������",
                                ADAPTIVE       =
                                    "����������-�������� �� ���������� "                \
                                    "���������� ��������. "                             \
                                    "������������� ���������� ��������";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION =
                                    "����������-�������� �� ���������� "                \
                                    "������������. "                                    \
                                    "������������� ���������� ��������",
                                ERGOTHERAPY    =
                                    "����������-�������� �� �����������. "              \
                                    "������������� ���������� ��������";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       =
                                    "���������� �� ����������. "                        \
                                    "����������-�������� �� ���������� "                \
                                    "����������";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING       =
                                    "������ (�� ���� ������). "                         \
                                    "������������� ���������� ��������",
                                MANAGEMENT     =
                                    "�������� � ������. "                               \
                                    "������������� ���������� ��������",
                                PSYCHOLOGY     =
                                    "��������. "                                        \
                                    "������������� ���������� ��������",
                                DIRECTING      =
                                    "��������-�������� ���������-�������� "             \
                                    "�����������."                                      \
                                    "������������� ���������� ��������";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION      =
                                    "���������� � ����� ������� � ��������������",
                                IT             =
                                    "���������� � ����� ������� � ��������������",
                                LOGISTICS      =
                                    "���������� � ����� ������� � ��������������",
                                SOCIAL         =
                                    "���������� � ����� ������� � ��������������",
                                TRANSPORT      =
                                    "���������� � ����� ������� � ��������������",
                                CATERING       =
                                    "���������� � ����� ������� � ��������������",
                                ACCOMMODATION  =
                                    "���������� � ����� ������� � ��������������",
                                SUPPORTING     =
                                    "���������� � ����� ������� � ��������������",
                                TREATMENT      =
                                    "���������� � ����� ������� � ��������������";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL   =
                                    "����������-�������� �� �������. "                  \
                                    "������������� ���������� ��������",
                                TUORISM_MNG    =
                                    "�������� �� �������. "                             \
                                    "������������� ���������� ��������";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS    = "��������. ��������";
                        }
                    }
                }
                namespace _2022
                {
                    namespace CODE
                    {
                        const AnsiString
                            PHYSIOLOGY       = "03.03.01",                                  // Master degree
                            THEORY_IMPROVING = "13.00.04",                                  // Master degree
                            INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                            INNO_TOURISM     = "1-89 81 02",                                // Master degree
                            INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                            INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                            PHYSICAL_CULTURE = "6-05-1012-01",
                            COACHING         = "6-05-1012-02",
                            REHABILITATION   = "6-05-1012-03",
                            MANAGEMENT       = "6-05-1012-04",
                            TOURISM          = "6-05-1013-01",
                            NATURE           = "6-05-1013-03",
                            HOSPITALITY      = "6-05-1013-04",
                            MNG_MASTER_DEGREE = "7-06-0412-01",
                            PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                            TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                            CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
                    }
                    namespace NAME
                    {
                        const AnsiString
                            PHYSIOLOGY       =                                              // Master degree
                                "����������",
                            THEORY_IMPROVING =                                              // Master degree
                                "������ � �������� ����������� ����������, "        \
                                "���������� ����������, ��������������� � "         \
                                "���������� ���������� ��������",
                            INNO_MANAGEMENT  =                                              // Master degree
                                "���������� �������������� ��������� � "            \
                                "���������� ���������",
                            INNO_TOURISM     =                                              // Master degree
                                "������������� ���������� � ����� �������",
                            INNO_HOSPITALITY =                                              // Master degree
                                "������������� ���������� � ����� ��������������",
                            INNO_TECHNOLOGY  =                                              // Master degree
                                "������������� ���������� � ����� ������� � "       \
                                "��������������",
                            PHYSICAL_CULTURE =
                                "���������� ��������",
                            COACHING         =
                                "���������� ������������",
                            REHABILITATION   =
                                "���������� ������������ � �����������",
                            MANAGEMENT       =
                                "����������� � ���������� ���������� ���������, "   \
                                "������� � ��������",
                            TOURISM          =
                                "������ � ��������������",
                            NATURE           =
                                "������ � ������������������",
                            HOSPITALITY      =
                                "���������� ��������� ��������������",
                            PC_MASTER_DEGREE =                                              // Master degree
                                "���������� �������� � �����",
                            TH_MASTER_DEGREE =                                              // Master degree
                                "������ � ��������������",
                            CHOREOGRAPHY     =
                                "���������� �����������";

                        namespace PHYSICAL
                        {
                            const AnsiString
                                IMPROVING      = "(���������������)",                       // "(��������������� ���������� ��������)",
                                HEALTH         = "(��������)",                              // "(�������� ���������� ��������)",
                                PRESCHOOLERS   = "(������������)",                          // "(���������� �������� ������������)",
                                ADAPTIVE       = "(����������)",                            // "(���������� ���������� ��������)",
                                DIRECTING      = "(���������� ���������)",
                                PSYCHOLOGY     = "(���������� ����������)",
                                RECREATIONAL   = "(���������� � ������������� ������)";
                        }
                        namespace COACH
                        {
                            const AnsiString
                                DEFAULT        = "(� ��������� ���� ������)";
                        }
                        namespace REHABILITATE
                        {
                            const AnsiString
                                REHABILITATION = "(���������� ������������)",
                                ERGOTHERAPY    = "(�����������)";
                        }
                        namespace MANAGE
                        {
                            const AnsiString
                                SPORT          = "(���������� � ������)",
                                TOURISM        = "(���������� � �������)";
                        }
                    }
                    namespace QUALIFICATION
                    {
                        const AnsiString
                            PHYSIOLOGY       = "�������",                                   // Master degree
                            THEORY_IMPROVING = "�������",                                   // Master degree
                            INNO_MANAGEMENT  = "������� ����������",                        // Master degree
                            INNO_TOURISM     = "������� �������",                           // Master degree
                            INNO_HOSPITALITY = "������� ��������������",                    // Master degree
                            INNO_TECHNOLOGY  = "������� ���������",                         // Master degree
                            PHYSICAL_CULTURE = "����������-��������. �������������",
                            COACHING         = "������. �������������",
                            REHABILITATION   = "����������-��������. �������������",
                            MANAGEMENT       = "��������. �������������",
                            TOURISM          = "����������",
                            NATURE           = "���������� �� ������� � ������������������",
                            HOSPITALITY      = "��������. ��������",
                            PC_MASTER_DEGREE = "�������",                                   // Master degree
                            TH_MASTER_DEGREE = "�������",                                   // Master degree
                            CHOREOGRAPHY     = "����������-��������";
                    }
                }
            }
            namespace KindOfSport
            {
                const AnsiString
                    GYMNASTICS                   =
                        "����������",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "���������� ������ � �������",
                    PHYSICAL_REHABILITATION      =
                        "���������� ������������",
                    THERAPEUTIC                  =
                        "�������� ���������� ��������",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "����������� ������������-��������������� "         \
                        "������ � �������",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "���������� ���������� ����������",
                    DANCE_SPORT                  =
                        "������������ �����",
                    AEROBICS                     =
                        "��������",
                    ROWING_OTHER                 =
                        "������� �����",
                    SWIMMING                     =
                        "��������",
                    SAILING                      =
                        "�������� �����",
                    ATHLETICS                    =
                        "������ ��������",
                    CROSS_COUNTRY_SKIING         =
                        "������ �����",
                    BULLET_SHOOTING_DEANERY      =
                        "������� ��������",
                    HAND_TO_HAND_COMBAT          =
                        "���������� ���",
                    TAEKWONDO                    =
                        "���������",
                    KARATE                       =
                        "������",
                    SKIING                       =
                        "������ �����",
                    AUTOMOTIVE_SPORT             =
                        "������������� �����",
                    BASKETBALL                   =
                        "���������",
                    BOXING                       =
                        "����",
                    GRECO_FREESTYLE_WRESTLING    =
                        "�����-������� � ������� ������",
                    CYCLING                      =
                        "������������ �����",
                    VOLLEYBALL                   =
                        "��������",
                    HANDBALL                     =
                        "�������",
                    EQUESTRIAN                   =
                        "������ �����",
                    SPEED_SKATING                =
                        "������������ �����",
                    TENNIS                       =
                        "������",
                    WEIGHTLIFTING                =
                        "������� ��������",
                    FENCING                      =
                        "����������",
                    FIGURE_SKATING_OLD           =
                        "�������� �������",
                    FOOTBALL                     =
                        "������",
                    HOCKEY                       =
                        "������",
                    SAMBO_JUDO                   =
                        "�����-�����",
                    WRESTLING                    =
                        "���������� ������",
                    FOOTBALL_HOCKEY              =
                        "������ � ������",
                    BIATHLON                     =
                        "�������",
                    HEALTH_IMPROVING             =
                        "��������������� ���������� ��������",
                    ADAPTIVE                     =
                        "���������� ���������� ��������",
                    FREESTYLE_WRESTLING          =
                        "������� ������",
                    GRECO_ROMAN_WRESTLING        =
                        "�����-������� ������",
                    SAMBO                        =
                        "�����",
                    JUDO                         =
                        "�����",
                    TABLE_TENNIS_ABITURIENT      =
                        "������ ����������",
                    ERGOTHERAPY                  =
                        "�����������",
                    MANAGEMENT_SPORTS            =
                        "���������� � ������",
                    SPORTS_DIRECTING_DEANERY     =
                        "���������� ���������",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "���������� � ������������� ������",
                    MANAGEMENT_TOURISM           =
                        "���������� � �������",
                    SPORTS_PSYCHOLOGY            =
                        "���������� ����������",
                    BILLIARD_SPORTS              =
                        "���������� �����",
                    ACROBATICS                   =
                        "����������",
                    ORIENTEERING                 =
                        "���������� ��������������",
                    SPORTS_DIRECTING             =
                        "���������� ���������",
                    PRESCHOOLERS                 =
                        "���������� �������� ������������",
                    MOUNTAINEERING               =
                        "���������",
                    SKI_COMBINED                 =
                        "������ ���������",
                    TOURISM_HOSPITALITY          =
                        "������ � ��������������",
                    WATER_TECHNICAL_SPORTS       =
                        "�����-����������� ���� ������",
                    MODEL_TECHNICAL_SPORTS       =
                        "��������-����������� ���� ������",
                    ALPINE_SKIING                =
                        "����������� �����",
                    BASEBALL                     =
                        "�������",
                    WUSHU                        =
                        "���",
                    CHESS                        =
                        "�������",
                    THAI_BOXING                  =
                        "����������� ����",
                    TOURISM_PROMOTION            =
                        "���������� ������������ � ����������� "            \
                        "������������� �����",
                    TOURISM_IT                   =
                        "�������������� ���������� ������������� "          \
                        "���������",
                    TOURISM_LOGISTICS            =
                        "��������� � ������������� ���������",
                    TOURISM_SOCIAL               =
                        "���������� ���������������� ������� "              \
                        "��������",
                    TOURISM_TRANSPORT            =
                        "���������� ������������� ������� ��������",
                    TOURISM_FOOD                 =
                        "���������� ������� ������� ��������",
                    TOURIST_ACCOMMODATION        =
                        "���������� ������� ���������� ��������",
                    TOURISM_EXCURSION            =
                        "���������� ������������-����������������� "        \
                        "������� ��������",
                    TOURISM_HEALTH               =
                        "���������� ������� ������������ � ������� "        \
                        "��������",
                    BULLET_SHOOTING              =
                        "�������� �������",
                    FIELD_HOCKEY                 =
                        "������ �� �����",
                    FIGURE_SKATING               =
                        "�������� ������� �� �������",
                    ROWING_AND_CANOEING          =
                        "������ �� ��������� � �����",
                    ACADEMIC_ROWING              =
                        "������ �������������",
                    HAND_TO_HAND_COMBAT_MS       =
                        "���������� ��� (��������� ������������)",
                    BILLIARDS_RPC                =
                        "�������",
                    WITHOUT_SPECIALIZATION       =
                        "��� �������������",
                    MEDICAL                      =
                        "���������� ��������(��������)",
                    MODERN_PENTATHLON            =
                        "����������� ���������",
                    SCIENCE_HEALTH               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    PHYSIOLOGY                   =
                        "����������",
                    SCIENCE_THEORY               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    RECEARCH_SPORT               =
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ���������������",
                    INNOVATIVE_TOURISM           =
                        "������������� ���������� � ����� �������",
                    INNOVATIVE_HOSPITALITY       =
                        "������������� ���������� � ����� ��������������",
                    INNOVATIVE_TECHNOLOGIES      =
                        "������������� ���������� � ����� ������� "         \
                        "� ��������������",
                    INNOVATIVE_MANAGEMENT        =
                        "���������� �������������� ��������� � "            \
                        "���������� ���������",
                    BILLIARDS_SMA                =
                        "�������",
                    HAND_TO_HAND_COMBAT_SMA      =
                        "���������� ��� (��������� ������������)",
                    BADMINTON                    =
                        "���������",
                    TABLE_TENNIS_DEANERY         =
                        "���������� ������",
                    PHYSICAL_CULTURE_SPORT       =
                        "���������� �������� � �����",
                    TOURISM_HOSPITALITY_MASTER   =
                        "������ � ��������������",
                    SPORT_CLIMBING               =
                        "������������ ����������",
                    MASTER_ANTHROPOLOGY          =
                        "������������",
                    MASTER_MANAGEMENT            =
                        "����������",
                    MASTER_PHYSICAL_CULTURE      =
                        "���������� �������� � �����";

                namespace DATIVE_CASE
                {
                    const AnsiString
                        GYMNASTICS                   =
                            "����������",
                        MANAGEMENT_SPORTS_TOURISM    =
                            "����������� ������ � �������",
                        PHYSICAL_REHABILITATION      =
                            "���������� ������������",
                        THERAPEUTIC                  =
                            "�������� ���������� ��������",
                        ORGANIZATION_SPORTS_TOURISM  =
                            "����������� ������������-��������������� "         \
                            "������ � �������",
                        PRESCHOOL_PHYSICAL_EDUCATION =
                            "����������� ����������� ����������",
                        DANCE_SPORT                  =
                            "������������� ������",
                        AEROBICS                     =
                            "��������",
                        ROWING_OTHER                 =
                            "�������� ������",
                        SWIMMING                     =
                            "��������",
                        SAILING                      =
                            "��������� ������",
                        ATHLETICS                    =
                            "������ ��������",
                        CROSS_COUNTRY_SKIING         =
                            "������ ������",
                        BULLET_SHOOTING_DEANERY      =
                            "������� ��������",
                        HAND_TO_HAND_COMBAT          =
                            "����������� ���",
                        TAEKWONDO                    =
                            "���������",
                        KARATE                       =
                            "������",
                        SKIING                       =
                            "������� ������",
                        AUTOMOTIVE_SPORT             =
                            "�������������� ������",
                        BASKETBALL                   =
                            "����������",
                        BOXING                       =
                            "�����",
                        GRECO_FREESTYLE_WRESTLING    =
                            "�����-������� � ������� ������",
                        CYCLING                      =
                            "������������� ������",
                        VOLLEYBALL                   =
                            "���������",
                        HANDBALL                     =
                            "��������",
                        EQUESTRIAN                   =
                            "������� ������",
                        SPEED_SKATING                =
                            "������������� ������",
                        TENNIS                       =
                            "�������",
                        WEIGHTLIFTING                =
                            "������� ��������",
                        FENCING                      =
                            "����������",
                        FIGURE_SKATING_OLD           =
                            "��������� �������",
                        FOOTBALL                     =
                            "�������",
                        HOCKEY                       =
                            "������",
                        SAMBO_JUDO                   =
                            "�����-�����",
                        WRESTLING                    =
                            "���������� ������",
                        FOOTBALL_HOCKEY              =
                            "������� � ������",
                        BIATHLON                     =
                            "��������",
                        HEALTH_IMPROVING             =
                            "��������������� ���������� ��������",
                        ADAPTIVE                     =
                            "���������� ���������� ��������",
                        FREESTYLE_WRESTLING          =
                            "������� ������",
                        GRECO_ROMAN_WRESTLING        =
                            "�����-������� ������",
                        SAMBO                        =
                            "�����",
                        JUDO                         =
                            "�����",
                        TABLE_TENNIS_ABITURIENT      =
                            "������� �����������",
                        ERGOTHERAPY                  =
                            "�����������",
                        MANAGEMENT_SPORTS            =
                            "����������� � ������",
                        SPORTS_DIRECTING_DEANERY     =
                            "���������� ���������",
                        SPORTS_RECREATIONAL_TOURISM  =
                            "����������� � �������������� �������",
                        MANAGEMENT_TOURISM           =
                            "����������� � �������",
                        SPORTS_PSYCHOLOGY            =
                            "���������� ����������",
                        BILLIARD_SPORTS              =
                            "����������� ������",
                        ACROBATICS                   =
                            "����������",
                        ORIENTEERING                 =
                            "����������� ��������������",
                        SPORTS_DIRECTING             =
                            "���������� ���������",
                        PRESCHOOLERS                 =
                            "���������� �������� ������������",
                        MOUNTAINEERING               =
                            "����������",
                        SKI_COMBINED                 =
                            "������� ���������",
                        TOURISM_HOSPITALITY          =
                            "������� � ��������������",
                        WATER_TECHNICAL_SPORTS       =
                            "�����-����������� ����� ������",
                        MODEL_TECHNICAL_SPORTS       =
                            "��������-����������� ����� ������",
                        ALPINE_SKIING                =
                            "������������ ������",
                        BASEBALL                     =
                            "��������",
                        WUSHU                        =
                            "���",
                        CHESS                        =
                            "��������",
                        THAI_BOXING                  =
                            "������������ �����",
                        TOURISM_PROMOTION            =
                            "����������� ������������ � ����������� "            \
                            "������������� �����",
                        TOURISM_IT                   =
                            "�������������� ����������� ������������� "          \
                            "���������",
                        TOURISM_LOGISTICS            =
                            "��������� � ������������� ���������",
                        TOURISM_SOCIAL               =
                            "����������� ���������������� ������� "              \
                            "��������",
                        TOURISM_TRANSPORT            =
                            "����������� ������������� ������� ��������",
                        TOURISM_FOOD                 =
                            "����������� ������� ������� ��������",
                        TOURIST_ACCOMMODATION        =
                            "����������� ������� ���������� ��������",
                        TOURISM_EXCURSION            =
                            "����������� ������������-����������������� "        \
                            "������� ��������",
                        TOURISM_HEALTH               =
                            "����������� ������� ������������ � ������� "        \
                            "��������",
                        BULLET_SHOOTING              =
                            "�������� �������",
                        FIELD_HOCKEY                 =
                            "������ �� �����",
                        FIGURE_SKATING               =
                            "��������� ������� �� �������",
                        ROWING_AND_CANOEING          =
                            "������ �� ��������� � �����",
                        ACADEMIC_ROWING              =
                            "������ �������������",
                        HAND_TO_HAND_COMBAT_MS       =
                            "����������� ��� (��������� ������������)",
                        BILLIARDS_RPC                =
                            "��������",
                        WITHOUT_SPECIALIZATION       =
                            "��� �������������",
                        MEDICAL                      =
                            "���������� �������� (��������)",
                        MODERN_PENTATHLON            =
                            "������������ ���������",
                        SCIENCE_HEALTH               =
                            "������ � �������� ����������� ����������, "        \
                            "���������� ����������, ���������������",
                        PHYSIOLOGY                   =
                            "����������",
                        SCIENCE_THEORY               =
                            "������ � �������� ����������� ����������, "        \
                            "���������� ����������, ���������������",
                        RECEARCH_SPORT               =
                            "������ � �������� ����������� ����������, "        \
                            "���������� ����������, ���������������",
                        INNOVATIVE_TOURISM           =
                            "�������������� ����������� � ����� �������",
                        INNOVATIVE_HOSPITALITY       =
                            "�������������� ����������� � ����� ��������������",
                        INNOVATIVE_TECHNOLOGIES      =
                            "������������� ����������� � ����� ������� "         \
                            "� ��������������",
                        INNOVATIVE_MANAGEMENT        =
                            "���������� �������������� ��������� � "            \
                            "���������� ���������",
                        BILLIARDS_SMA                =
                            "��������",
                        HAND_TO_HAND_COMBAT_SMA      =
                            "����������� ��� (��������� ������������)",
                        BADMINTON                    =
                            "����������",
                        TABLE_TENNIS_DEANERY         =
                            "����������� �������",
                        PHYSICAL_CULTURE_SPORT       =
                            "���������� �������� � ������",
                        TOURISM_HOSPITALITY_MASTER   =
                            "������� � ��������������",
                        SPORT_CLIMBING               =
                            "����������� ������������",
                        MASTER_ANTHROPOLOGY          =
                            "������������",
                        MASTER_MANAGEMENT            =
                            "�����������",
                        MASTER_PHYSICAL_CULTURE      =
                            "���������� �������� � ������";
                }
            }
        #else
            namespace NCRB_011                                                              // National Classifier of the Republic of Belarus
            {
                namespace _2009
                {
                    namespace CODE
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING   = "1-88 02 01-01",
                                    PSYCHOLOGY = "1-88 02 01-03",
                                    DIRECTING  = "1-88 02 01-04",
                                    MANAGEMENT = "1-88 02 01-02";
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL = "1-89 02 01-01",
                                    TUORISM_MNG  = "1-89 02 01-02";
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL      = "1-88 01 01-01",
                                    PRESCHOOLERS = "1-88 01 01-02";
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH   = "1-88 01 02-01",
                                    ADAPTIVE = "1-88 01 02-02";
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION = "1-88 01 03-01",
                                    ERGOTHERAPY    = "1-88 01 03-02";
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY   = "1-89 01 01",
                                    PROMOTION     = "1-89 01 01 01",
                                    IT            = "1-89 01 01 02",
                                    LOGISTICS     = "1-89 01 01 03",
                                    SOCIAL        = "1-89 01 01 04",
                                    TRANSPORT     = "1-89 01 01 05",
                                    CATERING      = "1-89 01 01 06",
                                    ACCOMMODATION = "1-89 01 01 07",
                                    SUPPORTING    = "1-89 01 01 08",
                                    TREATMENT     = "1-89 01 01 09";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS = "1-89 03 01-01";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING = "1-88 01 04";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "13.00.04",
                                    PHYSIOLOGY       = "03.03.01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "1-89 81 02",
                                    HOSPITALITY      = "1-89 81 03",
                                    TECHNOLOGIES     = "1-89 81 04",
                                    MANAGEMENT       = "1-89 81 01";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "1-08 80 04",
                                    PHYSICAL_CULTURE = "1-89 80 01",
                                    MANAGEMENT       = "1-26 80 04",
                                    TOURISM          = "1-89 80 01";
                            }
                        }
                    }
                    namespace SECTION
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                IMPROVING         =
                                    "��������������� � ���������� ���������� "          \
                                    "��������",                                             // (�� ������������)
                                COACHING          =
                                    "���������-�������������� ������������",                // (�� ������������)
                                MANAGEMENT        =
                                    "���������-���������� ������������",                    // (�� ������������)
                                PHYSICAL_CULTURE  =
                                    "���������� ��������",                                  // (�� ������������)
                                REHABILITATION    =
                                    "���������� ������������ � �����������",                // (�� ������������)
                                TOURISM           =
                                    "������ � ��������������";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "������ � �������� ����������� ����������, "    \
                                        "���������� ����������, ���������������",
                                    PHYSIOLOGY       =
                                        "����������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM        =
                                        "������������� ���������� � ����� �������",
                                    HOSPITALITY    =
                                        "������������� ���������� � ����� "             \
                                        "��������������",
                                    TECHNOLOGIES   =
                                        "������������� ���������� � ����� ������� "     \
                                        "� ��������������",
                                    MANAGEMENT     =
                                        "���������� �������������� ��������� � "        \
                                        "���������� ���������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "������ � �������� ����������� "                \
                                        "����������, ���������� ����������, "           \
                                        "��������������� � ���������� ��",
                                    PHYSICAL_CULTURE =
                                        "���������� �������� � �����",
                                    TOURISM          =
                                        "������ � ��������������",
                                    MANAGEMENT       =
                                        "����������";
                            }
                        }
                    }
                    namespace PROFILING
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING       = "T��������� ������ �� ",               // + getKindOfSportNameDativeCase (nSpecializ)
                                    PSYCHOLOGY     = "���������� ����������",               // (AsPostfix)
                                    DIRECTING      = "����������� ���������",               // (AsPostfix)
                                    MANAGEMENT     = "���������� � ������";                 // (AsPostfix)
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL   = "���������� � ������������� ������",   // (AsPostfix)
                                    TUORISM_MNG    = "���������� � �������";                // (AsPostfix)
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL        = "��������",                            // (AsPostfix)
                                    PRESCHOOLERS   = "������������";                        // (AsPostfix)
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH         = "���������������",                     // (AsPostfix)
                                    ADAPTIVE       = "����������";                          // (AsPostfix)
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION = "���������� ������������",             // (AsPostfix)
                                    ERGOTHERAPY    = "�����������";                         // (AsPostfix)
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY    = "������ � ��������������",
                                    PROMOTION      =
                                        "���������� ������������ � ����������� "        \
                                        "������������� �����",
                                    IT             =
                                        "�������������� ���������� ������������� "      \
                                        "���������",
                                    LOGISTICS      =
                                        "��������� � ������������� ���������",
                                    SOCIAL         =
                                        "���������� ���������������� ������ ��������",
                                    TRANSPORT      =
                                        "���������� ������������� ������� ��������",
                                    CATERING       =
                                        "���������� ������� ������� ��������",
                                    ACCOMMODATION  =
                                        "���������� ������� ������������������ ",
                                    SUPPORTING     =
                                        "���������� ������������-����������������� "    \
                                        "������� ��������",
                                    TREATMENT      =
                                        "���������� ������� ������������ � ������� "    \
                                        "��������";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS    = "����������� ������������";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       = "���������� ���������� ��������������";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "������ � �������� ����������� ����������, "    \
                                        "���������� ����������, ��������������� � "     \
                                        "���������� ���������� ��������.",
                                    PHYSIOLOGY       = "����������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          =
                                        "������������� ���������� � ����� �������",
                                    HOSPITALITY      =
                                        "������������� ���������� � ����� "             \
                                        "��������������",
                                    TECHNOLOGIES     =
                                        "������������� ���������� � ����� ������� � "   \
                                        "��������������",
                                    MANAGEMENT       =
                                        "���������� �������������� ��������� � "        \
                                        "���������� ���������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "������ � �������� ����������� ����������, "    \
                                        "���������� ����������, ��������������� � "     \
                                        "���������� ���������� ��������.",
                                    PHYSICAL_CULTURE = "���������� �������� � �����",
                                    MANAGEMENT       = "����������",
                                    TOURISM          = "������ � ��������������";
                            }
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING       =
                                        "������ (�� ���� ������). "                     \
                                        "������������� ���������� ��������",
                                    PSYCHOLOGY     =
                                        "��������. "                                    \
                                        "������������� ���������� ��������",
                                    DIRECTING      =
                                        "��������-�������� ���������-�������� "         \
                                        "�����������."                                  \
                                        "������������� ���������� ��������",
                                    MANAGEMENT     =
                                        "�������� � ������. "                           \
                                        "������������� ���������� ��������";
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL   =
                                        "����������-�������� �� �������. "              \
                                        "������������� ���������� ��������",
                                    TUORISM_MNG    =
                                        "�������� �� �������. "                         \
                                        "������������� ���������� ��������";
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL        =
                                        "����������-�������� �� �������� ���������� "   \
                                        "��������. ������������� ���������� ��������",
                                    PRESCHOOLERS   =
                                        "����������-�������� ����������� ���������� � " \
                                        "���������� �����������. "                      \
                                        "������������� ���������� ��������";
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH         =
                                        "����������-�������� �� ��������������� "       \
                                        "���������� ��������. "                         \
                                        "������������� ���������� ��������",
                                    ADAPTIVE       =
                                        "����������-�������� �� ���������� "            \
                                        "���������� ��������. "                         \
                                        "������������� ���������� ��������";
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION =
                                        "����������-�������� �� ���������� "            \
                                        "������������. "                                \
                                        "������������� ���������� ��������",
                                    ERGOTHERAPY    =
                                        "����������-�������� �� �����������. "          \
                                        "������������� ���������� ��������";
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY    =
                                        "���������� � ����� ������� � ��������������",
                                    PROMOTION      =
                                        "���������� � ����� ������� � ��������������",
                                    IT             =
                                        "���������� � ����� ������� � ��������������",
                                    LOGISTICS      =
                                        "���������� � ����� ������� � ��������������",
                                    SOCIAL         =
                                        "���������� � ����� ������� � ��������������",
                                    TRANSPORT      =
                                        "���������� � ����� ������� � ��������������",
                                    CATERING       =
                                        "���������� � ����� ������� � ��������������",
                                    ACCOMMODATION  =
                                        "���������� � ����� ������� � ��������������",
                                    SUPPORTING     =
                                        "���������� � ����� ������� � ��������������",
                                    TREATMENT      =
                                        "���������� � ����� ������� � ��������������";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS    = "��������. ��������";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       =
                                    "���������� �� ����������. "                        \
                                    "����������-�������� �� ���������� "                \
                                    "����������";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "�������",
                                    PHYSIOLOGY       = "�������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "������� �������",
                                    HOSPITALITY      = "������� ��������������",
                                    TECHNOLOGIES     = "������� ���������",
                                    MANAGEMENT       = "������� ����������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "�������",
                                    PHYSICAL_CULTURE = "�������",
                                    TOURISM          = "�������",
                                    MANAGEMENT       = "�������";
                            }
                        }
                    }
                }
                namespace _2022
                {
                    namespace CODE
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         = "6-05-1012-02",                          // "6-05-1012-02", old code: "1-88 02 01-01",
                                TOURISM          = "6-05-1013-01",                          // "6-05-1013-01", old code: "1-89 01 01";
                                PHYSICAL_CULTURE = "6-05-1012-01",                          // "6-05-1012-01", old code: "1-88 01 01";
                                REHABILITATION   = "6-05-1012-03",                          // "6-05-1012-03", old code: "1-88 01 03";
                                MANAGEMENT       = "6-05-1012-04";                          // "6-05-1012-04"; old code: "1-88 02 01-02";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "13.00.04",                          // "13.00.04",     old code: "13.00.04",
                                    PHYSIOLOGY       = "03.03.01";                          // "03.03.01";     old code: "03.03.01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "1-89 81 02",                        // "1-89 81 02",   old code: "1-89 81 02",
                                    HOSPITALITY      = "1-89 81 03",                        // "1-89 81 03",   old code: "1-89 81 03",
                                    TECHNOLOGIES     = "1-89 81 04",                        // "1-89 81 04",   old code: "1-89 81 04",
                                    MANAGEMENT       = "1-89 81 01";                        // "1-89 81 01";   old code: "1-89 81 01";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "7-06-1012-01",                      // "7-06-1012-01", old code: "1-08 80 04",
                                    PHYSICAL_CULTURE = "7-06-1012-01",                      // "7-06-1012-01", old code: "1-08 80 04",
                                    TOURISM          = "7-06-1013-01",                      // "7-06-1013-01", old code: "1-89 80 01",
                                    MANAGEMENT       = "7-06-0412-01";                      // "7-06-0412-01"; old code: "1-26 80 04",
                            }
                        }
                    }
                    namespace NAME
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         =
                                    "���������� ������������",
                                TOURISM          =
                                    "������ � ��������������",
                                PHYSICAL_CULTURE =
                                    "���������� ��������",
                                REHABILITATION   =
                                    "���������� ������������ � �����������",
                                MANAGEMENT       =
                                    "����������� � ���������� ���������� "              \
                                    "���������, ������� � ��������";

                            namespace PROFILING
                            {
                                namespace COACH
                                {
                                    const AnsiString
                                        DEFAULT        =
                                            "(� ��������� ���� ������)";
                                }
                                namespace PHYSICAL
                                {
                                    const AnsiString
                                        #ifndef USE_SHORT_NCRB011_2022_PROFILING_NAME
                                            IMPROVING      =
                                                "(��������������� ���������� ��������)",
                                            HEALTH         =
                                                "(�������� ���������� ��������)",
                                            PRESCHOOLERS   =
                                                "(���������� �������� ������������)",
                                            ADAPTIVE       =
                                                "(���������� ���������� ��������)",
                                        #else
                                            IMPROVING      =
                                                "(���������������)",
                                            HEALTH         =
                                                "(��������)",
                                            PRESCHOOLERS   =
                                                "(������������)",
                                            ADAPTIVE       =
                                                "(����������)",
                                        #endif  // USE_SHORT_NCRB011_2022_PROFILING_NAME
                                        DIRECTING      =
                                            "(���������� ���������)",
                                        PSYCHOLOGY     =
                                            "(���������� ����������)",
                                        RECREATIONAL   =
                                            "(���������� � ������������� "              \
                                            "������)";
                                }
                                namespace REHABILITATE
                                {
                                    const AnsiString
                                        REHABILITATION =
                                            "(���������� ������������)",
                                        ERGOTHERAPY    =
                                            "(�����������)";
                                }
                                namespace MANAGE
                                {
                                    const AnsiString
                                        SPORT          =
                                            "(���������� � ������)",
                                        TOURISM        =
                                            "(���������� � �������)";
                                }
                            }
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "������ � �������� ����������� "                \
                                        "����������, ���������� ����������, "           \
                                        "���������������",
                                    PHYSIOLOGY       =
                                        "����������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          =
                                        "������������� ���������� � "                   \
                                        "����� �������",
                                    HOSPITALITY      =
                                        "������������� ���������� � "                   \
                                        "����� ��������������",
                                    TECHNOLOGIES       =
                                        "������������� ���������� � "                   \
                                        "����� ������� � ��������������",
                                    MANAGEMENT       =
                                        "���������� �������������� "                    \
                                        "��������� � ���������� ���������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "T����� � �������� ����������� "                \
                                        "����������, ���������� ����������, "           \
                                        "��������������� � ���������� "                 \
                                        "���������� ��������",
                                    PHYSICAL_CULTURE =
                                        "���������� �������� � �����",
                                    TOURISM          =
                                        "������ � ��������������",
                                    MANAGEMENT       =
                                        "����������";
                            }
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         = "������. �������������",
                                TOURISM          = "����������",
                                PHYSICAL_CULTURE = "����������-��������. �������������",
                                REHABILITATION   = "����������-��������. �������������",
                                MANAGEMENT       = "��������. �������������";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "�������",
                                    PHYSIOLOGY       = "�������";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "������� �������",
                                    HOSPITALITY      = "������� ��������������",
                                    TECHNOLOGIES     = "������� ���������",
                                    MANAGEMENT       = "������� ����������";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "�������",
                                    PHYSICAL_CULTURE = "�������",
                                    TOURISM          = "�������",
                                    MANAGEMENT       = "�������";
                            }
                        }
                    }
                }
            }
            namespace KindOfSport
            {
                // KindOfSportCode::GYMNASTICS;                    // 1,   -> "����������",
                // KindOfSportCode::MANAGEMENT_SPORTS_TOURISM;     // 2,   -> "���������� ������ � �������",
                // KindOfSportCode::PHYSICAL_REHABILITATION;       // 3,   -> "���������� ������������",
                // KindOfSportCode::THERAPEUTIC;                   // 4,   -> "�������� ���������� ��������",
                // KindOfSportCode::ORGANIZATION_SPORTS_TOURISM;   // 5,   -> "����������� ������������-��������������� ������ � �������",
                // KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION;  // 6,   -> "���������� ���������� ����������",
                // KindOfSportCode::DANCE_SPORT;                   // 7,   -> "������������ �����",
                // KindOfSportCode::AEROBICS;                      // 8,   -> "��������",
                // KindOfSportCode::ROWING_OTHER;                  // 9,   -> "������� �����",
                // KindOfSportCode::SWIMMING;                      // 10,  -> "��������",
                // KindOfSportCode::SAILING;                       // 11,  -> "�������� �����",
                // KindOfSportCode::ATHLETICS;                     // 12,  -> "������ ��������",
                // KindOfSportCode::CROSS_COUNTRY_SKIING;          // 13,  -> "������ �����",
                // KindOfSportCode::BULLET_SHOOTING_DEANERY;       // 14,  -> "������� ��������",
                // KindOfSportCode::HAND_TO_HAND_COMBAT;           // 15,  -> "���������� ���",
                // KindOfSportCode::TAEKWONDO;                     // 16,  -> "���������",
                // KindOfSportCode::KARATE;                        // 17,  -> "������",
                // KindOfSportCode::SKIING;                        // 18,  -> "������ �����",
                // KindOfSportCode::AUTOMOTIVE_SPORT;              // 19,  -> "������������� �����",
                // KindOfSportCode::BASKETBALL;                    // 20,  -> "���������",
                // KindOfSportCode::BOXING;                        // 21,  -> "����",
                // KindOfSportCode::GRECO_FREESTYLE_WRESTLING;     // 22,  -> "�����-������� � ������� ������",
                // KindOfSportCode::CYCLING;                       // 23,  -> "������������ �����",
                // KindOfSportCode::VOLLEYBALL;                    // 24,  -> "��������",
                // KindOfSportCode::HANDBALL;                      // 25,  -> "�������",
                // KindOfSportCode::EQUESTRIAN;                    // 26,  -> "������ �����",
                // KindOfSportCode::SPEED_SKATING;                 // 27,  -> "������������ �����",
                // KindOfSportCode::TENNIS;                        // 28,  -> "������",
                // KindOfSportCode::WEIGHTLIFTING;                 // 29,  -> "������� ��������",
                // KindOfSportCode::FENCING;                       // 30,  -> "����������",
                // KindOfSportCode::FIGURE_SKATING;                // 31,  -> FIGURE_SKATING "�������� �������",
                // KindOfSportCode::FOOTBALL;                      // 32,  -> "������",
                // KindOfSportCode::HOCKEY;                        // 33,  -> "������",
                // KindOfSportCode::WRESTLING;                     // 35,  -> "���������� ������",
                // KindOfSportCode::BIATHLON;                      // 37,  -> "�������",
                // KindOfSportCode::HEALTH_IMPROVING;              // 38,  -> "��������������� ���������� ��������",
                // KindOfSportCode::ADAPTIVE;                      // 39,  -> "���������� ���������� ��������",
                // KindOfSportCode::FREESTYLE_WRESTLING;           // 42,  -> "������� ������",
                // KindOfSportCode::GRECO_ROMAN_WRESTLING;         // 43,  -> "�����-������� ������",
                // KindOfSportCode::SAMBO;                         // 44,  -> "�����",
                // KindOfSportCode::JUDO;                          // 45,  -> "�����",
                // KindOfSportCode::TABLE_TENNIS;                  // 46,  -> "������ ����������",
                // KindOfSportCode::ERGOTHERAPY;                   // 47,  -> "�����������",
                // KindOfSportCode::MANAGEMENT_SPORTS;             // 48,  -> "���������� � ������",
                // KindOfSportCode::SPORTS_RECREATIONAL_TOURISM;   // 50,  -> "���������� � ������������� ������",
                // KindOfSportCode::MANAGEMENT_TOURISM;            // 51,  -> "���������� � �������",
                // KindOfSportCode::SPORTS_PSYCHOLOGY;             // 52,  -> "���������� ����������",
                // KindOfSportCode::BILLIARD_SPORTS;               // 53,  -> "���������� �����",
                // KindOfSportCode::ACROBATICS;                    // 54,  -> "����������",
                // KindOfSportCode::ORIENTEERING;                  // 55,  -> "���������� ��������������",
                // KindOfSportCode::SPORTS_DIRECTING;              // 56,  -> "���������� ���������",
                // KindOfSportCode::PRESCHOOLERS;                  // 57,  -> "���������� �������� ������������",
                // KindOfSportCode::MOUNTAINEERING;                // 59,  -> "���������",
                // KindOfSportCode::SKI_COMBINED;                  // 60,  -> "������ ���������",
                // KindOfSportCode::TOURISM_HOSPITALITY;           // 61,  -> "������ � ��������������",
                // KindOfSportCode::WATER_TECHNICAL_SPORTS;        // 62,  -> "�����-����������� ���� ������",
                // KindOfSportCode::MODEL_TECHNICAL_SPORTS;        // 63,  -> "��������-����������� ���� ������",
                // KindOfSportCode::ALPINE_SKIING;                 // 64,  -> "����������� �����",
                // KindOfSportCode::BASEBALL;                      // 65,  -> "�������",
                // KindOfSportCode::WUSHU;                         // 66,  -> "���",
                // KindOfSportCode::CHESS;                         // 68,  -> "�������",
                // KindOfSportCode::THAI_BOXING;                   // 69,  -> "����������� ����",
                // KindOfSportCode::TOURISM_PROMOTION;             // 70,  -> "���������� ������������ � ����������� ������������� �����",
                // KindOfSportCode::TOURISM_IT;                    // 71,  -> "�������������� ���������� ������������� ���������",
                // KindOfSportCode::TOURISM_LOGISTICS;             // 72,  -> "��������� � ������������� ���������",
                // KindOfSportCode::TOURISM_SOCIAL;                // 73,  -> "���������� ���������������� ������� ��������",
                // KindOfSportCode::TOURISM_TRANSPORT;             // 74,  -> "���������� ������������� ������� ��������",
                // KindOfSportCode::TOURISM_FOOD;                  // 75,  -> "���������� ������� ������� ��������",
                // KindOfSportCode::TOURIST_ACCOMMODATION;         // 76,  -> "���������� ������� ���������� ��������",
                // KindOfSportCode::TOURISM_EXCURSION;             // 77,  -> "���������� ������������-����������������� ������� ��������",
                // KindOfSportCode::TOURISM_HEALTH;                // 78,  -> "���������� ������� ������������ � ������� ��������",
                // KindOfSportCode::BULLET_SHOOTING;               // 79,  -> "�������� �������",
                // KindOfSportCode::FIELD_HOCKEY;                  // 80,  -> "������ �� �����",
                // KindOfSportCode::FIGURE_SKATING_SKATES;         // 84,  -> "�������� ������� �� �������",
                // KindOfSportCode::ROWING_AND_CANOEING;           // 87,  -> "������ �� ��������� � �����",
                // KindOfSportCode::ACADEMIC_ROWING;               // 88,  -> "������ �������������",
                // KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS;     // 92,  -> "���������� ��� (��������� ������������)",
                // KindOfSportCode::BILLIARDS;                     // 93,  -> "�������",
                // KindOfSportCode::WITHOUT_SPECIALIZATION;        // 94,  -> "��� �������������",
                // KindOfSportCode::MODERN_PENTATHLON;             // 96,  -> "����������� ���������",
                // KindOfSportCode::SCIENCE_HEALTH;                // 101, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSportCode::PHYSIOLOGY;                    // 102, -> "����������",
                // KindOfSportCode::SCIENCE_THEORY;                // 103, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSportCode::RECEARCH_SPORT;                // 104, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSportCode::INNOVATIVE_TOURISM;            // 105, -> "������������� ���������� � ����� �������",
                // KindOfSportCode::INNOVATIVE_HOSPITALITY;        // 106, -> "������������� ���������� � ����� ��������������",
                // KindOfSportCode::INNOVATIVE_TECHNOLOGIES;       // 107, -> "������������� ���������� � ����� ������� � ��������������",
                // KindOfSportCode::INNOVATIVE_MANAGEMENT;         // 108, -> "���������� �������������� ��������� � ���������� ���������",
                // KindOfSportCode::BADMINTON;                     // 116, -> "���������",
                // KindOfSportCode::PHYSICAL_CULTURE_SPORT;        // 118, -> "���������� �������� � �����",
                // KindOfSportCode::TOURISM_HOSPITALITY_MASTER;    // 119, -> "������ � ��������������",
                // KindOfSportCode::SPORT_CLIMBING;                // 120, -> "������������ ����������",
                // KindOfSportCode::MASTER_ANTHROPOLOGY;           // 121, -> "������������",
                // KindOfSportCode::MASTER_MANAGEMENT;             // 122  -> "����������",
                const AnsiString
                    GYMNASTICS                   =
                        "����������",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "���������� ������ � �������",
                    PHYSICAL_REHABILITATION      =
                        "���������� ������������",
                    THERAPEUTIC                  =
                        "�������� ���������� ��������",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "����������� ������������-��������������� "                     \
                        "������ � �������",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "���������� ���������� ����������",
                    DANCE_SPORT                  =
                        "������������ �����",
                    AEROBICS                     =
                        "��������",
                    ROWING_OTHER                 =
                        "������� �����",
                    SWIMMING                     =
                        "��������",
                    SAILING                      =
                        "�������� �����",
                    ATHLETICS                    =
                        "������ ��������",
                    CROSS_COUNTRY_SKIING         =
                        "������ �����",
                    BULLET_SHOOTING_DEANERY      =
                        "������� ��������",
                    HAND_TO_HAND_COMBAT          =
                        "���������� ���",
                    TAEKWONDO                    =
                        "���������",
                    KARATE                       =
                        "������",
                    SKIING                       =
                        "������ �����",
                    AUTOMOTIVE_SPORT             =
                        "������������� �����",
                    BASKETBALL                   =
                        "���������",
                    BOXING                       =
                        "����",
                    GRECO_FREESTYLE_WRESTLING    =
                        "�����-������� � ������� ������",
                    CYCLING                      =
                        "������������ �����",
                    VOLLEYBALL                   =
                        "��������",
                    HANDBALL                     =
                        "�������",
                    EQUESTRIAN                   =
                        "������ �����",
                    SPEED_SKATING                =
                        "������������ �����",
                    TENNIS                       =
                        "������",
                    WEIGHTLIFTING                =
                        "������� ��������",
                    FENCING                      =
                        "����������",
                    FIGURE_SKATING               =
                        "�������� �������",
                    FOOTBALL                     =
                        "������",
                    HOCKEY                       =
                        "������",
                    WRESTLING                    =
                        "���������� ������",
                    BIATHLON                     =
                        "�������",
                    HEALTH_IMPROVING             =
                        "��������������� ���������� ��������",
                    ADAPTIVE                     =
                        "���������� ���������� ��������",
                    FREESTYLE_WRESTLING          =
                        "������� ������",
                    GRECO_ROMAN_WRESTLING        =
                        "�����-������� ������",
                    SAMBO                        =
                        "�����",
                    JUDO                         =
                        "�����",
                    TABLE_TENNIS                 =
                        "������ ����������",
                    ERGOTHERAPY                  =
                        "�����������",
                    MANAGEMENT_SPORTS            =
                        "���������� � ������",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "���������� � ������������� ������",
                    MANAGEMENT_TOURISM           =
                        "���������� � �������",
                    SPORTS_PSYCHOLOGY            =
                        "���������� ����������",
                    BILLIARD_SPORTS              =
                        "���������� �����",
                    ACROBATICS                   =
                        "����������",
                    ORIENTEERING                 =
                        "���������� ��������������",
                    SPORTS_DIRECTING             =
                        "���������� ���������",
                    PRESCHOOLERS                 =
                        "���������� �������� ������������",
                    MOUNTAINEERING               =
                        "���������",
                    SKI_COMBINED                 =
                        "������ ���������",
                    TOURISM_HOSPITALITY          =
                        "������ � ��������������",
                    WATER_TECHNICAL_SPORTS       =
                        "�����-����������� ���� ������",
                    MODEL_TECHNICAL_SPORTS       =
                        "��������-����������� ���� ������",
                    ALPINE_SKIING                =
                        "����������� �����",
                    BASEBALL                     =
                        "�������",
                    WUSHU                        =
                        "���",
                    CHESS                        =
                        "�������",
                    THAI_BOXING                  =
                        "����������� ����",
                    TOURISM_PROMOTION            =
                        "���������� ������������ � ����������� "                        \
                        "������������� �����",
                    TOURISM_IT                   =
                        "�������������� ���������� ������������� "                      \
                        "���������",
                    TOURISM_LOGISTICS            =
                        "��������� � ������������� ���������",
                    TOURISM_SOCIAL               =
                        "���������� ���������������� ������� "                          \
                        "��������",
                    TOURISM_TRANSPORT            =
                        "���������� ������������� ������� ��������",
                    TOURISM_FOOD                 =
                        "���������� ������� ������� ��������",
                    TOURIST_ACCOMMODATION        =
                        "���������� ������� ���������� ��������",
                    TOURISM_EXCURSION            =
                        "���������� ������������-����������������� "                    \
                        "������� ��������",
                    TOURISM_HEALTH               =
                        "���������� ������� ������������ � ������� "                    \
                        "��������",
                    BULLET_SHOOTING              =
                        "�������� �������",
                    FIELD_HOCKEY                 =
                        "������ �� �����",
                    FIGURE_SKATING_SKATES        =
                        "�������� ������� �� �������",
                    ROWING_AND_CANOEING          =
                        "������ �� ��������� � �����",
                    ACADEMIC_ROWING              =
                        "������ �������������",
                    HAND_TO_HAND_MARTIAL_ARTS    =
                        "���������� ��� (��������� ������������)",
                    BILLIARDS                    =
                        "�������",
                    WITHOUT_SPECIALIZATION       =
                        "��� �������������",
                    MODERN_PENTATHLON            =
                        "����������� ���������",
                    SCIENCE_HEALTH               =
                        "������ � �������� ����������� ����������, "                    \
                        "���������� ����������, ���������������",
                    PHYSIOLOGY                   =
                        "����������",
                    SCIENCE_THEORY               =
                        "������ � �������� ����������� ����������, "                    \
                        "���������� ����������, ���������������",
                    RECEARCH_SPORT               =
                        "������ � �������� ����������� ����������, "                    \
                        "���������� ����������, ���������������",
                    INNOVATIVE_TOURISM           =
                        "������������� ���������� � ����� �������",
                    INNOVATIVE_HOSPITALITY       =
                        "������������� ���������� � ����� ��������������",
                    INNOVATIVE_TECHNOLOGIES      =
                        "������������� ���������� � ����� ������� "                     \
                        "� ��������������",
                    INNOVATIVE_MANAGEMENT        =
                        "���������� �������������� ��������� � "                        \
                        "���������� ���������",
                    BADMINTON                    =
                        "���������",
                    PHYSICAL_CULTURE_SPORT       =
                        "���������� �������� � �����",
                    TOURISM_HOSPITALITY_MASTER   =
                        "������ � ��������������",
                    SPORT_CLIMBING               =
                        "������������ ����������",
                    MASTER_ANTHROPOLOGY          =
                        "������������",
                    MASTER_MANAGEMENT            =
                        "����������";

                // KindOfSport::DATIVE_CASE::GYMNASTICS;                                    // "����������",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS_TOURISM;                     // "����������� ������ � �������",
                // KindOfSport::DATIVE_CASE::PHYSICAL_REHABILITATION;                       // "���������� ������������",
                // KindOfSport::DATIVE_CASE::THERAPEUTIC;                                   // "�������� ���������� ��������",
                // KindOfSport::DATIVE_CASE::ORGANIZATION_SPORTS_TOURISM;                   // "����������� ������������-��������������� ������ � �������",
                // KindOfSport::DATIVE_CASE::PRESCHOOL_PHYSICAL_EDUCATION;                  // "����������� ����������� ����������",
                // KindOfSport::DATIVE_CASE::DANCE_SPORT;                                   // "������������� ������",
                // KindOfSport::DATIVE_CASE::AEROBICS;                                      // "��������",
                // KindOfSport::DATIVE_CASE::ROWING_OTHER;                                  // "�������� ������",
                // KindOfSport::DATIVE_CASE::SWIMMING;                                      // "��������",
                // KindOfSport::DATIVE_CASE::SAILING;                                       // "��������� ������",
                // KindOfSport::DATIVE_CASE::ATHLETICS;                                     // "������ ��������",
                // KindOfSport::DATIVE_CASE::CROSS_COUNTRY_SKIING;                          // "������ ������",
                // KindOfSport::DATIVE_CASE::BULLET_SHOOTING_DEANERY;                       // "������� ��������",
                // KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT;                           // "����������� ���",
                // KindOfSport::DATIVE_CASE::TAEKWONDO;                                     // "���������",
                // KindOfSport::DATIVE_CASE::KARATE;                                        // "������",
                // KindOfSport::DATIVE_CASE::SKIING;                                        // "������� ������",
                // KindOfSport::DATIVE_CASE::AUTOMOTIVE_SPORT;                              // "�������������� ������",
                // KindOfSport::DATIVE_CASE::BASKETBALL;                                    // "����������",
                // KindOfSport::DATIVE_CASE::BOXING;                                        // "�����",
                // KindOfSport::DATIVE_CASE::GRECO_FREESTYLE_WRESTLING;                     // "�����-������� � ������� ������",
                // KindOfSport::DATIVE_CASE::CYCLING;                                       // "������������� ������",
                // KindOfSport::DATIVE_CASE::VOLLEYBALL;                                    // "���������",
                // KindOfSport::DATIVE_CASE::HANDBALL;                                      // "��������",
                // KindOfSport::DATIVE_CASE::EQUESTRIAN;                                    // "������� ������",
                // KindOfSport::DATIVE_CASE::SPEED_SKATING;                                 // "������������� ������",
                // KindOfSport::DATIVE_CASE::TENNIS;                                        // "�������",
                // KindOfSport::DATIVE_CASE::WEIGHTLIFTING;                                 // "������� ��������",
                // KindOfSport::DATIVE_CASE::FENCING;                                       // "����������",
                // KindOfSport::DATIVE_CASE::FIGURE_SKATING;                                // "��������� �������",
                // KindOfSport::DATIVE_CASE::FOOTBALL;                                      // "�������",
                // KindOfSport::DATIVE_CASE::HOCKEY;                                        // "������",
                // KindOfSport::DATIVE_CASE::WRESTLING;                                     // "���������� ������",
                // KindOfSport::DATIVE_CASE::BIATHLON;                                      // "��������",
                // KindOfSport::DATIVE_CASE::HEALTH_IMPROVING;                              // "��������������� ���������� ��������",
                // KindOfSport::DATIVE_CASE::ADAPTIVE;                                      // "���������� ���������� ��������",
                // KindOfSport::DATIVE_CASE::FREESTYLE_WRESTLING;                           // "������� ������",
                // KindOfSport::DATIVE_CASE::GRECO_ROMAN_WRESTLING;                         // "�����-������� ������",
                // KindOfSport::DATIVE_CASE::SAMBO;                                         // "�����",
                // KindOfSport::DATIVE_CASE::JUDO;                                          // "�����",
                // KindOfSport::DATIVE_CASE::TABLE_TENNIS;                                  // "������� �����������",
                // KindOfSport::DATIVE_CASE::ERGOTHERAPY;                                   // "�����������",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS;                             // "����������� � ������",
                // KindOfSport::DATIVE_CASE::SPORTS_RECREATIONAL_TOURISM;                   // "����������� � �������������� �������",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_TOURISM;                            // "����������� � �������",
                // KindOfSport::DATIVE_CASE::SPORTS_PSYCHOLOGY;                             // "���������� ����������",
                // KindOfSport::DATIVE_CASE::BILLIARD_SPORTS;                               // "����������� ������",
                // KindOfSport::DATIVE_CASE::ACROBATICS;                                    // "����������",
                // KindOfSport::DATIVE_CASE::ORIENTEERING;                                  // "����������� ��������������",
                // KindOfSport::DATIVE_CASE::SPORTS_DIRECTING;                              // "���������� ���������",
                // KindOfSport::DATIVE_CASE::PRESCHOOLERS;                                  // "���������� �������� ������������",
                // KindOfSport::DATIVE_CASE::MOUNTAINEERING;                                // "����������",
                // KindOfSport::DATIVE_CASE::SKI_COMBINED;                                  // "������� ���������",
                // KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY;                           // "������� � ��������������",
                // KindOfSport::DATIVE_CASE::WATER_TECHNICAL_SPORTS;                        // "�����-����������� ����� ������",
                // KindOfSport::DATIVE_CASE::MODEL_TECHNICAL_SPORTS;                        // "��������-����������� ����� ������",
                // KindOfSport::DATIVE_CASE::ALPINE_SKIING;                                 // "������������ ������",
                // KindOfSport::DATIVE_CASE::BASEBALL;                                      // "��������",
                // KindOfSport::DATIVE_CASE::WUSHU;                                         // "���",
                // KindOfSport::DATIVE_CASE::CHESS;                                         // "��������",
                // KindOfSport::DATIVE_CASE::THAI_BOXING;                                   // "������������ �����",
                // KindOfSport::DATIVE_CASE::TOURISM_PROMOTION;                             // "����������� ������������ � ����������� ������������� �����",
                // KindOfSport::DATIVE_CASE::TOURISM_IT;                                    // "�������������� ����������� ������������� ���������",
                // KindOfSport::DATIVE_CASE::TOURISM_LOGISTICS;                             // "��������� � ������������� ���������",
                // KindOfSport::DATIVE_CASE::TOURISM_SOCIAL;                                // "����������� ���������������� ������� ��������",
                // KindOfSport::DATIVE_CASE::TOURISM_TRANSPORT;                             // "����������� ������������� ������� ��������",
                // KindOfSport::DATIVE_CASE::TOURISM_FOOD;                                  // "����������� ������� ������� ��������",
                // KindOfSport::DATIVE_CASE::TOURIST_ACCOMMODATION;                         // "����������� ������� ���������� ��������",
                // KindOfSport::DATIVE_CASE::TOURISM_EXCURSION;                             // "����������� ������������-����������������� ������� ��������",
                // KindOfSport::DATIVE_CASE::TOURISM_HEALTH;                                // "����������� ������� ������������ � ������� ��������",
                // KindOfSport::DATIVE_CASE::BULLET_SHOOTING;                               // "�������� �������",
                // KindOfSport::DATIVE_CASE::FIELD_HOCKEY;                                  // "������ �� �����",
                // KindOfSport::DATIVE_CASE::FIGURE_SKATING_SKATES;                         // "��������� ������� �� �������",
                // KindOfSport::DATIVE_CASE::ROWING_AND_CANOEING;                           // "������ �� ��������� � �����",
                // KindOfSport::DATIVE_CASE::ACADEMIC_ROWING;                               // "������ �������������",
                // KindOfSport::DATIVE_CASE::HAND_TO_HAND_MARTIAL_ARTS;                     // "����������� ��� (��������� ������������)",
                // KindOfSport::DATIVE_CASE::BILLIARDS;                                     // "��������",
                // KindOfSport::DATIVE_CASE::WITHOUT_SPECIALIZATION;                        // "��� �������������",
                // KindOfSport::DATIVE_CASE::MODERN_PENTATHLON;                             // "������������ ���������",
                // KindOfSport::DATIVE_CASE::SCIENCE_HEALTH;                                // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSport::DATIVE_CASE::PHYSIOLOGY;                                    // "����������",
                // KindOfSport::DATIVE_CASE::SCIENCE_THEORY;                                // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSport::DATIVE_CASE::RECEARCH_SPORT;                                // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_TOURISM;                            // "�������������� ����������� � ����� �������",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_HOSPITALITY;                        // "�������������� ����������� � ����� ��������������",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_TECHNOLOGIES;                       // "������������� ����������� � ����� ������� � ��������������",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_MANAGEMENT;                         // "���������� �������������� ��������� � ���������� ���������",
                // KindOfSport::DATIVE_CASE::BADMINTON;                                     // "����������",
                // KindOfSport::DATIVE_CASE::PHYSICAL_CULTURE_SPORT;                        // "���������� �������� � ������",
                // KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY_MASTER;                    // "������� � ��������������",
                // KindOfSport::DATIVE_CASE::SPORT_CLIMBING;                                // "����������� ������������",
                // KindOfSport::DATIVE_CASE::MASTER_ANTHROPOLOGY;                           // "������������",
                // KindOfSport::DATIVE_CASE::MASTER_MANAGEMENT;                             // "�����������";
                namespace DATIVE_CASE
                {
                    const AnsiString
                        GYMNASTICS                   =
                            "����������",
                        MANAGEMENT_SPORTS_TOURISM    =
                            "����������� ������ � �������",
                        PHYSICAL_REHABILITATION      =
                            "����������� ������������",
                        THERAPEUTIC                  =
                            "�������� ���������� ��������",
                        ORGANIZATION_SPORTS_TOURISM  =
                            "����������� ������������-��������������� "                 \
                            "������ � �������",
                        PRESCHOOL_PHYSICAL_EDUCATION =
                            "����������� ����������� ����������",
                        DANCE_SPORT                  =
                            "������������� ������",
                        AEROBICS                     =
                            "��������",
                        ROWING_OTHER                 =
                            "�������� ������",
                        SWIMMING                     =
                            "��������",
                        SAILING                      =
                            "��������� ������",
                        ATHLETICS                    =
                            "������ ��������",
                        CROSS_COUNTRY_SKIING         =
                            "������ ������",
                        BULLET_SHOOTING_DEANERY      =
                            "������� ��������",
                        HAND_TO_HAND_COMBAT          =
                            "����������� ���",
                        TAEKWONDO                    =
                            "���������",
                        KARATE                       =
                            "������",
                        SKIING                       =
                            "������� ������",
                        AUTOMOTIVE_SPORT             =
                            "�������������� ������",
                        BASKETBALL                   =
                            "����������",
                        BOXING                       =
                            "�����",
                        GRECO_FREESTYLE_WRESTLING    =
                            "�����-������� � ������� ������",
                        CYCLING                      =
                            "������������� ������",
                        VOLLEYBALL                   =
                            "���������",
                        HANDBALL                     =
                            "��������",
                        EQUESTRIAN                   =
                            "������� ������",
                        SPEED_SKATING                =
                            "������������� ������",
                        TENNIS                       =
                            "�������",
                        WEIGHTLIFTING                =
                            "������� ��������",
                        FENCING                      =
                            "����������",
                        FIGURE_SKATING               =
                            "��������� �������",
                        FOOTBALL                     =
                            "�������",
                        HOCKEY                       =
                            "������",
                        WRESTLING                    =
                            "���������� ������",
                        BIATHLON                     =
                            "��������",
                        HEALTH_IMPROVING             =
                            "��������������� ���������� ��������",
                        ADAPTIVE                     =
                            "���������� ���������� ��������",
                        FREESTYLE_WRESTLING          =
                            "������� ������",
                        GRECO_ROMAN_WRESTLING        =
                            "�����-������� ������",
                        SAMBO                        =
                            "�����",
                        JUDO                         =
                            "�����",
                        TABLE_TENNIS                 =
                            "������� �����������",
                        ERGOTHERAPY                  =
                            "�����������",
                        MANAGEMENT_SPORTS            =
                            "����������� � ������",
                        SPORTS_RECREATIONAL_TOURISM  =
                            "����������� � �������������� �������",
                        MANAGEMENT_TOURISM           =
                            "����������� � �������",
                        SPORTS_PSYCHOLOGY            =
                            "���������� ����������",
                        BILLIARD_SPORTS              =
                            "����������� ������",
                        ACROBATICS                   =
                            "����������",
                        ORIENTEERING                 =
                            "����������� ��������������",
                        SPORTS_DIRECTING             =
                            "���������� ���������",
                        PRESCHOOLERS                 =
                            "���������� �������� ������������",
                        MOUNTAINEERING               =
                            "����������",
                        SKI_COMBINED                 =
                            "������� ���������",
                        TOURISM_HOSPITALITY          =
                            "������� � ��������������",
                        WATER_TECHNICAL_SPORTS       =
                            "�����-����������� ����� ������",
                        MODEL_TECHNICAL_SPORTS       =
                            "��������-����������� ����� ������",
                        ALPINE_SKIING                =
                            "������������ ������",
                        BASEBALL                     =
                            "��������",
                        WUSHU                        =
                            "���",
                        CHESS                        =
                            "��������",
                        THAI_BOXING                  =
                            "������������ �����",
                        TOURISM_PROMOTION            =
                            "����������� ������������ � ����������� "                   \
                            "������������� �����",
                        TOURISM_IT                   =
                            "�������������� ����������� ������������� "                 \
                            "���������",
                        TOURISM_LOGISTICS            =
                            "��������� � ������������� ���������",
                        TOURISM_SOCIAL               =
                            "����������� ���������������� ������� "                     \
                            "��������",
                        TOURISM_TRANSPORT            =
                            "����������� ������������� ������� ��������",
                        TOURISM_FOOD                 =
                            "����������� ������� ������� ��������",
                        TOURIST_ACCOMMODATION        =
                            "����������� ������� ���������� ��������",
                        TOURISM_EXCURSION            =
                            "����������� ������������-����������������� "               \
                            "������� ��������",
                        TOURISM_HEALTH               =
                            "����������� ������� ������������ � ������� "               \
                            "��������",
                        BULLET_SHOOTING              =
                            "�������� �������",
                        FIELD_HOCKEY                 =
                            "������ �� �����",
                        FIGURE_SKATING_SKATES        =
                            "��������� ������� �� �������",
                        ROWING_AND_CANOEING          =
                            "������ �� ��������� � �����",
                        ACADEMIC_ROWING              =
                            "������ �������������",
                        HAND_TO_HAND_MARTIAL_ARTS    =
                            "����������� ��� (��������� �������������)",
                        BILLIARDS                    =
                            "��������",
                        WITHOUT_SPECIALIZATION       =
                            "��� �������������",
                        MODERN_PENTATHLON            =
                            "������������ ���������",
                        SCIENCE_HEALTH               =
                            "������ � �������� ����������� ����������, "                \
                            "���������� ����������, ���������������",
                        PHYSIOLOGY                   =
                            "����������",
                        SCIENCE_THEORY               =
                            "������ � �������� ����������� ����������, "                \
                            "���������� ����������, ���������������",
                        RECEARCH_SPORT               =
                            "������ � �������� ����������� ����������, "                \
                            "���������� ����������, ���������������",
                        INNOVATIVE_TOURISM           =
                            "�������������� ����������� � ����� �������",
                        INNOVATIVE_HOSPITALITY       =
                            "�������������� ����������� � ����� ��������������",
                        INNOVATIVE_TECHNOLOGIES      =
                            "������������� ����������� � ����� ������� "                \
                            "� ��������������",
                        INNOVATIVE_MANAGEMENT        =
                            "���������� �������������� ��������� � "                    \
                            "���������� ���������",
                        BADMINTON                    =
                            "����������",
                        PHYSICAL_CULTURE_SPORT       =
                            "���������� �������� � ������",
                        TOURISM_HOSPITALITY_MASTER   =
                            "������� � ��������������",
                        SPORT_CLIMBING               =
                            "����������� ������������",
                        MASTER_ANTHROPOLOGY          =
                            "������������",
                        MASTER_MANAGEMENT            =
                            "�����������";
                }
            }
        #endif  // ! DATABASE_SUBSTITUTE
    #endif // ! NEW_INTEGRATION
#else                                       // CHECKED!!!
    namespace Admissions
    {
        namespace TIME
        {
            const AnsiString
                YEAR                 = "2023";
        }
        namespace INVENTORY
        {
            const AnsiString
                #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                DATE                 =
                    "01.06.2023";
                #else
                DATE                 =
                    (Now ())
                        .FormatString (
                            "dd.mm.yyyy"
                        );
                #endif  // SET_INVENTORY_DATE_BY_HAND
        }
        namespace DEADLINE
        {
            const AnsiString
                FOR_RECEIVING_PART_1 = "05.06.2023 6:00:00",
                FOR_RECEIVING_PART_2 = "10.08.2023 6:00:00";
        }
        namespace ADDITIONAL
        {
            const AnsiString
                ORDER_DATE_PART_1    = "04.06.2023",
                ORDER_DATE_PART_2    = "08.08.2023";
        }
        namespace DOCUMENTS
        {
            const AnsiString
                PROVIDE_DATE = "15.06.2023";
        }
        namespace ARRIVAL
        {
            namespace TIME
            {
                const AnsiString
                    EVERYONE = "9:00";
            }
            namespace DATE
            {
                namespace INTRAMURAL
                {
                    const AnsiString
                        ALL = "01.09.2023";
                }
                namespace EXTRAMURAL
                {
                    namespace FULL
                    {
                        const AnsiString
                            MSTH  = "05.09.2023.",
                            OTHER = "12.09.2023.";
                    }
                    namespace SHORT
                    {
                        const AnsiString
                            SMA   = "03.10.2023.",
                            MS    = "05.10.2023.",
                            RPC   = "07.10.2023.",
                            MSTH  = "24.10.2023.";
                    }
                }
            }
        }
    }
    namespace ContestType
    {
        const AnsiString
            GENERAL                = "�����",
            WITHOUT_ENTRANCE_EXAMS = "��� ������������� ���������",
            OUT_OF_COMPETITION     = "��� ��������",
            TARGETED_TRAINING      = "�������";
    }
    namespace Contract
    {
        namespace DOCUMENT_FILE
        {
            const AnsiString
                BUDGET  = "������� - ������.xls",
                BUYERS  = "������� - ��������.xls";
        }
        namespace DOCUMENT_NAME
        {
            const AnsiString
                BUDGET = "������� - ������",
                BUYERS = "������� - ��������";
        }
        namespace BSUPC
        {
            const AnsiString
                PERSON = "������� ��������� �������������";                         // Old name: CONTRACT_SIDE_BSUPC_MAIN

            namespace BASE_DOCUMENT
            {
                const AnsiString
                    NAME   = "������������",                                        // Old name: CONTRACT_TYPE_POWER_DOC_MAIN
                    DATE   = "16.11.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_MAIN
                    NUMBER = "13-16-45";                                            // Old name: CONTRACT_POWER_DOC_NO_MAIN
            }
        }
        namespace IMS
        {
            const AnsiString
                PERSON = "���������� ����� ����������";                             // Old name: CONTRACT_SIDE_BSUPC_IMST

            namespace BASE_DOCUMENT
            {
                const AnsiString
                    NAME   = "������������",                                        // Old name: CONTRACT_TYPE_POWER_DOC_IMST
                    DATE   = "26.10.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_IMST
                    NUMBER = "13-16-42";                                            // Old name: CONTRACT_POWER_DOC_NO_IMST
            }
        }
        namespace PAYMENT_TERM
        {
            const AnsiString
                FIRST_SEMESTER  =
                    "�� 31.08.2023 (������������) � �� ������ "              \
                    "������� ������� ���� �������� � �������",
                SECOND_SEMESTER =
                    "� 01.02.2024 �� 01.03.2024 � �� ������ "               \
                    "������� ������� ���� �������� � �������";
        }
        namespace COST_FOR
        {
            namespace BUDGET
            {
                namespace INTRAMURAL
                {
                    const AnsiString
                        FULL_COURSE   =                                             // ������, �������, ������ ����
                            "���������� ���������� �������� "               \
                            "���������� 32830,32 ("                         \
                            "�������� ��� ������ ��������� �������� "       \
                            "������ 32 �������) ����������� ������.",
                        SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                            "���������� ���������� �������� "               \
                            "���������� 24622,74 ("                         \
                            "�������� ������ ������ �������� �������� ��� " \
                            "����� 74 �������) ����������� ������.";
                }
                namespace EXTRAMURAL
                {
                    const AnsiString
                        FULL_COURSE   =                                             // ������, �������, ������ ����
                            "���������� ���������� �������� "               \
                            "���������� 16415,15 ("                         \
                            "����������� ����� ��������� ���������� "       \
                            "������ 15 ������) ����������� ������.",
                        SECOND_COURSE =                                             // ������, �������, �����٨���� ���� (2 ����)
                            "���������� ���������� �������� "               \
                            "���������� 13132,12 ("                         \
                            "���������� ����� ��� �������� ��� "            \
                            "����� 12 ������) ����������� ������.",
                        THIRD_COURSE  =                                             // ������, �������, �����٨���� ���� (3 ����)
                            "���������� ���������� �������� "               \
                            "���������� 9849,09 ("                          \
                            "������ ����� ��������� ����� ������ "          \
                            "������ 09 ������) ����������� ������.";
                }
            }
            namespace BUYERS
            {
                namespace INTRAMURAL
                {
                    const AnsiString                                                // ��������, �������, �� ���
                        ANNUAL       =
                            "���������� 2748 ("                             \
                            "��� ������ ������� ����� ������"               \
                            ") ����������� ������ "                         \
                            "�� ������ ��� ��������.",
                        PER_SEMESTER =                                              // ��������, �������, �� ���������
                            "1374 ("                                        \
                            "���� ������ ������ ��������� ������"           \
                            ") ����������� ������;";
                }
                namespace EXTRAMURAL
                {
                    const AnsiString
                        ANNUAL           =                                          // ��������, �������, �� ��� (����, ���, ���)
                            "���������� 1065 ("                             \
                            "���� ������ ���������� ����"                   \
                            ") ����������� ������ "                         \
                            "�� ������ ��� ��������.",
                        ANNUAL_IMS       =                                          // ��������, �������, �� ��� (�����)
                            "���������� 1135 ("                             \
                            "���� ������ ��� �������� ����"                 \
                            ") ����������� ������ "                         \
                            "�� ������ ��� ��������.",
                        PER_SEMESTER     =                                          // ��������, �������, �� ��������� (����, ���, ���)
                            "532,50 ("                                      \
                            "������� �������� ��� "                         \
                            "����� 50 ������) ����������� ������;",
                        PER_SEMESTER_IMS =                                          // ��������, �������, �� ��������� (�����)
                            "567,50 ("                                      \
                            "������� ���������� ���� "                      \
                            "������ 50 ������) ����������� ������;";
                }
            }
        }
    }
    namespace DocumentFile
    {
        namespace APPLICATION_FOR
        {
            const AnsiString
                PARTICIPATION       = "��������� - ������ � �������.xls";
        }
        namespace LIST
        {
            const AnsiString
                GROUPS              = "������ - �����.xls";                         // NEW (������.xls -> ������ - �����.xls)
        }
        namespace PROTOCOL
        {
            AnsiString
                admitted            = "�������� - � ������� ������������.doc",      // NEW (OLE Issue) DELETE YEAR
                daily               = "�������� - ����������.xls",
                exam                = "�������� - ������� �� ����.xls";
            const AnsiString
                GIRLS_TESTS         = "�������� - ��������� (�������).xls";
        }
        namespace REGISTRY
        {
            const AnsiString
                BOOK                = "������ - �����������.xls";
        }
        namespace REPORT
        {
            const AnsiString
                FORM_1              = "����� - ����� 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                FORM_2              = "����� - ����� 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                SUBMITTED           = "����� - ������ ���������.xls";
        }
        namespace STATISTIC
        {
            AnsiString
                cert_result_hundred =
                    "���������� - ���������� ������������ (�����������).xls",
                cert_result_ten     =
                    "���������� - ���������� ������������ (��������������).xls",    // (REQUIRE CHECK Range)
                exam_result         =
                    "���������� - ���������� ����� ���������.xls";
            const AnsiString
                ADMISSION_PROGRESS  =
                    "���������� - ��� ������.xls",                                  // NEW
                CONTEST             =
                    "���������� - �������.xls",                                     // NEW DELETE YEAR
                DAILY               =
                    "���������� - ����������.xls",
                LEVEL_OF_SPORTS     =
                    "���������� - ������� ���������� ����������.xls",
                SCORES              =
                    "���������� - �����.xls";                                       // NEW (INSTEAD USEING Abitur_RIO) DELETE YEAR
        }
        namespace SUMMARY_LIST
        {
            const AnsiString
                ENROLLMENT          = "��������� - ����������.xls",                 // NEW
                ENTRANCE_EXAMS      = "��������� - ������������� ���������.xls";    // NEW DELETE YEAR
        }
    }
    namespace DocumentName
    {
        namespace APPLICATION_FOR
        {
            const AnsiString
                PARTICIPATION      = "��������� - ������ � �������";
        }
        namespace LIST
        {
            const AnsiString
                GROUPS             = "������ - �����",                              // NEW (������ -> ������ - �����)
                BY_DESTINATIONS    = "������ - �� ������������",                    // NEW
                BY_GENDER          = "������ - �� ����";                            // NEW
        }
        namespace PROTOCOL
        {
            AnsiString
                daily              = "�������� - ����������",
                exam               = "�������� - ������� �� ����";
            const AnsiString
                GIRLS_TESTS        = "�������� - ��������� (�������)";
        }
        namespace REGISTRY
        {
            const AnsiString
                BOOK               = "������ - �����������";
        }
        namespace REPORT
        {
            const AnsiString
                FORM_1             = "����� - ����� 1",
                FORM_2             = "����� - ����� 2",
                SUBMITTED          = "����� - ������ ���������";                    // (REQUIRE CHECK Calcalation)
        }
        namespace STATISTIC
        {
            const AnsiString
                ADMISSION_PROGRESS =
                    "���������� - ��� ������",                                      // NEW
                CONTEST            =
                    "���������� - �������",
                DAILY              =
                    "���������� - ����������",
                LEVEL_OF_SPORTS    =
                    "���������� - ������� ���������� ����������",
                SCORES             =
                    "���������� - �����";                                           // INSTEAD USEING Abitur_RIO
        }
        namespace SUMMARY_LIST
        {
            const AnsiString
                ENROLLMENT         = "��������� - ����������",                      // NEW
                ENTRANCE_EXAMS     = "��������� - ������������� ���������";
        }
    }
    namespace EducationType
    {
        const AnsiString
            EXTRAMURAL = "�������",
            INTRAMURAL = "�������",
            EXTRA_FORM = "�������",
            INTRA_FORM = "�������";
    }
    namespace EnvelopeMessage
    {
        namespace BUDGET
        {
            const AnsiString
                EXTRAMURAL = "������, ������� ����� ��������",
                INTRAMURAL = "������, ������� ����� ��������";
        }
        namespace BUYERS
        {
            const AnsiString
                EXTRAMURAL = "�� ������, ������� ����� ��������",
                INTRAMURAL = "�� ������, ������� ����� ��������";
        }
    }
    namespace Faculty
    {
        const AnsiString
            SMA  = "����",                                                          // 1, -> Sports and Marital Arts (����)
            MS   = "���",                                                           // 2, -> Mass Sports (���)
            RPC  = "���",                                                           // 3, -> Recreational Physical Culture (�����)
            MSTH = "�����",                                                         // 4, -> Management of Sports, Tourism and Hospitality (����)
            MD   = "�����������",                                                   // 5, -> Master's Degree (�����������)
            PGS  = "�����������",                                                   // 6, -> PostGraduate Studies (�����������)
            DOC  = "������������";                                                  // 7  -> DOCtorate (������������)
    }
    namespace LegallyAuthorizedPerson
    {
        AnsiString
            edu_head_desc  = "�������� �.�.";
        const AnsiString
            DEAN_FACULTY_1 = "�.�.��������",                                        // ����  (SMA)  - Sports and Marital Arts
            DEAN_FACULTY_2 = "�.�.����������",                                      // ���   (MS)   - Mass Sports
            DEAN_FACULTY_3 = "�.�.���������",                                       // ����� (RPC)  - Recreational Physical Culture
            DEAN_FACULTY_4 = "�.�.���������",                                       // ����  (MSTH) - Management of Sports, Tourism and Hospitality
            SECRETARY      = "�.�. �����",
            SECRETARY_DESC = "����� �.�.",
            VICE_RECTOR    = "�.�.������";
    }

    namespace DeaneryDB
    {
        namespace QUALIFICATION
        {
            const AnsiString
                TEACHER_PHYSICAL_CULTURE_SPORTS  =
                    "������������� ���������� �������� � ������",
                COACHING_BY_SPORT                =
                    "������ �� ���� ������",
                PHYSICAL_EDUCATION_TEACHER       =
                    "������� ���������� ��������",
                TEACHER_ORGANIZER_HEALTH_TOURISM =
                    "�������-����������� ������������-��������������� "     \
                    "������ � �������",
                TEACHER_ORGANIZER_PRESCHOOLERS   =
                    "�������-����������� ����������� ���������� � "         \
                    "���������� �����������",
                MANAGER_SPORT_TOURISM            =
                    "�������� ������ � �������",
                INSTRUCTOR_REHABILITATION        =
                    "����������-�������� ���������� ������������",
                INSTRUCTOR_MEDICAL               =
                    "����������-�������� �������� ���������� ��������",
                TEACHER_PHYSICAL_CULTURE         =
                    "������������� ���������� ��������",
                INSTRUCTOR_BY_HEALTH             =
                    "����������-�������� �� ��������������� ���������� "    \
                    "��������",
                INSTRUCTOR_BY_ADAPTIVE           =
                    "����������-�������� �� ���������� ���������� "         \
                    "��������",
                INSTRUCTOR_PRESCHOOLERS          =
                    "����������-�������� ����������� ���������� � "         \
                    "���������� �����������",
                PSYCHOLOGIST                     =
                    "��������",
                MANAGER_SPORT                    =
                    "�������� � ������",
                MANAGER_TUORISM                  =
                    "�������� �� �������",
                INSTRUCTOR_RECREATIONAL          =
                    "����������-�������� �� �������",
                MANAGER_DIRECTING                =
                    "��������-�������� ���������-�������� �����������",
                INSTRUCTOR_BY_MEDICAL            =
                    "����������-�������� �� �������� ���������� ��������",
                INSTRUCTOR_BY_REHABILITATION     =
                    "����������-�������� �� ���������� ������������",
                INSTRUCTOR_BY_ERGOTHERAPY        =
                    "����������-�������� �� �����������",
                SPECIALIST_TOURISM_HOSPITALITY   =
                    "���������� � ����� ������� � ��������������";
        }
    }
    namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
    {
        namespace _2009
        {
            namespace CODE
            {
                namespace PART
                {
                    const AnsiString
                        BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                        PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                        PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                        COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                        PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                        TOURISM_HOSPITALITY            = "1-89";
                }
                namespace CHAPTER
                {
                    const AnsiString
                        PHYSIOLOGY                     = "03.03.01",                // Master degree
                        THEORY_IMPROVING               = "13.00.04",                // Master degree
                        RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                        MANAGEMENT                     = "1-26 80",                 // Master degree
                        PHYSICAL_CULTURE               = "1-88 01",
                        SPORT                          = "1-88 02",
                        TOURISM_HOSPITALITY            = "1-89 01",
                        TOURISM                        = "1-89 02",
                        HOSPITALITY                    = "1-89 03",
                        RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                        INNOVATION                     = "1-89 81";                 // Master degree
                }
                namespace SECTION
                {
                    const AnsiString
                        RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                        RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                        PHYSICAL_CULTURE               = "1-88 01 01",
                        IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                        REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                        TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                        SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                        SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                        TOURISM_HOSPITALITY            = "1-89 01 01",
                        SPORTS_AND_TOURISM             = "1-89 02 01",
                        TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                        HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                        RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                        INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                        INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                        INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                        INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                }
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL                       = "1-88 01 01-01",
                        PRESCHOOLERS                  = "1-88 01 01-02",
                        HEALTH                        = "1-88 01 02-01",
                        ADAPTIVE                      = "1-88 01 02-02",
                        REHABILITATION                = "1-88 01 03-01",
                        ERGOTHERAPY                   = "1-88 01 03-02",
                        COACHING                      = "1-88 02 01-01",
                        MANAGEMENT                    = "1-88 02 01-02",
                        PSYCHOLOGY                    = "1-88 02 01-03",
                        DIRECTING                     = "1-88 02 01-04",
                        PROMOTION                     = "1-89 01 01 01",
                        IT                            = "1-89 01 01 02",
                        LOGISTICS                     = "1-89 01 01 03",
                        SOCIAL                        = "1-89 01 01 04",
                        TRANSPORT                     = "1-89 01 01 05",
                        CATERING                      = "1-89 01 01 06",
                        ACCOMMODATION                 = "1-89 01 01 07",
                        SUPPORTING                    = "1-89 01 01 08",
                        TREATMENT                     = "1-89 01 01 09",
                        RECREATIONAL                  = "1-89 02 01-01",
                        TUORISM_MNG                   = "1-89 02 01-02",
                        RESTAURANTS                   = "1-89 03 01-01";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  = "03.03.01",
                            THEORY      = "13.00.04";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       = "1-08 80 04",
                            MANAGEMENT  = "1-26 80 04",
                            TOURISM     = "1-89 80 01";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  = "1-89 81 01",
                            TOURISM     = "1-89 81 02",
                            HOSPITALITY = "1-89 81 03",
                            TECHNO      = "1-89 81 04";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL      = "1-88 01 01-01",
                        PRESCHOOLERS = "1-88 01 01-02";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH   = "1-88 01 02-01",
                        ADAPTIVE = "1-88 01 02-02";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION = "1-88 01 03-01",
                        ERGOTHERAPY    = "1-88 01 03-02";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING = "1-88 01 04";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING   = "1-88 02 01-01",
                        MANAGEMENT = "1-88 02 01-02",
                        PSYCHOLOGY = "1-88 02 01-03",
                        DIRECTING  = "1-88 02 01-04";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION     = "1-89 01 01 01",
                        IT            = "1-89 01 01 02",
                        LOGISTICS     = "1-89 01 01 03",
                        SOCIAL        = "1-89 01 01 04",
                        TRANSPORT     = "1-89 01 01 05",
                        CATERING      = "1-89 01 01 06",
                        ACCOMMODATION = "1-89 01 01 07",
                        SUPPORTING    = "1-89 01 01 08",
                        TREATMENT     = "1-89 01 01 09";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL = "1-89 02 01-01",
                        TUORISM_MNG  = "1-89 02 01-02";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS = "1-89 03 01-01";
                }
            }
            namespace NAME
            {
                namespace PART
                {
                    const AnsiString
                        BIOLOGICAL_SCIENCES        =                                // Master degree
                            "������������� �����",
                        PEDAGOGICAL_SCIENCES       =                                // Master degree
                            "�������������� �����",
                        PEDAGOGY_PROFESSIONAL      =                                // Master degree
                            "����������. ���������������� �����������",
                        COMMUNICATION_SCIENCES     =                                // Master degree
                            "����������",
                        PHYSICAL_CULTURE_AND_SPORT =
                            "���������� �������� � �����",
                        TOURISM_HOSPITALITY        =
                            "������. ��������������";
                }
                namespace CHAPTER
                {
                    const AnsiString
                        PHYSIOLOGY               =                                  // Master degree
                            "����������",
                        THEORY_IMPROVING         =                                  // Master degree
                            "������ � �������� ����������� ����������, "        \
                            "���������� ����������, ��������������� � "         \
                            "���������� ���������� ��������",
                        RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                            "������� ������������ � ����������, ������������",
                        PHYSICAL_CULTURE         =
                            "���������� ��������",
                        SPORT                    =
                            "�����",
                        TOURISM_HOSPITALITY      =
                            "������ � ��������������",
                        TOURISM                  =
                            "������",
                        HOSPITALITY              =
                            "��������������",
                        RESEARCH_AND_TEACHING    =                                  // Master degree
                            "������� ������������ � ����������, ������������",
                        INNOVATION                     =                            // Master degree
                            "������������� ������������ (� ����������� "        \
                            "����������� ������������)";
                }
                namespace SECTION
                {
                    const AnsiString
                        RESEARCH_SPORT                 =                            // Master degree
                            "���������� �������� � �����",
                        PHYSICAL_CULTURE              =
                            "���������� �������� (�� ������������)",
                        IMPROVING_AND_ADAPTIVE        =
                            "��������������� � ���������� ���������� �������� " \
                            "(�� ������������)",
                        REHABILITATION_ERGOTHERAPY    =
                            "���������� ������������ � ����������� "            \
                            "(�� ������������)",
                        TRAINING_MILITARY_PERSONNEL   =
                            "���������� ���������� ��������������",
                        SPORTS_AND_PEDAGOGY           =
                            "���������-�������������� ������������",
                        SPORTS_CHOREOGRAPHY           =
                            "���������� �����������",
                        TOURISM_HOSPITALITY       =
                            "������ � ��������������",
                        SPORTS_AND_TOURISM            =
                            "���������-���������� ������������ "                \
                            "(�� ������������)",
                        TOURISM_AND_NATURE_MANAGEMENT =
                            "������ � ������������������",
                        HOSPITALITY_TECHNOLOGIES      =
                            "���������� ��������� �������������� "              \
                            "(�� ������������)",
                        TOURISM_HOSPITALITY_STUDY =
                            "������ � ��������������",
                        RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                            "������ � ��������������",
                        INNOVATION_MANAGEMENT          =                            // Master degree
                            "���������� �������������� ��������� � "            \
                            "���������� ���������",
                        INNOVATION_TOURISM             =                            // Master degree
                            "������������� ���������� � ����� �������",
                        INNOVATION_HOSPITALITY         =                            // Master degree
                            "������������� ���������� � ����� ��������������",
                        INNOVATION_TECHNOLOGY          =                            // Master degree
                            "������������� ���������� � ����� ������� � "       \
                            "��������������";
                }
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL        =
                            "���������� �������� (��������)",
                        PRESCHOOLERS   =
                            "���������� �������� (������������)",
                        HEALTH         =
                            "��������������� � ���������� ���������� �������� " \
                            "(���������������)",
                        ADAPTIVE       =
                            "��������������� � ���������� ���������� �������� " \
                            "(����������)",
                        REHABILITATION =
                            "���������� ������������ � ����������� "            \
                            "(���������� ������������)",
                        ERGOTHERAPY    =
                            "���������� ������������ � ����������� "            \
                            "(�����������)",
                        COACHING       =
                            "���������-�������������� ������������ "            \
                            "(���������� ������ � ��������� ���� ������)",
                        MANAGEMENT     =
                            "���������-�������������� ������������ "            \
                            "(���������� � ������)",
                        PSYCHOLOGY     =
                            "���������-�������������� ������������ "            \
                            "(���������� ����������)",
                        DIRECTING      =
                            "���������-�������������� ������������ "            \
                            "(���������� ���������)",
                        PROMOTION      =
                            "���������� ������������ � ����������� "            \
                            "������������� �����",
                        IT             =
                            "�������������� ���������� ������������� "          \
                            "���������",
                        LOGISTICS      =
                            "��������� � ������������� ���������",
                        SOCIAL         =
                            "���������� ���������������� ������� ��������",
                        TRANSPORT      =
                            "���������� ������������� ������� ��������",
                        CATERING       =
                            "���������� ������� ������� ��������",
                        ACCOMMODATION  =
                            "���������� ������� ���������� ��������",
                        SUPPORTING     =
                            "���������� ������������-����������������� "        \
                            "������� ��������",
                        TREATMENT      =
                            "���������� ������� ������������ � ������� "        \
                            "��������",
                        RECREATIONAL   =
                            "���������-���������� ������������ "                \
                            "(���������� � ������������� ������)",
                        TUORISM_MNG    =
                            "���������-���������� ������������ "                \
                            "(���������� � �������)",
                        RESTAURANTS    =
                            "���������� ��������� �������������� "              \
                            "(����������� ������������)";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  =
                                "����������",
                            THEORY      =
                                "������ � �������� ����������� ����������, "    \
                                "���������� ����������, ��������������� � "     \
                                "���������� ���������� ��������";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       =
                                "���������� �������� � �����",
                            MANAGEMENT  =
                                "����������",
                            TOURISM     =
                                "������ � ��������������";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  =
                                "���������� �������������� ��������� � "        \
                                "���������� ���������",
                            TOURISM     =
                                "������������� ���������� � ����� �������",
                            HOSPITALITY =
                                "������������� ���������� � ����� "             \
                                "��������������",
                            TECHNO  =
                                "������������� ���������� � ����� ������� � "   \
                                "��������������";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        = "���������� �������� (��������)",
                        PRESCHOOLERS   = "���������� �������� (������������)";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         =
                            "��������������� � ���������� ���������� �������� " \
                            "(���������������)",
                        ADAPTIVE       =
                            "��������������� � ���������� ���������� �������� " \
                            "(����������)";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION =
                            "���������� ������������ � ����������� "            \
                            "(���������� ������������)",
                        ERGOTHERAPY    =
                            "���������� ������������ � ����������� "            \
                            "(�����������)";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING       = "���������� ���������� ��������������";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING       =
                            "���������-�������������� ������������ "            \
                            "(���������� ������ � ��������� ���� ������)",
                        MANAGEMENT     =
                            "���������-�������������� ������������ "            \
                            "(���������� � ������)",
                        PSYCHOLOGY     =
                            "���������-�������������� ������������ "            \
                            "(���������� ����������)",
                        DIRECTING      =
                            "���������-�������������� ������������ "            \
                            "(���������� ���������)";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION      =
                            "���������� ������������ � ����������� "            \
                            "������������� �����",
                        IT             =
                            "�������������� ���������� ������������� ���������",
                        LOGISTICS      =
                            "��������� � ������������� ���������",
                        SOCIAL         =
                            "���������� ���������������� ������� ��������",
                        TRANSPORT      =
                            "���������� ������������� ������� ��������",
                        CATERING       =
                            "���������� ������� ������� ��������",
                        ACCOMMODATION  =
                            "���������� ������� ���������� ��������",
                        SUPPORTING     =
                            "���������� ������������-����������������� "        \
                            "������� ��������",
                        TREATMENT      =
                            "���������� ������� ������������ � ������� "        \
                            "��������";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL   =
                            "���������-���������� ������������ "                \
                            "(���������� � ������������� ������)",
                        TUORISM_MNG    =
                            "���������-���������� ������������ "                \
                            "(���������� � �������)";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS    =
                            "���������� ��������� �������������� "              \
                            "(����������� ������������)";
                }
            }
            namespace QUALIFICATION
            {
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL        =
                            "����������-�������� �� �������� ���������� "       \
                            "��������. ������������� ���������� ��������",
                        PRESCHOOLERS   =
                            "����������-�������� ����������� ���������� � "     \
                            "���������� �����������. "                          \
                            "������������� ���������� ��������",
                        HEALTH         =
                            "����������-�������� �� ��������������� "           \
                            "���������� ��������. "                             \
                            "������������� ���������� ��������",
                        ADAPTIVE       =
                            "����������-�������� �� ���������� "                \
                            "���������� ��������. "                             \
                            "������������� ���������� ��������",
                        REHABILITATION =
                            "����������-�������� �� ���������� "                \
                            "������������. "                                    \
                            "������������� ���������� ��������",
                        ERGOTHERAPY    =
                            "����������-�������� �� �����������. "              \
                            "������������� ���������� ��������",
                        TRAINING       =
                            "���������� �� ����������. "                        \
                            "����������-�������� �� ���������� "                \
                            "����������",
                        COACHING       =
                            "������ (�� ���� ������). "                         \
                            "������������� ���������� ��������",
                        MANAGEMENT     =
                            "�������� � ������. "                               \
                            "������������� ���������� ��������",
                        PSYCHOLOGY     =
                            "��������. "                                        \
                            "������������� ���������� ��������",
                        DIRECTING      =
                            "��������-�������� ���������-�������� "             \
                            "�����������."                                      \
                            "������������� ���������� ��������",
                        PROMOTION      =
                            "���������� � ����� ������� � ��������������",
                        IT             =
                            "���������� � ����� ������� � ��������������",
                        LOGISTICS      =
                            "���������� � ����� ������� � ��������������",
                        SOCIAL         =
                            "���������� � ����� ������� � ��������������",
                        TRANSPORT      =
                            "���������� � ����� ������� � ��������������",
                        CATERING       =
                            "���������� � ����� ������� � ��������������",
                        ACCOMMODATION  =
                            "���������� � ����� ������� � ��������������",
                        SUPPORTING     =
                            "���������� � ����� ������� � ��������������",
                        TREATMENT      =
                            "���������� � ����� ������� � ��������������",
                        RECREATIONAL   =
                            "����������-�������� �� �������. "                  \
                            "������������� ���������� ��������",
                        TUORISM_MNG    =
                            "�������� �� �������. "                             \
                            "������������� ���������� ��������",
                        RESTAURANTS    = "��������. ��������";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  = "�������",
                            THEORY      = "�������";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       = "�������",
                            MANAGEMENT  = "�������",
                            TOURISM     = "�������";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  = "�������",
                            TOURISM     = "�������",
                            HOSPITALITY = "�������",
                            TECHNO      = "�������";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        =
                            "����������-�������� �� �������� ���������� "       \
                            "��������. ������������� ���������� ��������",
                        PRESCHOOLERS   =
                            "����������-�������� ����������� ���������� � "     \
                            "���������� �����������. "                          \
                            "������������� ���������� ��������";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         =
                            "����������-�������� �� ��������������� "           \
                            "���������� ��������. "                             \
                            "������������� ���������� ��������",
                        ADAPTIVE       =
                            "����������-�������� �� ���������� "                \
                            "���������� ��������. "                             \
                            "������������� ���������� ��������";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION =
                            "����������-�������� �� ���������� "                \
                            "������������. "                                    \
                            "������������� ���������� ��������",
                        ERGOTHERAPY    =
                            "����������-�������� �� �����������. "              \
                            "������������� ���������� ��������";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING       =
                            "���������� �� ����������. "                        \
                            "����������-�������� �� ���������� "                \
                            "����������";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING       =
                            "������ (�� ���� ������). "                         \
                            "������������� ���������� ��������",
                        MANAGEMENT     =
                            "�������� � ������. "                               \
                            "������������� ���������� ��������",
                        PSYCHOLOGY     =
                            "��������. "                                        \
                            "������������� ���������� ��������",
                        DIRECTING      =
                            "��������-�������� ���������-�������� "             \
                            "�����������."                                      \
                            "������������� ���������� ��������";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION      =
                            "���������� � ����� ������� � ��������������",
                        IT             =
                            "���������� � ����� ������� � ��������������",
                        LOGISTICS      =
                            "���������� � ����� ������� � ��������������",
                        SOCIAL         =
                            "���������� � ����� ������� � ��������������",
                        TRANSPORT      =
                            "���������� � ����� ������� � ��������������",
                        CATERING       =
                            "���������� � ����� ������� � ��������������",
                        ACCOMMODATION  =
                            "���������� � ����� ������� � ��������������",
                        SUPPORTING     =
                            "���������� � ����� ������� � ��������������",
                        TREATMENT      =
                            "���������� � ����� ������� � ��������������";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL   =
                            "����������-�������� �� �������. "                  \
                            "������������� ���������� ��������",
                        TUORISM_MNG    =
                            "�������� �� �������. "                             \
                            "������������� ���������� ��������";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS    = "��������. ��������";
                }
            }
        }
        namespace _2022
        {
            namespace CODE
            {
                const AnsiString
                    PHYSIOLOGY       = "03.03.01",                                  // Master degree
                    THEORY_IMPROVING = "13.00.04",                                  // Master degree
                    INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                    INNO_TOURISM     = "1-89 81 02",                                // Master degree
                    INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                    INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                    PHYSICAL_CULTURE = "6-05-1012-01",
                    COACHING         = "6-05-1012-02",
                    REHABILITATION   = "6-05-1012-03",
                    MANAGEMENT       = "6-05-1012-04",
                    TOURISM          = "6-05-1013-01",
                    NATURE           = "6-05-1013-03",
                    HOSPITALITY      = "6-05-1013-04",
                    MNG_MASTER_DEGREE = "7-06-0412-01",
                    PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                    TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                    CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
            }
            namespace NAME
            {
                const AnsiString
                    PHYSIOLOGY       =                                              // Master degree
                        "����������",
                    THEORY_IMPROVING =                                              // Master degree
                        "������ � �������� ����������� ����������, "        \
                        "���������� ����������, ��������������� � "         \
                        "���������� ���������� ��������",
                    INNO_MANAGEMENT  =                                              // Master degree
                        "���������� �������������� ��������� � "            \
                        "���������� ���������",
                    INNO_TOURISM     =                                              // Master degree
                        "������������� ���������� � ����� �������",
                    INNO_HOSPITALITY =                                              // Master degree
                        "������������� ���������� � ����� ��������������",
                    INNO_TECHNOLOGY  =                                              // Master degree
                        "������������� ���������� � ����� ������� � "       \
                        "��������������",
                    PHYSICAL_CULTURE =
                        "���������� ��������",
                    COACHING         =
                        "���������� ������������",
                    REHABILITATION   =
                        "���������� ������������ � �����������",
                    MANAGEMENT       =
                        "����������� � ���������� ���������� ���������, "   \
                        "������� � ��������",
                    TOURISM          =
                        "������ � ��������������",
                    NATURE           =
                        "������ � ������������������",
                    HOSPITALITY      =
                        "���������� ��������� ��������������",
                    PC_MASTER_DEGREE =                                              // Master degree
                        "���������� �������� � �����",
                    TH_MASTER_DEGREE =                                              // Master degree
                        "������ � ��������������",
                    CHOREOGRAPHY     =
                        "���������� �����������";

                namespace PHYSICAL
                {
                    const AnsiString
                        IMPROVING      = "(���������������)",                       // "(��������������� ���������� ��������)",
                        HEALTH         = "(��������)",                              // "(�������� ���������� ��������)",
                        PRESCHOOLERS   = "(������������)",                          // "(���������� �������� ������������)",
                        ADAPTIVE       = "(����������)",                            // "(���������� ���������� ��������)",
                        DIRECTING      = "(���������� ���������)",
                        PSYCHOLOGY     = "(���������� ����������)",
                        RECREATIONAL   = "(���������� � ������������� ������)";
                }
                namespace COACH
                {
                    const AnsiString
                        DEFAULT        = "(� ��������� ���� ������)";
                }
                namespace REHABILITATE
                {
                    const AnsiString
                        REHABILITATION = "(���������� ������������)",
                        ERGOTHERAPY    = "(�����������)";
                }
                namespace MANAGE
                {
                    const AnsiString
                        SPORT          = "(���������� � ������)",
                        TOURISM        = "(���������� � �������)";
                }
            }
            namespace QUALIFICATION
            {
                const AnsiString
                    PHYSIOLOGY       = "�������",                                   // Master degree
                    THEORY_IMPROVING = "�������",                                   // Master degree
                    INNO_MANAGEMENT  = "������� ����������",                        // Master degree
                    INNO_TOURISM     = "������� �������",                           // Master degree
                    INNO_HOSPITALITY = "������� ��������������",                    // Master degree
                    INNO_TECHNOLOGY  = "������� ���������",                         // Master degree
                    PHYSICAL_CULTURE = "����������-��������. �������������",
                    COACHING         = "������. �������������",
                    REHABILITATION   = "����������-��������. �������������",
                    MANAGEMENT       = "��������. �������������",
                    TOURISM          = "����������",
                    NATURE           = "���������� �� ������� � ������������������",
                    HOSPITALITY      = "��������. ��������",
                    PC_MASTER_DEGREE = "�������",                                   // Master degree
                    TH_MASTER_DEGREE = "�������",                                   // Master degree
                    CHOREOGRAPHY     = "����������-��������";
            }
        }
    }
    namespace KindOfSport
    {
        const AnsiString
            GYMNASTICS                   =
                "����������",
            MANAGEMENT_SPORTS_TOURISM    =
                "���������� ������ � �������",
            PHYSICAL_REHABILITATION      =
                "���������� ������������",
            THERAPEUTIC                  =
                "�������� ���������� ��������",
            ORGANIZATION_SPORTS_TOURISM  =
                "����������� ������������-��������������� "         \
                "������ � �������",
            PRESCHOOL_PHYSICAL_EDUCATION =
                "���������� ���������� ����������",
            DANCE_SPORT                  =
                "������������ �����",
            AEROBICS                     =
                "��������",
            ROWING_OTHER                 =
                "������� �����",
            SWIMMING                     =
                "��������",
            SAILING                      =
                "�������� �����",
            ATHLETICS                    =
                "������ ��������",
            CROSS_COUNTRY_SKIING         =
                "������ �����",
            BULLET_SHOOTING_DEANERY      =
                "������� ��������",
            HAND_TO_HAND_COMBAT          =
                "���������� ���",
            TAEKWONDO                    =
                "���������",
            KARATE                       =
                "������",
            SKIING                       =
                "������ �����",
            AUTOMOTIVE_SPORT             =
                "������������� �����",
            BASKETBALL                   =
                "���������",
            BOXING                       =
                "����",
            GRECO_FREESTYLE_WRESTLING    =
                "�����-������� � ������� ������",
            CYCLING                      =
                "������������ �����",
            VOLLEYBALL                   =
                "��������",
            HANDBALL                     =
                "�������",
            EQUESTRIAN                   =
                "������ �����",
            SPEED_SKATING                =
                "������������ �����",
            TENNIS                       =
                "������",
            WEIGHTLIFTING                =
                "������� ��������",
            FENCING                      =
                "����������",
            FIGURE_SKATING_OLD           =
                "�������� �������",
            FOOTBALL                     =
                "������",
            HOCKEY                       =
                "������",
            SAMBO_JUDO                   =
                "�����-�����",
            WRESTLING                    =
                "���������� ������",
            FOOTBALL_HOCKEY              =
                "������ � ������",
            BIATHLON                     =
                "�������",
            HEALTH_IMPROVING             =
                "��������������� ���������� ��������",
            ADAPTIVE                     =
                "���������� ���������� ��������",
            FREESTYLE_WRESTLING          =
                "������� ������",
            GRECO_ROMAN_WRESTLING        =
                "�����-������� ������",
            SAMBO                        =
                "�����",
            JUDO                         =
                "�����",
            TABLE_TENNIS_ABITURIENT      =
                "������ ����������",
            ERGOTHERAPY                  =
                "�����������",
            MANAGEMENT_SPORTS            =
                "���������� � ������",
            SPORTS_DIRECTING_DEANERY     =
                "���������� ���������",
            SPORTS_RECREATIONAL_TOURISM  =
                "���������� � ������������� ������",
            MANAGEMENT_TOURISM           =
                "���������� � �������",
            SPORTS_PSYCHOLOGY            =
                "���������� ����������",
            BILLIARD_SPORTS              =
                "���������� �����",
            ACROBATICS                   =
                "����������",
            ORIENTEERING                 =
                "���������� ��������������",
            SPORTS_DIRECTING             =
                "���������� ���������",
            PRESCHOOLERS                 =
                "���������� �������� ������������",
            MOUNTAINEERING               =
                "���������",
            SKI_COMBINED                 =
                "������ ���������",
            TOURISM_HOSPITALITY          =
                "������ � ��������������",
            WATER_TECHNICAL_SPORTS       =
                "�����-����������� ���� ������",
            MODEL_TECHNICAL_SPORTS       =
                "��������-����������� ���� ������",
            ALPINE_SKIING                =
                "����������� �����",
            BASEBALL                     =
                "�������",
            WUSHU                        =
                "���",
            CHESS                        =
                "�������",
            THAI_BOXING                  =
                "����������� ����",
            TOURISM_PROMOTION            =
                "���������� ������������ � ����������� "            \
                "������������� �����",
            TOURISM_IT                   =
                "�������������� ���������� ������������� "          \
                "���������",
            TOURISM_LOGISTICS            =
                "��������� � ������������� ���������",
            TOURISM_SOCIAL               =
                "���������� ���������������� ������� "              \
                "��������",
            TOURISM_TRANSPORT            =
                "���������� ������������� ������� ��������",
            TOURISM_FOOD                 =
                "���������� ������� ������� ��������",
            TOURIST_ACCOMMODATION        =
                "���������� ������� ���������� ��������",
            TOURISM_EXCURSION            =
                "���������� ������������-����������������� "        \
                "������� ��������",
            TOURISM_HEALTH               =
                "���������� ������� ������������ � ������� "        \
                "��������",
            BULLET_SHOOTING              =
                "�������� �������",
            FIELD_HOCKEY                 =
                "������ �� �����",
            FIGURE_SKATING               =
                "�������� ������� �� �������",
            ROWING_AND_CANOEING          =
                "������ �� ��������� � �����",
            ACADEMIC_ROWING              =
                "������ �������������",
            HAND_TO_HAND_COMBAT_MS       =
                "���������� ��� (��������� ������������)",
            BILLIARDS_RPC                =
                "�������",
            WITHOUT_SPECIALIZATION       =
                "��� �������������",
            MEDICAL                      =
                "���������� ��������(��������)",
            MODERN_PENTATHLON            =
                "����������� ���������",
            SCIENCE_HEALTH               =
                "������ � �������� ����������� ����������, "        \
                "���������� ����������, ���������������",
            PHYSIOLOGY                   =
                "����������",
            SCIENCE_THEORY               =
                "������ � �������� ����������� ����������, "        \
                "���������� ����������, ���������������",
            RECEARCH_SPORT               =
                "������ � �������� ����������� ����������, "        \
                "���������� ����������, ���������������",
            INNOVATIVE_TOURISM           =
                "������������� ���������� � ����� �������",
            INNOVATIVE_HOSPITALITY       =
                "������������� ���������� � ����� ��������������",
            INNOVATIVE_TECHNOLOGIES      =
                "������������� ���������� � ����� ������� "         \
                "� ��������������",
            INNOVATIVE_MANAGEMENT        =
                "���������� �������������� ��������� � "            \
                "���������� ���������",
            BILLIARDS_SMA                =
                "�������",
            HAND_TO_HAND_COMBAT_SMA      =
                "���������� ��� (��������� ������������)",
            BADMINTON                    =
                "���������",
            TABLE_TENNIS_DEANERY         =
                "���������� ������",
            PHYSICAL_CULTURE_SPORT       =
                "���������� �������� � �����",
            TOURISM_HOSPITALITY_MASTER   =
                "������ � ��������������",
            SPORT_CLIMBING               =
                "������������ ����������",
            MASTER_ANTHROPOLOGY          =
                "������������",
            MASTER_MANAGEMENT            =
                "����������",
            MASTER_PHYSICAL_CULTURE      =
                "���������� �������� � �����";

        namespace DATIVE_CASE
        {
            const AnsiString
                GYMNASTICS                   =
                    "����������",
                MANAGEMENT_SPORTS_TOURISM    =
                    "����������� ������ � �������",
                PHYSICAL_REHABILITATION      =
                    "���������� ������������",
                THERAPEUTIC                  =
                    "�������� ���������� ��������",
                ORGANIZATION_SPORTS_TOURISM  =
                    "����������� ������������-��������������� "         \
                    "������ � �������",
                PRESCHOOL_PHYSICAL_EDUCATION =
                    "����������� ����������� ����������",
                DANCE_SPORT                  =
                    "������������� ������",
                AEROBICS                     =
                    "��������",
                ROWING_OTHER                 =
                    "�������� ������",
                SWIMMING                     =
                    "��������",
                SAILING                      =
                    "��������� ������",
                ATHLETICS                    =
                    "������ ��������",
                CROSS_COUNTRY_SKIING         =
                    "������ ������",
                BULLET_SHOOTING_DEANERY      =
                    "������� ��������",
                HAND_TO_HAND_COMBAT          =
                    "����������� ���",
                TAEKWONDO                    =
                    "���������",
                KARATE                       =
                    "������",
                SKIING                       =
                    "������� ������",
                AUTOMOTIVE_SPORT             =
                    "�������������� ������",
                BASKETBALL                   =
                    "����������",
                BOXING                       =
                    "�����",
                GRECO_FREESTYLE_WRESTLING    =
                    "�����-������� � ������� ������",
                CYCLING                      =
                    "������������� ������",
                VOLLEYBALL                   =
                    "���������",
                HANDBALL                     =
                    "��������",
                EQUESTRIAN                   =
                    "������� ������",
                SPEED_SKATING                =
                    "������������� ������",
                TENNIS                       =
                    "�������",
                WEIGHTLIFTING                =
                    "������� ��������",
                FENCING                      =
                    "����������",
                FIGURE_SKATING_OLD           =
                    "��������� �������",
                FOOTBALL                     =
                    "�������",
                HOCKEY                       =
                    "������",
                SAMBO_JUDO                   =
                    "�����-�����",
                WRESTLING                    =
                    "���������� ������",
                FOOTBALL_HOCKEY              =
                    "������� � ������",
                BIATHLON                     =
                    "��������",
                HEALTH_IMPROVING             =
                    "��������������� ���������� ��������",
                ADAPTIVE                     =
                    "���������� ���������� ��������",
                FREESTYLE_WRESTLING          =
                    "������� ������",
                GRECO_ROMAN_WRESTLING        =
                    "�����-������� ������",
                SAMBO                        =
                    "�����",
                JUDO                         =
                    "�����",
                TABLE_TENNIS_ABITURIENT      =
                    "������� �����������",
                ERGOTHERAPY                  =
                    "�����������",
                MANAGEMENT_SPORTS            =
                    "����������� � ������",
                SPORTS_DIRECTING_DEANERY     =
                    "���������� ���������",
                SPORTS_RECREATIONAL_TOURISM  =
                    "����������� � �������������� �������",
                MANAGEMENT_TOURISM           =
                    "����������� � �������",
                SPORTS_PSYCHOLOGY            =
                    "���������� ����������",
                BILLIARD_SPORTS              =
                    "����������� ������",
                ACROBATICS                   =
                    "����������",
                ORIENTEERING                 =
                    "����������� ��������������",
                SPORTS_DIRECTING             =
                    "���������� ���������",
                PRESCHOOLERS                 =
                    "���������� �������� ������������",
                MOUNTAINEERING               =
                    "����������",
                SKI_COMBINED                 =
                    "������� ���������",
                TOURISM_HOSPITALITY          =
                    "������� � ��������������",
                WATER_TECHNICAL_SPORTS       =
                    "�����-����������� ����� ������",
                MODEL_TECHNICAL_SPORTS       =
                    "��������-����������� ����� ������",
                ALPINE_SKIING                =
                    "������������ ������",
                BASEBALL                     =
                    "��������",
                WUSHU                        =
                    "���",
                CHESS                        =
                    "��������",
                THAI_BOXING                  =
                    "������������ �����",
                TOURISM_PROMOTION            =
                    "����������� ������������ � ����������� "            \
                    "������������� �����",
                TOURISM_IT                   =
                    "�������������� ����������� ������������� "          \
                    "���������",
                TOURISM_LOGISTICS            =
                    "��������� � ������������� ���������",
                TOURISM_SOCIAL               =
                    "����������� ���������������� ������� "              \
                    "��������",
                TOURISM_TRANSPORT            =
                    "����������� ������������� ������� ��������",
                TOURISM_FOOD                 =
                    "����������� ������� ������� ��������",
                TOURIST_ACCOMMODATION        =
                    "����������� ������� ���������� ��������",
                TOURISM_EXCURSION            =
                    "����������� ������������-����������������� "        \
                    "������� ��������",
                TOURISM_HEALTH               =
                    "����������� ������� ������������ � ������� "        \
                    "��������",
                BULLET_SHOOTING              =
                    "�������� �������",
                FIELD_HOCKEY                 =
                    "������ �� �����",
                FIGURE_SKATING               =
                    "��������� ������� �� �������",
                ROWING_AND_CANOEING          =
                    "������ �� ��������� � �����",
                ACADEMIC_ROWING              =
                    "������ �������������",
                HAND_TO_HAND_COMBAT_MS       =
                    "����������� ��� (��������� ������������)",
                BILLIARDS_RPC                =
                    "��������",
                WITHOUT_SPECIALIZATION       =
                    "��� �������������",
                MEDICAL                      =
                    "���������� �������� (��������)",
                MODERN_PENTATHLON            =
                    "������������ ���������",
                SCIENCE_HEALTH               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                PHYSIOLOGY                   =
                    "����������",
                SCIENCE_THEORY               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                RECEARCH_SPORT               =
                    "������ � �������� ����������� ����������, "        \
                    "���������� ����������, ���������������",
                INNOVATIVE_TOURISM           =
                    "�������������� ����������� � ����� �������",
                INNOVATIVE_HOSPITALITY       =
                    "�������������� ����������� � ����� ��������������",
                INNOVATIVE_TECHNOLOGIES      =
                    "������������� ����������� � ����� ������� "         \
                    "� ��������������",
                INNOVATIVE_MANAGEMENT        =
                    "���������� �������������� ��������� � "            \
                    "���������� ���������",
                BILLIARDS_SMA                =
                    "��������",
                HAND_TO_HAND_COMBAT_SMA      =
                    "����������� ��� (��������� ������������)",
                BADMINTON                    =
                    "����������",
                TABLE_TENNIS_DEANERY         =
                    "����������� �������",
                PHYSICAL_CULTURE_SPORT       =
                    "���������� �������� � ������",
                TOURISM_HOSPITALITY_MASTER   =
                    "������� � ��������������",
                SPORT_CLIMBING               =
                    "����������� ������������",
                MASTER_ANTHROPOLOGY          =
                    "������������",
                MASTER_MANAGEMENT            =
                    "�����������",
                MASTER_PHYSICAL_CULTURE      =
                    "���������� �������� � ������";
        }
    }

    namespace PathTo
    {
        const AnsiString
            OUTPUT_DOCUMENTS       = "D:\\��������� �������� ��������",
            OUTPUT_DOCUMENTS_SLASH = "D:\\��������� �������� ��������\\";
    }
    namespace Payment
    {
        const AnsiString
            BUDGET = "������",
            BUYERS = "�������";
    }
    namespace SportsRanks
    {
        const AnsiString
            INTERNATIONAL_MASTER_OF_SPORTS =                                        // (IMS)
                "������ ������ �������������� ������ (����)",
            HONORED_MASTER_OF_SPORTS       = "����������� ������ ������ (���)",     // (HMS)
            MASTER_OF_SPORT                = "������ ������ (��)",                  // (MS)
            CANDIDATE_IN_MASTERS_OF_SPORT  = "�������� � ������� ������ (���)",     // (CMS)
            FIRST_SPORT_CATEGORY           = "I ���������� ������ (I ������)",      // (FSC)
            SECOND_SPORT_CATEGORY          = "II ���������� ������ (II ������)",    // (SSC)
            THIRD_SPORT_CATEGORY           = "III ���������� ������ (III ������)",  // (TSC)
            FIRST_YOUTH_CATEGORY           = "I ��������� ������ (I ���������)",    // (FYC)
            SECOND_YOUTH_CATEGORY          = "II ��������� ������ (II ���������)",  // (SYC)
            FIRST_APPRENTICESHIP_DEGREE    = "1-� ����������� ������� (1 ��)",      // (FAD)
            SECOND_APPRENTICESHIP_DEGREE   = "2-� ����������� ������� (2 ��)",      // (SAD)
            THIRD_APPRENTICESHIP_DEGREE    = "3-� ����������� ������� (3 ��)",      // (TAD)
            WITHOUT                        = "���";                                 // (NO)

        namespace ABBR
        {
            const AnsiString
                INTERNATIONAL_MASTER_OF_SPORTS = "����",
                HONORED_MASTER_OF_SPORTS       = "���",
                MASTER_OF_SPORT                = "��",
                CANDIDATE_IN_MASTERS_OF_SPORT  = "���",
                FIRST_SPORT_CATEGORY           = "I ������",
                SECOND_SPORT_CATEGORY          = "II ������",
                THIRD_SPORT_CATEGORY           = "III ������",
                FIRST_YOUTH_CATEGORY           = "I ���������",
                SECOND_YOUTH_CATEGORY          = "II ���������",
                FIRST_APPRENTICESHIP_DEGREE    = "1 ��",
                SECOND_APPRENTICESHIP_DEGREE   = "2 ��",
                THIRD_APPRENTICESHIP_DEGREE    = "3 ��",
                WITHOUT                        = "���";
        }
    }
    namespace StudyPeriod
    {
        namespace HIGH
        {
            const AnsiString
                NAME           = "������ �����������",
                FULL           = "������ ����",                                     // t_abitur_queue.term_edu = 0
                FIRST_COURSE   = "������ ����������� (1 ����)",                     // t_abitur_queue.term_edu = 3
                SECOND_COURSE  = "������ ����������� (2 ����)",                     // t_abitur_queue.term_edu = 4
                THIRD_COURSE   = "������ ����������� (3 ����)";                     // t_abitur_queue.term_edu = 5
        }
        namespace SHORT
        {
            const AnsiString
                NAME          = "C���������� ����",
                SECOND_COURSE = "C���������� ���� (2 ����)",                        // t_abitur_queue.term_edu = 1
                THIRD_COURSE  = "C���������� ���� (3 ����)";                        // t_abitur_queue.term_edu = 2
        }
    }
#endif // ! STATE_FROM_WORK_PC


#endif // PROPERTIES_HPP
