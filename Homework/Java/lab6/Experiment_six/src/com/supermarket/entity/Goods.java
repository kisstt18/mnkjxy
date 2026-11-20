package com.supermarket.entity;

public class Goods {
    private String goodsId;
    private String goodsName;
    private double price;
    private int stock;

    public Goods(){}
    public Goods(String goodsId,String goodsName,double price,int stock){
        this.goodsId=goodsId;
        this.goodsName=goodsName;
        this.price=price;
        this.stock=stock;
    }

    //getter/setter
    public String getGoodsId(){
        return goodsId;
    }

    public void setGoodsId(String goodsId){
        this.goodsId=goodsId;
    }

    public String getGoodsName(){
        return goodsName;
    }

    public void setGoodsName(String goodsName){
        this.goodsName=goodsName;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price){
        this.price=price;
    }

    public int getStock(){
        return stock;
    }

    public void setStock(int stock){
        this.stock=stock;
    }

    public void printInfo(){
        System.out.println("商品编号："+goodsId
                          +",名称："+goodsName
                          +",单价："+price
                          +",库存："+stock);
    }
}

class GoodsTest{
    public static void main(String[] args) {
        Goods coke=new Goods ("G001","可口可乐",3.0,100);
        coke.printInfo();
        coke.setPrice(3.5);
        coke.setStock(80);
        System.out.println("改价后单价："+coke.getPrice() +",库存:"+coke.getStock());
    }
}




















