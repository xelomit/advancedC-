public class Matcher<E> implements IMatcher<E> {

    private E value;

    public Matcher(E value) {
        this.value = value;
    }

    public E getValue() {
        return value;
    }

    @Override
    public boolean match(E elem) {
        return value.equals(elem);
    }

}
