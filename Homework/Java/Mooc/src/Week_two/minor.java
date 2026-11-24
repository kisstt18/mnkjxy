package Week_two;

import java.util.Scanner;

public class minor {
    public static void main(String[] args) {
        final int MINOR=35;
        System.out.print("请输入你的年龄：");
        Scanner in=new Scanner(System.in);
        int age=in.nextInt();
        System.out.println("\n您的年龄是："+age+"岁");
        if(age<MINOR)
            System.out.println("\n年轻是美好的");

        System.out.println("\n年龄决定了你的精神世界，请好好珍惜！");
    }

}
