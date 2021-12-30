

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace ::std;
class Node
{
public:
    int key;
    int val;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node() {}
};
class LRUCache
{
public:
    unordered_map<int, Node *> hash;
    int num;
    Node *head = new Node();
    Node *tail = new Node();
    LRUCache(int capacity)
    {
        num = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (hash.find(key) == hash.end())
            return -1;
        else
        {
            put(key, hash[key]->val);
            return hash[key]->val;
        }
    }

    void put(int key, int value)
    {
        Node *temp = new Node();
        if (hash.find(key) == hash.end())
        {
            hash[key] = temp;
            temp->key = key;
            if (hash.size() > num)
            {
                Node *del = tail->prev;
                del->next->prev = del->prev;
                del->prev->next = del->next;
                hash.erase(del->key);
            }
        }
        else
        {
            temp = hash[key];
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        temp->val = value;
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        temp->next->prev = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
