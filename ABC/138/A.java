import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        A_RedOrNot();
    }

    private static void A_RedOrNot() {

        final Scanner sc = new Scanner(System.in);
        final int a = sc.nextInt();
        final String s = sc.next();
        final String output;

        if (a >= 3200) {
            output = s;
        } else {
            output = "red";
        }

        System.out.println(output);
    }
}
