package com.supermarket.entity;

public class User {
    private int userId;
    private String username;
    private String password;

    public User(){}

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
    //getter/setter
    public int getUserId(){
        return userId;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

}

class UserTest{
    public static void main(String[] args) {
        User u=new User("xiaoming","123456");
        System.out.println("用户编号："+u.getUserId());
        System.out.println("用户名："+u.getUsername());
        System.out.println("密码："+u.getPassword());

        u.setUsername("xiaohong");
        System.out.println("修改后的用户名："+u.getUsername());
    }
}
















