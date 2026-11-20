package exp5;

public class Goods {
    public String goodsId;
    public String goodsName;
    public double price;
    public int stock;

    // 无参构造方法
    public Goods() {
    }

    // 带参构造方法
    public Goods(String goodsId, String goodsName, double price, int stock) {
        this.goodsId = goodsId;
        this.goodsName = goodsName;
        this.price = price;
        this.stock = stock;
    }

    // 输出当前商品的信息
    public void printInfo() {
        System.out.println("商品编号：" + goodsId);
        System.out.println("商品名称：" + goodsName);
        System.out.println("商品单价：" + price + " 元");
        System.out.println("商品库存：" + stock + " 件");
    }
}