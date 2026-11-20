package com.supermarket.test;

import com.supermarket.dao.OrderDao;
import com.supermarket.entity.Order;

public class OrderDaoDemo {

    public static void main(String[] args) {
        OrderDao dao = new OrderDao();
        dao.showOrders();

        Order d001 = new Order("D001", "zhangsan", "农夫山泉 x2", 4.0);
        System.out.println("保存 D001：" + dao.addOrder(d001));

        Order d002 = new Order("D002", "lisi", "乐事薯片 x3", 22.5);
        System.out.println("保存 D002：" + dao.addOrder(d002));

        Order d003 = new Order("D003", "zhangsan", "全麦面包 x1", 5.5);
        System.out.println("保存 D003：" + dao.addOrder(d003));

        OrderDao dao2 = new OrderDao();
        System.out.println("通过第二个 DAO 查看订单：");
        dao2.showOrders();
    }
}
