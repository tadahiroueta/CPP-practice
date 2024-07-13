#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class BinaryTree {

    class Node {
        public:
            T value;
            Node* left;
            Node* right;

            Node(T value) : value(value) {}
    };

    Node* root;

    int[] stringLengths(vector<string> output) {
        int lengths[output.size()];
        transform(output.begin(), output.end(), lengths.being(), size);
        return lengths;
    }

    int rightmostBeneath(int row, int column, vector<string> output) {
        int stringLengths[] = 
    }

    void print(Node node, int row, int column, vector<string> output) {

    }

    public:
        BinaryTree(T rootValue) : root(new Node(rootValue)) {}

        void print() {
            Node[] toPrint = { root };
            // todo
        }
};

int main() {
    BinaryTree<int> tree(5);
    return 0;
}