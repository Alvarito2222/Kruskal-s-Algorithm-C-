//Alvaro Leon Parra Project 3
#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#define C(x) ( x > 'Z' ? x-'a' : x-'A' )
using namespace std;
class Graph
{
  string vertices[10][10],sets[10][10];
  unsigned int cost[10][10],parent[10],no = 0;
 
  
public:
  Graph();
  void creat_graph();
  void display();
  void kruskal_algo();
  void readFile();
  char whatChar(int);
};
//Initialzing adj matrix with 000 
//000 denotes infinite distance 
Graph::Graph()
{
  no=0;
  for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
  {
     cost[i][j]=0;
   }
}
// Gives value of int to a char
char Graph::whatChar(int row)
{
    char ch;
	switch(row){
		case 0:
			return ch = 'a';
			break;
		case 1:
			return ch = 'b';
			break;
   		case 2:
        	return ch = 'c';
        	break;
   		case 3:
        	return ch = 'd';
        	break;
    	case 4:
        	return ch = 'e';
        	break;
   		case 5:
       	 	return ch = 'f';
       	 	break;
    	case 6:
        	return ch = 'g';
        	break;
    	case 7:
        	return ch = 'h';
        	break;
    	case 8:
        	return ch = 'i';
        	break;
   		case 9:
        	return ch = 'j';
        	break;
    	case 10:
        	return ch = 'k';
        	break;
    	case 11:
        	return ch = 'l';
        	break;
    	case 12:
        	return ch = 'm';
        	break;
    	case 13:
        	return ch = 'n';
        	break;
   		case 14:
        	return ch = 'o';
        	break;
    	case 15:
        	return ch = 'p';
        	break;
    	case 16:
       	 	return ch = 'q';
       	 	break;
    	case 17:
        	return ch = 'r';
        	break;
   		case 18:
        	return ch = 's';
        	break;
  		case 19:
        	return ch = 't';
        	break;
   	 	case 20:
        	return ch = 'u';
        	break;
   		case 21:
        	return ch = 'v';
        	break;
   		case 22:
       	 	return ch = 'w';
       	 	break;
    	case 23:
        	return ch = 'x';
        	break;
    	case 24:
        	return ch = 'y';
        	break;
   		case 25:
        	return ch = 'z';
        	break;

	}
	return ch;
}

//Displaying Weight matrix 
void Graph::display()
{
  int i,j;
  cout<<"\n\n\t Adjacency matrix ";
  for(i=0;i<no;i++)
  {
     cout<<"\n";
     for(j=0;j<no;j++)
     cout<<"\t"<<cost[i][j];
  }
}
// Retrieving position of vertices in 'vertices' array 
void Graph::kruskal_algo()
{
   	int minimumcost = 0; 
    int row;
    int col;
    int colMin;
    int counter = 0;
    bool inSet = false;
    bool nodeHere = false;
    bool nodeHere2 = false;
    string nodesInSet[no];
    string goBack[10];
    string temp;
    string temp2;

    // Initialize sets of disjoint sets.
    for (int i = 0; i < 10; i++)
        parent[i] = i;

    for(int k = 0; k < no; k++)
        nodesInSet[k] = "0";

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < 10 - 1)
    {
        int min = 1000;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    if(vertices[i][j] == sets[0][k])
                    {
                        inSet = true;
                    }
                }

                for(int k = 0; k < no; k++)
                {
                    temp = vertices[i][j];
                    temp2 = temp[0];
                    temp = temp[3];

                    if(nodesInSet[k] == temp2)
                    {
                        nodeHere = true;
                    }
                    else if(nodesInSet[k] == temp)
                    {
                        nodeHere2 = true;
                    }
                }

                for(int k = 0; k < 10; k++)
                {
                    temp = sets[0][k];
                    temp2 = temp[0];
                    temp = temp[3];
                    goBack[k] = temp + "  " + temp2;
                }

                if(cost[i][j] < min && cost[i][j] != 0 && inSet == false)
                {
                    if(nodeHere == false || nodeHere2 == false)
                    {
                        row = i;
                        col = j;
                        min = cost[i][j];
                        minimumcost += min;
                        sets[0][counter] = vertices[row][col];
                        sets[1][counter] = cost[row][col];
                        counter++;
                        cout << " {" << vertices[row][col] << "}        weight =  " << min << endl;
                    
                        edge_count++;
                    }
                    else
                    {
                        edge_count++;
                    }

                    nodeHere = false;
                    if (vertices[row][col] != "0")
                    {
                        temp = vertices[row][col];
                        temp2 = temp[0];
                        temp = temp[3];
                        nodeHere = true;
                    }

                    if(nodeHere == true)
                    {
                        for(int k = 0; k < no; k++)
                        {
                            if(temp2 != nodesInSet[k] && nodesInSet[k] == "0")
                            {
                                int f = 0;
                                nodeHere = false;
                                while(!nodeHere)
                                {
                                    if(nodesInSet[f] == temp2 && nodesInSet[f] != "0")
                                        nodeHere = true;
                                    else if(nodesInSet[f] == "0")
                                    {
                                        nodesInSet[f] = temp2;
                                        nodeHere = true;
                                    }
                                    else
                                        f++;
                                }
                            }
                            if(temp != nodesInSet[k] && nodesInSet[k] == "0")
                            {
                                int f = 0;
                                nodeHere = false;
                                while(!nodeHere)
                                {
                                    if(nodesInSet[f] == temp && nodesInSet[f] != "0")
                                        nodeHere = true;
                                    else if(nodesInSet[f] == "0")
                                    {
                                        nodesInSet[f] = temp;
                                        nodeHere = true;
                                    }
                                    else
                                        f++;
                                }
                            }
                        }
                    }
                }
                inSet = false;
                nodeHere = false;
                nodeHere2 = false;
            }
        }
    }

    int minimum = 1000;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                if(vertices[i][j] == sets[0][k])
                {
                    inSet = true;
                }
                else if(vertices[i][j] == goBack[k])
                {
                    inSet = true;
                }
            }
            if(inSet == false)
            {
                if(cost[i][j] < minimum && cost[i][j] != 0)
                {
                    minimum = cost[i][j];
                    temp = vertices[i][j];
                }
            }
            inSet = false;
        }
    }

    counter++;
    cout << " {" << temp << "}        weight =  " << minimum << endl;
    minimumcost += minimum;
    cout << endl << "Total weight of the minimal spanning tree is : " << minimumcost << endl;
}



void Graph::readFile()
{
    ifstream inputFile;
    string fileName;
    string line;
    int check;
    int num;
    int counter = 0;
    char temp;
    char start[10];
    char finish[10];
    int row = 0;
    int col = 1;
    int edge = 0;
    string one ,two;

    cout << "Name of the file that you would like to use: " ;
    cin >> fileName;

    inputFile.open(fileName);
    if (inputFile.is_open())
    {
        cout << "File Opened Successfully." << endl;
    }
    else
    {
        cerr << "File not found!" << endl;
        exit(0);
    }
	cout << " //EDGES// " << endl;
    while(getline(inputFile, line)) 
    {
        temp = line[0];
        check = isalpha(temp);

        if(check != 0)
        {
            no++;
            row--;
          
        }
        else
        {
            stringstream iss(line);
            while(iss >> num)
            {
                cost[row][col] = num;
                cost[col][row] = num;

                if(num != 0)
                {
                	
                    start[row]= whatChar(row);
                    finish[col] = whatChar(col);
                    one = start[row];
                    two = finish[col];
                    vertices[row][col] = (one + "  " + two);
                	cout << "Edge " << edge ++ << " from " << vertices[row][col] << " weight --> " <<  num <<  endl;
					 
                   
                }
                col++;
            }
            counter++;
        }
        col = 1+counter;
        row++;
    }
}

int main()
{
  Graph g;
  g.readFile();
  g.display();
  cout<<"\n\nEdges included in the minimal spannin tree for this graph : \n";
 
  g.kruskal_algo();
return 0;
}