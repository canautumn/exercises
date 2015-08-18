/*
219
Contains Duplicate II
https://leetcode.com/problems/contains-duplicate-ii/


Description:

Given an array of integers and an integer k, find out whether there are two 
distinct indices i and j in the array such that nums[i] = nums[j] and the 
difference between i and j is at most k.

(EASY) Array, Hash Table
Similar Problems: 217 Contains Duplicate, 220 Contains Duplicate III
*/

/*
SOLUTION: (A customized hash map implementation, where index range checking is 
done while the linked list traversal.)

Tips:
- Note that the bucket number of the hash map heavily influences the 
performance.
- Always remember to initialize any plain type array. In this case, the 
'ListNode ** buckets' is an array of pointers. Without initialization, some of 
the pointer could be non-NULL, which could cause segmentation fault when 
traversing or deleting.
- If memory leak is acceptable, the hash map could be a little faster without 
destructor.

Pitfalls:
- When implementing hash map using "value % bucket_number" as the hash, 
remember to deal with NEGATIVE HASH, since for example "-1 & 10 == -1". One way 
to do this is to allocate "bucket_number * 2 - 1" buckets, and shift the 
negative hash to positive numbers to accommodate into array indexes.
- Always remember to initialize any plain type array to avoid unexpected 
behaviors.

[xmx]
(bucket number = 100)
19 / 19 test cases passed.
Status: Accepted
Runtime: 136 ms
(bucket number = 10000)
19 / 19 test cases passed.
Status: Accepted
Runtime: 20 ms
(bucket number = 10000, no memory releasing destructor)
19 / 19 test cases passed.
Status: Accepted
Runtime: 16 ms
*/


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        Hashmap emerged(100, k);
        for (int i = 0; i < nums.size(); ++i) {
            if (emerged.check_dist(nums[i], i)) return true;
            emerged.insert(nums[i], i);
        }
        return false;
    }
private:
    struct Hashmap {
        struct ListNode {
            int key;
            int val;
            ListNode *next;
            ListNode(int x, int y) : key(x), val(y), next(NULL) {}
        };
        ListNode ** buckets;
        int bucket_count;
        int dist;
        Hashmap(int bucket_count, int dist) : bucket_count(bucket_count), 
                                              dist(dist) {
            buckets = new ListNode*[bucket_count * 2 - 1];
            for (int i = 0; i < bucket_count * 2 - 1; ++i) buckets[i] = NULL;
        }
        ~Hashmap() { // a little faster if memory leak is permitted
            for (int i = 0; i < bucket_count * 2 - 1; ++i) {
                delete_list(buckets[i]);
            }
            delete[] buckets;
        }
        void insert(int key, int value) {
            int hash = key % bucket_count + bucket_count - 1;
            if (!buckets[hash]) buckets[hash] = new ListNode(key, value);
            else insert_node(buckets[hash], key, value);
        }
        void insert_node(ListNode * node, int key, int value) {
            if (!node->next) node->next = new ListNode(key, value);
            else insert_node(node->next, key, value);
        }
        bool check_dist(int key, int value) {
            int hash = key % bucket_count + bucket_count - 1;
            if (!buckets[hash]) return false;
            ListNode * probe = buckets[hash];
            while (probe) {
                 // value as index must be increasing monotonically
                if (probe->key == key && value - probe->val <= dist) {
                    return true;
                }
                probe = probe->next;
            }
            return false;
        } 
        void delete_list(ListNode * node) {
            if (!node) return;
            delete_list(node->next);
            delete node;
        }
    };
};

int main() {
    Solution solution;
    // vector<int> init_array {1, 2, 3, 1, 4, 5};
    vector<int> init_array(30000);
    iota(init_array.begin(), init_array.end(), 0);
    init_array[29999] = 0;
    cout << solution.containsNearbyDuplicate(init_array, 29999);
 
    return 0;
}
