#pragma once

#include <string>
#include <vector>

class UserProfile
{
private:
    std::string preferredCategory;
    std::string preferredLevel;
    std::vector<std::string> interests;

public:
    UserProfile(
        const std::string& preferredCategory,
        const std::string& preferredLevel,
        const std::vector<std::string>& interests
    );

    std::string getPreferredCategory() const;
    std::string getPreferredLevel() const;
    std::vector<std::string> getInterests() const;
};
