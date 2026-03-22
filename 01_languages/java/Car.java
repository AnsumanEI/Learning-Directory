
import java.awt.*;

public class Car {
    int avgMilesPerGallon;
    String licensePlat;
    Color paintColor;
    boolean areTailLightsWorking;

    public Car(int avgMilesPerGallon, String licensePlat, Color paintColor, boolean areTailLightsWorking)

    {
        this.avgMilesPerGallon = avgMilesPerGallon;
        this.areTailLightsWorking = areTailLightsWorking;
        this.licensePlat = licensePlat;
        this.paintColor = paintColor;

    }

    public void changePaintColor(Color newPaintColor) {
        this.paintColor = newPaintColor;
    }
}
