#include <iostream>
using namespace std;

class Tnode{
	public:
		int data;
		Tnode *lchild;
		Tnode *rchild;
};

class BST{
	public:
		Tnode *root, *ploc, *loc;
		
		bool isEmpty(){
			return root == NULL;
		}
		
		void Insert(int value){
			Tnode *nn = new Tnode();
			nn->data = value;
			
			if(isEmpty()){
				root = nn;
				
			} else {
				ploc = NULL;
				loc = root;
				
				while(loc != NULL){
					//Checking if value is less than or greater than the value in the node
					if(value <= loc->data){
						ploc = loc;
						loc = loc->lchild;
					} else {
						ploc = loc;
						loc = loc->rchild;
					}
				}
				if(value <= ploc->data){
					ploc->lchild = nn;
				} else {
					ploc->rchild = nn;
				}
				//printing root
				preOrder(root);cout<<endl;
			}
			
		}
		
		void preOrder(Tnode *temp){
			if(temp!=NULL){
				cout<<temp->data<<" ";
				preOrder(temp->lchild);
				preOrder(temp->rchild);
				
			}
		}
		
		void Delete(int value){
			if(!isEmpty()){
				loc = root; ploc = NULL;	
				while(loc != NULL && loc->data != value){
					
					if(value <= loc->data){
						ploc = loc;
						loc = loc->lchild;
					} else {
						ploc = loc;
						loc = loc->rchild;
					}
				}
				if(loc == NULL){
					cout<<"Not Found!"<<endl;
				}
				if(loc->data == value){
					//Leaf Case
					if(loc->lchild == NULL && loc->rchild == NULL){
						if(ploc->lchild == loc){
							ploc->lchild = NULL;
							cout<<"\nValue Deleted: "<<loc->data<<endl;
							delete loc;
						} else {
							ploc->rchild = NULL;
							cout<<"\nValue Deleted: "<<loc->data<<endl;
							delete loc;
						}
						preOrder(root);
					}
					
					//only left child with further left child
					else if(loc->lchild != NULL && loc->rchild == NULL){
						cout<<"\nleft child only with left further"<<endl;
						Tnode *temp;
						temp = loc->lchild;
						delete loc;
						ploc->rchild = temp;
						preOrder(root);
					}
					
					//Only left child with further right child
					else if(loc->lchild == NULL && loc->rchild != NULL){
						cout<<"\nleft child only with right further"<<endl;
						Tnode *temp;
						temp = loc->rchild;
						delete loc;
						ploc->lchild = temp;
						preOrder(root);
					}
					
					//only right child with further left child
					else if(loc->rchild != NULL && loc->lchild == NULL){
						cout<<"\nRight child only with left further"<<endl;
						Tnode *temp;
						temp = loc->rchild;
						delete loc;
						ploc->lchild = temp;
						preOrder(root);
					}
					
					//only right child with further right child
					else if(loc->rchild == NULL && loc->lchild != NULL){
						cout<<"\nRight child only with right further"<<endl;
						Tnode *temp;
						temp = loc->lchild;
						delete loc;
						ploc->rchild = temp;
						preOrder(root);
					}
				}
			}
		}
		
		void PrintLeaf(Tnode *temp){
			if(temp->lchild == NULL && temp->rchild == NULL){
				cout<<temp->data<<" ";
			} else {
				if (temp->lchild != NULL){
					PrintLeaf(temp->lchild);
				} if (temp->rchild != NULL){
					PrintLeaf(temp->rchild);
				} if (temp->lchild == NULL){
					return;
				} if (temp->rchild == NULL){
					return;
				}
			}
		}
		
		void DestroyTree(Tnode *temp){
			if(temp != NULL){
				DestroyTree(temp->lchild);
				DestroyTree(temp->rchild);
				delete temp;
			}
		}
		
		Tnode* DestroyLeaf(Tnode *temp){
			bool isLeaf = false;
			if (temp != NULL){
				if (temp->lchild == NULL && temp->rchild == NULL){
					isLeaf = true;
				}
				temp->lchild = DestroyLeaf(temp->lchild);
				temp->rchild = DestroyLeaf(temp->rchild);
				if(isLeaf){
					delete temp;
					return NULL;
				} else {
					return temp;
				}
			} else {
				return NULL;
			}
		}
		
};


int main(){
	cout<<"Chalta hai bhai!"<<endl;
	BST *tree = new BST();
	
	tree->Insert(23);
	tree->Insert(2);
	tree->Insert(1);
	tree->Insert(13);
	tree->Insert(5);
	tree->Insert(10);
	tree->Insert(55);
	tree->Insert(66);
	tree->Insert(63);
	
	tree->DestroyLeaf(tree->root);
	tree->PrintLeaf(tree->root);
	
	/*cout<<"\nValue Deleted: "<<endl;
	tree->Delete(13);
	
	cout<<"\nLeaf Nodes: "<<endl;
	tree->PrintLeaf(tree->root);*/
}
