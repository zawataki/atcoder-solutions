import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        C_Alchemist();
    }

    private static void C_Alchemist() {

        final Scanner sc = new Scanner(System.in);
        final int numberOfMaterials = sc.nextInt();
        final List<Integer> valueListOfMaterials = new ArrayList<>();
        for (int i = 0; i < numberOfMaterials; i++) {
            valueListOfMaterials.add(sc.nextInt());
        }

        final List<Double> valueListByDouble = valueListOfMaterials.stream()
                .sorted()
                .map(Integer::doubleValue)
                .collect(Collectors.toList());

        Double answer = null;
        for (Double d : valueListByDouble) {
            if (answer == null) {
                answer = d;
            } else {
                answer = (answer + d) / 2;
            }
        }

        System.out.println(answer);
    }
}
