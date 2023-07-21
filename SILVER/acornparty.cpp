    #include <iostream>
    #include <vector>
    #include <queue>
    #include <set>

    using namespace std;

    int main() {
        int n, g;
        cin >> n >> g;

        vector<set<int>> v(n);
        for (int i = 0 ; i < g ; i++) {
            int k;
            cin >> k;
            for (int j = 0 ; j < k ; j++) {
                int num;
                cin >> num;
                v[i].insert(num);
            }
        }
        
        queue<int> q;
        vector<bool> done(n, false);
        done[0] = true;
        q.push(1);
        int ans = 0;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            for (int i = 0 ; i < n ; i++) {
                v[i].erase(num);
                if (v[i].size() == 1) {
                    if (!done[*v[i].begin()]) {
                        q.push(*v[i].begin());
                        done[*v[i].begin()] = true;
                    }
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
    /*
    Acorn Party
    Harry the squirrel has recently found a pile of acorns. Wanting to share this pile of acorns, Harry decides to invite some of his friends to have a party while eating the acorns. However, due to the limited amount of acorns, Harry wants to invite the smallest possible number of his friends.

    Among Harry’s friends, there are certain groups of friends that are hard to separate. For any group of size k, if Harry invites at least k-1 of the squirrels in the group to eat acorns, he must also invite the final friend to include the entire group. Friend groups can be of any size and can overlap with each other, but no two groups contain the exact same members. The sum of all the group sizes is at most 250,000.

    Given the friend groups, help Harry determine the minimum number of friends he can invite to the acorn party if he decides that he must definitely start by inviting friend #1 (he has numbered his friends from 1..N for convenience, with N being at most 1,000,000.

    INPUT FORMAT

    * Line 1: Two space-separated integers: N (the number of friends), and G (the number of groups).

    * Lines 2..1+G: Each line describes a group of friends. It starts with an integer giving the size S of the group, followed by the S friends in the group (each an integer in the range 1..N).

    OUTPUT FORMAT

    * Line 1: The minimum number of friends Harry can invite to his party.

    SAMPLE INPUT

    15 4
    2 1 4
    2 4 5
    6 1 2 3 4 6 7
    4 4 5 2 1
    There are 15 friends and 4 groups.  The first group contains squirrels 1 and 4, and so on.

    SAMPLE OUTPUT

    4
    In addition to squirrel #1, Harry must invite squirrel #4 (due to the first group constraint), squirrel #5 (due to the second group constraint), and also squirrel #2 (due to the final group constraint).
    */