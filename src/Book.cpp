#include "Book.h"

Book::Book(
    int id,
    const std::string& title,
    const std::string& author,
    const std::string& category,
    const std::string& level,
    const std::vector<std::string>& tags
)
    : id(id),
    title(title),
    author(author),
    category(category),
    level(level),
    tags(tags)
{}

int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getCategory() const
{
    return category;
}

std::string Book::getLevel() const
{
    return level;
}

std::vector<std::string> Book::getTags() const
{
    return tags;
}