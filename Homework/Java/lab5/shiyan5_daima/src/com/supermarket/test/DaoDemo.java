package com.supermarket.test;

import com.supermarket.dao.GoodsDao;
import com.supermarket.entity.Goods;
import java.util.Scanner;

public class DaoDemo {
    public static void main(String[] args) {
        GoodsDao dao=new GoodsDao();
        Scanner sc=new Scanner(System.in);
        while (true){
            System.out.print("请输入商品编号（输入0结束）：");
            String goodsId=sc.next();

            if("0".equals(goodsId)){
                break;
            }
            Goods goods= dao.findByGoodsId(goodsId);
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
    }
}
