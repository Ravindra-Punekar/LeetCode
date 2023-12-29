class StockSpanner {
public:
    stack<pair<int,int>> st;    //price,span
    StockSpanner() {
    
    }
    
    int next(int price) {
        int span = 1;
        /*
        for i<j<k
        if(a[i]<a[j]  and a[j]<a[k])
        then automatically 
        a[i]<a[k] 
        hence -pop until top()<=price
        */
        while(!st.empty() && st.top().first<=price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/*
while st.top().first <= price span++
[[],[100],[80],[60],[70],[60],[75],[85]]
[{100,1}]
[{100,1},{80,1}]
[{100,1},{80,1},{60,1}]
[{100,1},{80,1},{70,2}]
[{100,1},{80,1},{70,2},{60,1}]
[{100,1},{80,1},{75,4}]  -since 75-1, 60-1, 70-2
[{100,1},{80,1},{85,6}]  -since 85-1, 75-4, 80-1  
 */