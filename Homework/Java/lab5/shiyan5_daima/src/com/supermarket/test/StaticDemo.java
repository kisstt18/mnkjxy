package com.supermarket.test;

import com.supermarket.entity.Goods;
import com.supermarket.store.DataStore;

import java.util.Scanner;

public class StaticDemo {
    public static void main(String[] args) {
        System.out.println("欢迎光临:"+DataStore.STORE_NAME);
        Scanner sc=new Scanner(System.in);

        while (true){
            System.out.print("请输入商品编号（输入0结束）：");
            String goodsId=sc.next();

            if("0".equals(goodsId)){
                break;
            }
            Goods goods=DataStore.findByGoodsId(goodsId);
            if (goods !=null){
                System.out.println("商品编号："+goods.goodsId
                        +",名称："+goods.goodsName
                        +",单价："+goods.price
                        +",库存："+goods.stock);
            }else{
                System.out.println("未找到该商品");
            }
        }
        System.out.println("查询结束");
        sc.close();
    }
}
