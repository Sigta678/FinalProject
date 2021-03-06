#include "map.h"

Map:: Map(ifstream &file,int dm):dim(dm){
    place = new OBJ *[dim];
    for (int i = 0; i < dim; i++)
        place[i] = new OBJ [dim];
        
    int next;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            file >> next;
            place[i][j] = (OBJ)next;
        }
    }
}

Map::~Map(){
    for(int i=0; i<dim; i++)
        delete []place[i];
    delete []place;
    place = NULL;
}

void Map::printMap(){
    cout << "\r\n";
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            if(place[i][j]==0)  cout<<' ';
            else if(place[i][j]==1) cout<<"■";
            else if(place[i][j]==2) cout<<'P';
            else if(place[i][j]==3) cout<<'G';
            else if(place[i][j]==4) cout<<'K';
            else if(place[i][j]==5) cout<<"●";
            cout << " ";
        }
        cout << "\r\n";
    }
}

bool Map::setPlace(Coordinate coord, OBJ obj){
    int x = coord.getX();
    int y = coord.getY();
    //if(place[y][x]!=(OBJ)0)
    //    return false;
    place[y][x] = obj;
    return true;
}

bool Map::isfree(Coordinate coord){
    int x = coord.getX();
    int y = coord.getY();
    
    if(place[y][x]==(OBJ)0)
        return true;
    else return false;
}

Coordinate Map::GetFreeplace(){
    srand(time(NULL));
    int x = 0;
    int y = 0;
    while(! isfree( Coordinate(x,y) )){
        x = rand() % dim;
        y = rand() % dim;
    }
    
    return Coordinate(x,y);
}

OBJ Map::collision(Coordinate coord){
    return place[coord.getY()][coord.getX()];
}

OBJ Map::aplace(int x, int y){
    return place[y][x];
}
int Map::getDim(){
    return dim;
}
int** Map::getMap()
{
	/*int **output;
	output=new int*[7];
	for(int j=0;j<7;j++)
	{
		output[j]=new int[7];
	}
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(place[i][j]==0)
			{
				output[i][j]=0;	
			}
			else
			{
				output[i][j]=1;
			}
		}
	}
	return output;
	for(int i=0;i<7;i++)
	{
		delete output[i];
	}
	delete output;*/
	return (int**)place;
}
