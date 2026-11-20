package com.supermarket.entity;

public class Order {
    public String orderId;
    public String username;
    public String goodsInfo;
    public double totalMoney;

    public Order() {
    }

    public Order(String orderId, String username, String goodsInfo, double totalMoney) {
        this.orderId = orderId;
        this.username = username;
        this.goodsInfo = goodsInfo;
        this.totalMoney = totalMoney;
    }

    // 直接设置商品清单
    public void setGoodsInfo(String goodsInfo) {
        this.goodsInfo = goodsInfo;
    }

    // 根据商品名称和数量设置商品清单
    public void setGoodsInfo(String goodsName, int count) {
        this.goodsInfo = goodsName + "×" + count;
    }

    // 打印订单编号和金额
    public void printOrder() {
        System.out.println("订单编号：" + orderId);
        System.out.println("订单金额：" + totalMoney + " 元");
    }

    // 先打印指定前缀，再打印订单明细
    public void printOrder(String prefix) {
        System.out.println(prefix);
        System.out.println("订单编号：" + orderId);
        System.out.println("顾客用户名：" + username);
        System.out.println("商品清单：" + goodsInfo);
        System.out.println("订单金额：" + totalMoney + " 元");
    }
}
