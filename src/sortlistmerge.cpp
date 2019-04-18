//============================================================================
// Name        : sortlistmerge.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include "solu.h"
//#include <math>
using namespace std;


/*struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/



int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//return 0;
	Solution so;// = new Solution();
	ListNode* h1 = NULL;
	ListNode* h2 = NULL;
	TreeNode* r1 =NULL;
	TreeNode* r2 =NULL;
	//vector<int> x = so.printListFromTailToHead(h1);
	//ListNode* h = so.Merge(h1,h2);
	//int i = 3+2-4;
	vector<int>a={1,2};
	vector<int>b={2,1};
	vector<vector<int> > array(2,vector<int>(2,3));
	//array[0]=a;
	//array[1]=b;
	//cout << array.size() << endl<<array[0].size()<<endl;
	//cout <<so.Find(1,array)<<endl;
	//cout <<"5 in 1 2 3 4?"<<so.Find(5,array)<<endl;
	//char* str ="hello?";
	//cout<<str<<endl;
	//so.replaceSpace(str,7);
	//so.reConstructBinaryTree(a,b);
	//so.pop();
	//cout<<so.NumberOf1(-1)<<endl;
	//cout<<so.rectCover(2)<<endl;
	//cout<<so.jumpFloorII(3)<<endl;
	//cout<<so.Fibonacci(3)<<endl;
	//cout<<so.Power(2,-3)<<endl;
	//cout<<so.FindKthToTail(h1,2)<<endl;
	List li(a);
	//List li = new List(a);
	//li.print();
	//li.getValueAt();
	//solu h;
	//so.Merge1(h1,h2);
	//cout<<so.HasSubtree(r1,r2)<<endl;
	//so.printMatrix(array);
	//so.push(2);
	int arr[]={1,2,3,4,3,2,1};
	//int Num=5;
	set<int> iset(arr,arr+sizeof(arr)/sizeof(*arr));
	//set<int> iset(a.begin(),a.end());
	cout<<iset.size()<<endl;
	cout<<so.IsPopOrder(a,b)<<endl;




};


