/**
* file bst.hpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

class OrganNode{
    public:

	int data;
	OrganNode *left;
	OrganNode *right;
	
	OrganNode(const int& dt,OrganNode *lf=NULL,OrganNode*rg=NULL){
		data = dt;
		left = lf;
		right = rg;
	}
};

class BST{
	private:	
		OrganNode *root;
		
		void SearchAndAdd(OrganNode *&subNode,const int& newItem){
			if(subNode == NULL) subNode = new OrganNode(newItem);
			else if(newItem < subNode->data)
				SearchAndAdd(subNode->left,newItem);
			else if(newItem > subNode->data)
				SearchAndAdd(subNode->right,newItem);
			else return;
		}
		bool SearchAndDelete(OrganNode *&subNode,const int& data){
			if(subNode == NULL) return false;
			if(subNode->data == data) return DeleteNode(subNode);
			else if(data < subNode->data) return SearchAndDelete(subNode->left,data);
			else return SearchAndDelete(subNode->right,data);
		}
		bool DeleteNode(OrganNode *&subNode){
			OrganNode *DelNode = subNode;
			
			if(subNode->right == NULL) subNode = subNode->left;
			else if(subNode->left == NULL) subNode = subNode->right;
			else{
				DelNode = subNode->left;
				OrganNode *parent = subNode;
				while(DelNode->right != NULL){
					parent = DelNode;
					DelNode = DelNode->right;
				}
				subNode->data = DelNode->data;
				if(parent == subNode) subNode->left = DelNode->left;
				else parent->right = DelNode->left;
			}
			delete DelNode;
			return true;
		}
		void inorder(OrganNode *subNode){
			if(subNode != NULL){
				inorder(subNode->left);
				cout<<subNode->data<<" ";
				inorder(subNode->right);
			}
		}
		void preorder(OrganNode *subNode){
			if(subNode != NULL){
				cout<<subNode->data<<" ";
				preorder(subNode->left);
				preorder(subNode->right);
			}
		}
		void postorder(OrganNode *subNode){
			if(subNode != NULL){
				postorder(subNode->left);
				postorder(subNode->right);
				cout<<subNode->data<<" ";
			}
		}
		
		int Height(OrganNode *subNode){
			if(subNode == NULL) return 0;
			return 1+max(Height(subNode->left),Height(subNode->right));
		}
		void PrintLevel(OrganNode *subNode,int level){
			if(subNode == NULL) return;
			if(level == 0) cout<<subNode->data<<" ";
			else{
				PrintLevel(subNode->left,level-1);
				PrintLevel(subNode->right,level-1);
			}
		}
		bool Search(OrganNode *subNode,const int& item){
			if(subNode == NULL) return false;
			if(subNode->data == item) return true;
			if(item < subNode->data) return Search(subNode->left,item);
			else return Search(subNode->right,item);
		}
		int firstOf(OrganNode *subNode){
			return subNode->data;
		}
		bool isBalanced(OrganNode* subNode)
		{
			// for height of left subtree
			int lh;
		
			// for height of right subtree
			int rh;
		
			// If tree is empty then return true
			if (subNode == NULL)
				return 1;
		
			// Get the height of left and right sub trees
			lh = Height(subNode->left);
			rh = Height(subNode->right);
		
			if (abs(lh - rh) <= 1 && isBalanced(subNode->left)
				&& isBalanced(subNode->right))
				return 1;
		
			// If we reach here then tree is not height-balanced
			return 0;
		}
	public:
		BST(){
			root = NULL;
		}
		bool isEmpty()const{
			return root == NULL;
		}
		bool Check(){
			return isBalanced(root);
		}
		int firstOfRoot(){
			return firstOf(root);
		}
		void Add(const int& newItem){
			SearchAndAdd(root,newItem);
		}
		void Delete(const int &data){
			if(SearchAndDelete(root,data) == false) throw "Item not found.";
		}
		void inorder(){
			inorder(root);
		}
		void preorder(){
			preorder(root);
		}
		void postorder(){
			postorder(root);
		}
		void levelorder(){
			int h = Height();
			for(int level=0;level<=h;level++){
				PrintLevel(root,level);
			}
		}
		int Height(){
			return Height(root);
		}
		bool Search(const int& item){
			return Search(root,item);
		}
		void Clear(){
			while(!isEmpty()) DeleteNode(root);
		}
		~BST(){
			Clear();
		}
};





#endif