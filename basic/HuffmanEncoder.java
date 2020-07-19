import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class HuffmanEncoder {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HuffmanCoding app = new HuffmanCoding();
        RandomAccessFile fIn;
        try{
            System.out.print("input file name: ");
            String fileName = sc.next();
            sc.close();
            fIn = new RandomAccessFile(fileName, "r");
            app.compressFile(fileName, fIn);
            fIn.close();
        }catch(IOException e){
            System.err.println("error - " + e.getMessage());
        }
    }
}