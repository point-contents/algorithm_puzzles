#include <map>
#include <vector>
#include <string>

#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

namespace grade_school {
    class school {
        std::map<int,std::vector<std::string>> m_school_roster;

        public:
            school() { m_school_roster = {};}

            std::map<int, std::vector<std::string>> roster () const;
            void add(std::string student_name, int student_grade);
            std::vector<std::string> grade(int student_grades) const;
    };
}  // namespace grade_school

#endif // GRADE_SCHOOL_H
