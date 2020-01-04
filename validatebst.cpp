#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
};
class Creator{

	public:

		Node* insertNode(Node* s,int data){
			if(s==NULL){
				Node* temp=new Node();
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				return temp;
			}
			else{
				if(s->data<data){
					s->right=insertNode(s->right,data);
				}
				else{
					s->left=insertNode(s->left,data);
				}
			}
			return s;
		}

		bool isValidateBst(Node* root){
			if(root==NULL){
				return 1;
			}
			if(root->left==NULL && root->right==NULL){
				return 1;
			}
			return (isValidateBst(root->left) && isValidateBst(root->right) && ((root->left==NULL)?1:root->left->data < root->data)
			        && ((root->right==NULL)?1:root->right->data > root->data));
		}
		bool isValidBst(Node* root){
			Node* prev=NULL;
			return isValidBstUtil(root,prev);
		}
		bool isValidBstUtil(Node* curr,Node *&prev){
			if(curr==NULL){
				cout<<"cin"<<endl;
                return 1;
            }
		    if(!isValidBstUtil(curr->left,prev)){
                return 0;
            }
			if(prev!=NULL && curr->data<=prev->data){
				cout<<"in"<<endl;
				return 0;
			}
			prev=curr;
			return isValidBstUtil(curr->right,prev);
		}
		

};
int main()
{
	Node* n=NULL;
	Node* temp=new Node();
	Node* temp2=new Node();
	temp2->data=4;
	temp2->left=NULL;
	temp2->right=NULL;
	temp->data=3;
	temp->left=temp2;
	temp->right=NULL;
	Creator ns;
	n=ns.insertNode(n,5);
	n=ns.insertNode(n,6);
	n=ns.insertNode(n,4);
	n=ns.insertNode(n,8);
	n=ns.insertNode(n,7);
	cout<<ns.isValidBst(temp)<<endl;
	return 0;
}