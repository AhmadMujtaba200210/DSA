public class Main {
    public static void main(String[] args) {
        AdjenceyList adjenceyList=new AdjenceyList(5);
        adjenceyList.addEdge(0,1,true); // true: un-directional false: directional
        adjenceyList.addEdge(0,3,true); // true: un-directional false: directional
        adjenceyList.addEdge(1,4,true); // true: un-directional false: directional
        adjenceyList.addEdge(2,0,true); // true: un-directional false: directional
        adjenceyList.addEdge(0,2,true); // true: un-directional false: directional

        adjenceyList.displayList();
    }
}
