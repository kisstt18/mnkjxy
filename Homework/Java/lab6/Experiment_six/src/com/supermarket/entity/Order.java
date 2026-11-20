package com.supermarket.entity;

import java.sql.SQLOutput;

public class Order {
    // 4个public成员字段
    private String orderId;
    private String username;
    private String goodsInfo;
    private double totalMoney;

    public Order(){}
    // 四参数构造方法
    public Order(String orderId, String username, String goodsInfo, double totalMoney) {
        this.orderId = orderId;
        this.username = username;
        this.goodsInfo = goodsInfo;
        this.totalMoney = totalMoney;
    }

    //setter/getter

    public String getOrderId() {
        return orderId;
    }

    public String getUsername() {
        return username;
    }

    public String getGoodsInfo() {
        return goodsInfo;
    }

    public double getTotalMoney() {
        return totalMoney;
    }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setGoodsInfo(String goodsInfo) {
        this.goodsInfo = goodsInfo;
    }

    public void setTotalMoney(double totalMoney) {
        this.totalMoney = totalMoney;
    }

    public void setGoodsInfo(String goodsInfo,double totalMoney){
        this.goodsInfo=goodsInfo;
        this.totalMoney=totalMoney;
    }

    public void printOrder(String prefix){
        System.out.println(prefix+"订单编号:"+getOrderId());
        System.out.println(prefix+"顾客用户名:"+getUsername());
        System.out.println(prefix+"商品清单:"+getGoodsInfo());
        System.out.println(prefix+"订单金额:"+getTotalMoney());
    }
}

class TestOrder{
    public static void main(String[] args) {
        System.out.println("---无参构造订单---");
        Order order1=new Order();
        order1.setOrderId("AAA666");
        order1.setUsername("张三");
        order1.setGoodsInfo("AD钙 x1,喜之郎果冻 x1");
        order1.setTotalMoney(18.8);

        System.out.println("订单编号:"+order1.getOrderId());
        System.out.println("顾客:"+order1.getUsername());
        System.out.println("商品清单:"+order1.getGoodsInfo());
        System.out.println("金额:"+order1.getTotalMoney());

        System.out.println("---有参构造订单---");
        Order order2=new Order("BBB778","lisi","旺旺雪饼 x1,小蛋糕 x1",28.66);
        System.out.println("订单编号:"+order2.getOrderId());
        System.out.println("顾客:"+order2.getUsername());
        System.out.println("商品清单:"+order2.getGoodsInfo());
        System.out.println("金额:"+order2.getTotalMoney());
    }
}

















