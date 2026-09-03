#include "Scholar.h"

Scholar::Scholar(
    int id,
    const std::string& name,
    const std::string& field,
    const std::string& level,
    const std::vector<std::string>& tags
)
    : id(id),
      name(name),
      field(field),
      level(level),
      tags(tags)
{
}

int Scholar::getId() const
{
    return id;
}

std::string Scholar::getName() const
{
    return name;
}

std::string Scholar::getField() const
{
    return field;
}

std::string Scholar::getLevel() const
{
    return level;
}

std::vector<std::string> Scholar::getTags() const
{
    return tags;
}

bool Scholar::hasTag(const std::string& tag) const
{
    for (const std::string& currentTag : tags)
    {
        if (currentTag == tag)
        {
            return true;
        }
    }

    return false;
}
