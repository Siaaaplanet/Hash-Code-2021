#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int D, I, S, V, F;
vector<int> E[100005];
vector<int> B[100005];
map<string, int> mp;
vector<string> streetName;
vector<int> L;
vector<int> plan[1005];
int po[100005];
int endL[100005];

bool comp(int x, int y) {
	return po[x] > po[y];
}

int main () {
	cin >> D >> I >> S >> V >> F;
	for (int i = 0; i < S; i++) {
		int b, e, l;
		string name;
		cin >> b >> e >> name >> l;
		mp[name] = i;
		streetName.push_back(name);
		L.push_back(l);
		B[b].push_back(i);
		E[e].push_back(i);
		endL[i] = e;
	}
	for (int i = 0; i < V; i++) {
		int p;
		cin >> p;
		int sum = 0;
		for (int j = 0; j < p; j++) {
			string name;
			cin >> name;
			plan[i].push_back(mp[name]);
			sum += L[mp[name]];
			po[mp[name]] += ((int)E[endL[mp[name]]].size() - sum % (int)E[endL[mp[name]]].size());
		}
	}
	//cout << I << endl;
	int cntI = 0;
	for (int i = 0; i < I; i++) {
		if ((int)E[i].size() == 0) continue;
		int cnt = 0;
		for (int j = 0; j < (int)E[i].size(); j++) {
			if (po[E[i][j]] == 0) continue;
			cnt++;
		}
		if (cnt == 0) continue;
		cntI++;
	}
	cout << cntI << endl;
	for (int i = 0; i < I; i++) {
		if ((int)E[i].size() == 0) continue;
		sort(E[i].begin(), E[i].end(), comp);
		int sum = 0;
		int cnt = 0;
		for (int j = 0; j < (int)E[i].size(); j++) {
			if (po[E[i][j]] == 0) continue;
			sum += po[E[i][j]];
			cnt++;
		}
		if (cnt == 0) continue;
		cout << i << endl;
		cout << cnt << endl;
		for (int j = 0; j < (int)E[i].size(); j++) {
			if (po[E[i][j]] == 0) continue;
			cout << streetName[E[i][j]] << " " << max(1, min(D / 150, min(D, (int)(1.0 * po[E[i][j]] / sum * D / 100)))) << endl;
			//cout << streetName[E[i][j]] << " " << max(1, min(6, po[E[i][j]])) << endl;
			//cout << streetName[E[i][j]] << " 1" << endl;
		}
	}
	return 0;
}
