#include "BinarySearchTree.h"


template <typename T>
bool BinarySearchTree<T>::insert(const T& newKey) {
	try {
		bst::Node* current = new bst::Node(newKey);
		bst::Node* temp;
		//if (searchIterative(newKey)) {
			//throw TreeInvalidKey("this key already exists");
		//}

		switch (isEmpty()) {
		case true:
			this->root = current;
			return true;
		case false:
			getPlace(current, temp, this->root);
			if (current->key > temp->key) {
				temp->right = current;
			}
			else if (current->key < temp->key) {
				temp->left = current;
			}
			
			current->parent = temp;
			temp->last = false;
			return true;
		}


	}
	catch (TreeInvalidKey er) {
		std::cerr << "error: " << er.what() << '\n';
		return false;
	}
	
}
/*
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::searchIterative(const T& key) const {

}

template <typename T>
 void BinarySearchTree<T>::output(std::ostream& out, Node* root) const {

}
 template <typename T>
 int BinarySearchTree<T>::getNumberOfNodes(const Node* node) const {

 }
 template <typename T>
 int BinarySearchTree<T>::getHeight(const Node* node) const {

 }
 template <typename T>
 void BinarySearchTree<T>::inorderWalk(Node* node) const {

 }
 template <typename T>
 BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr) noexcept {

 }
 template <typename T>
 BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& other) noexcept {

 }
 template <typename T>
 BinarySearchTree<T>::~BinarySearchTree() {

 }
 template <typename T>
 bool BinarySearchTree<T>::remove(const T& key) {

 }
 template <typename T>
 void BinarySearchTree<T>::output(std::ostream& out) const {

 }
 template <typename T>
 int BinarySearchTree<T>::getNumberOfNodes() const {

 }
 template <typename T>
 int BinarySearchTree<T>::getHeight() const {

 }
 template <typename T>
 void BinarySearchTree<T>::inorderWalkIterative() const {

 }
 template <typename T>
 void BinarySearchTree<T>::inorderWalk() const {

 }
 template <typename T>
 void BinarySearchTree<T>::walkByLevels() const {

 }
 */
template class BinarySearchTree<int>;