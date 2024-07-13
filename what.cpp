using namespace std;

template <typename T>
class BinaryTree {

    class Node {
        public:
            T value;
            Node* left;
            Node* right;

            Node(T value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node root;

    public:
        BinaryTree(T rootValue) : root(rootValue) {}
};

int main() {
    BinaryTree<int> tree(5);
    return 0;
}