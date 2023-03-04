public class Grade {
    private int numGrade;
    private char letterGrade;

    public Grade(int numGrade) {
        this.numGrade = numGrade;
        if (numGrade > 65)
            letterGrade = 'S';
        else
            letterGrade = 'U';
    }

    public int getNumGrade() {
        return numGrade;
    }

    public char getLetterGrade() {
        return letterGrade;
    }

    public void setNumGrade(int numGrade) {
        this.numGrade = numGrade;
    }

    public void setLetterGrade(char letterGrade) {
        this.letterGrade = letterGrade;
    }

    public String toString() {
        return "Number Grade: " + numGrade + ", Letter Grade: " + letterGrade;
    }

    public boolean isSatisfactory() {
        if (this.letterGrade == 'S')
            return true;
        else
            return false;
    }

    public boolean equals(Grade otherGrade) {
        return this.letterGrade == otherGrade.getLetterGrade();
    }
}
