//
// Created by Mac on 11/10/2023.
//
#include "iostream"
#include "list"
#include "unordered_map"
#include "vector"
using namespace std;
class City_Node{
public:
    string name;
    list<string> nbrs_list;
    City_Node(string name){
        this->name=name;
    }
};

class CitiesGraph{
    // we have to create a hashmap of city node where each city is containing the list of its neighbouring(nbrs) cities
    unordered_map<string,City_Node*> map;
public:
    CitiesGraph(vector<string> cities){
        // this will create a city pointer and make a hashmap of cities
        for (auto city:cities){
            map[city]=new City_Node(city);
        }
    }
    void addEdge(string source,string destination,bool undirected=false){
        // it is adding a destination city into nbrs of source city. i.e, taxila is neighbour of islamabad
        map[source]->nbrs_list.push_back(destination);
        if (undirected)
            // this will also islamabad as neighbour of taxila
            map[destination]->nbrs_list.push_back(source);
    }
    void displayGraph(){
        for(auto cityPair:map){
            string city =cityPair.first;
            City_Node* city_node = cityPair.second;
            cout<<city<<" --> { ";
            for(auto nbr:city_node->nbrs_list){
                cout<<nbr<<" ";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
    vector<string> cities;
    cities.push_back("Islamabad");
    cities.push_back("Peshawer");
    cities.push_back("Taxila");
    cities.push_back("Wah-cantt");
    cities.push_back("Abottabad");

    CitiesGraph citiesGraph(cities);
    citiesGraph.addEdge("Islamabad","Lahore");
    citiesGraph.addEdge("Taxila","Islamabad");
    citiesGraph.addEdge("Islamabad","Wah-cantt");
    citiesGraph.addEdge("Peshawer","Aboottabad");

    citiesGraph.displayGraph();
}