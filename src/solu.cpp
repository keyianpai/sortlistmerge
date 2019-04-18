/*
 * solu.cpp
 *
 *  Created on: 2019Äê4ÔÂ16ÈÕ
 *      Author: Lenovo-T410
 */

#include "solu.h"
#include <set>

solu::solu() {
	// TODO Auto-generated constructor stub

}

solu::~solu() {
	// TODO Auto-generated destructor stub
}

int List::getValueAt(int position) {
    ListNode *p = head;
    if (p == NULL) {
        cout << "The List is Empty!" << endl;
        return -1;
    }
    int posi = 0;
    while (p != NULL && posi != position) {
            posi++;
            p = p->next;
        }
    if (p == NULL) {
            cout << "There is no value of this position in this List!" << endl;
        } else {
            cout << "In this Position,the value is" << p->val << endl;
        }

    return p->val;
}
void List::setValueAt(int position, int da) {
    ListNode *p = head;
    if (p == NULL) {
        cout << "The List is Empty!" << endl;
    } else {
        int posi = 0;
        while (p != NULL && posi != position) {
            posi++;
            p = p->next;
        }
        if (p == NULL) {
            cout << "There is No Position in this List!" << endl;
        } else {
            p->val = da;
            cout << "The Value in this position has been Updated!" << endl;
        }
    }
}

void List::Search(int da) {

    ListNode *p = head;
    if (p == NULL) {
        cout << "Sorry, The List is Empty!" << endl;
        return;
    }
    int count = 0;
    while (p != NULL && p->val != da) {
        p = p->next;
        count++;
    }
    cout << "the value you want to search is at position %d" << count << endl;
}

void List::Delete(int da) {
    ListNode *p = head, *q = head;
    if (p == NULL) {
        cout << "Sorry, The List is Empty!" << endl;
        return;
    }
    while (p != NULL && p->val != da) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    cout << "The Deletion Operation had been finished!" << endl;
}

void List::Insert(int da) {
    if (head == NULL) {
        head = tail = new ListNode(da);
        head->next = NULL;
        tail->next = NULL;
    } else {
        ListNode *p = new ListNode(da);
        tail->next = p;
        tail = p;
        tail->next = NULL;
    }

}

void List::print() {
    ListNode *p = head;
    while (p != NULL) {
        cout << p->val << " \a";
        p = p->next;
    }
    cout << endl;
}
ListNode* Solution:: Merge1(ListNode* h1, ListNode* h2){
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	ListNode* p1 = h1;
	ListNode* p2=h2;
	ListNode* head = new ListNode();
	ListNode* p = head;
	while(p1 && p2){
		if(p1->val<=p2->val){
			p->next = p1;
			p1=p1->next;
		}
		else{
			p->next =p2;
			p2=p2->next;
		}
		p=p->next;
	}
	if(p1)
		p->next=p1;
	if(p2)
		p->next=p2;
	//delete head;
	return head->next;


}
bool Solution::HasSubtree(TreeNode* r1, TreeNode* r2){
	if(r2==NULL||r1==NULL)
		return false;

	return isSubtree(r1,r2) || HasSubtree(r1->left,r2)|| HasSubtree(r1->right,r2);


}
bool Solution::isSubtree(TreeNode* r1, TreeNode* r2){
	if(r2==NULL){
		return true;
	}//r1 bigger
	if(r1==NULL)
		return false;
	if(r1->val==r2->val)
		return isSubtree(r1->left,r2->left) && isSubtree(r1->right,r2->right);
	else
		return false;


}
void Solution::Mirror(TreeNode *pRoot) {
	  if(pRoot==NULL)
		  return ;
	  TreeNode* temp = pRoot->left;
	  pRoot->left = pRoot->right;
	  pRoot->right = temp;
	  Mirror(pRoot->left);
	  Mirror(pRoot->right);


    }
vector<int> Solution::printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size(),col=matrix[0].size();
	vector<int> ans;
	vector<vector<bool>> visited(row,vector<bool>(col,false));
	int i=0,j=0,cur=0;
	while (cur < row*col){
		while(j<col && !visited[i][j]){
			ans.push_back(matrix[i][j]);
			visited[i][j]=true;
			j++;
			cur++;
		}
		j--,i++;
		while(i<row && !visited[i][j]){
			ans.push_back(matrix[i][j]);
			visited[i][j]=true;
			i++;
			cur++;
		}
		i--,j--;
		while(j>=0 && !visited[i][j]){
					ans.push_back(matrix[i][j]);
					visited[i][j]=true;
					j--;
					cur++;
				}
		j++,i--;
		while(i>=0 && !visited[i][j]){
					ans.push_back(matrix[i][j]);
					visited[i][j]=true;
					i--;
					cur++;
				}
		i++,j++;

	}
	return ans;

    }
void Solution::push(int value) {
	data.push(value);
	//int temp =minstack.top();
	if(minstack.empty())
		minstack.push(value);
	else if(value<minstack.top())
		minstack.push(value);
	else
		minstack.push(minstack.top());

    }
void Solution:: pop() {
	minstack.pop();
	//int ans = data.top();
	data.pop();
	//return ans;

    }
int Solution::top() {
	return data.top();

    }
int Solution::min() {
	return minstack.top();

    }
bool Solution::IsPopOrder(vector<int> pushV,vector<int> popV) {
	    set<int> out(pushV.begin(),pushV.end());
	    stack<int> st;
	    while(!popV.empty()){
	    	while(out.find(popV[0])!=out.end()){
	    		st.push(pushV[0]);
	    		out.erase(pushV[0]);
	    		pushV.erase(pushV.begin());

	    	}
	    	if(!st.empty()&&st.top()==popV[0]){
	    		st.pop();
	    		popV.erase(popV.begin());
	    	}
	    	else
	    		return false;

	    }
        return true;
    }
