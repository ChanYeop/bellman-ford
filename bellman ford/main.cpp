#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > v;
int **array1;
int *dist;

int main() {
	int city, bus;
	cin >> city >> bus;
	array1 = new int*[city + 1];
	dist = new int[city + 1];
	for (int i = 0; i <= city; i++) {
		array1[i] = new int[city + 1];
	}

	for (int i = 0; i <= city; i++) {
		for (int j = 0; j <= city; j++) {
			array1[i][j] = (numeric_limits<int>::max());
		}
	}
	array1[1][1] = 0;

	for (int i = 0; i <= city; i++) {
		dist[i] = numeric_limits<int>::max();
	}
	dist[1] = 0;

	int a, b, c;
	for (int i = 0; i < bus; i++) {
		cin >> a >> b >> c;
		if (array1[a][b] > c)
			array1[a][b] = c;
	}

	bool cycle = false;
	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++) {
			if (i != j && array1[i][j] != numeric_limits<int>::max()) {
				if (dist[j] > dist[i] + array1[i][j]) {
					dist[j] = dist[i] + array1[i][j];
					if (i == city) {
						cycle = true;
					}
				}
			}
		}
	}

	if (cycle) {
		cout << "-1" << endl;
	}

	else {
		for (int i = 2; i <= city; i++) {
			if (dist[i] == numeric_limits<int>::max()) {
				cout << "-1" << endl;
			}
			else {
				cout << dist[i] << endl;
			}
		}
	}
}