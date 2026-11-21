package com.supermarket.view;

import java.util.Scanner;

public class AdminMenu extends BaseMenu {

    public AdminMenu(Scanner sc) {
        super(sc);
    }

    @Override
    public void showMenu() {
        System.out.println("===== 管理员菜单 =====");
        System.out.println("  1. 新增商品");
        System.out.println("  2. 查询商品");
        System.out.println("  3. 修改商品");
        System.out.println("  4. 删除商品");
        System.out.println("  5. 查看全部订单");
        System.out.println("  0. 返回首页");

        while (true) {
            int choice = readInt(6);

            if (choice == 1) {
                System.out.println("进入新增商品功能...");
            } else if (choice == 2) {
                System.out.println("进入查询商品功能...");
            } else if (choice == 3) {
                System.out.println("进入修改商品功能...");
            } else if (choice == 4) {
                System.out.println("进入删除商品功能...");
            } else if (choice == 5) {
                System.out.println("进入查看全部订单功能...");
            } else {
                System.out.println("返回系统首页。");
                break;
            }
        }
    }
}
