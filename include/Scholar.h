#pragma once

#include <string>
#include <vector>

class Scholar
{
private:
    int id;
    std::string name;
    std::string field;
    std::string level;
    std::vector<std::string> tags;

public:
    Scholar(
        int id,
        const std::string& name,
        const std::string& field,
        const std::string& level,
        const std::vector<std::string>& tags
    );

    int getId() const;
    std::string getName() const;
    std::string getField() const;
    std::string getLevel() const;
    std::vector<std::string> getTags() const;

    bool hasTag(const std::string& tag) const;
};
