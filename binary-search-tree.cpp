using namespace std;

template <typename T> 
class BinaryTree {
  
    class Node {
        public:
            T value;
            Node* left;
            Node* right;

            Node(T value) : T(value), left(nullptr), right(nullptr) {}
    };

    Node root;

    // void add(T addition, Node comparison) {
    //   if (addition <= comparison.value) {
    //     if (!comparison.left) comparison.left = addition;
    //     else add(addition, comparison.left);
    //   } 
    //   else {
    //     if (!comparison.right) comparison.right = addition;
    //     else add(addition, comparison.right);
    //   }
    // }

    // int[]

    // int getRightmostBeneath(int row, int column, vector<string> output) {

    // }

    // void print(Node<T> node, int row, int column, vector<string> output) {
    // }
    
    public:
        BinaryTree() : root(nullptr) {}

        BinaryTree(T rootValue) : root(new Node(rootValue)) {}

        // void add(T addition) {
        //   if (!root) root = addition;
        //   else add(addition, root);
        // }

        // void print() {
        //   Node[] toPrint = { root };
        //   print(toPrint);
        // }
};

int main() {
    BinaryTree<int> tree(5);
    return 0;
}