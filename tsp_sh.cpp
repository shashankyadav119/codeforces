#include <bits/stdc++.h>
using namespace std;
//#include <graphics.h>
vector<int> cities;
vector<int> finalOrder;
int arr[131]; // arr is the array that stores the City order
int numOfCities;
int dist[131][131];
class TSP
{
public:
    int points[131][2];
    int numcities;

    int CalculateDistance(int x1, int y1, int x2, int y2)
    {
        //return int(sqrt(pow(x1-x2,2)+pow(y1-y2,2)) + 0.5 );
        return int(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) + 0.5 );
    }
    void input_pos()
    {
        cout << "enter no of cities ";
        cin >> numcities;
        int i = 0;
        cout << "Enter cordinates of points " << endl;
        while (i < numcities)
        {
            cin >> points[i][0] >> points[i][1];
            i++;
        }
    }
    void dist_graph()
    {   cout<<"calculating distances initials";
        for (int i = 0; i < 131; i++)
        {
            dist[i][i] = 0;
            for (int j = i + 1; j < 131; j++)
            {
                cout<<"finding distance bw "<<points[i][0]<<" "<<points[i][1]<<" and "<<points[j][0]<<" "<<points[j][1] <<" is "<<endl;
                dist[i][j] = CalculateDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
                dist[j][i] = dist[i][j];
                cout<<dist[i][j]<<" ";
                // cout<<"calculating of "<<points[i][0]<<" "<<points[i][1]<<" ; "<<points[j][0]<<" "<<points[j][1]<< " is"<<dist[i][j]<<endl;
            }
        }
      
    }
};
int getTourLength()
{    cout<<"cities size is"<<cities.size()<<""<<endl;
    vector<int>::iterator it = cities.begin();

    it = cities.begin();
    int pcity1 = *it, ncity;

    int tourLength = dist[0][pcity1];
    for (it = cities.begin() + 1; it != cities.end(); it++)
    {
        ncity = *it;
        tourLength += dist[pcity1][ncity];

        pcity1 = ncity;
    }

    tourLength += dist[pcity1][0]; //adding the distance back to the source path
    cout<<"returning "<<tourLength;
    return tourLength;
}
int get_initial_tour_length()
{
    //cout << " findint innitial permutation" << endl;
    // for (int i = 0; i < numOfCities; i++)
    //     arr[i] = i;
    // cities.clear();
    // for (int i = 0; i < numOfCities; i++)
    // {
    //     cities.push_back(arr[i]);
    //     finalOrder.push_back(arr[i]);
    // }

    //vector<int>::iterator itr;
    // cout << " initial permutaion is:" << endl;
    // for (itr = cities.begin(); itr != cities.end(); itr++)
    // {
    //     cout << (*itr) << " " << endl;
    // }
     vector<int>::iterator it;
    int numCities=numOfCities,i,j;

    for(i=0;i<numCities;i++)
    {
        arr[i]=i;
        //cout<<"arr is "<<i<<"\n";
    }
    int best,bestIndex;
    for(i=1;i<numCities;i++)
    {
        best=INT_MAX;
        for(j=i;j<numCities;j++)
        {
            if(dist[i-1][j]<best)
            {
                best=dist[i][j];
                bestIndex=j;
            }
        }
        swap(i,bestIndex);
    }
    cities.clear();
    for(i=1;i<numCities;i++)
    {
        cities.push_back(arr[i]);
        finalOrder.push_back(arr[i]);
    }
    
    // int nearestNeighbourTourLength=getTourLength();
    // return nearestNeighbourTourLength;
    int TourLength = getTourLength();
    return TourLength;
}
double getProbability(int difference, double temperature) //This function finds the probability of how bad the new solution is
{
    return exp(-1 * (difference / temperature));
}
void swap(int i, int j)
{
    vector<int>::iterator it = cities.begin();
    int temp = *(it + i);
    *(it + i) = *(it + j);
    *(it + j) = temp;
}
int mini = INT_MAX;
int main()
{
    TSP obj;
    vector<int>::iterator it2,it;
    obj.input_pos();
    obj.dist_graph();
    
    numOfCities = obj.numcities;
    int tourlength = get_initial_tour_length();
    cout<<" initial tour length is "<<tourlength<<endl;
    // cout<<tourlength<<endl;
    if(mini>tourlength) mini = tourlength;
    double temper,coolingrate = 0.9,absoluteTemper = 0.00001,prob;
    int posi1 = 0,posi2 = 0;
    int newTourLength,difference;
    int Tm = 1000;
    srand(time(0));
    int iter_max = 1000;
    for (int i = 1; i < 5; i++)
    {
        ///random_shuffle(cities.begin(), cities.end());
        temper = 9999999999999.0;
        while(temper > absoluteTemper)
        {
            posi1 = int(rand()%numOfCities - 1);
            posi2 = int(rand()%numOfCities - 1);
            while(posi1 == posi2)
            {
                posi1 = int(rand()%numOfCities - 2);
                posi2 = int(rand()%numOfCities - 2);
            }
            swap(posi1,posi2);
            it2 = cities.begin();
            if(posi2>posi1)
            random_shuffle(it2 + posi1, it2 + posi2);
            newTourLength = getTourLength();
            if(mini > newTourLength) mini = newTourLength;
            difference = newTourLength - tourlength;
        }
        vector<int> pos;
        pos.push_back(0);
        pos.push_back(0);
        while (pos[0] == pos[1])
        {
            //cout << "inside while loop" << endl;
            pos[0] = rand() % numOfCities;
            pos[1] = rand() % numOfCities;
        }
        cout << " pos[0] is" << pos[0] << " pos[1] is" << pos[1] << endl;
       // sort(pos.begin(), pos.end());
	   swap(pos[0], pos[1]);
        it=cities.begin();
        
        //int citinum=*it;
        cout<<"it is pointing to "<<*it<<endl;
        cout<<(*(it+pos[0]))<<" "<<(*(it+pos[1]))<<endl;
		if(pos[1]>pos[0])
        random_shuffle((it+pos[0]),(it+pos[1]));
       
        vector<int>::iterator itc;
        cout<<" new order of cities is"<<endl;
        cout<<"size of cities  is"<<cities.size()<<endl;
        for(itc=cities.begin();itc!=cities.end();itc++)cout<<(*itc)<<" ";
        //reverse(cities.begin() + pos[0], cities.begin() + pos[1]);
        vector<int>::iterator itr;
        // itr = cities.begin();
        // random_shuffle(itr + pos[0], itr + pos[1]);

        int newTourLength = getTourLength();
        cout<<"new tour length is"<<newTourLength<<endl;

        //cout << "prev tour lenght is" << tourlength << " new  tour lenght is " << newTourLength << endl;
        int E = -tourlength + newTourLength;
        // cout << " E is" << E << endl;
        int T = Tm / i;
        if (E < 0 or (E > 0 and (getProbability(E, T) > rand() % 2)))
        {
            finalOrder.clear();
            for (it2 = cities.begin(); it2 != cities.end(); it2++)
            {
                finalOrder.push_back(*it2);
            }
        }
        // vector<int>::iterator itrt;
        // cout << "Final order is" << endl;
        // for (itrt = finalOrder.begin(); itrt != finalOrder.end(); itrt++)
        // {
        //     cout << *itrt << " ";
        // }

        tourlength = newTourLength;

        random_shuffle(cities.begin(), cities.end());
    }

    vector<int>::iterator itrt, itr1;
    itr1 = finalOrder.begin();
    cout<<"size of final order is"<<finalOrder.size()<<endl;
    // int x1 = obj.points[*itrt + 1][0];
    // int y1 = obj.points[*itrt + 1][1];
    cout << "Final order of Travel would be " << endl;
    //int gd = DETECT, gm;
    // initgraph(&gd, &gm, "");
      cout<<" x cordinates are--"<<endl;
    for (itrt = finalOrder.begin(); itrt != finalOrder.end(); itrt++)
    {

        // cout << *itrt << " ->";
        // cout<<obj.points[*itrt+1][0]<<" "<<obj.points[*itrt+1][1]<<endl;
        int x2 = obj.points[*(itrt)][0];
        int y2=obj.points[*(itrt)][1];
        //cout<<x2<<" "<<y2<<"citi no ->"<<(*itrt)<<endl;
        cout<<x2<<endl;
       // int y2 = obj.points[*(itrt + 1) + 1][1];
        // line(x1, y1, x2, y2);
        //x1 = x2;
        //y1 = y2;

    }
    cout<<" y cordinates are--"<<endl;
    for (itrt = finalOrder.begin(); itrt != finalOrder.end(); itrt++)
    {
        
        int x2 = obj.points[*(itrt)][0];
        int y2=obj.points[*(itrt)][1];
        //cout<<x2<<" "<<y2<<"citi no ->"<<(*itrt)<<endl;
        cout<<y2<<endl;
       // int y2 = obj.points[*(itrt + 1) + 1][1];
        // line(x1, y1, x2, y2);
        //x1 = x2;
        //y1 = y2;

    }
    //cout << *itr1;
}