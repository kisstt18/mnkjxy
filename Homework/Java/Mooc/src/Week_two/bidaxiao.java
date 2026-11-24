package Week_two;

import java.sql.SQLOutput;
import java.util.Scanner;

public class bidaxiao {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x,y,z,max;

        System.out.print("请输入三个数：");
        x=sc.nextInt();
        y=sc.nextInt();
        z=sc.nextInt();

        if (x>y)
        {
            if (x > z)
            {
                max = x;
            }
        }
        else {
            if (y > z) {
                max = y;
            } else {
                max = z;
            }
            System.out.println("三个数的最大值为："+ max);
        }

    }
}
