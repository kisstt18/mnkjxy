package Week_two;

import java.util.Scanner;

public class Switch {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int type=sc.nextInt();
        switch (type)
        {
            case 1:
            case 2:
                System.out.println("你好");break;
            case 3:
                System.out.println("晚上好呀");
            case 4:
                System.out.println("吃饭了吗");break;
            default:
                System.out.println("我要睡觉啦");break;
        }
    }
}
