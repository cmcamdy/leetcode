#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace ::std;
class RecentCounter
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
    };
    ListNode *head = nullptr, *tail = nullptr;
    RecentCounter()
    {
        head = new ListNode;
        head->val = -1;
        head->next = nullptr;
    }

    int ping(int t)
    {
        if (head->next == nullptr)
        {
            ListNode *tmp = new ListNode;
            head->next = tmp;
            tmp->val = t;
            tail = tmp;
            return 1;
        }
        else
        {
            int left = t - 3000, count = 1;
            ListNode *tmp = head;
            while (tmp->next != nullptr && tmp->next->val < left)
                tmp = tmp->next;
            while (tmp->next != nullptr && tmp->next->val >= left && tmp->next->val <= t)
            {
                count++;
                tmp = tmp->next;
            }
            ListNode *tmp2 = new ListNode;
            tmp2->val = t;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
            return count;
        }
    }
};

// 队列居然是有std库的。。。。
class RecentCounter2
{
private:
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t)
    {
        q.push(t);
        while (t - q.front() > 3000)
            q.pop();     //若时间太早，则循环出队
        return q.size(); //最后返回队列长度，即最近3000ms的请求次数
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main()
{
    RecentCounter *r = new RecentCounter();
    vector<int> lis = {1, 100, 3001, 3002};

    for (int i = 0; i < lis.size(); i++)
    {
        cout << r->ping(lis[i]);
    }
    // r->ping(1);
    // r->ping(100);
    // r->ping(3001);
    // r->ping(3002);
}