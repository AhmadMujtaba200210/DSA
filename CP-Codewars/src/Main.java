
class TenMinWalk {
    public static boolean isValid(char[] walk) {
        return walk.length == 10 && walk[0] == walk[walk.length - 1];
    }
}


public class Main {
    public static void main(String[] args) {
            char [] walk={'n','s','n','s','n','s','n','s','n','s'};
        System.out.println(TenMinWalk.isValid(walk));
    }
}