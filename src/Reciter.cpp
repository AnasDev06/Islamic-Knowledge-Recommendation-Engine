#include "Reciter.h"

Reciter::Reciter(
    int id,
    const std::string& name,
    const std::string& style,
    const std::vector<std::string>& tags
)
    : id(id),
      name(name),
      style(style),
      tags(tags)
{
}

int Reciter::getId() const
{
    return id;
}

std::string Reciter::getName() const
{
    return name;
}

std::string Reciter::getStyle() const
{
    return style;
}

std::vector<std::string> Reciter::getTags() const
{
    return tags;
}

bool Reciter::hasTag(const std::string& tag) const
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
