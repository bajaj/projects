// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>

#include<fstream>

#include<deque>

#include <fstream>

#include<string>

#include<vector>


using namespace std;



struct node
{
	int data;
	node *left;
	node *right;
	node *next;              // adding next for Populate Inorder Successor for all nodes // just one sum
	int count;           // for geometric application of bst,rank of an element
	int keyy;

	node(int d):data(d),count(1)
	{
		left=NULL;
		right=NULL;
		next=NULL;
	}

};

void recursive_inorder(node *root);
node *insertr(node*,int);

class bst
{

	node *root;

void freememory(node *root);

public:

	bst()
	{
		root=NULL;
	}

	~bst()
	{
		freememory(root);
	//	delete root;
	}

void insert(int data)
{
	root=insertr(root,data);
}




void inorder()
{
	recursive_inorder(root);
}

void levelorder();

node* getroot()
{
	return root;
}

void print_bfs_using_dfs();

void delete_key(int key)
{
	if(root==NULL)
		return;

	node *p=NULL;
	node *visit=root;

	while(visit!=NULL && visit->data!=key)
	{
		p=visit;
		if(visit->data<key)
			visit=visit->right;
		else
			visit=visit->left;
	}

	if(visit==NULL)
	{
		cout<<"no such key to delete";return;
	}

	del_algo(p,visit);
	
}

void del_algo(node *p,node *visit);
void transplant(node*,node*,node*);





};


node *list_head;

void tree_to_list(node *nod)
{
	if(nod==NULL)
		return;

	static node *prev=NULL;

	tree_to_list(nod->left);


	if(prev!=NULL)
	{
		prev->right=nod;
		nod->left=prev;

	}
	else
		list_head=nod;


	prev=nod;

	tree_to_list(nod->right);


}




void tree_minimum(node *x,node **min,node **p_min)
{
	while(x->left!=NULL)
	{
		*(p_min)=x;
		x=x->left;
	}

	(*min)=x;
}


void bst::del_algo(node *p,node *y)
{
	if(y->left==NULL)
	{
		transplant(y,y->right,p);
	}
	else if(y->right==NULL)
	{
		transplant(y,y->left,p);
	}

	else
	{
		node *min,*p_min=NULL;
		tree_minimum(y->right,&min,&p_min);

		if(y->right!=min)   // then p_min i.e parent of minimum is also not null
		{
			transplant(min,min->right,p_min);
			min->right=y->right;
		}
		transplant(y,min,p);    // p is pointer of node to be deleted
		min->left=y->left;
		delete y;
	}

}




void bst::transplant(node *u,node *v,node *p)
{
	if(p==NULL)
		root=v;
	else if(p->left==u)
	{
		p->left=v;
	}
	else
		p->right=v;

}

int maxheight(node *root)
{
	if(root==NULL)
		return -1;

	return (max(maxheight(root->left),maxheight(root->right))+1);

}

void bst::levelorder()
{
	if(!root)
		return;

	deque<node*> current,next;

	current.push_front(root);

	while(!current.empty())
	{
		node *nod=current.front();
		
		if(nod)
		{
		cout<<"  "<<nod->data;

		next.push_back(nod->left);
		next.push_back(nod->right);
		}

		current.pop_front();

		if(current.empty())
		{
			cout<<endl;
			swap(current,next);
		}

	}


}


void recursive_inorder(node *root)
{
	if(root)
	{
		recursive_inorder(root->left);

		cout<<"   "<<root->data;
		
		recursive_inorder(root->right);

	}


}


node* insertr(node *root,int data)
{

	if(root==NULL)
		return new node(data);

	else
	{
		(root->count)++;

		if(root->data<data)
			
			{
				root->right=insertr(root->right,data);
				
		    }
		else
			root->left=insertr(root->left,data);

	}

	return root;
}

void bst::freememory(node *root)
{
	if(root==NULL)
		return;

	freememory(root->left);

	freememory(root->right);

	delete root;

}

void floor(node* root,int key,int& flor)
{
	if(root==NULL)
		return;

	if(key==root->data)
		{
			flor=root->data;
			return;
		}
	else if(key<root->data)
	{
		floor(root->left,key,flor);
	}
	else if(key>root->data)
	{
		flor=root->data;
		floor(root->right,key,flor);
	}


}

int floor(node *root,int key)
{
	int flor;

	floor(root,key,flor);

	return flor;
}

int size(node *root)
{
	if(root==NULL)
		return 0;
	
	return root->count;
}

int select(node *root,int rank)  // return the element with rank k
// int count is required for this purpose								// such that k elements are less than element to be returned
{
	if(root==NULL)
	{
		cout<<"no element in the tree";
		return 0;
	}

     	if(size(root->left)==rank)
			return root->data;

		if(size((root->left))>rank)
			return select(root->left,rank);

		
		return select(root->right,rank-size(root->left)-1);

}


int ranki(node *root,int key)             // returns the rank of the element  // since rank is ambiguous
{                                        // if the element is not return rank if suppose the element would be there

	if(root==NULL)
	{
	//	cout<<"element cannot be found ";
		return 0;
	}

	if(root->data==key)
		return size(root->left);

	if((root->data)>key)
		return ranki(root->left,key);

	if((root->data)<key)
		return (size(root->left) +1+ranki(root->right,key));


}

node* contains(node* root,int hi)
{
	if(root==NULL)
	return NULL;

	if(root->data==hi)
		return root;
	else if(root->data<hi)
		return contains(root->right,hi);
	
	return contains(root->left,hi);

}

int no_keys(node *root,int lo,int hi)
{
	if(contains(root,hi))
		return (ranki(root,hi)-ranki(root,lo)+1);
	else
		return (ranki(root,hi)-ranki(root,lo));

}

void search_range(int lo,int hi,node* root,deque<int>& dq)
{
	if(root==NULL)
		return ;

	if((root->data)>=lo && (root->data)<hi)
		search_range(lo,hi,root->left,dq);

	if((root->data)>=lo && (root->data)<=hi)
		dq.push_back(root->data);

	if(root->data>=hi)
		return;

	search_range(lo,hi,root->right,dq);

}

bool haspathsum(node* nod,int sum)
{
	
		int subsum=sum-nod->data;

		if(nod->left==NULL && nod->right==NULL)
			return ((sum-nod->data)==0);
		
	bool left=0,right=0;

		if(nod->left!=NULL)
		left=haspathsum(nod->left,subsum);

		if(nod->right!=NULL)
		 right=haspathsum(nod->right,subsum);

		return (left || right);
	
}

void printpaths(node* nod,string str)
{
	string sofar;
	

	sofar=str+to_string(nod->data)+" -> ";

	if(nod->left==NULL && nod->right==NULL)
	{
		cout<<sofar;
		cout<<endl;
	}
	if(nod->left!=NULL)
		printpaths(nod->left,sofar);

	if(nod->right!=NULL)
		printpaths(nod->right,sofar);
}

void mirror(node* nod)
{
	if(nod==NULL)
		return;

	mirror(nod->left);
	mirror(nod->right);

	node *temp=nod->left;

	nod->left=nod->right;

	nod->right=temp;
}

void double_tree(node *nod)
{
	if(nod==NULL)
		return;

	double_tree(nod->left);
	double_tree(nod->right);

	node *temp=nod->left;
	(nod->left)=new node(nod->data);
	(nod->left)->left=temp;
}

int same_tree(node* a,node* b)
{
	if(a==NULL && b==NULL)
		return 1;

	if(a==NULL && b!=NULL)
		return 0;

	if(b==NULL && a!=NULL)
		return 0;

	if(a->data!=b->data)
		return 0;

	int left=0,right=0;

	left=same_tree(a->left,b->left);

	right=same_tree(a->right,b->right);

	return (left && right);

}

void check(node *nod,int& x)
{
	static node* prev=NULL;

	if(nod==NULL)
		return;

	check(nod->left,x);

	if(prev!=NULL && prev->data>nod->data)
		x=0;

	prev=nod;

	check(nod->right,x);
}

int isbst(node *root)
{
	int x=1;
	check(root,x);

	return x;
}

int count_leaf(node* nod)
{
	if(nod==NULL)
		return 0;

	if(nod->left==NULL && nod->right==NULL)
		return 1;

	return(count_leaf(nod->left)+count_leaf(nod->right));

}

void populate_inoder(node *root)
{
	static node* prev=NULL;
	
	if(root==NULL)
		return;

	populate_inoder(root->left);

	if(prev!=NULL)
		prev->next=root;

	prev=root;

	populate_inoder(root->right);
}


string int_to_string(int n)
{
		static string str="";
		if(n==0)
		{
			if(str=="")
			str=(char)n+'0';			
			
			return str;
		}
	
		int a=n%10;

		string c;
		c=(char)a+'0';
		str.insert(0,c);

		return (int_to_string(n/10));
}




bool height_balanced(node* nod)
{
	if(nod==NULL)
		return true;

	int h_left_tree=maxheight(nod->left);

	int h_right_tree=maxheight(nod->right);

	cout<<" left "<<h_left_tree;
	cout<<" right "<<h_right_tree;


	if(abs(h_left_tree-h_right_tree)>1)
		return false;

	return true;

}

// carrer cup page 54

void inser(int arr[],int lo,int high,bst& tree)
{
	if(lo>high || high<lo) 
		return;

	int mid=(lo+high)/2;

	tree.insert(arr[mid]);

	inser(arr,lo,mid-1,tree);
	inser(arr,mid+1,high,tree);
}

void inorder_successor(node *nod,node* succ,node **ans)
{
	static node* prev=NULL;

	if(nod==NULL)
		return;

	inorder_successor(nod->left,succ,ans);

	if(prev==succ)
	{
		(*ans)=nod;
	//	return;
	}

	prev=nod;

	inorder_successor(nod->right,succ,ans);

}

node* get_inorder_successor(bst& tree,node* nod)
{
	if(nod==NULL)
		return NULL;

	node *temp=NULL;

	inorder_successor(tree.getroot(),nod,&temp);

	return temp;

}

node* search_value(node *root,int value)
{
	if(root==NULL)
		return NULL;

	if(root->data==value)
		return root;

	if(root->data>value)
		return search_value(root->left,value);

	return search_value(root->right,value);

}

//// lowest common ancestor in a binary tree

int countmatches(node* root,node *p,node *q)
{
	if(!root)
		return 0;

	int match=countmatches(root->left,p,q) + countmatches(root->right,p,q);

	if(root==p || root==q)
		return 1+match;
	else
		return match;

}

node* lca(node* root,node* p,node *q)
{
	if(!root || !p || !q)
		return NULL;

	if(root==p || root==q)
		return root;

	int totalmatch=countmatches(root->left,p,q);

	if(totalmatch==1)
		return root;
	else if(totalmatch==2)
		return lca(root->left,p,q);
	else
		return lca(root->right,p,q);

}


// preorder traversal

void preorder(node* nod)
{
	if(nod==NULL)
		return;

	cout<<" "<<nod->data<<" ";

	preorder(nod->left);
	preorder(nod->right);


}


// saving bst in the file in the disk

void savebst(node *nod,ofstream& ofile)
{

	if(!nod)
		return;

	ofile<<nod->data<<endl;

	savebst(nod->left,ofile);
	savebst(nod->right,ofile);
}

// create bst from file preoder linear time

void createbst(node** nod,int& insertval,int min,int max,ifstream& ifile)
{
	if(insertval>min && insertval<max)
	{
		int val=insertval;
		(*nod)=new node(insertval);

		if(ifile>>insertval)
		{
			createbst(&((*nod)->left),insertval,min,val,ifile);

			createbst(&((*nod)->right),insertval,val,max,ifile);
		}

	}


}

// inorder iteratively

void iterative_inorder(node *nod)
{

	vector<node*> stac;

	int done=true;

	while(done)
	{
		if(nod!=NULL)
		{
		stac.push_back(nod);
		nod=nod->left;
		}

		else
		{
			if(!stac.empty())
			{	
			nod=stac.back();
			stac.pop_back();

			cout<<"  "<<nod->data;

			nod=nod->right;
			}
			else
				done=false;

			
		}


	}






}




int _tmain(int argc, _TCHAR* argv[])
{

		bst tree;

		tree.insert(10);
		
			tree.insert(8);
			tree.insert(5);
			tree.insert(7);
			
	tree.insert(3);

		tree.insert(4);
			tree.insert(23);
			tree.insert(26);
			tree.insert(28);


	//		tree_to_list(tree.getroot());


	/*		while(list_head!=NULL)
			{

				cout<<" "<<list_head->data;
				list_head=list_head->right;
			}

			*/

			



	//		iterative_inorder(tree.getroot());



	//		preorder(tree.getroot());



			/// saving to disk

	/*		const char* filename="file.txt";

			ofstream ofile;

			ofile.open(filename);

			if(!ofile)
			{

				cout<<"failed to open file to write";
				return 1;
			}

			savebst(tree.getroot(),ofile);

			ifstream ifile;

			ifile.open(filename);

		    if(!ifile)
			{

				cout<<"failed to open file to read";
				return 1;
			}


			

		bst tree2;

		//tree2.insert(3);

		int val;

		ifile>>val;

		node *tere=tree.getroot();

		createbst(&tere,val,(1<<31),0x7fffffff,ifile);


			cout<<endl<<" preorder traversal of the tree is";

			cout<<endl;


			preorder(tere);

		*/







/*			node *temp,*temp2;

			temp=get_inorder_successor(tree,search_value(tree.getroot(),5));
			
			temp2=get_inorder_successor(tree,search_value(tree.getroot(),4));

		


		cout<<lca(tree.getroot(),temp,temp2)->data;
			
			*/
		//	if(temp)
	//		{
		//		cout<<" successor "<<temp->data;

		//	}

		

/*	int arr[]={1,2,3,4,5,6,7};

	inser(arr,0,6,tree2);

	tree2.inorder();

			if(height_balanced(tree2.getroot()))
			{
				cout<<" height balanced ";
			}
			else
				cout<<"unbalanced";

*/

//mirror(tree.getroot());
/*
tree.inorder();

cout<<endl;

populate_inoder(tree.getroot());

node *temp=tree.getroot();

while(temp->left!=NULL)	
	temp=temp->left;


		while(temp!=NULL)
		{
			cout<<temp->data<<"->  ";
			temp=temp->next;
		}
*/
		//	if(isbst(tree.getroot()))
		//		cout<<"it is bst";

		//	

		//	cout<<"leaf no is "<<count_leaf(tree.getroot());
			
//			if(haspathsum(tree.getroot(),23))
	//			cout<<"got it";
			cout<<endl;
		//	printpaths(tree.getroot(),"");
		//	cout<<int_to_string(1);
			
	//		double_tree(tree.getroot());
	//		tree.inorder();
//			tree.delete_key(3);
			cout<<endl;
//						
		//	if(same_tree(tree.getroot(),tree2.getroot()))
				cout<<"same";
		//	else
				cout<<"not same";
			//tree.inorder();
			int flor;


	//		cout<<"enter the element to get the floor  ";
		//	cin>>flor;
cout<<endl;



// cout<<"element of rank is "<<select(tree.getroot(),8);

// cout<<"rank of the element is "<<ranki(tree.getroot(),12);

/**


deque<int> dq;

//cout<<"no of elements in range is  "<<no_keys(tree.getroot(),1,16)<<"  "<<endl;

search_range(5,12,tree.getroot(),dq);

while(!dq.empty())
{
	cout<<"  "<<dq.front();

	dq.pop_front();

}


**/

// cout<<"floor of  "<<floor(tree.getroot(),flor);


		//	tree.levelorder();

		//	cout<<endl;

	//		cout<<maxheight(tree.getroot());


		

	return 0;
}

