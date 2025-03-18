#include <iostream>
#include <stdexcept>

class Matrix {
public:
    int rows, cols;
    int** data;

    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for(int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for(int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Input matrix elements
    void input() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                std::cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Sum of two matrices
    Matrix sum(const Matrix& other) const {
        if(rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices are not compatible for addition.");
        }
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Product of two matrices
    Matrix product(const Matrix& other) const {
        if(cols != other.rows) {
            throw std::invalid_argument("Matrices are not compatible for multiplication.");
        }
        Matrix result(rows, other.cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for(int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Transpose of a matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int choice;
    while(true) {
        std::cout << "1. Sum of two matrices\n";
        std::cout << "2. Product of two matrices\n";
        std::cout << "3. Transpose of a matrix\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                int r1, c1, r2, c2;
                std::cout << "Enter rows and columns for first matrix: ";
                std::cin >> r1 >> c1;
                std::cout << "Enter rows and columns for second matrix: ";
                std::cin >> r2 >> c2;

                Matrix mat1(r1, c1);
                Matrix mat2(r2, c2);

                std::cout << "Enter elements for first matrix:\n";
                mat1.input();
                std::cout << "Enter elements for second matrix:\n";
                mat2.input();

                try {
                    Matrix result = mat1.sum(mat2);
                    std::cout << "First matrix:\n";
                    mat1.display();
                    std::cout << "Second matrix:\n";
                    mat2.display();
                    std::cout << "Sum of matrices:\n";
                    result.display();
                } catch(const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                int r1, c1, r2, c2;
                std::cout << "Enter rows and columns for first matrix: ";
                std::cin >> r1 >> c1;
                std::cout << "Enter rows and columns for second matrix: ";
                std::cin >> r2 >> c2;

                Matrix mat1(r1, c1);
                Matrix mat2(r2, c2);

                std::cout << "Enter elements for first matrix:\n";
                mat1.input();
                std::cout << "Enter elements for second matrix:\n";
                mat2.input();

                try {
                    Matrix result = mat1.product(mat2);
                    std::cout << "First matrix:\n";
                    mat1.display();
                    std::cout << "Second matrix:\n";
                    mat2.display();
                    std::cout << "Product of matrices:\n";
                    result.display();
                } catch(const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                int r, c;
                std::cout << "Enter rows and columns for matrix: ";
                std::cin >> r >> c;

                Matrix mat(r, c);

                std::cout << "Enter elements for matrix:\n";
                mat.input();

                Matrix result = mat.transpose();
                std::cout << "Original matrix:\n";
                mat.display();
                std::cout << "Transpose of matrix:\n";
                result.display();
                break;
            }
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please choose again.\n";
        }
    }
    return 0;
}
