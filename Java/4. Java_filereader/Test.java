import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        // Specify the path to your file
        String filePath = "/home/philemon/Documents/Other Languages/Java/4. Java_filereader/Text.txt";

        try {
            // Create a FileReader object with the specified file path
            FileReader fileReader = new FileReader(filePath);

            // Create a Scanner object to read from the FileReader
            Scanner scanner = new Scanner(fileReader);

            // Read each line from the file until the end of the file is reached
            while (scanner.hasNextLine()) {
                // Read the next line from the file
                String line = scanner.nextLine();
                line = line + " Processed";
                String[] newArray = line.split("#",3);

                for(int i = 0; i < newArray.length; i++)
                {
                    System.out.println(newArray[i]);
                }
                System.out.println();
            }

            // Close the FileReader to release resources
            fileReader.close();
        } catch (FileNotFoundException e) {
            // Handle the case where the specified file is not found
            e.printStackTrace();
        } catch (Exception e) {
            // Handle any other exceptions that occur during file reading
            e.printStackTrace();
        }
    }
}

