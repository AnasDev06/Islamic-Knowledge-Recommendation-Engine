#pragma once

#include <string>
#include <vector>

class Reciter
{
private:
    int id;
    std::string name;
    std::string style;
    std::vector<std::string> tags;

public:
    Reciter(
        int id,
        const std::string& name,
        const std::string& style,
        const std::vector<std::string>& tags
    );

    int getId() const;
    std::string getName() const;
    std::string getStyle() const;
    std::vector<std::string> getTags() const;

    bool hasTag(const std::string& tag) const;
};
