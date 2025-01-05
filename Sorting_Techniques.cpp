#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int key){
        this->data = key;;
        this->next = NULL;
    }
};


void BubbleSort(vector<int> &v){
    int n = v.size();
    bool flag;
    for(int i = 0; i < n-1; i++){//Number of passes
        flag = false;
        for(int j = 0; j < n-1-i; j++){//Number of comparisons
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                flag = true;
            }
        }
        if(!flag) return;
    }
}

void InsertionSort(vector<int> &v){
    //Time complexity --> O(N^2) -->worst case
    //Best case --> O(N)

    //Total shifts/swaps --> O(N^2) -->worst case
    //Best case 0 => O(1)

    int n = v.size();
    int j, x;
    for(int i = 1; i < n; i++){//Passes
        j = i-1;
        x = v[i];
        while(v[j] > x){//Shifts
            v[j+1] = v[j];
            j--;
            if(j == -1) break;
        }
        v[j+1] = x;
    }

    //Adaptive and Stable
}

void SelectionSort(vector<int> &v){
    int n = v.size();
    int i, j, k;
    for(i = 0; i < n-1; i++){
        for(j = i, k = i; j < n; j++){
            if(v[j] < v[k]){
                k = j;
            }
        }
        swap(v[i], v[k]);
    }
}

void Merge(vector<int> &v, int l, int mid, int h){
    int i, j, k;
    int n = v.size();
    vector<int> Aux(h+1);
    i = l, j = mid+1, k = l;
    while(i <= mid && j <= h){
        if(v[i] < v[j]) Aux[k++] = v[i++];
        else Aux[k++] = v[j++];
    }
    for(; i <= mid; i++) Aux[k++] = v[i];
    for(; j <= h; j++) Aux[k++] = v[j];

    for(int m = l; m <= h; m++){
        v[m] = Aux[m];
    }
}
void IterativeMergeSort(vector<int> &v){
    int n = v.size();
    int p, i, l, mid, h;
    for(p = 2; p <= n; p *= 2){
        for(i = 0; i+p-1 < n; i += p){
            l = i;
            h = i+p-1;
            mid = floor((l+h)/2);
            Merge(v, l, mid, h);
        }
    }
    if(p/2 < n){//odd no. of elements => 1 element left so merge it
        Merge(v, 0, p/2 - 1, n-1);
    }
}
void RecursiveMergeSort(vector<int> &v, int l, int h){
    if(l < h){
        int mid = floor((l+h)/2);
        RecursiveMergeSort(v, l, mid);
        RecursiveMergeSort(v, mid+1, h);
        Merge(v, l, mid, h);
    }
}


int partition(vector<int> &v, int low, int high) {
    int pivot = v[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (v[i] <= pivot) i++;
        while (v[j] > pivot) j--;
        if (i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]); // Place the pivot in its correct position
    return j;           // Return the pivot index
}
void QuickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int p = partition(v, low, high);
        QuickSort(v, low, p - 1);  // Sort left part
        QuickSort(v, p + 1, high); // Sort right part
    }
}

void CountSort(vector<int> &v){
    int n = v.size();
    int maxEle = *max_element(v.begin(), v.end());
    vector<int> count(maxEle+1, 0);
    for(int i = 0; i < n; i++){
        count[v[i]]++;
    }
    int j = 0, k = 0;
    while(j <= maxEle){
        while(count[j]){
            v[k++] = j;
            count[j]--;
        }
        j++;
    }
}

void InsertNode(Node* &head, int num){
    if(head == NULL){
        head = new Node(num);
        return;
    }
    Node *temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new Node(num);
}
void BucketSort(vector<int> &v){
    int n = v.size();
    int maxVal = *max_element(v.begin(), v.end());
    vector<Node*> Bin(maxVal+1, NULL);
    for(int num : v){
        InsertNode(Bin[num], num);
    }
    int i = 0, j = 0;
    while (i <= maxVal){
        Node* temp = Bin[i];
        while (temp) {
            v[j++] = temp->data;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete; // Free memory for the node
        }
        i++;
    }
}

void RadixSort()

int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(1);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(12);
    v.push_back(5);
    v.push_back(5);

    //BubbleSort(v);
    //InsertionSort(v);
    //SelectionSort(v);
    //QuickSort(v, 0, v.size()-1);
    //IMergeSort(v);
    //RecursiveMergeSort(v, 0, v.size()-1);
    //CountSort(v);
    //BucketSort(v);
    RadixSort(v);

    for(auto ele : v) cout<<ele<<" ";
    cout<<endl;
}