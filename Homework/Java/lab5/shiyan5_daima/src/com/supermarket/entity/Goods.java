package com.supermarket.entity;

public class Goods {
    public String goodsId;
    public String goodsName;
    public double price;
    public int stock;

    public Goods(){}
    public Goods(String goodsId,String goodsName,double price,int stock){
        this.goodsId=goodsId;
        this.goodsName=goodsName;
        this.price=price;
        this.stock=stock;
    }

    public void printInfo(){
        System.out.println("商品编号："+goodsId
                          +",名称："+goodsName
                          +",单价："+price
                          +",库存："+stock);
    }
}
