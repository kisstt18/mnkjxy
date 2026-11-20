package com.supermarket.test;

import com.supermarket.entity.Order;

public class OrderDemo {
    public static void main(String[] args) {
        //测试一
        Order order1=new Order();
        order1.orderId="D001";
        order1.username="xiaoming";
        order1.setGoodsInfo("农夫山泉 x2");
        order1.totaMoney=4.0;

        order1.printOrder();
        order1.printOrder("【订单明细】");

        System.out.println();

        //测试二
        Order order2=new Order();
        order2.orderId="D002";
        order2.username="xiaohong";
        order2.setGoodsInfo("乐事薯片 x3", 22.5);
        order2.printOrder();
        order2.printOrder("【订单明细】");
    }
}
