/**
 * Definition for singly-linked list.
 */
 
#include <algorithm>
#include <iostream>
#include<string>
#include <cmath>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * Head = new ListNode(0);
        ListNode * Tail = Head;
        int carryValue = 0;
        int digit1 =0;
        int digit2 =0;
        int sumVal = 0;
        while(l1 || l2 || carryValue){
            digit1 =  l1 ? l1->val : 0;
            digit2 = l2 ? l2->val: 0;
            sumVal = (digit1 + digit2 + carryValue);
            ListNode * temp = new ListNode(sumVal % 10);
            carryValue = sumVal/10;
            Tail->next = temp;
            Tail = Tail->next;
            l1 = l1? l1->next: nullptr;
            l2 = l2? l2->next: nullptr;
    }
    auto result = Head->next;
    delete Head;
    return move(result);
    }
};

int main () {
    ListNode * Head1 = new ListNode(0);
    ListNode * tail1 = Head1;
    ListNode * Head2 = new ListNode(0);
    ListNode * tail2 = Head2;
    int inp1[3] = {2, 4, 3};
    int inp2[3] = {5, 6, 4};
    for(int i = 0; i< 3; ++i){
        auto temp = new ListNode(inp1[i]);
        auto temp2 = new ListNode(inp2[i]);
        tail1->next = temp;
        tail1 = tail1->next;
        tail2->next = temp2;
        tail2 = tail2->next;
        }
    auto l1 = Head1->next;
    delete Head1;
    auto l2 = Head2->next;
    delete Head2;
    auto answer = Solution::addTwoNumbers(l1, l2);
    while (answer){
        std::cout << answer->val <<" ";
        answer = answer->next;
    }
    return 0;
}