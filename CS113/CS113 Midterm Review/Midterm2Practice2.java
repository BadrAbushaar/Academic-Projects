public class Midterm2Practice2 {

    public int topPlayers(Player[] team, double target) {
        int total = 0;

        for (Player player : team)
            if (player.getAverage() > target)
                total++;

        return total;
    }
}
