public class recProd {
    public int recProd(int[] array, int count) {
        if (count == 1) {
            return array[0];
        } else {
            return recProd(array, count - 1) * array[count - 1];
        }
    }
}

recProd(array,4);recProd(array,3)*array[3]; // 24
recProd(array,2)*array[2]; // 6
recProd(array,1)*array[1]; // 2