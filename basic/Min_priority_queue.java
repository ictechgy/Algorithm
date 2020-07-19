//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

import java.util.ArrayList;
import java.util.Collections;

public class Min_priority_queue<T extends Comparable<T>> {   //최소우선순위 큐
    private ArrayList<T> queue = new ArrayList<>(); //or 배열로 구현해도 될 듯

    public Min_priority_queue(){}   //default 
    public Min_priority_queue(ArrayList<T> list){   //정렬되지 않은 List가 들어오면
        //shallow copy
        this.queue = list;
        for(int i = (queue.size()-2)/2; i >= 0; i--) heapify(i);
    }
    
    //insert, heapify, extract-min
    void insert(T item){
        queue.add(item);
        int i = queue.size()-1; //마지막에 추가된 아이템의 인덱스 
        while(i > 0 && queue.get((i-1)/2).compareTo(queue.get(i)) > 0){
            Collections.swap(queue, (i-1)/2, i);
            i = (i-1)/2;
        }
    }
    void heapify(int i){
        int left = i*2+1, right = i*2+2, child;
        if(left >= queue.size()) return;   
        else if(right >= queue.size()) child = left;  
        else child = (queue.get(left).compareTo(queue.get(right)) < 0)? left : right; 
        
        if(queue.get(i).compareTo(queue.get(child)) < 0) return;
        
        Collections.swap(queue, i, child);
        heapify(child);
    }
    T extract_min(){
        if(queue.isEmpty()) return null;
        Collections.swap(queue, 0, queue.size()-1);
        T item = queue.get(queue.size()-1);
        queue.remove(queue.size()-1);
        heapify(0);
        return item;
    }

    int getSize(){
        return queue.size();
    }

    T getElement(int index){
        return queue.get(index);
    }
}