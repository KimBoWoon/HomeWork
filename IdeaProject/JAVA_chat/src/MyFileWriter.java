import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class MyFileWriter {
    public static void main(String[] args) throws IOException {
        FileWriter fw;
        BufferedReader br;
        String fname = "src/test.data";

        fw = new FileWriter(fname);
        br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            fw.write(line);
            fw.write('\n');
        }
        fw.close();
        br.close();
    }
}
