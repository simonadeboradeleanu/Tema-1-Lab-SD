#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int part2(vector <int> &a, int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for(i=low; i < high; i++)
    {
        if(a[i] < a[pivot])
        {
            swap(a[i],a[index]);
            index++;
        }
    }
    // Swapping value at high and at the index obtained.
    swap(a[pivot], a[index]);

    return index;
}

int alegempivot2(vector <int> &a, int st, int dr){
    int m=(dr-st)/2+st;
    srand(time(NULL));
    int random = st + rand() % (dr - st);;
    swap(a[dr], a[random]);
    return part2(a, st, dr);

}
int quicksort2(vector <int> &a, int low, int high)sdfgbhnjmk,l.,kdfcvgbhnjm,
{
    int p;
    if(low < high)
    {
        p = alegempivot2(a, low, high);
        quicksort2(a, low, p-1);
        quicksort2(a, p+1, high);
    }
    return 0;
}

int part(vector <int> &a, int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for(i=low; i < high; i++)
    {
        if(a[i] < a[pivot])
        {
            swap(a[i],a[index]);
            index++;
        }
    }
    // Swapping value at high and at the index obtained.
    swap(a[pivot], a[index]);

    return index;
}
int median(vector <int> &a, int st, int dr, int m) {
    if ((a[st] > a[dr]) ^ (a[st] > a[m]))
        return st;
    else if ((a[dr] < a[st]) ^ (a[dr] < a[m]))
        return dr;
    else
        return m;
}
int alegempivot(vector <int> &a, int st, int dr){
    int m=(dr-st)/2+st;
    int x=median(a, st, dr, m);
    swap(a[dr], a[x]);
    return part(a, st, dr);

}
int quicksort(vector <int> &a, int low, int high)
{
    int p;
    if(low < high)
    {
        p = alegempivot(a, low, high);
        quicksort(a, low, p-1);
        quicksort(a, p+1, high);
    }
    return 0;
}

void countingsort(vector<int> &a,int n, int M)
{
    vector <int> B(n,0);
    //B.clear()     for some reason merge si cu asta WHY
    vector <int> frr(M,0);

    for (int i = 0; i < n; i++)
        frr[a[i]] = frr[a[i]] + 1;

    for (int i = 1; i <= M; i++)
        frr[i] = frr[i] + frr[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        B[frr[a[i]] - 1] = a[i];
        frr[a[i]] = frr[a[i]] -1;
    }
    a.clear();
    for (int i =0;i<n;i++)
    {
        a.push_back(B[i]);
    }
}

void merge(vector <int> &a, int st, int dr)
{
    vector <int> ar(dr+1,0);
    //a.clear();
    if(st < dr)
    {
        int m = (st + dr) / 2;
        merge(a, st , m);
        merge(a, m + 1 , dr);
        int i = st, j = m + 1, k = 0;
        while( i <= m && j <= dr )
            if( a[i] < a[j])
                //a[++k] = v[i++];
                ar.push_back(a[i++]);
            else
                ar.push_back(a[j++]);
        while(i <= m)
            ar.push_back(a[i++]);
        while(j <= dr)
            ar.push_back(a[j++]);
        for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
            a[i] = ar[j];
    }
}

void shellsort(vector <int> &v, int n){
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;i++){
            int aux=v[i], j;
            for(j=i;j>=gap && v[j-gap]>aux;j=j-gap)
                    v[j]=v[j-gap];
            v[j]=aux;

        }
}

int maxi(vector <int> a, int n){
    int m=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>m)
            m=a[i];
    return m;

}
void radix_countingsort(vector <int> &a, int n, int exp){

    int fr[10]={0},i;
    vector <int> nou(n,0);
    //nr aparitii ptr fiecare cifra
    for(i=0;i<n;i++)
        fr[(a[i]/exp)%10]++;
    //ultima poz a unei cifre in nou[]
    for(i=1;i<10;i++)
        fr[i]+=fr[i-1];

    for(i=n-1;i>=0;i--){
        nou[fr[(a[i]/exp)%10]-1]=a[i];
        fr[(a[i]/exp)%10]--;
    }

    for(i=0;i<n;i++)
        a[i]=nou[i];
}
void radixsort(vector <int> &a, int n){
    int m=maxi(a,n);
    for(int exp=1; m/exp>0; exp*=10)
        radix_countingsort(a,n,exp);
}

void afisare(vector <int> a, int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int test(vector <int> v)
{
    for(int i=0;i<v.size()-1;i++)
        if(v[i]>v[i+1])
            return 0;
    return 1;
}
int generarenr(){       //creeaza in general numere mai mari
    int x,b;
    for (int i=0;i<32;i++) {
        b = rand() % 2;
        x+=pow(2,i)*b;
    }
    return x;
}
template<typename T>
vector<T> copy(vector<T> const &vec)
{
    vector<T> v(vec);
    return v;
}

int main() {
    int N, M, x, t;
    cin>>t;
    for (int i=1;i<=t;i++) {
        cin>>N>>M;
        vector<int> v, a; //vector cu N numere generate random
        srand(time(NULL));
        v.push_back(M);
        for (int i = 1; i < N; i++) {
            x = generarenr();
            if (x <= M && x >= 0)
                v.push_back(x);
            else
                i--;
        }
        a = copy(v);
        auto start = high_resolution_clock::now();
        radixsort(a, N);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Radix Sort  " << duration.count() << " microseconds " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        shellsort(a, N);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Shell Sort  " << duration.count() << " microseconds  " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        merge(a, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Merge Sort  " << duration.count() << " microseconds  " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        quicksort(a, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Quick Sort cu mediana  " << duration.count() << " microseconds  " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        quicksort2(a, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Quick Sort cu element random  " << duration.count() << " microseconds  " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        countingsort(a, N, M);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Counting Sort  " << duration.count() << " microseconds  " << test(a) << endl;

        a = copy(v);
        start = high_resolution_clock::now();
        sort(a.begin(), a.end());;
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Algoritm de sortare nativ  " << duration.count() << " microseconds  " << test(a) << endl;
    }
    return 0;
}
