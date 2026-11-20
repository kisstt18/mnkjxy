package com.supermarket.entity;

public class Order {
    // 4个public成员字段
    public String orderId;
    public String username;
    public String goodsInfo;
    public double totalMoney;

    // 四参数构造方法
    public Order(String orderId, String username, String goodsInfo, double totalMoney) {
        this.orderId = orderId;
        this.username = username;
        this.goodsInfo = goodsInfo;
        this.totalMoney = totalMoney;
    }
}
