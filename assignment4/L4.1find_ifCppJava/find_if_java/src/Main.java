import java.util.Iterator;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {

        Matcher<String> matcher =  new Matcher<>("foo");
        Vector<String> vector = new Vector<>();

        for(int i = 0; i<10000000; i++) {
            if (i==9999999) {
                vector.add("foo");
            } else {
                vector.add("bar");
            }
        }

        String foundElem = findIf(vector.iterator(), matcher);

        if(foundElem == null) {
            System.out.println("Element \"" + matcher.getValue() + "\" not found!");
        } else {
            System.out.println("Found element: \"" + foundElem + "\"");
        }

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
