public class objini {
    public static void main(String[] args) {
        circle c1 = new circle();// default constructpr
        System.out.println(c1.Center);

        c1.Center = new point(1, 2);
        c1.radius = 10;
        // or

        c1.setCenter(new point(1, 2));
        c1.setRadius(5);

        System.out.println("Area = " + c1.getArea());
        System.out.println("perimeter + " + c1.getPerimeter());

    }

}
