import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        B_ResistorsInParallel();
    }

    private static void B_ResistorsInParallel() {

        final Scanner sc = new Scanner(System.in);
        final int numberOfInput = sc.nextInt();
        final List<Integer> inputs = new ArrayList<>();
        for (int i = 0; i < numberOfInput; i++) {
            inputs.add(sc.nextInt());
        }

        final double sum = inputs.stream()
                .mapToDouble(Integer::doubleValue)
                .map(dbl -> 1 / dbl)
                .sum();

        System.out.println(1 / sum);
    }
}
