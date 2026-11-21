package com.supermarket.view;

import java.util.Scanner;

public abstract class BaseMenu {

    protected Scanner sc;

    public BaseMenu(Scanner sc) {
        this.sc = sc;
    }

    public int readInt(int choiceNumber) {
        while (true) {
            System.out.print("请输入选择：");
            if (sc.hasNextInt()) {
                int choice = sc.nextInt();
                if (choice >= 0 && choice < choiceNumber) {
                    return choice;
                }
            } else {
                sc.next();
            }
            System.out.println("选择无效，请重新输入！");
        }
    }

    public abstract void showMenu();
}
