import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Practice {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("input.txt"));

        int testCase;
        testCase = in.nextInt();

        for (int t = 0; t < testCase; t++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();

            boolean[] winner = new boolean[c];

            for (int i = 0; i < c; i++) {
                int n = in.nextInt();
                int k = in.nextInt();

                if (n <= a) {
                    winner[i] = false;
                    continue;
                }
                if (a >= 2 + b) {
                    winner[i] = true;
                    continue;
                } else {
                    int temp = n;
                    while (0 < temp - ((a * k) + b))
                        temp -= (a * k + b);
                    if (temp <= a)
                        winner[i] = false;
                    else
                        winner[i] = true;
                }
            }
            System.out.println("Case #" + (t + 1));
            for (int i = 0; i < c; i++)
                System.out.print(winner[i] ? 'a' : 'b');
            System.out.println();
        }
    }
}