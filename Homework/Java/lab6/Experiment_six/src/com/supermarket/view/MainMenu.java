package com.supermarket.view;

import java.util.Scanner;

public class MainMenu {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        AdminMenu adminMenu = new AdminMenu(sc);
        adminMenu.showMenu();

        CustomerMenu customerMenu = new CustomerMenu(sc);
        customerMenu.showMenu();

        sc.close();
    }

}
