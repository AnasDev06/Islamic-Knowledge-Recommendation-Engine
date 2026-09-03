#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Scholar.h"
#include "Reciter.h"
#include "UserProfile.h"
#include "RecommendationEngine.h"

void printHeader(const std::string& title)
{
    std::cout << "\n============================================\n";
    std::cout << " " << title << "\n";
    std::cout << "============================================\n";
}

std::string chooseCategory()
{
    int choice;

    std::cout << "\nChoose your main interest:\n";
    std::cout << "1. Aqeedah\n";
    std::cout << "2. Hadith\n";
    std::cout << "3. Tafsir\n";
    std::cout << "4. Fiqh\n";
    std::cout << "5. Seerah\n";
    std::cout << "6. Tazkiyah\n";
    std::cout << "7. Quran\n";
    std::cout << "Choose: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1: return "Aqeedah";
    case 2: return "Hadith";
    case 3: return "Tafsir";
    case 4: return "Fiqh";
    case 5: return "Seerah";
    case 6: return "Tazkiyah";
    case 7: return "Quran";
    default: return "Aqeedah";
    }
}

std::string chooseLevel()
{
    int choice;

    std::cout << "\nChoose your level:\n";
    std::cout << "1. Beginner\n";
    std::cout << "2. Intermediate\n";
    std::cout << "3. Advanced\n";
    std::cout << "Choose: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1: return "Beginner";
    case 2: return "Intermediate";
    case 3: return "Advanced";
    default: return "Beginner";
    }
}

void printBooks(const std::vector<BookRecommendation>& results)
{
    printHeader("Recommended Books");

    for (size_t i = 0; i < results.size(); ++i)
    {
        std::cout << i + 1 << ". " << results[i].book.getTitle() << "\n";
        std::cout << "   Author   : " << results[i].book.getAuthor() << "\n";
        std::cout << "   Category : " << results[i].book.getCategory() << "\n";
        std::cout << "   Level    : " << results[i].book.getLevel() << "\n";
        std::cout << "   Score    : " << results[i].score << "\n\n";
    }
}

void printScholars(const std::vector<ScholarRecommendation>& results)
{
    printHeader("Recommended Scholars");

    for (size_t i = 0; i < results.size(); ++i)
    {
        std::cout << i + 1 << ". " << results[i].scholar.getName() << "\n";
        std::cout << "   Field : " << results[i].scholar.getField() << "\n";
        std::cout << "   Level : " << results[i].scholar.getLevel() << "\n";
        std::cout << "   Score : " << results[i].score << "\n\n";
    }
}

void printReciters(const std::vector<ReciterRecommendation>& results)
{
    printHeader("Recommended Quran Reciters");

    for (size_t i = 0; i < results.size(); ++i)
    {
        std::cout << i + 1 << ". " << results[i].reciter.getName() << "\n";
        std::cout << "   Style : " << results[i].reciter.getStyle() << "\n";
        std::cout << "   Score : " << results[i].score << "\n\n";
    }
}

int main()
{
    printHeader("SALAFI KNOWLEDGE RECOMMENDATION ENGINE");

    std::vector<Book> books =
    {
        Book(1, "Kitab at-Tawhid", "Muhammad ibn Abd al-Wahhab",
            "Aqeedah", "Beginner", {"Tawhid", "Aqeedah", "Ibadah"}),

        Book(2, "Al-Usool ath-Thalathah", "Muhammad ibn Abd al-Wahhab",
            "Aqeedah", "Beginner", {"Tawhid", "Aqeedah", "Foundations"}),

        Book(3, "Al-Qawa'id al-Arba'", "Muhammad ibn Abd al-Wahhab",
            "Aqeedah", "Beginner", {"Tawhid", "Aqeedah", "Shirk"}),

        Book(4, "Al-Aqidah al-Wasitiyyah", "Ibn Taymiyyah",
            "Aqeedah", "Intermediate", {"Aqeedah", "Sunnah", "Attributes"}),

        Book(5, "Lum'at al-I'tiqad", "Ibn Qudamah",
            "Aqeedah", "Intermediate", {"Aqeedah", "Sunnah"}),

        Book(6, "Zad al-Ma'ad", "Ibn al-Qayyim",
            "Seerah", "Advanced", {"Seerah", "Fiqh", "Sunnah"}),

        Book(7, "Al-Wabil as-Sayyib", "Ibn al-Qayyim",
            "Tazkiyah", "Intermediate", {"Tazkiyah", "Dhikr", "Ibadah"}),

        Book(8, "Bulugh al-Maram", "Ibn Hajar al-Asqalani",
            "Hadith", "Advanced", {"Hadith", "Fiqh", "Sunnah"}),

        Book(9, "Tafsir as-Sa'di", "Abd al-Rahman al-Sa'di",
            "Tafsir", "Intermediate", {"Tafsir", "Quran"}),

        Book(10, "Umdat al-Ahkam", "Abd al-Ghani al-Maqdisi",
            "Hadith", "Intermediate", {"Hadith", "Fiqh", "Sunnah"})
    };

    std::vector<Scholar> scholars =
    {
        Scholar(1, "Ibn Taymiyyah", "Aqeedah",
            "Intermediate", {"Aqeedah", "Sunnah", "Fiqh"}),

        Scholar(2, "Ibn al-Qayyim", "Tazkiyah",
            "Intermediate", {"Tazkiyah", "Fiqh", "Sunnah"}),

        Scholar(3, "Muhammad ibn Abd al-Wahhab", "Aqeedah",
            "Beginner", {"Aqeedah", "Tawhid", "Sunnah"}),

        Scholar(4, "Abd al-Aziz ibn Baz", "Fiqh",
            "Intermediate", {"Fiqh", "Hadith", "Aqeedah"}),

        Scholar(5, "Muhammad ibn Salih al-Uthaymeen", "Fiqh",
            "Intermediate", {"Fiqh", "Aqeedah", "Hadith"}),

        Scholar(6, "Salih al-Fawzan", "Aqeedah",
            "Advanced", {"Aqeedah", "Fiqh", "Sunnah"}),

        Scholar(7, "Abd al-Rahman al-Sa'di", "Tafsir",
            "Intermediate", {"Tafsir", "Quran", "Fiqh"}),

        Scholar(8, "Muhammad Nasir al-Din al-Albani", "Hadith",
            "Advanced", {"Hadith", "Sunnah", "Fiqh"})
    };

    std::vector<Reciter> reciters =
    {
        Reciter(1, "Mahmoud Khalil Al-Husary", "Precise and measured",
            {"Quran", "Tajweed", "Slow"}),

        Reciter(2, "Muhammad Siddiq Al-Minshawi", "Highly expressive",
            {"Quran", "Tajweed", "Reflective"}),

        Reciter(3, "Abdul Basit Abdus-Samad", "Powerful and melodic",
            {"Quran", "Tajweed", "Melodic"}),

        Reciter(4, "Mahmoud Khalil Al-Husary (Murattal)", "Murattal",
            {"Quran", "Tajweed", "Slow"}),

        Reciter(5, "Salah Bukhatir", "Clear and calm",
            {"Quran", "Calm", "Reflective"}),

        Reciter(6, "Saad Al-Ghamdi", "Calm and balanced",
            {"Quran", "Calm", "Reflective"})
    };

    std::string category = chooseCategory();
    std::string level = chooseLevel();

    std::vector<std::string> interests = { category };

    if (category == "Aqeedah")
    {
        interests.push_back("Tawhid");
        interests.push_back("Sunnah");
    }
    else if (category == "Hadith")
    {
        interests.push_back("Hadith");
        interests.push_back("Sunnah");
    }
    else if (category == "Quran")
    {
        interests.push_back("Tajweed");
        interests.push_back("Reflective");
    }
    else if (category == "Tafsir")
    {
        interests.push_back("Quran");
        interests.push_back("Tafsir");
    }
    else if (category == "Fiqh")
    {
        interests.push_back("Fiqh");
        interests.push_back("Sunnah");
    }
    else if (category == "Seerah")
    {
        interests.push_back("Seerah");
        interests.push_back("Sunnah");
    }
    else if (category == "Tazkiyah")
    {
        interests.push_back("Tazkiyah");
        interests.push_back("Dhikr");
    }

    UserProfile user(category, level, interests);
    RecommendationEngine engine;

    printBooks(engine.recommendBooks(books, user));

    // Scholars use their field as the matching category.
    printScholars(engine.recommendScholars(scholars, user));

    printReciters(engine.recommendReciters(reciters, user));

    printHeader("Recommendation Complete");
    std::cout << "The results were ranked using a weighted scoring algorithm.\n";

    return 0;
}
