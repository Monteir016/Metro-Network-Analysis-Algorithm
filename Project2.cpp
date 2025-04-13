#include <iostream> 
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

int numberStations; // n
int numberConnections; // m
int numberOfLines; // l

struct Connection {

    int station;
    int line;
    
};

vector<vector<Connection>> metroNetwork; // Graph
vector<unordered_set<int>> colorGraph; // ColorGraph

void printOutput(int output){
    cout << output << endl;
}
 
int modifiedBFS(int lineNode) {

    queue<int> q;
    vector<int> marked(colorGraph.size(), -1);

    q.push(lineNode);
    marked[lineNode] = 0;
    int maxDistance = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int adj : colorGraph[current]) {
            if (marked[adj] == -1) { 
                marked[adj] = marked[current] + 1;
                maxDistance = max(maxDistance, marked[adj]);
                q.push(adj);
            }
        }
    }

    
    for (size_t i = 0; i < colorGraph.size(); i++) {
        if (marked[i] == -1 && !colorGraph[i].empty()) {
            printOutput(-1);
            return -1;
        }
    }

    return maxDistance;
}

int finalValue(){
    int value = -1;
    
    for (size_t i = 0; i < colorGraph.size(); i++){
        int bfs = modifiedBFS(i);
        if (bfs == -1) {
            return 0;
        }
        value = max(value, bfs);
    }

    printOutput(value);
    return 0;
}

int buildColorGraph() {

    colorGraph.resize(numberOfLines);

    for (int i = 0; i < numberStations; i++) { //Percorrer todas as estações do Metro
        int linesCounter = 0;

        if (metroNetwork[i].size() > 1) {
            set<int> uniqueLines;

            for (Connection conn :  metroNetwork[i]) {
                
                uniqueLines.insert(conn.line); // Adicionar as várias linhas que passam pela a estação
                linesCounter++;
                if (linesCounter == numberOfLines) {
                    break;
                }
            }

            if (uniqueLines.size() > 1) {
                

                for (auto i = uniqueLines.begin(); i != uniqueLines.end(); i++) {
                    auto v = i;
                    v++;
                    for (; v != uniqueLines.end(); ++v) {
                        colorGraph[*i].insert(*v);
                        colorGraph[*v].insert(*i);
                    }
                }
            }

        } else if (metroNetwork[i].size() == 0) {
            printOutput(-1);
            return 1;
        }
    }

    finalValue();
    return 0;
}


int readInput() {

    cin >> numberStations >> numberConnections >> numberOfLines;

    int counter = 0;
    int prevLine = 0;

    metroNetwork.resize(numberStations);

    for (int i = 0; i < numberConnections; i++) {
        int x, y, line;
        cin >> x >> y >> line;
        if (i > 0 && prevLine != line){
            counter = 0;
        }
        counter++;
        prevLine = line;
        
        if (counter == numberStations - 1) {
            printOutput(0);
            return 1;
        }

        metroNetwork[x - 1].push_back({y - 1, line - 1});
        metroNetwork[y - 1].push_back({x - 1, line - 1}); //Grafo não dirigido logo x --> y e y --> x

    }
    return 0;
}


int main() {

    int input = readInput();
    if (input == 1) {
        return 0;
    }
    buildColorGraph();
    return 0;

}
