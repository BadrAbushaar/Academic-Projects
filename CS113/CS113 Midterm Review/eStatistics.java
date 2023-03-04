public class eStatistics {
    public int[] eStatistics(String[] names) {
        int[] frequencies = new int[names.length];
        for (int i = 0; i < names.length; i++) {
            int count = 0;
            for (int c = 0; c < names[i].length(); c++) {
                count++
            }
        
        }
        frequencies[i] = count;
    }return frequencies;

}

    public int[] eStatistics(String[] names) {
        int[] frequencies = new int[names.length];
        for (int i = 0; i < names.length; i++) {
            int count = names[i].length() - names[i].replace("e","").length();
            frequencies[i] = count;
    }
        return frequencies;
    }