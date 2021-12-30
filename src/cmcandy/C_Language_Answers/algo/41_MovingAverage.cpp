class MovingAverage
{
public:
    /** Initialize your data structure here. */
    struct ListNode
    {
        int val;
        ListNode *next;
    };
    int free, num = 0;
    double avg = 0.0;
    ListNode *head = nullptr, *tail = nullptr;
    MovingAverage(int size)
    {
        free = size;
        head = new ListNode;
        head->val = -1;
        head->next = nullptr;
        // tail = head;
    }

    double next(int val)
    {
        if (free > 0)
        {
            ListNode *tmp = new ListNode;
            tmp->val = val;
            tmp->next = nullptr;
            if (tail == nullptr)
                head->next = tmp;
            else
            {
                tail->next = tmp;
            }
            tail = tmp;
            free--;
            avg = (avg * num + val) / (++num);
            // cout<<tail->next->val<<"\t"<<head->next->val<<endl;

            // if (head==tail) head=tmp;
        }
        else
        {
            ListNode *tmp = head->next;
            avg = (avg * num - tmp->val + val) / num;
            head->next = tmp->next;

            tmp->val = val;
            tail->next = tmp;
            tail = tmp;
            tmp->next = nullptr;
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */