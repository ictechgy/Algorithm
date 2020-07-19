import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

class Run implements Comparable<Run>{ //각각의 Run을 나타낼 객체 클래스
    public byte symbol; //해당 Run의 바이트 심볼 값
    public int runLen;  //심볼값이 몇개나 연속해서 등장하는가
    public int freq;    //등장 빈도 수

    public Run left;
    public Run right;   //트리의 노드로 사용할 때.. 

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

    public static void main(String args[]){
        HuffmanCoding app = new HuffmanCoding();
        RandomAccessFile fIn;
        try{
            fIn = new RandomAccessFile("sample.txt", "r");
            app.collectRuns(fIn);
            fIn.close();
        }catch(IOException e){
            System.err.println("error - " + e.getMessage());
        }
    }
}