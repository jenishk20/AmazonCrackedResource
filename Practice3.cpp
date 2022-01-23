class Solution {
public:
	int dp[101];
//     int recur(string s,int idx)
//     {
//         if(idx==s.size())
//             return 1;
//         if(s[idx]=='0')
//             return 0;
//         if(idx==s.size()-1)
//             return 1;
//         if(dp[idx]!=-1)
//             return dp[idx];
//         string temp=s.substr(idx,2);

//         int op1=recur(s,idx+1);
//         int op2=(stoi(temp)>=1 and stoi(temp)<=26)?recur(s,idx+2):0;

//         return dp[idx]=op1+op2;
//     }
	int numDecodings(string s) {


		memset(dp, 0, sizeof dp);
		int n = s.size();
		if (s[0] == '0')
			return 0;
		if (n == 1)
			return 1;
		int i, j;
		dp[0] = 1;
		dp[1] = 1;
		for (i = 2; i <= n; i++)
		{
			int one = s[i - 1] - '0';
			string temp = s.substr(i - 2, 2);
			if (one >= 1)
				dp[i] += dp[i - 1];
			if (stoi(temp) >= 10 and stoi(temp) <= 26)
			{
				dp[i] += dp[i - 2];
			}


		}
		return dp[n];
	}
};