package com.supermarket.dao;

import com.supermarket.entity.Goods;
import com.supermarket.store.DataStore;

public class GoodsDao {
        public Goods findByGoodsId(String id){
            return DataStore.findByGoodsId(id);
    }
}
