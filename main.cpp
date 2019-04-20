/*
 * Segment Tree using Array
 **/
#include <iostream>

using namespace std;

void createSegmentTree(int data[], int tree[], int pos, int low, int high){
    if(low==high){
        tree[pos] = data[low];
        return;
    }
    int mid = (low+high)/2;
    createSegmentTree(data, tree, 2*pos+1, low, mid);
    createSegmentTree(data, tree, 2*pos+2, mid+1, high);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int minQuery(int tree[], int qlow, int qhigh, int low, int high, int pos){
        /*total overlap*/
    if(qlow<=low && qhigh>=high){
        return tree[pos];
    }
        /*no overlap*/
    if(qlow>high || qhigh<low){
        return INT32_MAX;
    }
        /*partial overlap*/
    int mid = (low+high)/2;
    return min(minQuery(tree, qlow, qhigh, low, mid, 2*pos+1), minQuery(tree, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main(){
    

    return 0;
}
