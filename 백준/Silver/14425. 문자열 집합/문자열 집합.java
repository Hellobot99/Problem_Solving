import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int count=0;
        int first = sc.nextInt();
        int second = sc.nextInt();
        Set<String>set1 = new HashSet<>();
        for(int i=0;i<first;i++){
            String a = sc.next();
            set1.add(a);
        }
        for(int i =0;i<second;i++) {
            String a = sc.next();
            if (set1.contains(a)) count++;
        }
        System.out.println(count);
    }
}