/*
 * solu.h
 *
 *  Created on: 2019Äê4ÔÂ16ÈÕ
 *      Author: Lenovo-T410
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
//#include "solu.h" wrong
//#include <math>
using namespace std;

#ifndef SOLU_H_
#define SOLU_H_

class solu {
public:
	solu();
	virtual ~solu();
};
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int da = 0, ListNode *p = NULL) {
        this->val = da;
        this->next = p;
    }
};
class List{
private:
  ListNode *head,*tail;
  int position;
public:
  List(){head=tail=NULL;};
  List(vector<int> vec){
	  head=tail=NULL;
	  int n = vec.size();
	  for(int i=0;i<n;i++){
		  this->Insert(vec[i]);
	  }
  }
  ~List(){delete head;delete tail;};
  void print();
  void Insert(int da=0);
  void Delete(int da=0);
  void Search(int da=0);
  int getValueAt(int position=0);
  void setValueAt(int position=0, int da=0);

};
struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)

    {
    	if(pHead1==NULL)
    		return pHead2;
    	if(pHead2==NULL)
    		return pHead1;
    	ListNode* newHead;
    	if(pHead1->val<pHead2->val){
    		newHead = pHead1;
			newHead->next = Merge(pHead1->next,pHead2);
    	}
    	else{
    		newHead = pHead2;
    		newHead->next = Merge(pHead1,pHead2->next);
    	}
    	cout << "haha";
    	return newHead;

    }
    ListNode* ReverseList(ListNode* pHead) {
    	if(pHead==NULL)
    		return pHead;
    	ListNode* pre = NULL;
    	ListNode* cur = pHead;
    	ListNode* head = NULL;
    	while(cur!=NULL){
    		ListNode* next = cur->next;
    		if(next==NULL)
    			//return cur;
    			head = cur;
    		cur->next = pre;
    		pre = cur;
    		cur = next;

    	}
    	return head;

        }
    bool Find(int target, vector<vector<int> > array) {
    	if(array.empty())
    		return false;
    	int rows = array.size();
    	int cols = array[0].size();
    	int i=0,j =cols-1 ;
    	bool find = false;
    	while(i<rows&&j>=0){
    		if(array[i][j]>target){
    			j--;
    		}else if(array[i][j]<target){
    			i++;
    		}else{
    			//find = true;
    			return true;
    			break;
    		}
    	}
    	return find;

       }
    void replaceSpace(char *str,int length) {
            if(str==NULL||length==0)
            	return ;
            int strLen =0;
            int blank =0;
            int i =0;
            while(str[i]!='\0'){
            	strLen++;
            	//char temp = str[i];
            	if(str[i]==' ')
            		blank++;
            	i++;
            }
            int newLen = strLen + 2*blank;
            if(newLen>length)
            	return;
            while(strLen>=0&&newLen>strLen){
            	if(str[strLen]==' '){
            		str[newLen--]='0';
            		str[newLen--]='2';
            		str[newLen--]='%';


            	}else
            		str[newLen--]=str[strLen];
            	strLen--;
            }
            return ;

    	}
    vector<int> printListFromTailToHead(ListNode* head) {
    	vector<int> res;
    	if(head==NULL)
    		return res;
    	if(head->next==NULL){
    		res.push_back(head->val);
    	    return res;

        }else{
        res = printListFromTailToHead(head->next);
    }

		res.push_back(head->val);
		return res;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if(pre.empty()||(pre.size()!=vin.size()))
    		return NULL;//?
    	if(pre.size()==1 && pre[0]==vin[0])
    		return  new TreeNode(pre[0]);
    	TreeNode* root = new TreeNode(pre[0]);
    	auto ind = find(vin.begin(),vin.end(),pre[0]);//algorithm
    	int pos = distance(vin.begin(),ind);
    	vector<int> l_pre,l_vin,r_pre,r_vin;
    	l_pre.insert(l_pre.begin(),pre.begin()+1,pre.begin()+1+pos);
    	l_vin.insert(l_vin.begin(),vin.begin(),vin.begin()+pos);

    	root->left = reConstructBinaryTree(l_pre,l_vin);
    	r_pre.insert(r_pre.begin(),pre.begin()+1+pos,pre.end());
    	r_vin.insert(r_vin.begin(),vin.begin()+pos+1,vin.end());
    	root->right = reConstructBinaryTree(r_pre,r_vin);
    	return root;



        }
    int minNumberInRotateArray(vector<int> arr) {
    	if(arr.size()==0)
    		return 0;
    	int lo =0,hi=arr.size()-1;
    	while(lo<hi){
    		int mid = lo + (hi-lo)/2;
    		if(arr[mid]<arr[hi])
    			hi = mid ;
    		else if(arr[mid]>arr[hi])
    			lo = mid +1;
    		else
    			hi--;
    	}
    	return arr[hi];

        }
    void push1(int node) {
         stack1.push(node);
         //stack1.pop();
        }

    int pop1() {
        	if(stack2.empty()){
        		int n = stack1.size();
        		//int i;
        		for(int i=0;i<n;i++){
        			int data = stack1.top();
        			stack2.push(data);
		            stack1.pop();
        		}
        		if(n>0){
        			int data = stack2.top();
        			stack2.pop();
        			return  data;
        		}
        		else
        			return 0;
        	}
        	else{
        		int data = stack2.top();
        		stack2.pop();
        		return  data;

        	}

        }
    int  NumberOf1(int n) {
    	int count =0;
    	while(n!=0){
    		count++;
    		n&=(n-1);

        }
    	return count;
    }

    int rectCover(int n) {
    	if(n<0)
    		return 0;
    	int ans =1;
    	int pre=1,ppre =1;
    	for(int i=1;i<n;i++){
    		ans = pre + ppre;
    		ppre = pre;
    		pre = ans;
    	}
    	return ans;

    }
    int jumpFloorII(int n) {
    	if(n<0)
    		return 0;
    	int ans =1;
    	for(int i=1;i<n;i++){
    		ans*=2;
    	}
    	return ans;

        }
    int Fibonacci(int n) {
    	if(n<=0)
    		return 0;
    	int cur=1;
    	int ppre=0,pre=1;
    	for(int i=2;i<=n;i++){
    		cur = pre + ppre;
    		ppre = pre;
    		pre = cur;
    	}
    	return cur;

        }
    double Power(double base, int exponent) {
    	if(exponent==0)
    		return 1;
    	if(exponent<0 && base==0)
    		return 0;
    	int ex = exponent;
    	if(exponent<0)
    		 ex = -exponent;
    	double term = base,ans=1;
    	while(ex!=0){
    		if(ex%2)
    			ans*=term;
    		term *=term;
    		ex/=2;
    	}
    	if(exponent<0)
    		return 1.0/ans;
    	else
    		return ans;


        }
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
    	if(head==NULL || k<=0)
    		return NULL;
    	ListNode* p =head;
    	ListNode* q =head;
    	for(unsigned int i=1;i<k;i++){
    		if(p->next==NULL)
    			return NULL;
    		p=p->next;

    	}//reach k-1 when loop over

        while(p->next){
        	p=p->next;
        	q=q->next;
        }
    	return q;
        }
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2);
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    void Mirror(TreeNode *pRoot);
    vector<int> printMatrix(vector<vector<int> > matrix);
    void push(int value);

    void pop() ;
    int top() ;
    int min();
    bool IsPopOrder(vector<int> pushV,vector<int> popV);





    private:
        stack<int> stack1;//push
        stack<int> stack2;
        stack<int> data;
        stack<int> minstack;

};



#endif /* SOLU_H_ */
