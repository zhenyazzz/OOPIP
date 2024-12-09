
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Array {
    private int size;
    private int[] array;

    public int getSize() {
        return size;
    }

    public Array(int size) {
        this.size = size;
        this.array = new int[size];
    }

    public void reSize(int newSize) {
    int[] newArray = Arrays.copyOf(array, newSize);
    this.size = newSize;
    this.array = newArray;
    }

    public Array() {
        this.size = 10;
        this.array = new int[size];
    }

    public void inputArray() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
    }

    public void printArray() {
        System.out.println(Arrays.toString(array));
    }

    public void findMax() {
        int[] cloneArray = array.clone();
        Arrays.sort(cloneArray);
        if (cloneArray.length == 0){
            return;
        }
        System.out.println("Первый максимальный элемент: " + (array.length >= 1 ? cloneArray[size - 1]: "Отсутствует" ));
        System.out.println("Второй максимальный элемент: " + (array.length >= 2 ? cloneArray[size - 2]: "Отсутствует" ));
        System.out.println("Третий максимальный элемент: " + (array.length >= 3 ? cloneArray[size - 3]: "Отсутствует" ));

        try (FileWriter writer = new FileWriter("laba7.txt")) {
            writer.write(Arrays.toString(array) + "\n");
            writer.write("Первый максимальный элемент: " + (array.length >= 1 ? cloneArray[size - 1]: "Отсутствует" ) + "\n");
            writer.write("Второй максимальный элемент: " + (array.length >= 2 ? cloneArray[size - 2]: "Отсутствует" ) + "\n");
            writer.write("Третий максимальный элемент: " + (array.length >= 3 ? cloneArray[size - 3]: "Отсутствует" ) + "\n");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        int choice;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите размер массива который хотите создать: ");
        int size = scanner.nextInt();
        Array arr = new Array(size);
        do {
            System.out.println("Меню: ");
            System.out.println("1) Заполнить массив");
            System.out.println("2) Изменить размер массива");
            System.out.println("3) Вывести массив");
            System.out.println("4) Найтии первых три максимальных элемента");
            System.out.println("5) Выход");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    arr.inputArray();
                    break;
                case 2:
                    System.out.println("Введите новый размер массива: ");
                    int newSize = scanner.nextInt();
                    arr.reSize(newSize);
                    break;
                case 3:
                    arr.printArray();
                    break;
                case 4:
                    arr.findMax();
                    break;
            }

        } while (choice != 5);

    }
}