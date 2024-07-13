#include<bits/stdc++.h>
using namespace std;

class BinarySearchTree {
private:
	int data { };
	BinarySearchTree* left { };
	BinarySearchTree* right { };

public:
    static int counter ;
	BinarySearchTree(int data) :
			data(data) {
            ++counter;
	}

	void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	////////////////////////////////////////////

	void insert(int target) {
		if (target < data) {
			if (!left){
				left = new BinarySearchTree(target);
 			}
			else
				left->insert(target);
		} else if(target > data){
			if (!right){
				right = new BinarySearchTree(target);
 			}
			else
				right->insert(target);
		}
	}

	bool search(int target) {
		if (target == data)
			return true;

		if (target < data)
			return left && left->search(target);

		return right && right->search(target);
	}
	//search using iterative method
	bool search_iterative(int target){
        BinarySearchTree *node = this;
        while(node){
            if(node->data == target)return true;
            else if(node->data > target ){
                node=node->left;
            }else
                node = node->right;
        }
        return false;
	}
	static void num_objects(){
        cout<<"number of ojects = "<<counter<<endl;
	}////////////finding the minimum
	int min_val(){
        BinarySearchTree *cur = this;
        while(cur && cur->left){
            cur = cur->left;
        }
        return cur->data;
	}
	//////////////finding the parents to get the successor
	bool find_chain(vector<BinarySearchTree *> &ancestor,int target){
        ancestor.push_back(this);
        if(target == data)
            return true;
        if(target<data)
            return left&&left->find_chain(ancestor,target);
        return right && right->find_chain(ancestor, target);
	}
	////getting the next parent
	BinarySearchTree *get_next(vector<BinarySearchTree *> &ancestor){
        if(ancestor.size()==0)return nullptr;
        BinarySearchTree *node=ancestor.back();
        ancestor.pop_back();
        return node;
	}
	/////the successor function
	pair<bool,int> successor(int target){
        vector<BinarySearchTree *>ancestor;
        if(!find_chain(ancestor,target)){
            return make_pair(false,-1);
        }
        BinarySearchTree *child = get_next(ancestor);
        if(child->right){
            return make_pair(true, child->right->min_val());
        }
        BinarySearchTree *parent = get_next(ancestor);
        while(parent && parent->right == child){
            child = parent;
            parent = get_next(ancestor);
        }
        if (parent)
			return make_pair(true, parent->data);
		return make_pair(false, -1);
	}

~BinarySearchTree(){
    --counter;
}
};
int BinarySearchTree::counter;
int main() {
	BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);
    cout<< 45<<" is in tree ? "<<tree.search_iterative(45)<<endl;
    cout<< 60<<" is in tree ? "<<tree.search_iterative(60)<<endl;
    cout<< 12<<" is in tree ? "<<tree.search_iterative(12)<<endl;
	tree.print_inorder();
    tree.num_objects();
    cout<<"getting the successors of the bst"<<endl;
    vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		pair<bool, int> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}

	return 0;
}
