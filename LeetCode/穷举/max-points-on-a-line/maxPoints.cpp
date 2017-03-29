/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 *Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. 
 */
class Solution {
public:
   int maxPoints(vector<Point> &points)
    {
        unordered_map<float, int> mp;
        int maxNum = 0;
        for(int i = 0; i < points.size(); ++i)
        {       //注意每一次需要清空map, 且初始化mp[INT_MIN]=0
            mp.clear();
            mp[INT_MIN] = 0;
            int duplicate = 1;  //初始值为1，包含了当前点比较的点本身。
            for(int j = 0; j < points.size(); ++j)
            {
                if(j == i)continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    duplicate++;
                    continue;
                }
                float k = points[i].x== points[j].x ? INT_MAX:(float)(points[i].y - points[j].y)/(points[i].x - points[j].x);
                mp[k]++;
            }

            unordered_map<float, int>::iterator it = mp.begin();
            for(; it!= mp.end(); ++it)
                if(maxNum < (it ->second + duplicate))
                    maxNum = it ->second + duplicate;
        }
        return maxNum;	
    } 
};  