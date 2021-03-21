#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string state;
    string l = "abc";
    string r = "xyz";

    vector<node *> child; // pointer to the array containing list of node

    node(string state)
    {
        this->state = state;
    }
    string swap(int x, int y, string str)
    {
        char temp = str[x];
        str[x] = str[y];
        str[y] = temp;
        return str;
    }

    int find_position(string s)
    {
        int pos;
        for (int i = 0; i < this->state.length(); i++)
        {
            if (this->state[i] == '_')
                pos = i;
        }
        return pos;
    }

    bool isvalid(string parent, string s)
    {

        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (parent[i] != s[i] and parent[i] == '_')
            {

                pos1 = i;
            }
             if(parent[i] != s[i] and parent[i] !='_')
            {
                pos2 = i;
                if(s[i])
            }
        }
        // a_bxy
        // ->ab_xy
    }

    void find_successor()
    {
        cout << "suceesor" << endl;
        int pos = find_position(this->state);

        string temp = this->state;

        for (int i = 0; i < this->state.length(); i++)
        { //cout<<" inside for"<<endl;
            // int p = find_position()
            if ((i >= pos - 2 and i <= pos + 2))
            {
                string st = swap(i, pos, this->state);

                node *g = new node(st);
                if (st != temp)
                {
                    this->child.push_back(g);
                    // frontier.push(g);
                }
            }
        }
    }
};
int main()
{
    node *start = new node("a_z");
    string goal = "z_a";
    start->find_successor();
    int steps = 0;
    set<node *> frontier;
    set<node *> explored;
    vector<node *>::iterator itr;
    for (itr = start->child.begin(); itr != start->child.end(); itr++)
    {
        frontier.insert(*itr);
    }
    while (!frontier.empty())
    {
        auto it = frontier.begin();
        node *n = *it;
        if (explored.find(n) == explored.end())
        {
            n->find_successor();
            vector<node *>::iterator itr;
            for (itr = n->child.begin(); itr != n->child.end(); itr++)
            {
                if (frontier.find(*itr) == frontier.end())
                    frontier.insert(*itr);
            }
            if (n->state == goal)
            {

                set<node *>::iterator itr;
                cout << "\n The frontier is : \n";
                for (itr = frontier.begin(); itr != frontier.end(); itr++)
                {
                    cout << '\t' << (*itr)->state << " ";
                }

                cout << endl;

                set<node *>::iterator itr1;
                cout << "\nThe  explored set is : \n";
                for (itr1 = explored.begin(); itr1 != explored.end(); itr1++)
                {
                    cout << '\t' << (*itr1)->state << " ";
                }
                cout << endl;
                cout << " goal found in " << steps << "steps" << endl;

                cout << '\n';
                break;
            }
            else
            {
                explored.insert(n);
                steps++;
            }
        }
        frontier.erase(*it);
    }
}