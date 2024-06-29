#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Matrix {
public:
    Matrix(){}
    std::vector<std::vector<int>> data;

    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols, 0)) {}

    void print() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << ' ';
            }
            std::cout << '\n';
        }
    }
};

struct Book {
    std::string ID, Author, Title;
    int Pages;
};

int countWordOccurrences(const std::string& word, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != std::string::npos) {
            ++count;
            pos += word.length();
        }
    }
    return count;
}

void writeMatrixToFile(const Matrix& matrix, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    for (const auto& row : matrix.data) {
        for (int val : row) {
            file << val << ' ';
        }
        file << '\n';
    }
}

Matrix readMatrixFromFile(const std::string& filename) {
    Matrix matrix;
    std::ifstream file(filename);
    for (auto& row : matrix.data) {
        for (int& val : row) {
            file >> val;
        }
    }
    return matrix;
}

void addBook(std::vector<Book>& books) {
    Book newBook;
    std::cout << "Enter ID: ";
    std::cin >> newBook.ID;
    std::cout << "Enter author: ";
    std::cin >> newBook.Author;
    std::cout << "Enter Name: ";
    std::cin >> newBook.Title;
    std::cout << "Enter number of pages: ";
    std::cin >> newBook.Pages;
    books.push_back(newBook);

    std::ofstream file("books.txt", std::ios::app); 
    file << newBook.ID << " " << newBook.Author << " " << newBook.Title << " " << newBook.Pages << std::endl;
}

void viewBooks() {
    std::ifstream file("books.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}
void deleteBook(std::vector<Book>& books) {
    std::string ID;
    std::cout << "Enter the book ID to delete: ";
    std::cin >> ID;
    bool found = false;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->ID == ID) {
            books.erase(it);
            found = true;
            break;
        }
    }
    if (found) {
        std::ofstream file("books.txt");
        for (const auto& book : books) {
            file << book.ID << " " << book.Author << " " << book.Title << " " << book.Pages << std::endl;
        }
        std::cout << "Book with ID " << ID << " has been deleted." << std::endl;
    } else {
        std::cout << "Book with ID " << ID << " not found." << std::endl;
    }
}


void searchBook(const std::string& ID) {
    std::ifstream file("books.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string bookID, author, title;
        int pages;
        if (!(iss >> bookID >> author >> title >> pages)) { break; }
        if (bookID == ID) {
            std::cout << bookID << " " << author << " " << title << " " << pages << std::endl;
            break;
        }
    }
}

void editBook(std::vector<Book>& books) {
    std::string ID;
    std::cout << "Enter the book ID to edit: ";
    std::cin >> ID;
    bool found = false;
    for (auto& book : books) {
        if (book.ID == ID) {
            std::cout << "Enter a new name: ";
            std::cin >> book.Title;
            std::cout << "Enter new number of pages: ";
            std::cin >> book.Pages;
            found = true;
            break;
        }
    }
    if (found) {
        std::ofstream file("books.txt");
        for (const auto& book : books) {
            file << book.ID << " " << book.Author << " " << book.Title << " " << book.Pages << std::endl;
        }
        std::cout << "Book with ID " << ID << " has been updated." << std::endl;
    } else {
        std::cout << "Book with ID " << ID << " not found." << std::endl;
    }
}

int main() {
    std::string word = "example";
    std::string filename = "text.txt";
    int count = countWordOccurrences(word, filename);
    std::cout << "Word '" << word << "' meets " << count << " number of times." << std::endl;

    Matrix matrix1(3, 3);
    writeMatrixToFile(matrix1, "matrix.txt");
    Matrix matrix2 = readMatrixFromFile("matrix.txt");
    matrix2.print();

    std::vector<Book> books;
    int choice;
    do {
        std::cout << "1. Add a new entry\n2. View all posts\n3. Delete entry\n4. Search for an entry\n5. Editing a post\n6. Count the number of words in the file\n7. Exit\nSelect action: ";
        std::cin >> choice;
        switch (choice) {
            case 1: addBook(books); break;
            case 2: viewBooks(); break;
            case 3: deleteBook(books); break;
            case 4: {
                std::string ID;
                std::cout << "Enter book ID to search: ";
                std::cin >> ID;
                searchBook(ID); 
                break;
            }
            case 5: editBook(books); break;
            case 6: std::string filename, word;
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                std::cout << "Enter the word to count: ";
                std::cin >> word;
                int count = countWordOccurrences(word, filename);
                std::cout << "The word '" << word << "' appears " << count << " times in the file '" << filename << "'." << std::endl;;break;
        }
    } while (choice != 7);

    return 0;
}