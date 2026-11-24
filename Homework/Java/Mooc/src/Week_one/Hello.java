import java.util.Scanner;

public class Hello {
    public static void main(String[] args) {
        System.out.println("你好");
        Scanner in =new Scanner(System.in);
//        System.out.println("Echo:"+sc.nextLine());
        int amount=100;
        int price=0;
        System.out.print("请输入金额：");
        amount=in.nextInt();
        System.out.print("请输入金额：");
        price=in.nextInt();
        System.out.println(amount+"元-"+price+"元="+(amount - price)+"元");
    }
}
