#pragma once

#include <string>
#include <vector>

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    std::string category;
    std::string level;
    std::vector<std::string> tags;

public:
    Book(
        int id,
        const std::string& title,
        const std::string& author,
        const std::string& category,
        const std::string& level,
        const std::vector<std::string>& tags
    );

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getCategory() const;
    std::string getLevel() const;
    std::vector<std::string> getTags() const;
};