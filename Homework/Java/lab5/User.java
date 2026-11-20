package com.supermarket.entity;

public class User {
    public int userId;
    public String username;
    public String password;

    public User() {
    }

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
}