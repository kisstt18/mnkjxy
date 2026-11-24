import java.util.Scanner;

public class Homework {
    public static void main(String[] args) {
        int H;
        int C;
        Scanner sc=new Scanner(System.in);
        H=sc.nextInt();
        C=(int)((H-32)*5/9);
        System.out.println(C);
    }
}
