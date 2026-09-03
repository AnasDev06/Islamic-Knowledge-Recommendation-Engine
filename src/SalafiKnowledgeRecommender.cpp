#include <iostream>
#include "Book.h"

int main()
{
    Book book(
        1,
        "Kitab at-Tawhid",
        "Muhammad ibn Abd al-Wahhab",
        "Aqeedah",
        "Beginner",
        { "Tawhid", "Aqeedah", "Ibadah" }
    );

    std::cout << "Book ID: " << book.getId() << '\n';
    std::cout << "Title: " << book.getTitle() << '\n';
    std::cout << "Author: " << book.getAuthor() << '\n';
    std::cout << "Category: " << book.getCategory() << '\n';
    std::cout << "Level: " << book.getLevel() << '\n';

    std::cout << "Tags: ";

    for (const std::string& tag : book.getTags())
    {
        std::cout << tag << ", ";
    }

    std::cout << '\n';

    return 0;
}