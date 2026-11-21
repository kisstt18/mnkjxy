package com.supermarket.view;

import java.util.Scanner;

public class CustomerMenu extends BaseMenu {

    public CustomerMenu(Scanner sc) {
        super(sc);
    }

    @Override
    public void showMenu() {
        System.out.println("===== 顾客菜单 =====");
        System.out.println("  1. 删除单个商品");
        System.out.println("  2. 修改购买数量");
        System.out.println("  3. 确认清单进入结算");
        System.out.println("  0. 返回首页");

        while (true) {
            int choice = readInt(4);

            if (choice == 1) {
                System.out.println("进入删除单个商品功能...");
            } else if (choice == 2) {
                System.out.println("进入修改购买数量功能...");
            } else if (choice == 3) {
                System.out.println("进入结算功能...");
            } else {
                System.out.println("返回系统首页。");
                break;
            }
        }
    }
}
