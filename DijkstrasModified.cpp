//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))
 
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX //Infinity
 
const int sz=10001; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<int,int> > a[sz]; //Adjacency list
int dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not
vector<int> edgeTime;

void Dijkstra(int source, int n, int T) //Algorithm for SSSP 
{   
    for(int i = 0; i < n; i++) edgeTime.push_back(0);   //getting time for all edges.
    int time = 0;
    bool light = true;

    for(int i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    //Custom Comparator for Determining priority for priority queue (shortest edge comes first)
    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,int> ,vector<pair<int,int> >, prioritize> pq; //Priority queue to store vertex,weight pairs
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0

    while(!pq.empty()){

        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.first, cw=curr.second; //'cw' the final shortest distance for this vertex

        if(vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
            continue;

        vis[cv]=true; 
        
        for(int i = 0; i < a[cv].size(); i++){ //Iterating through all adjacent vertices
            //As each shortest distances for each vertex has it's own time.
            time = edgeTime[cv-1];  //-1 as it's a vector.
            light = true;   //reset light

            while(time >= T){
                time -= T;
                light = !light;
            }

            if(light == true){  //green light
                if(!vis[a[cv][i].first] &&   (a[cv][i].second+cw  <  dis[a[cv][i].first] and edgeTime[cv-1] < dis[a[cv][i].first])){ //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                    pq.push(make_pair(a[cv][i].first, (dis[a[cv][i].first] = a[cv][i].second+edgeTime[cv-1]+cw))); //Set the new distance and add to priority queue
                    
                    edgeTime[cv-1] += cw;
                }
            }
            else{   //red light
                if(!vis[a[cv][i].first] &&   (a[cv][i].second+cw+(T-time)  <  dis[a[cv][i].first] and edgeTime[cv-1]+(T-time) < dis[a[cv][i].first])){
                    pq.push(make_pair(a[cv][i].first, (dis[a[cv][i].first] = a[cv][i].second+edgeTime[cv-1]+cw+(T-time))));
                    
                    edgeTime[cv-1] += cw + (T-time);
                }
            }

            cout << "time: " << edgeTime[cv-1] << "    cv: " << cv << "     cw: " << cw;
            cout << "    a[cv]["<<i<<"].second+cw: " << a[cv][i].second+cw << "   dis[a[cv]["<<i<<"].first]: " << dis[a[cv][i].first] << endl;
        }

        //time = 0;
    }
}
 
int main() //Driver Function for Dijkstra SSSP
{
    int n,m,x,y,w, T, source = 1;//Number of vertices and edges
    //cout<<"Enter number of vertices and edges in the graph\n";
    cin >> n >> T >> m;
    
    for(int i=0;i<m;i++) //Building Graph
    {
        cin >> x >> y >> w; //Vertex1, Vertex2, weight of edge
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }

    Dijkstra(source, n, T);//SSSP from source (Also passing number of vertices as parameter)

    cout << dis[n] << endl;
    
    return 0;
}