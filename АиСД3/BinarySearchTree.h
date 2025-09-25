#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include<stdexcept>
#include<string>

//	определения, являются ли два дерева похожими. Похожими будем называть деревья поиска, содержащие одинаковые наборы ключей. 
// индивидуальный побочный квест


template <typename T>
class BinarySearchTree
{


private:
    using bst = BinarySearchTree<T>;
    struct Node {
        bool last;
        T key;            // значение ключа, содержащееся в узле
        Node* left;     // указатель на левое поддерево
        Node* right;    // указатель на правое поддерево
        Node* parent;        // указатель на  родителя !!! не используется
        // Конструктор узла
        Node(T newKey) : key(newKey), left(nullptr), right(nullptr), parent(nullptr), last(true) {};
        friend std::ostream& operator<<(std::ostream& os, const Node& node) {
            os << node.key;
            return os;
        }
    };

    /////////////

    Node* root; // Указатель на корневой узел

    /////////////

    

        // 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
    bool searchIterative(const T& key) const &;
    
    // 4.2 Рекурсивная функция для вывода структуры дерева в выходной поток
    static void output(std::ostream& out, Node* root);
    
    // 5.2 Рекурсивная функция определения количества узлов дерева
    static int getNumberOfNodes(const Node* node);
    
    // 6.2 Рекурсивная функция определения высоты дерева
    static int getHeight(const Node* node); // а зачем не static, если аргумент - root?
    
    // 8.2 Рекурсивная функция для инфиксного обхода узлов дерева.
    void inorderWalk(Node* node) const;
    

    bool isEmpty() const { return this->root == nullptr; }

    static void removeLast(Node* lastNode) {
        Node* temp = lastNode->parent;
        if (!(temp->left) || !(temp->right)) {
            temp->last = true;
        }
        delete lastNode;
    }

    void removeNotLast(Node* node) {
        Node* temp;
        Node* temp1;
        if (!node->right) {
            temp = node->left;
            if (node->parent) {
                temp->parent = node->parent;
                temp1 = temp->parent;
                if (temp1->left = node) {
                    temp1->left = temp;
                }
                else {
                    temp1->right = temp;
                }
            }
            else {
                temp = node->left;
                this->root = temp;
                temp->parent = nullptr;
            }
        }
        else {
            temp = node->right;
            if (node->parent) {
                temp->parent = node->parent;
                temp1 = temp->parent;
                if (temp1->left = node) {
                    temp1->left = temp;
                }
                else {
                    temp1->right = temp;
                }
            }
            else {
                temp = node->right;
                if (node->left) {
                    temp->left = node->left;
                    temp1 = temp->left;
                    temp1->parent = temp;
                }
                this->root = temp;
                temp->parent = nullptr;
            }

        }
        delete node;
    }

    static void swapNode(Node* &first, Node* &second){
        T temp = first->key;
        first->key = second->key;
        second->key = temp;
    }

    static Node* getPlace(Node* source, T keyToRemove) {
        while (source) {
            if (source->key == keyToRemove) {
                break;
            }
            else if (source->key > keyToRemove) {
                source = source->left;
            }
            else {
                source = source->right;
            }
        }
        return source;
    }

    void getPlace(Node* &current, Node* &resultNode, Node* &source) {
        static Node* temp;
        temp = source;
        
        if (source->last) { 
            resultNode = source;
            temp = source;
            return; 
        }
        if (current->key > source->key && temp->right) {
            temp = temp->right;
            getPlace(current, resultNode, temp);
        }
        else if (current->key < source->key && temp->left) {
            temp = temp->left;
            getPlace(current, resultNode, temp);
        }

        

        resultNode = temp;
        return;
    }
    ////////////////////////////////////////////////////

    

public:
    //class EasyTreeCreator {
       // using etc = EasyTreeCreator;
        //static BinarySearchTree createIntTree() { return BinarySearchTree<int>; }
        //static BinarySearchTree createCharTree() { return BinarySearchTree<char>; }
    //};
    BinarySearchTree() : root(nullptr) {};// "по умолчанию" создает пустое дерево
    BinarySearchTree(const BinarySearchTree<T>& source) = delete;
    BinarySearchTree(BinarySearchTree<T>&& source) noexcept;
    BinarySearchTree <T>& operator= (const BinarySearchTree <T>& source) = delete;
    //BinarySearchTree <T>& operator= (BinarySearchTree <T>&& other) noexcept;
    ~BinarySearchTree();

    // 1.1 Функция поиска по ключу в бинарном дереве поиска
    bool searchIterative(const T&& key) const &&;

    // 2 Вставка нового элемента в дерево: true, если элемент добавлен; 
    // false, если элемент уже был
    bool insert(const T& newKey);

    

    // 3.1 Удаление элемента c заданным ключом, не нарушающее порядок элементов
    // true, если элемент удален; false, если элемента не было
    void remove(const T&& keyToRemove);
    bool remove(const T& keyToRemove);

    
    // 4.1 Вывод структуры (строкового изображения дерева) в выходной поток out,
// использовать скобки, чтобы показать структуру дерева
    void output(std::ostream& out) const;

    // 5.1 Определение количества узлов дерева
    int getNumberOfNodes() const;

    // 6.1 Определение высоты дерева
    int getHeight() const;

    // 7 Инфиксный обход дерева (итеративный) 
    void inorderWalkIterative() const;

    // 8.1 Инфиксный обход дерева (рекурсивный) 
    void inorderWalk() const;

    // 9 Обход двоичного дерева по уровням (в ширину).  
    void walkByLevels() const;
    

}; // конец шаблона класса BinarySearchTree

class TreeUndeerflow : public std::underflow_error {
private:
    std::string message;
public:
    explicit TreeUndeerflow(const std::string& msg) noexcept : std::underflow_error(msg), message(msg) {};
    const char* what() const noexcept override { return message.c_str(); }
};

class TreeOverflow : public std::overflow_error {
private:
    std::string message;
public:
    explicit TreeOverflow(const std::string& msg) noexcept : std::overflow_error(msg), message(msg) {};
    const char* what() const noexcept override { return message.c_str(); }
};

class TreeInvalidKey : std::invalid_argument {
    std::string message;
public:
    explicit TreeInvalidKey(const std::string& msg) noexcept : std::invalid_argument(msg), message(msg) {};
    const char* what() const noexcept override { return message.c_str(); }
};



#endif;