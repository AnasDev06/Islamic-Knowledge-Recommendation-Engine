#include "UserProfile.h"

UserProfile::UserProfile(
    const std::string& preferredCategory,
    const std::string& preferredLevel,
    const std::vector<std::string>& interests
)
    : preferredCategory(preferredCategory),
      preferredLevel(preferredLevel),
      interests(interests)
{
}

std::string UserProfile::getPreferredCategory() const
{
    return preferredCategory;
}

std::string UserProfile::getPreferredLevel() const
{
    return preferredLevel;
}

std::vector<std::string> UserProfile::getInterests() const
{
    return interests;
}
