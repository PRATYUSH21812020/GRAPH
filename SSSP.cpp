#include<bits/stdc++.h>
using namespace std;
class Graph
{
  int v;    // no of vertices
  list<int>*l; // list to store a graph
public:
  Graph(int v)
  {
    this->v=v;  //initializing the vertices
    l=new list<int>[v];//creating a list dynamically for graph
  }
  void add_edge(int x,int y)
  {
    l[x].push_back(y);//adding edges of the undirected graph to the list
    l[y].push_back(x);
  }
  void SSSP(int src,vector<int> vertices)//single source shortest path for undirected graph
  {
    map<int,int>dist;//creating a distance map
    for(int i=0;i<vertices.size();i++)
    {
      dist[vertices[i]]=INT_MAX;
    }
    dist[src]=0;//except the source vertex whose distance is zero
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
      int temp=q.front();
      q.pop();
      for(auto it=l[temp].begin();it!=l[temp].end();it++)
      {
        if(dist[*it]==INT_MAX)
        {
          q.push(*it);
          dist[*it]=dist[temp]+1;
        }
      }
    }
    // printing all the distances
  for(int i=0;i<vertices.size();i++)
  {
    int vertex=vertices[i];
    int distance=dist[vertex];
    cout<<"vertex "<<vertex<<" distance from src "<<src<<"-> "<<distance<<endl;
  }
  }
};
int main()
{
  int v,temp;
  cin>>v;
  Graph g(v);
  vector<int>vertices;
  for(int i=0;i<v;i++)
  {
    cin>>temp;
    vertices.push_back(temp);
  }
  g.add_edge(2,1);
  g.add_edge(2,3);
  g.add_edge(1,0);
  g.add_edge(3,0);
  g.add_edge(3,4);
  g.add_edge(4,5);
  g.SSSP(0,vertices);
}
