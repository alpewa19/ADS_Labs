#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Stu { 
    string last,
    first; double gpa;
    };

double gradeValue(const string& g){
    if (g=="A+") return 4.00;
    if (g=="A") return 3.75;
    if (g=="B+") return 3.50; 
    if (g=="B") return 3.00;
    if (g=="C+") return 2.50; 
    if (g=="C") return 2.00;
    if (g=="D+") return 1.50; 
    if (g=="D") return 1.00;
    return 0.00;
}
bool better(const Stu& a, const Stu& b){
    if (fabs(a.gpa - b.gpa) > 1e-12) return a.gpa < b.gpa; 
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}

void merge_range(vector<Stu>& v, int L, int M, int R, vector<Stu>& tmp){
    int i=L, j=M+1, k=L;
    while(i<=M && j<=R){
        if (better(v[i], v[j])) tmp[k++] = v[i++];
        else                    tmp[k++] = v[j++];
    }
    while(i<=M) tmp[k++] = v[i++];
    while(j<=R) tmp[k++] = v[j++];
    for(int t=L; t<=R; ++t) v[t] = tmp[t];
}
void mergesort(vector<Stu>& v, int L, int R, vector<Stu>& tmp){
    if (L>=R) return;
    int M = L + (R-L)/2;
    mergesort(v, L, M, tmp);
    mergesort(v, M+1, R, tmp);
    merge_range(v, L, M, R, tmp);
}

int main(){
    int n;
    cin>>n;
    vector<Stu> stus; 
    for(int s=0; s<n; ++s){
        string last, first; int m; cin>>last>>first>>m;
        double sum=0.0; long long creds=0;
        for(int i=0;i<m;++i){ string g; int c; cin>>g>>c; sum+=gradeValue(g)*c; creds+=c; }
        stus.push_back({last, first, creds? sum/creds : 0.0});
    }
    vector<Stu> tmp(stus.size());
    if(!stus.empty()) mergesort(stus, 0, (int)stus.size()-1, tmp);
    cout << setprecision(3) << fixed;
    for (const auto& s: stus)
        cout << s.last << ' ' << s.first << ' ' << s.gpa << "\n";
    return 0;
}
