//******************************** Uniform cost based search ************************************//
#include <bits/stdc++.h>
using namespace std;
map<vector<vector<int>>, bool> visited;
vector<vector<int>> goal = {
	{2, 2, 0, 0, 0, 2, 2},
	{2, 2, 0, 0, 0, 2, 2},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{2, 2, 0, 0, 0, 2, 2},
	{2, 2, 0, 0, 0, 2, 2}};
stack<int> steps;
vector<vector<int>> board = {

	{2, 2, 0, 0, 0, 2, 2},
	{2, 2, 0, 0, 0, 2, 2},
	{0, 0, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{2, 2, 0, 1, 0, 2, 2},
	{2, 2, 0, 0, 0, 2, 2}};
class node
{
public:
	vector<vector<int>> state;
	vector<node *> child;
	node *parent;
	//string action;
	int path_cost;
	node() // default constructor
	{

		//cout << "default cons" << endl;
	
		for(int i = 0;i<7;i++)
		{
			vector<int> temp;
			for(int j = 0;j<7;j++)
			{   
				temp.push_back(board[i][j]);
			}
			state.push_back(temp);
		}

		

		parent = NULL;
	
		path_cost = 0;
		// h_n = 9;
	}
	node(vector<vector<int>> ar, node *p, int path_cst) //parametrized constructor
	{
		for (int i = 0; i < ar.size(); i++)
		{
			vector<int> temp;
			for (int j = 0; j < ar[0].size(); j++)
			{
				temp.push_back(ar[i][j]);
			}
			this->state.push_back(temp);
		}
		this->parent = p;
		//this->action = ac;
		this->path_cost = path_cst + 1;
		//this->h_n = h_val;
	}
	bool isvalid(vector<vector<int>> temp_board, int row, int col, int dir)
	{

		
		//cout << " size of temp board " << temp_board.size() << endl;
		// for (int i = 0; i < 7; i++)
		// {
		// 	for (int j = 0; j < 7; j++)
		// 	{
		// 		cout << temp_board[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		//cout << "is valid called :" << endl;
		if (row >= 0 && row < 7 && col >= 0 && col < 7)
		{

			if (temp_board[row][col] == 1)
			{
				//cout << "temp_board[row][col] == 1" << row << " " << col << endl;
				switch (dir)
				{
				case 1: //UP
					//cout << " check up for" << row << " " << col << endl;
					if (row - 2 >= 0)
					{

						//cout << "row,column isvalid() " << row << " " << col << " " << endl;
						if (temp_board[row - 1][col] == 1 && temp_board[row - 2][col] == 0)
							return true;
					}
					break;
				case 2: //DOWN

					if (row + 2 < 7)
					{

						//cout << "row,column isvalid() " << row << " " << col << " " << endl;

						if (temp_board[row + 1][col] == 1 && temp_board[row + 2][col] == 0)
							return true;
					}
					break;
				case 3: //LEFT

					if (col - 2 >= 0)
					{

						//cout << "row,column isvalid() " << row << " " << col << " " << endl;

						if (temp_board[row][col - 1] == 1 && temp_board[row][col - 2] == 0)
							return true;
					}
					break;
				case 4: //RIGHT
					if (col + 2 < 7)
					{

						//cout << "row,column isvalid() " << row << " " << col << " " << endl;

						if (temp_board[row][col + 1] == 1 && temp_board[row][col + 2] == 0)
							return true;
					}
					break;
				default:
					return false;
					break;
				} //end switch
			}
			//end peg check
		}
		//end starting bounds check
		return false;
	}
	void jump(vector<vector<int>> &temp, int a, int b, int dir)
	{
		switch (dir)
		{
		case 1: //N

			temp[a][b] = 0;

			temp[a - 1][b] = 0;

			temp[a - 2][b] = 1;

			break;
		case 2: //S

			temp[a][b] = 0;
			temp[a + 1][b] = 0;
			temp[a + 2][b] = 1;
			break;
		case 4: //E

			temp[a][b] = 0;
			temp[a][b + 1] = 0;
			temp[a][b + 2] = 1;
			break;
		case 3: //W

			temp[a][b] = 0;
			temp[a][b - 1] = 0;
			temp[a][b - 2] = 1;
			break;
		default:
			cout << "qwerty";
			break;
		}
	}
	void successor()
	{
		
		//cout << "Successor called " << endl;
		// for(int i = 0;i<7;i++)
		// {
		// 	vector<int> temp;
		// 	for(int j = 0;j<7;j++)
		// 	{
		// 		cout<<this->state[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 7; b++)
			{
				for (int c = 1; c <= 4; c++)
				{

					if (isvalid(this->state, a, b, c))
					{
						//cout << " suceessor -> isvalid() " << a << " " << b << " " << c << endl;
						vector<vector<int>> hold;
						for (int i = 0; i < 7; i++)
						{
							vector<int> tempp;
							for (int j = 0; j < 7; j++)
							{
								tempp.push_back(this->state[i][j]);
							}
							hold.push_back(tempp);
						}
						jump(hold, a, b, c);
						node *c = new node(hold, this, this->path_cost + 1);
						this->child.push_back(c);
					}
				}
			}
		}
	}
};
int nrpos = 0;
bool visit(vector<vector<int>> a)
{
	if (visited[a] == true)
		return true;
	else
		return false;
}
bool isGoal(vector<vector<int>> a) // checks for the goal state
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (a[i][j] != goal[i][j])
				return false;
		}
	}

	return true;
}
typedef pair<node *, int> pd;
struct myComp
{
	constexpr bool operator()(
		pair<node *, int> const &a,
		pair<node *, int> const &b)
		const noexcept
	{
		return a.second > b.second;
	}
};
void showboard(vector<vector<int>>board)
{
    int n;
    cout<<endl;
    for (int a = 0; a < 7; a++)
    {
        for (int b = 0; b < 7; b++)
        {
            n = board[a][b];
            if (n == 2)
                cout << " ";
            else
                cout << n;
        }
        cout << endl;
    }
}
void printsolution(node *n)
{
	cout << "\nPath  followed is :\n"
		 << endl;
	stack<node *> temp1;
	stack<node *> temp2;

	while (n != NULL)
	{

		temp2.push(n);
		temp1.push(n);
		n = n->parent;
	}
	int path_length=0;

	while (!temp1.empty())
	{
        cout<<endl;
		path_length++;
		// for (int i = 0; i < 7; i++)
		// {
		// 	for (int j = 0; j < 7; j++)
		// 	{
		// 		cout << temp1.top()->state[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		showboard(temp1.top()->state);
		temp1.pop();
		cout << endl;
	}
	// int path_length = 0;

	cout << "\nPath length is" << path_length - 1;
}
// void showboard(vector<vector<int>>board)
// {
//     int n;
//     cout<<endl;
//     for (int a = 0; a < 7; a++)
//     {
//         for (int b = 0; b < 7; b++)
//         {
//             n = board[a][b];
//             if (n == 2)
//                 cout << " ";
//             else
//                 cout << n;
//         }
//         cout << endl;
//     }
// }
int main()
{

	node *start = new node();
	//cout << "Hello 1" << endl;
	//cout << start->path_cost << endl;
	// for (int i = 0; i < 7; i++)
	// {
	// 	for (int j = 0; j < 7; j++)
	// 	{
	// 		cout << board[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
    //cout<<"size is"<<start->state.size();
    // for (int i = 0; i < 7; i++)
	// {
	// 	for (int j = 0; j < 7; j++)
	// 	{
	// 		cout << start->state[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	start->successor();
	//cout << "Hello 2";

	
	int ct = 0;
	priority_queue<pd, vector<pd>, myComp> frontier;
	set<node *> explored;
	frontier.push(make_pair(start, 0));
	while (!frontier.empty())
	{
		node *n = frontier.top().first;
		if (isGoal(n->state))
		{
			// cout << "NO of nodes explored are " << ct;
			// printsolution(n);
			// return 0;
			cout << "NO of nodes explored are " << ct << endl;
            cout << "Goal state is:" << endl;
            showboard(goal);
            cout << "start state is:" << endl;
            showboard(start->state);
            printsolution(n);
            return 0;
		}
		else
		{   

            showboard(n->state);
			explored.insert(n);

			visited[n->state] = true;
			ct++;
			n->successor();
			vector<node *>::iterator itr;

			for (itr = n->child.begin(); itr != n->child.end(); itr++)
			{

				vector<vector<int>> temp = (*itr)->state;
				if (!visit(temp))
				{
					frontier.push(make_pair(*itr, (*itr)->path_cost));
				}
			}
		}
		frontier.pop();
	}
}