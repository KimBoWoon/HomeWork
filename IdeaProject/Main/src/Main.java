/**
 * Created by 보운 on 2015-03-03.
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        TreeSet<People> tSet = new TreeSet<People>();
        int n = s.nextInt();
        String name;
        int seore;

        for (int i = 0; i < n; i++) {
            name = s.next();
            seore = s.nextInt();
            tSet.add(new People(name, seore));
        }
        Iterator<People> iter = tSet.iterator();
        while (iter.hasNext())
            System.out.println(iter.next().name);
    }
}

class People implements Comparable<People> {
    String name;
    int seore;

    public People(String x, int y) {
        name = x;
        seore = y;
    }

    public int compareTo(People f) {
        if (seore > f.seore)
            return -1;
        else if (seore < f.seore)
            return 1;
        else
            return 0;
    }

    public String toString() {
        return name + " " + seore;
    }
}