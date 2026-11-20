package com.supermarket.store;

import com.supermarket.entity.Goods;
import com.supermarket.entity.Order;
import com.supermarket.entity.User;

public class DataStore {

    // 门店名称：静态常量
    public static final String STORE_NAME = "无人超市";

    // 4个静态商品对象
    public static Goods g1 = new Goods("G001", "可口可乐", 3.00, 100);
    public static Goods g2 = new Goods("G002", "农夫山泉", 2.00, 200);
    public static Goods g3 = new Goods("G003", "全麦面包", 5.50, 50);
    public static Goods g4 = new Goods("G004", "乐事薯片", 7.50, 80);

    public static Goods findByGoodsId(String goodsId) {
        if (g1.goodsId.equals(goodsId)) {
            return g1;
        }
        if (g2.goodsId.equals(goodsId)) {
            return g2;
        }
        if (g3.goodsId.equals(goodsId)) {
            return g3;
        }
        if (g4.goodsId.equals(goodsId)) {
            return g4;
        }
        return null;
    }

    // ========== 附加题：订单与用户存储 ==========

    public static Order o1;
    public static Order o2;

    public static User u1 = new User("zhangsan", "123456");
    public static User u2 = new User("lisi", "123456");
    public static User u3;

    public static boolean addOrder(Order order) {
        if (order == null) {
            return false;
        }
        if (o1 == null) {
            o1 = order;
            return true;
        }
        if (o2 == null) {
            o2 = order;
            return true;
        }
        return false;
    }

    public static void showOrders() {
        if (o1 == null && o2 == null) {
            System.out.println("当前没有订单");
            return;
        }
        if (o1 != null) {
            printOrder(o1);
        }
        if (o2 != null) {
            printOrder(o2);
        }
    }

    public static void printOrder(Order order) {
        System.out.println("订单编号：" + order.orderId);
        System.out.println("顾客用户名：" + order.username);
        System.out.println("商品清单：" + order.goodsInfo);
        System.out.println("订单金额：" + order.totalMoney);
    }
}
