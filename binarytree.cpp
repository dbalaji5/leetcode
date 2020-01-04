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

		void inorder(Node* s){
			if(s==NULL){
				return;
			}
			inorder(s->left);
			cout<<s->data<<endl;
			inorder(s->right);
		}
		void preorder(Node* s){
			if(s==NULL){
				return;
			}
			cout<<s->data<<endl;
			preorder(s->left);
			preorder(s->right);
		}
		void postorder(Node* s){
			if(s==NULL){
				return;
			}
			postorder(s->right);
			postorder(s->left);
			cout<<s->data<<endl;
		}
		vector<int> inorderTraversal(Node* root){
			stack<Node *> s;
			Node* temp=root;
			vector<int> res;
			while(1){

				if(temp!=NULL){
					s.push(temp);
					temp=temp->left;
				}
				else if(temp==NULL && !s.empty()){
					res.push_back(s.top()->data);
					temp=s.top()->right;
					s.pop();
				}
				else{
					break;
				}
			} 
			return res;

		}

};
int main()
{
	Node* n=NULL;
	Creator ns;
	n=ns.insertNode(n,5);
	n=ns.insertNode(n,6);
	n=ns.insertNode(n,4);
	n=ns.insertNode(n,8);
	n=ns.insertNode(n,7);
	ns.inorder(n);
	vector<int> res2=ns.inorderTraversal(n);
	for(int j=0;j<res2.size();j++){
		cout<<res2[j]<<endl;
	}
	return 0;
}