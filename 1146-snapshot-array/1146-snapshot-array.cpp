class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;
    unordered_map<int, map<int, int>> A;
    int snap_no = 0;
public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        A[index][snap_no] = val;
    }
    
    int snap() {
        return snap_no++;
    }
    
    int get(int index, int snap_id) {
        auto it = A[index].upper_bound(snap_id);
        
        return it==begin(A[index])?0:prev(it)->second; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */