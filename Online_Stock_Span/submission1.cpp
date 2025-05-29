class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    int arrSize;

    StockSpanner() {
        this->arrSize = 0;
    }
    
    int next(int price) {
        arr.push_back(price);
        arrSize++;

        while (!st.empty() && arr[st.top()]<=arr[arrSize-1]){
            st.pop();
        }

        int ans;
        if (st.empty()){
            ans = arrSize;
        } else {
            ans = arrSize - st.top() - 1;
        }

        st.push(arrSize-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */