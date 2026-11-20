package com.supermarket.dao;

import com.supermarket.entity.Order;
import com.supermarket.store.DataStore;

public class OrderDao {

    public boolean addOrder(Order order) {
        return DataStore.addOrder(order);
    }

    public void showOrders() {
        DataStore.showOrders();
    }
}
