package com.supermarket.dao;

import com.supermarket.entity.Order;
import com.supermarket.store.DataStore;

public class OrderDao {

    // 保存订单，调用 DataStore.addOrder() 并返回保存结果
    public boolean addOrder(Order order) {
        return DataStore.addOrder(order);
    }

    // 查看已保存的订单，调用 DataStore.showOrders()
    public void showOrders() {
        DataStore.showOrders();
    }
}
