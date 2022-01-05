import java.util.ArrayList;
public class Player {
    private ArrayList<Key> keys = new ArrayList<>();

    public ArrayList<Key> getKeys() {
        return keys;
    }
    public void addKey(Key key){
        keys.add(key);
    }
    
    public void eraseKey(Key key){
        for(int i = 0; i < keys.size(); i++){
            if(keys.get(i).equals(key)){
                keys.remove(i);
                break;
            }
        }
    }
}
