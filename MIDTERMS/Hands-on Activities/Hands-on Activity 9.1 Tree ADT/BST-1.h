#ifndef BST_H
#define BST_H

// ====================================
//
//              General Tree
//
// ====================================

template <typename T>
class BinarySearchTree {
    private:
        //create a key
        T key; 

        // pointers left and right
        BinarySearchTree <T>* left;
        BinarySearchTree <T>* right;

    public:
        // constructor
        BinarySearchTree(T value);

        // insert left and insert right
        void insert(T newNode);
        
        // traversing
        void preOrder();
        void inOrder();
        void postOrder();


        // searching



};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;


}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    // left or right


    // go left if val > key // go right if val < key
    if(value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        }
        else {
            left->insert(value);
        }
    }
    else if(value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        }
    
        else {
        right->insert(value);
        }

    }

}
template <typename T>
void BinarySearchTree<T>::preOrder() {

    std::cout << key << " ";
    if(left != nullptr) {
        left->preOrder();

    }

    if(right != nullptr) {
        right->preOrder();
    }

} 

template <typename T>
void BinarySearchTree<T>::inOrder() {

    
    if(left != nullptr) {
        left->inOrder();

    }
    std::cout << key << " ";
    
    if(right != nullptr) {
        right->inOrder();
    }

} 

template <typename T>
void BinarySearchTree<T>::postOrder() {

    
    if(left != nullptr) {
        left->postOrder();

    }
    
    if(right != nullptr) {
        right->postOrder();
    }
    std::cout << key << " ";
} 

// ====================================
//
//              General Tree
//
// ====================================
template <typename T>
class GeneralTree {
    private:
        T key;
        GeneralTree<T>* firstChild;
        GeneralTree<T>* nextSibling;

        GeneralTree<T>* find(T value);

        // attach 'child' as the last child in this node's child list
        void addChild(GeneralTree<T>* child);

        void preOrderFind(T target, bool& found);
        void postOrderFind(T target, bool& found);
        void inOrderFind(T target, bool& found);

    public:
        // constructor
        GeneralTree(T value);

        // insert newValue as a child of the node currently holding parentValue
        void insert(T parentValue, T newValue);

        // traversing
        void preOrder();
        void inOrder();
        void postOrder();

        void findData(std::string choice, T key);

        
};

template <typename T>
GeneralTree<T>::GeneralTree(T value) {
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::find(T value) {
    if (key == value) return this;

    GeneralTree<T>* child = firstChild;
    while (child != nullptr) {
        GeneralTree<T>* found = child->find(value);
        if (found != nullptr) return found;
        child = child->nextSibling;
    }
    return nullptr;
}

template <typename T>
void GeneralTree<T>::addChild(GeneralTree<T>* child) {
     // if parent has no children newNode becomes first child
    if (firstChild == nullptr) {
        firstChild = child;

    // 
    } else {
        GeneralTree<T>* sibling = firstChild;
        while (sibling->nextSibling != nullptr) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

template <typename T>
void GeneralTree<T>::insert(T parentValue, T newValue) {
    GeneralTree<T>* parent = find(parentValue);
    if (parent == nullptr) {
        std::cout << "Parent " << parentValue << " not found!\n";
        return;
    }
    parent->addChild(new GeneralTree<T>(newValue));
}

template <typename T>
void GeneralTree<T>::preOrder() {
    std::cout << key << " ";
    GeneralTree<T>* child = firstChild;
    while (child != nullptr) {
        child->preOrder();
        child = child->nextSibling;
    }
}

template <typename T>
void GeneralTree<T>::postOrder() {
    GeneralTree<T>* child = firstChild;
    while (child != nullptr) {
        child->postOrder();
        child = child->nextSibling;
    }
    std::cout << key << " ";
}

template <typename T>
void GeneralTree<T>::inOrder() {
    GeneralTree<T>* child = firstChild;
    if (child != nullptr) {
        child->inOrder();
        std::cout << key << " ";
        child = child->nextSibling;
        while (child != nullptr) {
            child->inOrder();
            child = child->nextSibling;
        }
    } else {
        std::cout << key << " ";
    }
}


template <typename T>
void GeneralTree<T>::preOrderFind(T target, bool& found) {
    if (found) return;

    // 1. Visit current node
    if (key == target) {
        std::cout << key << " was found!" << std::endl;
        found = true;
        return;
    }

    // 2. Recursively search children
    GeneralTree<T>* child = firstChild;
    while (child != nullptr && !found) {
        child->preOrderFind(target, found);
        child = child->nextSibling;
    }
}

template <typename T>
void GeneralTree<T>::postOrderFind(T target, bool& found) {
    if (found) return;

    // 1. Recursively search children first
    GeneralTree<T>* child = firstChild;
    while (child != nullptr && !found) {
        child->postOrderFind(target, found);
        child = child->nextSibling;
    }

    // 2. Check current node
    if (found) return;
    if (key == target) {
        std::cout << key << " was found!" << std::endl;
        found = true;
    }
}

template <typename T>
void GeneralTree<T>::inOrderFind(T target, bool& found) {
    if (found) return;

    GeneralTree<T>* child = firstChild;
    if (child != nullptr) {
        // 1. Visit 1st child
        child->inOrderFind(target, found);
        if (found) return;

        // 2. Visit current node
        if (key == target) {
            std::cout << key << " was found!" << std::endl;
            found = true;
            return;
        }

        // 3. Visit remaining siblings
        child = child->nextSibling;
        while (child != nullptr && !found) {
            child->inOrderFind(target, found);
            child = child->nextSibling;
        }
    } else {
        // Leaf node check
        if (key == target) {
            std::cout << key << " was found!" << std::endl;
            found = true;
        }
    }
}

template <typename T>
void GeneralTree<T>::findData(std::string choice, T key) {
    bool found = false;

    if (choice == "PRE")       preOrderFind(key, found);
    else if (choice == "POST") postOrderFind(key, found);
    else if (choice == "IN")   inOrderFind(key, found);
    else {
        std::cout << "Invalid choice.\n";
        return;
    }

    // Displays message ONLY if entire tree traversal completes without finding the key
    if (!found) {
        std::cout << key << " not found!" << std::endl;
    }
}
#endif