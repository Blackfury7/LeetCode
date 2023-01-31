struct Player
{

    int score;

    int age;

public:
    Player(int age, int score) : age(age), score(score) {}
};

class Solution
{

    static bool comp(const Player &p1, const Player &p2)
    {
        if (p1.age == p2.age)
            return p1.score < p2.score;

        return p1.age < p2.age;
    }

    vector<vector<int>> dp;

    int getMaxScore(int curr, int prev, const vector<Player> &players)
    {
        if (curr == players.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int score = getMaxScore(curr + 1, prev, players);

        if (prev == -1 || players[curr].score >= players[prev].score)
        {
            score = max(score, players[curr].score + getMaxScore(curr + 1, curr, players));
        }

        return dp[curr][prev + 1] = score;
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {

        vector<Player> players;

        for (int i = 0; i < scores.size(); ++i)
        {
            players.push_back(Player(ages[i], scores[i]));
        }

        sort(players.begin(), players.end(), comp);

        dp.resize(scores.size(), vector<int>(scores.size() + 1, -1));

        return getMaxScore(0, -1, players);
    }
};