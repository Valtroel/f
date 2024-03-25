#pragma once
#ifndef ENUMS_HPP
#define ENUMS_HPP


#ifndef STATE_FROM_WORK_PC
    #ifndef NEW_INTEGRATION
        enum ContestTypeCode
        {
            GENERAL                             = 0,
            OUT_OF_COMPETITION                  = 1,
            WITHOUT_ENTRANCE_EXAMS              = 2,
            TARGETED_TRAINING                   = 3
        };
        enum Default
        {
            EMPTY                               = 0,
            START                               = 0,
            DISABLE                             = 0,
            STEP                                = 1,
            ENABLE                              = 1,
            LOOPS_MAX_ITERATIONS                = 2
        };
        enum EducationTypeCode
        {
            INTRAMURAL                          = 0,
            EXTRAMURAL                          = 1
        };
        enum FacultyCode
        {
            SMA                                 = 1,                                    // Sports and Marital Arts (����)
            MS                                  = 2,                                    // Mass Sports (���)
            RPC                                 = 3,                                    // Recreational Physical Culture (�����)
            MSTH                                = 4,                                    // Management of Sports, Tourism and Hospitality (����)
            MD                                  = 5,                                    // Master's Degree (�����������)
            PGS                                 = 6,                                    // PostGraduate Studies (�����������)
            DOC                                 = 7                                     // DOCtorate (������������)
        };
        enum FormTypeCode
        {
            REGISTRATION                        = 1,
            ENROLLMENT                          = 2
        };
        enum PaymentCode
        {
            BUDGET                              = 0,
            BUYERS                              = 1
        };
        enum SportsRanksCode
        {
            THIRD_SPORT_CATEGORY                = 1,                                    // 1  -> 3 ������
            SECOND_SPORT_CATEGORY               = 2,                                    // 2  -> 2 ������
            FIRST_SPORT_CATEGORY                = 3,                                    // 3  -> 1 ������
            CANDIDATE_IN_MASTERS_OF_SPORT       = 4,                                    // 4  -> ���
            MASTER_OF_SPORT                     = 5,                                    // 5  -> ��
            INTERNATIONAL_MASTER_OF_SPORTS      = 6,                                    // 6  -> ����
            HONORED_MASTER_OF_SPORTS            = 7,                                    // 7  -> ���
            THIRD_APPRENTICESHIP_DEGREE         = 8,                                    // 8  -> 3 ��
            SECOND_APPRENTICESHIP_DEGREE        = 9,                                    // 9  -> 2 ��
            FIRST_APPRENTICESHIP_DEGREE         = 10,                                   // 10 -> 1 ��
            FIRST_YOUTH_CATEGORY                = 11,                                   // 11 -> 1 ��������� ������
            WITHOUT                             = 12,                                   // 12 -> ���
            SECOND_YOUTH_CATEGORY               = 13
        };
        enum StudyPeriodCode
        {
            FULL                                = 0,                                    // "������ ����"
            SHORT_SECOND_COURSE                 = 1,                                    // "C���������� ���� (2 ����)"
            SHORT_THIRD_COURSE                  = 2,                                    // "C���������� ���� (3 ����)"
            HIGH_FIRST_COURSE                   = 3,                                    // "������ ����������� (1 ����)"
            HIGH_SECOND_COURSE                  = 4,                                    // "������ ����������� (2 ����)"
            HIGH_THIRD_COURSE                   = 5                                     // "������ ����������� (3 ����)"
        };
        enum SubjectCode
        {
            RUS                                 = 0,
            BEL                                 = 1
        };

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
        enum DirectionNcrb2022Code
        {
            PHYSICAL_CULTURE_2022               = 1,                                    // 6-05-1012-01
            COACHING_2022                       = 2,                                    // 6-05-1012-02
            REHABILITATION_2022                 = 3,                                    // 6-05-1012-03
            MANAGEMENT_2022                     = 4,                                    // 6-05-1012-04
            TOURISM_2022                        = 5                                     // 6-05-1013-01
        };
        enum KindOfSportCode
        {
            GYMNASTICS                          = 1,                                    // "����������",
            MANAGEMENT_SPORTS_TOURISM           = 2,                                    // "���������� ������ � �������",
            PHYSICAL_REHABILITATION             = 3,                                    // "���������� ������������",
            THERAPEUTIC                         = 4,                                    // "�������� ���������� ��������",
            ORGANIZATION_SPORTS_TOURISM         = 5,                                    // "����������� ������������-��������������� ������ � �������",
            PRESCHOOL_PHYSICAL_EDUCATION        = 6,                                    // "���������� ���������� ����������",
            DANCE_SPORT                         = 7,                                    // "������������ �����",
            AEROBICS                            = 8,                                    // "��������",
            ROWING_OTHER                        = 9,                                    // "������� �����",
            SWIMMING                            = 10,                                   // "��������",
            SAILING                             = 11,                                   // "�������� �����",
            ATHLETICS                           = 12,                                   // "������ ��������",
            CROSS_COUNTRY_SKIING                = 13,                                   // "������ �����",
            BULLET_SHOOTING_DEANERY             = 14,                                   // "������� ��������",
            HAND_TO_HAND_COMBAT                 = 15,                                   // "���������� ���",
            TAEKWONDO                           = 16,                                   // "���������",
            KARATE                              = 17,                                   // "������",
            SKIING                              = 18,                                   // "������ �����",
            AUTOMOTIVE_SPORT                    = 19,                                   // "������������� �����",
            BASKETBALL                          = 20,                                   // "���������",
            BOXING                              = 21,                                   // "����",
            GRECO_FREESTYLE_WRESTLING           = 22,                                   // "�����-������� � ������� ������",
            CYCLING                             = 23,                                   // "������������ �����",
            VOLLEYBALL                          = 24,                                   // "��������",
            HANDBALL                            = 25,                                   // "�������",
            EQUESTRIAN                          = 26,                                   // "������ �����",
            SPEED_SKATING                       = 27,                                   // "������������ �����",
            TENNIS                              = 28,                                   // "������",
            WEIGHTLIFTING                       = 29,                                   // "������� ��������",
            FENCING                             = 30,                                   // "����������",
            FIGURE_SKATING_OLD                  = 31,                                   // FIGURE_SKATING "�������� �������",
            FOOTBALL                            = 32,                                   // "������",
            HOCKEY                              = 33,                                   // "������",
            SAMBO_JUDO                          = 34,                                   // "�����-�����",
            WRESTLING                           = 35,                                   // "���������� ������",
            FOOTBALL_HOCKEY                     = 36,                                   // "������ � ������",
            BIATHLON                            = 37,                                   // "�������",
            HEALTH_IMPROVING                    = 38,                                   // "��������������� ���������� ��������",
            ADAPTIVE                            = 39,                                   // "���������� ���������� ��������",
            FREESTYLE_WRESTLING                 = 42,                                   // "������� ������",
            GRECO_ROMAN_WRESTLING               = 43,                                   // "�����-������� ������",
            SAMBO                               = 44,                                   // "�����",
            JUDO                                = 45,                                   // "�����",
            TABLE_TENNIS_ABITURIENT             = 46,                                   // "������ ����������",
            ERGOTHERAPY                         = 47,                                   // "�����������",
            MANAGEMENT_SPORTS                   = 48,                                   // "���������� � ������",
            SPORTS_DIRECTING_DEANERY            = 49,                                   // "���������� ���������",
            SPORTS_RECREATIONAL_TOURISM         = 50,                                   // "���������� � ������������� ������",
            MANAGEMENT_TOURISM                  = 51,                                   // "���������� � �������",
            SPORTS_PSYCHOLOGY                   = 52,                                   // "���������� ����������",
            BILLIARD_SPORTS                     = 53,                                   // "���������� �����",
            ACROBATICS                          = 54,                                   // "����������",
            ORIENTEERING                        = 55,                                   // "���������� ��������������",
            SPORTS_DIRECTING                    = 56,                                   // "���������� ���������",
            PRESCHOOLERS                        = 57,                                   // "���������� �������� ������������",
            MOUNTAINEERING                      = 59,                                   // "���������",
            SKI_COMBINED                        = 60,                                   // "������ ���������",
            TOURISM_HOSPITALITY                 = 61,                                   // "������ � ��������������",
            WATER_TECHNICAL_SPORTS              = 62,                                   // "�����-����������� ���� ������",
            MODEL_TECHNICAL_SPORTS              = 63,                                   // "��������-����������� ���� ������",
            ALPINE_SKIING                       = 64,                                   // "����������� �����",
            BASEBALL                            = 65,                                   // "�������",
            WUSHU                               = 66,                                   // "���",
            CHESS                               = 68,                                   // "�������",
            THAI_BOXING                         = 69,                                   // "����������� ����",
            TOURISM_PROMOTION                   = 70,                                   // "���������� ������������ � ����������� ������������� �����",
            TOURISM_IT                          = 71,                                   // "�������������� ���������� ������������� ���������",
            TOURISM_LOGISTICS                   = 72,                                   // "��������� � ������������� ���������",
            TOURISM_SOCIAL                      = 73,                                   // "���������� ���������������� ������� ��������",
            TOURISM_TRANSPORT                   = 74,                                   // "���������� ������������� ������� ��������",
            TOURISM_FOOD                        = 75,                                   // "���������� ������� ������� ��������",
            TOURIST_ACCOMMODATION               = 76,                                   // "���������� ������� ���������� ��������",
            TOURISM_EXCURSION                   = 77,                                   // "���������� ������������-����������������� ������� ��������",
            TOURISM_HEALTH                      = 78,                                   // "���������� ������� ������������ � ������� ��������",
            BULLET_SHOOTING                     = 79,                                   // "�������� �������",
            FIELD_HOCKEY                        = 80,                                   // "������ �� �����",
            FIGURE_SKATING                      = 84,                                   // "�������� ������� �� �������",
            ROWING_AND_CANOEING                 = 87,                                   // "������ �� ��������� � �����",
            ACADEMIC_ROWING                     = 88,                                   // "������ �������������",
            HAND_TO_HAND_COMBAT_MS              = 92,                                   // "���������� ��� (��������� ������������)",
            BILLIARDS_RPC                       = 93,                                   // "�������",
            WITHOUT_SPECIALIZATION              = 94,                                   // "��� �������������",
            MEDICAL                             = 95,                                   // "���������� ��������(��������)",
            MODERN_PENTATHLON                   = 96,                                   // "����������� ���������",
            SPORTS_RECREATIONAL_TOURISM_OLD     = 100,                                  // "���������� � ������������� ������"
            SCIENCE_HEALTH                      = 101,                                  // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            PHYSIOLOGY                          = 102,                                  // "����������",
            SCIENCE_THEORY                      = 103,                                  // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            RECEARCH_SPORT                      = 104,                                  // "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            INNOVATIVE_TOURISM                  = 105,                                  // "������������� ���������� � ����� �������",
            INNOVATIVE_HOSPITALITY              = 106,                                  // "������������� ���������� � ����� ��������������",
            INNOVATIVE_TECHNOLOGIES             = 107,                                  // "������������� ���������� � ����� ������� � ��������������",
            INNOVATIVE_MANAGEMENT               = 108,                                  // "���������� �������������� ��������� � ���������� ���������",
            BILLIARDS_SMA                       = 109,                                  // "�������",
            HAND_TO_HAND_COMBAT_SMA             = 110,                                  // "���������� ��� (��������� ������������)",
            BADMINTON                           = 116,                                  // "���������",
            TABLE_TENNIS_DEANERY                = 117,                                  // "���������� ������",
            PHYSICAL_CULTURE_SPORT              = 118,                                  // "���������� �������� � �����",
            TOURISM_HOSPITALITY_MASTER          = 119,                                  // "������ � ��������������",
            SPORT_CLIMBING                      = 120,                                  // "������������ ����������",
            MASTER_ANTHROPOLOGY                 = 121,                                  // "������������",
            MASTER_MANAGEMENT                   = 122                                   // "����������",
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
    #else
        enum ContestTypeCode
        {
            GENERAL                                     = 0,
            WITHOUT_ENTRANCE_EXAMS                      = 1,
            OUT_OF_COMPETITION                          = 2,
            TARGETED_TRAINING                           = 3
        };
        enum Default
        {
            EMPTY                                       = 0,
            START                                       = 0,
            DISABLE                                     = 0,
            STEP                                        = 1,
            ENABLE                                      = 1,
            LOOPS_MAX_ITERATIONS                        = 2
        };
        enum EducationTypeCode
        {
            INTRAMURAL                                  = 0,
            EXTRAMURAL                                  = 1
        };
        enum FacultyCode
        {
            SMA                                         = 1,                            // 1, -> Sports and Marital Arts (����)
            MS                                          = 2,                            // 2, -> Mass Sports (���)
            RPC                                         = 3,                            // 3, -> Recreational Physical Culture (�����)
            MSTH                                        = 4,                            // 4, -> Management of Sports, Tourism and Hospitality (����)
            MD                                          = 5,                            // 5, -> Master's Degree (�����������)
            PGS                                         = 6,                            // 6, -> PostGraduate Studies (�����������)
            DOC                                         = 7                             // 7  -> DOCtorate (������������)
        };
        enum FormTypeCode
        {
            REGISTRATION                                = 1,
            ENROLLMENT                                  = 2
        };
        enum LineThicknessCode
        {
            THIN                                        = 1,
            MEDIUM                                      = 2,
            WIDE                                        = 3,
            EXTRA_WIDE                                  = 4
        };
        enum PaymentCode
        {
            BUDGET                                      = 0,
            BUYERS                                      = 1
        };
        enum SportsRanksCode
        {
            THIRD_SPORT_CATEGORY                        = 1,                            // 1  -> 3 ������
            SECOND_SPORT_CATEGORY                       = 2,                            // 2  -> 2 ������
            FIRST_SPORT_CATEGORY                        = 3,                            // 3  -> 1 ������
            CANDIDATE_IN_MASTERS_OF_SPORT               = 4,                            // 4  -> ���
            MASTER_OF_SPORT                             = 5,                            // 5  -> ��
            INTERNATIONAL_MASTER_OF_SPORTS              = 6,                            // 6  -> ����
            HONORED_MASTER_OF_SPORTS                    = 7,                            // 7  -> ���
            THIRD_APPRENTICESHIP_DEGREE                 = 8,                            // 8  -> 3 ��
            SECOND_APPRENTICESHIP_DEGREE                = 9,                            // 9  -> 2 ��
            FIRST_APPRENTICESHIP_DEGREE                 = 10,                           // 10 -> 1 ��
            FIRST_YOUTH_CATEGORY                        = 11,                           // 11 -> 1 ��������� ������
            WITHOUT                                     = 12,                           // 12 -> ���
            SECOND_YOUTH_CATEGORY                       = 13                            // 13 -> 2 ��������� ������
        };
        enum StudyPeriodCode
        {
            FULL                                        = 0,                            // 0, -> "������ ����"
            SHORT_SECOND_COURSE                         = 1,                            // 1, -> "C���������� ���� (2 ����)"
            SHORT_THIRD_COURSE                          = 2,                            // 2, -> "C���������� ���� (3 ����)"
            HIGH_FIRST_COURSE                           = 3,                            // 3, -> "������ ����������� (1 ����)"
            HIGH_SECOND_COURSE                          = 4,                            // 4, -> "������ ����������� (2 ����)"
            HIGH_THIRD_COURSE                           = 5                             // 5  -> "������ ����������� (3 ����)"
        };
        enum SubjectCode
        {
            RUS                                         = 0,
            BEL                                         = 1
        };
        enum TypeLineCode
        {
            REGULAR_LINE                                = 1,
            SMALL_DOTTED_LINE                           = 2,
            LARGE_DOTTED_LINE                           = 3,
            ONE_LONG_ONE_SHORT                          = 4,
            ONE_LONG_TWO_SHORT                          = 5,
            DOUBLE_LINE                                 = 9
        };

        enum KindOfSportCode
        {
            GYMNASTICS                                  = 1,                            // 1,   -> "����������",
            MANAGEMENT_SPORTS_TOURISM                   = 2,                            // 2,   -> "���������� ������ � �������",
            PHYSICAL_REHABILITATION                     = 3,                            // 3,   -> "���������� ������������",
            THERAPEUTIC                                 = 4,                            // 4,   -> "�������� ���������� ��������",
            ORGANIZATION_SPORTS_TOURISM                 = 5,                            // 5,   -> "����������� ������������-��������������� ������ � �������",
            PRESCHOOL_PHYSICAL_EDUCATION                = 6,                            // 6,   -> "���������� ���������� ����������",
            DANCE_SPORT                                 = 7,                            // 7,   -> "������������ �����",
            AEROBICS                                    = 8,                            // 8,   -> "��������",
            ROWING_OTHER                                = 9,                            // 9,   -> "������� �����",
            SWIMMING                                    = 10,                           // 10,  -> "��������",
            SAILING                                     = 11,                           // 11,  -> "�������� �����",
            ATHLETICS                                   = 12,                           // 12,  -> "������ ��������",
            CROSS_COUNTRY_SKIING                        = 13,                           // 13,  -> "������ �����",
            BULLET_SHOOTING_DEANERY                     = 14,                           // 14,  -> "������� ��������",
            HAND_TO_HAND_COMBAT                         = 15,                           // 15,  -> "���������� ���",
            TAEKWONDO                                   = 16,                           // 16,  -> "���������",
            KARATE                                      = 17,                           // 17,  -> "������",
            SKIING                                      = 18,                           // 18,  -> "������ �����",
            AUTOMOTIVE_SPORT                            = 19,                           // 19,  -> "������������� �����",
            BASKETBALL                                  = 20,                           // 20,  -> "���������",
            BOXING                                      = 21,                           // 21,  -> "����",
            GRECO_FREESTYLE_WRESTLING                   = 22,                           // 22,  -> "�����-������� � ������� ������",
            CYCLING                                     = 23,                           // 23,  -> "������������ �����",
            VOLLEYBALL                                  = 24,                           // 24,  -> "��������",
            HANDBALL                                    = 25,                           // 25,  -> "�������",
            EQUESTRIAN                                  = 26,                           // 26,  -> "������ �����",
            SPEED_SKATING                               = 27,                           // 27,  -> "������������ �����",
            TENNIS                                      = 28,                           // 28,  -> "������",
            WEIGHTLIFTING                               = 29,                           // 29,  -> "������� ��������",
            FENCING                                     = 30,                           // 30,  -> "����������",
            FIGURE_SKATING                              = 31,                           // 31,  -> FIGURE_SKATING "�������� �������",
            FOOTBALL                                    = 32,                           // 32,  -> "������",
            HOCKEY                                      = 33,                           // 33,  -> "������",
            WRESTLING                                   = 35,                           // 35,  -> "���������� ������",
            BIATHLON                                    = 37,                           // 37,  -> "�������",
            HEALTH_IMPROVING                            = 38,                           // 38,  -> "��������������� ���������� ��������",
            ADAPTIVE                                    = 39,                           // 39,  -> "���������� ���������� ��������",
            FREESTYLE_WRESTLING                         = 42,                           // 42,  -> "������� ������",
            GRECO_ROMAN_WRESTLING                       = 43,                           // 43,  -> "�����-������� ������",
            SAMBO                                       = 44,                           // 44,  -> "�����",
            JUDO                                        = 45,                           // 45,  -> "�����",
            TABLE_TENNIS                                = 46,                           // 46,  -> "������ ����������",
            ERGOTHERAPY                                 = 47,                           // 47,  -> "�����������",
            MANAGEMENT_SPORTS                           = 48,                           // 48,  -> "���������� � ������",
            SPORTS_RECREATIONAL_TOURISM                 = 50,                           // 50,  -> "���������� � ������������� ������",
            MANAGEMENT_TOURISM                          = 51,                           // 51,  -> "���������� � �������",
            SPORTS_PSYCHOLOGY                           = 52,                           // 52,  -> "���������� ����������",
            BILLIARD_SPORTS                             = 53,                           // 53,  -> "���������� �����",
            ACROBATICS                                  = 54,                           // 54,  -> "����������",
            ORIENTEERING                                = 55,                           // 55,  -> "���������� ��������������",
            SPORTS_DIRECTING                            = 56,                           // 56,  -> "���������� ���������",
            PRESCHOOLERS                                = 57,                           // 57,  -> "���������� �������� ������������",
            MOUNTAINEERING                              = 59,                           // 59,  -> "���������",
            SKI_COMBINED                                = 60,                           // 60,  -> "������ ���������",
            TOURISM_HOSPITALITY                         = 61,                           // 61,  -> "������ � ��������������",
            WATER_TECHNICAL_SPORTS                      = 62,                           // 62,  -> "�����-����������� ���� ������",
            MODEL_TECHNICAL_SPORTS                      = 63,                           // 63,  -> "��������-����������� ���� ������",
            ALPINE_SKIING                               = 64,                           // 64,  -> "����������� �����",
            BASEBALL                                    = 65,                           // 65,  -> "�������",
            WUSHU                                       = 66,                           // 66,  -> "���",
            CHESS                                       = 68,                           // 68,  -> "�������",
            THAI_BOXING                                 = 69,                           // 69,  -> "����������� ����",
            TOURISM_PROMOTION                           = 70,                           // 70,  -> "���������� ������������ � ����������� ������������� �����",
            TOURISM_IT                                  = 71,                           // 71,  -> "�������������� ���������� ������������� ���������",
            TOURISM_LOGISTICS                           = 72,                           // 72,  -> "��������� � ������������� ���������",
            TOURISM_SOCIAL                              = 73,                           // 73,  -> "���������� ���������������� ������� ��������",
            TOURISM_TRANSPORT                           = 74,                           // 74,  -> "���������� ������������� ������� ��������",
            TOURISM_FOOD                                = 75,                           // 75,  -> "���������� ������� ������� ��������",
            TOURIST_ACCOMMODATION                       = 76,                           // 76,  -> "���������� ������� ���������� ��������",
            TOURISM_EXCURSION                           = 77,                           // 77,  -> "���������� ������������-����������������� ������� ��������",
            TOURISM_HEALTH                              = 78,                           // 78,  -> "���������� ������� ������������ � ������� ��������",
            BULLET_SHOOTING                             = 79,                           // 79,  -> "�������� �������",
            FIELD_HOCKEY                                = 80,                           // 80,  -> "������ �� �����",
            FIGURE_SKATING_SKATES                       = 84,                           // 84,  -> "�������� ������� �� �������",
            ROWING_AND_CANOEING                         = 87,                           // 87,  -> "������ �� ��������� � �����",
            ACADEMIC_ROWING                             = 88,                           // 88,  -> "������ �������������",
            HAND_TO_HAND_MARTIAL_ARTS                   = 92,                           // 92,  -> "���������� ��� (��������� ������������)",
            BILLIARDS                                   = 93,                           // 93,  -> "�������",
            WITHOUT_SPECIALIZATION                      = 94,                           // 94,  -> "��� �������������",
            MODERN_PENTATHLON                           = 96,                           // 96,  -> "����������� ���������",
            SCIENCE_HEALTH                              = 101,                          // 101, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            PHYSIOLOGY                                  = 102,                          // 102, -> "����������",
            SCIENCE_THEORY                              = 103,                          // 103, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            RECEARCH_SPORT                              = 104,                          // 104, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
            INNOVATIVE_TOURISM                          = 105,                          // 105, -> "������������� ���������� � ����� �������",
            INNOVATIVE_HOSPITALITY                      = 106,                          // 106, -> "������������� ���������� � ����� ��������������",
            INNOVATIVE_TECHNOLOGIES                     = 107,                          // 107, -> "������������� ���������� � ����� ������� � ��������������",
            INNOVATIVE_MANAGEMENT                       = 108,                          // 108, -> "���������� �������������� ��������� � ���������� ���������",
            BADMINTON                                   = 116,                          // 116, -> "���������",
            PHYSICAL_CULTURE_SPORT                      = 118,                          // 118, -> "���������� �������� � �����",
            TOURISM_HOSPITALITY_MASTER                  = 119,                          // 119, -> "������ � ��������������",
            SPORT_CLIMBING                              = 120,                          // 120, -> "������������ ����������",
            MASTER_ANTHROPOLOGY                         = 121,                          // 121, -> "������������",
            MASTER_MANAGEMENT                           = 122                           // 122  -> "����������",
        };
        enum Profiling2022Code
        {
            IMPROVING_PROF                              = 1,
            HEALTH_PROF                                 = 2,
            PRESCHOOLERS_PROF                           = 3,
            ADIAPTIVE_PROF                              = 4,
            DIRECTING_PROF                              = 5,
            PSYCHOLOGY_PROF                             = 6,
            RECRIATIONAL_PROF                           = 7,
            COACHING_PROF                               = 8,
            REHABILITATION_PROF                         = 9,
            ERGOTHERAPY_PROF                            = 10,
            SPORT_PROF                                  = 11,
            TOURISM_PROF                                = 12,
            HOSPITALITY_PROF                            = 13
        };
        enum ProfilingCode                                                              // INSTEAD OF DeanerySpecialDirectionNSpecDirCode
        {
            NSPECDIR_SPORT_COACHING                     = 1,                            // 1,  -> "���������� ������ ��",
            NSPECDIR_SPORT_PSYCHOLOGY                   = 2,                            // 2,  -> "���������� ����������",
            NSPECDIR_SPORT_DIRECTING                    = 3,                            // 3,  -> "���������� ���������",
            NSPECDIR_SPORT_MANAGEMENT                   = 4,                            // 4,  -> "���������� � ������",
            NSPECDIR_MANAGEMENT_RECREATIONAL            = 5,                            // 5,  -> "���������� � ������������� ������",
            NSPECDIR_MANAGEMENT_TOURISM_MNG             = 6,                            // 6,  -> "���������� � �������",
            NSPECDIR_PHYSICAL_CULTURE_MEDICAL           = 7,                            // 7,  -> "��������",
            NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS      = 8,                            // 8,  -> "������������",
            NSPECDIR_IMPROVING_HEALTH                   = 9,                            // 9,  -> "���������������",
            NSPECDIR_IMPROVING_ADAPTIVE                 = 10,                           // 10, -> "����������",
            NSPECDIR_REHABILITATION_REHABILITATION      = 11,                           // 11, -> "���������� ������������",
            NSPECDIR_REHABILITATION_ERGOTHERAPY         = 12,                           // 12, -> "�����������",
            NSPECDIR_TOURISM_HOSPITALITY                = 13,                           // 13, -> "������ � ��������������",
            NSPECDIR_TOURISM_PROMOTION                  = 14,                           // 14, -> "���������� ������������ � ����������� ������������� �����",
            NSPECDIR_TOURISM_IT                         = 15,                           // 15, -> "�������������� ���������� ������������� ���������",
            NSPECDIR_TOURISM_LOGISTICS                  = 16,                           // 16, -> "��������� � ������������� ���������",
            NSPECDIR_TOURISM_SOCIAL                     = 17,                           // 17, -> "���������� ���������������� ������ ��������",
            NSPECDIR_TOURISM_TRANSPORT                  = 18,                           // 18, -> "���������� ������������� ������� ��������",
            NSPECDIR_TOURISM_CATERING                   = 19,                           // 19, -> "���������� ������� ������� ��������",
            NSPECDIR_TOURISM_ACCOMMODATION              = 20,                           // 20, -> "���������� ������� ���������� ��������",
            NSPECDIR_TOURISM_SUPPORTING                 = 21,                           // 21, -> "���������� ������������-����������������� ������� ��������",
            NSPECDIR_TOURISM_TREATMENT                  = 22,                           // 22, -> "���������� ������� ������������ � ������� ��������",
            NSPECDIR_MASTER_SCIENCE_THEORY              = 23,                           // 23, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ���������� ��������.",
            NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY          = 24,                           // 24, -> "����������",
            NSPECDIR_MASTER_RESEARCH_SPORT              = 25,                           // 25, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ���������� ��������.",
            NSPECDIR_MASTER_INNOVATION_TOURISM          = 26,                           // 26, -> "������������� ���������� � ����� �������",
            NSPECDIR_MASTER_INNOVATION_HOSPITALITY      = 27,                           // 27, -> "������������� ���������� � ����� ��������������",
            NSPECDIR_MASTER_INNOVATION_TECHNOLOGY       = 28,                           // 28, -> "������������� ���������� � ����� ������� � ��������������",
            NSPECDIR_MASTER_INNOVATION_MANAGEMENT       = 29,                           // 29, -> "���������� �������������� ��������� � ���������� ���������",
            NSPECDIR_MASTER_RESEARCH_MANAGEMENT         = 30,                           // 30, -> "����������",
            NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE   = 31,                           // 31, -> "���������� �������� � �����",
            NSPECDIR_MASTER_RESEARCH_TOURISM            = 32                            // 32  -> "������ � ��������������";
        };
        enum Section2022Code                                                            // INSTEAD OF DirectionNcrb2022Code
        {
            PHYSICAL_CULTURE_2022                       = 0,                            // 1, -> 6-05-1012-01
            COACHING_2022                               = 1,                            // 2, -> 6-05-1012-02
            REHABILITATION_2022                         = 2,                            // 3, -> 6-05-1012-03
            MANAGEMENT_2022                             = 3,                            // 4, -> 6-05-1012-04
            TOURISM_2022                                = 4                             // 5  -> 6-05-1013-01
        };
        enum SectionCode
        {
            NSPEC_HIGH_SCHOOL_IMPROVING                 = 5,                            // 5,  -> "��������������� � ���������� ���������� ��������"     (�� ������������)
            NSPEC_HIGH_SCHOOL_COACHING                  = 6,                            // 6,  -> "���������-�������������� ������������"                (�� ������������)
            NSPEC_HIGH_SCHOOL_MANAGEMENT                = 7,                            // 7,  -> "���������-���������� ������������"                    (�� ������������)
            NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE          = 8,                            // 8,  -> "���������� ��������"                                  (�� ������������)
            NSPEC_HIGH_SCHOOL_REHABILITATION            = 9,                            // 9,  -> "���������� ������������ � �����������"                (�� ������������)
            NSPEC_HIGH_SCHOOL_TOURISM                   = 10,                           // 10, -> "������ � ��������������"
            NSPEC_MASTER_SCIENCE_THEORY                 = 11,                           // 11, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������"
            NSPEC_MASTER_SCIENCE_PHYSIOLOGY             = 12,                           // 12, -> "����������"
            NSPEC_MASTER_RESEARCH_SPORT                 = 13,                           // 13, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ��"
            NSPEC_MASTER_INNOVATION_TOURISM             = 14,                           // 14, -> "������������� ���������� � ����� �������"
            NSPEC_MASTER_INNOVATION_HOSPITALITY         = 15,                           // 15, -> "������������� ���������� � ����� ��������������"
            NSPEC_MASTER_INNOVATION_TECHNOLOGY          = 16,                           // 16, -> "������������� ���������� � ����� ������� � ��������������"
            NSPEC_MASTER_INNOVATION_MANAGEMENT          = 17,                           // 17, -> "���������� �������������� ��������� � ���������� ���������"
            NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE      = 18,                           // 18, -> "���������� �������� � �����"
            NSPEC_MASTER_RESEARCH_TOURISM               = 19,                           // 19, -> "������ � ��������������"
            NSPEC_MASTER_RESEARCH_MANAGEMENT            = 20                            // 20  -> "����������"
            #ifdef ADDITIONAL_SECTION
            NSPEC_SPORTS_CHOREOGRAPHY                   = 21,                           // 21, -> "���������� �����������" (code: "1-88 02 74")
            NSPEC_HIGH_SCHOOL_NATURE                    = 22,                           // 22, -> "������ � ������������������" (code: "1-89 02 02")
            NSPEC_HOSPITALITY_TECHNOLOGIES              = 23                            // 23  -> "���������� ��������� �������������� (�� ������������)" (code: "1-89 03 01")
            #endif  // ADDITIONAL_SECTION
        };
    #endif // ! NEW_INTEGRATION
#else
    enum ContestTypeCode
    {
        GENERAL                                     = 0,
        WITHOUT_ENTRANCE_EXAMS                      = 1,
        OUT_OF_COMPETITION                          = 2,
        TARGETED_TRAINING                           = 3
    };
    enum Default
    {
        EMPTY                                       = 0,
        START                                       = 0,
        DISABLE                                     = 0,
        STEP                                        = 1,
        ENABLE                                      = 1,
        LOOPS_MAX_ITERATIONS                        = 2
    };
    enum EducationTypeCode
    {
        INTRAMURAL                                  = 0,
        EXTRAMURAL                                  = 1
    };
    enum FacultyCode
    {
        SMA                                         = 1,                            // 1, -> Sports and Marital Arts (����)
        MS                                          = 2,                            // 2, -> Mass Sports (���)
        RPC                                         = 3,                            // 3, -> Recreational Physical Culture (�����)
        MSTH                                        = 4,                            // 4, -> Management of Sports, Tourism and Hospitality (����)
        MD                                          = 5,                            // 5, -> Master's Degree (�����������)
        PGS                                         = 6,                            // 6, -> PostGraduate Studies (�����������)
        DOC                                         = 7                             // 7  -> DOCtorate (������������)
    };
    enum FormTypeCode
    {
        REGISTRATION                                = 1,
        ENROLLMENT                                  = 2
    };
    enum LineThicknessCode
    {
        THIN                                        = 1,
        MEDIUM                                      = 2,
        WIDE                                        = 3,
        EXTRA_WIDE                                  = 4
    };
    enum PaymentCode
    {
        BUDGET                                      = 0,
        BUYERS                                      = 1
    };
    enum SportsRanksCode
    {
        THIRD_SPORT_CATEGORY                        = 1,                            // 1  -> 3 ������
        SECOND_SPORT_CATEGORY                       = 2,                            // 2  -> 2 ������
        FIRST_SPORT_CATEGORY                        = 3,                            // 3  -> 1 ������
        CANDIDATE_IN_MASTERS_OF_SPORT               = 4,                            // 4  -> ���
        MASTER_OF_SPORT                             = 5,                            // 5  -> ��
        INTERNATIONAL_MASTER_OF_SPORTS              = 6,                            // 6  -> ����
        HONORED_MASTER_OF_SPORTS                    = 7,                            // 7  -> ���
        THIRD_APPRENTICESHIP_DEGREE                 = 8,                            // 8  -> 3 ��
        SECOND_APPRENTICESHIP_DEGREE                = 9,                            // 9  -> 2 ��
        FIRST_APPRENTICESHIP_DEGREE                 = 10,                           // 10 -> 1 ��
        FIRST_YOUTH_CATEGORY                        = 11,                           // 11 -> 1 ��������� ������
        WITHOUT                                     = 12,                           // 12 -> ���
        SECOND_YOUTH_CATEGORY                       = 13                            // 13 -> 2 ��������� ������
    };
    enum StudyPeriodCode
    {
        FULL                                        = 0,                            // 0, -> "������ ����"
        SHORT_SECOND_COURSE                         = 1,                            // 1, -> "C���������� ���� (2 ����)"
        SHORT_THIRD_COURSE                          = 2,                            // 2, -> "C���������� ���� (3 ����)"
        HIGH_FIRST_COURSE                           = 3,                            // 3, -> "������ ����������� (1 ����)"
        HIGH_SECOND_COURSE                          = 4,                            // 4, -> "������ ����������� (2 ����)"
        HIGH_THIRD_COURSE                           = 5                             // 5  -> "������ ����������� (3 ����)"
    };
    enum SubjectCode
    {
        RUS                                         = 0,
        BEL                                         = 1
    };
    enum TypeLineCode
    {
        REGULAR_LINE                                = 1,
        SMALL_DOTTED_LINE                           = 2,
        LARGE_DOTTED_LINE                           = 3,
        ONE_LONG_ONE_SHORT                          = 4,
        ONE_LONG_TWO_SHORT                          = 5,
        DOUBLE_LINE                                 = 9
    };

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
    #ifndef DELETE_PREVIOUS_VERSION_OF_KOS
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
    #endif  // ! DELETE_PREVIOUS_VERSION_OF_KOS
    enum KindOfSportCode                                                            // UPDATED. TODO: Delete previous version
    {
        GYMNASTICS                                  = 1,                            // 1,   -> "����������",
        MANAGEMENT_SPORTS_TOURISM                   = 2,                            // 2,   -> "���������� ������ � �������",
        PHYSICAL_REHABILITATION                     = 3,                            // 3,   -> "���������� ������������",
        THERAPEUTIC                                 = 4,                            // 4,   -> "�������� ���������� ��������",
        ORGANIZATION_SPORTS_TOURISM                 = 5,                            // 5,   -> "����������� ������������-��������������� ������ � �������",
        PRESCHOOL_PHYSICAL_EDUCATION                = 6,                            // 6,   -> "���������� ���������� ����������",
        DANCE_SPORT                                 = 7,                            // 7,   -> "������������ �����",
        AEROBICS                                    = 8,                            // 8,   -> "��������",
        ROWING_OTHER                                = 9,                            // 9,   -> "������� �����",
        SWIMMING                                    = 10,                           // 10,  -> "��������",
        SAILING                                     = 11,                           // 11,  -> "�������� �����",
        ATHLETICS                                   = 12,                           // 12,  -> "������ ��������",
        CROSS_COUNTRY_SKIING                        = 13,                           // 13,  -> "������ �����",
        BULLET_SHOOTING_DEANERY                     = 14,                           // 14,  -> "������� ��������",
        HAND_TO_HAND_COMBAT                         = 15,                           // 15,  -> "���������� ���",
        TAEKWONDO                                   = 16,                           // 16,  -> "���������",
        KARATE                                      = 17,                           // 17,  -> "������",
        SKIING                                      = 18,                           // 18,  -> "������ �����",
        AUTOMOTIVE_SPORT                            = 19,                           // 19,  -> "������������� �����",
        BASKETBALL                                  = 20,                           // 20,  -> "���������",
        BOXING                                      = 21,                           // 21,  -> "����",
        GRECO_FREESTYLE_WRESTLING                   = 22,                           // 22,  -> "�����-������� � ������� ������",
        CYCLING                                     = 23,                           // 23,  -> "������������ �����",
        VOLLEYBALL                                  = 24,                           // 24,  -> "��������",
        HANDBALL                                    = 25,                           // 25,  -> "�������",
        EQUESTRIAN                                  = 26,                           // 26,  -> "������ �����",
        SPEED_SKATING                               = 27,                           // 27,  -> "������������ �����",
        TENNIS                                      = 28,                           // 28,  -> "������",
        WEIGHTLIFTING                               = 29,                           // 29,  -> "������� ��������",
        FENCING                                     = 30,                           // 30,  -> "����������",
        #ifdef DATABASE_SUBSTITUTE
            FIGURE_SKATING                              = 31,                           // 31,  -> "�������� �������",
        #endif // DATABASE_SUBSTITUTE
        FOOTBALL                                    = 32,                           // 32,  -> "������",
        HOCKEY                                      = 33,                           // 33,  -> "������",
        WRESTLING                                   = 35,                           // 35,  -> "���������� ������",
        BIATHLON                                    = 37,                           // 37,  -> "�������",
        HEALTH_IMPROVING                            = 38,                           // 38,  -> "��������������� ���������� ��������",
        ADAPTIVE                                    = 39,                           // 39,  -> "���������� ���������� ��������",
        FREESTYLE_WRESTLING                         = 42,                           // 42,  -> "������� ������",
        GRECO_ROMAN_WRESTLING                       = 43,                           // 43,  -> "�����-������� ������",
        SAMBO                                       = 44,                           // 44,  -> "�����",
        JUDO                                        = 45,                           // 45,  -> "�����",
        TABLE_TENNIS                                = 46,                           // 46,  -> "������ ����������",
        ERGOTHERAPY                                 = 47,                           // 47,  -> "�����������",
        MANAGEMENT_SPORTS                           = 48,                           // 48,  -> "���������� � ������",
        SPORTS_RECREATIONAL_TOURISM                 = 50,                           // 50,  -> "���������� � ������������� ������",
        MANAGEMENT_TOURISM                          = 51,                           // 51,  -> "���������� � �������",
        SPORTS_PSYCHOLOGY                           = 52,                           // 52,  -> "���������� ����������",
        BILLIARD_SPORTS                             = 53,                           // 53,  -> "���������� �����",
        ACROBATICS                                  = 54,                           // 54,  -> "����������",
        ORIENTEERING                                = 55,                           // 55,  -> "���������� ��������������",
        SPORTS_DIRECTING                            = 56,                           // 56,  -> "���������� ���������",
        PRESCHOOLERS                                = 57,                           // 57,  -> "���������� �������� ������������",
        MOUNTAINEERING                              = 59,                           // 59,  -> "���������",
        SKI_COMBINED                                = 60,                           // 60,  -> "������ ���������",
        TOURISM_HOSPITALITY                         = 61,                           // 61,  -> "������ � ��������������",
        WATER_TECHNICAL_SPORTS                      = 62,                           // 62,  -> "�����-����������� ���� ������",
        MODEL_TECHNICAL_SPORTS                      = 63,                           // 63,  -> "��������-����������� ���� ������",
        ALPINE_SKIING                               = 64,                           // 64,  -> "����������� �����",
        BASEBALL                                    = 65,                           // 65,  -> "�������",
        WUSHU                                       = 66,                           // 66,  -> "���",
        CHESS                                       = 68,                           // 68,  -> "�������",
        THAI_BOXING                                 = 69,                           // 69,  -> "����������� ����",
        TOURISM_PROMOTION                           = 70,                           // 70,  -> "���������� ������������ � ����������� ������������� �����",
        TOURISM_IT                                  = 71,                           // 71,  -> "�������������� ���������� ������������� ���������",
        TOURISM_LOGISTICS                           = 72,                           // 72,  -> "��������� � ������������� ���������",
        TOURISM_SOCIAL                              = 73,                           // 73,  -> "���������� ���������������� ������� ��������",
        TOURISM_TRANSPORT                           = 74,                           // 74,  -> "���������� ������������� ������� ��������",
        TOURISM_FOOD                                = 75,                           // 75,  -> "���������� ������� ������� ��������",
        TOURIST_ACCOMMODATION                       = 76,                           // 76,  -> "���������� ������� ���������� ��������",
        TOURISM_EXCURSION                           = 77,                           // 77,  -> "���������� ������������-����������������� ������� ��������",
        TOURISM_HEALTH                              = 78,                           // 78,  -> "���������� ������� ������������ � ������� ��������",
        BULLET_SHOOTING                             = 79,                           // 79,  -> "�������� �������",
        FIELD_HOCKEY                                = 80,                           // 80,  -> "������ �� �����",
        FIGURE_SKATING_SKATES                       = 84,                           // 84,  -> "�������� ������� �� �������",
        ROWING_AND_CANOEING                         = 87,                           // 87,  -> "������ �� ��������� � �����",
        ACADEMIC_ROWING                             = 88,                           // 88,  -> "������ �������������",
        HAND_TO_HAND_MARTIAL_ARTS                   = 92,                           // 92,  -> "���������� ��� (��������� ������������)",
        BILLIARDS                                   = 93,                           // 93,  -> "�������",
        WITHOUT_SPECIALIZATION                      = 94,                           // 94,  -> "��� �������������",
        MODERN_PENTATHLON                           = 96,                           // 96,  -> "����������� ���������",
        SCIENCE_HEALTH                              = 101,                          // 101, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        PHYSIOLOGY                                  = 102,                          // 102, -> "����������",
        SCIENCE_THEORY                              = 103,                          // 103, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        RECEARCH_SPORT                              = 104,                          // 104, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������",
        INNOVATIVE_TOURISM                          = 105,                          // 105, -> "������������� ���������� � ����� �������",
        INNOVATIVE_HOSPITALITY                      = 106,                          // 106, -> "������������� ���������� � ����� ��������������",
        INNOVATIVE_TECHNOLOGIES                     = 107,                          // 107, -> "������������� ���������� � ����� ������� � ��������������",
        INNOVATIVE_MANAGEMENT                       = 108,                          // 108, -> "���������� �������������� ��������� � ���������� ���������",
        BADMINTON                                   = 116,                          // 116, -> "���������",
        PHYSICAL_CULTURE_SPORT                      = 118,                          // 118, -> "���������� �������� � �����",
        TOURISM_HOSPITALITY_MASTER                  = 119,                          // 119, -> "������ � ��������������",
        SPORT_CLIMBING                              = 120,                          // 120, -> "������������ ����������",
        MASTER_ANTHROPOLOGY                         = 121,                          // 121, -> "������������",
        MASTER_MANAGEMENT                           = 122                           // 122  -> "����������",

        #ifndef DELETE_PREVIOUS_VERSION_OF_KOS
            ,
            FIGURE_SKATING_OLD                  = 31,                                   // NEW -> FIGURE_SKATING "�������� �������",
            SAMBO_JUDO                          = 34,                                   // DELETE "�����-�����",
            FOOTBALL_HOCKEY                     = 36,                                   // DELETE "������ � ������",
            TABLE_TENNIS_ABITURIENT             = 46,                                   // NEW -> TABLE_TENNIS "������ ����������",
            SPORTS_DIRECTING_DEANERY            = 49,                                   // DELETE "���������� ���������",
            #ifndef DATABASE_SUBSTITUTE
                FIGURE_SKATING                      = 84,                                   // NEW -> FIGURE_SKATING_SKATES "�������� ������� �� �������",
            #endif  // ! DATABASE_SUBSTITUTE
            HAND_TO_HAND_COMBAT_MS              = 92,                                   // NEW -> HAND_TO_HAND_MARTIAL_ARTS "���������� ��� (��������� ������������)",
            BILLIARDS_RPC                       = 93,                                   // NEW -> BILLIARDS "�������",
            MEDICAL                             = 95,                                   // DELETE "���������� ��������(��������)",
            SPORTS_RECREATIONAL_TOURISM_OLD     = 100,                                  // DELETE "���������� � ������������� ������"
            BILLIARDS_SMA                       = 109,                                  // DELETE "�������",
            HAND_TO_HAND_COMBAT_SMA             = 110,                                  // DELETE "���������� ��� (��������� ������������)",
            TABLE_TENNIS_DEANERY                = 117                                   // DELETE "���������� ������",
        #endif  // ! DELETE_PREVIOUS_VERSION_OF_KOS
    };
    enum ProfilingCode                                                              // INSTEAD OF DeanerySpecialDirectionNSpecDirCode
    {
        NSPECDIR_SPORT_COACHING                     = 1,                            // 1,  -> "���������� ������ ��",
        NSPECDIR_SPORT_PSYCHOLOGY                   = 2,                            // 2,  -> "���������� ����������",
        NSPECDIR_SPORT_DIRECTING                    = 3,                            // 3,  -> "���������� ���������",
        NSPECDIR_SPORT_MANAGEMENT                   = 4,                            // 4,  -> "���������� � ������",
        NSPECDIR_MANAGEMENT_RECREATIONAL            = 5,                            // 5,  -> "���������� � ������������� ������",
        NSPECDIR_MANAGEMENT_TOURISM_MNG             = 6,                            // 6,  -> "���������� � �������",
        NSPECDIR_PHYSICAL_CULTURE_MEDICAL           = 7,                            // 7,  -> "��������",
        NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS      = 8,                            // 8,  -> "������������",
        NSPECDIR_IMPROVING_HEALTH                   = 9,                            // 9,  -> "���������������",
        NSPECDIR_IMPROVING_ADAPTIVE                 = 10,                           // 10, -> "����������",
        NSPECDIR_REHABILITATION_REHABILITATION      = 11,                           // 11, -> "���������� ������������",
        NSPECDIR_REHABILITATION_ERGOTHERAPY         = 12,                           // 12, -> "�����������",
        NSPECDIR_TOURISM_HOSPITALITY                = 13,                           // 13, -> "������ � ��������������",
        NSPECDIR_TOURISM_PROMOTION                  = 14,                           // 14, -> "���������� ������������ � ����������� ������������� �����",
        NSPECDIR_TOURISM_IT                         = 15,                           // 15, -> "�������������� ���������� ������������� ���������",
        NSPECDIR_TOURISM_LOGISTICS                  = 16,                           // 16, -> "��������� � ������������� ���������",
        NSPECDIR_TOURISM_SOCIAL                     = 17,                           // 17, -> "���������� ���������������� ������ ��������",
        NSPECDIR_TOURISM_TRANSPORT                  = 18,                           // 18, -> "���������� ������������� ������� ��������",
        NSPECDIR_TOURISM_CATERING                   = 19,                           // 19, -> "���������� ������� ������� ��������",
        NSPECDIR_TOURISM_ACCOMMODATION              = 20,                           // 20, -> "���������� ������� ���������� ��������",
        NSPECDIR_TOURISM_SUPPORTING                 = 21,                           // 21, -> "���������� ������������-����������������� ������� ��������",
        NSPECDIR_TOURISM_TREATMENT                  = 22,                           // 22, -> "���������� ������� ������������ � ������� ��������",
        NSPECDIR_MASTER_SCIENCE_THEORY              = 23,                           // 23, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ���������� ��������.",
        NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY          = 24,                           // 24, -> "����������",
        NSPECDIR_MASTER_RESEARCH_SPORT              = 25,                           // 25, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ���������� ��������.",
        NSPECDIR_MASTER_INNOVATION_TOURISM          = 26,                           // 26, -> "������������� ���������� � ����� �������",
        NSPECDIR_MASTER_INNOVATION_HOSPITALITY      = 27,                           // 27, -> "������������� ���������� � ����� ��������������",
        NSPECDIR_MASTER_INNOVATION_TECHNOLOGY       = 28,                           // 28, -> "������������� ���������� � ����� ������� � ��������������",
        NSPECDIR_MASTER_INNOVATION_MANAGEMENT       = 29,                           // 29, -> "���������� �������������� ��������� � ���������� ���������",
        NSPECDIR_MASTER_RESEARCH_MANAGEMENT         = 30,                           // 30, -> "����������",
        NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE   = 31,                           // 31, -> "���������� �������� � �����",
        NSPECDIR_MASTER_RESEARCH_TOURISM            = 32                            // 32  -> "������ � ��������������";
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
    enum Section2022Code                                                            // INSTEAD OF DirectionNcrb2022Code
    {
        PHYSICAL_CULTURE_2022                       = 0,                            // 1, -> 6-05-1012-01
        COACHING_2022                               = 1,                            // 2, -> 6-05-1012-02
        REHABILITATION_2022                         = 2,                            // 3, -> 6-05-1012-03
        MANAGEMENT_2022                             = 3,                            // 4, -> 6-05-1012-04
        TOURISM_2022                                = 4                             // 5  -> 6-05-1013-01
    };
    enum SectionCode
    {
        NSPEC_HIGH_SCHOOL_IMPROVING                 = 5,                            // 5,  -> "��������������� � ���������� ���������� ��������"     (�� ������������)
        NSPEC_HIGH_SCHOOL_COACHING                  = 6,                            // 6,  -> "���������-�������������� ������������"                (�� ������������)
        NSPEC_HIGH_SCHOOL_MANAGEMENT                = 7,                            // 7,  -> "���������-���������� ������������"                    (�� ������������)
        NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE          = 8,                            // 8,  -> "���������� ��������"                                  (�� ������������)
        NSPEC_HIGH_SCHOOL_REHABILITATION            = 9,                            // 9,  -> "���������� ������������ � �����������"                (�� ������������)
        NSPEC_HIGH_SCHOOL_TOURISM                   = 10,                           // 10, -> "������ � ��������������"
        NSPEC_MASTER_SCIENCE_THEORY                 = 11,                           // 11, -> "������ � �������� ����������� ����������, ���������� ����������, ���������������"
        NSPEC_MASTER_SCIENCE_PHYSIOLOGY             = 12,                           // 12, -> "����������"
        NSPEC_MASTER_RESEARCH_SPORT                 = 13,                           // 13, -> "������ � �������� ����������� ����������, ���������� ����������, ��������������� � ���������� ��"
        NSPEC_MASTER_INNOVATION_TOURISM             = 14,                           // 14, -> "������������� ���������� � ����� �������"
        NSPEC_MASTER_INNOVATION_HOSPITALITY         = 15,                           // 15, -> "������������� ���������� � ����� ��������������"
        NSPEC_MASTER_INNOVATION_TECHNOLOGY          = 16,                           // 16, -> "������������� ���������� � ����� ������� � ��������������"
        NSPEC_MASTER_INNOVATION_MANAGEMENT          = 17,                           // 17, -> "���������� �������������� ��������� � ���������� ���������"
        NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE      = 18,                           // 18, -> "���������� �������� � �����"
        NSPEC_MASTER_RESEARCH_TOURISM               = 19,                           // 19, -> "������ � ��������������"
        NSPEC_MASTER_RESEARCH_MANAGEMENT            = 20                            // 20  -> "����������"

        #ifdef ADDITIONAL_SECTION
        NSPEC_SPORTS_CHOREOGRAPHY                   = 21,                           // 21, -> "���������� �����������" (code: "1-88 02 74")
        NSPEC_HIGH_SCHOOL_NATURE                    = 22,                           // 22, -> "������ � ������������������" (code: "1-89 02 02")
        NSPEC_HOSPITALITY_TECHNOLOGIES              = 23                            // 23  -> "���������� ��������� �������������� (�� ������������)" (code: "1-89 03 01")
        #endif
    };
#endif // ! STATE_FROM_WORK_PC


#endif // ENUMS_HPP