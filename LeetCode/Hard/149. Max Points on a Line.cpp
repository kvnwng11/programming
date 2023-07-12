class Solution
{
  private:
    double calcSlope(vector<int> &p1, vector<int> &p2)
    {
        if (p1[0] == p2[0])
            return DBL_MAX;
        return (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
    }

  public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            unordered_map<double, int> counts;

            for (int j = 0; j < points.size(); ++j)
            {
                if (j != i)
                {
                    double slope = calcSlope(points[i], points[j]);
                    counts[slope] += 1;
                }
            }

            for (auto pair : counts)
            {
                ans = max(ans, pair.second);
            }
        }

        return ans + 1;
    }
};