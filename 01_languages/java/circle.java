public class circle {
    point Center;
    double radius;

    double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    double getArea() {
        return Math.PI * radius * radius;
    }

    void setCenter(point newCenter) {
        Center = newCenter;
    }

    void setRadius(double newRadius) {
        radius = newRadius;
    }
}
