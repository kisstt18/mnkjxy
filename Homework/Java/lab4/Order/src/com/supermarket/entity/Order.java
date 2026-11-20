package com.supermarket.entity;

public class Order {
    public String orderId;
    public String username;
    public String goodsInfo;
    public double totaMoney;

    public Order(){}

    public Order(String orderId,String username,String goodsInfo,double totaMoney){
        this.orderId=orderId;
        this.username=username;
        this.goodsInfo=goodsInfo;
        this.totaMoney=totaMoney;
    }

    //new重载
    //setGoodsInfo方法一
    public void setGoodsInfo(String goodsInfo){
        this.goodsInfo=goodsInfo;
    }
    //setGoodsInfo方法二
    public void setGoodsInfo(String goodsInfo,double totaMoney){
        this.goodsInfo=goodsInfo;
        this.totaMoney=totaMoney;
    }

    //printOrder方法一
    public void printOrder(){
        System.out.println("订单编号："+this.orderId+"订单金额："+this.totaMoney);
    }
    //printOrder方法二
    public void printOrder(String prefix){
        System.out.println(prefix+"订单编号："+this.orderId);
        System.out.println(prefix+"顾客用户名："+this.username);
        System.out.println(prefix+"商品清单："+this.goodsInfo);
        System.out.println(prefix+"订单金额："+this.totaMoney);
    }
}

class TestOrder{
    public static void main(String[] args) {
        System.out.println("===测试无参构造订单===");
        Order order1=new Order();
        order1.orderId="AAA669";
        order1.username="张三";
        order1.goodsInfo="AD钙 x1, 喜之郎果冻 x1";
        order1.totaMoney=18.80;

        System.out.println("订单编号："+order1.orderId);
        System.out.println("顾客："+order1.username);
        System.out.println("商品清单："+order1.goodsInfo);
        System.out.println("金额："+order1.totaMoney);

        System.out.println("===测试有参构造订单===");
        Order order2=new Order("BBB778","lisi","旺旺雪饼 x1, 小蛋糕 x1",28.66);
        System.out.println("订单编号："+order2.orderId);
        System.out.println("顾客："+order2.username);
        System.out.println("商品清单："+order2.goodsInfo);
        System.out.println("金额："+order2.totaMoney);
    }
}


