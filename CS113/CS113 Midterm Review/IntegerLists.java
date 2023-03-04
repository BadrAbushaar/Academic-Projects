public class IntegerLists {
    private int[] list;

    public IntegerLists(int size) {
        list = new int[size];
    }

    public int[] getList() {
        return list;
    }

    public void setList(int[] list) {
        this.list = list;
    }

    public void randomize() {
        for (int i : list) {
            i = (int) (Math.random() * 100) + 1;
        }
    }

    public String toString() {
        String stringList = "";
        for (int i : list) {
            stringList = i + " ";
        }
        return stringList;
    }

    public IntegerLists merge(IntegerLists other) {
        int list1Size = this.list.length;
        int list2Size = other.list.length;
        int[] merger = new int[list1Size + list2Size];

        for (int i = 0; i < list1Size; i++) {
            merger[i] = this.list[i];
        }
        for (int i = 0; i < list2Size; i++) {
            merger[list1Size + i] = other.list[i];
        }

        IntegerLists mergedList = new IntegerLists(list1Size + list2Size);
        mergedList.setList(merger);
        return mergedList;
    }
}