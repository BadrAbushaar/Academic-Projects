public class MonetaryCoinTest {
    public static void main(String[] args) {
        MonetaryCoin[] coinArr = new MonetaryCoin[20];
        int highestCentValue = 0;

        for (int i = 0; i < coinArr.length; i++) {
            coinArr[i] = new MonetaryCoin();
            coinArr[i].setCentValue((int)(Math.random()* 100) + 1);

            System.out.println(coinArr[i].toString());
            if (coinArr[i].getCentValue() > highestCentValue && !coinArr[i].isHeads()) {
                highestCentValue = coinArr[i].getCentValue();
            }
        }
        System.out.println("The highest monetary value with a face of tails is: " + highestCentValue);
    }
}