#include <iostream>
using namespace std;
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
int main()
{
    //     priority_queue<int, vector<int>, greater<int>> gq;
    //     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    //                    greater<pair<int, pair<int, int>>>>
    //         minHeap;
    //     pair<int, pair<int, int>> p = make_pair(1, pair<int, int>(3, 3));
    //     pair<int,pair<int,int>>p2 = make_pair(2,pair<int,int>(3,4));
    //     minHeap.push(p);
    //     minHeap.push(p2);
    //     cout<<minHeap.top().second.first<<endl;
    //     minHeap.pop();
    //     cout<<minHeap.top().second.second<<endl;
    //     unordered_map<pair<int,int>,int>m;
    class Solution
    {
    public:
        vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
        {
            int len1 = nums1.size() - 1;
            int len2 = nums2.size() - 1;
            vector<vector<int>> v;
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            map<pair<int, int>, int> m;
            m[{0, 0}] = 1;
            pq.push(make_pair(nums1[0] + nums2[0], pair<int, int>(0, 0)));
            while (k-- && pq.empty() != true)
            {
                vector<int> ele;
                int index1, index2;
                pair<int, int> p1 = pq.top().second;
                ele.push_back(nums1[p1.first]);
                ele.push_back(nums2[p1.second]);

                v.push_back(ele);
                index1 = p1.first;
                index2 = p1.second;
                pq.pop();
                pair<int, pair<int, int>> p2;
                if (m.count({index1 + 1, index2}) != true && index1 + 1 <= len1)
                {
                    p2 = make_pair(nums1[index1 + 1] + nums2[index2], pair<int, int>(index1 + 1, index2));
                    pq.push(p2);
                    m[{index1 + 1, index2}] = 1;
                }
                if (m.count({index1, index2 + 1}) != true && index2 + 1 <= len2)
                {
                    p2 = make_pair(nums1[index1] + nums2[index2 + 1], pair<int, int>(index1, index2 + 1));
                    pq.push(p2);
                    m[{index1, index2 + 1}] = 1;
                }
                ele.clear();
            }
            return v;
        }
    };
}