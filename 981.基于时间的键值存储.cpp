/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * 哈希表+二分查找 
 * 
 * [981] 基于时间的键值存储
 */
// @lc code=start
class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> hash;

public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        hash[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp)
    {
        auto &val = hash[key];
        // pair<int, string> p = {timestamp,string({127})};
        auto it = __upper_bound(val.begin(), val.end(), timestamp);
        if (it==val.begin()) 
            return "";
        return (--it)->second;
    }

    template <typename _ForwardIterator, typename _Tp>
    _ForwardIterator
    __upper_bound(_ForwardIterator __first, _ForwardIterator __last,
                  const _Tp &__val)
    {
        typedef typename iterator_traits<_ForwardIterator>::difference_type
            _DistanceType;

        _DistanceType __len = std::distance(__first, __last);

        while (__len > 0)
        {
            _DistanceType __half = __len >> 1;
            _ForwardIterator __middle = __first;
            std::advance(__middle, __half);
            if (__val < __middle->first)
                __len = __half;
            else
            {
                __first = __middle;
                ++__first;
                __len = __len - __half - 1;
            }
        }
        return __first;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
