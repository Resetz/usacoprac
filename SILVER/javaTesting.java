//import java.util.Scanner;

public class javaTesting {

    public static class yes {
        boolean theYes;
        public yes(boolean theYesIn) {
            theYes = theYesIn;
        }
    }
    public static class no extends yes {
        boolean theNo;
        public no(boolean theYesIn, boolean theNoIn) {
            super(theYesIn);
            theNo = theNoIn;
        }
    }

    public static void testing(yes yesIn) {
        System.out.println(yesIn);
    }
    public static void main(String[] args) {

        no nos = new no(true, false);
        //wraps but keeps type
        testing(nos);


        /*
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter two strings, result is printed after.");
        System.out.println("Enter the sentinel \"exit\" to exit the program.");
        String a = "";
        String b = "";
        while (true) {
            System.out.print("> ");
            a = scanner.nextLine();
            if (a.compareTo("exit") == 0) {
                break;
            }
            System.out.print("> ");
            b = scanner.nextLine();
            
            System.out.println("Result of \"" + a + "\".compareTo(\"" + b + "\") = " + a.compareTo(b));

            if (a.compareTo(b) < 0) {
                System.out.println("\"" + a + "\" PRECEDES \"" + b + "\" (\"" + a + "\" comes before \"" + b + "\")");
            } else if (a.compareTo(b) == 0) {
                System.out.println("\"" + a + "\" IS THE SAME AS \"" + b + "\" (\"" + a + "\"is in the same place as \"" + b + "\")");
            } else {
                System.out.println("\"" + a + "\" FOLLOWS \"" + b + "\" (\"" + a + "\" comes after \"" + b + "\")");
            }
            
        }
        scanner.close();

        */
        /*
        Random rand = new Random();
        System.out.println(200000);
        for (int i = 0; i < 200000; i++) {
            System.out.println((int) (rand.nextDouble()*10) + " " + (int) (rand.nextDouble()*20+1));
        }*/

        /*
        int total = 0;
        int currentPow = 1;
        for (int i = 0; i <= 65; i++) {
            System.out.print(i + ". ");
            int num = i - total;
            if (i - total >= (int) Math.pow(2, currentPow*2)) {
                total += (int) Math.pow(2, currentPow*2);
                currentPow++;
            }
            for (int j = 0; j < 2*currentPow; j++) {
                System.out.print(((num) & (1 << j)) > 0 ? '1' : '0');
            }

            System.out.println();
        }
        */
        /*
        int a = 1;
        int b = 2;
        int c = 3;
        a = b = c = 0;
        //        ^
        // c = 0 executes first, then b = c, then a = b.
        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("c = " + c);


        if (false)
            if (true) System.out.println("no");
            else System.out.println("yes");
            //the else maps to the second if.
        //else System.out.println("yes2");
        /*
        */
        /*
        int[] data = {1,2,3,4,5,6,7,8};

        int[] other = {1,2,3,4,5,6,7,8};
        int i = 0;
        do {
            if (i % 2 == 0) {
                for (int j = 0; j < 8; j+=2) {
                    int temp = other[j];
                    other[j] = other[j+1];
                    other[j+1] = temp;
                }
            } else {
                for (int j = 0; j < 4; j++) {
                    int temp = other[j];
                    other[j] = other[j+4];
                    other[j+4] = temp;
                }
            }
            i++;
            for (int j = 0; j < 8; j++) {
                System.out.print(other[j] + " ");
            }
            System.out.println();
        } while(!(data == other));
        System.out.println(i);
         */
    }

}
