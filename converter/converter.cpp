#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
#include <math.h>
using std::vector;

int main(int argc, const char* argv[])
{
    string input;
    if(!(cin >> input) || input != "OFF")   return 1;

    int numvertices;
    int numfaces;
    int numedges;

    if(!(cin >> numvertices >> numfaces >> numedges) || numedges > 0)
        return 1;

    vector<double> vertices(numvertices*3);
    vector< vector<int> > faces(numfaces);

    double xmax, xmin, ymax, ymin, zmax, zmin;
    cin >> xmax;
    xmin = xmax;
    cin >> ymax;
    ymin = ymax;
    cin >> zmax;
    zmin = zmax;

    for(int i=1; i<numvertices; i++){
      for(int v=0; v<3; v++){
        double coord;
        cin >> coord;
        vertices[3*i+v] = coord;
        if (v==0){
          if (coord > xmax){
            xmax = coord;
          }
          if (coord < xmin){
            xmin = coord;
          }
        }
        if (v==1){
          if (coord > ymax){
            ymax = coord;
          }
          if (coord < ymin){
            ymin = coord;
          }
        }
        if (v==2){
          if (coord > zmax){
            zmax = coord;
          }
          if (coord < zmin){
            zmin = coord;
          }
        }
      }
    }

    // find diagonal
    double diag = sqrt((xmax - xmin)*(xmax - xmin) + (ymax - ymin)*(ymax - ymin) + (zmax - zmin)*(zmax - zmin))/2;
    double xmid, ymid, zmid;
    xmid = xmin + (xmax - xmin)/2;
    ymid = ymin + (ymax - ymin)/2;
    zmid = zmin + (zmax - zmin)/2;

    //Update points
    for(int i = 0; i<numvertices; i++){
      vertices.at(3*i) = (vertices.at(3*i) - xmid) / diag;
      vertices.at(3*i+1) = (vertices.at(3*i+1) - ymid) / diag;
      vertices.at(3*i+2) = (vertices.at(3*i+2) - zmid) / diag;
    }

    for(int i=0; i<numvertices; i++)
    {
        cout << "v";
        for(int v=0; v<3; v++)
        {
            cout << ' ' << vertices.at(3*i+v);
        }
        cout << endl;
    }

    for(int i=0; i<numfaces; i++)
    {
        int vcount;
        if(!(cin >> vcount) || vcount < 3) return 1;

        cout << "f ";
        for(int v=0; v<vcount; v++)
        {
            int index;
            cin >> index;
            cout << ' ' << index+1;
        }
        cout << endl;
    }

    return 0;
}
