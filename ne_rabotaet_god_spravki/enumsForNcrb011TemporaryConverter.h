#pragma once
#ifndef ENUMS_FOR_NCRB_011_TEMPORARY_CONVERTER_H
#define ENUMS_FOR_NCRB_011_TEMPORARY_CONVERTER_H

// SEE PREVIOUS VERSION: .\.TEMPORARY\!Ncrb011TemporaryConverter_beforeChanging

namespace TC
{
//    enum Default
//    {
//        EMPTY                                       = 0,
//        START                                       = 0,
//        DISABLE                                     = 0,
//        STEP                                        = 1,
//        ENABLE                                      = 1
//    };
//    enum EducationTypeCode
//    {
//        INTRAMURAL                                  = 0,
//        EXTRAMURAL                                  = 1
//    };
//    enum PaymentCode
//    {
//        BUDGET                                      = 0,
//        BUYERS                                      = 1
//    };
//    enum FormTypeCode
//    {
//        REGISTRATION                        = 1,
//        ENROLLMENT                          = 2
//    };
//    enum FacultyCode
//    {
//        SMA                                         = 1,                            // 1, -> Sports and Marital Arts (����)
//        MS                                          = 2,                            // 2, -> Mass Sports (���)
//        RPC                                         = 3,                            // 3, -> Recreational Physical Culture (�����)
//        MSTH                                        = 4,                            // 4, -> Management of Sports, Tourism and Hospitality (����)
//        MD                                          = 5,                            // 5, -> Master's Degree (�����������)
//        PGS                                         = 6,                            // 6, -> PostGraduate Studies (�����������)
//        DOC                                         = 7                             // 7  -> DOCtorate (������������)
//    };
//    enum SubjectCode
//    {
//        RUS                                 = 0,
//        BEL                                 = 1
//    };
//    enum StudyPeriodCode
//    {
//        FULL                                        = 0,                            // 0, -> "������ ����"
//        SHORT_SECOND_COURSE                         = 1,                            // 1, -> "C���������� ���� (2 ����)"
//        SHORT_THIRD_COURSE                          = 2,                            // 2, -> "C���������� ���� (3 ����)"
//        HIGH_FIRST_COURSE                           = 3,                            // 3, -> "������ ����������� (1 ����)"
//        HIGH_SECOND_COURSE                          = 4,                            // 4, -> "������ ����������� (2 ����)"
//        HIGH_THIRD_COURSE                           = 5                             // 5  -> "������ ����������� (3 ����)"
//    };
//    enum SportsRanksCode
//    {
//        THIRD_SPORT_CATEGORY                = 1,                                    // 1  -> 3 ������
//        SECOND_SPORT_CATEGORY               = 2,                                    // 2  -> 2 ������
//        FIRST_SPORT_CATEGORY                = 3,                                    // 3  -> 1 ������
//        CANDIDATE_IN_MASTERS_OF_SPORT       = 4,                                    // 4  -> ���
//        MASTER_OF_SPORT                     = 5,                                    // 5  -> ��
//        INTERNATIONAL_MASTER_OF_SPORTS      = 6,                                    // 6  -> ����
//        HONORED_MASTER_OF_SPORTS            = 7,                                    // 7  -> ���
//        THIRD_APPRENTICESHIP_DEGREE         = 8,                                    // 8  -> 3 ��
//        SECOND_APPRENTICESHIP_DEGREE        = 9,                                    // 9  -> 2 ��
//        FIRST_APPRENTICESHIP_DEGREE         = 10,                                   // 10 -> 1 ��
//        FIRST_YOUTH_CATEGORY                = 11,                                   // 11 -> 1 ��������� ������
//        WITHOUT                             = 12,                                   // 12 -> ���
//        SECOND_YOUTH_CATEGORY               = 13                                    // 13 -> 2 ��������� ������
//    };

    enum DeanerySpecialDirectionNSpecDirCode
    {
        SPORT_COACHING                      = 1,                                    // old code: "1-88 02 01-01",
        SPORT_PSYCHOLOGY                    = 2,                                    // old code: "1-88 02 01-03",
        SPORT_DIRECTING                     = 3,                                    // old code: "1-88 02 01-04",
        SPORT_MANAGEMENT                    = 4,                                    // old code: "1-88 02 01-02",
        TOURISM_RECREATIONAL                = 5,                                    // old code: "1-89 02 01-01",
        TOURISM_TUORISM_MNG                 = 6,                                    // old code: "1-89 02 01-02",
        PHYSICAL_CULTURE_MEDICAL            = 7,                                    // old code: "1-88 01 01-01",
        PHYSICAL_CULTURE_PRESCHOOLERS       = 8,                                    // old code: "1-88 01 01-02",
        IMPROVING_HEALTH                    = 9,                                    // old code: "1-88 01 02-01",
        IMPROVING_ADAPTIVE                  = 10,                                   // old code: "1-88 01 02-02",
        REHABILITATION_REHABILITATION       = 11,                                   // old code: "1-88 01 03-01",
        REHABILITATION_ERGOTHERAPY          = 12,                                   // old code: "1-88 01 03-02",
        SECTION_TOURISM_HOSPITALITY         = 13,                                   // old code: "1-89 01 01",
        TOURISM_HOSPITALITY_PROMOTION       = 14,                                   // old code: "1-89 01 01 01",
        TOURISM_HOSPITALITY_IT              = 15,                                   // old code: "1-89 01 01 02",
        TOURISM_HOSPITALITY_LOGISTICS       = 16,                                   // old code: "1-89 01 01 03",
        TOURISM_HOSPITALITY_SOCIAL          = 17,                                   // old code: "1-89 01 01 04",
        TOURISM_HOSPITALITY_TRANSPORT       = 18,                                   // old code: "1-89 01 01 05",
        TOURISM_HOSPITALITY_CATERING        = 19,                                   // old code: "1-89 01 01 06",
        TOURISM_HOSPITALITY_ACCOMMODATION   = 20,                                   // old code: "1-89 01 01 07",
        TOURISM_HOSPITALITY_SUPPORTING      = 21,                                   // old code: "1-89 01 01 08",
        TOURISM_HOSPITALITY_TREATMENT       = 22,                                   // old code: "1-89 01 01 09",
        MASTER_SCIENCE_THEORY               = 23,                                   // old code: "13.00.04",
        MASTER_SCIENCE_PHYSIOLOGY           = 24,                                   // old code: "03.03.01",
        MASTER_RESEARCH_SPORT               = 25,                                   // old code: "1-08 80 04",
        MASTER_INNOVATION_TOURISM           = 26,                                   // old code: "1-89 81 02",
        MASTER_INNOVATION_HOSPITALITY       = 27,                                   // old code: "1-89 81 03",
        MASTER_INNOVATION_TECHNOLOGY        = 28,                                   // old code: "1-89 81 04",
        MASTER_INNOVATION_MANAGEMENT        = 29,                                   // old code: "1-89 81 01",      // NOT USE
        MASTER_PHYSICAL_CULTURE_SPORT       = 31,                                   // old code: "1-08 80 04",
        MASTER_RESEARCH_TOURISM             = 32                                    // old code: "1-89 80 01",
    };

    enum KindOfSportCode
    {
        GYMNASTICS                                  = 1,                        // 1,   -> "����������",
        MANAGEMENT_SPORTS_TOURISM                   = 2,                        // 2,   -> "���������� ������ � �������",
        PHYSICAL_REHABILITATION                     = 3,                        // 3,   -> "���������� ������������",
        THERAPEUTIC                                 = 4,                        // 4,   -> "�������� ���������� ��������",
        ORGANIZATION_SPORTS_TOURISM                 = 5,                        // 5,   -> "����������� ������������-��������������� ������ � �������",
        PRESCHOOL_PHYSICAL_EDUCATION                = 6,                        // 6,   -> "���������� ���������� ����������",
        DANCE_SPORT                                 = 7,                        // 7,   -> "������������ �����",
        AEROBICS                                    = 8,                        // 8,   -> "��������",
        ROWING_OTHER                                = 9,                        // 9,   -> "������� �����",
        SWIMMING                                    = 10,                       // 10,  -> "��������",
        SAILING                                     = 11,                       // 11,  -> "�������� �����",
        ATHLETICS                                   = 12,                       // 12,  -> "������ ��������",
        CROSS_COUNTRY_SKIING                        = 13,                       // 13,  -> "������ �����",
        BULLET_SHOOTING_DEANERY                     = 14,                       // 14,  -> "������� ��������",
        HAND_TO_HAND_COMBAT                         = 15,                       // 15,  -> "���������� ���",
        TAEKWONDO                                   = 16,                       // 16,  -> "���������",
        KARATE                                      = 17,                       // 17,  -> "������",
        SKIING                                      = 18,                       // 18,  -> "������ �����",
        AUTOMOTIVE_SPORT                            = 19,                       // 19,  -> "������������� �����",
        BASKETBALL                                  = 20,                       // 20,  -> "���������",
        BOXING                                      = 21,                       // 21,  -> "����",
        GRECO_FREESTYLE_WRESTLING                   = 22,                       // 22,  -> "�����-������� � ������� ������",
        CYCLING                                     = 23,                       // 23,  -> "������������ �����",
        VOLLEYBALL                                  = 24,                       // 24,  -> "��������",
        HANDBALL                                    = 25,                       // 25,  -> "�������",
        EQUESTRIAN                                  = 26,                       // 26,  -> "������ �����",
        SPEED_SKATING                               = 27,                       // 27,  -> "������������ �����",
        TENNIS                                      = 28,                       // 28,  -> "������",
        WEIGHTLIFTING                               = 29,                       // 29,  -> "������� ��������",
        FENCING                                     = 30,                       // 30,  -> "����������",
        FIGURE_SKATING                              = 31,                       // 31,  -> "�������� �������",
        FOOTBALL                                    = 32,                       // 32,  -> "������",
        HOCKEY                                      = 33,                       // 33,  -> "������",
        SAMBO_JUDO                          = 34,                               // DELETE "�����-�����",
        WRESTLING                                   = 35,                       // 35,  -> "���������� ������",
        FOOTBALL_HOCKEY                     = 36,                               // DELETE "������ � ������",
        BIATHLON                                    = 37,                       // 37,  -> "�������",
        HEALTH_IMPROVING                            = 38,                       // 38,  -> "��������������� ���������� ��������",
        ADAPTIVE                                    = 39,                       // 39,  -> "���������� ���������� ��������",
        FREESTYLE_WRESTLING                         = 42,                       // 42,  -> "������� ������",
        GRECO_ROMAN_WRESTLING                       = 43,                       // 43,  -> "�����-������� ������",
        SAMBO                                       = 44,                       // 44,  -> "�����",
        JUDO                                        = 45,                       // 45,  -> "�����",
        TABLE_TENNIS_ABITURIENT             = 46,                               // NEW -> TABLE_TENNIS "������ ����������",
        TABLE_TENNIS                                = 46,                       // 46,  -> "������ ����������",
        ERGOTHERAPY                                 = 47,                       // 47,  -> "�����������",
        MANAGEMENT_SPORTS                           = 48,                       // 48,  -> "���������� � ������",
        SPORTS_DIRECTING_DEANERY            = 49,                               // DELETE "���������� ���������",
        SPORTS_RECREATIONAL_TOURISM                 = 50,                       // 50,  -> "���������� � ������������� ������",
        MANAGEMENT_TOURISM                          = 51,                       // 51,  -> "���������� � �������",
        SPORTS_PSYCHOLOGY                           = 52,                       // 52,  -> "���������� ����������",
        BILLIARD_SPORTS                             = 53,                       // 53,  -> "���������� �����",
        ACROBATICS                                  = 54,                       // 54,  -> "����������",
        ORIENTEERING                                = 55,                       // 55,  -> "���������� ��������������",
        SPORTS_DIRECTING                            = 56,                       // 56,  -> "���������� ���������",
        PRESCHOOLERS                                = 57,                       // 57,  -> "���������� �������� ������������",
        MOUNTAINEERING                              = 59,                       // 59,  -> "���������",
        SKI_COMBINED                                = 60,                       // 60,  -> "������ ���������",
        TOURISM_HOSPITALITY                         = 61,                       // 61,  -> "������ � ��������������",
        WATER_TECHNICAL_SPORTS                      = 62,                       // 62,  -> "�����-����������� ���� ������",
        MODEL_TECHNICAL_SPORTS                      = 63,                       // 63,  -> "��������-����������� ���� ������",
        ALPINE_SKIING                               = 64,                       // 64,  -> "����������� �����",
        BASEBALL                                    = 65,                       // 65,  -> "�������",
        WUSHU                                       = 66,                       // 66,  -> "���",
        CHESS                                       = 68,                       // 68,  -> "�������",
        THAI_BOXING                                 = 69,                       // 69,  -> "����������� ����",
        TOURISM_PROMOTION                           = 70,                       // 70,  -> "���������� ������������ � ����������� ������������� �����",
        TOURISM_IT                                  = 71,                       // 71,  -> "�������������� ���������� ������������� ���������",
        TOURISM_LOGISTICS                           = 72,                       // 72,  -> "��������� � ������������� ���������",
        TOURISM_SOCIAL                              = 73,                       // 73,  -> "���������� ���������������� ������� ��������",
        TOURISM_TRANSPORT                           = 74,                       // 74,  -> "���������� ������������� ������� ��������",
        TOURISM_FOOD                                = 75,                       // 75,  -> "���������� ������� ������� ��������",
        TOURIST_ACCOMMODATION                       = 76,                       // 76,  -> "���������� ������� ���������� ��������",
        TOURISM_EXCURSION                           = 77,                       // 77,  -> "���������� ������������-����������������� ������� ��������",
        TOURISM_HEALTH                              = 78,                       // 78,  -> "���������� ������� ������������ � ������� ��������",
        BULLET_SHOOTING                             = 79,                       // 79,  -> "�������� �������",
        FIELD_HOCKEY                                = 80,                       // 80,  -> "������ �� �����",
        FIGURE_SKATING_SKATES                       = 84,                       // 84,  -> "�������� ������� �� �������",
        ROWING_AND_CANOEING                         = 87,                       // 87,  -> "������ �� ��������� � �����",
        ACADEMIC_ROWING                             = 88,                       // 88,  -> "������ �������������",
        HAND_TO_HAND_MARTIAL_ARTS                   = 92,                       // 92,  -> "���������� ��� (��������� ������������)",
        BILLIARDS_RPC                       = 93,                               // NEW -> BILLIARDS "�������",
        BILLIARDS                                   = 93,                       // 93,  -> "�������",
        WITHOUT_SPECIALIZATION                      = 94,                       // 94,  -> "��� �������������",
        MEDICAL                             = 95,                               // DELETE "���������� ��������(��������)",
        MODERN_PENTATHLON                           = 96,                       // 96,  -> "����������� ���������",
        SPORTS_RECREATIONAL_TOURISM_OLD     = 100,                              // DELETE "���������� � ������������� ������"
        SCIENCE_HEALTH                              = 101,                      // 101, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        PHYSIOLOGY                                  = 102,                      // 102, -> "����������",
        SCIENCE_THEORY                              = 103,                      // 103, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        RECEARCH_SPORT                              = 104,                      // 104, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        INNOVATIVE_TOURISM                          = 105,                      // 105, -> "������������� ���������� � ����� �������",
        INNOVATIVE_HOSPITALITY                      = 106,                      // 106, -> "������������� ���������� � ����� ��������������",
        INNOVATIVE_TECHNOLOGIES                     = 107,                      // 107, -> "������������� ���������� � ����� ������� � ��������������",
        INNOVATIVE_MANAGEMENT                       = 108,                      // 108, -> "���������� �������������� ��������� � ���������� ���������",
        BILLIARDS_SMA                       = 109,                              // DELETE "�������",
        HAND_TO_HAND_COMBAT_SMA             = 110,                              // DELETE "���������� ��� (��������� ������������)",
        BADMINTON                                   = 116,                      // 116, -> "���������",
        TABLE_TENNIS_DEANERY                = 117,                              // DELETE "���������� ������",
        PHYSICAL_CULTURE_SPORT                      = 118,                      // 118, -> "���������� �������� � �����",
        TOURISM_HOSPITALITY_MASTER                  = 119,                      // 119, -> "������ � ��������������",
        SPORT_CLIMBING                              = 120,                      // 120, -> "������������ ����������",
        MASTER_ANTHROPOLOGY                         = 121,                      // 121, -> "������������",
        MASTER_MANAGEMENT                           = 122                       // 122  -> "����������",
    };

//    enum SectionCode
//    {
//        NSPEC_HIGH_SCHOOL_IMPROVING                 = 5,                            // 5,  -> "��������������� � ���������� ���������� ��������"     (�� ������������)
//        NSPEC_HIGH_SCHOOL_COACHING                  = 6,                            // 6,  -> "���������-�������������� ������������"                (�� ������������)
//        NSPEC_HIGH_SCHOOL_MANAGEMENT                = 7,                            // 7,  -> "���������-���������� ������������"                    (�� ������������)
//        NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE          = 8,                            // 8,  -> "���������� ��������"                                  (�� ������������)
//        NSPEC_HIGH_SCHOOL_REHABILITATION            = 9,                            // 9,  -> "���������� ������������ � �����������"                (�� ������������)
//        NSPEC_HIGH_SCHOOL_TOURISM                   = 10,                           // 10, -> "������ � ��������������"
//        NSPEC_MASTER_SCIENCE_THEORY                 = 11,                           // 11, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������"
//        NSPEC_MASTER_SCIENCE_PHYSIOLOGY             = 12,                           // 12, -> "����������"
//        NSPEC_MASTER_RESEARCH_SPORT                 = 13,                           // 13, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ��"
//        NSPEC_MASTER_INNOVATION_TOURISM             = 14,                           // 14, -> "������������� ���������� � ����� �������"
//        NSPEC_MASTER_INNOVATION_HOSPITALITY         = 15,                           // 15, -> "������������� ���������� � ����� ��������������"
//        NSPEC_MASTER_INNOVATION_TECHNOLOGY          = 16,                           // 16, -> "������������� ���������� � ����� ������� � ��������������"
//        NSPEC_MASTER_INNOVATION_MANAGEMENT          = 17,                           // 17, -> "���������� �������������� ��������� � ���������� ���������"
//        NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE      = 18,                           // 18, -> "���������� �������� � �����"
//        NSPEC_MASTER_RESEARCH_TOURISM               = 19,                           // 19, -> "������ � ��������������"
//        NSPEC_MASTER_RESEARCH_MANAGEMENT            = 20                            // 20  -> "����������"
//
//        #ifdef ADDITIONAL_SECTION
//        NSPEC_SPORTS_CHOREOGRAPHY                   = 21,                           // 21, -> "���������� �����������" (code: "1-88 02 74")
//        NSPEC_HIGH_SCHOOL_NATURE                    = 22,                           // 22, -> "������ � ������������������" (code: "1-89 02 02")
//        NSPEC_HOSPITALITY_TECHNOLOGIES              = 23                            // 23  -> "���������� ��������� �������������� (�� ������������)" (code: "1-89 03 01")
//        #endif
//    };

    enum DeaneryQualificationNameByNomerQu
    {
        TEACHER_PHYSICAL_CULTURE_SPORTS     = 1,
        COACHING_BY_SPORT                   = 2,
        PHYSICAL_EDUCATION_TEACHER          = 3,
        TEACHER_ORGANIZER_HEALTH_TOURISM    = 4,
        TEACHER_ORGANIZER_PRESCHOOLERS      = 5,
        MANAGER_SPORT_TOURISM               = 6,
        INSTRUCTOR_REHABILITATION           = 7,
        INSTRUCTOR_MEDICAL                  = 8,
        TEACHER_PHYSICAL_CULTURE            = 9,
        INSTRUCTOR_BY_HEALTH                = 10,
        INSTRUCTOR_BY_ADAPTIVE              = 11,
        INSTRUCTOR_PRESCHOOLERS             = 12,
        PSYCHOLOGIST                        = 13,
        MANAGER_SPORT                       = 14,
        MANAGER_TUORISM                     = 15,
        INSTRUCTOR_RECREATIONAL             = 16,
        MANAGER_DIRECTING                   = 17,
        INSTRUCTOR_BY_MEDICAL               = 18,
        INSTRUCTOR_BY_REHABILITATION        = 19,
        INSTRUCTOR_BY_ERGOTHERAPY           = 20,
        SPECIALIST_TOURISM_HOSPITALITY      = 21
    };
    enum DeanerySpecialityNSpecCode
    {
        PHYSICAL_CULTURE_SPORT_AUX          = 1,                                    // old code: "� 02.02.00"
        IMPROVING_AND_ADAPTIVE_AUX          = 5,                                    // old code: "1-88 01 02"
        SPORTS_AND_PEDAGOGY_AUX             = 6,                                    // old code: "1-88 02 01"
        SPORTS_AND_TOURISM_AUX              = 7,                                    // old code: "1-89 02 01"
        PHYSICAL_CULTURE_AUX                = 8,                                    // old code: "1-88 01 01"
        REHABILITATION_ERGOTHERAPY_AUX      = 9,                                    // old code: "1-88 01 03"
        TOURISM_HOSPITALITY_AUX             = 10,                                   // old code: "1-89 01 01"
        THEORY_IMPROVING_AUX                = 11,                                   // old code: "13.00.04"
        PHYSIOLOGY_AUX                      = 12,                                   // old code: "03.03.01"
        THEORY_ADAPTIVE_AUX                 = 13,                                   // old code: "1-08 80 04"
        INNOVATION_TOURISM_AUX              = 14,                                   // old code: "1-89 81 02"
        INNOVATION_HOSPITALITY_AUX          = 15,                                   // old code: "1-89 81 03"
        INNOVATION_TECHNOLOGY_AUX           = 16,                                   // old code: "1-89 81 04"
        INNOVATION_MANAGEMENT_AUX           = 17,                                   // old code: "1-89 81 01"
        MASTER_PHYSICAL_CULTURE_AUX         = 18,                                   // old code: "1-08 80 04"
        TOURISM_HOSPITALITY_STUDY_AUX       = 19,                                   // old code: "1-89 80 01"

        TRAINING_MILITARY_PERSONNEL_AUX     = 20,                                   // old code: "1-88 01 04"
        SPORTS_CHOREOGRAPHY_AUX             = 21,                                   // old code: "1-88 02 74"
        TOURISM_AND_NATURE_MANAGEMENT_AUX   = 22,                                   // old code: "1-89 02 02"
        HOSPITALITY_TECHNOLOGIES_AUX        = 23                                    // old code: "1-89 03 01"
    };
    enum ProfilingNcrb2022
    {
        IMPROVING_PROF                      = 1,
        HEALTH_PROF                         = 2,
        PRESCHOOLERS_PROF                   = 3,
        ADIAPTIVE_PROF                      = 4,
        DIRECTING_PROF                      = 5,
        PSYCHOLOGY_PROF                     = 6,
        RECRIATIONAL_PROF                   = 7,
        COACHING_PROF                       = 8,
        REHABILITATION_PROF                 = 9,
        ERGOTHERAPY_PROF                    = 10,
        SPORT_PROF                          = 11,
        TOURISM_PROF                        = 12,
        HOSPITALITY_PROF                    = 13
    };

#endif // ! ENUMS_FOR_NCRB_011_TEMPORARY_CONVERTER_H
