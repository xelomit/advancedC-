import java.util.Iterator;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {

        Matcher<String> matcher =  new Matcher<>("foo");
        Vector<String> vector = new Vector<>();

        long startTime = System.nanoTime();

        for(int i = 0; i<10000000; i++) {
            if (i==9999999) {
                vector.add("foo");
            } else {
                vector.add("bar");
            }
        }

        String foundElem = findIf(vector.iterator(), matcher);

        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;

        if(foundElem == null) {
            System.out.println("Element \"" + matcher.getValue() + "\" not found!");
        } else {
            System.out.println("Found element: \"" + foundElem + "\"");
        }

        System.out.println("Total run time in seconds: " + (double)totalTime/1000000000);

    }

    private static <E> E findIf(Iterator<E> iter, IMatcher<E> matcher) {
        E elem;

        while(iter.hasNext()) {
            elem = iter.next();
            if(matcher.match(elem)) {
                return elem;
            }
        }

        return null;
    }
}
