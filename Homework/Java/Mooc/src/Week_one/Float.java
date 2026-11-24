import java.util.Scanner;

public class Float {
    public static void main(String[] args) {
        int foot;
        double inch;
        foot=(int)(30/3.0);
        Scanner sc=new Scanner(System.in);
        foot=sc.nextInt();
        inch=sc.nextInt();
        System.out.println("foot="+foot+",inch="+inch);
        System.out.println((int)((foot+inch/12)*0.3048*100));
    }
}
