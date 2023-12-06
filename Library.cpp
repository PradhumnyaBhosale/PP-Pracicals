#include <iostream>
#include <cstring>

class Book {
private:
    char* author;
    char* title;
    float price;
    char* publisher;
    int stock;

public:
 
    Book(const char* author, const char* title, float price, const char* publisher, int stock) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);

        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->price = price;

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);

        this->stock = stock;
    }

  
    void displayDetails() const {
        std::cout << "Author: " << author << "\nTitle: " << title << "\nPrice: $" << price
                  << "\nPublisher: " << publisher << "\nStock: " << stock << std::endl;
    }

   
    void checkAvailability(int requiredCopies) const {
        if (requiredCopies <= stock) {
            float totalCost = requiredCopies * price;
            std::cout << "Available! Total cost for " << requiredCopies << " copies: $" << totalCost << std::endl;
        } else {
            std::cout << "Required copies not in stock." << std::endl;
        }
    }

    
    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }
};

int main() {
  
    Book book1("John Doe", "Programming Basics", 29.99, "TechBooks", 10);
    book1.displayDetails();

  
    book1.checkAvailability(5);

    return 0;
}
