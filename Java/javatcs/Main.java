package javatcs;

import java.awt.Color;

public class Main {
    public static void main(String[] args) {
        Car myCar = new Car(12, "CB123", Color.BLACK, false);
        Car Sally = new Car(13, "CB1323", Color.BLACK, false);
        System.out.println("My car No. " + myCar.licensePlat);
        System.out.println("Sally car no. " + Sally.licensePlat);

    }

}
