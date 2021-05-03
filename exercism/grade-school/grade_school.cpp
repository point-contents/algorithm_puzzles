#include "grade_school.h"
#include <map>
#include <vector>
#include <string>
#include <algorithm>

namespace grade_school {
    bool compare_strings(std::string a, std::string b) { return a < b ;}

    void school::school::add(std::string student_name, int student_grade) {
        auto it = m_school_roster.find(student_grade);
        if(it == m_school_roster.end()) {
            std::vector<std::string> student_names = { student_name };
            m_school_roster.insert(std::pair<int,std::vector<std::string>>(student_grade, student_names));
        } else {
            std::vector<std::string> grade_names_vector = it->second;
            grade_names_vector.push_back(student_name);
            std::sort(grade_names_vector.begin(), grade_names_vector.end(), compare_strings);
            it->second = grade_names_vector;
        }
    }

    std::vector<std::string> school::school::grade(int student_grades) const {
        auto it = m_school_roster.find(student_grades);
        if(it != m_school_roster.end()) {
            return it->second;
        } else {
            return {};
        }
    }

    std::map<int, std::vector<std::string>> school::school::roster() const {
        return school::m_school_roster;
    }
}  // namespace grade_school
