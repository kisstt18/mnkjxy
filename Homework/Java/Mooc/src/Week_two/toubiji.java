package Week_two;

import java.util.Scanner;

public class toubiji {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.print("请投币：");
        int amount=in.nextInt();

        if (amount>=10) {
            System.out.println("*************");
            System.out.println("*Java铁路专线*");
            System.out.println("* 票价：10元 *");
            System.out.println("*************");
            System.out.println("\n找零：" + (amount - 10) + "元");
        }
        else
            System.out.println("金额错误");
    }
}
