#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>
#include<complex.h>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define S(x) scanf("%d",&x)
#define SD(x) scanf("%lf",&x)
#define SL(x) scanf("%lld",&x)
#define pb(x) push_back(x)
#define mp make_pair
#define F(i, a, b) for (int i = int(a); i < int(b); i++)
#define forit(it, a) for (it = (a).begin(); it != (a).end(); it++)
#define M(x,i) memset(x,i,sizeof(x))

/* -------------------CODE GOES HERE---------------------- */

#define INF INT_MAX

#define XWIN 3
#define OWIN 0
#define DRAW -2
#define STILLON -1

#define WINNERSCORE 10
#define LOSERSCORE 10

#define BLANK_MOVE -10

char computerChar;

struct Move{
	int i,j;

	Move(){

	};
	Move(int ii, int jj){
		i=ii;
		j=jj;
	}

};

Move choice;

int isGameOver(vector<vi> matrix){

	bool anyBlank = 0;
	int rowSum = 0;
	int columnSum = 0;

	// also check row wise
	F(i,0,3){
		rowSum = 0;
		columnSum = 0;
		F(j,0,3){
			if(matrix[i][j]==BLANK_MOVE){
				anyBlank=1;
			}
			rowSum += matrix[i][j];
			columnSum += matrix[j][i];
		}
		if(rowSum==3 || columnSum==3)
			return XWIN;

		if(rowSum==0 || columnSum==0) return OWIN;
	}

	int diaASum = matrix[0][0]+matrix[1][1]+matrix[2][2];
	int diaBSum = matrix[0][2]+matrix[1][1]+matrix[2][0];

	if(diaASum == 0 || diaBSum==0){
		return OWIN;
	}

	if(diaASum==3 || diaBSum==3){
			return XWIN;
	}


	if(anyBlank==1){
		return STILLON;
	}
	else{
		return DRAW;
	}

}

int getScore(int result, int depth){

	if(result == DRAW) return 0;

	if(result == XWIN && computerChar=='X') return WINNERSCORE - depth;

	if(result == OWIN && computerChar=='O') return WINNERSCORE - depth;

	return depth - LOSERSCORE;
}

int getMyMove(char player){
	if(player == 'X')
		return 1;

	return 0;
}

char getOpponent(char player){
	return player == 'X' ? 'O' : 'X';
}

void printVector(vector<int> score){

	cout<<"\n print score \n";
	F(i,0,score.size()){
		cout<<" "<< score[i];
	}
cout<<"\n";
}

int minmax(vector<vi> matrix, char player, int depth){

	int result = isGameOver(matrix);

	if(result != STILLON) {
		return getScore(result, depth);
	}

	vi scores;
	vector<Move> allMoves;
	depth += 1;

	F(i,0,3){
		F(j,0,3){
			if(matrix[i][j] == BLANK_MOVE){
				matrix[i][j] = getMyMove(player);
				Move m(i,j);
				scores.push_back(minmax(matrix, getOpponent(player), depth));
				allMoves.push_back(m);
				matrix[i][j] = BLANK_MOVE;  // recorrect this move
			}
		}
	}

	if(player == computerChar){
		int maxScore = -100;

//		cout<<"size "<<allMoves.size()<<"\n";

//		if(allMoves.size() > 5){
//			printVector(scores);
//		}

		for(int i=0;i<allMoves.size();i++){
			if(maxScore < scores[i]){
				choice = allMoves[i];
				maxScore = scores[i];
			}
		}
		return maxScore;
	}
	else {
		int minScore = 100;

		for(int i=0;i<allMoves.size();i++){
			if(minScore > scores[i]){
				choice = allMoves[i];
				minScore = scores[i];
			}
		}
		return minScore;
	}

}

void printGame(vector<vi> matrix){

	cout<<"\nThe state of the game is \n";

	F(i,0,3){
			F(j,0,3){
				char x = ' ';
				if(matrix[i][j]==0)
					x='O';
				if(matrix[i][j]==1) x='X';
				cout<<x<<" | ";
			}
			cout<<"\n";
		}

}

int main(){

	//freopen("/Users/bajaj/Downloads/manic_movie.txt", "r", stdin);
	//freopen("/Users/bajaj/Downloads/manic_output.txt", "w", stdout);

	//debug(ans270);


	vector<vi> matrix(3, vi(3));

	F(i,0,3){
		F(j,0,3){
			matrix[i][j] = BLANK_MOVE;
		}
	}

	cout<<"Enter computer player X or O\n";
	cin>>computerChar;

	bool whoseChance = true;

	while(isGameOver(matrix) == STILLON){

		if(whoseChance){
			cout<<"Enter your position as i j \n";
			int x,y;
			cin>>x>>y;
			matrix[x][y] = getMyMove(getOpponent(computerChar));
			printGame(matrix);
		}
		else{
			int score = minmax(matrix, computerChar, 0);
			matrix[choice.i][choice.j] = getMyMove(computerChar);
			printGame(matrix);
		}

		whoseChance = !whoseChance;
	}



return 0;

}
