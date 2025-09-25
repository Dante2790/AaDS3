#include "BinarySearchTree.h"


template <typename T>
bool BinarySearchTree<T>::insert(const T& newKey) {
	try {
		bst::Node* current = new bst::Node(newKey);
		bst::Node* temp;
		if (searchIterative(newKey)) {
			throw TreeInvalidKey("this key already exists");
		}
		switch (isEmpty()) {
		case true:
			this->root = current;
			std::cout << "-------------------------" << '\n';
			std::cout << "node: " << *current << '\n';
			std::cout << "nodes: ";
			bst::output(std::cout, this->root);

			std::cout << "height: " << bst::getHeight(this->root) << '\n';
			std::cout << "number of nodes: " << bst::getNumberOfNodes(this->root) << '\n';
			std::cout << "-------------------------" << '\n';
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
			std::cout << "-------------------------" << '\n';
			std::cout << "node: " << *current << '\n';
			std::cout << "nodes: ";
			bst::output(std::cout, this->root);

			std::cout << "height: " << bst::getHeight(this->root) << '\n';
			std::cout << "number of nodes: " << bst::getNumberOfNodes(this->root) << '\n';
			std::cout << "-------------------------" << '\n';
			return true;
		}
		return false;

	}
	catch (TreeInvalidKey er) {
		std::cerr << "error: " << er.what() << '\n';
		return false;
	}
	
	
	
}

template <typename T>
//typename BinarySearchTree<T>::Node*
bool BinarySearchTree<T>::searchIterative(const T& key) const & {
	bst::Node* current = this->root;

	while (current) {
		if (key == current->key) { return true; }
		else if (!(current->left) && !(current->right)) { break; }
		else if ((key < current->key) && (current->left)) { current = current->left; }
		else if (key > current->key && (current->right)) { current = current->right; }
		else { break; }
		
	}

	return false;

}

template <typename T>
 void BinarySearchTree<T>::output(std::ostream& out, bst::Node* root){
	 if (!root) { throw TreeInvalidKey("tree is empty"); }
	 out << '(' << *root;
	 if (root->left) { output(out, root->left); }
	 if (root->right) { output(out, root->right); }
	 out << ')';
}
 
 template <typename T>
 int BinarySearchTree<T>::getNumberOfNodes(const bst::Node* node) {
	 //////////////////////////
	 if (!(node)) { return 0; }
	 //////////////////////////
	 static int numberOfNodes;
	 if (!(node->parent)) { numberOfNodes = 0; }

	 numberOfNodes++;
	 if (node->left) { bst::getNumberOfNodes(node->left); }
	 if (node->right) { bst::getNumberOfNodes(node->right); }

	 return numberOfNodes;
 }
 
 template <typename T>
 int BinarySearchTree<T>::getHeight(const bst::Node* node) {
	 //////////////////////////
	 if (!(node)) { return 0; }
	 //////////////////////////
	 static int mainHeight;
	 int currentHeight = 0;
	 if (!(node->parent)) { mainHeight = 0; }
	 
	 if (node->left) { bst::getHeight(node->left); }
	 if (node->right) { bst::getHeight(node->right); }

	 while (node->parent) {
		 currentHeight++;
		 node = node->parent;
	 }

	 if (currentHeight > mainHeight) { mainHeight = currentHeight; }
	 return mainHeight;
 }
 
 template <typename T>
 void BinarySearchTree<T>::inorderWalk(Node* node) const {

 }
 template <typename T>
 BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& source) noexcept {

 }
 //template <typename T>
 //BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& other) noexcept {

 //}
 template <typename T>
 BinarySearchTree<T>::~BinarySearchTree() {

 }
 
 template <typename T>
 bool BinarySearchTree<T>::remove(const T& keyToRemove) {
	 try {
		 if (!(searchIterative(keyToRemove))) {
			 throw TreeInvalidKey("this key does'nt exist");
		 }
		 bst::Node* nodeToRemove = bst::getPlace(this->root, keyToRemove);
		 bst::Node* temp;
		 if (nodeToRemove->last) {
			 //temp1 = temp->parent;
			 //if (!(temp1->left) || !(temp1->right)) {
				 //temp1->last = true;
			 //}
			 //delete temp;
			 bst::removeLast(nodeToRemove);
		 }
		 else {
			 if (nodeToRemove->right) {
				 temp = nodeToRemove->right;
				 while (temp->left != nullptr) {
					 temp = temp->left;
				 }
				 if (temp->last) {
					 bst::swapNode(nodeToRemove, temp);
					 bst::removeLast(temp);
				 }
				 else {
					 removeNotLast(nodeToRemove);
				 }
			 }
			 else {
				 removeNotLast(nodeToRemove);
			 }
			 
			 


		 }

		 return true;
	 }
	 catch (TreeInvalidKey er) {
		 std::cerr << "error: " << er.what() << '\n';
		 return false;
	 }
 }
 
 template <typename T>
 void BinarySearchTree<T>::remove(const T&& keyToRemove) {
	 remove(keyToRemove);
	 return;
 }
 
 template <typename T>
 void BinarySearchTree<T>::output(std::ostream& out) const {
	 try { bst::output(std::cout, this->root); std::cout << '\n'; }
	 catch (TreeInvalidKey er) { std::cerr << "error: " << er.what() << '\n'; }
 }
 template <typename T>
 int BinarySearchTree<T>::getNumberOfNodes() const {
	 return bst::getNumberOfNodes(this->root);
 }
 template <typename T>
 int BinarySearchTree<T>::getHeight() const {
	 return bst::getHeight(this->root);
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
 template <typename T>
 bool BinarySearchTree<T>::searchIterative(const T&& key) const&& {
	 return searchIterative(key);
 }
 
template class BinarySearchTree<int>;