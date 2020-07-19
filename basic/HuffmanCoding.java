import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

class Run implements Comparable<Run>{ //각각의 Run을 나타낼 객체 클래스
    public byte symbol; //해당 Run의 바이트 심볼 값
    public int runLen;  //심볼값이 몇개나 연속해서 등장하는가
    public int freq;    //등장 빈도 수

    public Run left;
    public Run right;   //트리의 노드로 사용할 때.. 

    public int codeword;
    public int codewordLen;

    public Run(byte symbol, int runLen){    //기존에 없던 Run을 생성할때의 생성자
        this.symbol = symbol;
        this.runLen = runLen;
        freq = 1;
        left = null;
        right = null;
    }

    public Run(Run left, Run right, int freq){   //부모노드용 생성자
        this.left = left;
        this.right = right;
        this.freq = freq;   //left의 freq와 right의 freq의 합
    }

    public Run(Run o){
        this.symbol = o.symbol;
        this.runLen = o.runLen;
        this.freq = o.freq;
    }

    @Override
    public boolean equals(Object obj) {
        Run o = (Run)obj;
        return (this.symbol == o.symbol) && (this.runLen == o.runLen);  //symbol과 runlen이 같아야 동일한 Run
    }

    @Override
    public int compareTo(Run o) {
        return this.freq - o.freq;
    }

    @Override
    public String toString() {
        return freq+"";
    }
}

public class HuffmanCoding {
    private ArrayList<Run> runs = new ArrayList<>();    //파일에 존재하는 Run들을 저장
    private Min_priority_queue<Run> heap;
    private Run theRoot = null;
    private Run[] chars = new Run[256];

    private void findRunAndProcess(byte symbol, int runLen){  //특정 Run이 이미 리스트에 존재하는지 검색하고 없으면 새로 만들어서 추가, 있으면 freq를 증가시키는 함수
        Run run = new Run(symbol, runLen);
        int index = runs.indexOf(run);
        if(index == -1) runs.add(run);
        else runs.get(index).freq++;
    }

    private void collectRuns(RandomAccessFile fIn) throws IOException{  //run 수집
        int ch = fIn.read();    //맨처음 가장 앞 1바이트 읽기
        if(ch == -1) return;    //파일의 내용이 없으면 바로 종료

        byte start_symbol = (byte)ch;  //기존에 읽은 심볼 -> 심볼값은 0 ~ 255의 문자값으로 생각, 맨 앞 문자로 초기화
        byte next_symbol;  //새로 읽은 심볼, EOF = -1
        int runLen = 1;      //runLen측정, 가장 앞 글자를 하나 읽고 시작했으므로 1로 초기화

        while(true){
            ch = fIn.read();
            next_symbol = (byte)ch;
            if(start_symbol != next_symbol){   //새로운 심볼이 나오면 기존의 Run 저장 or freq 증가
                findRunAndProcess(start_symbol, runLen);
                start_symbol = next_symbol;
                runLen = 1;
                if(ch == -1) return;
            }else runLen++;  //같은 symbol이 나온 경우
        }
    }   

    private void createHuffmanTree(){
        //heap = new Min_priority_queue<>(runs);    //shallow copy
        heap = new Min_priority_queue<>();
        for(Run r : runs){  //deep copy needed -> 나중에 runs 정보를 그대로 파일의 헤더에 넣어줄 것이기 때문
            Run r2 = new Run(r);
            heap.insert(r2);
        }
        Run first, second;
        while(heap.getSize() > 1){
            first = heap.extract_min();
            second = heap.extract_min();
            
            Run parent = new Run(first, second, first.freq + second.freq);
            heap.insert(parent);
        }
        theRoot = heap.getElement(0);   //허프만트리 최종 완성 후 root를 가리킴
    }
    
    private void printHuffmanTree(){
        preOrderTraverse(theRoot, 0);
    }
    private void preOrderTraverse(Run node, int depth){
        for(int i = 0; i < depth; i++) System.out.println("\t");
        if(node == null) System.out.println("null");
        else{
            System.out.println(node.toString());
            preOrderTraverse(node.left, depth + 1);
            preOrderTraverse(node.right, depth + 1);
        }
    }

    private void assignCodewords(Run p, int codeword, int length){
        if(p.left == null && p.right == null){
            p.codeword = codeword;
            p.codewordLen = length;
        }else{
            assignCodewords(p.left, codeword << 1, length + 1);
            assignCodewords(p.right, (codeword << 1) + 1, length + 1);
        }
    }

    private void storeRunsIntoArray(Run p){
        if(p.left == null && p.right == null){
            insertToArray(p);
        }else{
            storeRunsIntoArray(p.left);
            storeRunsIntoArray(p.right);
        }
    }

    private void insertToArray(Run p){  //leaf노드 p를 chars배열에 체이닝 해시테이블처럼 저장
        Run tmp = chars[p.symbol];
        p.right = tmp;
        p.left = null;
        chars[p.symbol] = p;
    }

    private Run findRun(byte symbol, int runLen){
        Run r = chars[symbol];
        while(r.runLen != runLen){
            r = r.right;
        }
        return r;
    }

    private void outputFrequencies(RandomAccessFile fIn, RandomAccessFile fOut) throws IOException{
        fOut.writeInt(runs.size());
        fOut.writeLong(fIn.getFilePointer());   //이전에 파일을 처음부터 끝까지 읽었기 때문에 파일의 크기가 나옴
        for(Run r : runs){
            fOut.write(r.symbol);
            fOut.writeInt(r.runLen);
            fOut.writeInt(r.freq);
        }
    }

    private void encode(RandomAccessFile fIn, RandomAccessFile fOut) throws IOException{
        int buffer = 0;
        int size = 0;   //buffer에 차있는 비트의 수를 나타냄. 32가 되면 꽉 찬것
        int ch = fIn.readInt();
        byte start_symbol = (byte)ch;
        byte next_symbol;
        int runLen = 1;
        Run r;
        while(true){
            ch = fIn.readInt();
            next_symbol = (byte)ch;
            if(start_symbol != next_symbol){
                r = findRun(start_symbol, runLen);
                
                if(32-size-r.codewordLen >= 0){ //만약 버퍼가 충분해서 codeword를 넣을 수 있다면
                    buffer = buffer << r.codewordLen;
                    buffer = buffer + r.codeword;
                    size += r.codewordLen;
                    if(size == 32){ //꽉 찼다면
                        fOut.writeInt(buffer);
                        buffer = 0;
                        size = 0;
                    }
                }else{  //buffer가 충분히 남아있지 않다면
                    //buffer- 32비트, codeword가 최대 32비트이므로 버퍼공간이 남아있지 않다면 남은 공간에만 가능한만큼 codeword유효비트를 넣어주고 
                    //다음 버퍼의 초기값을 codeword의 나머지 유효비트로 해주면 된다.
                    int codeWord = r.codeword;
                    int codeWordLen = r.codewordLen;
                    buffer = buffer << (32-size);   //남은 만큼 왼쪽으로
                    buffer = buffer + (codeWord >> (codeWordLen - (32-size)));  //남은 공간 채우기
                    codeWordLen -= (32-size);   //남은 비트
                    fOut.writeInt(buffer);
                    
                    //이미 들어간 비트값은 없애줘야 함.
                    int tmp = codeWord >> codeWordLen;
                    tmp = tmp << codeWordLen;
                    codeWord -= tmp;    //남은 유효비트들

                    buffer = codeWord;
                    size= codeWordLen;
                }
               
                if(ch == -1) break; //파일의 끝
                start_symbol = next_symbol;
                runLen = 1;
            }else runLen++;
        }

        if(size!=0){    //남은 비트 값이 있다면
            buffer = buffer << (32-size);   //남은 공간 0으로 채우기
            fOut.writeInt(buffer);  //나머지 쓰기 끝
        } 

    }

    public void compressFile(String inFileName, RandomAccessFile fIn) throws IOException{
        String outFileName = new String(inFileName + ".z");
        RandomAccessFile fOut = new RandomAccessFile(outFileName, "rw");

        collectRuns(fIn);
        outputFrequencies(fIn, fOut);
        createHuffmanTree();
        assignCodewords(theRoot, 0, 0);
        storeRunsIntoArray(theRoot);
        fIn.seek(0);
        encode(fIn, fOut);
    }
}