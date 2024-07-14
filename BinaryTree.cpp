#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Sorted binary tree for any comparable datatype
 */
template <typename T>
class BinaryTree {

    /**
     * @brief Inner Node class for each branch/leaf on the tree.
     * 
     * Each node contains its value and two pointers to the next nodes (defaulted to null pointers)
     */
    class Node {
        public:
            T value;
            Node* left;
            Node* right;

            Node(T value) : value(value) {}
    };

    Node* root;

    /**
     * @brief Getting the lengths of strings for printing
     * 
     * @param output - the current lines to be printed
     * @return the lengths of the strings
     */
    vector<int> stringLengths(const vector<string>& output) {
        vector<int> lengths(output.size());
        transform(output.begin(), output.end(), lengths.begin(), [](const string& line) { return line.size(); });
        return lengths;
    }

    /**
     * @brief Getting the size of the longest line below the current node for printing
     * 
     * @param row - the row number of the current node
     * @param column - the column number of the current node
     * @param output - the current lines to be printed
     * @return the size of the longest line
     */
    int rightmostBeneath(int row, int column, const vector<string>& output) {
        vector<string> subarray(output.begin() + row, output.end());
        vector<int> lengths = stringLengths(subarray);
        return *max_element(lengths.begin(), lengths.end());
    }

    void addBranch(int row, int targetColumn, int childColumn, vector<string> output) {
        string branchLine = output[row + 1];
        branchLine.append(targetColumn - branchLine.size(), ' ');
        if (targetColumn == childColumn) {
            branchLine += "|";
            return;
        }
        branchLine += "└";
        const int dashes = childColumn - targetColumn - 2;
        if (dashes > 0) branchLine.append(dashes, '─');
        branchLine += "┐";
    }

    int print(Node node, int row, int column, vector<string> output) {
        // printing the node
        // adding more lines if needed
        for (int i = output.size(); i < row; i++) output.push_back("");

        // in case leaves to its left are getting in the way of this current branch
        int rightmost = rightmostBeneath(row, column, output) + 1;
        int targetColumn = rightmost > column ? rightmost : column;
        string line = output[row];
        line.append(targetColumn - line.size(), ' ');
        line += node.value;

        // printing children
        const int childrenRow = row + 2;
        int childrenColumn = targetColumn;
        if (node.left) {
            addBranch(row, targetColumn, print(*node.left, childrenRow, childrenColumn, output), output);
            childrenColumn += 2;
        }
        if (node.right) addBranch(row, targetColumn, print(*node.right, childrenRow, childrenColumn, output), output);

        // for parent to print branch leading up to this
        return targetColumn;
    }   

    public:
        BinaryTree(T rootValue) : root(new Node(rootValue)) {}

        void print() {
            print(*root, 0, 0, { "" });
        }
};

int main() {
    BinaryTree<int> tree(5);
    tree.print();
    return 0;
}