/***
  A sequence of number is called arithmetic if it consists of at least three elements and 
  if the difference between any two consecutive elements is the same.
  A zero-indexed array A consisting of N numbers is given. 
  A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A. 

这是一道在大小为N的数组中寻找连续的等差数列（长度至少为3）个数得题目，我的做法比较原始，就是按照长度递增的顺序依次判断当前序列是否为等差
序列，时间复杂度较大，代码如下：
***/
int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector< vector<bool> > isAri(n, vector<bool>(n, true));
        int cnt = 0;
        for(int l=3; l<=n; l++)
        {
            for(int i=0; i<=n-l; i++)
            {
                int j = i + l - 1;
                if(isAri[i][j-1])
                {
                    int d = (A[j-1] - A[i]) / (j-1-i);
                    if(A[j]-A[j-1] == d)
                    {
                        cnt++;
                    }
                    else
                    {
                        isAri[i][j] = false;
                    }
                }
                else
                {
                    isAri[i][j] = false;
                }
            }
          }
        return cnt;
        
    }
    /**
    大神用一个一维数组来保存子问题的解，数组中第i个元素，即dp[i]，表示所有以dp[i]为结尾的序列中等差序列的个数，初始时dp[i]=0,经分析，
    有如下递推公式:
    dp[i] = dp[i-1] + 1, if A[i] - A[i-1] == A[i-1] - A[i-2]
          = 0, else
    所以代码如下：
    **/
          int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int res = 0;
        vector<int> dp(n, 0);
        for(int i=2; i<n; i++)
        {
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1] + 1;
                res += dp[i];
            }
        }
        return res;
    }
        
    
    
